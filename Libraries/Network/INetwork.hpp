/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** INetwork
*/

#ifndef INETWORK_HPP_
#define INETWORK_HPP_

class INetwork {
    public:
        /**
         * @brief Destroy the INetwork object
         * 
         */
        virtual ~INetwork() {};

        /**
         * @brief Send method, using asio send()
         * 
         */
        virtual void Send() = 0;

        /**
         * @brief Send method but asynchronous, using asio async_send()
         * 
         */
        virtual void AsynchronousSend() = 0;

        /**
         * @brief Receive method, using asio receive()
         * 
         */
        virtual void Receive() = 0;

        /**
         * @brief Receive method but asynchronous, using asio asyync_send()
         * 
         */
        virtual void AsynchronousReceive() = 0;

    protected:
    private:
};

#endif /* !INETWORK_HPP_ */
