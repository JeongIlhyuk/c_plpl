
#include "timeTable.h"

int main(){
    TimeTable t(3,"1");
    // t.showTable();
    showCurriculum();

    return 0;
}

bool showCurriculum(){
    
    string gradeInput, semesterInput, currentLine, token;
    ifstream file("./data/curriculum.csv");
    int tokenNum = 0;
    const int gradePlace = 0, semesterPlace = 1;

    cout << "What is your grade? >>";
    cin >> gradeInput;
    cout << "What is your semester? >>";
    cin >> semesterInput;

    while(getline(file, currentLine)){
        stringstream ss(currentLine);
        tokenNum = -1;
        while(getline(ss, token, ',')){
            tokenNum++;
            if(tokenNum == gradePlace){
                if(token == gradeInput){
                    getline(ss, token, ',');
                    tokenNum++;
                    if (tokenNum == semesterPlace){
                        if((token == semesterInput) || token == "Both"){
                          cout << currentLine << endl;
                        }
                    }
                }
            }else{
                break;
            }
        }
    }
    return true;
}

bool showGrade(){
    
}