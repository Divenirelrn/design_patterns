#include <iostream>

/********传统模式*******/
//底层模块
class BankWorker{
public:
    void doSaveBusiness(){
        std::cout << "Save Business" << std::endl;
    }
    void doFetchBusiness(){
        std::cout << "Fetch Business" << std::endl;
    }
    void doTransferBusiness(){
        std::cout << "Transfer Business" << std::endl;
    }
};

//中层模块
void doSavebusiness(BankWorker* bankWorker){
    bankWorker->doSaveBusiness();
}
void doFetchbusiness(BankWorker* bankWorker){
    bankWorker->doFetchBusiness();
}
void doTransferbusiness(BankWorker* bankWorker){
    bankWorker->doTransferBusiness();
}


//业务模块
void test(){
    BankWorker* bankworker = new BankWorker;
    doSavebusiness(bankworker);
    doFetchbusiness(bankworker);
    doTransferbusiness(bankworker);
    delete bankworker;
}


/********依赖倒转原则******/
/*面向接口（抽象类）编程，业务逻辑依赖于抽象层，底层的具体实现同样与抽象层关联，抽象层作为业务层与底层的接口*/


class AbstractWorker{
public:
    virtual void doBusiness() = 0;
};


class SaveWorker: public AbstractWorker{
public:
    virtual void doBusiness(){
        std::cout << "Save Business" << std::endl;
    }
};


class FetchWorker: public AbstractWorker{
public:
    virtual void doBusiness(){
        std::cout << "Fetch Business" << std::endl;
    }
};


class TransferWorker: public AbstractWorker{
public:
    virtual void doBusiness(){
        std::cout << "Transfer Business" << std::endl;
    }
};


void doBusiness(AbstractWorker* worker){
    worker->doBusiness();
    delete worker;
}


void test02(){
    doBusiness(new SaveWorker);
    doBusiness(new FetchWorker);
    doBusiness(new TransferWorker);
}


int main(){
    // test();
    test02();
    return 0;
}