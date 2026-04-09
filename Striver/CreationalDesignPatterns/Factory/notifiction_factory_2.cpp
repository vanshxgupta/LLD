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
    virtual Notification*createNotification()=0;
    virtual ~NotificationFactory(){};
};

class EmailNotificationFactory:public NotificationFactory{
    public:
    Notification*createNotification() override{
        return new EmailNotifcation;
    }
};

class WhtsNotificationFactory: public NotificationFactory{
    public:
    Notification*createNotification() override{
        return new WhtsNotifcation;
    }  
};

int main(){
    NotificationFactory* f1 = new EmailNotificationFactory();
    NotificationFactory* f2 = new WhtsNotificationFactory();

    Notification* notify1 = f1->createNotification();
    Notification* notify2 = f2->createNotification();
    
    if(notify1)notify1->sendnotification();
    if(notify2)notify2->sendnotification();

    delete notify1;
    delete notify2;

    return 0;
}