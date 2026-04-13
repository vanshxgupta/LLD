#include<bits/stdc++.h>
using namespace std;

//interface
class VideoQuality{
    public:
    virtual void load()=0;
    virtual ~VideoQuality(){} 
};

class HDQuality:public VideoQuality{
    public:
    void load() override{
        cout<<"HD quality"<<endl;
    }
};
class SDQuality:public VideoQuality{
    public:
    void load() override{
        cout<<"SD quality"<<endl;
    }
};
class K4Quality:public VideoQuality{
    public:
    void load() override{
        cout<<"4K quality"<<endl;
    }
};

// <<abstract class>>
class VideoPlayer{
    protected:
    VideoQuality*quality;

    public:
    VideoPlayer(VideoQuality*quality):quality(quality){}

    virtual void play()=0;
    
    virtual ~VideoPlayer(){
        delete quality;
    }
};

class SmartTV:public VideoPlayer{
    public:
    SmartTV(VideoQuality*quality):VideoPlayer(quality){}

    void play() override{
        cout<<"Playing on SmartTV with ";
        quality->load();
        cout<<endl;
    }
};
class WebPlayer:public VideoPlayer{
    public:
    WebPlayer(VideoQuality*quality):VideoPlayer(quality){}

    void play() override{
        cout<<"Playing on WebPlayer with ";
        quality->load();
        cout<<endl;
    }
};
class MobilePlayer:public VideoPlayer{
    public:
    MobilePlayer(VideoQuality*quality):VideoPlayer(quality){}

    void play() override{
        cout<<"Playing on MobilePlayer with ";
        quality->load();
        cout<<endl;
    }
};

int main(){
    VideoPlayer*player=new SmartTV(new K4Quality());
    player->play();
    delete player;
}