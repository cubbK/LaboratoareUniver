#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
//Laborator 5
using namespace std;

class Text {
public:
    Text(string text) :rawText(text) {}; //constructor
    string rawText;
    vector<string> words = separateText(rawText); //cuvintele separate

    void showBadWords() {
        cout << "Cuvintele ce nu satisfac cerintei sunt: ";
        for (int i = 0; i < words.size(); i++) {
            if (!wordIsGood(words[i])) {
                cout << words[i] << " ";
            }
        }
    }

    void showGoodWords() {
        cout << "Fraza noua:" <<endl;
        for (int i = 0 ; i < words.size(); i++) {
            if (wordIsGood(words[i])) {
                cout << words[i] << " ";
            }
        }
    }

    void writeGoodWords(){
        string goodWords ="";
        for (int i = 0; i < words.size(); i++) {
            if (wordIsGood(words[i])) {
                goodWords += words[i] + " ";
            }
        }
        writeToFile(goodWords, "data.out");
    }

    void deleteGoodWords() {
        string badWords ="";
        for (int i = 0; i < words.size(); i++) {
            if (!wordIsGood(words[i])) {
                badWords += words[i] + " ";
            }
        }
        cout << "cuvinte rele "<< badWords << endl;
        writeToFile(badWords, "data.in");
    }
private:
    vector<string> separateText(string text) {
        vector<string> words;
        istringstream iss(text);
        for(string text; iss >> text; ) {
            words.push_back(text);
        }
        return words;
    }

    bool wordIsGood(string word) {
        char vowels[5] = {0};
        for (int i = 0; i < word.size(); i++) {
            switch(word[i]){
            case 'a':
                vowels[0] +=1;
                break;
            case 'e':
                vowels[1] +=1;
                break;
            case 'i':
                vowels[2] +=1;
                break;
            case 'o':
                vowels[3] +=1;
                break;
            case 'u':
                vowels[4] +=1;
                break;
            }
        }
        for (int i = 0 ; i < 5; i++) {
            if(vowels[i]>1) {
                return false;
            }
        }
        return true;
    }

    void writeToFile(string text, string file) {
        ofstream stream(file.c_str());
        stream << text;
        stream.close();
    }
};

class Students : public Text {
private:
    struct student{
        string name;
        int mark1;
        int mark2;
    };
    vector<student> separateStudents() {
        vector<student> students;
        int pos = 0;


        return students;
    }
public:
    Students(string text) : Text(text){};
    vector<student> studentsList;


    void showWords() {
        for (int i = 0 ; i < words.size(); i++) {
            cout << words[i] << " ";
        }
        cout << endl;
    }
};

string readFromFile(string filePath) {
    ifstream inFile(filePath.c_str());
    stringstream strStream;
    strStream << inFile.rdbuf();//read the file
    return strStream.str();
}

int main() {
    //data.in processing
    string inFileStr = readFromFile("data.in");
    //end data.in processing
    string inFileStudents = readFromFile("students.dat");


    string text;
    cout << "Introduceti fraza"<<endl;
    getline(cin, text);

    Text UserText(text);
    Text DataText(inFileStr);
    Students students(inFileStudents);
    students.showWords();



    cout << "(0) Intr-o fraza de determinat numarul de cuvinte." << endl;
    cout << "(1) De determinat cuvintele dintr-o fraza, ce contin orice vocala doar o singura data." << endl;
    cout << "(2) De sters cuvintele dintr-o fraza, ce contin orice vocala doar o singura data." << endl;
    cout << "(3) In fisierul data.in de determinat numărul de cuvinte." << endl;
    cout << "(4) De inscris in fisierul data.out cuvintele, ce contin orice vocala doar o singură data." << endl;
    cout << "(5) De sters cuvintele din data.in, ce contin orice vocala doar o singura data" << endl;
    cout << "(6) De aratat studentii cu media mai mare de N din students.dat"<<endl;

    int itemChosen;
    cout << "Alegeti varianta dorita " << endl;
    cin >> itemChosen;
    switch (itemChosen){
    case 0:
        cout << "Sunt "<< UserText.words.size() << " cuvinte" << endl;
        break;
    case 1:
        UserText.showGoodWords();
        break;
    case 2:
        UserText.deleteGoodWords();
        cout << "Cuvintele ce satisfac conditia au fost sterse" << endl;
        break;
    case 3:
        cout << "Sunt "<< DataText.words.size() << " cuvinte in data.in" << endl;
        break;
    case 4 :
        UserText.writeGoodWords();
        cout << "Operatie reusita" <<endl;
        break;
    case 5:
        DataText.deleteGoodWords();
        cout << "Operatie reusita"<< endl;
        break;
    case 6:
        cout << "Conditie speciala";
        break;
    default:
        cout << "Ati ales varianta gresita" << endl;


    }
    return 0;
}
