#include <iostream>

class MySingleton {
private:
    static MySingleton * _self;
    int _var;  // < data!
public:
    static MySingleton * get_instance() {
        if(_self) _self = new MySingleton;
        return _self;
    };

    // data
    void var(int v) { _var = v; }
    int var() const { return _var; }
};

MySingleton * MySingleton::_self = nullptr;

void one() {
    std::cout << "one(), var=" << MySingleton::get_instance()->var() << std::endl;
    MySingleton::get_instance()->var(12);
    std::cout << "one(), var=" << MySingleton::get_instance()->var() << std::endl;
}

void two() {
    std::cout << "two(), var=" << MySingleton::get_instance()->var() << std::endl;
    MySingleton::get_instance()->var(13);
    std::cout << "two(), var=" << MySingleton::get_instance()->var() << std::endl;
}

// user code

int
main(int argc, char * argv[]) {
    MySingleton::get_instance()->var(14);

    //one();
    //two();
    return 0;
}

