#include <iostream>
#include <vector>
#include <algorithm>

class Observer {
public:
    virtual ~Observer() {}
    virtual void update(const std::string& message) = 0;  // Pure virtual function
};

class User : public Observer {
public:
    User(std::string name) : name(name) {}
    void update(const std::string& message) override {
        std::cout << name << " received message: " << message << std::endl;
    }
private:
    std::string name;
};

class NotificationChannel {
public:
    void subscribe(Observer* observer) {
        subscribers.push_back(observer);
    }

    void unsubscribe(Observer* observer) {
        subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), observer), subscribers.end());
    }

    void notify(const std::string& message) {
        for (Observer* subscriber : subscribers) {
            subscriber->update(message);
        }
    }
private:
    std::vector<Observer*> subscribers;
};

int main() {
    NotificationChannel channel;

    User alice("Alice");
    User bob("Bob");

    channel.subscribe(&alice);
    channel.subscribe(&bob);

    channel.notify("Hello, World!");  // Alice and Bob receive notification

    return 0;
}
