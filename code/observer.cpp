#include <iostream>
#include <list>


class AbstractHero{
public:
    virtual void update() = 0;
};


class HeroA: public AbstractHero {
public:
    HeroA(){
        std::cout << "HeroA is battling..." << std::endl;
    }
    void update(){
        std::cout << "Boss is dead, HeroA await..." << std::endl;
    }
};


class HeroB: public AbstractHero {
public:
    HeroB(){
        std::cout << "HeroB is battling..." << std::endl;
    }
    void update(){
        std::cout << "Boss is dead, HeroB await..." << std::endl;
    }
};


class HeroC: public AbstractHero {
public:
    HeroC(){
        std::cout << "HeroC is battling..." << std::endl;
    }
    void update(){
        std::cout << "Boss is dead, HeroC await..." << std::endl;
    }
};


class AbstractBoss{
public:
    virtual void addHero(AbstractHero*) = 0;
    virtual void deleteHero(AbstractHero*) = 0;
    virtual void notify() = 0;
};


class Boss: public AbstractBoss {
public:
    void addHero(AbstractHero* hero){
        pHeroList.push_back(hero);
    }
    void deleteHero(AbstractHero* hero){
        pHeroList.remove(hero);
    }
    void notify(){
        for(std::list<AbstractHero*>::iterator it = pHeroList.begin(); it != pHeroList.end(); it++){
            (*it)->update();
        }
    }
private:
    std::list<AbstractHero*> pHeroList;
};


void test(){
    AbstractHero* hearoA = new HeroA;
    AbstractHero* hearoB = new HeroB;
    AbstractHero* hearoC = new HeroC;

    AbstractBoss* boss = new Boss;
    boss->addHero(hearoA);
    boss->addHero(hearoB);
    boss->addHero(hearoC);

    boss->deleteHero(hearoB);

    boss->notify();

    delete hearoA;
    delete hearoB;
    delete hearoC;
    delete boss;
}


int main(){
    test();
    return 0;
}