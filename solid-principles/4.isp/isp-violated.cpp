#include <bits/stdc++.h>

using namespace std;

class Shape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

// square -> does not need a vol but forced to implement it
class Square : public Shape
{
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() override
    {
        return side * side;
    }

    double volume() override
    {
        throw logic_error("Volume not applicable for square");
    }
};

class Cube : public Shape
{
private:
    double side;

public:
    Cube(double s) : side(s) {}

    double area() override
    {
        return side * side;
    }

    double volume() override
    {
        return side * side * side;
    }
};

int main()
{
    Shape *square = new Square(5);
    Shape *cube = new Cube(5);

    cout << "Square Area: " << square->area() << endl;

    try
    {
        cout << "Square Volume: " << square->volume() << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "Cube Area: " << cube->area() << endl;
    cout << "Cube Area: " << cube->volume() << endl;
}