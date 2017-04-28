#include <iostream>
#include <string>
#include <vector>

using namespace std;
//Numere Pandigitale
// Laborator 2
bool isPrime(long nr){
    for(long i = 2; i <= nr / 2; i++){
      if(nr % i == 0){
          return false;
      }
  }
  return true;
}
bool isPandigital(long nr) {
    int allNr[10] = {0};
    while (nr > 0) {
        int singleNr = (int)(nr%10);
        nr = nr /10;
        allNr[singleNr] +=1;
    }
    bool isZero = false;
    int posArr = 0;
    while (!isZero && posArr<10) {
        if (allNr[posArr] ==0) {
            isZero = true;
        }else
        posArr +=1;
    }
    if (isZero) {
        return false;
    }else {
        return true;
    }
}

vector<long> allPanFromInterval(long a, long b) {
    vector<long> numbers;
    for (int i = a ; i <=b;i++){
        if(isPandigital(i)) {
            numbers.push_back(i);
        }
    }
    return numbers;
}

void showAllPanFromInterval(){
    long a,b;
        cout << "introduceti a " << endl;
        cin >> a;
        cout <<"introduceti b" << endl;
        cin >> b;
        vector<long> numbers = allPanFromInterval(a,b);
        if ( numbers.size() == 0) {
            cout << "nu sunt numere pandigitale in intervalul dat" << endl;
        } else {
            cout << "Numerele pan sunt: ";
            for (int i = 0 ; i < numbers.size();i++) {
                cout << numbers[i] << " ";
            }
            cout << endl;
        }
}

void showAllPrimeFromInterval(){
    long a,b;
    cout << "introduceti a " << endl;
    cin >> a;
    cout <<"introduceti b" << endl;
    cin >> b;
    vector<long> numbers = allPanFromInterval(a,b);
    for (int i = 0 ; i < numbers.size();i++) {
        if (isPrime(numbers[i])) {
            cout << numbers[i] << endl;
        }
    }
}

void firstNPan(){
    int n;
    cout << "Introdu n" << endl;
    cin >> n;
    long i = 1023456789;
    while (n > 0) {
        if (isPandigital(i)) {
            cout << i << endl;
            n-=1;
        }
        i+=1;
    }
}

void biggestNum() {
    long a,b;
    cout << "introduceti a " << endl;
    cin >> a;
    cout <<"introduceti b" << endl;
    cin >> b;
    vector<long> numbers = allPanFromInterval(a,b);
    cout << "Numarul maxim e " << numbers[numbers.size()-1] << endl;
}
void selectToDo() {
    cout << "Introduceti cifra pt operatia dorita" << endl;
    cout << "(0)Daca nr e pandigital" <<endl;
    cout << "(1)Care numere din intervalul [a,b] sunt pandigitale" <<endl;
    cout << "(2)primele n numere, care sunt pandigitale" <<endl;
    cout << "(3)Care numere din intervalul [a,b] sunt pandigitale prime" <<endl;
    cout << "(4)cel mai mare numar pandigital" <<endl;
    cout << "(5)Exit" << endl;
    int operation;
    cin >> operation;
    switch(operation) {
    case 0:
        long nr;
        cout << "introdu nr "<< endl;
        cin >> nr;
        if(isPandigital(nr)) {
            cout << "e pan"<<endl;
        }else {
            cout << "nu e pan"<<endl;
        }
        break;
    case 1:
        showAllPanFromInterval();
        break;
    case 2 :
        firstNPan();
        break;
    case 3:
         showAllPrimeFromInterval();
         break;
    case 4:
        biggestNum();
        break;
    default :
        cout << "no dude";
    }
}
int main(){

    selectToDo();
    return 0;
}
