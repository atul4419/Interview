//write factorial using recursive method and consider edge cases

#include<iostream>
int factorial(int num){

    if((1 == num) || (0 == num)) return 1;

    return num * factorial(num - 1);
}

int main(){

    int num{0};
    std:: cin >>num;
    std::cout << factorial(num) << std::endl;
}