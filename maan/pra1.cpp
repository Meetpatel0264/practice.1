#include <iostream>
#include <stack>
using namespace std;

int main (){

    string str;

    cout << "enter any string : ";
    getline(cin, str);

    stack <char> palandromeString;

    for (char alpha : str)
    {
        palandromeString.push(alpha);
    }
    for (char character : str)
    {
        if (character != palandromeString.top())
        {
            cout << "IT'S NOT A PALANDROME.... " << endl;
            return 0;
        }
        palandromeString.pop();
    }
    cout << "IT'S A PALANDROME.... " << endl;
    
    

    return 0;
}