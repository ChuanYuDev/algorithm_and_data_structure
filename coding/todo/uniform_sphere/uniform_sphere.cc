#include <chrono>
#include <random>
#include <math.h>
#include <iostream>

std::vector<std::vector<double>> uniform_points(int num){
    double phi, theta;
    std::vector<std::vector<double>> points(num);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_real_distribution<double> uniform01(0.0, 1.0);

    for (int i = 0; i < num; ++i){
        phi = acos(1 - 2 * uniform01(generator));
        theta = 2 * M_PI * uniform01(generator);

        points[i].push_back(sin(phi) * cos(theta));
        points[i].push_back(sin(phi) * sin(theta));
        points[i].push_back(cos(phi));
    }

    return points;
}

int count_points(std::vector<std::vector<double>> &points, double z){
    int count = 0;
    for (auto point: points){
        if (point[2] >= z)
            ++count;
    }
    return count;
}

std::vector<std::vector<double>> rotate_x(std::vector<std::vector<double>> &points, double theta){
    int size = points.size();
    std::vector<std::vector<double>> rotate_points(size);

    double x, y, z;

    for (int i = 0; i < size; ++i){
        x = points[i][0];
        y = points[i][1];
        z = points[i][2];

        rotate_points[i].push_back(x);
        rotate_points[i].push_back(y * cos(theta) - z * sin(theta));
        rotate_points[i].push_back(y * sin(theta) + z * cos(theta));
    }

    return rotate_points;
}

std::vector<std::vector<double>> not_uniform_points(int num){
    double phi, theta;
    std::vector<std::vector<double>> points(num);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_real_distribution<double> uniform01(0.0, 1.0);

    for (int i = 0; i < num; ++i){
        phi = M_PI * uniform01(generator);
        theta = 2 * M_PI * uniform01(generator);

        points[i].push_back(sin(phi) * cos(theta));
        points[i].push_back(sin(phi) * sin(theta));
        points[i].push_back(cos(phi));
    }

    return points;
}

int main(int argc, char *argv[]){
    int n = 100000;
    int m = 20;
    double z = 0.9;

    std::vector<std::vector<double>> points;
    std::vector<std::vector<double>>rotate_points;

    std::cout << "uniform:" << std::endl;
    points = uniform_points(n);
    for (int i = 0; i <= m - 1; ++i){
        rotate_points = rotate_x(points, M_PI / m * i);
        std::cout << count_points(rotate_points, z) << std::endl;
    }

    std::cout << "non-uniform:" << std::endl;
    points = not_uniform_points(n);
    for (int i = 0; i <= m - 1; ++i){
        rotate_points = rotate_x(points, M_PI / m * i);
        std::cout << count_points(rotate_points, z) << std::endl;
    }

    return 0;
}