#include <iostream>

//懒汉模式
class SingleLetonLazy{
private:
    SingleLetonLazy(){}
public:
    static SingleLetonLazy* getInstance(){ //构造函数私有化，无法初始化对象，因此无法调用getInstance，因此只能加static，
                                            //用类调用的方法
        if(pSingleLetonLazy == NULL){
            pSingleLetonLazy = new SingleLetonLazy;
        }

        return pSingleLetonLazy;
    }

private:
    static SingleLetonLazy* pSingleLetonLazy;
};

SingleLetonLazy* SingleLetonLazy::pSingleLetonLazy = NULL;


//恶汉模式
class SingleLetonHungry{
private:
    SingleLetonHungry(){};
public:
    static SingleLetonHungry* getInstance(){
        return pSingleLetonHungry;
    }
private:
    static SingleLetonHungry* pSingleLetonHungry;
};

SingleLetonHungry* SingleLetonHungry::pSingleLetonHungry = new SingleLetonHungry;


int main(){
    SingleLetonLazy* pSingleLetonLazy = SingleLetonLazy::getInstance();
    SingleLetonLazy* pSingleLetonLazy2 = SingleLetonLazy::getInstance();
    std::cout << (pSingleLetonLazy == pSingleLetonLazy2) << std::endl;
    SingleLetonHungry* pSingleLetonHungry = SingleLetonHungry::getInstance();
    SingleLetonHungry* pSingleLetonHungry2 = SingleLetonHungry::getInstance();
    std::cout << (pSingleLetonHungry == pSingleLetonHungry2) << std::endl;
    return 0;
}