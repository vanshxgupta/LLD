#include<bits/stdc++.h>
using namespace std;

class Request {
public:
   string user;
   string userRole;
   int requestCount;
   string payload;

   Request(string user, string userRole, int requestCount, string payload)
   : user(user), userRole(userRole), requestCount(requestCount), payload(payload) {}

};

//interface
class RequestHandler{
    public:
    virtual void setnext(RequestHandler*next)=0;
    virtual void handle(Request &request)=0;
    virtual ~RequestHandler(){}
};


//Abstract class BaseHandler ->it is created so that we dont have to set the next again and agin in every handler ,
//  we will create a forward(req) function in this which will forward it to next RESPONSBILITY IN CHAIN
class BaseHandler:public RequestHandler{
    protected:
    RequestHandler*next;
    public:
    BaseHandler(){
        next=nullptr;
    }
    void setnext(RequestHandler*next) override{
        this->next=next;
    }
    //as it was abstract class, it is all fine to not override the handle function from RequestHandler interface
    //but we cannot instantiate the object of BaseHandler as well in the main fuction

    void forward(Request &req){
        if(next!=nullptr){
            next->handle(req);
        }
    }
};

class AuthHandler:public BaseHandler{
    public:
    void handle(Request &request) override{
        if(request.user.empty()){
            cout<<"Authentication failed: User not found"<<endl;
            return;
        }
        else{
            cout<<"Authentication successful for user: "<<request.user<<endl;
            forward(request);
        }
    }
};

class AuthorizationHandler:public BaseHandler{
    public:
    void handle(Request &request) override{
        if(request.userRole!="admin"){
            cout<<"Authorization failed: User is not an admin"<<endl;
            return;
        }
        else{
            cout<<"Authorization successful for user: "<<request.user<<endl;
            forward(request);
        }
    }
};

class RateLimitingHandler:public BaseHandler{
    public:
    void handle(Request &request) override{
        if(request.requestCount>10){
            cout<<"Rate limit exceeded for user: "<<request.user<<endl;
            return;
        }
        cout << "RateLimitHandler: Within rate limit." << endl;
        forward(request);
    }
};

class ValidationHandler:public BaseHandler{
    public:
    void handle(Request &request) override{
        if(request.payload.empty()){
            cout<<"Validation failed: Payload is empty"<<endl;
            return;
        }
        else{
            cout<<"Validation successful for user: "<<request.user<<endl;
            forward(request);
        }
    }
};

class BusinessLogicHandler:public BaseHandler{
    public:
    void handle(Request &request) override{
        cout<<"[BusinessLogicHandler] Processing request for :"<<request.user<<endl;
    }
};

//Client have freedom to create the chain as per their requirement and can also reuse the handlers in different chains as well
int main(){

    RequestHandler* auth = new AuthHandler();
    RequestHandler* authorization = new AuthorizationHandler();
    RequestHandler* rateLimit = new RateLimitingHandler();
    RequestHandler* validation = new ValidationHandler();
    RequestHandler* businessLogic = new BusinessLogicHandler();

    auth->setnext(authorization);
    authorization->setnext(rateLimit);
    rateLimit->setnext(validation);
    validation->setnext(businessLogic);

    Request request("vansh","admin",3,"vanshxgupta");
    auth->handle(request);

    // Request request2("vansh","user",3,"vanshxgupta");
    // auth->handle(request2);

}
