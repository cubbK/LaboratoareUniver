#include <iostream>
#include <string>
//Laborator 5
using namespace std;

class Text {
public:
    Text(string text) :rawText(text) {};
    string rawText;
};

int main()
{
    Text UserText("Hey dude");
    cout << "textul din fraza e " << UserText.rawText;
    return 0;
}
