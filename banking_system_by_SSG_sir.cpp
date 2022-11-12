//Name: Hasibul Hasan
// Roll: 2003127
// Lab: 2 → banking system


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int usedAccount = 0;

class User
{

    string name;
    long long mobileNo;
    string address;
    long long nid;
    string pin;

public:
    // ======
    void setName(string nameToUpdate)
    {
        name = nameToUpdate;
    }
    void setMobile(long long n)
    {
        mobileNo = n;
    }

    void setAddress(string addr)
    {
        address = addr;
    }

    void setPin(string pi)
    {
        pin = pi;
    }

    void setNID(long long nd)
    {
        nid = nd;
    }

    string getName(){
        return name;
    }
    long long getMob(){
        return mobileNo;
    }
    string getPin(){
        return pin;
    }
    long long getNid(){
        return nid;
    }
    string getAdr(){
        return address;
    }
};

class Transaction
{
private:
    double amount;
    string type;
    string date;
    long long number;
public:
    void setTnxData(double d, long long n){
    cout<<"enter tnx type: ";
    string s = "<SEND MONEY>";
    
     type = s;
     amount = d; 
     number = n;

    }
    void setViceTnxData(double d, long long n){
        type = "<received money>";
        amount = d;
        number = n;
    }
    void viewTnxHist(){
        cout<<"-------------"<<endl;
        cout<<"Tnx type "<<type<<endl;
        cout<<"Mobile No: "<<number<<endl;
        cout<<"ammount: "<<amount<<endl;
        cout<<"-------------"<<endl;
    }

};

class Account:public User
{
    double balance=100;
    Transaction transinfo[200];

public:
   
    int tnxCt=0;
    
    bool sendORnot(double b){
        if(balance - b >=0)  return true;
        return false;
    }

    void initialize(string name, long long mob, string address, string pin, long long nid);

    void showAll()
    {
        cout<<"name: "<<getName()<<endl;
        cout<<"Mob: "<<getMob()<<endl;
        cout<<"Address: "<<getAdr()<<endl;

    }
    int checkPassAndPhn(long long , string);

    bool senderExistance(long long);
    void setAcTnx(double d, long long num){
        transinfo[tnxCt].setTnxData(d,num);
        tnxCt++;
    }
    void setAcIN(double d, long long n){
        transinfo[tnxCt].setViceTnxData(d,n);
        tnxCt++;
    }
    void viewTnHistory(){
        for(int i=0;i<tnxCt;i++){
            transinfo[i].viewTnxHist();
        }
    }
    void cashIn(double a){

        balance +=a;
        
    }
    void checkBalance(){
        cout<<"Your current balance is : "<<balance<<"$"
        <<endl;
        
    }
    void cashGO(double b){
        balance -=b;
    }

};

Account accounts[10000];
// problem

int senderExistance(long long n){
    for(int i=0;i<=usedAccount;i++){
        if(accounts[i].getMob() == n){
            return i;
            
        }
    }
    return -9;
}
void createAc()
{

    string name;
    long long mobile, nid;
    string address, pin;
    cout << "\n===========\n";
    cout<<"YOUR NAME: ";
    cin.ignore(); getline(cin, name);
    cout<<"YOUR MOBILE NO: ";
    cin >> mobile; cout<<"YOUR ADDRESS: ";
    cin.ignore(); getline(cin,address);  cout<<"YOUR NID NO: ";cin >> nid;
    cout<<"YOUR PIN: ";
    cin.ignore(); getline(cin, pin);
    accounts[usedAccount].initialize(name, mobile, address, pin, nid);
    usedAccount++;
    cout<<"Congratulations!! You have received 100$ for creating new account"<<endl<<"Check your balance "<<endl;
}
void sendMoney()
{
    long long x;
    cout<<"Enter Receiver mobile no: ";
    cin>>x;
    int sid; sid = senderExistance(x);
    if(sid>=0){
        
        long long phn;
        string s;
        cout<<"Enter your phone number: ";
        cin>>phn;
        cout<<"Enter your password: "; cin>>s;
        Account temp;
        int ind = temp.checkPassAndPhn(phn,s);
        if(ind>=0){
            double amt; cout<<"enter your sending ammount: ";
            cin>>amt;
            if(accounts[ind].sendORnot(amt)){
               accounts[sid].cashIn(amt);
               accounts[ind].cashGO(amt);
               accounts[sid].setAcIN(amt,phn);
               accounts[ind].setAcTnx(amt,x);

               cout<<"#################"<<endl;
               cout<<"send money successfully!"<<endl;

            }

            else cout<<"NOT sufficient ammount!"<<endl;

        }
        else cout<<"Incorrect user phone and password!"<<endl;
    }
    else cout<<"Invalid user mobile!"<<endl;
    cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}


void checkamount(){
     long long n;
    string p;
    cout<<"enter your phone number: "; cin>>n;
    cout<<"enter your password: "; cin>>p;
    Account tmp;
    int x = tmp.checkPassAndPhn(n,p);
    if(x>=0){ accounts[x].checkBalance();}
    else cout<<"incorrect phone number and password!"<<endl;
}
void printInfo()
{
    
    long long phn;
    cout<<"enter your phone number: ";
    cin>>phn;
    cout<<"enter your passowrd: ";
    string s;
    cin>>s;
    Account a;
    cout<<endl;
    cout<<"**************\n";
    int x = a.checkPassAndPhn(phn,s);
    if(x>=0){
        accounts[x].showAll();
        int y;
        cout<<"if you want to show your all transcation history press 1 else press 0 "<<endl;
        cin>>y;
        if(y) accounts[x].viewTnHistory();
        
    }
    else cout<<"invalid password or mobile!"<<endl;
    
    cout<<endl<<"***************"<<endl;
}
// how many accounts

int main()
{   
    
    
    int a;
    do
    {   cout<<"-------------------\n\n";
        cout << "select option\n";
        cout << "1. Create account\n";
        cout << "2.send money\n";
        cout<<"3. Show info\n";
        // cout<<"4. cash in"<<endl;
        cout<<"4.Check balance"<<endl;

        cout << "5. Exit\n";

        cin >> a;
        if (a == 1)
            createAc();
        if (a == 2)
            sendMoney();
        if(a==3) printInfo();
        if(a==4)  checkamount();
    } while (a != 5);

    return 0;
}

void Account::initialize(string name, long long mob, string address, string pin, long long nid)
{
    setName(name);
    setMobile(mob);
    setAddress(address);
    setNID(nid);
    setPin(pin);
}

int Account::checkPassAndPhn(long long n, string s){
        bool flag = false;
    int ind=-1;
    for(int i=0; i<usedAccount; i++){
        if(accounts[i].getMob()==n){
        flag = true;
        ind =  i;
        break;
        }
    }

    if(flag){
    
    
        if(accounts[ind].getPin()==s){
            
            return ind;
        }
    
    }

    return -9999;
}

