﻿#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <ctime>

using namespace std;

template<typename Container>
void showContainer(Container &con) {
    typename Container::iterator it = con.begin();
    for (; it != con.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

template<typename Iterator, typename Compare>
Iterator my_find_if(Iterator first, Iterator last, Compare comp) {
    for (; first != last; ++first) {
        if (comp(*first)) {
            return first;
        }
    }
    return last;
}
// 其实就是封装了一下，对于val固定值,返回的还是一个函数类型
template<typename Compare, typename T>
class _mybind1st {
private:
    Compare _comp;
    T _val;
public:
    _mybind1st(Compare comp, T val)
            : _comp(comp), _val(val) {}

    bool operator()(const T &second) {
        return _comp(_val, second);
    }
};

// mybind1st(grater<int>(),70)
template<typename Compare, typename T>
_mybind1st<Compare, T> mybind1st(Compare comp, const T &val) {
    return _mybind1st<Compare, T>(comp, val);
}

int main() {
    vector<int> vec;
    srand(time(nullptr));
    for (int i = 0; i < 20; ++i) {
        vec.push_back(rand() % 100 + 1);
    }
    showContainer(vec);
    sort(vec.begin(), vec.end());
    showContainer(vec);
    sort(vec.begin(), vec.end(), greater<int>());
    showContainer(vec);
    /*
    把70按顺序插入到vec容器中，即找第一个小于70的数
    operator() (const T& val)
    绑定器 + 二元函数对象 =》 一元函数对象
    bind1st: + greater bool operator() (70, const _Ty& _Right)
    bind2nd: + less bool operator() (const _Ty& _Left, 70)
    */
    auto it1 = find_if(vec.begin(), vec.end(),
                       bind1st(greater<int>(), 70));
    if (it1 != vec.end()) {
        vec.insert(it1, 70);
    }
    showContainer(vec);

    auto it2 = my_find_if(vec.begin(), vec.end(),
                          bind2nd(less<int>(), 71));
    if (it2 != vec.end()) {
        vec.insert(it2, 72);
    }
    showContainer(vec);

    return 0;
}