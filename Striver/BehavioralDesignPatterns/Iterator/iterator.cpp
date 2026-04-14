#include<bits/stdc++.h>
using namespace std;

class Video{
    string title;
    public:
    Video(string title):title(title){}

    string gettitle(){
        return title;
    }
};

//interfece Iterator
class PlaylistIterator{
    public:
    virtual bool hasnext()=0;
    virtual Video* next()=0;
    virtual ~PlaylistIterator(){}
};

//interface
class Playlist{
    public:
    virtual PlaylistIterator* createIterator()=0;
    virtual ~Playlist(){}
};

//concreteiterator
class YoutubePlaylistIterator:public PlaylistIterator{
    vector<Video*>videos;
    int position=0;
    public:
    YoutubePlaylistIterator(vector<Video*>videos){
        this->videos=videos;
    }

    bool hasnext() override{
        return position<videos.size();
    }
    Video* next() override{
        if(hasnext()){
            return videos[position++];
        }
        return nullptr;
    }
};

class YoutubePlaylist:public Playlist{
    vector<Video*>videos;
    public:

    PlaylistIterator* createIterator() override{
        return new YoutubePlaylistIterator(videos);
    }
    void addvideo(Video* video){
        videos.push_back(video);
    }

};

int main(){

    YoutubePlaylist* ytplaylist=new YoutubePlaylist();
    Video* video1=new Video("Asdfasd");
    Video* video2=new Video("2q3r");
    ytplaylist->addvideo(video1);
    ytplaylist->addvideo(video2);

    PlaylistIterator* iterator= ytplaylist->createIterator();
    //iterate
    while(iterator->hasnext()){
        cout << iterator->next()->gettitle() << endl;
    }

    delete video1;
    delete video2;
    delete ytplaylist;

    return 0;

}