#include <bits/stdc++.h>
using namespace std;

//Lazy initialization
//not thread safe
//but provide the memory efficient solution

class LazySingleton{
    private:
        static LazySingleton* instance;
        // Private constructor prevents creating objects from outside the class
        LazySingleton(){
            cout << "Constructor called\n";
        }

    public:
    static LazySingleton* getinstance(){
        if(instance==NULL){
            instance=new LazySingleton();
        }
        // instance=new LazySingleton();
        return instance;
    }
};

LazySingleton* LazySingleton::instance = NULL;// Initialize the static member variable

int main(){
    LazySingleton* instance1 = LazySingleton::getinstance();
    LazySingleton* instance2 = LazySingleton::getinstance();

    //address same aa skta hai dono instances ka if singleton na bhi ho tooh ,
    // isliye singleton check krna hai tooh address se nahi , constructor call se check kr , 
    // sirf 1 baar constuctor call ->single instance
    cout<<instance1<<endl;
    cout<<instance2<<endl;
    
    return 0;
}