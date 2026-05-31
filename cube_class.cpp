#include <iostream>

using namespace std;

class Cube
{
public:
    void setLength(int l)
    {
        length = l;
    }

    int getLength()
    {
        return length;
    }

    void setWidth(int w)
    {
        width = w;
    }

    int getWidth()
    {
        return width;
    }

    void setHeight(int h)
    {
        height = h;
    }

    int getHeight()
    {
        return height;
    }

    int calculateArea()
    {
        return 2 * length * width + 2 * length * height + 2 * width * height;
    }

    int calculateVolume()
    {
        return length * width * height;
    }

    bool isSameByClass(Cube cube)
    {
        return length == cube.getLength()
            && width == cube.getWidth()
            && height == cube.getHeight();
    }

private:
    int length;
    int width;
    int height;
};

bool isSame(Cube cube1, Cube cube2)
{
    return cube1.getLength() == cube2.getLength()
        && cube1.getWidth() == cube2.getWidth()
        && cube1.getHeight() == cube2.getHeight();
}

int main()
{
    Cube cube1;
    cube1.setLength(10);
    cube1.setWidth(10);
    cube1.setHeight(10);

    Cube cube2;
    cube2.setLength(10);
    cube2.setWidth(10);
    cube2.setHeight(10);

    cout << "cube1的面积为：" << cube1.calculateArea() << endl;
    cout << "cube1的体积为：" << cube1.calculateVolume() << endl;

    bool result1 = isSame(cube1, cube2);
    if (result1)
    {
        cout << "全局函数判断：cube1和cube2相等" << endl;
    }
    else
    {
        cout << "全局函数判断：cube1和cube2不相等" << endl;
    }

    bool result2 = cube1.isSameByClass(cube2);
    if (result2)
    {
        cout << "成员函数判断：cube1和cube2相等" << endl;
    }
    else
    {
        cout << "成员函数判断：cube1和cube2不相等" << endl;
    }

    return 0;
}
