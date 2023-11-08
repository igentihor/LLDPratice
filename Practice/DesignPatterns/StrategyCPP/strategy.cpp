#include <iostream>
using namespace std;

class IRouteBuilder {
    public:
        virtual void buildRoute() = 0;
};

class CarRoute : public IRouteBuilder {
    public:
        void buildRoute() {
            cout << "Building road route" << endl;
        }
};

class CycleRoute : public IRouteBuilder {
    public:
        void buildRoute() {
            cout << "Building cycle route" << endl;
        }
};

class WalkingRoute : public IRouteBuilder {
    public:
        void buildRoute() {
            cout << "Building walking route" << endl;
        }
};

class Context {
    private:
        IRouteBuilder* routeBuilder = NULL;
    public:
        Context(IRouteBuilder* routeBuilder) {
            this->routeBuilder = routeBuilder;
        }
        void setRouteBuilder(IRouteBuilder* routeBuilder) {
            this->routeBuilder = routeBuilder;
        }
        void businessLogic() {
            routeBuilder->buildRoute();
        }
};

int main() {
    IRouteBuilder* carRouteBuilder = new CarRoute();
    Context* context = new Context(carRouteBuilder);
    context->businessLogic();
    context->setRouteBuilder(new CycleRoute);
    context->businessLogic();
    context->setRouteBuilder(new WalkingRoute);
    context->businessLogic();
    return 0;
}
