int main(){
    int a = 1;
    int b = 2;

    int *p = &a;
    *p = 2;
    p = &b;

    const int *p1 = &a;
    // *p1 = 2;
    p1 = &b;

    int const *p2 = &a;
    // *p2 = 2;
    p2 = &b;

    int * const p3 = &a;
    *p3 = 2;
    // p3 = &b;

    return 0;
}