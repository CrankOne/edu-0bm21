#ifndef H_SCORER_H
#define H_SCORER_H 1

#include <vector>
#include <string>

typedef double Float_t;

// Pairwise sum implementation
struct iScorer {
    virtual void add(Float_t value) = 0;
    virtual Float_t get() const = 0;
    virtual std::string get_name() const = 0;
};

// Factory method: instantiates particular scorer class, returns ptr to a new
// instance
iScorer * create_scorer(const std::string &);

#endif  // H_SCORER_H

