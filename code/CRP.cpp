#include <iostream>


class Car{
public:
    virtual void run() = 0;
};


class Bench: public Car{
public:
    virtual void run(){
        std::cout << "Bench" << std::endl;
    }
};


class BMW: public Car{
public:
    virtual void run(){
        std::cout << "BMW" << std::endl;
    }
};


class Person{
public:
    void setCar(Car* car){
        this->car = car;
    }
    void drive(){
        car->run();
    }
    ~Person(){
        std::cout << "Decomponent has called" << std::endl;
        if(car != NULL){
            delete car;
            car = NULL;
        }
    }
private:
    Car* car; //优先使用组合
};


void test(){
    Person* p1 = new Person;
    p1->setCar(new Bench);
    p1->drive();
    p1->setCar(new BMW);
    p1->drive();
    delete p1;
}


int main(){
    test();
    return 0;
}