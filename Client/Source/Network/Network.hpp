/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

    // #include <asio/ip/udp.hpp>

/**
 * @brief A structure that represents a position in the game space
 * 
 */
struct position
{
    int id;

    float x;
    float y;
};

/**
 * @brief The Network class, it handles communication with udp protocol
 * 
 */
class Network
{
	public:
		/**
		 * @brief Construct a new Network object
		 * 
		 * @param host host of the server
		 * @param port port of the server
		 */
		Network(std::string const &host, std::string const &port);

		/**
		 * @brief Destroy the Network object
		 * 
		 */
		~Network();

		/**
		 * @brief A method to send a message using a string object
		 * 
		 * @param msg message to send
		 */
		void send(const std::string& msg);

		/**
		 * @brief A method to receive an object as a string
		 * 
		 * @return std::string 
		 */
    	std::string receive(void);

		/**
		 * @brief A test method
		 * 
		 */
        void test(void);
	private:
};

#endif /* !NETWORK_HPP_ */
