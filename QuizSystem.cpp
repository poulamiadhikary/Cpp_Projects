#include<iostream>
#include<vector>
using namespace std;

class Question{ 
private:
    string questionText;
    vector<string>options;
    int correctOption;

public:

    Question(string text, vector<string> opts, int correct){
        questionText = text;
        options = opts;
        correctOption = correct;
    }

    void displayQuestion(){
        cout<<questionText<<endl;
        for(int i=0; i<options.size(); i++){
            cout<<i+1<<"."<<options[i]<<" ";
            cout<<endl;
        }
    }

    bool optionCheck(int opt){
        return correctOption == opt;
    }

};

class Quiz{
private:
    vector<Question> questions;
    int score;

public:

    int displayScore(){
        cout<<"Your total score is: "<<score<<" out of 35"<<endl;
    }

    void addQuestions(){
        questions.push_back(Question("What type of device allows you to control your smart home devices with your voice?", {"Smartwatch", "Smart TV", "Smart Speaker", "Tablet"}, 3));
        questions.push_back(Question("What is the name of the most popular video-sharing platform in the world?", {"TikTok", "Twitch", "Vimeo", "Youtube"}, 1));
        questions.push_back(Question("What is the name of the operating system used on most iPhones?", {"Windows", "Android", "Chrome OS", "iOS"}, 4));
        questions.push_back(Question("What is a common way to connect a laptop to the internet wirelessly?", {"Ethernet", "Wi-Fi", "Bluetooth", "Cellular Data"}, 2));
        questions.push_back(Question("What is a type of digital currency that is not controlled by any bank or government?", {"US Dollar", "Euro", "Cryptocurrency", "Credit Card"}, 3));
        questions.push_back(Question("What is the name of the company that created the powerpoint?", {"Samsung", "Huawei", "Microsoft", "LG"}, 3));
        questions.push_back(Question("What is the name of the world's richest person, known for his electric car company and space exploration ventures?", {"Bill Gates", "Mark Zuckerberg", "Jeff Bezos", "Elon Musk"}, 4));
    }

    void start(){

        score = 0;
        addQuestions();

        char userChoice;
        int answer;

        for(int i=0; i<questions.size(); i++){
            questions[i].displayQuestion();

            cout<<"Enter correct option: ";
            cin>>answer;

            if(questions[i].optionCheck(answer)){
                cout<<"YOUR ANSWER IS CORRECT !"<<endl;
                score+=5;
                cout<<"Do you want to continue ? (Y - yes || N - no)";
                cout<<"Enter your choice: ";
                cin>>userChoice;
                cout<<endl;

                if(userChoice == 'n' || userChoice == 'N'){
                    break;
                }
                else{
                    continue;
                }
            }
            else{
                cout<<"WRONG ANSWER !"<<endl<<"Would you like to start again? (Y - yes || N - no): ";
                cin>>userChoice;
                if(userChoice == 'y' || userChoice == 'Y'){
                    start();
                    return;
                }
                else{
                    displayScore();
                    return;
                }
            }
        }
        
        displayScore();
        
    }

};

int main(){

    Quiz game;
    game.start();
}
