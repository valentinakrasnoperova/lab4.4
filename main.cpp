#include <iostream>
#include <cmath>

using namespace std;

class Function {
public:
    virtual float func() const = 0;
};

class Ellipse : public Function {
    float x, a, b;
public:
    Ellipse() : x(0), a(0), b(0) {}
    Ellipse(float x1, float a1, float b1) : x(x1), a(a1), b(b1) {}
    virtual float func() const {
        return b * sqrt(1- pow(x,2)/ pow(a,2));
    }
};

class Hyperbola : public Function {
    float x, a, b;
public:
    Hyperbola() : x(0), a(0), b(0) {}
    Hyperbola(float x1, float a1, float b1) : x(x1), a(a1), b(b1) {}
    virtual float func() const {
        return b * sqrt(pow(x, 2) /pow(a, 2) - 1);
    }
};



int main() {
    Function * mas[2];
    mas[0] = new Ellipse(3, 4, 6);
    mas[1] = new Hyperbola(27, 2, 3 );
    cout << "1-Еліпс"  << endl << "2-Гіпербола"<< endl;
    for (int i = 0; i < 4; i++) { //Для перевірки використовую массив посилань на абстрактний клас, яким присвоюю адреса різних об'єктів
        cout << "Значення функції номер " << i + 1 << " = " << mas[i]->func() << endl;

    }

}
