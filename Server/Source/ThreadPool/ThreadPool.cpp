/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** ThreadPool
*/

#include "ThreadPool.hpp"
#include <iostream>

ThreadPool::ThreadPool(std::shared_ptr<udp::socket> socket)
    : _nbThread(0), _socket(socket), _stop(false), _oneBreak(false)
{
}

ThreadPool::~ThreadPool()
{

}

void ThreadPool::threadLoop()
{
    std::function<void(void)> task;

    while (!_stop) {
        {
            std::unique_lock<std::mutex> lock(_mutexQueue);
            _mutexCondition.wait(lock);

            if (_stop)
                return;
            if (_oneBreak) {
                !_oneBreak;
                return;
            }
            _inactiveThread -= 1;
            task = _queue.front();
            _queue.pop();
        }
            task();
        {
            std::unique_lock<std::mutex> lock(_mutexQueue);
            _inactiveThread += 1;
        }
        notify();
    }
}

void ThreadPool::stop()
{
    _stop = true;
    _mutexCondition.notify_all();
    for (auto &thread : _threadsList)
        thread.join();
    _threadsList.clear();
}

void ThreadPool::add(udp::endpoint &endpoint)
{
    _threadsCondition.try_emplace(endpoint.address(), std::map<unsigned short, bool>());
    _threadsCondition.at(endpoint.address()).try_emplace(endpoint.port(), true);
    _threadsList.emplace_back(std::thread(&ThreadPool::threadLoop, this));
    _nbThread++;
}

void ThreadPool::stop_one(udp::endpoint &endpoint)
{
    try {
        _threadsCondition.at(endpoint.address()).at(endpoint.port());
        _threadsCondition.at(endpoint.address()).erase(endpoint.port());
        if (_threadsCondition.at(endpoint.address()).empty())
            _threadsCondition.erase(endpoint.address());
        _oneBreak = true;
        _mutexCondition.notify_one();
        _nbThread--;
    } catch (std::out_of_range const &) {}
}

void ThreadPool::notify()
{
    if (!_queue.empty())
        _mutexCondition.notify_one();
}

void ThreadPool::queueJob(std::function<void(void)> task)
{
    {
        std::unique_lock<std::mutex> lock(_mutexQueue);
        _queue.push(task);
    }
    if (_inactiveThread > 0)
        _mutexCondition.notify_one();
}
