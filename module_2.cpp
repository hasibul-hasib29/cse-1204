#include<iostream>
using namespace std;
class Test{
private:
    int x;
    int y;
    static int z;
    static int sumX;
    static int temp;
    static int yInd;
    
public:

    
    Test (int a=0, int b=0){
        x=a; y =b;
        z++;
        sumX+=x;
        
         
        if(y>temp){
            yInd =z;
        }
        else temp =y;

    }
    Test(const Test &p){
        x = p.x;
        y = p.y;
        z++;
        sumX +=x;
        
        if(y>temp){
            yInd =z;
        }
        else temp =y;
    }

    void Initilize(int a, int b){
        x =a;
        y =b;
        sumX +=x;
        if(y>temp){
            yInd =z;
        }
        else temp =y;

    }

    static void getZ(){                      // for display data member z
        cout<<"z = "<<z<<endl;
    }

    void getAll(){
        cout<<"x = "<<x<<endl<<
            "y = "<<y<<endl<<
            "z = "<<z<<endl;
    }

    void getConstData ()const{
        cout<<"x = "<<x<<endl
            <<"y = "<<y<<endl
            <<"z =  "<<z<<endl;
    }
    static void SumOfx() {
        cout<<"the sum of all x = "<<sumX<<endl;
    }

    static void YmaxInd(){
        cout<<"Y's maximum value is class no : "<<yInd<<endl;
    }
    
    
    
};
int Test::z = 0;
int Test::sumX =0;
int Test::yInd=0;
int Test::temp =0;
int main(){
    Test a;
    Test b(4,5);
    Test c(b);
    Test d(8, 7);
    Test e;
    e.Initilize(7, 9);
    e.getConstData();
    
    Test::SumOfx();
    Test::YmaxInd();
    

    return 0;
}





// OUTPUT:
// x = 7
// y = 9
// z =  5
// the sum of all x = 23
// Y's maximum value is class no : 5