#include <iostream>
#include <variant>

using namespace std;

class A {
private:
    std::string m_int;
public:
    A(){}
    A(std::string i): m_int(i){}
    void printObj() const {
        std::cout<<"Hello World!\n";
    }
    std::string getVal() const {
        return m_int; 
    }
};

class B {
private:
    std::string m_string;
public:
    B(){}
    B(std::string str): m_string(str){}
    void printObj() const {
        std::cout<<"Hello Mars!\n";
    }
    std::string getVal() const {
        return m_string; 
    }
};

using Var = std::variant<A, B>;
struct CallablePrintObj {
    template<typename T> // using templates you create generic signature of the concrete obj methods
    void operator()(const T& obj) {
        obj.printObj();
    }
};
struct CallableGetValue {
    template<typename T> // same here
    std::string operator()(const T& obj) {
        return obj.getVal();
    }
};

int main()
{
    A a("Another trick!");
    B b("Nice trick!");
    Var v1, v2; // This is like interface ref objects
    
    v1 = a; // assign ref objects to concrete types and get desired results
    std::visit(CallablePrintObj{}, v1);
    std::cout<< std::visit(CallableGetValue{}, v1) <<"\n";
    
    v2 = b; // same here: assign ref objects to concrete types
    std::visit(CallablePrintObj{}, v2);
    std::cout<< std::visit(CallableGetValue{}, v2) <<"\n";
    
    return 0;
}
