#ifndef SIZE_H
#define SIZE_H

struct Size {
    Size(unsigned int _x, unsigned int _y)
        :x(_x), y(_y)
    {}
    unsigned int x;
    unsigned int y;
};

#endif // SIZE_H
