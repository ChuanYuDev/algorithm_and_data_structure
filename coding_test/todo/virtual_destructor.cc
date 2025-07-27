# include <stdio.h>

class A
{
    public:
        ~A()
        {
            puts("~A()");
        }
};

class B: public A
{
    public:
        virtual ~B()
        {
            puts("~B()");
        }
    
};

class C: public B
{
    public:
        virtual ~C()
        {
            puts("~C()");
        }
};

int main()
{
    // A *a = new B();
    B b;
    // B *c = new C();

    // delete a;
    // delete c;

    return 0;
}