#include "../include/scorer.hh"
#include <iostream>

void Scorer::add(Float_t value) {

    const Float_t y = value - e;
    const Float_t t = sum + y;
    e = (t - sum) - y;
    // std::cout.precision(15);
    // if (value > (1e7 - 5)) std::cout << y << " " << t << " " << e << "\n";
    sum = t;
}

Float_t Scorer::get() const {
    return sum;
}

/*void Scorer::add(Float_t value) {
    Float_t coef = 0;
    if (value != 0 || sum != 0) coef = (value/sum);
    //if (value > (1e7 - 5))
    //std::cout << coef << "\n";
    if ((coef< 10 && coef > 0.1) || value == 0 || sum == 0) {
        sum += value;
    }
    else {
        if (sum < value) {
            while (value >= sum * coef){
                sum += value / coef;
                value -= value / coef;
            }
        }
        else {
            Float_t buffer = sum;
            Float_t val_buf = value;
            while (buffer >= 1e6) {
                val_buf += buffer * coef;
                buffer -= buffer * coef;

                if (value > (1e7 - 2)) std::cout << "Buffer: "<< buffer << " value " << val_buf << "\n";
            }
            sum = val_buf;
        }
    }
}
*/
