#include <iostream>
using namespace std;

// Interface
class IImage {
    public:
        virtual void displayImage() = 0;
};

// COncrete class
class Image : public IImage {
    private:
        string filename;
    public:
        Image(string filename) {
            this->filename = filename;
            loadFromDisk(this->filename);
        }
        void loadFromDisk(string filename) {
            cout << "Loading image from Disk" << endl;
        }
        void displayImage() override { 
            cout << "Displaying image" << endl;
        }
};

// Proxy class
class ImageProxy : public IImage {
    private:
        Image* image = NULL;
        string filename;
    public:
        ImageProxy(string filename) {
            this->filename = filename;
        }
        void displayImage() override {
            if(image == NULL) {
                cout << "invoking real object" << endl;
                image = new Image(this->filename);
            } else {
                cout << "cached object returned" << endl;
            }
            return image->displayImage();
        }
};

int main(void) {
    IImage* im = new ImageProxy("Tiger Image");
    im->displayImage();
    im->displayImage();
    im->displayImage();
    return 0;
}
