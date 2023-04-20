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

#endif  // H_SCORER_H

