#ifndef _FOOD_
#define _FOOD_

class Food
{
private:
    char *name_cl;
    int worth_cl;
    bool HaveToBeCooked_cl;

public:
    Food();
    Food(char *name);
    ~Food(){};
};

#endif