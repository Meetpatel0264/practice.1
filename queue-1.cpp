#include <iostream>
using namespace std;

class Queue{
    private : 
        int front;
        int *arr;
        int rear;
        int count;
        int size;

    public :
        Queue(int size){
            this->arr = new int[size];
            this->count = 0 ; 
            this->front = -1;
            this->rear = -1;
            this->size = size;
        }

        void enqueue(int);
        void dequeue();
        void display();
        void getFront();
        void getRear();
        bool isempty();
        bool isfull();
        int getSize();
};

void Queue::enqueue(int data){
    if(this->rear == this->size -1){
        cout << "Queue is full ...." << endl;
        return;
    }
    if(this->front == -1 && this->rear == -1){
        this->rear++;
        this->front++;
        this->arr[this->rear] = data;
        this->count++;
        cout << "Data successfully added..." << endl;
    }else{
        this->rear++;
        this->arr[this->rear] = data;
        this->count++;
        cout << "Data successfully added..." << endl;
    }
}

void Queue::dequeue(){
    if(this->front == -1 && this->rear == -1){
        cout << "Queue is empty .. " << endl;
        return ;
    }else{
        this->arr[this->front] = 0 ;
        this->front++ ; 
        this->count--;
        cout << "Element deleted successfully." << endl;
    }
}

void Queue::display(){
    if(this->front == -1 && this->rear == -1){
        cout <<"--------------------\n";
        cout << "Queue is empty.";
        cout << "\n--------------------\n\n";
        return;
    }
    cout << "\n--------------------\n\n";
    for(int i = this->front ; i <= this->rear ; i++){
        cout << arr[i] << " " ;
    }
    cout << "\n--------------------\n\n";
}

void Queue::getFront(){
    cout << "Front Data : " << this->arr[this->front] << endl;
}

void Queue::getRear(){
    cout << "Rear Data : " << this->arr[this->rear] << endl;
}

bool Queue::isempty(){
    return this->count == 0;
}

bool Queue::isfull(){
    return this->count == this->size;
}

int Queue::getSize(){
    return count;
}

int main(){
    int choice , size;
    cout << "Enter the size of Queue : ";
    cin >> size;

    Queue q(size);

    do
    {
        cout << "Enter 1 to enqueue data." << endl;
        cout << "Enter 2 to dequeue data." << endl;
        cout << "Enter 3 to get Front data." << endl;
        cout << "Enter 4 to get Rear data." << endl;
        cout << "Enter 5 to display all data." << endl;
        cout << "Enter 6 to check whether queue is empty ." << endl;
        cout << "Enter 7 to check whether queue is full ." << endl;
        cout << "Enter 8 to check size of queue." << endl;
        cout << "Enter 0 to exit." << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1 : {
                int data;
                cout << "Enter data : " ;
                cin >> data;
                q.enqueue(data);
                break;
            }
            case 2 : {
                q.dequeue();
                break;
            }
            case 3 : {
                q.getFront();
                break;
            }
            case 4 : {
                q.getRear();
                break;
            }
            case 5 : {
                q.display();
                break;
            }
            case 6 : {
                if(q.isempty() == true){
                    cout << "Queue is empty." << endl;
                }else{
                    cout << "Queue is not empty." << endl;
                }
                break;
            }
            case 7 : {
                if(q.isfull() == true){
                    cout << "Queue is Full .. " << endl;
                }
                else{
                    cout << "Queue is not Full .. " << endl;
                }
                break;
            }
            case 8 : {
                cout << "Size of Queue : " << q.getSize() << endl;
                break;
            }
            case 0 : {
                cout << "\n----------------------\n";
                cout << "THANK FOR VISIING." ;
                cout << "\n----------------------\n\n";
                break;
            }
        }
    } while (choice != 0);
    
    

    return 0;
}