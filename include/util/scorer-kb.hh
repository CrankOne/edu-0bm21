#ifndef H_SCORER_KAHAN_BABUSKA_H
#define H_SCORER_KAHAN_BABUSKA_H 1
#include <string>
#include "scorer.hh"

// Pairwise sum implementation
class ScorerKB : public iScorer {
private:
    double e;
    Float_t sum;
public:
    void add(Float_t value) override;
    Float_t get() const override;
    std::string get_name() const override;

    ScorerKB() : e(0), sum(0) {}
    virtual ~ScorerKB() {}
};

#endif  // H_SCORER_KAHAN_BABUSKA_H
