#include <iostream>


class Calculator{
public:
    virtual void setValues(int a, int b) = 0;
    virtual int getResults() = 0;
};


class AddCalculator :public Calculator{
public:
    void setValues(int a, int b){
        this->mA = a;
        this->mB = b;
    }
    int getResults(){
        return mA + mB;
    }
private:
    int mA;
    int mB;
};


class SubCalculator :public Calculator{
public:
    virtual void setValues(int a, int b){
        this->mA = a;
        this->mB = b;
    }
    virtual int getResults(){
        return mA - mB;
    }
private:
    int mA;
    int mB;
};


class MulCalculator :public Calculator{
public:
    virtual void setValues(int a, int b){
        this->mA = a;
        this->mB = b;
    }
    virtual int getResults(){
        return mA * mB;
    }
private:
    int mA;
    int mB;
};


class DivCalculator :public Calculator{
public:
    virtual void setValues(int a, int b){
        this->mA = a;
        this->mB = b;
    }
    virtual int getResults(){
        return mA / mB;
    }
private:
    int mA;
    int mB;
};


class ModCalculator :public Calculator{
public:
    virtual void setValues(int a, int b){
        this->mA = a;
        this->mB = b;
    }
    virtual int getResults(){
        return mA % mB;
    }
private:
    int mA;
    int mB;
};


void test(){
    Calculator* calculator = new AddCalculator;
    calculator->setValues(10, 20);
    std::cout << calculator->getResults() << "\n";
    calculator->setValues(20, 30);
    std::cout << calculator->getResults() << "\n";
    calculator = new SubCalculator;
    calculator->setValues(20, 30);
    std::cout << calculator->getResults() << "\n";
}


int main(){
    test();
    return 0;
}