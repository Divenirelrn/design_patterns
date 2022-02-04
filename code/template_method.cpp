#include <iostream>


class DrinkMaker{
public:
    virtual void boildWater() = 0;
    virtual void brew() = 0;
    virtual void pourIntoCup() = 0;
    virtual void addSomething() = 0;

    void make(){
        boildWater();
        brew();
        pourIntoCup();
        addSomething();
    }
};


class CoffeMaker: public DrinkMaker{
public:
    virtual void boildWater(){
        std::cout << "煮水" << std::endl;
    }
    virtual void brew(){
        std::cout << "冲咖啡" << std::endl;
    }
    virtual void pourIntoCup(){
        std::cout << "倒入杯中" << std::endl;
    }
    virtual void addSomething(){
        std::cout << "加糖" << std::endl;
    }
};


class TeaMaker: public DrinkMaker{
public:
    virtual void boildWater(){
        std::cout << "煮水" << std::endl;
    }
    virtual void brew(){
        std::cout << "冲茶" << std::endl;
    }
    virtual void pourIntoCup(){
        std::cout << "倒入杯中" << std::endl;
    }
    virtual void addSomething(){
        std::cout << "加柠檬" << std::endl;
    }
};


void test(){
    DrinkMaker* maker = new CoffeMaker;
    maker->make();
    maker = new TeaMaker();
    maker->make();
    delete maker;
}


int main(){
    test();
    return 0;
}