#include <iostream>
using namespace std;

class student
{

public:
    int roll_no;
    int age;
    static int total_no_students;
};


/*
cout << "we are the best at what we do" << endl;
int a[3] = {1, 2, 3};
cout << a << endl;
int *ptr = a + 1;
cout << *ptr << endl;
char s = 't';
char *char_ptr = &s;
cout << *(&char_ptr) << endl;
double d = 3.234;
cout << &d << endl;
const char *f = "the strings attached";
cout << f << endl;
int x;
x = 9;
int *int_ptr = &x;
cout << int_ptr << endl;
int *ptr5 = 0;
string harry = "mufc";
cout << harry.substr(0, 3);
int *ptr7 = 0;
int b = 10;
*ptr7 = b;
cout << *ptr7 << endl;

*/
int main()
{
    student s;
    s.total_no_students=23;
    cout << s.total_no_students;
}