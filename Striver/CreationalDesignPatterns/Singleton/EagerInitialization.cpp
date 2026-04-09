#include <bits/stdc++.h>
using namespace std;

class EagerSingleton{
    private:
        static EagerSingleton* instance;
        EagerSingleton(){
            cout << "Constructor called\n";
        }
    public:
        static EagerSingleton* getinstance(){
            return instance;
        }
};

EagerSingleton* EagerSingleton::instance =  new EagerSingleton();//at the starting of program , we made the instance

int main(){
    EagerSingleton* instance1 = EagerSingleton::getinstance();
    EagerSingleton* instance2 = EagerSingleton::getinstance();
    cout<<instance1<<endl;
    cout<<instance2<<endl;
    
    return 0;
}