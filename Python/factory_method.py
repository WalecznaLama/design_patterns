from abc import ABC, abstractmethod


class Document(ABC):
    @abstractmethod
    def show_type(self):
        pass


class PdfDocument(Document):
    def show_type(self):
        return "PDF Document"


class WordDocument(Document):
    def show_type(self):
        return "Word Document"


class DocumentFactory(ABC):
    @abstractmethod
    def create_document(self) -> Document:
        pass


class PdfDocumentFactory(DocumentFactory):
    def create_document(self) -> Document:
        return PdfDocument()


class WordDocumentFactory(DocumentFactory):
    def create_document(self) -> Document:
        return WordDocument()


if __name__ == "__main__":
    # Użycie
    pdf_factory = PdfDocumentFactory()
    document = pdf_factory.create_document()
    print(document.show_type())  # Wyświetla: PDF Document

    word_factory = WordDocumentFactory()
    document = word_factory.create_document()
    print(document.show_type())  # Wyświetla: Word Document
