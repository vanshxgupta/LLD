#include<bits/stdc++.h>
using namespace std;
//base case defining the template method
class ModelTrainer{
    public:
    void trainpipeline(const string&datapath){
        loaddata(datapath);
        preprocessdata();
        trainmodel();
        evaluatemodel();
        savemodel();
    }
    protected:
    virtual void loaddata(const string&path ){
        cout<<"[Common] Loading dataset"<<path<<endl;
    }
    virtual void preprocessdata(){
        cout<<"[Common] Pre Processing data"<<endl;
    }
    virtual void trainmodel()=0;
    virtual void evaluatemodel()=0;
    virtual void savemodel(){
        cout<<"[Common] Saving Model"<<endl;
    }
};
class NeuralNetTrainer:public ModelTrainer{
    protected:
    void trainmodel() override{
        cout<<"[NeuralNet] Training Neural Network"<<endl;
    }
    void evaluatemodel() override{
        cout<<"[NeuralNet] Evaluating Neural Network"<<endl;
    }
};
class DecisionTreeTrainer:public ModelTrainer{
    protected:
    void trainmodel() override{
        cout<<"[DecisionTree] Training Decision Tree"<<endl;
    }
    void evaluatemodel() override{
        cout<<"[DecisionTree] Evaluating Decision Tree"<<endl;
    }
};
int main(){
    NeuralNetTrainer nntrainer;
    nntrainer.trainpipeline("neuralnetdata.csv");
    cout<<endl;
    DecisionTreeTrainer dtt;
    dtt.trainpipeline("decisiontreedata.csv");
    return 0;
}