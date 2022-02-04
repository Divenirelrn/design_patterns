#include <iostream>


class AbstractApple{
public:
    virtual void showName() = 0;
};


class ChinaApple: public AbstractApple{
public:
    virtual void showName(){
        std::cout << "Apple in China" << std::endl;
    }
};


class USAApple: public AbstractApple{
public:
    virtual void showName(){
        std::cout << "Apple in USA" << std::endl;
    }
};


class EuropeApple: public AbstractApple{
public:
    virtual void showName(){
        std::cout << "Apple in Europe" << std::endl;
    }
};


class AbstractBanana{
public:
    virtual void showName() = 0;
};


class ChinaBanana: public AbstractBanana{
public:
    virtual void showName(){
        std::cout << "Banana in China" << std::endl;
    }
};


class USABanana: public AbstractBanana{
public:
    virtual void showName(){
        std::cout << "Banana in USA" << std::endl;
    }
};


class EuropeBanana: public AbstractBanana{
public:
    virtual void showName(){
        std::cout << "Banana in Europe" << std::endl;
    }
};


class AbstractPear{
public:
    virtual void showName() = 0;
};


class ChinaPear: public AbstractPear{
public:
    virtual void showName(){
        std::cout << "Pear in China" << std::endl;
    }
};


class USAPear: public AbstractPear{
public:
    virtual void showName(){
        std::cout << "Pear in USA" << std::endl;
    }
};


class EuropePear: public AbstractPear{
public:
    virtual void showName(){
        std::cout << "Pear in Europe" << std::endl;
    }
};


class Factory{
public:
    virtual AbstractApple* createApple() = 0;
    virtual AbstractBanana* createBanana() = 0;
    virtual AbstractPear* createPear() = 0;
};


class ChinaFactory: public Factory{
public:
    AbstractApple* createApple(){
        return new ChinaApple;
    }
    AbstractBanana* createBanana(){
        return new ChinaBanana;
    }
    AbstractPear* createPear(){
        return new ChinaPear;
    }
};


class USAFactory: public Factory{
public:
    AbstractApple* createApple(){
        return new USAApple;
    }
    AbstractBanana* createBanana(){
        return new USABanana;
    }
    AbstractPear* createPear(){
        return new USAPear;
    }
};


class EuropeFactory: public Factory{
public:
    AbstractApple* createApple(){
        return new EuropeApple;
    }
    AbstractBanana* createBanana(){
        return new EuropeBanana;
    }
    AbstractPear* createPear(){
        return new EuropePear;
    }
};


void test(){
    Factory* factory = NULL;
    AbstractApple* apple = NULL;
    AbstractBanana* banana = NULL;
    AbstractPear* pear = NULL;

    factory = new ChinaFactory;
    apple = factory->createApple();
    banana = factory->createBanana();
    pear = factory->createPear();

    apple->showName();
    banana->showName();
    pear->showName();

    delete factory;
    delete apple;
    delete banana;
    delete pear;
}


int main(){
    test();
    return 0;
}