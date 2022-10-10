/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** ThreadPool
*/

#include "ThreadPool.hpp"

ThreadPool::ThreadPool(std::shared_ptr<asio::ip::udp::socket> socket)
    : _socket(socket), _inactiveThread(0), _stop(false), _oneBreak(false), _threadIndex(0), _suppressedIndex(-1)
{
}

ThreadPool::~ThreadPool()
{

}

void ThreadPool::threadLoop(std::size_t index)
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
    {
        std::unique_lock<std::mutex> lock(_mutexQueue);
        _suppressedIndex = index;
    }
}

void ThreadPool::stop()
{
    _stop = true;
    _mutexCondition.notify_all();
    for (auto &[index, thread]: _threadsList)
        thread.join();
    _threadsList.clear();
}

void ThreadPool::add(asio::ip::udp::endpoint &endpoint)
{
    _threadsList.emplace(_threadIndex, std::thread(&ThreadPool::threadLoop, this, _threadIndex));
    _threadIndex++;
    _inactiveThread++;
}

void ThreadPool::stop_one(asio::ip::udp::endpoint &endpoint)
{
    _oneBreak = true;
    _mutexCondition.notify_one();
    try {
        _threadsList.at(_suppressedIndex).join();
    } catch (std::out_of_range const &) {}
}

void ThreadPool::notify()
{
    if (!_queue.empty()) {
    std::cout << "notify" << std::endl;
        _mutexCondition.notify_one();
    }
}

void ThreadPool::queueJob(std::function<void(void)> task)
{
    std::cout << "inactive cooks: " << _inactiveThread<< std::endl;
    {
        std::unique_lock<std::mutex> lock(_mutexQueue);
        _queue.push(task);
    }
    if (_inactiveThread > 0)
        _mutexCondition.notify_one();
}
