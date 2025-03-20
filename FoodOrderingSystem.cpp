#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

// User class ______________________________________________________________________________
class User{
private:
    string name, password, address, phNo;

public:
    User(string name, string password, string address, string phNo){
        this->name = name;
        this->password = password;
        this->address = address;
        this->phNo = phNo;
    }
};

// Menu class ______________________________________________________________________________
class Menu{
public:
    string itemName, id;
    double price;

    Menu(string name, string id, double price){
        itemName = name;
        this->id = id;
        this->price = price;
    }

    string getMenuId(){
        return id;
    }

    double getPrice(){
        return price;
    }

    string getMenuName(){
        return itemName;
    }

    void setMenuId(string s){
        id = s;
    }

    void setMenuName(string n){
        itemName = n;
    }

    void setPrice(double p){
        price = p;
    }

    void menuInfo(){
        cout<<endl;
        cout<<"Item name: "<<itemName<<endl;
        cout<<"Item price: "<<price<<endl;
        cout<<"Item id: "<<id<<endl;
        cout<<"---------------------------------------------------"<<endl;
    }
};

// Order class ______________________________________________________________________________
class Order{
public:

    string itemName, userName;
    Order(string itemName, string UserName){
        this->itemName = itemName;
        this->userName = userName;
    }

    void orderInfo(){
        cout<<"Order "<<itemName<<" placed by "<<userName<<endl;
    }

    string getOrderUsername(){
        return userName;
    }
};

// Admin class ______________________________________________________________________________
class Admin{
private:
    string username, password;

public:
    vector<Order> receivedOrder;
    vector<Menu> menuList;

    Admin(string username, string password){
        this->username = username;
        this->password = password;
    }
    
    void addMenuToFile(Menu menu){
        ofstream file("menuList.txt", ios::app);
        if(file.is_open()){
            file<<menu.itemName<<","<<menu.id<<","<<menu.price<<endl;
            file.close();
        } 
        else{
            cout<<"Unable to open file to write menu"<<endl;
        }
    }

    void updateMenuFile(){
    ofstream file("menuList.txt", ios::trunc);
    if(file.is_open()){
        for(int i=0; i<menuList.size(); i++){
            file<<menuList[i].getMenuName()<<","<<menuList[i].getMenuId()<<","<<menuList[i].getPrice()<<endl;
        }
        file.close();
    }
    else{
        cout<<"Unable to open file to update menu"<<endl;
    }
}

    void addMenuItem(){
        string itemName, id;
        double price;

        cout<<"Enter item name you want to add: ";
        cin.ignore();
        getline(cin, itemName);
        cout<<"Enter price: ";
        cin>>price;
        cout<<"Enter item id: ";
        cin>>id;

        for(int i=0; i<menuList.size();  i++){
            if(menuList[i].getMenuId() == id){
                cout<<"AN ITEM WITH SAME ID EXISTS ! TRY AGAIN"<<endl;
                return;
            }
        }
        Menu new_menu(itemName, id, price);
        menuList.push_back(new_menu);
        addMenuToFile(new_menu);
    }

    void updateMenuItem(){
        string name, id;
        double price;
        bool idFound = false;
        char choice;
        int c;

        cout<<"Enter the menu item id you want to update: ";
        cin>>id;

        for(int i=0; i<menuList.size(); i++){
            if(menuList[i].getMenuId()==id){
                idFound = true;
                cout<<"ID FOUND !"<<endl;
                
                do{
                cout<<"1.UPDATE ID      2.UPDATE ITEM NAME      3.UPDATE PRICE      4.EXIT"<<endl;
                cout<<"Enter your choice: ";
                cin>>c;

                switch(c){
                    case 1:
                    cout<<"Enter new id: ";
                    cin.ignore();
                    cin>>id;
                    menuList[i].setMenuId(id);
                    cout<<"MENU ID UPDATED SUCCESSFULLY !"<<endl;
                    break;
                    

                    case 2:
                    cout<<"Enter new name: ";
                    cin.ignore();
                    getline(cin, name);
                    menuList[i].setMenuName(name);
                    cout<<"MENU NAME UPDATED SUCCESSFULLY !"<<endl;
                    break;

                    case 3:
                    cout<<"Enter new price: ";
                    cin.ignore();
                    cin>>price;
                    menuList[i].setPrice(price);
                    cout<<"MENU PRICE UPDATED SUCCESSFULLY !"<<endl;
                    break;

                    case 4:
                    cout<<"EXITING !"<<endl;
                    break;

                    default:
                    cout<<"INVALID CHOICE !"<<endl;
                }

                if(c!=4){
                    cout<<"DO YOU WANT TO UPDATE ANYTHING ELSE ? ( y - yes | n - no): ";
                    cin>>choice;
                    if(choice == 'n' || choice == 'N'){
                        break;
                    }
                }
             }
             while(c!=4);

             updateMenuFile();
             return;
            }
        }
        
        if(!idFound){
            cout<<"ID NOT FOUND !"<<endl;
        }
    }

    void deleteMenuItem(){
        string id;
        bool itemFound = false;

        cout<<"Enter the item id you want to delete: ";
        cin.ignore();
        cin>>id;

        for(int i=0; i<menuList.size(); i++){
            if(menuList[i].getMenuId() == id){
                itemFound = true;
                cout<<"ITEM DELETED !"<<endl;
                menuList.erase(menuList.begin() + i);
                updateMenuFile();
                return;
            }
        }

        if(!itemFound){
            cout<<"ITEM NOT FOUND !"<<endl;
            return;
        }
    }


    void logOrder(Order order){
        ofstream pastOrdersFile("pastOrders.txt", ios::app);
        ofstream receivedOrdersFile("receivedOrders.txt", ios::app);

        if(pastOrdersFile.is_open() && receivedOrdersFile.is_open()){
            pastOrdersFile<<"User "<< order.getOrderUsername()<< "ordered -> "<<order.itemName<<endl;
            receivedOrdersFile<<"Order "<< order.itemName<<" placed by "<<order.getOrderUsername()<<endl;

            pastOrdersFile.close();
            receivedOrdersFile.close();
        } else {
            cout << "Unable to open order files" << endl;
        }
    }
};

// OrderingSystem class inherits from both Menu & Admin class ______________________________________________________________________________
class FoodOrderingSystem : public Admin{
public:

    FoodOrderingSystem(string adminName, string password) : Admin(adminName, password) {}
    string name;
    char choice;

    void searchFoodItem(){
        string name, phNo;
        string userName;
        bool foodFound = false;
        string newOrder;

        cout<<"Enter the item you want to search: ";
        cin.ignore();
        getline(cin, name);

        for(int i=0; i<menuList.size(); i++){
            if(menuList[i].getMenuName() == name){
                foodFound = true;
                menuList[i].menuInfo();
                cout<<"Do want to place order ( y - yes | n - no): ";
                cin>>choice;
                if(choice == 'y' || choice == 'Y'){
                    cout<<"Enter your name: ";
                    cin.ignore();
                    getline(cin, userName);
                    cout<<"Enter phone number: ";
                    cin>>phNo;
                    if(phNo.size()!=10){
                        cout<<"INVALID PHONE NUMBER ! TRY AGAIN"<<endl;
                        return;
                    }

                    Order newOrder(name, userName);
                    receivedOrder.push_back(newOrder);
                    logOrder(newOrder);
                    cout<<"ORDER PLACED SUCCESSFULLY ! "<<endl;
                }
            }
        }

        if(!foodFound){
            cout<<"ITEM NOT FOUND !"<<endl;
        }
    }

    void viewMenu(){

        if(menuList.size() == 0){
            cout<<"MENU IS  EMPTY !"<<endl;
            return;
        }

        for(int i=0; i<menuList.size(); i++){
            menuList[i].menuInfo();
            cout<<endl;

        }
    }

    void viewPastOrders(){
        ifstream pastOrdersFile("pastOrders.txt");
        string line;
        if(pastOrdersFile.is_open()){
            while(getline(pastOrdersFile, line)){
                cout<<line<<endl;
            }
            pastOrdersFile.close();
        }
        else{
            cout<<"Unable to open past orders file"<<endl;
        }
    }

    void viewReceivedOrders(){
        ifstream receivedOrdersFile("receivedOrders.txt");
        string line;
        if(receivedOrdersFile.is_open()){
            while(getline(receivedOrdersFile, line)){
                cout<<line<<endl;
            }
            receivedOrdersFile.close();
        }
        else{
            cout<<"Unable to open received orders file"<<endl;
        }
    }
};

int main(){

    FoodOrderingSystem system("sudipto", "github24");
    int mainChoice, adminChoice, userChoice;
    string name, password;

    do{
        cout<<"WELCOME TO FOOD ORDERING SYSTEM"<<endl;
        cout<<"---------------------------------------------------------------------------------"<<endl;
        cout<<"1.Admin      2.User      3.EXIT"<<endl;
        cout<<"Enter your choice: ";
        cin>>mainChoice;

        switch(mainChoice){
            case 1:
            cout<<"Enter your name: ";
            cin.ignore();
            getline(cin, name);
            cout<<"Enter password: ";
            cin>>password;

            if(name == "sudipto" && password =="github24"){
                cout<<"WELCOME SUDIPTO !"<<endl;
                do{
                    cout<<"1.ADD MENU ITEM      2.DELETE MENU ITEM      3.UPDATE MENU ITEM      4.VIEW REVEIVED ORDERS     5.LOGOUT"<<endl;
                    cout<<"Enter  your choice: ";
                    cin>>adminChoice;

                    switch(adminChoice){
                        case 1:
                        system.addMenuItem();
                        break;

                        case 2:
                        system.deleteMenuItem();
                        break;

                        case 3:
                        system.updateMenuItem();
                        break;

                        case 4:
                        system.viewReceivedOrders();
                        break;

                        case 5:
                        cout<<"LOGGING OUT"<<endl;
                        break;

                        default:
                        cout<<"INVALID CHOICE !";
                    }
                }
                while(adminChoice != 5);
            }
            else{
                cout<<"INVALID ADMIN CREDENTIALS !"<<endl;
            }
            break;

            case 2:
            do{
                cout<<"1.VIEW MENU     2.SEARCH FOOD     3.VIEW PAST ORDERS      4.LOGOUT"<<endl;
                cout<<"Enter your choice: ";
                cin>>userChoice;

                switch(userChoice){
                    case 1:
                    system.viewMenu();
                    break;

                    case 2:
                    system.searchFoodItem();
                    break;

                    case 3:
                    system.viewPastOrders();
                    break;

                    case 4:
                    cout<<"LOGGING OUT"<<endl;
                    break;

                    default:
                    cout<<"INVALID INPUT !"<<endl;
                }
            }
            while(userChoice != 4);
        }   
        
    }
    while(mainChoice !=3);

}