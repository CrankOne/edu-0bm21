#include <iostream>
#include <cmath>

#include "scorer-kb.hh"
#include "scorerP.hh"
#include "scorer-simple-pairwise.hh"

int
main(int argc, char * argv[]) {
    #if 0
    iScorer * scorers[] = {
          new ScorerKB
        , new ScorerP
        , new ScorerSimplePairwise
        , nullptr  // sentinel
    };

    #if 1

    float ctrl = 0.;
    unsigned long ctrl2 = 0;
    for(int i = 1e7; i; --i) {
        ctrl  += i;
        ctrl2 += i;
        for(iScorer ** cs = scorers; *cs; ++cs) {
            (*cs)->add(i);
        }
    }
    std::cout << "float ctrl = " << ctrl  << std::endl
              << "  int ctrl = " << ctrl2 << std::endl;
    for(iScorer ** cs = scorers; *cs; ++cs) {
        std::cout << " " << (void*) *cs << " = " <<  (*cs)->get()
                  << "(diff " << (ctrl2 - ((double) (*cs)->get())) << ")"
                  << std::endl;
    }

    //<< "  diff = " << std::fabs(ctrl - s.get()) << std::endl;
    #endif
    #endif
    return 0;
}
