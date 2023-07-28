#include <iostream>
#include <list>

// Interfejs dla obserwatorów
class Observer {
public:
    virtual ~Observer() {}
    virtual void update(int value) = 0;
};

// Klasa Obserwowanego (Subject)
class Subject {
private:
    std::list<Observer*> observers;
    int state;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void set_state(int value) {
        state = value;
        notify();
    }

    void notify() {
        for (auto observer : observers) {
            observer->update(state);
        }
    }
};

// Konkretny obserwator
class ConcreteObserver : public Observer {
private:
    int observerState;

public:
    void update(int value) override {
        observerState = value;
        std::cout << "Stan obserwatora zaktualizowany na: " << observerState << "\n";
    }
};

int main() {
    Subject subject;
    ConcreteObserver observer;

    subject.attach(&observer);
    subject.set_state(5); // "Stan obserwatora zaktualizowany na: 5" zostanie wydrukowany na konsoli

    return 0;
}
