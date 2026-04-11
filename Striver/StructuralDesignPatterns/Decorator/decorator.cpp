#include<bits/stdc++.h>
using namespace std;

//interface
class Pizza{
    public:
    virtual double getamount()=0;
    virtual string getdesc()=0;
    virtual ~Pizza(){}
};

class SimplePizza:public Pizza{
    public:
    double getamount() override{
        return 100;
    }
    string getdesc() override{
        return "Pizza";
    }
};
class MargheritaPizza:public Pizza{
    public:
    double getamount() override{
        return 150;
    }
    string getdesc() override{
        return "MargheritaPizza";
    }
};

//abstract class
class PizzaDecorator:public Pizza{
    protected:
    Pizza *pizza;
    public:
    PizzaDecorator(Pizza*pizza){
        this->pizza=pizza;
    }
};

class withChesse:public PizzaDecorator{
    public:
    withChesse(Pizza*pizza):PizzaDecorator(pizza){}

    double getamount() override{
        return pizza->getamount()+20;
    }
    string getdesc() override{
        return  pizza->getdesc() + "WithChesse";
    }
};

class withOlives:public PizzaDecorator{
    public:
    withOlives(Pizza*pizza):PizzaDecorator(pizza){}
    double getamount() override{
        return pizza->getamount()+50;
    }
    string getdesc() override{
        return pizza->getdesc() +"WithOlives";
    }
};

int main(){
    Pizza*pizza=new withChesse(new withOlives(new MargheritaPizza()));
    cout<<pizza->getamount()<<endl;
    cout<<pizza->getdesc()<<endl;

    delete pizza;
    return 0;
}