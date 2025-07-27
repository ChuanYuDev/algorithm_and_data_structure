#include <iostream>

class MyCin{
    private:
        bool status;
    public:
        MyCin():status(true){}
        MyCin &operator >>(int &n){
            if (!status)
                return *this;
            
            if (!(std::cin >> n) || (n == 100))
                status = false;
            return *this;
        }
        explicit operator bool() const{
            return status;
        }
};

int main(){
    MyCin m;
    int n = 0;
    freopen("cpp//mycin.txt", "r", stdin);
    while(m >> n)
        std::cout << n << std::endl;
    return 0;
}