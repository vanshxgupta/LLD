#include<bits/stdc++.h>
using namespace std;

//interface Command
class Command{
    public:
    virtual void execute()=0;
    virtual void undo()=0;
    virtual ~Command(){}
};

class Light{
    bool state;
    public:
    void on(){
        state=true;
        cout<<"Light Turned On"<<endl;
    }
    void off(){
        state=false;
        cout<<"Light Turned Off"<<endl;
    }
    bool getstate(){
        return state;
    }
};

class LightCommand:public Command{
    Light light;
    bool prevstate;
    public:
    void execute() override{
        if(prevstate==true) light.off();
        else light.on();
        prevstate=light.getstate();
    }
    void undo() override{
        if(prevstate==true) light.off(); 
        else light.on();
        prevstate=light.getstate();
    }

};

class Fan{
    bool state;
    public:
    void on(){
        state=true;
        cout<<"Fan Turned On"<<endl;
    }
    void off(){
        state=false;
        cout<<"Fan Turned Off"<<endl;
    }
    bool getstate(){
        return state;
    }
};

class FanCommand:public Command{
    Fan fan;
    bool prevstate;
    public:
    void execute() override{
        if(prevstate==true) fan.off();
        else fan.on();
        prevstate=fan.getstate();
    }
    void undo() override{
        if(prevstate==true) {
            fan.off(); 
        }
        else fan.on();
        prevstate=fan.getstate();
    }
};

//Invoker
class RemoteControl{
    vector<Command*>buttons;
    stack<Command*>CommandHistory;
    public:
    RemoteControl(){
        buttons.resize(4,nullptr);
    }
    void setcommand(Command* command,int index){
        if(index>=4){
            cout<<"command index Invalid"<<endl;
        }
        buttons[index]=command;
    }
    void pressbutton(int index){
         if(index>=4 || buttons[index]==nullptr){
            cout<<"No command assigned\n";
            return;
        }
        buttons[index]->execute();
        CommandHistory.push(buttons[index]);
    }
    void pressundo(){
        if(CommandHistory.empty()){
            cout<<"Nothing to undo"<<endl;
            return;
        }
        Command*command=CommandHistory.top();
        CommandHistory.pop();
        command->undo();
    }
};

int main(){
    RemoteControl* remote= new RemoteControl();
    Light *l = new Light();
    remote->setcommand(new LightCommand(),2);
    remote->setcommand(new FanCommand(),3);
    remote->pressbutton(3);
    remote->pressbutton(3);
    remote->pressbutton(3);
    remote->pressundo();
    return 0;
}