//
// Created by lhc456 on 2024/3/10.
//

#include <functional>
#include <iostream>
#include <string>

using namespace std;

void hello(string abc) { std::cout << "hello! "<< abc << std::endl; }

int sum(int a, int b) {
    return a + b;
}

class Test {
public:
    int sum(int a, int b) {
        return a + b;
    }
};

int main() {
    bind(hello, "123")();
    cout << bind(sum, 1, 2)() << endl;
    cout << bind(&Test::sum, Test(), 20, 30)() << endl;

    bind(hello, placeholders::_1)("xinxin");
}
