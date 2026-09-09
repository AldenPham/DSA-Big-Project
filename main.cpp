#include <Student.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    Student a("pham thanh Tin", 2516767, 10, 1);

    a.get_Info();

    a.update_Ranking(67);

    a.get_Info();
}