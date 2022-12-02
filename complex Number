
#include<bits/stdc++.h>
using namespace std;

class Complex{
    float real;
    float imaginary;
public:
    Complex operator+(Complex x){
        Complex temp;
        temp.real = real + x.real;
        temp.imaginary = imaginary + x.imaginary;
        return temp;
    }

        Complex operator-(Complex x){           // minus
        Complex temp;
        temp.real = real - x.real;
        temp.imaginary = imaginary - x.imaginary;
        return temp;
    }


    Complex operator* (Complex x){      //(a+ib)*(x+iy) = ax + iay + ixb - by
        Complex temp;
        temp.real = real*x.real - imaginary*x.imaginary ;
        temp.imaginary = real*x.imaginary + x.real*imaginary ;
        return temp;
    }


    Complex operator/ (Complex x){

        int denm = x.real*x.real + x.imaginary*x.imaginary ;
        Complex temp;
        temp.real = (real*x.real + imaginary*x.imaginary)/denm;
        temp.imaginary = -( real*x.imaginary - x.real*imaginary)/denm ;
        return temp;

    }
    void print(){
        cout<<real<<" +i"<<imaginary<<endl;
    }

    void setComplex(int r, int i){
        real = r;
        imaginary = i;
    }

    friend Complex operator+ (int x, Complex y);
    friend istream& operator>> (istream &in, Complex &a);
    friend ostream& operator<< (ostream &out, Complex &a);
    friend Complex operator- (int x, Complex y);

};

Complex operator+ (int x, Complex y){
    Complex temp;
    temp.real = y.real + x;
    temp.imaginary = y.imaginary;
    return temp;
}

Complex operator- (int x, Complex y){
    Complex temp;
    temp.real = y.real - x;
    temp.imaginary = y.imaginary;
    return temp;
}

istream& operator>> (istream &in, Complex &a){
    cout<<"enter real part: "<<endl;
    in>>a.real;
    cout<<"enter imaginary part: "<<endl;
    in>>a.imaginary;
    return in;
}

ostream& operator<< (ostream &out, Complex &a){
    out<<a.real;
    if(a.imaginary>=0)
    out<<"+i"<<a.imaginary<<endl;
    else{
    a.imaginary = -1*a.imaginary;
    out<<"-i"<<a.imaginary<<endl;

    }


    return out;
}





int main()
{

    
    Complex c, a,b;
    cin>>a;
    cin>>b;
    c = a-b;
    cout<<c;

    Complex f = a/b;
    cout<<f;

    
    return 0;
}

    




