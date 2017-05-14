#include <iostream>
#include <string.h> // memcpy
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

void showBiArr(int arr[][100], int lines, int columns) {
    for (int i = 0 ; i < lines; i++) {
        for (int j = 0 ; j < columns; j++) {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}

void showMaxValues(int arr[][100], int lines, int columns) {
    int maxValues[3];
    // 0 - populatia
    // 1 - suprafata
    // 2 - pib
    for (int i = 0; i < columns; i++) {
        maxValues[i] = arr[0][i];
    }
    for (int i = 1; i < lines; i++) {
        for( int j = 0; j < columns; j++) {
            if (maxValues[j] < arr[i][j]) {
                maxValues[j] = arr[i][j];
            }
        }
    }
    cout << "Populatia maxima e " << maxValues[0] << endl;
    cout << "Suprafata maxima e " << maxValues[1] << endl;
    cout << "PIB-ul maxima e " << maxValues[2] << endl;
}

void showMinValues(int arr[][100], int lines, int columns) {
    int minValues[3];
    // 0 - populatia
    // 1 - suprafata
    // 2 - pib
    for (int i = 0; i < columns; i++) {
        minValues[i] = arr[0][i];
    }
    for (int i = 1; i < lines; i++) {
        for( int j = 0; j < columns; j++) {
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

void changeColumn (int arr[][100], int lines, int columns) {
    int posFirst;
    int posLast;
    cout << "introduceti pozitia primei coloane" << endl;
    cin >> posFirst;
    cout << "introduceti pozitia coloanei 2" << endl;
    cin >> posLast;

    int tempArr[columns];
    copyArr(tempArr, arr[posLast], columns);
    pasteArr(arr[posFirst], arr[posLast], columns);
    pasteArr(tempArr,arr[posFirst], columns);
}

void makeSpaceForColumn(int arr[][100], int lines, int &columns, int startPos) {
    for (int i = lines; i >= startPos; i--) {
        for (int j = 0; j < columns; j++) {
            arr[i+1][j] = arr[i][j];
        }
    }
    columns +=1;
}

void getColumnInput(int arr[], int lines) {
    cout << "Introduceti valorile pentru coloana data" << endl;
    for (int i = 0 ; i < lines; i++) {
        cin >> arr[i];
    }
}

void addColumn (int arr[][100], int &lines, int columns) {
    int pos;
    cout << "Introduceti pozitia de inserare a coloanei ";
    cin >> pos;
    makeSpaceForColumn(arr, lines, columns, pos);

    int newColumn[columns];
    getColumnInput(newColumn,lines);

    pasteArr(newColumn, arr[pos], columns);
    showBiArr(arr,lines,columns);
}

void getMedium (int arr[][100], int output[], int lines, int columns) {
    for (int j = 0 ; j < columns; j++) {
        for (int i = 0 ; i < lines -1 ; i++) {
            output[j] +=arr[i][j];
        }
        output[j] = output[j]/ (lines -1) ;
    }
}

void addColumnMed (int arr[][100], int &lines, int columns) {
    lines +=1;
    int medColumn[columns] = {0};
    getMedium(arr, medColumn, lines, columns);
    pasteArr(medColumn, arr[lines-1], columns);
}

void genSpecialMatrix(int arr[][100], int lines, int columns) {
    for (int i = 0 ; i < lines; i++) {
        int refNr = 0;
        for(int j = 0 ; j < columns; j++) {
            if (j == 0) {
              arr[i][j] =1;
              refNr = 1;
            } else {
                arr[i][j] = refNr + i+1;
            refNr = arr[i][j];
            }
        }
    }
}

void getArrInput(int arr[][100], int &lines, int &columns) {
    cout << "Introduceti numarul de randuri" <<endl;
    cin >> lines;
    cout << "Introduceti numarul de coloane" <<endl;
    cin >> columns;
    cout << "Introduceti matricea, cate " << columns << " valori pe rand" << endl;
    for (int i = 0 ; i < lines; i++) {
        cout << "Randul " << i +1<< endl;
        for (int j = 0 ; j < columns; j++){
            cin >> arr[i][j];
        }
    }
}

void getArr(int arr[], int nrElements) {
    cout << "Introduceti lista" << endl;
    for(int i = 0 ; i < nrElements;i++){
        cout << "Elementul " << i << endl;
        cin >> arr[i];
    }
}

int getSmallestNrIndex(int arr[], int startPos, int length) {
    int smallest = arr[startPos];
    int index = startPos;
    for (int i = startPos+1; i < length; i++) {
        if (smallest > arr[i]) {
            smallest = arr[i];
            index = i;
        }
    }
    return index;
}

void sortArrLines(int arr[], int arr2d[][100], int length){
    for(int i = 0 ; i < length-1; i++) {
        int smallestIndex = getSmallestNrIndex(arr, i, length);
        int tempArr[100] = {};
        memcpy(tempArr, arr2d[i], sizeof(arr2d[i])); //destination , source
        memcpy(arr2d[i], arr2d[smallestIndex], sizeof(arr2d[i])); //destination , source
        memcpy(arr2d[smallestIndex], tempArr, sizeof(arr2d[i])); //destination , source
    }
}

void sortArrColumns(int arr[], int arr2d[][100], int length){
    for(int i = 0 ; i < length-1; i++) {
        int smallestIndex = getSmallestNrIndex(arr, i, length);
        int tempArr[100] = {};
        memcpy(tempArr, arr2d[i], sizeof(arr2d[i])); //destination , source
        memcpy(arr2d[i], arr2d[smallestIndex], sizeof(arr2d[i])); //destination , source
        memcpy(arr2d[smallestIndex], tempArr, sizeof(arr2d[i])); //destination , source
    }
}

int main() {
    //test
    int lines =0;
    int columns = 0;
    int mainArr [100][100] = {0};
    getArrInput(mainArr, columns, lines);
    showBiArr(mainArr,lines,columns);
    //end test
    int refArr[5] = {0};

    cout << "(0) De determinat valorile maxime" << endl;
    cout << "(1) De determinat valorile minime" << endl;
    cout << "(2) De schimbat 2 coloane" << endl;
    cout << "(3) De adaugat 1 coloana" << endl;
    cout << "(4) De adaugat 1 coloana si de completat cu media populatiei,suprafetei si pib-ului" << endl;
    cout << "(5) De aranjaat matricea dupa linia adaugata" << endl;
    cout << "(6) De aranjaat matricea dupa coloana adaugata" << endl;
    cout << "(7) De generat matricea speciala din varianta"<<endl;

    int itemChosen;
    cout << "Alegeti varianta dorita " ;
    cin >> itemChosen;
    switch (itemChosen) {
    case 0 :
        showMaxValues(mainArr, lines, columns);
        break;
    case 1 :
        showMinValues(mainArr, lines, columns);
        break;
    case 2 :
        changeColumn(mainArr, lines, columns);
        cout << "Dupa schimbarea coloanelor" << endl;
        showBiArr(mainArr,lines,columns);
        break;
    case 3 :
        addColumn(mainArr, lines, columns);
        break;
    case 4 :
        cout << "Ultima coloana e media la PIB, populatie si suprafata" << endl;
        addColumnMed(mainArr, lines, columns);
        showBiArr(mainArr,lines-1,columns+1);
        break;
    case 5:
        getArr(refArr, columns);
        sortArrLines(refArr, mainArr, lines);
        cout << "array sortat" << endl;
        showBiArr(mainArr, lines, columns);
        break;
    case 6:
        getArr(refArr, lines);
        sortArrLines(refArr, mainArr, lines);
        cout << "array sortat" << endl;
        showBiArr(mainArr, lines, columns);
        break;
    case 7:
        genSpecialMatrix(mainArr, lines, columns);
        showBiArr(mainArr, lines, columns);
        break;
    default:
        cout << "Gresit" << endl;
    }
    return 0;
}

