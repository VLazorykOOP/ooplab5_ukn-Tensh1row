
//Exercise 1

#include <iostream>
#include <string>

using namespace std;

class Window {
private:
    int x1, y1, x2, y2;
    string bgColor;

public:
    Window() {
        x1 = 0;
        y1 = 0;
        x2 = 0;
        y2 = 0;
        bgColor = "white";
    }

    Window(int x1, int y1, int x2, int y2, string bgColor) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->bgColor = bgColor;
    }

    ~Window() {
        cout << "Window destroyed." << endl;
    }

    void print() {
        cout << "Window coordinates: (" << x1 << "," << y1 << ") to (" << x2 << "," << y2 << ")" << endl;
        cout << "Background color: " << bgColor << endl;
    }

    void setBackgroundColor(string color) {
        bgColor = color;
    }
};

class MenuWindow : public Window {
private:
    string menuText;

public:
    MenuWindow() {
        menuText = "Default Menu";
    }

    MenuWindow(int x1, int y1, int x2, int y2, string bgColor, string menuText) : Window(x1, y1, x2, y2, bgColor) {
        this->menuText = menuText;
    }

    ~MenuWindow() {
        cout << "MenuWindow destroyed." << endl;
    }

    void print() {
        Window::print();
        cout << "Menu Text: " << menuText << endl;
    }

    void setMenuText(string text) {
        menuText = text;
    }
};

int main() {
    Window window1(10, 10, 50, 50, "blue");
    window1.print();
    window1.setBackgroundColor("green");
    window1.print();

    MenuWindow menuWindow1(100, 100, 200, 200, "red", "File Edit View");
    menuWindow1.print();
    menuWindow1.setBackgroundColor("yellow");
    menuWindow1.setMenuText("Edit File");
    menuWindow1.print();

    return 0;
}


//Exercise 2



#include <iostream>
#include <string>

using namespace std;

class HardDisk {
private:
    int capacity;

public:
    HardDisk() {
        capacity = 0;
    }

    HardDisk(int capacity) {
        this->capacity = capacity;
    }

    ~HardDisk() {
        cout << "Hard Disk destroyed." << endl;
    }

    int getCapacity() {
        return capacity;
    }

    void setCapacity(int capacity) {
        this->capacity = capacity;
    }
};

class Computer {
private:
    string brand;
    int price;
    HardDisk hardDisk;

public:
    Computer() {
        brand = "";
        price = 0;
        hardDisk = HardDisk();
    }

    Computer(string brand, int price, int hardDiskCapacity) {
        this->brand = brand;
        this->price = price;
        hardDisk = HardDisk(hardDiskCapacity);
    }

    ~Computer() {
        cout << "Computer destroyed." << endl;
    }

    string getBrand() {
        return brand;
    }

    int getPrice() {
        return price;
    }

    HardDisk getHardDisk() {
        return hardDisk;
    }

    void setBrand(string brand) {
        this->brand = brand;
    }

    void setPrice(int price) {
        this->price = price;
    }

    void setHardDisk(HardDisk hardDisk) {
        this->hardDisk = hardDisk;
    }

    void print() {
        cout << "Brand: " << brand << endl;
        cout << "Price: " << price << endl;
        cout << "Hard Disk Capacity: " << hardDisk.getCapacity() << " MB" << endl;
    }
};

class Desktop : public Computer {
private:
    int monitorSize;

public:
    Desktop() {
        monitorSize = 0;
    }

    Desktop(string brand, int price, int hardDiskCapacity, int monitorSize) : Computer(brand, price, hardDiskCapacity) {
        this->monitorSize = monitorSize;
    }

    ~Desktop() {
        cout << "Desktop destroyed." << endl;
    }

    int getMonitorSize() {
        return monitorSize;
    }

    void setMonitorSize(int monitorSize) {
        this->monitorSize = monitorSize;
    }

    void print() {
        Computer::print();
        cout << "Monitor Size: " << monitorSize << " inches" << endl;
    }
};

int main() {
    HardDisk hd1(1000);
    cout << "Hard Disk Capacity: " << hd1.getCapacity() << " MB" << endl;
    hd1.setCapacity(2000);
    cout << "Hard Disk Capacity: " << hd1.getCapacity() << " MB" << endl;

    Computer pc1("Dell", 1000, 500);
    pc1.print();
    pc1.setHardDisk(HardDisk(1000));
    pc1.print();

    Desktop desktop1("HP", 1500, 1000, 24);
    desktop1.print();
    desktop1.setBrand("Lenovo");
    desktop1.print();

    return 0;
}



//Exercise 3





#include <iostream>
#include <cmath>

using namespace std;

class Quadrilateral {
public:
    Quadrilateral() : side1(0), side2(0), side3(0), side4(0) {}
    Quadrilateral(double s1, double s2, double s3, double s4)
        : side1(s1), side2(s2), side3(s3), side4(s4) {}
    virtual ~Quadrilateral() {}

    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    virtual void print(ostream& os) const {
        os << "Quadrilateral with sides " << side1 << ", " << side2 << ", "
           << side3 << ", " << side4;
    }

    virtual void read(istream& is) {
        is >> side1 >> side2 >> side3 >> side4;
    }

    Quadrilateral(const Quadrilateral& other)
        : side1(other.side1), side2(other.side2),
          side3(other.side3), side4(other.side4) {}

    Quadrilateral& operator=(const Quadrilateral& other) {
        if (this == &other) {
            return *this;
        }

        side1 = other.side1;
        side2 = other.side2;
        side3 = other.side3;
        side4 = other.side4;

        return *this;
    }

protected:
    double side1, side2, side3, side4;
};

class Square : public Quadrilateral {
public:
    Square() : Quadrilateral() {}
    Square(double side) : Quadrilateral(side, side, side, side) {}
    virtual ~Square() {}

    virtual double area() const {
        return side1 * side1;
    }

    virtual double perimeter() const {
        return 4 * side1;
    }

    virtual void print(ostream& os) const {
        os << "Square with side " << side1;
    }

    virtual void read(istream& is) {
        is >> side1;
        side2 = side3 = side4 = side1;
    }

    Square(const Square& other) : Quadrilateral(other) {}

    Square& operator=(const Square& other) {
        Quadrilateral::operator=(other);
        return *this;
    }
};

int main() {
    Quadrilateral* q1 = new Square(5);
    Quadrilateral* q2 = new Square();

    cout << "Enter a side length for a square: ";
    q2->read(cin);

    cout << "Area of q1: " << q1->area() << endl;
    cout << "Perimeter of q1: " << q1->perimeter() << endl;
    cout << "q1: ";
    q1->print(cout);
    cout << endl;

   cout << "Area of q2: " << q2->area() << endl;
   cout << "Perimeter of q2: " << q2->perimeter() << endl;
   cout << "q2: ";
   q2->print(cout);
   cout << endl;

   delete q1;
   delete q2;

return 0;
    
}
