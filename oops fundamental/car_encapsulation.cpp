#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class SportsCar{

    private:
    string brand;
    string model;
    int currspeed;
    int currgear;
    bool isEngineOn;

    public:
    SportsCar(string b,string a){
        this->brand=b;
        this->model=a;
        isEngineOn=false;
        currgear=0;
        currspeed=0;
    }

    //we can get and set from this methods, 
    int getspeed(){
        return this->currspeed;
    }
    void setspeed(int speed){//here we can set the speed , the user can set the speed with this method from outside, but this method is secure because we can have validations in this method 
        //validations 
        this->currspeed=speed;
    }

    void startengine(){
        isEngineOn=true;
        cout<<brand<<" "<<model<<" "<<"Engine starts with a roar"<<endl;
    }
    void stopengine(){
        isEngineOn=false;
        cout<<brand<<" "<<model<<" "<<"Engine stops...."<<endl;
    }
    void accelerate(){
        if(!isEngineOn){
            cout<<"Engine is off... cant't be accelerated"<<endl;
            return;
        }
        currspeed+=20;
        cout<<brand<<" "<<model<<" "<<"Car accerelates.... now speed="<<currspeed<<endl;
    }
    void brake(){
        if(!isEngineOn){
            cout<<"Engine is off...brake cant't be applied"<<endl;
            return;
        }
        currspeed-=20;
        cout<<brand<<" "<<model<<" "<<"Car brakes applied.... now speed="<<currspeed<<endl;
    }
    void shiftgear(){
        if(!isEngineOn){
            cout<<"Engine is off...gear cant't be shifted"<<endl;
            return;
        }
        currgear=currgear+1;
        cout<<brand<<" "<<model<<" "<<"Gear shifted to:"<<currgear<<endl;
        
    }

};

int main(){

    SportsCar *mycar=new SportsCar("Ford","Mustang");
    
    // mycar->currspeed=50;//->working only when the currspeed is public 

    mycar->setspeed(100);
    mycar->getspeed();
    mycar->accelerate();
    mycar->startengine();
    mycar->accelerate();
    mycar->getspeed();
    mycar->setspeed(50);
    mycar->getspeed();
    mycar->accelerate();
    mycar->brake();
    mycar->stopengine();
    mycar->startengine();
    mycar->shiftgear();
    mycar->brake();
    mycar->stopengine();
    
    

}