#include<bits/stdc++.h>

using namespace std;

class DocumentEditor{
private:
    vector<string> documentElements;
    string renderedDocument;
public:
    void addText(string text){
        documentElements.push_back(text);
    }

    void addImage(string imagePath){
        documentElements.push_back(imagePath);
    }


    string renderDocument(){
        if(renderedDocument.empty()){
            string result;

            for(auto element : documentElements){
                if((element.find(".jpg") != string::npos ) || (element.find(".png") != string::npos )){
                    result += "[Image:  " + element + "]" + "\n";
                }else{
                    result += element + "\n";
                }
            }
            renderedDocument = result;
        }
        return renderedDocument;
    }


    void saveToFile(){
        ofstream file("document.txt");

        if(file.is_open()){
            file << renderDocument();
            file.close();
            cout<<"Document saved to document.txt"<<endl;
        }else{
            cout<<"Error: Unable to open the file for writing."<<endl;
        }
    }
};

int main(){
    DocumentEditor editor;
    editor.addText("Hello, World!");
    editor.addImage("picture.png");
    editor.saveToFile();

    return 0;
}