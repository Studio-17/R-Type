/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

    #include <boost/asio.hpp>

using boost::asio::ip::udp;

struct position
{
    int id;

    float x;
    float y;
};

class Network
{
	public:
		Network(std::string const &host, std::string const &port);
		~Network();

		void send(const std::string& msg);
    	std::string receive(void);
        void test(void);
	private:
};

#endif /* !NETWORK_HPP_ */
