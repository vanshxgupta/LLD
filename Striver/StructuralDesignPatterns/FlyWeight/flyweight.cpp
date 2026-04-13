#include<bits/stdc++.h>
using namespace std;

class TreeType{//shared->intrinsic
    string name;
    string color;
    string texture;

    public:
    TreeType(string name,string color,string texture):name(name),color(color),texture(texture){}

    void draw(int x, int y) {
        cout << name << " " << color << " " << texture << " at (" << x << "," << y << ")" << endl;
    }
};

//extrinsic
class Tree{
    TreeType* type;
    int x;
    int y;

    public:
    Tree(TreeType*type,int x,int y):type(type),x(x),y(y){}

    void draw(){
        type->draw(x,y);
    }

};
class TreeFactory{
    unordered_map<string,TreeType*> mp;
    public:
    TreeType* gettreetype(string name,string color,string texture){
        string s=name+"#"+color+"#"+texture;
        if(mp.find(s)==mp.end()){
            TreeType*newtreetype= new TreeType(name,color,texture);
            mp[s]=newtreetype;
            return newtreetype;
        }
        else{
            return mp[s];
        }
    }
};
class Forest{
    public:
    vector<Tree>trees;
    TreeFactory treefactory;
    void planttree(string name,string color,string texture,int x,int y){
        TreeType* type=treefactory.gettreetype(name,color,texture);
       
        trees.push_back(Tree(type,x,y));
    }
    void draw(){
        for(auto &tree:trees){
            tree.draw();
        }
    }
};
int main(){
    Forest f;
    f.planttree("Neem","Green","Plain",15,30);
    f.planttree("Neem","Green","Plain",1234,123);
    f.planttree("Neem","Blue","Plain",45,310);
    f.draw();

    return 0;
}