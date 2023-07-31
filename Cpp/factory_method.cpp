#include <iostream>
#include <memory>

class Document {
public:
    virtual ~Document() {}
    virtual std::string getType() = 0;
};

class PdfDocument : public Document {
public:
    std::string getType() override {
        return "PDF Document";
    }
};

class WordDocument : public Document {
public:
    std::string getType() override {
        return "Word Document";
    }
};

class DocumentFactory {
public:
    virtual ~DocumentFactory() {}
    virtual std::unique_ptr<Document> createDocument() = 0;
};

class PdfDocumentFactory : public DocumentFactory {
public:
    std::unique_ptr<Document> createDocument() override {
        return std::make_unique<PdfDocument>();
    }
};

class WordDocumentFactory : public DocumentFactory {
public:
    std::unique_ptr<Document> createDocument() override {
        return std::make_unique<WordDocument>();
    }
};

int main() {
    PdfDocumentFactory pdfFactory;
    auto doc1 = pdfFactory.createDocument();
    std::cout << doc1->getType() << std::endl;  // Prints: PDF Document

    WordDocumentFactory wordFactory;
    auto doc2 = wordFactory.createDocument();
    std::cout << doc2->getType() << std::endl;  // Prints: Word Document

    return 0;
}
