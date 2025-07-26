# include <math.h>
# include <iostream>
# include <chrono>

double get_y(double x){
    return sin(x);
}

double integral(double x1, double x2, int n){
    double dx = (x2 - x1) / n;
    double result = 0, x, y;

    for (int i = 0; i < n; ++i){
        x = x1 + dx * i;
        y = get_y(x);
        result += y * dx;
    }
    return result;
}

int main(){
    auto start = std::chrono::system_clock::now();

    double x1 = 0, x2 = M_PI, n = 10000;
    std::cout << "Answer: 2" << std::endl;
    std::cout << "Output: " << integral(x1, x2, n) << std::endl;

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;

    std::cout << "time: " << diff.count() << std::endl;

    return 0;
}