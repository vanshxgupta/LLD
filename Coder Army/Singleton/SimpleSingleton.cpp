
//static is used when you want a variable, method, or member to belong to the class itself rather than to individual objects (instances).
// class Student {
//     static String school = "ABC School";
// }
// Here, every Student object shares the same school value. Only one copy exists in memory.

#include<iostream>

using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() {
        cout << "Singleton Constructor called" << endl;
    }

public:
    static Singleton* getInstance() {
        if(instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}