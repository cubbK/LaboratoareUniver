#include <iostream>
using namespace std;
//Laborator 4

//Populatia
//Suprafata
//PIB
void showArr(int arr[], int lines) {
    for (int i = 0; i < lines; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void showBiArr(int arr[][100], int lines, int rows) {
    for (int i = 0 ; i < lines; i++) {
        for (int j = 0 ; j < rows; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void showMaxValues(int arr[][100], int lines, int rows) {
    int maxValues[3];
    // 0 - populatia
    // 1 - suprafata
    // 2 - pib
    for (int i = 0; i < rows; i++) {
        maxValues[i] = arr[0][i];
    }
    for (int i = 1; i < lines; i++) {
        for( int j = 0; j < rows; j++) {
            if (maxValues[j] < arr[i][j]) {
                maxValues[j] = arr[i][j];
            }
        }
    }
    cout << "Populatia maxima e " << maxValues[0] << endl;
    cout << "Suprafata maxima e " << maxValues[1] << endl;
    cout << "PIB-ul maxima e " << maxValues[2] << endl;
}

void showMinValues(int arr[][100], int lines, int rows) {
    int minValues[3];
    // 0 - populatia
    // 1 - suprafata
    // 2 - pib
    for (int i = 0; i < rows; i++) {
        minValues[i] = arr[0][i];
    }
    for (int i = 1; i < lines; i++) {
        for( int j = 0; j < rows; j++) {
            if (minValues[j] > arr[i][j]) {
                minValues[j] = arr[i][j];
            }
        }
    }
    cout << "Populatia minima e " << minValues[0] << endl;
    cout << "Suprafata minima e " << minValues[1] << endl;
    cout << "PIB-ul minim e " << minValues[2] << endl;
}

void copyArr(int arr[], int arr2[], int items) {
    for (int i = 0; i < items; i++) {
        arr[i] = arr2[i];
    }
}

void pasteArr(int from[], int to[], int lines) {
    for (int i = 0 ; i < lines; i++) {
        to[i] = from[i];
    }
}

void changeColumn (int arr[][100], int lines, int rows) {
    int posFirst;
    int posLast;
    cout << "introduceti pozitia primei coloane" << endl;
    cin >> posFirst;
    cout << "introduceti pozitia coloanei 2" << endl;
    cin >> posLast;

    int tempArr[rows];
    copyArr(tempArr, arr[posLast], rows);
    pasteArr(arr[posFirst], arr[posLast], rows);
    pasteArr(tempArr,arr[posFirst], rows);
}

void makeSpaceForColumn(int arr[][100], int &lines, int rows, int startPos) {
    for (int i = lines; i >= startPos; i--) {
        for (int j = 0; j < rows; j++) {
            arr[i+1][j] = arr[i][j];
        }
    }
    lines +=1;
}

void getColumnInput(int arr[], int rows) {
    cout << "Introduceti valorile pentru coloana data" << endl;
    for (int i = 0 ; i < rows; i++) {
        cin >> arr[i];
    }
}

void addColumn (int arr[][100], int &lines, int rows) {
    int pos;
    cout << "Introduceti pozitia de inserare a coloanei ";
    cin >> pos;
    makeSpaceForColumn(arr, lines, rows, 1);

    int newColumn[rows];
    getColumnInput(newColumn,rows);

    pasteArr(newColumn, arr[pos], rows);
    showBiArr(arr,lines,rows);
}

int main() {
    //test
    int lines = 3;
    int rows = 3;
    int mainArr [100][100] = { {1,1,1} ,

                               {2,2,2},
                               {3,3,3}
                             };
    showBiArr(mainArr,lines,rows);
    //end test
    cout << "(0) De determinat valorile maxime" << endl;
    cout << "(1) De determinat valorile minime" << endl;
    cout << "(2) De schimbat 2 coloane" << endl;
    cout << "(3) De adaugat 1 coloana" << endl;
    cout << "(4) De adaugat 1 coloana si de completat cu media populatiei,suprafetei si pib-ului" << endl;
    cout << "(5) ???" << endl;
    cout << "De generat matricea speciala din varianta"<<endl;

    int itemChosen;
    cout << "Alegeti varianta dorita " ;
    cin >> itemChosen;
    switch (itemChosen) {
    case 0 :
        showMaxValues(mainArr, lines, rows);
        break;
    case 1 :
        showMinValues(mainArr, lines, rows);
        break;
    case 2 :
        changeColumn(mainArr, lines, rows);
        cout << "Dupa schimbarea coloanelor" << endl;
        showBiArr(mainArr,lines,rows);
        break;
    case 3 :
        addColumn(mainArr, lines, rows);
        break;
    default:
        cout << "Gresit" << endl;
    }
    return 0;
}

