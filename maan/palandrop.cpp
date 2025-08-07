#include <iostream>
#include <stack>

using namespace std;

int main(){
    string str;

    cout << "enter the palandrome string... : ";
    getline(cin, str);

    stack <char> palandrome;

    for (char alpha : str){
         palandrome.push(alpha);
    }
    for (char c : str)
    {
        if (c != palandrome.top())
        {
            cout << "It's Not A Palandrome " << endl;
            return 0;
        }
        palandrome.pop();
    }

    cout << "it's A Palandrom " << endl;
    
    

    return 0;
}