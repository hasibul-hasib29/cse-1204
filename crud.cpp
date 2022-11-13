// create read update delete
#include <bits/stdc++.h>

using namespace std;
class Student;
vector<Student> st;
class Student
{
private:
    string roll;
    string name;
    string cgpa;
    string dept;

public:
    void SetData(string, string, string, string);
    void GetData();
    void Update();
    void Delete();

    string GetRoll()
    {
        return roll;
    }
};

bool aliveUpdate(string r)
{
    for (auto &i : st)
    {
        if (i.GetRoll() == r)
        {   
            string n = "0";
            i.SetData(n, n, n, n);
            return true;
        }
    }

    return false;
}

bool alive(string r)
{
    for (auto &i : st)
    {
        if (i.GetRoll() == r){
            i.GetData();
            return true;
        }
            
    }

    return false;
}

void StdData()
{
    cout << "Enter student name: ";
    string name;
    cin.ignore();
    getline(cin, name);
    cout << "enter student roll: ";
    string roll;
    cin >> roll;
    cout << "enter department: ";
    string dept;
    cin.ignore();
    getline(cin, dept);
    cout << "enter cgpa: ";
    string cgpa;
    cin >> cgpa;
    ofstream file("student.txt", ios::app);
    file << name << endl;
    file << roll << endl;
    file << dept << endl;
    file << cgpa << endl;
    Student temp;
    temp.SetData(name, roll, dept, cgpa);
    st.push_back(temp);
}
void Update()
{
    string r;
    cout << "enter student roll to update: " << endl;
    cin >> r;
    if (aliveUpdate(r))
    {
        StdData();
    }
    else cout<<"This roll number isn't exist!!"<<endl;
}
void Search()
{
    string roll;
    cout<<"Enter roll to update: ";
    cin>>roll;
    if(alive(roll)){
        
    }
    else cout<<"This roll number isn't exist!!"<<endl;
}
int main()
{
    ifstream file("student.txt");
    string input;
    while (file.eof() == 0)
    {
        string name;
        getline(file, name);
        string roll;
        getline(file, roll);
        string dept;
        getline(file, dept);
        string cgpa;
        getline(file, cgpa);
        Student temp;
        temp.SetData(name, roll, dept, cgpa);
        st.push_back(temp);
    }

    while (1)
    {
        int choice;
        cout << "\n====================\n";
        cout << "Enter option: " << endl;
        cout << "0. Quit" << endl;
        cout << "1. Enter student data" << endl;
        cout << "2. search" << endl;
        cout << "3. update" << endl;
        cout << "\n====================\n";
        cin >> choice;

        if (choice == 0)
            break;

        switch (choice)
        {
        case 1:
        {
            StdData();
            break;
        }

        case 2:
        {
            Search();
            break;
        }

        case 3:
        {
            Update();
            break;
        }
        }
    }

    return 0;
}

void Student::SetData(string n, string r, string d, string c)
{
    name = n;
    roll = r;
    cgpa = c;
    dept = d;
}

void Student::GetData()
{   
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "NAME  : " << name << endl;
    cout << "ROLL  : " << roll << endl;
    cout << "DEPT. : " << dept << endl;
    cout << "CGPA  : " << cgpa << endl;
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}