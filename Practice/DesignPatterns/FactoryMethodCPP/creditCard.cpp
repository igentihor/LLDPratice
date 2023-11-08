#include <iostream>
using namespace std;

// Product class
class CreditCard {
    public:
        virtual ~CreditCard() {}
        virtual string getCardType() = 0;
        virtual int getCreditLimit() = 0;
        virtual int getAnnualCharge() = 0;
};

// Concrete product 1
class Platinum : public CreditCard {
    public:
        string getCardType() override {
            return "PLATINUM";
        }
        int getCreditLimit() override {
            return 55000;
        }
        int getAnnualCharge() override {
            return 1700;
        }
};

// Concrete product 2
class Titanium : public CreditCard {
    public:
        string getCardType() override {
            return "TITANIUM";
        }
        int getCreditLimit() override {
            return 60000;
        }
        int getAnnualCharge() override {
            return 1900;
        }
};

// Creator class
class CreditCardFactory {
    public:
        virtual CreditCard* createCreditCard() = 0;

        CreditCard* issueCreditCard() {
            return this->createCreditCard();
        }
};

// Concrete Creator class 1
class PlatinumFactory : public CreditCardFactory {
    public:
        CreditCard* createCreditCard() {
            CreditCard* newCard = new Platinum();
            return newCard;
        }
};

// Concrete Creator class 2
class TitaniumFactory : public CreditCardFactory {
    public:
        CreditCard* createCreditCard() {
            CreditCard* newCard = new Titanium();
            return newCard;
        }
};

// Client code
int main(void) {
    CreditCard* platinum = PlatinumFactory().issueCreditCard();
    CreditCard* titanium = TitaniumFactory().issueCreditCard();
    if(platinum != NULL) {
        cout << platinum->getCardType() << endl;
        cout << platinum->getAnnualCharge() << endl;
        cout << platinum->getCreditLimit() << endl;
    }
    if(titanium != NULL) {
        cout << titanium->getCardType() << endl;
        cout << titanium->getAnnualCharge() << endl;
        cout << titanium->getCreditLimit() << endl;
    }
    return 0;
}
