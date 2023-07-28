class Observer:
    def update(self, value):
        pass


class Subject:
    def __init__(self):
        self._observers = []
        self._state = None

    def attach(self, observer):
        self._observers.append(observer)

    def set_state(self, value):
        self._state = value
        self.notify()

    def notify(self):
        for observer in self._observers:
            observer.update(self._state)


class ConcreteObserver(Observer):
    def __init__(self):
        self._observer_state = None

    def update(self, value):
        self._observer_state = value
        print(f"Stan obserwatora zaktualizowany na: {self._observer_state}")


def main():
    subject = Subject()
    observer = ConcreteObserver()

    subject.attach(observer)
    subject.set_state(5)  # "Stan obserwatora zaktualizowany na: 5" zostanie wydrukowane na konsoli


if __name__ == "__main__":
    main()
