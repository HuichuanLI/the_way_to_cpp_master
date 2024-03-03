#include <iostream>

using namespace std;

class Base {
public:
    virtual void func() = 0;
};

class Derive1 : public Base {
public:
    void func() { cout << "call Derive1::func" << endl; }
};

class Derive2 : public Base {
public:
    void func() { cout << "call Derive2::func" << endl; }

    // 实现新功能API
    void derive02func() {
        cout << "call Derive2::derive02func" << endl;
    }
};

void showFunc(Base *p) {
    // dynamic_cast会检查p指针是否指向的是一个Derive2类型的对象？
    // p->vfptr->vftable RTTI信息 如果是，dynamic_cast转换类型成功，
    // 返回Derive2对象的地址给pd2；否则返回nullptr
    Derive2 *pd2 = dynamic_cast<Derive2 *>(p);
    if (pd2 != nullptr) {
        pd2->derive02func();
    } else {
        p->func();
    }
}

// const casr

int main() {
    const int a = 0;
    int *p1 = const_cast<int *>(&a); //    去掉常量的转换，语言级别没有问题
    // static_cast 编译器默认,没有任何的联系的类型转换就会被否定
    // reinterpet_cast 就是c的强制转换
    // dynamic_cast( rtti)

//    int *b = static_cast<int *>(&a);
    int *p = nullptr;
    // 不安全
    double *b = reinterpret_cast<double  *>(p);



    Derive1 d1;
    Derive2 d2;
    showFunc(&d1);
    showFunc(&d2);

    return 0;
}