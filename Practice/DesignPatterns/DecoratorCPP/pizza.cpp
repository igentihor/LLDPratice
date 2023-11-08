#include <iostream>
using namespace std;

class Pizza {
    public:
        virtual int getCost() = 0;
        virtual string getComposition() = 0;
};

class PizzaBase : public Pizza {
    public:
        int getCost() {
            return 5;
        }
        string getComposition() {
            return "Pizza Base";
        }
};

class Cheese : public Pizza {
    private:
        Pizza* pizza;
    public:
        Cheese(Pizza* pizza) {
            this->pizza = pizza;
        }
        int getCost() {
            return pizza->getCost() + 10;
        }
        string getComposition() {
            return pizza->getComposition() + " + Cheese";
        }
};

class Sauce : public Pizza {
    private:
        Pizza* pizza;
    public:
        Sauce(Pizza* pizza) {
            this->pizza = pizza;
        }
        int getCost() {
            return pizza->getCost() + 7;
        }
        string getComposition() {
            return pizza->getComposition() + " + Sauce";
        }
};

class Corn : public Pizza {
    private:
        Pizza* pizza;
    public:
        Corn(Pizza* pizza) {
            this->pizza = pizza;
        }
        int getCost() {
            return pizza->getCost() + 20;
        }
        string getComposition() {
            return pizza->getComposition() + " + Corn";
        }
};

int main() {
    Pizza* pizza = new Sauce(
        new Corn(
            new Cheese(
                new Cheese(
                    new Corn(
                        new PizzaBase
                    )
                )
            )
        )
    );
    cout << pizza->getComposition() << endl;
    cout << pizza->getCost() << endl;
    Pizza* pizza1 = new PizzaBase;
    Pizza* newPizza = new Corn(pizza1);
    cout << newPizza->getComposition() << " " << newPizza->getCost() << endl;
}
