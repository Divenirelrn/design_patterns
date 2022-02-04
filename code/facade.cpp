#include <iostream>


class TV{
public:
    void on(){
        std::cout << "TV 0n..." << std::endl;
    }
    void off(){
        std::cout << "TV off..." << std::endl;
    }
};


class Light{
public:
    void on(){
        std::cout << "Light 0n..." << std::endl;
    }
    void off(){
        std::cout << "Light  off..." << std::endl;
    }
};


class Audio{
public:
    void on(){
        std::cout << "Audio 0n..." << std::endl;
    }
    void off(){
        std::cout << "Audio off..." << std::endl;
    }
};


class MicroPhone{
public:
    void on(){
        std::cout << "MicroPhone 0n..." << std::endl;
    }
    void off(){
        std::cout << "MicroPhone off..." << std::endl;
    }
};


class DVD{
public:
    void on(){
        std::cout << "DVD 0n..." << std::endl;
    }
    void off(){
        std::cout << "DVD off..." << std::endl;
    }
};


class KTVMode{
public:
    KTVMode(){
        tv = new TV;
        light = new Light;
        audio = new Audio;
        microPhone = new MicroPhone;
        dvd = new DVD;
    }

    void onMode(){
        tv->on();
        light->off();
        audio->on();
        microPhone->on();
        dvd->on();
    }

    ~KTVMode(){
        delete tv;
        delete light;
        delete audio;
        delete microPhone;
        delete dvd;
    }

private:
    TV* tv;
    Light* light;
    Audio* audio;
    MicroPhone* microPhone;
    DVD* dvd;
};


class GameMode{
public:
    GameMode(){
        tv = new TV;
        light = new Light;
        audio = new Audio;
        microPhone = new MicroPhone;
        dvd = new DVD;
    }

    void onMode(){
        tv->on();
        light->on();
        audio->on();
        microPhone->on();
        dvd->on();
    }

    ~GameMode(){
        delete tv;
        delete light;
        delete audio;
        delete microPhone;
        delete dvd;
    }

private:
    TV* tv;
    Light* light;
    Audio* audio;
    MicroPhone* microPhone;
    DVD* dvd;
};


void test(){
    KTVMode* ktvMode = new KTVMode;
    ktvMode->onMode();
    delete ktvMode;
}


int main(){
    test();
    return 0;
}