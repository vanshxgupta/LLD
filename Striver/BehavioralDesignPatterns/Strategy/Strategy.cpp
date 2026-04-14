#include<bits/stdc++.h>
using namespace std;

// <<interface>>
class MatchingStrategy{
    public:
    virtual void match(int x,int y)=0;
    virtual ~MatchingStrategy(){}
};

class NearstDriveStrategy:public MatchingStrategy{
    public:
    void match(int x,int y) override{
        cout<<"Matching with NearstDriveStrategy for location : ("<<x<<","<<y<<")"<<endl;
    }
};
class AirportQueueStrategy:public MatchingStrategy{
    public:
     void match(int x,int y) override{
        cout<<"Matching with AirportQueueStrategy for location : ("<<x<<","<<y<<")"<<endl;
    }
};
class SurgePriorityStrategy:public MatchingStrategy{
    public:
    void match(int x,int y) override{
        cout<<"Matching with SurgePriorityStrategy for location : ("<<x<<","<<y<<")"<<endl;
    }
};

class RiderMatchingStrategy{
    MatchingStrategy*strategy;
    public:
    RiderMatchingStrategy(MatchingStrategy*strategy){
        this->strategy=strategy;
    }
    void setStrategy(MatchingStrategy* s){
        strategy=s;
    }
    void matchrider(int x,int y){
        strategy->match(x,y);
    }
};

int main(){
    RiderMatchingStrategy* strategy1=new RiderMatchingStrategy(new AirportQueueStrategy());
    strategy1->matchrider(4,7);
    strategy1->setStrategy(new SurgePriorityStrategy());
    strategy1->matchrider(123,7);
    strategy1->matchrider(4,71234);
    
    delete strategy1;

}