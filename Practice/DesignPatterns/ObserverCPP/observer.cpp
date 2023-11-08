#include <bits/stdc++.h>
using namespace std;

class ISubscriber {
    public:
        virtual void update() = 0;
};

class IPublisher {
    public:
        virtual void addSubscriber(ISubscriber* sub) = 0;
        virtual void removeSubscriber(ISubscriber* sub) = 0;
        virtual void notify() = 0;
};

class Publisher : public IPublisher {
    private:
        int temperature = 1;
        vector<ISubscriber*> v;
        void printSubscribers() {
            vector<ISubscriber*>::iterator iter = v.begin();
            for(iter; iter < v.end(); iter++)
            {
                cout << *iter << " ";
            }
            cout << endl;
        }
    public:
        void addSubscriber(ISubscriber* sub) {
            v.push_back(sub);
            printSubscribers();
        }
        void removeSubscriber(ISubscriber* sub) {
            v.erase(std::remove(v.begin(), v.end(), sub), v.end());
            printSubscribers();
        }
        void notify() {
        }
        int getTemperature() {
            temperature *= 5;
            return this->temperature;
        }
};

class FirstSubscriber : public ISubscriber {
    private:
        int temperature = 1;
        Publisher* publisher = NULL;
    public:
        FirstSubscriber(Publisher* publisher) {
             this->publisher = publisher;
        }
        void update() {
            this->temperature = publisher->getTemperature();
            cout << this->temperature << endl;
        }
};

class SecondSubscriber : public ISubscriber {
    private:
        int temperature = 1;
        Publisher* publisher = NULL;
    public:
        SecondSubscriber(Publisher* publisher) {
             this->publisher = publisher;
        }
        void update() {
            this->temperature = publisher->getTemperature();
            cout << this->temperature << endl;
        }
};

int main() {
    Publisher* publisher = new Publisher();
    ISubscriber* firstSubscriber = new FirstSubscriber(publisher);
    ISubscriber* secondSubscriber = new SecondSubscriber(publisher);
    publisher->addSubscriber(firstSubscriber);
    publisher->addSubscriber(secondSubscriber);
    publisher->removeSubscriber(firstSubscriber);
    return 0;
}
