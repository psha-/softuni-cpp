#include <iostream>
#include <cmath>

using namespace std;

class Size {
public:
    Size(int w, int h);
    ~Size();
    inline void setW(int w) { m_W = w; }
    inline void setH(int h) { m_H = h; }
    inline int getWidth() const { return m_W; }
    inline int getHeight() const { return m_H; }
private:
    int m_W;
    int m_H;
};

class Vec2 {
public:
    Vec2(int x, int y);
    ~Vec2();
    inline void setX(int x) { m_X = x; }
    inline void setY(int y) { m_Y = y; }
    inline int getX() const { return m_X; }
    inline int getY() const { return m_Y; }
private:
    int m_X;
    int m_Y;
};

class Rectangle {
public:
    Rectangle(int x, int y, int w, int h);
    Rectangle(Vec2 position, Size size);
    ~Rectangle();
    inline void setPosition(Vec2 position) { m_Position = position;}
    inline void setSize(Size size) { m_Size = size;}
    inline Size& getSize() { return m_Size; }
    inline Vec2& getPosition() { return m_Position; }
    inline int getPerimeter() const { return 2 * ( m_Size.getHeight() + m_Size.getWidth()); }
    inline int getSurface() const { return m_Size.getHeight() * m_Size.getWidth(); }
    inline float getDiagonalLength() const
    {
        return sqrt(pow(m_Size.getHeight(),2) + pow(m_Size.getWidth(),2));
    }
private:
    Size m_Size;
    Vec2 m_Position;
};

Rectangle::Rectangle(int x, int y, int w, int h):m_Position(x, y),m_Size(w, h)
{
    cout << "Rectangle created" << endl;
}

Rectangle::Rectangle(Vec2 position, Size size):m_Position(position),m_Size(size)
{
    cout << "Rectangle created" << endl;
}

Rectangle::~Rectangle()
{
    cout << "Rectangle destroyed" << endl;
}

Size::Size(int w, int h):m_W(w),m_H(h)
{
    cout << "Size created" << endl;
}

Size::~Size()
{
    cout << "Size destroyed" << endl;
}

Vec2::Vec2(int x, int y):m_X(x),m_Y(y)
{
    cout << "Vector created" << endl;
}

Vec2::~Vec2()
{
    cout << "Vector destroyed" << endl;
}


int main()
{
    Rectangle rect(2, 2, 2, 2);
    cout << "Position: " << rect.getPosition().getX() << "," << rect.getPosition().getY() << endl;
    cout << "Size: " << rect.getSize().getWidth() << "," << rect.getSize().getHeight() << endl;
    cout << "Perimeter: " << rect.getPerimeter() << endl;
    cout << "Surface: " << rect.getSurface() << endl;
    cout << "Diagonal length: " << rect.getDiagonalLength() << endl << endl;

    Rectangle rect1(Vec2(2,2), Size(2,2));
    cout << "Position: " << rect1.getPosition().getX() << "," << rect1.getPosition().getY() << endl;
    cout << "Size: " << rect1.getSize().getWidth() << "," << rect1.getSize().getHeight() << endl;
    cout << "Perimeter: " << rect1.getPerimeter() << endl;
    cout << "Surface: " << rect1.getSurface() << endl;
    cout << "Diagonal length: " << rect1.getDiagonalLength() << endl << endl;
    return 0;
}

