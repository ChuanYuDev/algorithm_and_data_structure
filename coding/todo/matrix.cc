# include <vector>

std::vector<double> get_a(double x1, double x2, double x3, double x4){
    std::vector<double> as;

    as.push_back(x1);
    as.push_back(-1 * x1 + 1 * x2);
    as.push_back(-1 * x1 + 1 * x4);
    as.push_back(x1 - x2 + x3 - x4);

    return as;
}

int main(){
    return 0;
}