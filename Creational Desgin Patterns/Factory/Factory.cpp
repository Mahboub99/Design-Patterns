#include <iostream>

using namespace std;

enum shapeType
{
    Circle,
    Rectangle,
    Square
};

class shape
{
public:
    virtual void draw() = 0;
    static shape *create(shapeType type);
};
class circle : public shape
{
public:
    void draw()
    {
        cout << "Circle" << endl;
    }
};
class rectangle : public shape
{
public:
    void draw()
    {
        cout << "Rectangle" << endl;
    }
};
class square : public shape
{
public:
    void draw()
    {
        cout << "Square" << endl;
    }
};
shape *shape::create(shapeType type)
{
    if (type == Circle)
        return new circle();
    else if (type == Square)
        return new square();
    else if (type == Rectangle)
        return new rectangle();
}
class Client
{
private:
    shape *pShape = NULL;
    shapeType type;

public:
    Client(shapeType type)
    {
        this->type = type;
        pShape = shape::create(type);
    }
    ~Client()
    {
        if (pShape)
        {
            delete[] pShape;
            pShape = NULL;
        }
    };
    shape *getShap()
    {
        return pShape;
    }
};

main()
{
    Client *pClient = new Client(Circle);
    shape *pShape = pClient->getShap();

    pShape->draw();
}
