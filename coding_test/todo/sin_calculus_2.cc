# include <math.h>
// # include <cmath>
# include <iostream>

double get_y(double x){
    return sin(x);
    // return x + 1.0;
}

double q2(double x1, double x2, int n){
    double dx = (x2 - x1) / n, x;
    double ans, sum = 0;

    for (int i = 1; i < n; ++i){
        x = x1 + dx * i;
        sum += get_y(x);
    }

    ans = (dx / 2.0) * (get_y(x1) + 2 * sum + get_y(x2));

    return ans;
}

int main(){
    const int mxN = 1e10;
    // int array[mxN];
    int *a = new int[mxN];
    //malloc, free -> heap
    //new delete -> free store

    // double x1 = 0, x2 = M_PI, n = 1000;
    // double ans, err;

    // ans = q2(x1, x2, n);
    // std::cout << ans << std::endl;

    // err = 2 - ans;
    // std::cout << err << std::endl;

    return 0;
}