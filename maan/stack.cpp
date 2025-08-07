#include<iostream>

using namespace std;

class Stack
{
    private:
        int top;
        int size;
        int count;
        int *arr;
    public:
        Stack(int size){
            this->top = -1;
            this->count = 0;
            this->size = size;
            this->arr = new int[size];
        }

        void Push(int);
        void Pop();
        void Display();
        void isEmpty();
        void isFull();
};

void Stack::Push(int data){

    if(this->size == this->count){
        cout << "\n--------------\n";
        cout << "Stack is Full..." << endl;
        cout << "--------------\n\n";
        return;
    }

    this->top++;
    this->arr[top] = data;
    this->count++;

    cout << "\n---------------------------\n";
    cout << "Data Inserted successfully..." << endl;
    cout << "------------------------------\n\n";
}

void Stack::Pop(){
    if(this->count == 0){
        cout << "\n--------------\n";
        cout << "Stack is Empty..." << endl;
        cout << "-----------------\n\n";
        return;
    }

    this->arr[top] = 0;
    this->top--;
    this->count--;

    cout << "\n---------------------------\n";
    cout << "Data Deleted successfully..." << endl;
    cout << "------------------------------\n\n";
}

void Stack::Display(){
    if(this->count == 0){
        cout << "\n--------------\n";
        cout << "Stack is Empty..." << endl;
        cout << "-----------------\n\n";
        return;
    }

    for(int i = this->top; i >= 0; i--){
        cout << endl;
        cout << arr[i] << endl;
    }
}

void Stack::isEmpty(){
    if(this->count == 0){
        cout << "\n--------------\n";
        cout << " Yes, Stack is Empty..." << endl;
        cout << "-----------------\n\n";
    }else{
        cout << "\n--------------\n";
        cout << " No, Stack is not Empty..." << endl;
        cout << "-----------------\n\n";
    }
}

void Stack::isFull(){
    if(this->size == this->count){
        cout << "\n-------------------\n";
        cout << "Yes, Stack is Full..." << endl;
        cout << "---------------------\n\n";
    }else{
        cout << "\n----------------------\n";
        cout << "No, Stack is not Full..." << endl;
        cout << "------------------------\n\n";
    }
}

int main(){

    int size, choice;

    cout << "Input the size of Stack: ";
    cin >> size;

    Stack s(size);

    do{
        cout << endl;
        cout << "0. Exit. "  << endl;
        cout << "1. Push Element. " << endl;
        cout << "2. Pop an Element. " << endl;
        cout << "3.  Display Elements. " << endl;
        cout << "4. Check If Stack is Empty. " << endl;
        cout << "5. Check If Stack is Full. " << endl;

        cout << "Enter the choice : ";
        cin >> choice;

        switch(choice){
            case 1:
            {
                int data;

                cout << "Enter the data : " ;
                cin >> data;

                s.Push(data);
                break;
            }
            case 2:
            {
                s.Pop();
                break;
            }
            case 3:
            {
                s.Display();
                break;
            }
            case 4:
            {
                s.isEmpty();
                break;
            }
            case 5:
            {
                s.isFull();
                break;
            }
            case 0:
            {
                cout << "\n--------------\n";
                cout << "Thank You for Using Stack..." << endl;
                cout << "--------------\n\n";
                break;
            }
        }
    }while(choice != 0);
    
    return 0;
}