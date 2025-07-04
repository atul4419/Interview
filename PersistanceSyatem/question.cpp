//claas name -> complex
// members x,y
// show data, print data
// all the constr

//write all constructor and assignment operator
// Why after delete ptr it gives garbage value.
// Fix this code.
// What sre the smart pointers
// What is socket programing with example.
#include<iostream>

class Complex {
    private :
    int *x = nullptr, *y = nullptr;

    public:
    Complex() {

    }
    Complex(int *x, int *y): x(x),y(y) {
        
    }
    Complex(const Complex &fcomplex){
        std::cout << " Copy/n" ;
        x = new int(*fcomplex.x);
        
        y = new int(*fcomplex.y);
    }

    void printData(){
        std::cout << *x <<  "\t" << *y << std::endl;
    }
   Complex operator = (const Complex &complex) {
    std::cout << " Assignment/n" ;
        x = complex.x;
        y = complex.y;

        return *this;
    }

    ~ Complex(){
        if(x != nullptr){
            delete x;
        }
        if(y != nullptr){
            delete y;
        }
    }

};


int main(){

    Complex *ptr = new Complex(new int(1),new int(2));

    Complex *ptr2 = ptr;

    delete ptr;
    ptr2->printData();
}