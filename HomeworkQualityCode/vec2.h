#ifndef VEC2_H
#define VEC2_H

// 2d vector
struct Vec2
{
    float x;
    float y;

    Vec2(float _x=0, float _y=0)
        :x(_x), y(_y)
    {
    }

    Vec2 operator+(const Vec2& rhs)
    {
        return Vec2(x+rhs.x, y+rhs.y);
    }

    Vec2 operator-(const Vec2& rhs)
    {
        return Vec2(x-rhs.x, y-rhs.y);
    }

    Vec2& operator+=(const Vec2& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    Vec2& operator-=(const Vec2& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    Vec2 operator*(float rhs)
    {
        return Vec2(x*rhs, y*rhs);
    }

    Vec2 operator/(float rhs)
    {
        return Vec2(x/rhs, y/rhs);
    }
};

#endif // VEC2_H
