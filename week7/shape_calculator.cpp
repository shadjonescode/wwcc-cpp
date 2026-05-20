#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w);

    double getLength() const;
    double getWidth() const;

    void setLength(double l);
    void setWidth(double w);

    double area() const;
    void area(double& result) const;

    Rectangle& resize(double scale);
};
Rectangle::Rectangle(double l, double w){
    if (l > 0){
        length = l;
    }
    else{
        length = 1;
    }

    if (w > 0){
        width = w;
    }
    else{
        width = 1;
    }
}
double Rectangle::getLength() const{
    return length;
}
double Rectangle::getWidth() const{
    return width;
}
void Rectangle::setLength(double l){
    if (l > 0){
        length = l;
    }
}
void Rectangle::setWidth(double w){
    if (w > 0){
        width = w;
    }
}
double Rectangle::area() const{
    return length * width;
}
void Rectangle::area(double& result) const{
    result = length * width;
}
Rectangle& Rectangle::resize(double scale){
    this->length *= scale;
    this->width *= scale;

    return *this;
}

class Circle{
private:
    double radius;

public:
    Circle(double r);

    void setRadius(double r);

    double getArea() const;
    double getCircumference() const;

    void print() const;
    void print(bool fullCalculation) const;
};
Circle::Circle(double r){
    if (r > 0){
        radius = r;
    }
    else{
        radius = 1;
    }
}
void Circle::setRadius(double r){
    if (r > 0){
        radius = r;
    }
}
double Circle::getArea() const{
    return 3.14159 * radius * radius;
}
double Circle::getCircumference() const{
    return 2 * 3.14159 * radius;
}
void Circle::print() const{
    cout << "Radius: " << radius << endl;
}
void Circle::print(bool fullCalculation) const{
    if (fullCalculation == true){
        cout << "Area = 3.14159 * " << radius << " * " << radius << " = " << getArea() << endl;
        
        cout << "Circumference = 2 * 3.14159 * " << radius << " = " << getCircumference() << endl;
    }
}
int main(){
    cout << "SHAPE CALCULATOR" << endl;
    cout << "----------------" << endl << endl;

    Rectangle rectangle(5.0, 3.0);

    cout << "Rectangle (Length: " << rectangle.getLength() << ", Width: " << rectangle.getWidth() << ")" << endl;

    cout << "Area: " << rectangle.area() << endl;

    double rectangleArea;
    rectangle.area(rectangleArea);
    cout << "Area via reference: " << rectangleArea << endl << endl;

    Circle circle(4.0);

    circle.print();
    cout << endl;

    circle.print(true);
    cout << endl;

    cout << "Method chaining:" << endl;
    cout << "Original: Length = " << rectangle.getLength() << ", Width = " << rectangle.getWidth() << endl << endl;

    rectangle.resize(2.0).resize(3.0);

    cout << "After resize(2.0).resize(3.0): Length = " << rectangle.getLength() << ", Width = " << rectangle.getWidth() << endl << endl;

    const Circle constCircle(6.0);

    cout << "Const Circle: " << endl;
    cout << "Area: " << constCircle.getArea() << endl;
    cout << "Circumference: " << constCircle.getCircumference() << endl;

    return 0;
}