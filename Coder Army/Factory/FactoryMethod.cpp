//not a coderarmy burger example 
//but a better example 


// The Scenario: You are building a logistics management system. Initially, your app only handles road transportation (Trucks). 
// Later, you need to add sea transportation (Ships). The Factory Method lets you extract the creation of the transport object so you can easily add new modes of transport without breaking the existing code.
// Why this works: The Logistics base class doesn't know what type of transport it is using. It just knows that whatever createTransport() returns will have a deliver() method.

// The Goal: Create one specific type of product without tightly coupling the code to the product's class.

// How it works: The main Logistics app knows how to plan a route, but it doesn't know what vehicle it's using. It delegates the creation to its subclasses (RoadLogistics or SeaLogistics).

// The Benefit (Why it’s good): If you want to add drones or cargo planes later, you just create an AirLogistics subclass. You never have to modify the core routing algorithm.


#include <iostream>
using namespace std;

// --- 1. The Product Interface ---
class Transport {
public:
    virtual void deliver() = 0;
    virtual ~Transport() {}
};

// --- 2. Concrete Products ---
class Truck : public Transport {
public:
    void deliver() override {
        cout << "Delivering cargo by land in a box..." << endl;
    }
};

class Ship : public Transport {
public:
    void deliver() override {
        cout << "Delivering cargo by sea in a container..." << endl;
    }
};

// --- 3. The Creator (Factory Base Class) ---
class Logistics {
//Base Creator -> Product Interface: Dependency. 
// * The base Logistics class depends on the Transport interface to do its core business logic, but it doesn't know about Trucks or Ships.
public:
    // The Factory Method itself
    virtual Transport* createTransport() = 0; 

    // Core business logic that relies on the factory method
    void planDelivery() {
        Transport* transport = createTransport();
        cout << "Logistics calculating route... ";
        transport->deliver();
        
        delete transport; // Remember to manage memory in C++!
    }
    
    virtual ~Logistics() {}
};

// --- 4. Concrete Creators ---
class RoadLogistics : public Logistics { //The RoadLogistics class is a type of Logistics
public:
    Transport* createTransport() override {
        return new Truck();
    }
};

class SeaLogistics : public Logistics {
public:
    Transport* createTransport() override {
        return new Ship();
    }
};

// --- Main Execution ---
int main() {
    cout << "--- Factory Method Output ---" << endl;
    
    Logistics* myRoadApp = new RoadLogistics();
    myRoadApp->planDelivery();

    Logistics* mySeaApp = new SeaLogistics();
    mySeaApp->planDelivery();

    delete myRoadApp;
    delete mySeaApp;
    
    return 0;
}