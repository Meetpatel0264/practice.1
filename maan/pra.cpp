#include <iostream>
#include <stack>

using namespace std;

void decToBin(int);

int main(){
   int data;
    cout << "enter the any num... : ";
    cin >> data;

    decToBin(data);

    return 0;
}
void decToBin (int data){
     stack <int> decToBin;
    int count = 0;
    int rem;

   while (data > 0){
    rem = data % 2;
    decToBin.push(rem);
    data = data / 2;
    count++;    
   }

   for (int i = 0; i < count; i++){
    cout << decToBin.top();
    decToBin.pop();
}
}