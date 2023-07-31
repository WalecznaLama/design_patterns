from abc import ABC, abstractmethod


class Text(ABC):
    @abstractmethod
    def get_text(self):
        pass


class PlainText(Text):
    def __init__(self, text):
        self.text = text

    def get_text(self):
        return self.text


class TextDecorator(Text):
    def __init__(self, text: Text):
        self.text = text


class BoldText(TextDecorator):
    def get_text(self):
        return f'<b>{self.text.get_text()}</b>'


class ItalicText(TextDecorator):
    def get_text(self):
        return f'<i>{self.text.get_text()}</i>'


if __name__ == "__main__":

    # Użycie
    text = PlainText('Hello, World!')

    bold_text = BoldText(text)
    print(bold_text.get_text())  # Wyświetla: <b>Hello, World!</b>

    italic_text = ItalicText(text)
    print(italic_text.get_text())  # Wyświetla: <i>Hello, World!</i>

    bold_italic_text = BoldText(ItalicText(text))
    print(bold_italic_text.get_text())  # Wyświetla: <b><i>Hello, World!</i></b>
