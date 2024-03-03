//
// Created by lhc456 on 2024/3/3.
//
//#include <iostream>
//
//class GrandParent {
//public:
//    std::string m_00;
//
//    GrandParent() {
//        m_00 = "grandParent";
//        std::cout << "GrandParent constructed !" << std::endl;
//    }
//};
//
//class Father : public GrandParent {
//public:
//    std::string m_11;
//
//    Father() {
//        m_11 = "Father";
//        std::cout << "Father constructed !" << std::endl;
//    }
//};
//
//class Mother : public GrandParent {
//public:
//    std::string m_22;
//
//    Mother() {
//        m_22 = "Mother";
//        std::cout << "Mother constructed !" << std::endl;
//    }
//};
//
//class GrandSon : public Father, public Mother {
//public:
//    std::string m_33;
//
//    GrandSon() {
//        m_33 = "GrandSon";
//        std::cout << "GrandSon constructed !" << std::endl;
//    }
//};
//
//int main() {
//    GrandSon grandSon;
//    std::cout << grandSon.Mother::m_00 << std::endl;
//    std::cout << grandSon.Father::m_00 << std::endl;
//    std::cin.get();
//}

解释

#include <iostream>

class GrandParent {
public:
    std::string m_00;

    GrandParent() {
        m_00 = "grandParent";
        std::cout << "GrandParent constructed !" << std::endl;
    }
};

class Father : virtual public GrandParent {
public:
    std::string m_11;

    Father() {
        m_11 = "Father";
        std::cout << "Father constructed !" << std::endl;
    }
};

class Mother : virtual public GrandParent {
public:
    std::string m_22;

    Mother() {
        m_22 = "Mother";
        std::cout << "Mother constructed !" << std::endl;
    }
};

class GrandSon : public Father, public Mother {
public:
    std::string m_33;

    GrandSon() {
        m_33 = "GrandSon";
        std::cout << "GrandSon constructed !" << std::endl;
    }
};

int main() {
    GrandSon grandSon;
    std::cout << grandSon.Mother::m_00 << std::endl;
    std::cout << grandSon.Father::m_00 << std::endl;
    std::cout << grandSon.m_00 << std::endl;
    std::cin.get();
}