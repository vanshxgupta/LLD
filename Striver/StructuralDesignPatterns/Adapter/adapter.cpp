#include<bits/stdc++.h>
using namespace std;

//interface
class PaymentGateway{
    public:
    virtual void pay(string orderid,double amount)=0;
    virtual ~PaymentGateway(){}
};

class PayU:public PaymentGateway{
    //PayU does not need adapter becuase it is implementing PaymentGateway and is compatible with it
    public:
    void pay(string orderid,double amount) override{
        cout<<"Order Succesfull with PayU"<<endl;
    }
};

//if we added another PaymentGateway i.e RazorpayAPI ->this do not implement PaymentGateway
// Adaptee (incompatible)
class RazorpayAPI{
    public:
    void makepayment(string InvoiceId,double amount){
        cout<<"RazorpayAPI is used"<<endl;
    }
};

//make a Adapter which implements the PaymentGateway , and make it compatible with it with RazorpayAPI in it
// Adapter
class RazorpayAdapter:public PaymentGateway{
    private:
    unique_ptr<RazorpayAPI> razorpayapi;
    public:
    RazorpayAdapter(){
        this->razorpayapi=make_unique<RazorpayAPI>();
    }
    void pay(string orderid,double amount) override{
        razorpayapi->makepayment(orderid,amount);
        cout<<"Order Succesfull with Razorpay with orderid : "<<orderid<<" with amount : "<<amount<<endl;
    }
};

class CheckOutService{
    private:
    unique_ptr<PaymentGateway> paymentgateway;
    public:
    CheckOutService(unique_ptr<PaymentGateway> paymentgateway){
        this->paymentgateway=move(paymentgateway);
    }

    void checkout(string orderid,double amount){
        paymentgateway->pay(orderid,amount);
    }
};

int main(){
    unique_ptr<PaymentGateway> paymentgate1=make_unique<RazorpayAdapter>();
    unique_ptr<CheckOutService> out1=make_unique<CheckOutService>(move(paymentgate1));
    out1->checkout("1232134feewq",121123);
    return 0;
}