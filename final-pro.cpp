#include <iostream>
using namespace std;

void program1() {
    class Rectangle {
    private:
        float length, width;
    public:
        void setLength(float l) { length = l; }
        void setWidth(float w) { width = w; }
        float getLength() { return length; }
        float getWidth() { return width; }
        float getArea() { return length * width; }
    };

    Rectangle r;
    r.setLength(8.1);
    r.setWidth(4.5);

    cout << "Length: " << r.getLength() << endl;
    cout << "Width: " << r.getWidth() << endl;
    cout << "Area: " << r.getArea() << endl;
}


void program2() {
    class Employee {
    private:
        string name;
        float salary;
        string designation;
    public:
        void setName(string n) { name = n; }
        void setSalary(float s) { salary = s; }
        void setDesignation(string d) { designation = d; }
        string getName() { return name; }
        float getSalary() { return salary; }
        string getDesignation() { return designation; }
    };

    Employee emp;
    emp.setName("dipak");
    emp.setSalary(31000);
    emp.setDesignation("co-manager");

    cout << "Employee Data:\n";
    cout << "Name: " << emp.getName() << endl;
    cout << "Salary: " << emp.getSalary() << endl;
    cout << "Designation: " << emp.getDesignation() << endl;
}

void program3() {
    class Shape {
    private:
        string color;
        float area;
    public:
        void setColor(string c) { color = c; }
        string getColor() { return color; }
        void setArea(float a) { area = a; }
        float getArea() { return area; }
    };

    class Circle : public Shape {
    private:
        float radius;
    public:
        void setRadius(float r) { radius = r; }
        void calculateArea() { setArea(3.14f * radius * radius); }
    };

    class Rectangle : public Shape {
    private:
        float length, width;
    public:
        void setDimensions(float l, float w) {
            length = l; width = w;
        }
        void calculateArea() { setArea(length * width); }
    };

    Circle c;
    c.setColor("green");
    c.setRadius(2);
    c.calculateArea();

    cout << "Circle Color: " << c.getColor() << endl;
    cout << "Circle Area: " << c.getArea() << endl;

    Rectangle r;
    r.setColor("red");
    r.setDimensions(1, 4);
    r.calculateArea();

    cout << "Rectangle Color: " << r.getColor() << endl;
    cout << "Rectangle Area: " << r.getArea() << endl;
}

void program4() {
    class Shape {
    protected:
        string color;
        float area;
    public:
        void setColor(string c) { color = c; }
        void setArea(float a) { area = a; }
        virtual void display() {
            cout << "this is shape\n";
        }
    };

    class Circle : public Shape {
    private:
        float radius;
    public:
        void setRadius(float r) { radius = r; }
        void calculateArea() { area = 3.14f * radius * radius; }
        void display() override {
            cout << "Circle Info:\nColor: " << color
                 << "\nRadius: " << radius
                 << "\nArea: " << area << endl;
        }
    };

    class Rectangle : public Shape {
    private:
        float length, width;
    public:
        void setDimensions(float l, float w) {
            length = l; width = w;
        }
        void calculateArea() { area = length * width; }
        void display() override {
            cout << "Rectangle Info:\nColor: " << color
                 << "\nLength: " << length
                 << "\nWidth: " << width
                 << "\nArea: " << area << endl;
        }
    };

    Circle c;
    c.setColor("red");
    c.setRadius(2);
    c.calculateArea();

    Rectangle r;
    r.setColor("yellow");
    r.setDimensions(2, 1);
    r.calculateArea();

    Shape* shapes[2] = { &c, &r };

    cout << "\nPolymorphism Output:\n";
    for (int i = 0; i < 2; i++) {
        shapes[i]->display();
        cout << endl;
    }
}

void program5() {
    class Animal {
    public:
        virtual void sound() = 0;
        virtual void move() = 0;
    };

    class Dog : public Animal {
    public:
        void sound() override { cout << "Dog Bark.." << endl; }
        void move() override { cout << "Dog runs quickly." << endl; }
    };

    class Bird : public Animal {
    public:
        void sound() override { cout << "Bird chiiii..chiiii.." << endl; }
        void move() override { cout << "Bird flying." << endl; }
    };

    Dog d;
    Bird b;
    Animal* arr[2] = { &d, &b };

    for (int i = 0; i < 2; i++) {
        arr[i]->sound();
        arr[i]->move();
        cout << endl;
    }
}


int main() {
    int choice;

    cout << "\n Choose one\n";
    cout << "Program-1 Click-1\n";
    cout << "Program-2 Click-2\n";
    cout << "Program-3 Click-3\n";
    cout << "Program-4 Click-4\n";
    cout << "Program-5 Click-5\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "\n--\n";

    switch (choice) {
        case 1: program1(); break;
        case 2: program2(); break;
        case 3: program3(); break;
        case 4: program4(); break;
        case 5: program5(); break;
        default: cout << "wrong choice!" << endl;
    }

    return 0;
}
