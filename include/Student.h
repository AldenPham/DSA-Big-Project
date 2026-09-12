/*
.h là một file tạo class trong c++

Điểm khác giữa abs class trong c++ và c#, java là sytax.
    -Sytax
    -Tính là thư viện, vậy nên muốn sài class này phải #include <Student.h>
    -Phải khai báo các abs method (constructor cũng tính là 1 method)
*/


#pragma once
#include <string>

using namespace std;

struct Student{
    private:
    string name;
    string studentID;
    int GPA;
    int ranking;

    public:
    //constructor
    Student(string name, string studentID, int GPA, int ranking);

    void get_Info();

    string get_MSSV();
    
    void update_Ranking(int newRank);
};