//Create a class having two pointer data member and write all constructor and destructor.

#include<iostream>

class Complex{
    private:
    int *ptr1{nullptr}, *ptr2{nullptr};

    public:
    //Default constructor
    Complex(){
        //
        std::printf("default\n");
    }
    //parameterized constructor
    Complex(int x, int y) : ptr1(new int(x)), ptr2(new int(y)){
        std::printf("Parameterized\n");
    }
    //copy constructor
    Complex(const Complex &other): ptr1(new int(*other.ptr1)), ptr2(new int(*other.ptr2)){
        std::printf("copy constructor\n");
    }

    //move constructor
    Complex(Complex &&other) noexcept : ptr1(other.ptr1),ptr2(other.ptr2) {
        printf("move constructor\n");
        other.ptr1 = nullptr;
        other.ptr2 = nullptr;
    }
    // why noexcet in move constructor
    // Because many parts of the Standard Library (especially containers like std::vector, std::deque, etc.) will:
    // Prefer move over copy only if they know that move cannot throw exceptions.
    // If the move constructor might throw, containers fall back to using the (possibly slower)
    // copy constructor during operations like resize, reserve, or reallocation — to keep strong exception safety.
    // std::vector<MyClass> v;
    // v.push_back(MyClass());

    // //delegate constructor

    // Complex( ): Complex(0,0){}

    //destructor
    ~Complex(){
        printf("destructor\n");
        if(ptr1) delete ptr1;
        if(ptr2) delete ptr2;
    }

    void printData(){
        std::cout << *ptr1 << "\t" << *ptr2 << " \n";
    }
};

// int main(){
//     Complex *ptr = new Complex(10,20);
//     Complex *ptr2 = ptr;
//     delete ptr;
//     ptr2->printData(); //dangling pointer gives garbage value
//     Complex *ptr3(new Complex(40,50));
// }


// ===== DRIVER CODE =====
int main(){
   // std::printf("== Create using default constructor ==\n");
    Complex c1;

   //std::printf("\n== Create using parameterized constructor ==\n");
    Complex c2(10, 20);
    c2.printData();

    //std::printf("\n== Create using copy constructor ==\n");
    Complex c3 = c2;  // copy constructor
    c3.printData();

    //std::printf("\n== Create using move constructor ==\n");
    Complex c4 = std::move(c3);
    c4.printData();
    //c2.printData();  // after move, c2's pointers are nullptr

    //using temp data

    Complex c5(Complex(100,200)); // here compiler does not call move constructor due to optimization
    //This is called copy elision or named return value optimization (NRVO).
    //here no memory for temp object is created it creates memory for c5 itself

    //if you still wants move constructor is called in this case use below flags
//     -fno-elide-constructors tells GCC/Clang not to elide
//g++ -std=c++17 -fno-elide-constructors allConstructor.cpp
// ✅ Best way to force move constructor: create a named temporary, then std::move it
    c5.printData();

    return 0;
}