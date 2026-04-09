#include <bits/stdc++.h>
using namespace std;


//interface
class TaxCalculator{
    public:
    virtual int calculatetax(int amount) = 0;
    virtual ~TaxCalculator(){};
};

class IndianTax: public TaxCalculator{
    public:
    int calculatetax (int amount) override{
        return 0.18*amount;
    }
};

class USTax: public TaxCalculator{
    public:
    int calculatetax (int amount) override{
        return 0.20*amount;
    }
};


class InvoiceSystem{
    private:
    TaxCalculator* tax;

    public:
    InvoiceSystem(TaxCalculator* tax){//type of tax i.e indiantax or ustax
        this->tax=tax;
    }

    void generateinvoice(int amount){
        cout<<amount+tax->calculatetax(amount)<<endl;
    }
};



int main(){

    TaxCalculator* tax1=new IndianTax();
    InvoiceSystem invoice1(tax1);
    invoice1.generateinvoice(100);
    
    TaxCalculator* tax2=new USTax();
    InvoiceSystem invoice2(tax2);
    invoice2.generateinvoice(100);

    delete tax1;
    delete tax2;

    return 0;
}