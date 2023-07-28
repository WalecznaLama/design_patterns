#include <iostream>

// Interfejs Strategy
class Strategy {
public:
    virtual ~Strategy() {}
    virtual void execute() const = 0;
};

// ConcreteStrategyA
class ConcreteStrategyA : public Strategy {
public:
    void execute() const override {
        std::cout << "Wykonywanie strategii A\n";
    }
};

// ConcreteStrategyB
class ConcreteStrategyB : public Strategy {
public:
    void execute() const override {
        std::cout << "Wykonywanie strategii B\n";
    }
};

// Context
class Context {
private:
    Strategy* strategy;

public:
    Context(Strategy* strategy = nullptr) : strategy(strategy) {}

    ~Context() {
        delete this->strategy;
    }

    void set_strategy(Strategy* strategy) {
        delete this->strategy;
        this->strategy = strategy;
    }

    void execute_strategy() const {
        this->strategy->execute();
    }
};

int main() {
    Context* context = new Context(new ConcreteStrategyA);
    context->execute_strategy(); // Wykonywanie strategii A

    context->set_strategy(new ConcreteStrategyB);
    context->execute_strategy(); // Wykonywanie strategii B

    delete context;

    return 0;
}

