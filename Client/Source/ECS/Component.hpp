namespace component
{
    typedef struct position_s
    {
        int x;
        int y;
    } position_t;

    typedef struct velocity_s
    {
        int vx;
        int vy;
    } velocity_t;

    typedef struct drawable_s
    {
        int texture;
        int sprite;
        int *window = nullptr;
    } drawable_t;

    typedef struct controllable_s
    {
        bool isControllable;
    } controllable_t;
}