#include <iostream>
using namespace std;

class Student {

private:
    int rollNo;
    string name;
public:
    Student(int r, string n) {
        rollNo = r;
        name = n;
        cout << "Student object created" << endl;
    }
    void display() {
        cout << "Roll Number : " << rollNo << endl;
        cout << "Name : " << name << endl;
    }
    ~Student() {
        cout << "Student object destroyed" << endl;
    }
};

int main() 
{
    int rollNo=0;
    string name;
    cout<<"enter roll number:"<<endl;
    cin>>rollNo;
    cout<<"enter name:"<<endl;
    cin>>name;
    Student s1(rollNo,name);
    s1.display();
    return 0;
}