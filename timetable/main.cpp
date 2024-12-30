
#include "timeTable.h"

int main(){
    TimeTable t('3',"1");
    //t.showTable();
    //showCurriculum();
    showPoorGrade();

    return 0;
}

bool showCurriculum(){
    
    string gradeInput, semesterInput, currentLine, token;
    int tokenNum = 0;
    const int gradePlace = 0, semesterPlace = 1;

    ifstream file("./data/curriculum.csv");
    if(!file.is_open()){
        cout << "Fail to open the curriculum file" << endl;
        return false;
    }

    cout << "What is your grade? >>>";
    cin >> gradeInput;
    cout << "What is your semester? >>>";
    cin >> semesterInput;

    getline(file, currentLine);
    cout << currentLine << endl;
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

    file.close();
    return true;
}

bool showPoorGrade(){

    string currentLine, token;
    vector<string> grdArray, tmpArray;
    int tokenNum, i;

    ifstream file("./data/grade.csv");
    if(!file.is_open()){
        cout << "Fail to open the grade file" << endl;
        return false;
    }

    cout << "<Poor Subjects>" << endl;
    getline(file, currentLine);
    cout << endl << "===" << currentLine << "===" << endl << endl;
    while(getline(file, currentLine)){
        stringstream ss(currentLine);
        tokenNum = -1;
        while(getline(ss, token, ',')){
            tokenNum++;
            if(tokenNum == 6){
                if(token.length() == 1 && isalpha(token[0])){
                    continue;
                }else if(token.length() == 3 && token[1] == '.'){
                    if(stof(token) <= 2.5 ){
                        grdArray.push_back(currentLine);
                        //cout << currentLine << endl;
                        continue;
                    }
                }else{
                    cout << "Grade Format Error" << endl;
                    return false;
                }
            }
        }
    }

    cout << "Major Electives" << endl;
    tmpArray = grdArray;
    for(i = 0; i < tmpArray.size(); i++){
        stringstream ss(tmpArray[i]);
        tokenNum = -1;
        while(getline(ss, token, ',')){
            tokenNum++;
            if(tokenNum == 2){
                if(token == "ME"){
                    cout << tmpArray[i] << endl;
                    grdArray.erase(grdArray.begin() + i);
                }
            }
        }
    }

    cout << endl << "The Others" << endl;
    for(i = 0; i < grdArray.size(); i++){
        cout << grdArray[i] << endl;
    }

    file.close();
    return true;
}