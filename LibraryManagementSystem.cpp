#include<iostream>
#include<vector>
using namespace std;

class Book{
public:
    string bookName;
    string bookAuthor;
    bool issued;

    Book(string name, string author, bool issue){
        bookName = name;
        bookAuthor = author;
        issued = issue;
    }
    
    bool setIssued(bool is){
        issued = is;
        return true;
    }
    void getBookInfo(){
        cout<<"Book Name: "<<bookName<<endl;
        cout<<"Author: "<<bookAuthor<<endl;
        if(issued){
            cout<<"BOOK HAS BEEN ISSUED !"<<endl;
        }
        else{
            cout<<"BOOK AVAILABLE !"<<endl;
        }
        cout<<"---------------------------------------------"<<endl;
    }

    string getBookName(){
        return bookName;
    }

    bool getIssue(){
        return issued;
    }
};

class User{
private:
    string userName;
    string password;

public:
    User(string name, string pass){
        userName = name;
        password = pass;
    }

    string getUserName(){
        return userName;
    }

    string getPassword(){ 
        return password;
    }

};

class LibrarySystem{
private:
    vector<Book>bookList;
    vector<User>userList;

public:

    void registerUser(){
        string nam, pswrd;

        cout<<"Enter username: ";
        cin.ignore();
        getline(cin, nam);

        cout<<"Enter password: ";
        cin>>pswrd;
        
        userList.push_back(User(nam, pswrd));
        cout<<"REGISTRATION SUCCESSFULL !"<<endl;
    }

    void loginUser(){
        string name, pass;
        bool userFound = false;

        cout<<"Enter your username: ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter your password: ";
        getline(cin,pass);

        for(int i=0; i<userList.size(); i++){
            if(userList[i].getUserName() == name && userList[i].getPassword() == pass){
                cout<<"WELCOME "<<name<<endl;
                userFound = true;
                break;
            }
        }

        if(!userFound){
                char ans;
                cout<<"YOU ARE NOT REGISTERED !"<<endl;
                cout<<"DO YOU WANT TO REGISTER YOURSELF NOW ? (Y - yes | N - no): ";
                cin>>ans;

                if(ans == 'y' || ans == 'Y'){
                    registerUser();
                }
            }
    }

    void addBooks(){
        string bname, auth;
        bool isIssued = false;

        cout<<"Enter book name: ";
        cin.ignore();
        getline(cin, bname);
        cout<<"Enter author name: ";
        getline(cin, auth);
        
        for(int i=0; i<bookList.size(); i++){
            if(bookList[i].getBookName() == bname){
                cout<<"BOOK ALREADY EXISTS !"<<endl;
                return;
            }
        }

        bookList.push_back(Book(bname, auth, isIssued));
        cout<<"BOOK ADDED SUCCESSFULLY !"<<endl;
        
    }

    void deleteBooks(){
        string bname;
        bool isIssued;

        cout<<"Enter book name to delete: ";
        cin.ignore();
        getline(cin, bname);

        for(int i=0; i<bookList.size(); i++){
            if(bookList[i].getBookName() == bname){
                if(bookList[i].getIssue() == true){
                    cout<<"BOOK IS IN ISSUE CANNOT DELETE BOOK !"<<endl;
                    return;
                }
                bookList.erase(bookList.begin() + i);
                cout<<"BOOK DELETED SUCCESSFULLY !"<<endl;
                return; 
            }
        }

        cout<<"BOOK NOT FOUND !"<<endl;
    }

    void viewAllBooks(){
        for(int i=0; i<bookList.size(); i++){
            bookList[i].getBookInfo();
        }
    }

    void searchBook(){
        string bk;

        cout<<"Enter book name: ";
        cin.ignore();
        getline(cin, bk);

        for(int i=0; i<bookList.size(); i++){
            if(bookList[i].getBookName() == bk){
                bookList[i].getBookInfo();
                cout<<endl;
                return;
            }
        }

        cout<<"BOOK NOT FOUND !"<<endl;
    }

    void viewIssuedBooks(){
        for(int i=0; i<bookList.size(); i++){
            if(bookList[i].getIssue() == true){
                bookList[i].getBookInfo();
                cout<<endl;
            }
        }
    }

    void issueBook(){
        string bk;
        int day;

        cout<<"Enter the book you want to issue: ";
        cin.ignore();
        getline(cin, bk);

        for(int i=0; i<bookList.size(); i++){
            if(bookList[i].getBookName() == bk){
                if(bookList[i].getIssue() == false){
                    cout<<"Enter time period in days: ";
                    cin>>day;
                    bookList[i].setIssued(true);
                    cout<<"ENJOY YOUR BOOK !"<<endl;
                    return;
                }
                else{
                    cout<<"BOOK IS ALREADY IN ISSUE !"<<endl;
                    return;
                }
                
            }
        }

        cout<<"BOOK NOT AVAILABLE !"<<endl;
    }

    void returnBook(){
        string bk;

        cout<<"Enter the book you want to return: ";
        cin.ignore();
        getline(cin, bk);
        
        for(int i=0; i<bookList.size(); i++){
            if(bookList[i].getBookName() == bk && bookList[i].getIssue() == true){
                cout<<"BOOK RETURN SUCCESSFULL !"<<endl;
                bookList[i].setIssued(false);
                return;
            }
        }

        cout<<"BOOK NOT FOUND OR NOT ISSUED !"<<endl;
    }
    
};

int main(){

    LibrarySystem library;

     int choice;
        
        do{
            cout<<"1.REGISTER   2.LOG IN"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;

            switch(choice){
                case 1:
                library.registerUser();
                break;

                case 2:
                library.loginUser();
                break;
            }
        }
        while(choice!=1 && choice !=2);  

        do{
            cout<<"1.ADD BOOK  2.DELETE BOOK   3.VIEW ALL BOOKS    4.SEARCH BOOK   5.VIEW ISSUED BOOKS    6.ISSUE BOOK   7.RETURN BOOK   8.LOGOUT"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;

            switch(choice){
                case 1:
                library.addBooks();
                break;

                case 2:
                library.deleteBooks();
                break;

                case 3:
                library.viewAllBooks();
                break;

                case 4:
                library.searchBook();
                break;

                case 5:
                library.viewIssuedBooks();
                break;

                case 6:
                library.issueBook();
                break;

                case 7:
                library.returnBook();
                break;

                case 8:
                cout<<"LOGGED OUT !"<<endl;
                break;

                default:
                cout<<"INVALID CHOICE !"<<endl;
            }
        }
        while(choice!=8);

}