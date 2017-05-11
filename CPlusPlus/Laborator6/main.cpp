#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

class Country{
public:
    int id;
    string name;
    string capital;
    string continent;
    int aria;
    int populatie;
    int pib;
    void setData(){
        cout << "ID:";
        cin >> id;
        cout << "\nNume:";
        cin >> name;
        cout << "\nCapitala:";
        cin >> capital;
        cout << "\nContinentul:";
        cin >> continent;
        cout << "\nAria:";
        cin >> aria;
        cout << "\nPopulatia" ;
        cin >> populatie;
        cout << "\nPIB:" ;
        cin >> pib;
    }

    void showData(){
        cout << id << " " << name << " " << capital << " " << continent << " " << aria << " " << populatie << " " << pib;
    }

};

/*
* function to write in a binary file.
*/

void write_record(){
    ofstream outFile;
    outFile.open("data.bin", ios::binary | ios::app);

    Country obj;
    obj.setData();

    outFile.write((char*)&obj, sizeof(obj));

    outFile.close();
}

/*
* function to display records of file
*/


void display(){
    ifstream inFile;
    inFile.open("data.bin", ios::binary);

    Country obj;

    while(inFile.read((char*)&obj, sizeof(obj))){
        obj.showData();
    }

    inFile.close();
}

/*
* function to search and display from binary file
*/

void search(int n){
    ifstream inFile;
    inFile.open("student.dat", ios::binary);

    Country obj;

    while(inFile.read((char*)&obj, sizeof(obj))){
        if(obj.id == n)
        {
            obj.showData();
        }
    }

    inFile.close();
}

/*
* function to delete a record
*/

void delete_record(int n){
    Country obj;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);

    ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.id != n)
        {
            outFile.write((char*)&obj, sizeof(obj));
        }
    }

    inFile.close();
    outFile.close();

    remove("student.dat");
    rename("temp.dat", "student.dat");
}

/*
* function to modify a record
*/

void modify_record(int n){
    fstream file;
    file.open("student.dat",ios::in | ios::out);

    Country obj;

    while(file.read((char*)&obj, sizeof(obj)))
    {
        if(obj.id == n)
        {
            cout << "\nEnter the new details of student";
            obj.setData();

            int pos = -1 * sizeof(obj);
            file.seekp(pos, ios::cur);

            file.write((char*)&obj, sizeof(obj));
        }
    }

    file.close();
}
//Laborator 6
int main() {
    Country obj;
    write_record();
    obj.showData();
    //data.in processing
    ifstream inFile("data.txt");
    stringstream strStream;
    strStream << inFile.rdbuf();//read the file
    string inFileStr = strStream.str();//str holds the content of the file
    //end data.in processing
    cout << inFileStr << endl;
    cout << "(0) De inscris datele initiale intr-un fisier binar dintr-un fisier text" << endl;
    cout << "(1) De inscris datele initiale intr-un fisier binar de la tastatura" << endl;
    cout << "(2) De adaugat date in fisier." << endl;
    cout << "(3) De afisat continutul fisierului initial / intermediar / final." << endl;
    cout << "(4) De aranjat datele din fisier dupa id" << endl;
    cout << "(5) De aranjat datele din fisier dupa id si nume" << endl;
    cout << "(6) De sters datele din fisier cu cel mai mare id" << endl;
    cout << "(7) De calculat numarul datelor inscrise" << endl;
    cout << "(8) De afisat 3 liste tematice" << endl;

    int  choise;
    cout << "Alegetei varianta" << endl;
    cin >> choise;

    return 0;
}
