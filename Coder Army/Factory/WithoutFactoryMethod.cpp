#include <iostream>
#include <string>
using namespace std;

// --- 1. The Concrete Products (No common interface needed if client couples directly, but keeping them for similarity) ---
class Truck {
public:
    void deliver() {
        cout << "Delivering cargo by land in a box..." << endl;
    }
};

class Ship {
public:
    void deliver() {
        cout << "Delivering cargo by sea in a container..." << endl;
    }
};

// --- 2. The Monolithic Logistics Class ---
class Logistics {
private:
    string transportType; // Bad: We need a type flag to know what to build

public:
    Logistics(string type) : transportType(type) {}

    // Core business logic is now a mess of if-else/switch statements
    void planDelivery() {
        cout << "Logistics calculating route... ";

        if (transportType == "Road") {
            Truck* truck = new Truck(); // Bad: Tightly coupled to concrete class
            truck->deliver();
            delete truck;
        } 
        else if (transportType == "Sea") {
            Ship* ship = new Ship();   // Bad: Tightly coupled to concrete class
            ship->deliver();
            delete ship;
        }
        /* CRITICAL ISSUE:
        Agar kal ko Drone/Air transport add karna ho, toh hume IS MEHANT-SE-LIKHI-HUI 
        class ke andar aakar ek aur 'else if' block ghusana padega. 
        Yeh class tight couple ho chuki hai!
        */
    }
};

// --- Main Execution ---
int main() {
    cout << "--- Without Factory Method Output ---" << endl;
    
    // Client has to pass strings/flags to control behavior
    Logistics* myRoadApp = new Logistics("Road");
    myRoadApp->planDelivery();

    Logistics* mySeaApp = new Logistics("Sea");
    mySeaApp->planDelivery();

    delete myRoadApp;
    delete mySeaApp;
    
    return 0;
}