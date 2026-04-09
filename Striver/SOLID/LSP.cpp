#include <bits/stdc++.h>
using namespace std;

class NotificationSystem{
    public:
    //make the method virtual , to override in the derived class
    virtual void sendnotifaction(){
        cout<<"Email send"<<endl;
    }
    virtual ~NotificationSystem() {}
};

class TextNotification: public NotificationSystem{
    public:
    void sendnotifaction() override{
        cout<<"Text send"<<endl;
    }
};

class WhatsappNotification:public NotificationSystem{
    public:
    void sendnotifaction() override{
        cout<<"WHatsapp send"<<endl;
    }
};

int main(){

    NotificationSystem ns;
    ns.sendnotifaction();

    NotificationSystem* ns1=new NotificationSystem();
    ns1->sendnotifaction();

    //lsp followed
    NotificationSystem* ns2=new TextNotification();
    ns2->sendnotifaction();

    NotificationSystem* ns3=new WhatsappNotification();
    ns3->sendnotifaction();

    delete ns1;
    delete ns2;
    delete ns3;

    return 0;
}