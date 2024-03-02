//
// Created by lhc456 on 2024/3/2.
//
#include <iostream>

template<typename T>
class SeqStack {
public:
    SeqStack(int size = 10) : _pstack(new T[size]), _size(size), _top(0) {

    }

    ~SeqStack() {
        delete[] _pstack;
        _pstack = nullptr;
    }

    SeqStack(const SeqStack<T> &stack) : _top(stack._top), _size(stack._size) {
        _pstack = nullptr;
        _pstack = new T[_size];
        for (int i = 0; i < _top; i++) {
            _pstack[i] = stack._pstack[i];
        }
    }

    SeqStack<T> &operator=(const SeqStack<T> &stack) {
        if (this == &stack) {
            return *this;
        }
        delete[] _pstack;

        _top = stack._top;
        _size = stack._size;
        _pstack = new T[_size];
        for (int i = 0; i < _top; i++) {
            _pstack[i] = stack._pstack[i];
        }
        return *this;
    }

    void push(const T &val) {
        if (full()) {
            expand();
        }
        _pstack[_top++] = val;
    }

    void pop() {
        if (empty()) {
            return;
        }
        --_top;
    }

    T top() const {
        if (empty()) {
            throw "stack is empty!";
        }
        return _pstack[_top - 1];
    }

    bool empty() const {
        return _top == 0;

    }

    bool full() const {
        return _top == _size;
    }


private:
    T *_pstack;
    int _top;
    int _size;

    void expand() {
        T *ptmp = new T[_size * 2];
        for (int i = 0; i < _top; i++) {
            _pstack[i] = _pstack[i];
        }
        delete[] _pstack;
        _pstack = ptmp;
        _size *= 2;
    }

};

int main() {
    SeqStack<int> s1;
    s1.push(20);
    s1.push(78);
    s1.pop()
    return 0;
}