/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Data
*/

#ifndef DATA_HPP_
    #define DATA_HPP_

    #include <string>

class Data {
    public:
        Data(std::string const &);
        ~Data();
        operator std::string();

    protected:
    private:
        std::string _data;
};

#endif /* !DATA_HPP_ */
