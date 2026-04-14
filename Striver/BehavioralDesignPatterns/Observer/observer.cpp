#include<bits/stdc++.h>
using namespace std;

// <<interface>>
class Subscriber{
    public:
    virtual void update(string title)=0;
    virtual ~Subscriber(){}
};

class EmailSubscriber:public Subscriber{
    string email;
    public:
    EmailSubscriber(string email):email(email){}
    void update(string title) override{
        cout<<email << " : Watch : "<<title<<endl;
    }
};

class MobileAppSubscriber:public Subscriber{
    string username;
    public:
    MobileAppSubscriber(string username):username(username){}
    void update(string title) override{
        cout<<username<<": Watch : "<<title<<endl;
    }
};

// <<interface>>
class Channel{
    public:
    virtual void subscribe(Subscriber* sub)=0;
    virtual void unsubscribe(Subscriber* sub)=0;
    virtual void notify(string videotitle)=0;
    virtual ~Channel(){}
};

class YoutubeChannel:public Channel{
    unordered_set<Subscriber* >subscribers;
    public:
    void subscribe(Subscriber* sub) override{
        subscribers.insert(sub);
    }
    void unsubscribe(Subscriber* sub) override{
        subscribers.erase(sub);
    }
    void notify(string videotitle) override{
        for(auto it:subscribers){//push notifcation to all subscribers 
            it->update(videotitle);
        }
    }
};

int main(){

    Channel* SmallTownBoys=new YoutubeChannel();
    Subscriber* sub1=new MobileAppSubscriber("vanshxgupta");
    Subscriber* sub2=new MobileAppSubscriber("gupta");
    Subscriber* sub3=new MobileAppSubscriber("vansh");
    Subscriber* sub4=new MobileAppSubscriber("vanshgupta");
    Subscriber* sub5=new MobileAppSubscriber("vansh gmail");
    
    SmallTownBoys->subscribe(sub1);
    SmallTownBoys->subscribe(sub2);
    SmallTownBoys->subscribe(sub3);
    SmallTownBoys->subscribe(sub4);
    SmallTownBoys->subscribe(sub5);

    SmallTownBoys->notify("New Video Watch Now");

    return 0;
}