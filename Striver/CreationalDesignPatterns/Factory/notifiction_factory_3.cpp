
//factory method , but with the use of the unique_ptr and make_unique
// with the use of unique_ptr and make_unique , we don't have to delete the memory manully 

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
    virtual unique_ptr<Notification>createNotification()=0;
    virtual ~NotificationFactory(){};
};

class EmailNotificationFactory:public NotificationFactory{
    public:
    unique_ptr<Notification> createNotification() override{
        return make_unique<EmailNotifcation>();
    }
};

class WhtsNotificationFactory: public NotificationFactory{
    public:
    unique_ptr<Notification>createNotification() override{
        return make_unique<WhtsNotifcation>();
    }  
};

int main(){

    unique_ptr<NotificationFactory> f1 = make_unique<EmailNotificationFactory>();
    unique_ptr<NotificationFactory> f2 = make_unique<WhtsNotificationFactory>();

    unique_ptr<Notification> notify1 = f1->createNotification();
    unique_ptr<Notification> notify2 = f2->createNotification();

    
    if(notify1)notify1->sendnotification();
    if(notify2)notify2->sendnotification();

    return 0;
}