#include<bits/stdc++.h>
using namespace std;

class VendingMachine;//declaration

//machine interface
class MachineState{
    public:
    virtual void selectitem(VendingMachine*context,string itemCode)=0;
    virtual void insertcoin(VendingMachine*context,double amount)=0;
    virtual void dispenseitem(VendingMachine*context)=0;
    virtual ~MachineState(){}
};

class IdleState;
class ItemSelectedState;
class HasCoinState;
class DispenseState;

class VendingMachine{
    MachineState*currentState;
    string selectedItem;
    double insertedAmount;

    public:
    VendingMachine(){
        selectedItem="";
        insertedAmount=0;
        currentState=new IdleState();
    }
    ~VendingMachine() {
        delete currentState;
    }

    void setstate(MachineState*newstate){
        delete currentState;
        currentState=newstate;
    }
    void setselecteditem(string itemcode){
        currentState->selectitem(this, itemcode);
    }
    void setinsertedamount(double amount){
        insertedAmount+=amount;
        currentState->insertcoin(this,insertedAmount);
    }
    void dispenseitem(){
        currentState->dispenseitem(this);
    }
    string getselecteditem(){
        return selectedItem;
    }
    double getinsertedamount(){
       return insertedAmount;
    }
    void reset() {
        selectedItem = "";
        insertedAmount = 0.0;
        setstate(new IdleState());
    }
};

class IdleState:public MachineState{
    public:
    void selectitem(VendingMachine* context,string itemcode) override{
        cout<<"[IdleState] Item "<<itemcode<<" selected"<<endl;
        context->setselecteditem(itemcode);
        context->setstate(new ItemSelectedState());
    }
    void insertcoin(VendingMachine*context,double amount) override{
        cout<<"[IdleState] Please select an item before inserting coins."<<endl;
    }
    void dispenseitem(VendingMachine*context) override{
        cout<<"[IdleState] Please select an item and insert coins before dispensing."<<endl;
    }
};

class ItemSelectedState:public MachineState{
    void selectitem(VendingMachine* context,string itemcode) override{
        cout<<"Item already selected" <<context->getselecteditem() <<"Please insert coins."<<endl;

    }
    void insertcoin(VendingMachine*context,double amount) override{
        cout<<"[ItemSelectedState] Total Inserted amount: "<<context->getinsertedamount()<<endl;
        context->setinsertedamount(amount);
        context->setstate(new HasCoinState());
    }
    void dispenseitem(VendingMachine*context) override{
        cout<<"[ItemSelectedState] Please insert coins before dispensing."<<endl;
    }
    
};

class HasCoinState:public MachineState{
    public:
     void selectitem(VendingMachine* context,string itemcode) override{
        cout<<"[HasCoinState] Item already selected: "<<context->getselecteditem()<<endl;
    }
    void insertcoin(VendingMachine*context,double amount) override{
        cout << "Money already inserted." << endl;
    }
    void dispenseitem(VendingMachine*context) override{
        cout << "Dispensing item: " << context->getselecteditem() << endl;
        context->setstate(new DispenseState());
        cout << "Item dispensed successfully." << endl;
        context->reset();
    }
};

class DispenseState:public MachineState{
    public:
     void selectitem(VendingMachine* context,string itemcode) override{
        cout<<"[DispenseState] Please wait, dispensing item: "<<context->getselecteditem()<<endl;
    }
    void insertcoin(VendingMachine*context,double amount) override{
        cout<<"[DispenseState] Please wait, dispensing item: "<<context->getselecteditem()<<endl;
    }
    void dispenseitem(VendingMachine*context) override{
        cout<<"[DispenseState] Please wait, dispensing item: "<<context->getselecteditem()<<endl;
    }
};


int main(){
    VendingMachine vm;
    vm.setselecteditem("A1");
    vm.setinsertedamount(2.0);
    vm.dispenseitem();
    return 0;
};