#include <iostream>
#include <string>
#include <functional>
#include <vector>

// Observer interface
class IObserver {
public:
    virtual ~IObserver() {}
    virtual void Update(const std::string& message) = 0;
};

// Observable class
class Text {
    std::string subText;
    std::vector<IObserver*> observers;

public:
    void Attach(IObserver* observer) {
        observers.push_back(observer);
    }

    void SetSubText(const std::string& newSubText) {
        subText = newSubText;
        Notify();
    }

    void Notify() {
        for (IObserver* observer : observers) {
            observer->Update(subText);
        }
    }

    std::string GetSubText() const {
        return subText;
    }
};

// Concrete observer
class TextObserver : public IObserver {
public:
    virtual void Update(const std::string& message) override {
        std::cout << "Sub-text property has changed to: " << message << std::endl;
    }
};

int main() {
    Text text;
    TextObserver observer;

    text.Attach(&observer);

    // Simulate sub-text changes
    text.SetSubText("Hello");
    text.SetSubText("World");

    return 0;
}
