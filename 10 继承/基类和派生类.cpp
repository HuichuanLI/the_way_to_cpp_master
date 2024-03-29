//
// Created by lhc456 on 2024/3/3.
//
#include<iostream>
#include<typeinfo>

using namespace std;


class Base {
public:
    Base(int data = 10) : ma(data) {}

    void show() { cout << "Base::show()" << endl; }

    void show(int) { cout << "Base:show(int)" << endl; }

protected:
    int ma;
};

class Derive : public Base {
public:
    Derive(int data = 20) : Base(data), mb(data) {}

    void show() { cout << "Derive::show()" << endl; }

private:
    int mb;
};

int main() {
    Derive d(50);
    Base *pb = &d;
    pb->show(); // 静态（编译时期）的绑定（函数的调用）call        Base::show (0851037h)
    pb->show(10); // 静态绑定 call        Base::show (0851307h)

    cout << sizeof(Base) << endl; // 4
    cout << sizeof(Derive) << endl; // 8

    cout << typeid(pb).name() << endl; // Base*
    cout << typeid(*pb).name() << endl; // Base

    return 0;
}
