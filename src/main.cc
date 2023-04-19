#include <iostream>
#include <cmath>

#include "scorer-kb.hh"
#include "scorer-simple-pairwise.hh"

int main(int argc, char * argv[]) {
    ScorerKB skb;
    ScorerSimplePairwise ssp;

    #if 0
    iScorer s;

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
    #endif
    return 0;
}
