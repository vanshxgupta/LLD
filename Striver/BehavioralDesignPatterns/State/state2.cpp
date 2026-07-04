#include<bits/stdc++.h>
using namespace std;

class VendingMachine;

// ================= INTERFACE =================
class MachineState{
public:
    virtual void selectitem(VendingMachine* context,string itemCode)=0;
    virtual void insertcoin(VendingMachine* context,double amount)=0;
    virtual void dispenseitem(VendingMachine* context)=0;
    virtual ~MachineState(){}
};

// Forward declarations
class IdleState;
class ItemSelectedState;
class HasCoinState;
class DispenseState;

// ================= CONTEXT =================
class VendingMachine{
    MachineState* currentState;
    string selectedItem;
    double insertedAmount;

public:
    VendingMachine();
    ~VendingMachine();

    void setState(MachineState* newState);

    // Public APIs
    void selectItem(string itemCode);
    void insertCoin(double amount);
    void dispenseItem();

    // Internal helpers
    void setSelectedItemInternal(string itemCode);
    void addAmountInternal(double amount);

    string getSelectedItem();
    double getInsertedAmount();

    void reset();
};

// ================= STATES =================

class IdleState: public MachineState{
public:
    void selectitem(VendingMachine* context,string itemcode) override;
    void insertcoin(VendingMachine* context,double amount) override;
    void dispenseitem(VendingMachine* context) override;
};

class ItemSelectedState: public MachineState{
public:
    void selectitem(VendingMachine* context,string itemcode) override;
    void insertcoin(VendingMachine* context,double amount) override;
    void dispenseitem(VendingMachine* context) override;
};

class HasCoinState: public MachineState{
public:
    void selectitem(VendingMachine* context,string itemcode) override;
    void insertcoin(VendingMachine* context,double amount) override;
    void dispenseitem(VendingMachine* context) override;
};

class DispenseState: public MachineState{
public:
    void selectitem(VendingMachine* context,string itemcode) override;
    void insertcoin(VendingMachine* context,double amount) override;
    void dispenseitem(VendingMachine* context) override;
};

// ================= CONTEXT IMPLEMENTATION =================

VendingMachine::VendingMachine(){
    selectedItem="";
    insertedAmount=0;
    currentState=new IdleState();
}

VendingMachine::~VendingMachine(){
    delete currentState;
}

void VendingMachine::setState(MachineState* newState){
    delete currentState;
    currentState=newState;
}

void VendingMachine::selectItem(string itemCode){
    currentState->selectitem(this,itemCode);
}

void VendingMachine::insertCoin(double amount){
    currentState->insertcoin(this,amount);
}

void VendingMachine::dispenseItem(){
    currentState->dispenseitem(this);
}

void VendingMachine::setSelectedItemInternal(string itemCode){
    selectedItem=itemCode;
}

void VendingMachine::addAmountInternal(double amount){
    insertedAmount+=amount;
}

string VendingMachine::getSelectedItem(){
    return selectedItem;
}

double VendingMachine::getInsertedAmount(){
    return insertedAmount;
}

void VendingMachine::reset(){
    selectedItem="";
    insertedAmount=0;
    setState(new IdleState());
}

// ================= STATE IMPLEMENTATIONS =================

// IdleState
void IdleState::selectitem(VendingMachine* context,string itemcode){
    cout<<"[Idle] Item selected: "<<itemcode<<endl;
    context->setSelectedItemInternal(itemcode);
    context->setState(new ItemSelectedState());
}

void IdleState::insertcoin(VendingMachine*,double){
    cout<<"[Idle] Select item first\n";
}

void IdleState::dispenseitem(VendingMachine*){
    cout<<"[Idle] Nothing to dispense\n";
}

// ItemSelectedState
void ItemSelectedState::selectitem(VendingMachine* context,string){
    cout<<"Item already selected: "<<context->getSelectedItem()<<endl;
}

void ItemSelectedState::insertcoin(VendingMachine* context,double amount){
    context->addAmountInternal(amount);
    cout<<"Inserted: "<<context->getInsertedAmount()<<endl;
    context->setState(new HasCoinState());
}

void ItemSelectedState::dispenseitem(VendingMachine*){
    cout<<"Insert coins first\n";
}

// HasCoinState
void HasCoinState::selectitem(VendingMachine* context,string){
    cout<<"Already selected: "<<context->getSelectedItem()<<endl;
}

void HasCoinState::insertcoin(VendingMachine* context,double amount){
    context->addAmountInternal(amount);
    cout<<"Total amount: "<<context->getInsertedAmount()<<endl;
}

void HasCoinState::dispenseitem(VendingMachine* context){
    cout<<"Dispensing "<<context->getSelectedItem()<<endl;
    context->setState(new DispenseState());
    cout<<"Item dispensed successfully\n";
    context->reset();
}

// DispenseState
void DispenseState::selectitem(VendingMachine*,string){
    cout<<"Wait, dispensing...\n";
}

void DispenseState::insertcoin(VendingMachine*,double){
    cout<<"Wait, dispensing...\n";
}

void DispenseState::dispenseitem(VendingMachine*){
    cout<<"Already dispensing...\n";
}

// ================= MAIN =================

int main(){
    VendingMachine vm;

    vm.selectItem("A1");
    vm.insertCoin(10);
    vm.dispenseItem();

    return 0;
}