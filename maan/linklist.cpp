#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node (int data) {
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList {
    public:
        Node *head;
        Node *tail;
        int count;

        LinkedList () {
            this->head = nullptr;
            this->count = 0;
        }

        void addAtStart(int data) {
            Node *newNode = new Node(data);

            newNode->next = this->head;
            this->head = newNode;
            this->count++;

            cout << "\n-----------------------------------\n";
            cout << "New Node Added Successfully..." << endl;
            cout << "-----------------------------------\n\n";
        }

        void addAtEnd (int data) {
            Node *newNode = new Node(data);

            if(this->head == NULL || this->count == 0) {
                this->head = newNode;
                this->count++;
            } else {
                Node *temp = this->head;

                while (temp->next != NULL) {
                    temp = temp->next;
                }

                temp->next = newNode;
                this->count++;

                cout << "\n-----------------------------------\n";
                cout << "New Node Added Successfully..." << endl;
                cout << "-----------------------------------\n\n";
            }
        }

        void addAtAnyPosition(int data, int pos) {  
            Node *newNode = new Node(data);

            if(this->head == NULL || this->count == 0){
                this->head = newNode;
                this->count++;
            } else {
                Node *temp = this->head;

                for (int i = 0; i < pos - 1; i++) {
                    temp = temp->next;
                }

                newNode->next = temp->next; 
                temp->next = newNode; 
                this->count++;
            }
        }

        void display() {
            Node *temp = this->head;

            cout << "\n-----------------------------------\n";
            while(temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
            cout << "-----------------------------------\n";
        }

        void updateAtAnyPosition(int data, int pos = 1) {
            Node *temp = this->head;

            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            }

            temp->data = data;
            cout << "\n-----------------------------------\n";
            cout << "Node Updated Successfully..." << endl;
            cout << "-----------------------------------\n\n";
        }

        void deleteAtStart() {
            Node *temp = this->head;

            if(this->count > 0) {
                this->head = this->head->next;
                this->count--;
                
                delete temp;
                temp = nullptr;
            } else {
                cout << "\n-----------------------------------\n";
                cout << "Linked List is Empty...." << endl;
                cout << "-----------------------------------\n\n";
            }
        }

        void deleteAtEnd() {
            if(this->head->next == nullptr) {
                delete this->head;
                this->head = nullptr;
                this->count--;
                return;
            }

            if(this->count > 0) {
                Node *temp = this->head;

                while (temp->next->next != NULL) {
                    temp = temp->next;
                }
                
                
                delete temp->next;
                temp->next = nullptr;
                temp = nullptr;
                this->count--;

                cout << "\n-----------------------------------\n";
                cout << "Last Node Deleted Succesfully...." << endl;
                cout << "-----------------------------------\n\n";
            } else {
                cout << "\n-----------------------------------\n";
                cout << "Linked List is Empty...." << endl;
                cout << "-----------------------------------\n\n";
            }
        }

        void deleteAtAnyPosition(int pos) {
            if (pos == 0) {
                deleteAtStart();
                return;
            }

            if (pos >= count || pos < 0) {
                cout << "\n-----------------------------------\n";
                cout << "Invalid Position!" << endl;
                cout << "-----------------------------------\n\n";
                return;
            }

            Node *temp = this->head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }

            Node *nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;

            delete nodeToDelete;
            this->count--;

            cout << "\n-----------------------------------\n";
            cout << "Node Deleted Successfully..." << endl;
            cout << "-----------------------------------\n\n";
        }

        void revercelinkedlist() {
        Node* prev = NULL;
        Node* current = this->head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next; 
            current->next = prev; 
            prev = current;       
            current = next;       
        }

        this->head = prev;

        cout << "\n-----------------------------------\n";
        cout << "Linked List Reversed Successfully..." << endl;
       cout << "-----------------------------------\n\n";

    }

        void searchValue() {
        if (this->head == NULL) {
            cout << "\n-----------------------------------\n";
            cout << "Linked List is Empty...." << endl;
            cout << "-----------------------------------\n\n";
            return;
        }

        int value;
        cout << "Enter value to search in Linked List: ";
        cin >> value;

        Node* current = this->head;
        int count = 0;
        bool flag = false;

        while (current != NULL) {
            if (current->data == value) {
                flag = true;
                break;
            }
            current = current->next;
            count++;
        }

        if (flag) {
            cout << "\n-----------------------------------\n";
            cout << "Value " << value << " found at Position (Index Wise): " << count << endl;
            cout << "-----------------------------------\n\n";
        } else {
            cout << "\n-----------------------------------\n";
            cout << "Value " << value << " Not Found in Linked List." << endl;
            cout << "-----------------------------------\n\n";
        }
    }
};

int main() {
    LinkedList list;
    int choice;

    do {
        cout << "Enter 1 to insert node at Begining of the list...." << endl;
        cout << "Enter 2 to insert node at Ending of the list...." << endl;
        cout << "Enter 3 to insert node at Any Position of the list...." << endl;
        cout << "Enter 4 to View Linked List...." << endl;
        cout << "Enter 5 to Update any node of Linked List...." << endl;
        cout << "Enter 6 to Delete node from Start of Linked List...." << endl;
        cout << "Enter 7 to Delete node from End of Linked List...." << endl;
        cout << "Enter 8 to Delete node from Any position of Linked List...." << endl;
        cout << "Enter 9 to Reverced Linked List...." << endl;
        cout << "Enter 10 to Search value in Linked List...." << endl;
        cout << "Enter 0 to exit Linked List...." << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int val;

                cout << "Enter any value to insert : ";
                cin >> val;

                list.addAtStart(val);
                break;
            }
            case 2: {
                int val;

                cout << "Enter any value to insert : ";
                cin >> val;

                list.addAtEnd(val);
                break;
            }
            case 3: {
                int val, pos;

                cout << "Enter any value to insert : ";
                cin >> val;

                cout << "Enter the position (Index Wise) : ";
                cin >> pos;

                list.addAtAnyPosition(val, pos);
                break;
            }
            case 4: {
                list.display();
                break;
            }
            case 5: {
                int data, pos;
                
                cout << "Enter the position (Index Wise) to update the node : ";
                cin >> pos;

                cout << "Enter any value to update the node : ";
                cin >> data;

                list.updateAtAnyPosition(data, pos);
                break;
            }
            case 6: {
                list.deleteAtStart();
                break;
            }
            case 7: {
                list.deleteAtEnd();
                break;
            }
            case 8: {
                int pos;
                cout << "Enter the position (Index Wise) to delete the node : ";
                cin >> pos;
                list.deleteAtAnyPosition(pos);
                break;
            }
            case 9: {
                list.revercelinkedlist();
                break;
            }
            case 10:{
                list.searchValue();
                break;
            }
            case 0:{
                cout << "\n-----------------------------------" << endl;
                cout << "Thank you for using Linkedlist....." << endl;
                cout << "-----------------------------------\n\n" << endl;
                break;
            } 
            default : {
                 cout << "\n-----------------------------------" << endl;
                cout << "Invalide choice !" << endl;
                cout << "-----------------------------------\n\n" << endl;
                break;
            }
        }
    } while (choice != 0);

    return 0;
}