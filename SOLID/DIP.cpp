#include <bits/stdc++.h>
using namespace std;

//abstraction /interface
class Database{
    public:
    virtual void save()=0;
    virtual ~Database(){}
};

//low level modules
class MongoBD:public Database{
    public:
    void save() override{
        cout<<"Saved to mongodb"<<endl;
    }
};
class Postgress:public Database{
    public:
    void save() override{
        cout<<"Saved to Postgress"<<endl;
    }
};
class Cassandra:public Database{
    public:
    void save() override{
        cout<<"Saved to Cassandra"<<endl;
    }
};

//high level module
class DBservice{
    private:
    Database* db;
    public:
    DBservice(Database *db){
        this->db=db;
    }
    void storetodb(){
        db->save();
    }
    
};

int main(){
    Database*db1=new Postgress();
    DBservice service(db1);
    service.storetodb();
    
    
    return 0;
}