/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

    #include <boost/asio.hpp>

using boost::asio::ip::udp;

class Client
{
	public:
		Client(boost::asio::io_service &io_service, std::string const &host, std::string const &port);
		~Client();

		void send(const std::string& msg);
    	std::string receive(void);
	private:
		boost::asio::io_service& io_service_;
		udp::socket socket_;
		udp::endpoint endpoint_;
};

#endif /* !CLIENT_HPP_ */
