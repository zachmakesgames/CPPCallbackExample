//C++ callback example
#include <iostream>
#include <functional>


class Caller {
public: 
    std::function<void(int)>callback;

    Caller() {
    }

    void SetCallback(std::function<void(int)>new_function) {
        callback = new_function;
    }

    void Run() {
        for (int i = 0; i < 10; ++i) {
            if (i == 5) {
                std::cout << "Caller requirements met, calling back! with value 1234!" << std::endl;
                callback(1234);
            }
            else {
                std::cout << "Caller doing something else.." << std::endl;
            }
        }
    }
};


class Controller {
public:
    Caller* _caller;


    Controller(Caller* new_caller):_caller(new_caller) {
        //This is a very simple way to pass callbacks between classes using C++ 11 and the functional library.
        //Callbacks on static or non-member functions are easy to do, but passing callbacks between classes can
        //get tricky. Using this method avoids most of the mess and allows the method to be determined at run
        //time rather than compile time, even though this example doesn't demonstrate that.
        _caller->SetCallback(std::bind(&Controller::Callback, this, std::placeholders::_1));
    
    }

    void Callback(int i) {
        std::cout << "Controller running callback... " << std::endl;
        std::cout << "Controller called with argument: " << i << std::endl;
        std::cout << std::endl;
    }

};



int main()
{
    Caller _caller;
    Controller c(&_caller);

    //Note that the caller has no reference to the controller, yet it can still
    //call back when it needs to.
    _caller.Run();
   
}
