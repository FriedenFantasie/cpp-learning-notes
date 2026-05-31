#include <iostream>

using namespace std;

class Point
{
public:
    void setX(int x)
    {
        pointX = x;
    }

    int getX()
    {
        return pointX;
    }

    void setY(int y)
    {
        pointY = y;
    }

    int getY()
    {
        return pointY;
    }

private:
    int pointX;
    int pointY;
};

class Circle
{
public:
    void setRadius(int r)
    {
        radius = r;
    }

    int getRadius()
    {
        return radius;
    }

    void setCenter(Point centerPoint)
    {
        center = centerPoint;
    }

    Point getCenter()
    {
        return center;
    }

private:
    int radius;
    Point center;
};

void checkPointAndCircle(Circle circle, Point point)
{
    int distance =
        (circle.getCenter().getX() - point.getX()) * (circle.getCenter().getX() - point.getX()) +
        (circle.getCenter().getY() - point.getY()) * (circle.getCenter().getY() - point.getY());

    int radiusDistance = circle.getRadius() * circle.getRadius();

    if (distance == radiusDistance)
    {
        cout << "点在圆上" << endl;
    }
    else if (distance > radiusDistance)
    {
        cout << "点在圆外" << endl;
    }
    else
    {
        cout << "点在圆内" << endl;
    }
}

int main()
{
    Point center;
    center.setX(0);
    center.setY(0);

    Circle circle;
    circle.setRadius(10);
    circle.setCenter(center);

    Point point;
    point.setX(10);
    point.setY(0);

    checkPointAndCircle(circle, point);

    return 0;
}
