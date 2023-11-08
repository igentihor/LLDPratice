#include <iostream>
using namespace std;

/* Key is to make the default constructor private so that no one can create object using new.
create a public method which will be responsible for creating the object if it doesn't exist 
or return the existing object for furthur requests */
class SingletonDemo {
    static SingletonDemo* instance;
    int data;

    SingletonDemo() {}

    public:
        static SingletonDemo* getInstance();

        int getData() {
            return this->data;
        }

        void setData(int data) {
            this->data = data;
        }
};

SingletonDemo* SingletonDemo::instance = NULL;

SingletonDemo* SingletonDemo::getInstance() {
    if(instance == NULL) {
        instance =  new SingletonDemo();
        cout << "new instance created" << endl;
    }
    cout << "old instance returned" << endl;
    return instance;
}

int main(void) {
    SingletonDemo* singleton1 = SingletonDemo::getInstance();
    singleton1->setData(100);
    cout << singleton1->getData() << endl;
    singleton1->setData(150);
    cout << singleton1->getData() << endl;

    SingletonDemo* singleton2 = SingletonDemo::getInstance();
    SingletonDemo* singleton3 = SingletonDemo::getInstance();
    SingletonDemo* singleton4 = SingletonDemo::getInstance();
    SingletonDemo* singleton5 = SingletonDemo::getInstance();
    cout << singleton2->getData() << endl;
}
