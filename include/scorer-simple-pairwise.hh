#ifndef H_SCORER_PAIRWISE_SIMPLE_H
#define H_SCORER_PAIRWISE_SIMPLE_H 1

#include "scorer.hh"

typedef double Float_t;

// Pairwise sum implementation
class ScorerSimplePairwise : public iScorer {
public:
    void add(Float_t value) override;
    Float_t get() const override;
    std::vector<Float_t> elements;

    std::string get_name() const { return "scorer-pairwise"; }
};

#endif  // H_SCORER_PAIRWISE_SIMPLE_H

