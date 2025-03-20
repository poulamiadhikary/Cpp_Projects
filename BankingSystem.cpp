#include<iostream>
#include<vector>
using namespace std;

class BankAccount{
private:
    int account_number;
    string name;
    double balance;

public:
    BankAccount(int account_number, string name, double balance){
        this->account_number = account_number;
        this->name = name;
        this->balance = balance;
    }
    
    // displays account info
    void displayAccountInfo() const {
        cout<<"Account Holder's Name: "<<name<<endl;
        cout<<"Account Number: "<<account_number<<endl;
        cout<<"Balance: ₹"<<balance<<endl;
        cout<<"-----------------------------------------"<<endl;
    }


    int getAccountNumber() const {
        return account_number;
    }

    double getBalance(){
        return balance;
    }

    void debit(double amount){
        balance-=amount;
    }

     void credit(double amount){
        balance+=amount;
    }
};

class BankingSystem{
    private:
    vector<BankAccount> accounts;

    public:
    
    double balance = 0;

    // function to add new bank account
    void addAccount(){

        string name;
        int acc_num;
        double balance = 0;
        bool accountExists = false;

        cout<<"Enter account holders name: ";
        cin.ignore();
        getline(cin, name);
        cout<<"Enter account number: ";
        cin>>acc_num;

        for(int i=0; i<accounts.size(); i++){
            if(accounts[i].getAccountNumber() == acc_num){
                accountExists = true;
                cout<<"ACCOUNT WITH SAME ACCOUNT NUMBER EXISTS ! TRY AGAIN"<<endl;
                break;
            }
        }

        if(!accountExists){
            accounts.push_back(BankAccount(acc_num, name, balance));
            cout<<"ACCOUNT CREATED SUCCESSFULLY !"<<endl;
        }  
    }

    // function to display all accounts
    void displayAccounts(){
        for(int i = 0; i<accounts.size(); i++){
            accounts[i].displayAccountInfo();
        }
    }

    void accountInfo(){
        
        int acc_num;
        bool accountExists = false;

        cout<<"Enter account number: ";
        cin>>acc_num;
        
        for(int i=0; i<accounts.size(); i++){
            if(accounts[i].getAccountNumber() == acc_num){
                accountExists = true;
                accounts[i].displayAccountInfo();
            }
        }

        if(!accountExists){
            cout<<"ACCOUNT NOT FOUND !";
        }
    }

    void accountBalance(){
        
        int acc_num;
        bool accountFound = false;

        cout<<"Enter account number: ";
        cin>>acc_num;
        
        for(int i=0; i<accounts.size(); i++){
            if(accounts[i].getAccountNumber() == acc_num){
                accountFound = true;
                cout<<"Total Balance: "<<accounts[i].getBalance()<<endl;
                return;
            }
        }

        if(!accountFound){
            cout<<"ACCOUNT NOT FOUND !";
        }
    }

    // function to deposit money
    void deposit(){

        int acc_num;
        double amount;
        bool accountFound = false;

        cout<<"Enter account number: ";
        cin>>acc_num;
        cout<<"Enter amount to deposit: ";
        cin>>amount;
        
        for(int i=0; i<accounts.size(); i++){
            if(accounts[i].getAccountNumber() == acc_num){
                accountFound = true;
                if(amount<=0){
                    cout<<"INVALID DEPOSIT ACCOUNT !"<<endl;
                }
                accounts[i].credit(amount);
                cout<<"YOUR ACCOUNT CREDITED WITH: ₹"<<amount<<endl;;
            }
        } 

        if(!accountFound) {
            cout<<"ACCOUNT NOT FOUND!"<<endl; 
        }
    }

    // function to withdraw money
    void withdraw(){

        int acc_num;
        double amount;
        bool accountFound = false;
        cout<<"Enter account number: ";
        cin>>acc_num;
        cout<<"Enter amount to withdraw: ";
        cin>>amount;
      
        for(int i=0; i<accounts.size(); i++){
            if(accounts[i].getAccountNumber() == acc_num){
                accountFound = true;
                if(accounts[i].getBalance()>=amount){
                    accounts[i].debit(amount);
                    cout<<"YOUR ACCOUNT WAS DEBITED WITH ₹"<<amount<<endl;
                    return;
                }
                else if(amount<=0){
                    cout<<"INVALID AMOUNT !";
                    return;
                }
                    
                cout<<"INSUFFICIENT BALANCE! TRANSACTION FAILED"<<endl;
                
            }
        }

        if(!accountFound) {
            cout<<"ACCOUNT NOT FOUND !"<<endl; 
        }
    }
};

int main(){

    BankingSystem bank;
    int choice;
    
    do{
    cout<<"1. ADD ACCOUNT   2. DISPLAY ACCOUNT INFO    3. WITHDRAW   4. DEPOSIT     5. DISPLAY BALANCE     6. EXIT"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    
    switch(choice){

        case 1:
        bank.addAccount();
        break;
        
        case 2:
        bank.accountInfo();
        break;
        
        case 3:
        bank.withdraw();
        break;

        case 4:
        bank.deposit();
        break;
        
        case 5:
        bank.accountBalance();
        break;

        default:
        cout<<"INVALID CHOICE !"<<endl;

    }
    }
    while(choice!=6);

}
