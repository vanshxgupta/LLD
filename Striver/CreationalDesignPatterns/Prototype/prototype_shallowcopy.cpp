#include<bits/stdc++.h>
using namespace std;

// interface EmailTemplate
class EmailTemplate{
    public:
    virtual EmailTemplate*clone()=0;
    virtual void setcontent(string content)=0;
    virtual void send(string to)=0;
    virtual void show()=0;
    virtual ~EmailTemplate(){}
};

class WelcomeEmail:public EmailTemplate{
    private:
    string subject;
    string content;
    string to;
    int*    priority;
    public:
    
    WelcomeEmail(){
        subject    = "Welcome to our platform!";
        to      = "";
        content = "";   // default empty
        priority = new int(1);
        // content    = loadFromDatabase();     // DB call — slow
        // htmlLayout = parseHTMLTemplate();    // file read — slow

        cout << "EXPENSIVE setup done!\n";
    }

    //deep clone
    EmailTemplate*clone() override{//Copy constructor — sirf values copy karta hai, koi DB/file call nahi
        WelcomeEmail* clonedobject=new WelcomeEmail(*this);//here there is no call to constrcutor again , just copying of values
        cout << "[WelcomeEmail] Cloned successfully\n";
        cout << "[Cloned] priority address: " << clonedobject->priority<< " same as original!\n";
        return clonedobject;
    }
    void setcontent(string newcontent) override{
        content=newcontent;
    }
    void send(string new_to) override{
        to=new_to;
    }
    void setPriority(int val){
        *priority = val;
    }

    void show() override{
        cout<<"send to "<<to<<endl;
        cout<<"subject : "<<subject<<endl;
        cout<<"content :"<<content<<endl;
        cout << "Priority : " << *priority<< "\n";
        cout << "Ptr addr : " << priority << "\n"; // alag address dikhayega
        cout<<"----------------" <<endl;
    }

};

class EmailTemplateRegistry{
    private:
    unordered_map<string,EmailTemplate*>templates;

    public:
    void registertemplate(string key,EmailTemplate*prototype){
        templates[key]=prototype;
        cout<<"Registered : "<<key<<endl;
    }
    EmailTemplate* gettemplate(string key){
        if(templates.find(key)==templates.end()){
            cout<<"Not exist"<<endl;
            return nullptr;
        }
        return templates[key]->clone();
    }

    // Cleanup stored prototypes
    ~EmailTemplateRegistry() {
        for (auto& pair : templates) {
            delete pair.second;
        }
    }
};

int main(){

    EmailTemplateRegistry registry1;
    WelcomeEmail* template1=new WelcomeEmail();
    registry1.registertemplate("welcome",template1);
    template1->show();
    
    EmailTemplate *newmail1=registry1.gettemplate("welcome");
    newmail1->send("Vansh");
    newmail1->setcontent("Hy vansh");
    newmail1->show();

    EmailTemplate *newmail2=registry1.gettemplate("welcome");
    newmail2->send("Tarun");
    newmail2->setcontent("Hy tarun");
    static_cast<WelcomeEmail*>(newmail2)->setPriority(99);
    newmail2->show();

    delete newmail1;
    delete newmail2;

    return 0;
}
