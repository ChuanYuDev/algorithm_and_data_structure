#include <iostream>
#include <array>

using scalar_type = double;
using size_type = unsigned long long;

class Vector2d;

Vector2d operator-(const Vector2d &, const Vector2d &);

class Vector2d {
friend std::ostream &operator<<(std::ostream &os, const Vector2d& v);

public:
    Vector2d() = default;
    Vector2d(scalar_type x, scalar_type y)
    {
        array_[0] = x;
        array_[1] = y;
    }

    Vector2d(const Vector2d &) = delete;
    Vector2d(Vector2d &&){std::cout << "move constructor triggered" << std::endl;};

    Vector2d &operator=(const Vector2d &) = delete;
    Vector2d &operator=(Vector2d &&) {std::cout << "move assignment triggered" << std::endl; return *this;};

public:
    scalar_type operator()(size_type i) const {return array_[i];}
    scalar_type &operator()(size_type i) {return array_[i];}

private:
    std::array<scalar_type, 2> array_;
};

Vector2d operator-(const Vector2d &v1, const Vector2d &v2)
{
    return Vector2d(v1(0) - v2(0), v1(1) - v2(1));
}

std::ostream &operator<<(std::ostream &os, const Vector2d& v)
{
    os << v(0) << ", " << v(1);
    return os;
}

int main(){
    Vector2d v1(3, 4), v2(1, 2);
    Vector2d v = v1 - v2;
    std::cout << v << std::endl;

    return EXIT_SUCCESS;
}