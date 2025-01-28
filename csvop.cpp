#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <sstream>

using namespace std;

class Student
{
    public:
        int ID,age;
        string Name,Major;
        float GPA;
    Student(int id,int a,string name,string major,float gpa)
    {
        ID=id;
        age=a;
        Name=name;
        Major=major;
        GPA=gpa;
    }
    Student(vector<string> inp)
    {
        ID = stoi(inp[0]);
        Name = inp[1];
        age = stoi(inp[2]);
        Major = inp[3];
        GPA = stof(inp[4]);
    }
};

vector<Student> students;   

void read(string filename="students.csv")
{
    string line,val;
    fstream file;
    file.open(filename,ios::in);
    bool firstLine = true;  // To avoid reading the column names
    if (file)
    {
        while(getline(file,line))
        {
            if (firstLine)
            {
                firstLine=false;
                continue;
            }

            vector<string> vals;
            stringstream ss(line);
            while (getline(ss,val,',')){
                vals.push_back(val);
            }
            Student stu(vals);
            students.push_back(stu);    
        }
    }
    file.close();
}

void display()
{
    cout << left << setw(10) << "ID"
         << setw(15) << "Name"
         << setw(10) << "Age"
         << setw(20) << "Major"
         << setw(5) << "GPA" << endl;
    for (Student student : students)
    {
        cout << left << setw(10) << student.ID
             << setw(15) << student.Name
             << setw(10) << student.age
             << setw(20) << student.Major
             << setw(5) << student.GPA << endl;
    }
}

int main()
{
    read();
    display();
    return 0;
}