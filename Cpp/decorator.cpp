#include <iostream>
#include <string>

class Component {
public:
    virtual ~Component() {}
    virtual std::string operation() const = 0;
};

class ConcreteComponent : public Component {
public:
    std::string operation() const override {
        return "ConcreteComponent";
    }
};

class Decorator : public Component {
protected:
    Component* component;

public:
    Decorator(Component* c) : component(c) {}
    virtual ~Decorator() {}

    std::string operation() const override {
        return this->component->operation();
    }
};

class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* c) : Decorator(c) {}

    std::string operation() const override {
        return "ConcreteDecoratorA(" + Decorator::operation() + ")";
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* c) : Decorator(c) {}

    std::string operation() const override {
        return "ConcreteDecoratorB(" + Decorator::operation() + ")";
    }
};

void client_code(Component* component) {
    std::cout << "RESULT: " << component->operation();
}

int main() {
    Component* simple = new ConcreteComponent;
    Component* decorator1 = new ConcreteDecoratorA(simple);
    Component* decorator2 = new ConcreteDecoratorB(decorator1);
    client_code(decorator2);  // Zwraca: RESULT: ConcreteDecoratorB(ConcreteDecoratorA(ConcreteComponent))

    delete simple;
    delete decorator1;
    delete decorator2;

    return 0;
}
