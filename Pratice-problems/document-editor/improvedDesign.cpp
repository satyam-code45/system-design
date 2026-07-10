#include <bits/stdc++.h>

using namespace std;

// abstraction for the document elements
class DocumentElement
{
public:
    virtual string render() = 0;
};

// implementation of text elements
class TextElement : public DocumentElement
{
private:
    string text;

public:
    TextElement(string text)
    {
        this->text = text;
    }

    string render() override
    {
        return text;
    }
};

// implementation of image
class ImageELement : public DocumentElement
{
private:
    string iamgePath;

public:
    ImageELement(string imagePath)
    {
        this->iamgePath = imagePath;
    }

    string render() override
    {
        return "[Image: " + iamgePath + "]";
    }
};

class NewLineElement : public DocumentElement
{
public:
    string render() override
    {
        return "\n";
    }
};

class TabSpaceElement : public DocumentElement
{
public:
    string render() override
    {
        return "\t";
    }
};

// Document class responsible for holding a colleciton of elments;

class Document
{
private:
    vector<DocumentElement *> documentElements;

public:
    void addElement(DocumentElement *element)
    {
        documentElements.push_back(element);
    }

    string render()
    {
        string result;

        for (auto element : documentElements)
        {
            result += element->render();
        }
        return result;
    }
};

// persistence class
class Persistence
{
public:
    virtual void save(string data) = 0;
};

class FileStorage : public Persistence
{
public:
    void save(string data) override
    {
        ofstream outFile("document.txt");

        if (outFile)
        {
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        }
        else
        {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }
};

class DBStorage : public Persistence
{
public:
    void save(string data) override
    {
        cout << "Saving this data to DB: \n"
             << data;
    }
};

// DocumentEditor class managing  client interations
class DocumentEditor
{
private:
    Document *document;
    Persistence *storage;
    string renderedDocument;

public:
    DocumentEditor(Document *document, Persistence *storage)
    {
        this->document = document;
        this->storage = storage;
    }

    void addText(string text)
    {
        document->addElement(new TextElement(text));
    }

    void addImage(string imagePath)
    {
        document->addElement(new ImageELement(imagePath));
    }

    void addNewLine()
    {
        document->addElement(new NewLineElement());
    }

    void addTabSpace()
    {
        document->addElement(new TabSpaceElement());
    }

    string renderDocument()
    {
        if (renderedDocument.empty())
        {
            renderedDocument = document->render();
        }
        return renderedDocument;
    }

    void SaveDocument()
    {
        storage->save(renderDocument());
    }
};

// client code
int main()
{
    Document *document = new Document();
    Persistence *persistence = new FileStorage();

    DocumentEditor *editor = new DocumentEditor(document, persistence);

    editor->addImage("picture.png");
    editor->addText("Hello World!");
    editor->addTabSpace();
    editor->addText("Hello after Tab Space");
    editor->addNewLine();
    editor->addText("Hello from new line");
    editor->addImage("satyam.png");

    cout << editor->renderDocument() << endl;

    editor->SaveDocument();

    return 0;
}