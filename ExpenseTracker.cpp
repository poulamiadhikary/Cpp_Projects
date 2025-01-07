#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Expense{
private:
    double expense;
    string expenseDescription;
    string expenseDate;

public:
    Expense(double exp, string expInfo, string expDate){
        expense = exp;
        expenseDescription = expInfo;
        expenseDate = expDate;
    }

    string getExpInfo(){
        return expenseDescription;
    }

    void viewExp(){
        cout<<"Expense Amount: "<<expense<<endl;
        cout<<"Expense Description: "<<expenseDescription<<endl;
        cout<<"Expense Date: "<<expenseDate<<endl;
        cout<<"--------------------------------------------------------";
        cout<<endl;
    }

    double getExpAmount(){
        return expense;
    }

};

class ExpenseTracker{
private:
    vector<Expense> expList;

public:
    double totalExpense = 0;
    
    bool isValidDate(string dat) {
    
        for(int i=0; i<dat.size(); i++){
            if(dat[2] != '/' && dat[5] != '/'){
                return false;
                break;
            }
            else if(dat.size() != 10){
                return false;
                break;
            }
        }

        return true;
    }

    void addExpense(){
        double amount;
        string expInfo, date;

        cout<<"Enter expense amount: ";
        cin>>amount;
        if(amount<=0){
            cout<<"INVALID AMOUNT! TRY AGAIN";
            addExpense();
            return;
        }
        cout<<"Enter expense description: ";
        cin.ignore();
        getline(cin, expInfo);

        cout<<"Enter expense date (DD/MM/YYYY): ";
        getline(cin, date);
        
        if(isValidDate(date)){
            expList.push_back(Expense(amount, expInfo, date));
            cout<<"EXPENSE ADDED SUCCESSFULLY !"<<endl;
            totalExpense+=amount;
        }
        else{
            cout<<"INVALID DATE ! TRY AGAIN"<<endl;
            addExpense();
        }
        
    }

    void deleteExpense(){
        string info;

        cout<<"Enter the expense you want to delete: ";
        cin.ignore();
        getline(cin, info);

        double amount;

        for(int i=0; i<expList.size(); i++){
            if(expList[i].getExpInfo() == info){
                expList[i].getExpAmount();
                expList.erase(expList.begin()+i);
                totalExpense-=amount;
                cout<<"EXPENSE DELETED SUCCESSFULLY !"<<endl;
                break;
            }
            else{
                cout<<"NO EXPENSE FOUND"<<endl;
            }
        }
    }

    void viewAllExpenses(){
        for(int i=0; i<expList.size(); i++){
            expList[i].viewExp();
        }
    }

    void showTotalExpense(){
        cout<<"Your total expense amount is: "<<totalExpense<<endl;
    }

    void splitExpense(){
        int n;
        cout<<"Enter the number of person you want to split in between: ";
        cin>>n;
        if(n==1){
        cout<<"MINIMUM PERSON FOR SPLITTING EXPENSE IS 2 ! TRY AGAIN"<<endl;
        splitExpense();
        return;
        }
        else if(n<1){
        cout<<"INVALID INPUT ! TRY AGAIN"<<endl;
        splitExpense();
        return;
        }
        else{
            int split = totalExpense/=n;
            cout<<"Each person will have to pay: "<<split<<endl;
        }
    }
};

int main(){

    ExpenseTracker track;
    int choice;

    do{
        cout<<"1.ADD EXPENSE    2.DELETE EXPENSE    3.VIEW ALL EXPENSES     4.TOTAL EXPENSE AMOUNT      5.SPLIT EXPENSE     6.EXIT"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl;

        switch(choice){
            case 1:
            track.addExpense();
            break;

            case 2:
            track.deleteExpense();
            break;

            case 3:
            track.viewAllExpenses();
            break;

            case 4:
            track.showTotalExpense();
            break;

            case 5:
            track.splitExpense();
            break;

            default:
            cout<<"INVALID CHOICE";
        }
    }
    while(choice!=6);
}