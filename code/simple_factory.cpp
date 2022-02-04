#include <iostream>


class AbstractFruit{
public:
    virtual void showName() = 0;
};


class Apple: public AbstractFruit{
public:
    virtual void showName(){
        std::cout << "Apple" <<std::endl;
    }
};


class Banana: public AbstractFruit{
public:
    virtual void showName(){
        std::cout << "Banana" <<std::endl;
    }
};


class Orange: public AbstractFruit{
public:
    virtual void showName(){
        std::cout << "Orange" <<std::endl;
    }
};


class FruitFactory{
public:
    AbstractFruit* makeFruit(std::string fruit){
        if(fruit == "apple"){
            return new Apple; 
        }else if(fruit == "banana"){
            return new Banana;
        }else if(fruit == "orange"){
            return new Orange;
        }else{
            return NULL;
        }
    }
};


void test(){
    FruitFactory* fFactory = new FruitFactory;
    AbstractFruit* fruit = fFactory->makeFruit("apple");
    fruit->showName();
    fruit = fFactory->makeFruit("orange");
    fruit->showName();
    delete fruit;
    delete fFactory;
}


int main(){
    test();
    return 0;
}