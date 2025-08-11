#include <iostream>

using namespace std;

class Stack
{
private:
    int *arr;
    int size;
    int count;
    int top;

public:
    Stack(int data)
    {
        this->arr = new int(size);
        this->count = 0;
        this->size = size;
        this->top = -1;
    }

    void push(int data);
    void pop();
    void display();
    void isEmpty();
    void isFull();
};

void Stack::push(int data)
{
    if (this->size == this->count)
    {
        cout << "Stack Is Full..." << endl;
        return;
    }

    this->top++;
    this->arr[top] = data;
    this->count++;

    cout << "Data Added Successfully..." << endl;       
}
void Stack::pop()
{
    if (this->count == 0)
    {
        cout << "Stack Is Empty..." << endl;
        return;
    }

    this->arr[top] = 0;
    this->top--;
    this->count--;

    cout << "Data deleted Successfully..." << endl;
}
void Stack::display()
{
    if (this->count == 0)
    {
        cout << "Stack Is Empty..." << endl;
        return;
    }

    for (int i = top; i <= 0; i++)
    {
        cout << this->arr[i] << endl;
    }
    
    
}
void Stack::isEmpty()
{
    if (this->count == 0)
    {
        cout << "Stack Is Empty..." << endl;
    }
    else
    {
        cout << "Stack Is not Empty..." << endl;
    }
}

void Stack::isFull()
{
    if (this->size == this->count)
    {
        cout << "Stack Is Full..." << endl;
    }
    else
    {
        cout << "Stack Is not Full..." << endl;
    }
}

int main()
{

    int n, choice;

    cout << "Input the size of Stack: ";
    cin >> n;

    Stack s(n);

    do
    {
        cout << endl;
        cout << "0. Exit. " << endl;
        cout << "1. Push Element. " << endl;
        cout << "2. Pop an Element. " << endl;
        cout << "3.  Display Elements. " << endl;
        cout << "4. Check If Stack is Empty. " << endl;
        cout << "5. Check If Stack is Full. " << endl;

        cout << "Enter the choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int data;

            cout << "Enter the data : ";
            cin >> data;

            s.push(data);
            break;
        }
        case 2:
        {
            s.pop();
            break;
        }
        case 3:
        {
            s.display();
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
    } while (choice != 0);

    return 0;
}