#include<bits/stdc++.h>
using namespace std;

class HttpRequest{
    string url;
    string method;
    map<string,string>headers;
    string body;

    private:
    //private becuase , we want client to make the object through builder class
    HttpRequest(string url,string method,map<string,string>headers,string body){
        this->url=url;
        this->method=method;
        this->headers=headers;
        this->body=body;
    }

    public:
    void showrequest(){
        cout<<"URL : "<<url<<endl;
        cout<<"METHOD : "<<method<<endl;
        cout<<"Headers : "<<endl;
        for(auto &it:headers){
            cout<<it.first<<":"<<it.second<<endl;
        }
        cout<<"Body : "<<body<<endl;
    }

    class Builder{
        string url;
        string method;
        map<string,string>headers;
        string body;

        public:
        //mandatory fields
        Builder(string url, string method){
            this->url=url;
            this->method=method;
        }
        Builder& addheaders(string key,string value){
            //Builder& becuase we don't want to make copy of the object again and again, 
            // and just build on same object 
            headers[key]=value;
            return *this; // this returns the address of the object , but *this returns the object itself
        }

        Builder& addbody(string body){
            this->body=body;
            return *this;
        }

        HttpRequest build(){
            return HttpRequest(url,method,headers,body);
        }

    };
};

int main(){

    // HttpRequest request=HttpRequest::Builder("asdfasd","asdfasd")->this is not the HttpRequest type , it is the Builder type 

    HttpRequest request=HttpRequest::Builder("https://api.com","POST").build();//.build() will make it the HttpRequest type-
    HttpRequest request2=HttpRequest::Builder("https://api.com","GET")
                        .addheaders("auth","Bearear token")
                        .addbody("vansh Gupta")
                        .build();
    
    request.showrequest();
    cout<<endl;
    request2.showrequest();

}