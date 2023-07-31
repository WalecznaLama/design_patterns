from abc import ABC, abstractmethod

class Observer(ABC):
    @abstractmethod
    def update(self, message: str):
        pass

class User(Observer):
    def __init__(self, name):
        self.name = name

    def update(self, message: str):
        print(f'{self.name} received message: {message}')

class NotificationChannel:
    def __init__(self):
        self.subscribers = []

    def subscribe(self, subscriber: Observer):
        self.subscribers.append(subscriber)

    def unsubscribe(self, subscriber: Observer):
        self.subscribers.remove(subscriber)

    def notify(self, message: str):
        for subscriber in self.subscribers:
            subscriber.update(message)


if __name__ == "__main__":
    # Użycie
    channel = NotificationChannel()

    alice = User('Alice')
    bob = User('Bob')

    channel.subscribe(alice)
    channel.subscribe(bob)

    channel.notify('Hello, World!')  # Alice and Bob receive notification
