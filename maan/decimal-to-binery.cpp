#include <iostream>
#include <stack>
using namespace std;

void convertDectoBinary(int);
void convertDectoBinary(int n){
    stack<int> DecitoBin;
    int rem , count = 0;
    while(n > 0){
        rem = n  % 2 ;
        DecitoBin.push(rem);
        n = n / 2 ;
        count++ ;
    }
    for(int i = count ; i >= 0 ; i--){
        cout << DecitoBin.top();
        DecitoBin.pop();
    }    
}
int main(){
    int n;
    cout << "Enter a number : ";
    cin >> n ;
    convertDectoBinary(n);
    return 0 ;
}
