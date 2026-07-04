#include <bits/stdc++.h>
using namespace std;


// class UserInterface{
    // public:
    //     virtual void bookride()=0;
    //     virtual void pay()=0;
    //     virtual void acceptride()=0;
    //     virtual void drive()=0;
    //     virtual void endride()=0;
    // };
    

//isp ->interface segregation principle
class RiderInterface{
    public:
    virtual void bookride()=0;
    virtual void pay()=0;
    virtual ~RiderInterface() {}
};

class DriverInterface{
    public:
        virtual void acceptride()=0;
        virtual void drive()=0;
        virtual void endride()=0;
        virtual ~DriverInterface() {}
};

class Rider: public RiderInterface{
    public:
    void bookride() override{
        cout<<"Ride Booked"<<endl;
    }
    void pay() override{
        cout<<"Payment Success"<<endl;
    }
};

class Driver: public DriverInterface{
    public:
    void acceptride() override{
        cout<<"Ride Accepted"<<endl;
    }
    void drive() override{
        cout<<"Driving.."<<endl;
    }
    void endride() override{
        cout<<"Ride Completed"<<endl;
    }
};


int main(){

    //make a ride request by rider 
    //driver accepts the ride request
    //then drives
    //end ride
    //then rider pays

    Rider r;
    Driver d;

    r.bookride();
    d.acceptride();
    d.drive();
    d.endride();
    r.pay();

    return 0;
}