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


class AbstractFactory{
public:
    virtual AbstractFruit* makeFruit() = 0;
};


class AppleFactory: public AbstractFactory{
public:
    virtual AbstractFruit* makeFruit(){
        return new Apple;
    }
};


class BananaFactory: public AbstractFactory{
public:
    virtual AbstractFruit* makeFruit(){
        return new Banana;
    }
};


class OrangeFactory: public AbstractFactory{
public:
    virtual AbstractFruit* makeFruit(){
        return new Orange;
    }
};


void test(){
    AbstractFruit* fruit = NULL;
    AbstractFactory* factory = NULL;

    factory = new AppleFactory;
    fruit = factory->makeFruit();
    fruit->showName();

    factory = new OrangeFactory;
    fruit = factory->makeFruit();
    fruit->showName();

    delete fruit;
    delete factory;

}


int main(){
    test();
    return 0;
}