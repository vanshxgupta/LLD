#include<bits/stdc++.h>
#include<thread>
using namespace std;

// <<interface>>
class VideoDownloader{
    public:
    virtual void downloadvideo(string url)=0;
    virtual ~VideoDownloader(){}
};
class RealVideoDownloader:public VideoDownloader{
    public:
    void simulatenetworkdelay(){
        for(int i=0;i<1e9;i++){//expensive task
            i++;
        }
        cout<<"Downloading from RealDownloader.."<<endl;
    }
    void downloadvideo(string url) override{
        simulatenetworkdelay();
        cout<<"Video Downloaded"<<url<<endl;
    }
};
//proxy
class CachedVideoDownloader:public VideoDownloader{
    private:
    RealVideoDownloader* realvideodownloader;
    unordered_map<string,string> &cache;

    public:
    CachedVideoDownloader(unordered_map<string,string> &cache):cache(cache){
        realvideodownloader=new RealVideoDownloader();
    }

    ~CachedVideoDownloader(){
        delete realvideodownloader;
    }

    void downloadvideo(string url) override{
        if(cache.find(url)!=cache.end()){
            cout<<"Video Cached..."<<endl;
            cout<<"Video Downloaded"<<cache[url]<<endl;
        }
        else{
            realvideodownloader->downloadvideo(url);
            string video=url+" : video";
            cache[url]=video;
        }
    }
};
int main(){
    unordered_map<string,string>cache;
    VideoDownloader* videodownload=new CachedVideoDownloader(cache);
    videodownload->downloadvideo("asfasdf");
    videodownload->downloadvideo("asfasdf");
    videodownload->downloadvideo("asfdf");
    cache.clear();
    delete videodownload;
    return 0;
}