//designing a file system 

#include<bits/stdc++.h>
using namespace std;

// <<interface>>
class FileSystemItem{
    public:
    virtual void ls()=0;
    virtual void openall(int indent=0)=0;
    virtual int getsize()=0;
    virtual string getname()=0;
    virtual FileSystemItem* cd(string target)=0;
    virtual void additem(FileSystemItem* item)=0;
    virtual bool isFolder()=0;
    virtual ~FileSystemItem(){}
};

class File:public FileSystemItem{
    private:
    int size;
    string name;
    public:
    File(string name,int size):name(name),size(size){}

    void ls() override{
        cout<<getname()<<endl;
    }
    void openall(int indent=0) override{
        return ;
    }
    int getsize() override{
        return size;
    }
    string getname() override{
         return name;
    }
    FileSystemItem* cd(string target) override{
        return nullptr; //a file cannot change its directory
    }
    void additem(FileSystemItem* item) override{
        return ;
    }
    bool isFolder() override{
        return false;
    }
};

class Folder:public FileSystemItem{
    private:
    string name;
    vector<FileSystemItem*>Items;

    public:
    Folder(string name):name(name){}

    ~Folder(){
        for(auto &it:Items){
            delete it;
        }
    }

    void ls() override{ 
        for(auto &it:Items){
            cout<<it->getname()<<endl;
        }
    }
    void openall(int indent=0) override{
        for(auto &it:Items){
            string indetation(indent,' ');
            cout<<indetation + (it->getname())<<endl;
            it->openall(indent+4);
        }
    }
    int getsize() override{
        int totalsize=0;
        for(auto &it:Items){
            totalsize+=(it->getsize());
        }
        return totalsize;
    }
    string getname() override{
        return name;
    }
    FileSystemItem* cd(string target) override{
        for(auto &it:Items){
            if(it->isFolder() && it->getname()==target){
                return it;
            }
        }
        return nullptr;
    }
    void additem(FileSystemItem* item) override{
        Items.push_back(item);
    }
    bool isFolder() override{
        return true;
    }
};

int main(){

    Folder*root=new Folder("root");
    Folder*docs=new Folder("docs");

    File* doc1=new File("fileofdoc1",1);
    docs->additem(doc1);
    root->additem(docs);

    Folder*images=new Folder("images");
    File* image1=new File("image1",2);
    File* image2=new File("image2",1);
    images->additem(image1);
    images->additem(image2);
    root->additem(images);
    
    File* image3=new File("imageinroot",1);
    root->additem(image3);

    // root->ls();
    root->openall();
    // cout<<root->getsize()<<endl;
    // cout<<doc1->getname()<<endl;

    // root->cd("images")->ls();

    delete root;

}