#include <iostream>
using namespace std;

class Student {
    private:
        string name;
        string address;
        string college;
        string batch;
        int psp;
        int age;

    public:
        class Builder {
            private:
                Student* student;
            public:
                Builder() {
                    student = new Student();
                }
                Builder* setName(string name) {
                    student->name = name;
                    return this;
                }
                Builder* setAge(int age) {
                    student->age = age;
                    return this;
                }
                Builder* setCollege(string college) {
                    student->college = college;
                    return this;
                }
                Builder* setBatch(string batch) {
                    student->batch = batch;
                    return this;
                }
                Builder* setPsp(int psp) {
                    student->psp = psp;
                    return this;
                }
                Builder* setAddress(string address) {
                    student->address = address;
                    return this;
                }
                Student* build() {
                    return student;
                }
        };

        string getName() {
            return this->name;
        }
        string getCollege() {
            return this->college;
        }
        int getAge() {
            return this->age;
        }
        
        static Builder* getBuilder();
};

Student::Builder* Student::getBuilder() {
    return new Builder();
}

int main() {
    Student* student = Student::getBuilder()
                    ->setName("Rohit Negi")
                    ->setAge(20)
                    ->setCollege("ABES")
                    ->setPsp(95)
                    ->build();

    cout << student->getName() << endl;
    cout << student->getAge() << endl;
    cout << student->getCollege() << endl;
}
