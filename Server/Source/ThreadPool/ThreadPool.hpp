/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** ThreadPool
*/

#ifndef THREADPOOL_HPP_
    #define THREADPOOL_HPP_

    #include <vector>
    #include <thread>
    #include <map>
    #include <mutex>
    #include <condition_variable>
    #include <queue>
    #include <boost/asio.hpp>

using boost::asio::ip::udp;

class ThreadPool {
    public:
       ThreadPool(std::shared_ptr<udp::socket> socket);
       ~ThreadPool();

        void stop_one(udp::endpoint &endpoint);
        void stop();
        void add(udp::endpoint &endpoint);

        void notify();
        void queueJob(std::function<void(void)> task);

    private:
        // std::vector<std::thread> _threadsList;
        std::map<std::size_t, std::thread> _threadsList;

        std::size_t _threadIndex;
        std::size_t _suppressedIndex;
        // std::map<boost::asio::ip::address, std::map<unsigned short, bool>> _threadsCondition;

        bool _stop;
        bool _oneBreak;

        void threadLoop(std::size_t index);

        std::shared_ptr<udp::socket> _socket;

        std::size_t _inactiveThread;

        std::mutex _mutexQueue;
        std::condition_variable _mutexCondition;


        std::queue<std::function<void(void)>> _queue;
};

#endif /* !THREADPOOL_HPP_ */
