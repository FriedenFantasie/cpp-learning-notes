#include <iostream>

using namespace std;

const double PI = 3.1415926;

class Circle
{
public:
    void setRadius(double r)
    {
        radius = r;
    }

    double getRadius()
    {
        return radius;
    }

    double calculateCircumference()
    {
        return 2 * PI * radius;
    }

private:
    double radius;
};

int main()
{
    Circle circle;

    circle.setRadius(10);

    cout << "圆的半径为：" << circle.getRadius() << endl;
    cout << "圆的周长为：" << circle.calculateCircumference() << endl;

    return 0;
}
