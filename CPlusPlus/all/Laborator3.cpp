#include <iostream>

using namespace std;
//Laborator 3
//De facut mai sof
int maxim(int numbers[],int n) {
    int maxNr = numbers[0];
    for (int i = 0 ; i < n;i++) {
        if (maxNr < numbers[i]) {
            maxNr = numbers[i];
        }
    }
    return maxNr;
}

int minim(int numbers[],int n) {
    int minNr = numbers[0];
    for (int i = 0 ; i < n;i++) {
        if (minNr > numbers[i]) {
            minNr = numbers[i];
        }
    }
    return minNr;
}

float media(int numbers[],int n) {
    float suma = 0;
    for (int i = 0 ; i < n;i++) {
        suma += numbers[i];
    }
    return suma /(float)n;
}

void insertionSortDesc(int numbers[],int n) {
     int i, j, key, numLength = n;
     for(j = 1; j < numLength; j++) {
        key = numbers[j];
        for(i = j - 1; (i >= 0) && (numbers[i] < key); i--) {
                 numbers[i+1] = numbers[i];
        }
        numbers[i+1] = key;
     }
}

void add(int numbers[],int &n) {
    int value;
    cout << "Introduceti valoarea" <<endl;
    cin >> value;
    int pos;
    cout << "Introduceti pozitia" << endl;
    cin >> pos;
    for (int i = n -1 ; i >= pos; i--) {
        numbers[i+1] = numbers[i];
    }
    numbers[pos] = value;
    n +=1;
}

void del(int numbers[], int &n) {
    int pos;
    cout << "introduceti pozitia" << endl;
    cin >> pos;
    for (int i = pos; i < n-1; i++) {
        numbers[i] = numbers[i+1];
    }
    n -=1;
}

void showArray(int numbers[],int n) {
    for (int i = 0 ; i < n ; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

int suma(int numbers[],int n) {
    int s=0;
    for (int i = 0 ; i < n ; i++) {
        s+=numbers[i];
    }
    return s;
}

void rotateArr(int numbers[], int n) {
    int first = numbers[0];
    for (int i =1; i < n;i++) {
        numbers[i-1] = numbers[i];
    }
    numbers[n-1] = first;
}

int main() {
    int n;
    cout << "Introduceti n"<< endl;
    cin >> n;
    int numbers[100];
    cout << "Introduceti tabelul(fiecare valoare prin enter)" << endl;
    for (int i = 0 ; i < n; i++) {
        cin >> numbers[i];
    }
    cout << "(0) Afisat maximul si minimul" << endl;
    cout << "(1) Afisat media aritmetica" << endl;
    cout << "(2) Sortare" << endl;
    cout << "(3) Rotirea la stinga de 8 ori" << endl;
    cout << "(4) Adauga in tablel" << endl;
    cout << "(5) Sterge din tabel" << endl;
    cout << "(6) Afiseaza Suma" << endl;
    int option;
    cin >> option;
    switch(option) {
    case 0 :
        cout << "Numarul maxim e " << maxim(numbers,n) << endl;
        cout << "Numarul minim e " << minim(numbers,n) << endl;
        break;
    case 1 :
        cout << "Media e " << media(numbers,n) << endl;
        break;
    case 2 :
        insertionSortDesc(numbers,n);
        cout << "Tabelul in ordine decrescatoare: ";
         showArray(numbers,n);
        break;
    case 3 :
        for (int i = 0 ; i < 8; i++) {
            rotateArr(numbers,n);
        }
        cout << "Dupa rotire: ";
        showArray(numbers,n);
        break;
    case 4 :
        add(numbers,n);
        cout << "Lista noua: " << endl;
        showArray(numbers, n);
        break;
    case 5 :
        del(numbers, n);
        cout << "Lista nou e " << endl;
        showArray(numbers,n);
        break;
    case 6 :
        cout << "Suma este " << suma(numbers,n) << endl;
        break;
    default :
        cout << "incorect";
        break;
    }
    return 0;
}
