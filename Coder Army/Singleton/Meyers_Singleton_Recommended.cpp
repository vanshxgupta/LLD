#include <bits/stdc++.h>
using namespace std;

class Singleton {
private:
    Singleton() {}

public:
    Singleton(const Singleton&) = delete;// copy constructor band hai
    Singleton& operator=(const Singleton&) = delete; //assignment bhi band

    static Singleton& getInstance() {
        static Singleton instance;  // Thread-safe in C++11+
        return instance;
    }

    void doSomething() {
        std::cout << "Singleton operation" << std::endl;
    }
};

int main(){

    Singleton& s1 = Singleton::getInstance();
    // Singleton s2 = s1;//-> as copy constructor is band , we cannot do this , otherwise this creates a new object
    s1.doSomething();

    return 0;
}