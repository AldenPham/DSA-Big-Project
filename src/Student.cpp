/*
Này để cập nhật các method của abstract class làm gì.
*/


#include <Student.h>
#include <iostream>
#include <string>

using namespace std;

Student::Student(string name, string studentID, int GPA, int ranking){
    this->name = name;
    this->studentID = studentID;
    this->GPA = GPA;
    this->ranking = ranking;
}

void Student::get_Info(){
    cout << name << "\n";
    cout << studentID << "\n";
    cout << GPA << "\n";
    cout << ranking << "\n";
}

string Student::get_MSSV(){
    return studentID;
}

void Student::update_Ranking(int newRank){
    ranking = newRank;
}