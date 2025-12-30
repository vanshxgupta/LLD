#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Car{
    public:
    virtual void startengine()=0;
    virtual void stopengine()=0;
    virtual void accelerate()=0;
    virtual void brake()=0;
    virtual void shiftgear()=0;
    virtual ~Car(){}
};

class SportsCar: public Car{

    public:
    string brand;
    string model;
    int currspeed;
    int currgear;
    bool isEngineOn;

    SportsCar(string b,string a){
        this->brand=b;
        this->model=a;
        isEngineOn=false;
        currgear=0;
        currspeed=0;
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

    Car *mycar=new SportsCar("Ford","Mustang");
    

    mycar->accelerate();
    mycar->startengine();
    mycar->accelerate();
    mycar->accelerate();
    mycar->brake();
    mycar->stopengine();
    mycar->startengine();
    mycar->shiftgear();
    mycar->brake();
    mycar->stopengine();
    

}