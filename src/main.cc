#include <iostream>
#include <cmath>

#include "../include/scorer.hh"

int main(int argc, char * argv[]) {
    Scorer s;

    float ctrl = 0.;
    for(int i = 0; i < (int) 1e7; ++i) {
        ctrl += i;
        s.add(i);
        std::cout.precision(15);
        // if (i % 100000 == 0 || i == (1e7 - 1)) std::cout << "step " << i << " " << s.get() << "\n";
    }
    std::cout << "  ctrl = " << ctrl << std::endl
              << "scorer = " << s.get() << std::endl
              << "  diff = " << std::fabs(ctrl - s.get()) << std::endl;
    return 0;
}
