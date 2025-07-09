#include<iostream>

using namespace std;

class Book {
    protected:
        int bookID;
        string name;
        string author;
        bool isIssued;
    public:
        Book(){
            this->bookID = 0;
            this->name = "";
            this->author = "";
            this->isIssued = false;
        }

        void addBook(int bookID, string name, string author) {
            this->bookID = bookID;
            this->name = name;
            this->author = author;
            this->isIssued = false;
        }

        void viewBookDetails() {
            cout << "\n---------------------------------------\n";
            cout << "BookID : " << this->bookID << endl;
            cout << "Name : " << this->name << endl;
            cout << "Author : " << this->author << endl;
            cout << "Availability : " << (this->isIssued == true ? "No" : "Yes") << endl;
            cout << "----------------------------------------\n\n";
        }

        int getBookId(){
            return this->bookID;
        }

        bool getIsIssued() {
            return this->isIssued;
        }
};

class IssuedBook : public Book {
    private:
        string issuedTo;
        string issueDate;
    public:
        void issueBook(string issuedTo, string issueDate) {
            this->issuedTo = issuedTo;
            this->issueDate = issueDate;
            this->isIssued = true;
            cout << "\n---------------------------------------\n";
            cout << "Book is issued to : " << issuedTo << " on Date : " << issueDate << endl;
            cout << "---------------------------------------\n\n";
        }
        void returnBook() {

        }
};

int main(){
    IssuedBook library[5];
    int choice, idx = 0;

    do {
        cout << "Enter 1 to Add A Book...." << endl;
        cout << "Enter 2 to View All Book...." << endl;
        cout << "Enter 3 to Issue A Book...." << endl;
        cout << "Enter 4 to Return A Book...." << endl;
        cout << "Enter 5 to Exit...." << endl;
        cout << "Enter your choice : ";     
        cin >> choice;

        switch(choice) {
            case 1: {
                int bookID;
                string name, author;

                cout << "Enter a book Id : ";
                cin >> bookID; // 1234

                cin.ignore();

                cout << "Enter the name of Book : ";
                getline(cin, name);

                cout << "Enter the name of Author : ";
                getline(cin, author);

                library[idx].addBook(bookID, name, author);
                idx++; // 2

                break;
            }
            case 2: {
                if(idx == 0){
                    cout << "No Book Available at a time...." << endl;
                    break;
                }

                for(int i = 0; i < idx; i++){
                    library[i].viewBookDetails();
                }
                cout << endl;
                break;
            }
            case 3: {
                int bookID;
                bool flag = false;

                cout << "Enter the id of book you want to issue : ";
                cin >> bookID;

                cin.ignore();

                for(int i = 0; i < idx; i++){
                    int id = library[i].getBookId();

                    if(id == bookID){
                        flag = true;
                        if(library[i].getIsIssued() == false){
                            string name, date;

                            cout << "Enter the name of borrower : ";
                            getline(cin, name);
                            
                            cout << "Enter the issue date : ";
                            getline(cin, date);
                            
                            library[i].issueBook(name, date);
                            break;
                        } else {
                            cout << "Its Already issued to someone else....." << endl;
                        }
                    }
                }

                if(flag == false){
                    cout << "It's Not Availble.....";
                }
                break;
            }
            case 4: {
                int bookID;
                bool flag = false;

                cout << "Enter the book ID to return: ";
                cin >> bookID;

                for (int i = 0; i < idx; i++) {
                    if (library[i].getBookId() == bookID) {
                        flag = true;
                        if (library[i].getIsIssued()) {
                            library[i].returnBook();
                        } else {
                            cout << "Book is not issued to anyone" << endl;
                        }
                        break;
                    } else {
                        cout << "Book is Not Issued To Anyone..." << endl;
                    }
                }
                break;
            }
            case 5: {
                cout << "Thank You Use For Libary.." << endl;
                break;
            }
            default:
                cout << "Invalid Choice...." << endl;
        }
    } while(choice != 5);


    return 0;
}
