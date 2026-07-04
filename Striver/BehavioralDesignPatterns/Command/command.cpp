#include<bits/stdc++.h>
using namespace std;

// interface
class Command{
public:
    virtual void execute()=0;
    virtual void undo()=0;
    virtual ~Command(){}
};

// Receiver
class Light{
public:
    void on(){
        cout<<"Light Turned On"<<endl;;
    }
    void off(){
        cout<<"Light Turned Off"<<endl;
    }
};

// Command
class LightCommand:public Command{
    Light* light;

public:
    LightCommand(Light* l){
        light = l;
    }

    void execute() override{
        light->on();
    }

    void undo() override{
        light->off();
    }
};

// Receiver
class Fan{
public:
    void on(){
        cout<<"Fan Turned On"<<endl;
    }
    void off(){
        cout<<"Fan Turned Off"<<endl;
    }
};

// Command
class FanCommand:public Command{
    Fan* fan;

public:
    FanCommand(Fan* f){
        fan = f;
    }

    void execute() override{
        fan->on();
    }

    void undo() override{
        fan->off();
    }
};

// Invoker
class RemoteControl{
    vector<Command*>buttons;
    stack<Command*>history;

public:
    RemoteControl(){
        buttons.resize(4,nullptr);
    }

    void setcommand(Command* command,int index){
        if(index>=4){
            cout<<"Invalid index"<<endl;
            return;
        }
        buttons[index]=command;
    }

    void pressbutton(int index){
        if(index>=4 || buttons[index]==nullptr){
            cout<<"No command assigned"<<endl;
            return;
        }
        buttons[index]->execute();
        history.push(buttons[index]);
    }

    void pressundo(){
        if(history.empty()){
            cout<<"Nothing to undo\n";
            return;
        }
        Command* cmd = history.top();
        history.pop();
        cmd->undo();
    }
};

int main(){
    RemoteControl remote;

    Light* l = new Light();
    Fan* f = new Fan();

    remote.setcommand(new LightCommand(l),2);
    remote.setcommand(new FanCommand(f),3);

    remote.pressbutton(2);
    remote.pressundo();

    return 0;
}