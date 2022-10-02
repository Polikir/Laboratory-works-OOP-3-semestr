
#ifndef SEM_3_LABA1_COMPLEX_H
#define SEM_3_LABA1_COMPLEX_H


#pragma once
#include<cmath>
#include <iomanip>

class complex {
private:
    float x;
    float y;

public:

    complex() {
        x = 0;
        y = 0;
    }

    complex(float real, float imagine) {
        x = real;
        y = imagine;
    }

    complex(const complex &ob) {
        x = ob.x;
        y = ob.y;
    };

    float real() const {
        return this->x;
    }

    float imag() const {
        return this->y;
    }

    complex operator+(float val) const {
        return complex(this->x + val, this->y);
    }

    complex operator-(float val) const {
        return complex(this->x - val, this->y);
    }

    complex operator+(const complex &val) const {
        return complex(this->x + val.x, this->y + val.y);
    }

    complex operator-(const complex &val) const {
        return complex(this->x - val.x, this->y - val.y);
    }


    complex operator*(float val) const {
        return complex(this->x * val, this->y * val);
    }


    complex operator*(complex val) const {
        return complex(this->x * val.x - this->y * val.y, this->x * val.y + this->y * val.x);
    }

    bool operator==(const complex& val) const {
        return this->x == val.real() && this->y == val.imag();
    }

    bool operator>(const complex& val) const {
        return this->x > val.real();
    }

    bool operator<(const complex& val) const {
        return this->x < val.real();
    }

    bool operator!=(const complex& val) const {
        return !this->operator==(val);
    }

    float abs_complex() {
        float r = this->x;
        float i = this->y;
        float res = sqrt(r * r + i * i);
        return res;
    }

    int Sign(float im) {
        if (im < 0) { return -1; }
        if (im > 0) { return 1; }
        return 0;
    }

    complex sqrt_complex() {
        float re = this->x;
        float im = this->y;
        re = ::sqrt((::sqrt(re * re + im * im) + re) / 2);
        im = float(Sign(im)) * (::sqrt((::sqrt(re * re + im * im) - re) / 2));
        return complex(re, im);
    }

    void print_complex() const {
        cout << this->x <<"+ (" << this->y << ")" << "i" << setw(3);
    }

};



#endif //SEM_3_LABA1_COMPLEX_H
