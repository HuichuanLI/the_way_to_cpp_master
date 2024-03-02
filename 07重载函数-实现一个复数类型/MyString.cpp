//
// Created by lhc456 on 2024/3/2.
//


#include <iostream>
#include <string>

using namespace std;


class MyString {
public:
    MyString(const char *p = nullptr) {
        if (p != nullptr) {
            p_str = new char[strlen(p) + 1];
            stpcpy(p_str, p);
        } else {
            p_str = new char[1];
            *p_str = '\0';
        }
    }

    ~MyString() {
        delete[] p_str;
        p_str = nullptr;
    }

    MyString(const MyString &str) {
        p_str = new char[strlen(str.p_str) + 1];
        strcpy(p_str, str.p_str);

    }

    MyString operator=(const MyString src) {
        if (this == &src) {
            return *this;
        }

        delete[] p_str;
        p_str = new char[strlen(src.p_str) + 1];
        strcpy(p_str, src.p_str);
        return *this;

    }

    bool operator>(const MyString &str) const {
        return strcmp(p_str, str.p_str) > 0;
    }

    bool operator<(const MyString &str) const {
        return strcmp(p_str, str.p_str) < 0;
    }

    bool operator==(const MyString &str) const {
        return strcmp(p_str, str.p_str) == 0;
    }

    int length() const { return strlen(p_str); }

    char &operator[](int index) { return p_str[index]; };

    const char &operator[](int index) const { return p_str[index]; }

    const char *c_str() const { return p_str; }


private:
    char *p_str;

    friend ostream &operator<<(ostream &out, const MyString &str);

    friend MyString operator+(const MyString &lhs, const MyString &rhs);

};

ostream &operator<<(ostream &out, const MyString &str) {
    out << str.p_str;
    return out;
}

MyString operator+(const MyString &lhs, const MyString &rhs) {
    char *ptmp = new char[strlen(lhs.p_str) + strlen(rhs.p_str) + 1];
    strcpy(ptmp, lhs.p_str);
    strcat(ptmp, rhs.p_str);
    return MyString(ptmp);
}

int main() {
    MyString str1 = "abf";
    MyString str2 = "abc";
    MyString  str3 = str1 + str2;
    cout << str3 << endl;
    cout << "--------------------" << endl;

    return 0;
}