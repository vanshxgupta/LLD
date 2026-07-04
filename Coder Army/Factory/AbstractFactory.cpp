//not a coderarmy burger example 
//but a better example 

// The Scenario: You are building a cross-platform GUI toolkit. If a user is on Windows, you want to generate a Windows-style Button and a Windows-style Checkbox. If they are on Mac, you need Mac-style components. You must ensure a Mac Button is never accidentally paired with a Windows Checkbox.

// answer:
// The Goal: Create a family of related products that must work together.

// How it works: The Application needs multiple UI elements (Buttons, Checkboxes) but doesn't care about the OS. It asks a master factory (GUIFactory) to give it the parts.

// The Benefit (Why it’s good): It guarantees consistency. Because the WindowsFactory only ever spits out Windows-style buttons and checkboxes, it is physically impossible for your application to accidentally render a Mac button on a Windows screen.
#include <iostream>
using namespace std;

// --- 1. Abstract Products ---
class Button {
public:
    virtual void paint() = 0;
    virtual ~Button() {}
};

class Checkbox {
public:
    virtual void paint() = 0;
    virtual ~Checkbox() {}
};

// --- 2. Concrete Products (Family 1: Windows) ---
class WindowsButton : public Button {
public:
    void paint() override {
        cout << "Rendering a Windows-style button." << endl;
    }
};

class WindowsCheckbox : public Checkbox {
public:
    void paint() override {
        cout << "Rendering a Windows-style checkbox." << endl;
    }
};

// --- 3. Concrete Products (Family 2: Mac) ---
class MacButton : public Button {
public:
    void paint() override {
        cout << "Rendering a Mac-style button." << endl;
    }
};

class MacCheckbox : public Checkbox {
public:
    void paint() override {
        cout << "Rendering a Mac-style checkbox." << endl;
    }
};

// --- 4. The Abstract Factory Interface ---
class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;
    virtual ~GUIFactory() {}
};

// --- 5. Concrete Factories ---
class WindowsFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new WindowsButton();
    }
    Checkbox* createCheckbox() override {
        return new WindowsCheckbox();
    }
};

class MacFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new MacButton();
    }
    Checkbox* createCheckbox() override {
        return new MacCheckbox();
    }
};

// --- 6. The Client Code ---
class Application {
private:
    Button* button;
    Checkbox* checkbox;

public:
    // The client only knows about the abstract interfaces!
    Application(GUIFactory* factory) {
        button = factory->createButton();
        checkbox = factory->createCheckbox();
    }

    void renderUI() {
        button->paint();
        checkbox->paint();
    }
    
    ~Application() {
        delete button;
        delete checkbox;
    }
};

// --- Main Execution ---
int main() {
    cout << "--- Abstract Factory Output ---" << endl;
    
    // Simulate detecting a Windows OS
    GUIFactory* winFactory = new WindowsFactory();
    Application* winApp = new Application(winFactory);
    cout << "Starting Windows App:" << endl;
    winApp->renderUI();

    cout << "\n-----------------------------\n" << endl;

    // Simulate detecting a Mac OS
    GUIFactory* macFactory = new MacFactory();
    Application* macApp = new Application(macFactory);
    cout << "Starting Mac App:" << endl;
    macApp->renderUI();

    // Cleanup
    delete winApp;
    delete winFactory;
    delete macApp;
    delete macFactory;

    return 0;
}