#include <iostream>


class Person{
public:
    int age;
    int getAge(){
        return this->age;
    }
    void showAge(){
        std::cout << this->getAge();
        std::cout << "\n";
    }
};


int main(){
    Person *p = new Person();
    p->age = 18;
    p->showAge();
    return 0;
}