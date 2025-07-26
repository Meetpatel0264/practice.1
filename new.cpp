#include <iostream>
#include <vector>

using namespace std;

class GroceryProduct{
    protected:
        string productName;
        int price, productID;
    public:
        GroceryProduct(int productID, string productName, int price){
            this->productID = productID;
            this->productName = productName;
            this->price = price;
        }
        void viewProcutDetails(){
            cout << "----------------------------------------------------\n";
            cout << "Product ID : " << this->productID << endl;
            cout << "Product Name : " << this->productName << endl;
            cout << "Product Price : " << this-> price << endl;
            cout << "----------------------------------------------------\n\n";
        }
        int getProductId(){
            return this->productID; 
        }
        void updateProduct(string newProductName, int newPrice){
            this->productName = newProductName;
            this->price = newPrice;

            cout << "----------------------------------------------------\n";
            cout << "Product : " << productName <<  " has been Updated." << endl;
            cout << "----------------------------------------------------\n\n";
        }
};

int main(){

    vector<GroceryProduct> p1;

    int choice;

    do {
        cout << "\n----------------------------------------------------\n";
        cout << "Press 1. For Add a Product" << endl;
        cout << "Press 2. For Display all Prodcuts" << endl;
        cout << "Press 3. For Remove a Product" << endl;
        cout << "Press 4. For Update a Product" << endl;
        cout << "Press 5. For Exit This Program" << endl;
        cout << "----------------------------------------------------\n\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice){

            case 1:{
                int productID, price;
                string productName;

                cout << "Enter the ProductID : ";
                cin >> productID;

                cin.ignore();

                cout << "Enter the Product Name : ";
                getline(cin, productName);

                cout << "Enter the Product Price : ";
                cin >> price;

                GroceryProduct newProduct(productID, productName, price);
                p1.push_back(newProduct);

                cout << "----------------------------------------------------\n";
                cout << "Product " << productName << " Added to Grocery." << endl;
                cout << "----------------------------------------------------\n\n";
                
                break;
            }
            
            case 2:{
                if (p1.empty()){

                    cout << "----------------------------------------------------\n";
                    cout << "Product Is Not Available" << endl;
                    cout << "----------------------------------------------------\n\n";

                    break;
                }

                 for (int i = 0; i < p1.size(); i++) {
                    p1[i].viewProcutDetails();
                }

                break;
            }
            
            case 3:{
                int productID;
                bool flag = true;

                cout << "Enter the ProductID: ";
                cin >> productID;


                for(int i = 0; i < p1.size(); i++){
                    if(p1[i].getProductId() == productID){
                        p1.erase(p1.begin() + i);

                        cout << "----------------------------------------------------\n";
                        cout << "Product Removed Successfully." << endl;
                        cout << "----------------------------------------------------\n\n";
                        
                        flag = false;
                    }
                }

                if(flag){

                    cout << "----------------------------------------------------\n";
                    cout << "Product Is Not Available" << endl;
                    cout << "----------------------------------------------------\n\n";
                }

                break;
            }

            case 4:{

                int productID;
                cout << "Enter the productID: ";
                cin >> productID;

                bool flag = true;

                for(int i = 0; i < p1.size(); i++){
                    if(p1[i].getProductId() == productID){
                        string newProductName;
                        int newPrice;

                        cin.ignore();

                        cout << "Enter the New Product name: ";
                        getline(cin, newProductName);

                        cout << "Enter the New Product price: ";
                        cin >> newPrice;

                        p1[i].updateProduct(newProductName, newPrice);
                        flag = false;
                    }
                }

                if(flag){
                    cout << "----------------------------------------------------\n";
                    cout << "Product Is Not Available" << endl;   
                    cout << "----------------------------------------------------\n\n";             
                }
                
                break;
                
            }
            case 5:{
                cout << "----------------------------------------------------\n";
                cout << "Thank You For Using This Program" << endl;
                cout << "....................Visit Again" << endl;
                cout << "\n----------------------------------------------------\n\n";
                break;
            }
            default:{
                cout << "----------------------------------------------------\n";
                cout << "Invalid Choice..." << endl;
                cout << "----------------------------------------------------\n\n";           
            }
        }

    } while (choice != 5);

    return 0;
}
