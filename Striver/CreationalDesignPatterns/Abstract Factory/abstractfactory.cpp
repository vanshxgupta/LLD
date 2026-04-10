#include <bits/stdc++.h>
using namespace std;

//interface invoice
class Invoice{
    public:
    virtual void createinvoice()=0;
    virtual ~Invoice(){}
};

class USInvoice: public Invoice{
    public:
    void createinvoice() override{
        cout<<"US Invoice created"<<endl;
    }
};

class IndiaInvoice: public Invoice{
    public:
    void createinvoice() override{
        cout<<"India Invoice created"<<endl;
    }
};

// interface paymentgateway
class PaymentGateway{
    public:
    virtual void createpayment(double amount)=0;
    virtual ~PaymentGateway(){}
};

class Stripe: public PaymentGateway{
    public:
    void createpayment(double amount) override{
        cout<<"Payment success with Stripe of amount : "<<amount<<endl;
    }
};

class Razorpay: public PaymentGateway{
    public:
    void createpayment(double amount) override{
        cout<<"Payment success with Razorpay of amount : "<<amount<<endl;
    }
};


//abstract factory
class RegionFactory{
    public:
    virtual PaymentGateway* createpayment() = 0;
    virtual Invoice* createinvoice() = 0;
    virtual ~RegionFactory(){}
};

class USFactory:public RegionFactory{
    public:
    PaymentGateway *createpayment() override{
            return new Stripe();
    }
    Invoice* createinvoice() override{
        return new USInvoice();
    }
};

class IndiaFactory:public RegionFactory{
    public:
    PaymentGateway *createpayment() override{
        return new Razorpay();
    }
    Invoice* createinvoice() override{
        return new IndiaInvoice();
    }
};

class CheckoutService{
    public:
    PaymentGateway* paymentGateway;
    Invoice* invoice;
    CheckoutService(RegionFactory *factory){
        this->paymentGateway=factory->createpayment();
        this->invoice=factory->createinvoice();
    }

    void completeprocess(double amount){
        if(paymentGateway==nullptr){
            cout<<"Select valid gateway type"<<endl;
            return;
        }
        paymentGateway->createpayment(amount);
        invoice->createinvoice();
    }
    
    ~CheckoutService() {
        delete paymentGateway;
        delete invoice;
    }
};
int main(){
    RegionFactory * factory=new USFactory();
    CheckoutService* out1= new CheckoutService(factory);
    out1->completeprocess(1000);

    delete out1;
    delete factory;
    return 0;
    
}
