#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class ThreadSafeSingleton{
    private:
        static ThreadSafeSingleton*instance;
        static std::mutex lock;
    
    ThreadSafeSingleton(){}

    public:
        static ThreadSafeSingleton* getinstance(){
            lock_guard<mutex> gurad(lock);//lock for the critical section , so that only one thread enters at a time 
            if(instance==NULL){
                instance=new ThreadSafeSingleton();
            }
            return instance;
        }

};

ThreadSafeSingleton * ThreadSafeSingleton::instance=NULL;
mutex ThreadSafeSingleton::lock;

int main(){

    ThreadSafeSingleton*instance1=ThreadSafeSingleton::getinstance();
    ThreadSafeSingleton*instance2=ThreadSafeSingleton::getinstance();


    cout<<instance1<<endl;
    cout<<instance2<<endl;  

    return 0;
}