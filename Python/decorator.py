class Component:
    def operation(self):
        return "ConcreteComponent"


class Decorator(Component):
    def __init__(self, component):
        self._component = component

    @property
    def component(self):
        return self._component

    def operation(self):
        return self._component.operation()


class ConcreteDecoratorA(Decorator):
    def operation(self):
        return f"ConcreteDecoratorA({self.component.operation()})"


class ConcreteDecoratorB(Decorator):
    def operation(self):
        return f"ConcreteDecoratorB({self.component.operation()})"


def client_code(component):
    print(f"RESULT: {component.operation()}")


if __name__ == "__main__":
    simple = Component()
    decorator1 = ConcreteDecoratorA(simple)
    decorator2 = ConcreteDecoratorB(decorator1)
    client_code(decorator2)  # Zwraca: RESULT: ConcreteDecoratorB(ConcreteDecoratorA(ConcreteComponent))
