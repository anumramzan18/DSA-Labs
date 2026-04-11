#include<iostream>
using namespace std;

class shape {
public:
    virtual float area() = 0;
};

class circle : public shape {
private:
    float radius;
public:
    circle(float r) {
        radius = r;
    }
    float area() {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public shape {
private:
    float length;
    float width;
public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }
    float area() {
        return length * width;
    }
};

int main() {
    circle c(5);
    Rectangle r(4, 6);

    cout << "Area of Circle " << c.area() << endl;
    cout << "Area of Rectangle " << r.area() << endl;

    return 0;
}