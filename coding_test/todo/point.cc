# include <iostream>

class Point {
    public:
        double x, y;
        Point();
        Point(double x, double y);
        Point(const Point &p);
        Point & operator=(const Point &p);
};

Point::Point()
{}

Point::Point(double x, double y)
{
    this -> x = x;
    this -> y = y;
}

Point::Point(const Point &p)
{
    x = p.x;
    y = p.y;
}

Point & Point::operator=(const Point &p)
{
    x = p.x;
    y = p.y;
    return *this;
};

int main()
{
    Point p1(3,4);
    std::cout << p1.x << ", " << p1.y << std::endl;

    Point p2(p1);
    std::cout << p2.x << ", " << p2.y << std::endl;

    Point p3;
    p3 = p1;
    std::cout << p3.x << ", " << p3.y << std::endl;

    return 0;
}