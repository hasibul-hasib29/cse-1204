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
    
    string GetName(){ return name;}
    string GetRoll(){ return roll;}
    string GetDept(){ return dept;}
    string GetCgpa(){ return cgpa;}


   
};

bool aliveUpdate(string r)
{
    for (auto &i : st)
    {
        if (i.GetRoll() == r)
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
            i.SetData(name, roll, dept , cgpa);

            return true;
        }
    }

    return false;
}

bool alive(string r)
{
    for (auto &i : st)
    {
        if (i.GetRoll() == r)
        {
            i.GetData();
            return true;
        }
    }

    return false;
}
bool aliveDead(string r)
{
    for (int i=0; i<st.size(); i++)
    {
        if (st[i].GetRoll() == r)
        {   
            
            st.erase(st.begin()+i);
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
        cout<<"Update successfull!!"<<endl;
    }
    else
        cout << "This roll number isn't exist!!" << endl;
}
void Search()
{
    string roll;
    cout << "Enter roll to update: ";
    cin >> roll;
    if (alive(roll))
    {
    }
    else
        cout << "This roll number isn't exist!!" << endl;
}
void Delete()
{
    string st;
    cout << "enter student's roll to delete id: ";
    cin >> st;
    if(aliveDead(st)) cout<<"Delete completed"<<endl;
    else cout<<"Failed!!"<<endl;
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
        cout << "4. Delete" << endl;
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
        case 4: {Delete(); break;}
        }
    }


    // updated and all student info into file
    ofstream output ("student.txt");
    for(int i=0; i<st.size(); i++){
        string name = st[i].GetName();
        string roll = st[i].GetRoll();
        string dept = st[i].GetDept();
        string cgpa = st[i].GetCgpa();
        output<<name<<endl;
        output<<roll<<endl;
        output<<dept<<endl;
        output<<cgpa<<endl;
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
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "NAME  : " << name << endl;
    cout << "ROLL  : " << roll << endl;
    cout << "DEPT. : " << dept << endl;
    cout << "CGPA  : " << cgpa << endl;
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
