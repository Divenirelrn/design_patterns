#include <iostream>


class AbstractCommanInterface{
public:
    virtual void run() = 0;
};


class MySystem: public AbstractCommanInterface{
public:
    virtual void run(){
        std::cout << "System booted!" << std::endl;
    }
};


class PrototypeSystem: public AbstractCommanInterface{
public:
    PrototypeSystem(std::string username, std::string password){
        this->username = username;
        this->password = password;
        this->system = new MySystem;
    }

    bool checkAuthority(){
        if(this->username == "xiaojun" && this->password == "123456"){
            return true;
        }
        return false;
    }

    virtual void run(){
        if(checkAuthority()){
            system->run();
        }else{
            std::cout << "用户名或密码错误" << std::endl;
        }
    }

    ~PrototypeSystem(){
        if(this->system != NULL){
            delete this->system;
        }
    }

private:
    std::string username;
    std::string password;
    MySystem* system;
};


int main(){
    PrototypeSystem proto("xiaojun", "123456");
    proto.run();
    return 0;
}