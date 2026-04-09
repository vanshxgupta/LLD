#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class DoubleCheckedSingleton{
    private:
        static DoubleCheckedSingleton*instance;
        static mutex lock;
    
    DoubleCheckedSingleton(){}

    public:
        static DoubleCheckedSingleton* getinstance(){
            if(instance==NULL){
                lock_guard<mutex> gurad(lock);
                if(instance==NULL){
                    instance=new DoubleCheckedSingleton();
                }
            }
            return instance;
        }

};

DoubleCheckedSingleton * DoubleCheckedSingleton::instance=NULL;
mutex DoubleCheckedSingleton::lock;

int main(){

    DoubleCheckedSingleton*instance1=DoubleCheckedSingleton::getinstance();
    DoubleCheckedSingleton*instance2=DoubleCheckedSingleton::getinstance();


    cout<<instance1<<endl;
    cout<<instance2<<endl;  

    return 0;
}