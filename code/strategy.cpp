#include <iostream>


class WeaponStrategy{
public:
    virtual void weapon() = 0;
};

class KnifeStrategy: public WeaponStrategy{
public:
    virtual void weapon(){
        std::cout << "Use weapon..." << std::endl;
    }
};

class AK47Strategy: public WeaponStrategy{
public:
    virtual void weapon(){
        std::cout << "Use AK47..." << std::endl;
    }
};


class Character{
public:
    void setWeapon(WeaponStrategy* weapon){
        this->pWeapon = weapon;
    }

    void useWeapon(){
        pWeapon->weapon();
    }
private:
    WeaponStrategy* pWeapon;
};


int main(){
    Character* person = new Character;
    KnifeStrategy* knife = new KnifeStrategy;
    AK47Strategy* ak47 = new AK47Strategy; 
    person->setWeapon(knife);
    person->useWeapon();
    person->setWeapon(ak47);
    person->useWeapon();
    delete person;
    delete knife;
    delete ak47;
    return 0;
}