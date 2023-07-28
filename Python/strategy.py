from abc import ABC, abstractmethod


# Interfejs Strategy
class Strategy(ABC):
    @abstractmethod
    def execute(self):
        pass


# ConcreteStrategyA
class ConcreteStrategyA(Strategy):
    def execute(self):
        print("Wykonywanie strategii A")


# ConcreteStrategyB
class ConcreteStrategyB(Strategy):
    def execute(self):
        print("Wykonywanie strategii B")


# Context
class Context:
    def __init__(self, strategy: Strategy):
        self._strategy = strategy

    @property
    def strategy(self):
        return self._strategy

    @strategy.setter
    def strategy(self, strategy: Strategy):
        self._strategy = strategy

    def execute_strategy(self):
        self._strategy.execute()


def main():
    context = Context(ConcreteStrategyA())
    context.execute_strategy()  # Wykonywanie strategii A

    context.strategy = ConcreteStrategyB()
    context.execute_strategy()  # Wykonywanie strategii B


if __name__ == "__main__":
    main()
