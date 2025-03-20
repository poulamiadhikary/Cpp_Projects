#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Student{
public:
    string name, course, rollNo;

    Student(string name, string course, string rollNo){
        this->name = name;
        this->course = course;
        this->rollNo = rollNo;
    }

    string getStudentRollNo(){
        return rollNo;
    }

    string getStudentName(){
        return name;
    }

    string getStudentCourse(){
        return course;
    }

    void setName(string name){
        this->name = name;
    }

    void setCourse(string course){
        this->course = course;
    }

    void setRollNo(string rollNo){
        this->rollNo = rollNo;
    }

    void getStudentInfo(){
        cout<<"Student name: "<<name<<endl;
        cout<<"Student course: "<<course<<endl;
        cout<<"Student roll no: "<<rollNo<<endl;
        cout<<"----------------------------------------------"<<endl;

    }

};

class StudentInformationSystem{
private:
    vector<Student> studentList;

public:
    
    void addStudentToFile(Student student){
        ofstream file("students.txt");

        if(file.is_open()){
            file<<student.getStudentName()<<" , "<<student.getStudentCourse()<<" , "<<student.getStudentRollNo()<<endl;
            file.close();
        }
        else{
            cout<<"UNABLE TO ADD STUDENT TO FILE !"<<endl;
        }
        
    }

    void updateStudentFromFile(){
        ofstream file("student.txt");
        
        for(int i=0; i<studentList.size(); i++){
            if(file.is_open()){
                file<<studentList[i].getStudentName()<<" , "<<studentList[i].getStudentCourse()<<" , "<<studentList[i].getStudentRollNo()<<endl;
            }
        }
        
    }

    void addStudent(){
        string name, course, rollNo;
        bool studentFound = false;
        cout<<"Enter students name: ";
        cin.ignore();
        getline(cin, name);
        cout<<"Enter student course (INITIALS ONLY): ";
        cin>>course;
        cout<<"Enter 10-digit student roll no: ";
        cin>>rollNo;
        if(rollNo.size()!=10){
            cout<<"INVALID ROLL NO ! TRY AGAIN"<<endl;
            return;
        }

        for(int i=0; i<studentList.size(); i++){
            if(studentList[i].getStudentRollNo() == rollNo){
                studentFound = true;
                cout<<"STUDENT WITH SAME ROLL NO ALREADY EXIST ! TRY AGAIN"<<endl;
                return;
            }
        }

        if(!studentFound){
            Student newStudent(name, course, rollNo);
            studentList.push_back(newStudent);
            addStudentToFile(newStudent);
            cout<<"STUDENT SUCCESSFULLY ADDED !"<<endl;
        }
    }

    void deleteStudent(){
        string rollNo;
        bool studentFound = false;

        cout<<"Enter 10-digit student roll no: ";
        cin>>rollNo;
        if(rollNo.size()!=10){
            cout<<"INVALID ROLL NO ! TRY AGAIN"<<endl;
            return;
        }

        for(int i=0; i<studentList.size(); i++){
            if(studentList[i].getStudentRollNo() == rollNo){
                studentFound = true;
                studentList.erase(studentList.begin() + i);
                updateStudentFromFile();
                cout<<"STUDENT DELETED SUCCESSFULLY !"<<endl;
                return;
            }
        }

        if(!studentFound){
            cout<<"STUDENT NOT FOUND ! TRY AGAIN"<<endl;
            return;
        }
    }

    void updateStudent(){
        string name, course, rollNo;
        bool studentFound = false;
        int choice;
        
        cout<<"Enter 10-digit student roll no:";
        cin>>rollNo;
        if(rollNo.size()!=10){
            cout<<"INVALID ROLL NO ! TRY AGAIN"<<endl;
            return;
        }

        for(int i=0; i<studentList.size(); i++){
            if(studentList[i].getStudentRollNo() == rollNo){
                studentFound = true;
                cout<<"1.UPDATE NAME    2.UPDATE COURSE     3.UPDATE ROLL NO"<<endl;
                cout<<"Enter your choice: ";
                cin>>choice;
                cin.ignore();

                switch(choice){
                    case 1:
                    cout<<"Enter new name: ";
                    getline(cin, name);
                    studentList[i].setName(name);
                    updateStudentFromFile();
                    cout<<"STUDENT NAME UPDATED !"<<endl;
                    break;

                    case 2:
                    cout<<"Enter new course: ";
                    cin>>course;
                    studentList[i].setCourse(course);
                    updateStudentFromFile();
                    cout<<"STUDENT COURSE UPDATED !"<<endl;
                    break;

                    case 3:
                    cout<<"Enter new 10-digit roll no: ";
                    cin>>rollNo;
                    if(rollNo.size()!=10){
                        cout<<"INVALID ROLL NO ! TRY AGAIN"<<endl;
                        return;
                    }
                    else{
                        studentList[i].setRollNo(rollNo);
                        updateStudentFromFile();
                        cout<<"STUDENT COURSE UPDATED !"<<endl;
                    }
                    break;

                    default:
                    cout<<"INVALID CHOICE !"<<endl;
                }

                return;
               
            }
        }
        
        cout<<"STUDENT NOT FOUND ! TRY AGAIN"<<endl;
    
    } 

    void searchStudent(){
        string rollNo;
        bool studentFound = false;

        cout<<"Enter roll no: ";
        cin>>rollNo;
        if(rollNo.size()!=10){
            cout<<"INVALID ROLL NO ! TRY AGAIN"<<endl;
            return;
        }

        for(int i=0; i<studentList.size(); i++){
            if(studentList[i].getStudentRollNo() == rollNo){
                studentFound = true;
                studentList[i].getStudentInfo();
            }
        }

        if(!studentFound){
            cout<<"STUDENT NOT FOUND ! TRY AGAIN"<<endl;
            return;
        }
    }
};

int main(){

    StudentInformationSystem student;
    int choice;

    do{
        cout<<"1.ADD STUDENT    2.DELETE STUDENT    3.SEARCH STUDENT    4.UPDATE STUDENT    5.EXIT"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
            student.addStudent();
            break;

            case 2: 
            student.deleteStudent();
            break;

            case 3:
            student.searchStudent();
            break;

            case 4:
            student.updateStudent();
            break;
        }
    }
    while(choice!=5);
    
}