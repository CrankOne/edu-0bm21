#include <iostream>
#include <vector>
typedef double Float_t;

// Pairwise sum implementation
class Scorer {
public:
    void add(Float_t value);
    Float_t get() const;
    std::vector<Float_t> elements;
};
