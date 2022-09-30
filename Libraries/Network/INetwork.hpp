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
        virtual ~INetwork() {};

        virtual void Send() = 0;
        virtual void AsynchronousSend() = 0;

        virtual void Receive() = 0;
        virtual void AsynchronousReceive() = 0;

    protected:
    private:
};

#endif /* !INETWORK_HPP_ */
