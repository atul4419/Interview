//What are the use cases of move constructor and when to use it.
// To avoid multiple copy object creation we use move constructor, in STL for e.g in vector when we 
//push_back the element and capacity is full now vector can reallocate new memory block  with double it's capacity
//and copies the previous element into it. It is wastage of effort to OS in order to manage all the stuff.
//If we use move then it simply moves the element into newly created vector.
#include<iostream>
#include<vector>

class MoveUseCase{

    int num = 0;
    public:
    
    MoveUseCase(int num) : num(num){
        printf("patrameterized\n");
    }
    MoveUseCase():MoveUseCase(0){
        //delegate
        printf("Delegate\n");

    }
    //copy constructor
    MoveUseCase(const MoveUseCase &other): num(other.num){
        //
        std::printf("Copy Constructor\n");
    }

    MoveUseCase(MoveUseCase &&rValue) noexcept :num(rValue.num) {
        rValue.num = 0;
        std::printf("Move constructor \n");
    }

    void printData(){
        std::cout << " num \t" << num << std::endl;
    }

};

int main(){
    std::vector<MoveUseCase> arr;
    arr.reserve(2);

    MoveUseCase mv1;
    MoveUseCase mv2;
    

    arr.push_back(mv1);
    arr.push_back(mv2);

    MoveUseCase mv3;

    arr.push_back(mv3);
}