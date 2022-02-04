#include <iostream>
#include <algorithm>
#include <vector>


class Print{
public:
    void operator()(int v1, int v2){
     std::cout << v1 + v2 << std::endl;
    }
};


class Target{
public:
    virtual void operator()(int v) = 0;
};


class Adapter: public Target {
public:
    Adapter(int base){
        this->base = base;
    }
    virtual void operator()(int v){
        p(v, base);
    }
private:
    Print p;
    int base;
};


void test(){
    std::vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), Adapter(10));
}


int main(){
    test();
    return 0;
}