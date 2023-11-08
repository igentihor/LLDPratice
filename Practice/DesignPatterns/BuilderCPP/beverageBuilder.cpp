#include <iostream>
using namespace std;

// Product class
class Beverage {

    string beverageType;
    int waterQuantity;
    string powderType;

    public:
        void setBeverageType(string pBeverageType) {
            this->beverageType = pBeverageType;
        }
        void setWaterQuantity(int pWaterQuantity) {
            this->waterQuantity = pWaterQuantity;
        }
        void setPowderType(string pPowderType) {
            this->powderType = pPowderType;
        }
        void showBeverage() {
            cout << "Preparing Beverage Type : " << this->beverageType << endl;
            cout << "Adding water : " << this->waterQuantity << " ml" << endl;
            cout << "Adding " << this->powderType << endl;
            cout << this->beverageType << " is ready!" << endl;
        }
};

// Builder interface
class BeverageBuilder {
    protected:
        Beverage* beverage;
    public:
        BeverageBuilder() {
            beverage = new Beverage;
        }
        virtual void BuildBeverageType() = 0;
        virtual void BuildWaterQuantity() = 0;
        virtual void BuildPowderType() = 0;
        virtual Beverage* getBeverage() {
            return beverage;
        }
};

// Concrete Builder 1
class TeaBuilder : public BeverageBuilder {
    public:
        void BuildBeverageType() override {
            beverage->setBeverageType("Tea");
        }
        void BuildWaterQuantity() override {
            beverage->setWaterQuantity(10);
        }
        void BuildPowderType() override {
            beverage->setPowderType("TeaPowder");
        }
};

// Concrete Builder 2
class CoffeeBuilder : public BeverageBuilder {
    public:
        void BuildBeverageType() override {
            beverage->setBeverageType("Coffee");
        }
        void BuildWaterQuantity() override {
            beverage->setWaterQuantity(5);
        }
        void BuildPowderType() override {
            beverage->setPowderType("CoffeePowder");
        }
};

// Director
class BeverageDirector {
    private:
        BeverageBuilder* beverageBuilder;
    public:
        BeverageDirector(BeverageBuilder* pBeverageBuilder) {
            beverageBuilder = pBeverageBuilder;
        }
        Beverage* BuildBeverage() {
            beverageBuilder->BuildBeverageType();
            beverageBuilder->BuildWaterQuantity();
            beverageBuilder->BuildPowderType();
            return beverageBuilder->getBeverage();
        }
};

int main() {
    BeverageBuilder *teaBuilder = new TeaBuilder();
    BeverageBuilder *coffeeBuilder = new CoffeeBuilder();

    BeverageDirector *beverageDirector1 = new BeverageDirector(teaBuilder);
    BeverageDirector *beverageDirector2 = new BeverageDirector(coffeeBuilder);

    Beverage *b1 = beverageDirector1->BuildBeverage();
    b1->showBeverage();
    Beverage *b2 = beverageDirector2->BuildBeverage();
    b2->showBeverage();
    return 0;
}
