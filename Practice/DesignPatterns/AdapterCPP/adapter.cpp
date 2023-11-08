#include <iostream>
using namespace std;

// Target interface
// we need all the adapters to implement these methods
class PaymentProcessorInterface {
    public:
        virtual void link() = 0;
        virtual void pay() = 0;
        virtual void status() = 0;
};


//////////////////////////////////////////////////////////////////////////////
// Adaptee class - class which needs to be adapted in our system, can be some external service provider or anything. We need to adapt
// its APIs as per our convention
class JustPaypPaymentProcessor {
    public:
        void linkToPay() {
            cout << "JustPay payment link" << endl;
        }
        void payment() {
            cout << "JustPay pay" << endl;
        }
        void isPaymentDone() {
            cout << "Justpay status" << endl;
        }
};

class RazorPayPaymentProcessor {
    public:
        void generateLink() {
            cout << "RazorPay payment link" << endl;
        }
        void makePayment() {
            cout << "RazorPay pay" << endl;
        }
        void paymentStatus() {
            cout << "RazorPay status" << endl;
        }
};

class PayuPayPaymentProcessor {
    public:
        void makeLink() {
            cout << "PayuPay payment link" << endl;
        }
        void payNow() {
            cout << "PayuPay pay" << endl;
        }
        void statusCheck() {
            cout << "PayuPay status" << endl;
        }
};
//////////////////////////////////////////////////////////////////////////////////////////////

// Now we need adapter class for each type of Adaptee class / service provider
// Adapter class
class AdapterJustPaypPaymentProcessor : public PaymentProcessorInterface, public JustPaypPaymentProcessor {
    private:
        JustPaypPaymentProcessor* processor = NULL;
    public:
        AdapterJustPaypPaymentProcessor(JustPaypPaymentProcessor* processor) {
            this->processor = processor;
        }
        void link() {
            processor->linkToPay();
        }
        void pay() {
            processor->payment();
        }
        void status() {
            processor->isPaymentDone();
        }
};

class AdapterRazorPayPaymentProcessor : public PaymentProcessorInterface, public RazorPayPaymentProcessor {
    private:
        RazorPayPaymentProcessor* processor = NULL;
    public:
        AdapterRazorPayPaymentProcessor(RazorPayPaymentProcessor* processor) {
            this->processor = processor;
        }
        void link() {
            processor->generateLink();
        }
        void pay() {
            processor->makePayment();
        }
        void status() {
            processor->paymentStatus();
        }
};

class AdapterPayuPayPaymentProcessor : public PaymentProcessorInterface, public PayuPayPaymentProcessor {
    private:
        PayuPayPaymentProcessor* processor = NULL;
    public:
        AdapterPayuPayPaymentProcessor(PayuPayPaymentProcessor* processor) {
            this->processor = processor;
        }
        void link() {
            processor->makeLink();
        }
        void pay() {
            processor->payNow();
        }
        void status() {
            processor->statusCheck();
        }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// client code
int main() {
    PaymentProcessorInterface* paymentProcessor = new AdapterJustPaypPaymentProcessor(new JustPaypPaymentProcessor);
    paymentProcessor->link();
    paymentProcessor->pay();
    paymentProcessor->status();
}

/*
Important points
1. Every API can have different return types or signature or different flow of execution. We will have to mould the code
inside Adapter class so as to keep the interface uniform.
2. Like for status codes, every processor can return different status codes. We will have to return our known status codes
from the method.
*/