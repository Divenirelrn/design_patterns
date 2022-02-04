#include <iostream>
#include <queue>
#include <Windows.h>


class ProtocolHandler{
public:
    void addMoney(){
        std::cout << "Add Money!" << std::endl;
    }

    void addDiamond(){
        std::cout << "Add Diamond!" << std::endl;
    }

    void addEquipment(){
        std::cout << "Add Equipment!" << std::endl;
    }

    void addLevel(){
        std::cout << "Add Level!" << std::endl;
    }
};


class AbstractCommand{
public:
    virtual void handle() = 0;
};


class AddMoneyCommand: public AbstractCommand {
public:
    AddMoneyCommand(ProtocolHandler* protocolHandler){
        this->protocolHandler = protocolHandler;
    }
    virtual void handle(){
        protocolHandler->addMoney();
    }

private:
    ProtocolHandler* protocolHandler;
};


class AddDiamondCommand: public AbstractCommand {
public:
    AddDiamondCommand(ProtocolHandler* protocolHandler){
        this->protocolHandler = protocolHandler;
    }
    virtual void handle(){
        protocolHandler->addDiamond();
    }

private:
    ProtocolHandler* protocolHandler;
};


class AddEquipmentCommand: public AbstractCommand {
public:
    AddEquipmentCommand(ProtocolHandler* protocolHandler){
        this->protocolHandler = protocolHandler;
    }
    virtual void handle(){
        protocolHandler->addEquipment();
    }

private:
    ProtocolHandler* protocolHandler;
};


class AddLevelCommand: public AbstractCommand {
public:
    AddLevelCommand(ProtocolHandler* protocolHandler){
        this->protocolHandler = protocolHandler;
    }
    virtual void handle(){
        protocolHandler->addLevel();
    }

private:
    ProtocolHandler* protocolHandler;
};


class Server{
public:
    void addCommand(AbstractCommand* command){
        this->cQueue.push(command);
    }

    void executeCommands(){
        while(!cQueue.empty()){
            Sleep(2000);
            AbstractCommand* command = cQueue.front();
            command->handle();
            cQueue.pop();
        }
    }

private:
    std::queue<AbstractCommand*> cQueue;
};


void test(){
    ProtocolHandler* protocolHandler = new ProtocolHandler;
    AbstractCommand* addMoney = new AddMoneyCommand(protocolHandler);
    AbstractCommand* addDiamod = new AddDiamondCommand(protocolHandler);
    AbstractCommand* addEquipment = new AddEquipmentCommand(protocolHandler);
    AbstractCommand* addLevel = new AddLevelCommand(protocolHandler);

    Server* server = new Server;
    server->addCommand(addMoney);
    server->addCommand(addDiamod);
    server->addCommand(addEquipment);
    server->addCommand(addLevel);

    server->executeCommands();

    delete protocolHandler;
    delete addMoney;
    delete addDiamod;
    delete addEquipment;
    delete addLevel;
    delete server;
}


int main(){
    test();
    return 0;
}