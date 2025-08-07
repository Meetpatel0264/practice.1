#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

class Linkedlist{
    public:
    Node * head;
    int count;
    Linkedlist(){
        this->head=nullptr;
        this->count=0;
    }
    void addAtStart(int data){

        Node *newnode = new Node(data);
        if(count == 0 && head == nullptr){
            head = newnode;
        }
        else{
            newnode->next=head;
            head = newnode;
        }
        this->count++;
    };
    void Search(int data){
        
        Node * temp=head;
        int flag=1;

        while(temp != nullptr){
            if(temp->data == data){
                flag = 0;
            }

             temp = temp->next;
                   
        }

        if( flag == 0){
            cout <<"data is in the link list" << endl;
        }
        else{
            cout <<"Data is not in the linked list:" << endl;
        }

    }
    void deleteatPos(int pos){
        Node *prev= head;
        Node *curr=head;

        for(int i = 1 ; i < pos ; i ++){
            curr = curr->next;
        }
        for(int i = 1 ; i < pos-1 ; i ++){
            prev = prev->next;
        }

        prev->next=curr->next;
        delete curr;
        prev = nullptr;
        this->count--;

        
    }
    void reverse(){
        Node *prev=nullptr;
        Node *curr=head;
        Node *next2;

        while (curr != nullptr)
        {
         next2=curr->next;
         curr->next=prev;
         prev=curr;
         curr=next2;    
        }

        head=prev;
        
    }

    void display(){
        Node *temp = head;

        while(temp != nullptr){
            cout << temp->data <<"-->";
            temp = temp->next;
        }
        cout <<"Null";
        cout << endl;
    }


};

int main(){

    int choice;
    Linkedlist List;

    do
    {
        cout <<"Enter 1 to add at start:" << endl;
        cout <<"Enter 2 to Search Node:" << endl;
        cout <<"Enter 3 to delete at any position Node:" << endl;
        cout <<"Enter 4 to reverse Node:" << endl;
        cout <<"Enter 5 to Display Linkedlist:" << endl;
        cout <<"Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            {

            int data;
            cout <<"Enter data you want to insert:" ;
            cin >> data;
            List.addAtStart(data);
            cout <<"data entered successfully:" << endl;

            break;
        }
        case 2:{
            int data;
            cout <<"Enter data you want to find";
            cin >> data;
            List.Search(data);
            break;
        }
        case 3:{
            int pos;
            cout <<"Enter pos you want to delete";
            cin >> pos;
            List.deleteatPos(pos);
            cout <<"Data deleted Successfully:" << endl;
            break;
        }
        case 4:{
            List.reverse();
            break;
        }
        case 5:{
            List.display();
            break;
        }
        
        default:
            break;
        }
    } while (choice != 0);
}