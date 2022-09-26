/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

class Text {
    public:
        Text();
        ~Text();

        void getScale();
        float setScale(float scale);

        void getRotation();
        float setRotation(float rotation);

        void getOrigin();
        void setOrigin(float origin);

        void getPosition();
        void setPosition(float position);

    protected:
    private:
};

#endif /* !TEXT_HPP_ */
