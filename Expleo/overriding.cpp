#include <iostream>
using namespace std;
//difference between H264 and H265 codec
//What is inter and intra frame
// When we use pass by pointer and pass by refference
// Ovveriding
// Virtual keyword
class Base {
    public :

    virtual void print(){
        cout << " Base is called";
    }

};

class Child1 : public Base{
    public :
     void print(){
        cout << " Child is called";
    }

};
class Child2 : public  Child1{
    public :

    void  print(){
        cout << " Child is called";
    }

};

int main(){

    Base *base = new Child2;


    base->print();




}
