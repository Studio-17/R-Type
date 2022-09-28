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
        virtual ~INetwork() = 0;

        void Send();
        void AsynchronousSend();

        void Receive();
        void AsynchronousReceive();

    protected:
    private:
};

#endif /* !INETWORK_HPP_ */
