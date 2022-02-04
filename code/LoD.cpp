#include <iostream>
#include <string>
#include <vector>


class Building{
public:
    virtual std::string getQuality() = 0;
    virtual void sale() = 0;
};


class HighQualityBuilding: public Building{
public:
    HighQualityBuilding(){
        quality = "High Quality";
    }
    virtual std::string getQuality(){
        return quality;
    }
    virtual void sale(){
        std::cout << "The building of " << quality << " has been saled" << std::endl;
    }
private:
    std::string quality;
};


class LowQualityBuilding: public Building{
public:
    LowQualityBuilding(){
        quality = "Low Quality";
    }
    virtual std::string getQuality(){
        return quality;
    }
    virtual void sale(){
        std::cout << "The building of " << quality << " has been saled" << std::endl;
    }
private:
    std::string quality;
};


class Median{
public:
    Median(){
        Building* building = new HighQualityBuilding;
        vBuildings.push_back(building);
        building = new LowQualityBuilding;
        vBuildings.push_back(building);
    }

    Building* getBuilding(std::string quality){
        for(std::vector<Building*>::iterator it = vBuildings.begin(); it != vBuildings.end(); it++){
            if((*it)->getQuality().compare(quality) == 0){
                return *it;
            }
        }
        return NULL;
    }

    ~Median(){
        for(std::vector<Building*>::iterator it = vBuildings.begin(); it != vBuildings.end(); it++){
            if(*it != NULL){
                delete *it;
            }
        }
    }

public:
    std::vector<Building*> vBuildings;
};


void test(){
    Median median;
    Building* building = median.getBuilding("High Quality");
    if(building != NULL){
        building->sale();
    }else{
        std::cout << "No building has found!";
    }
}


int main(){
    test();
    return 0;
}