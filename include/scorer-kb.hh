#ifndef H_SCORER_KAHAN_BABUSKA_H
#define H_SCORER_KAHAN_BABUSKA_H 1

#include "scorer.hh"

// Pairwise sum implementation
class ScorerKB : public iScorer {
public:
    void add(Float_t value);
    Float_t get() const;
    double e = 0;
private:
    Float_t sum = 0;
};

#endif  // H_SCORER_KAHAN_BABUSKA_H
