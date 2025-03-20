#include<iostream>
#include<vector>
#include<fstream>
#include<limits>
using namespace std;

class Task{
public:
    string taskName, taskDueDate, taskPriority;
    bool progress;

    Task(string name, string dueDate, string priority, bool progress){
        taskName = name;
        taskDueDate = dueDate;
        taskPriority = priority;
        this->progress = progress;
    }
    
    void viewTasks(){
        cout<<"Task: "<<taskName<<endl;
        cout<<"Due on: "<<taskDueDate<<endl;
        cout<<"Task priority: "<<taskPriority<<endl;
        if(progress == true){
            cout<<"TASK COMPLETED !"<<endl;
        }
        else{
            cout<<"TASK PENDING...!"<<endl;
        }
        cout<<"----------------------------------------------------------------------"<<endl;
    }
    
    string getTaskName(){
        return taskName;
    }

    string getTaskPriority(){
        return taskPriority;
    }

    string getTaskDuedate(){
        return taskDueDate;
    }

    bool getProgress(){
        return progress;
    }

    void setName(string s){
        taskName = s;
    }

    void setDuedate(string d){
        taskDueDate = d;
    }

    void setPriority(string p){
        taskPriority = p;
    }

    void setProgress(bool p){
        progress = p;
    }

};

class User{
private:
    string username, password;

public:
    
    User(string name, string pass){
        username = name;
        password = pass;
    }

    string getUsername(){
        return username;
    }
};

class TodoList{
private:
    vector<Task> tasks;
public:

    void addTask(){
        string name, dueDate, priority;
        bool progress;

        cout<<"Enter task name: ";
        cin.ignore();
        getline(cin, name);
        cout<<"Enter task due date (DD/MM/YYYY): ";
        getline(cin, dueDate);
        cout<<"Enter task priority (high | medium | low): ";
        cin>>priority;
        cout<<"Enter task progress ( 0 -> incomplete | 1 -> complete): ";
        cin>>progress;
        cout<<"TASK ADDED SUCCESSFULLY !"<<endl;

        Task newTask(name, dueDate, priority, progress);
        tasks.push_back(newTask);
    }

    void viewPendingTasks(){
        bool pendingTask = false;

        for(int i=0; i<tasks.size(); i++){
            if(tasks[i].getProgress() == false){
                tasks[i].viewTasks();
                pendingTask = true;
            }
        }
        
        if(!pendingTask){
            cout<<"NO PENDING TASKS !"<<endl;
        }
    }

    void viewCompletedTasks(){
        bool completedTask = false;

        for(int i=0; i<tasks.size(); i++){
            if(tasks[i].getProgress() == true){
                tasks[i].viewTasks();
                completedTask = true;
            }
        }
        
        if(!completedTask){
            cout<<"NO COMPLETED TASKS !"<<endl;
        }
    }

    void updateTask(){
        bool taskFound = false;
        string name, dueDate, priority;
        bool progress;
        int choice;
        char nestedChoice;

        cout<<"Search task by name to update: ";
        cin.ignore();
        getline(cin, name);

        for(int i=0; i<tasks.size(); i++){
            if(tasks[i].getTaskName() == name){
                taskFound = true;
                do{
                    cout<<"1.UPDATE TASK NAME   2.UPDATE DUE DATE   3.UPDATE PRIORITY   4.UPDATE PROGRESS   5.EXIT"<<endl;
                    cout<<"Enter your choice: ";
                    cin>>choice;

                    switch(choice){
                        case 1:
                        cout<<"Enter new name for task: ";
                        cin.ignore();
                        getline(cin, name);
                        tasks[i].setName(name);
                        cout<<"TASK NAME UPDATED SUCCESSFULLY !"<<endl;
                        cout<<"Do you want to update anything else (y - yes | n - no): ";
                        cin>>nestedChoice;

                        if(nestedChoice == 'y' || nestedChoice == 'Y'){
                            return;
                        }
                        else{
                            break;
                        }

                        case 2:
                        cout<<"Enter new due date for task: ";
                        cin.ignore();
                        getline(cin, dueDate);
                        tasks[i].setDuedate(dueDate);
                        cout<<"TASK DUE DATE UPDATED SUCCESSFULLY !"<<endl;
                        cout<<"Do you want to update anything else (y - yes | n - no): ";
                        cin>>nestedChoice;

                        if(nestedChoice == 'y' || nestedChoice == 'Y'){
                            return;
                        }
                        else{
                            break;
                        }

                        case 3:
                        cout<<"Enter new priority for task: ";
                        cin.ignore();
                        getline(cin, priority);
                        tasks[i].setPriority(priority);
                        cout<<"TASK PRIORITY UPDATED SUCCESSFULLY !"<<endl;
                        cout<<"Do you want to update anything else (y - yes | n - no): ";
                        cin>>nestedChoice;

                        if(nestedChoice == 'y' || nestedChoice == 'Y'){
                            return;
                        }
                        else{
                            break;
                        }

                        case 4:
                        cout<<"Enter new progress for task: ";
                        cin>>progress;
                        tasks[i].setProgress(progress);
                        cout<<"TASK PROGRESS UPDATED SUCCESSFULLY !"<<endl;
                        cout<<"Do you want to update anything else (y - yes | n - no): ";
                        cin>>nestedChoice;

                        if(nestedChoice == 'y' || nestedChoice == 'Y'){
                            return;
                        }
                        else{
                            break;
                        }

                        case 5:
                        cout<<"EXITING FROM UPDATE MENU"<<endl;
                        break;

                        default:
                        cout<<"INVALID CHOICE"<<endl;
                    }
                }
                while(choice!=5);
            }
        }
        
    }

    void deleteTask(){
        string name;
        bool taskFound = false;

        cout<<"Enter task name to delete: ";
        cin.ignore();
        getline(cin, name);

        for(int i=0; i<tasks.size(); i++){
            if(tasks[i].getTaskName() == name){
                taskFound = true;
                tasks.erase(tasks.begin() + i);
                cout<<"TASK DELETED SUCCESSFULLY !"<<endl;
            }
        }

        if(!taskFound){
            cout<<"NO TASK FOUND !"<<endl;
        }
    }

    void filterTasks(){
        string dueDate, priority;
        int choice;

        do{
            cout<<"1.FILTER BY DUE DATE     2.FILTER BY PRIORITY       3.EXIT"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;

            switch(choice){
                case 1:{
                bool dateFound = false;
                cout<<"Enter due date: ";
                getline(cin, dueDate);

                for(int i=0; i<tasks.size(); i++){
                    if(tasks[i].getTaskDuedate() == dueDate){
                        tasks[i].viewTasks();
                        dateFound = true;
                    }
                }
                if(!dateFound){
                    cout<<"NO TASK FOUND WITH DUE DATE ! TRY AGAIN"<<dueDate<<endl;
                    return;
                }
                break;
                }

                case 2:{
                bool priorityFound = false;
                cout<<"Enter priority (high | medium | low): ";
                getline(cin, priority);

                for(int i=0; i<tasks.size(); i++){
                    if(tasks[i].getTaskPriority() == priority){
                        tasks[i].viewTasks();
                        priorityFound = true;
                    }
                }

                if(!priorityFound){
                    cout<<"NO TASK FOUND WITH PRIORITY ! TRY AGAIN"<<priority<<endl;
                    return;
                }
                break;
                }

                case 3:
                cout<<"EXITING..."<<endl;
                break;

                default:
                cout<<"INVALID CHOICE !"<<endl;
            }
        }
        while(choice!=3);
    }

};

int main(){

    string name, password;
    int choice;

    User newUser("sudipto", "github24");
    TodoList newList;

    cout<<"Enter your name: ";
    getline(cin, name);
    cout<<"Enter password: ";
    cin>>password;

    if(name == "sudipto" && password == "github24"){
        cout<<"WELCOME "<<name<<endl;
        do{
            cout<<"1.ADD TASK     2.DELETE TASK    3.UPDATE TASK    4.VIEW PENDING TASK     5.VIEW COMPLETED TASK      6.FILTER TASK    7.EXIT"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;

            switch(choice){
                case 1:
                newList.addTask();
                break;

                case 2:
                newList.deleteTask();
                break;

                case 3:
                newList.updateTask();
                break;

                case 4:
                newList.viewPendingTasks();
                break;

                case 5:
                newList.viewCompletedTasks();
                break;

                case 6:
                newList.filterTasks();
                break;

                case 7:
                cout<<"EXITING FROM SYSTEM"<<endl;
                break;

                default:
                cout<<"INVALID CHOICE !"<<endl;
            }
        }
        while(choice!=7);
    }
    else{
        cout<<"INVALID CREDENTIALS ! TRY AGAIN"<<endl;
    }
}