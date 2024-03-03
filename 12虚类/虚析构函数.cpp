#include <iostream>

using namespace std;

class Base {
public:
    Base(int data) : ma(data) { cout << "Base()" << endl; }

    virtual ~Base() { cout << "~Base()" << endl; }

    virtual void show() { cout << "call Base::show()" << endl; }

protected:
    int ma;
};

class Derive : public Base {
public:
    Derive(int data)
            : Base(data), mb(data), ptr(new int(data)) {
        cout << "Derive()" << endl;
    }

    ~Derive() { cout << "~Derive()" << endl; }

    void show() { cout << "call Derive::show()" << endl; }

private:
    int mb;
    int *ptr;
};

int main() {
    // 这种情况下，一定要动态绑定否则没有办法使用析构函数（派生类）
    // 虚函数，静态绑定，动态绑定：
    // 问题1:哪些函数不能用虚函数？
    //  1. 虚函数能够产生函数地址，虚函数表（vftable）的地址在vfptr，在对象的内存中，所以没有对象就没有办法使用virtual

    Base *p = new Derive(10);
    p->show();
    delete p;

    return 0;
}
