#include <iostream>
#include <string>

class Text {
public:
    virtual ~Text() {}
    virtual std::string getText() = 0;  // Pure virtual function
};

class PlainText : public Text {
public:
    PlainText(std::string text) : text(text) {}
    std::string getText() override {
        return text;
    }
private:
    std::string text;
};

class TextDecorator : public Text {
public:
    TextDecorator(Text* text) : text(new PlainText(text->getText())) {}
    ~TextDecorator() { delete text; }
protected:
    Text* text;
};

class BoldText : public TextDecorator {
public:
    BoldText(Text* text) : TextDecorator(text) {}
    std::string getText() override {
        return "<b>" + text->getText() + "</b>";
    }
};

class ItalicText : public TextDecorator {
public:
    ItalicText(Text* text) : TextDecorator(text) {}
    std::string getText() override {
        return "<i>" + text->getText() + "</i>";
    }
};

int main() {
    Text* text = new PlainText("Hello, World!");

    Text* boldText = new BoldText(new PlainText(text->getText()));
    std::cout << boldText->getText() << std::endl;  // Prints: <b>Hello, World!</b>
    delete boldText;

    Text* italicText = new ItalicText(new PlainText(text->getText()));
    std::cout << italicText->getText() << std::endl;  // Prints: <i>Hello, World!</i>
    delete italicText;

    Text* boldItalicText = new BoldText(new ItalicText(new PlainText(text->getText())));
    std::cout << boldItalicText->getText() << std::endl;  // Prints: <b><i>Hello, World!</i></b>
    delete boldItalicText;

    delete text;

    return 0;
}

