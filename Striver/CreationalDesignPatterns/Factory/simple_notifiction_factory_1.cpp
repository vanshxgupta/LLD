#include<bits/stdc++.h>
using namespace std;


class Notification{
    public:
    virtual void sendnotification()=0;
    virtual ~Notification(){};
};


class EmailNotifcation:public Notification{
    public:
    void sendnotification() override{
        cout<<"Email Notifucation"<<endl;
    }
};
class WhtsNotifcation:public Notification{
    public:
    void sendnotification() override{
        cout<<"whts Notifucation"<<endl;
    }
};

class NotificationFactory{
    public:
    static Notification* createNotification(string type){
        if(type=="email") return new EmailNotifcation;
        if(type=="whatsapp") return new WhtsNotifcation;
        return nullptr;
    }

};

int main(){

    Notification*notify1=NotificationFactory::createNotification("email");

    Notification*notify2=NotificationFactory::createNotification("whatsapp");
    Notification*notify3=NotificationFactory::createNotification("");
    
    if(notify1)notify1->sendnotification();
    if(notify2)notify2->sendnotification();
    if(notify3)notify3->sendnotification();

    delete notify1;
    delete notify2;

    return 0;
}