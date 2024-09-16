#include <iostream>
#include <cmath>

class Shape {
public:
    virtual float get_area() const = 0; // Méthode virtuelle pure
    virtual void print_data() const = 0; // Méthode virtuelle pure
};

class Triangle : public Shape {
private:
    float side1, side2, side3;

public:
    Triangle(float s1, float s2, float s3) : side1(s1), side2(s2), side3(s3) {}

    float get_area() const override {
        float d = (side1 + side2 + side3) / 2.f;
        return sqrtf(d * (d - side1) * (d - side2) * (d - side3));
    }

    void print_data() const override {
        std::cout << "Triangle: " << std::endl;
        std::cout << "Sides: " << side1 << ", " << side2 << ", " << side3 << std::endl;
        std::cout << "Area: " << get_area() << std::endl;
    }
};
