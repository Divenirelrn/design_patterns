#include <iostream>


class AbstractHero{
public:
    virtual void showStatus() = 0;
public:
    int mHp;
    int mMp;
    int mAt;
    int mDf;
};


class Hero : public AbstractHero {
public:
    Hero(){
        mHp = 0;
        mMp = 0;
        mAt = 0;
        mDf = 0;
    }

    virtual void showStatus(){
        std::cout << "mHp: " << mHp << std::endl;
        std::cout << "mMp: " << mMp << std::endl;
        std::cout << "mAt: " << mAt << std::endl;
        std::cout << "mDf: " << mDf << std::endl;
    }
};


class Equipment : public AbstractHero {
public:
    Equipment(AbstractHero* hero){
        this->pHero = hero;
    }
    virtual void showStatus(){}

public:
    AbstractHero* pHero;
};


class AddMHp : public Equipment {
public:
    AddMHp(AbstractHero* hero) : Equipment(hero){}
    void addMHp(){
        this->mHp = this->pHero->mHp + 30;
        this->mMp = this->pHero->mMp;
        this->mAt = this->pHero->mAt;
        this->mDf = this->pHero->mDf;
    }
    void showStatus(){
        addMHp();
        std::cout << "mHp: " << mHp << std::endl;
        std::cout << "mMp: " << mMp << std::endl;
        std::cout << "mAt: " << mAt << std::endl;
        std::cout << "mDf: " << mDf << std::endl;
    }
};


class AddMDf : public Equipment {
public:
    AddMDf(AbstractHero* hero) : Equipment(hero){}
    void addMDf(){
        this->mHp = this->pHero->mHp;
        this->mMp = this->pHero->mMp;
        this->mAt = this->pHero->mAt;
        this->mDf = this->pHero->mDf + 50;
    }
    void showStatus(){
        addMDf();
        std::cout << "mHp: " << mHp << std::endl;
        std::cout << "mMp: " << mMp << std::endl;
        std::cout << "mAt: " << mAt << std::endl;
        std::cout << "mDf: " << mDf << std::endl;
    }
};


void test(){
    AbstractHero* hero = new Hero;
    hero->showStatus();
    std::cout << "Add MHp:" << std:: endl;
    hero = new AddMHp(hero);
    hero->showStatus();
    std::cout << "Add MDf:" << std:: endl;
    hero = new AddMDf(hero);
    hero->showStatus();
    delete hero;
}


int main(){
    test();
    return 0;
}