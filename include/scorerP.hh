#include <vector>
typedef double Float_t;

// Pairwise sum implementation
class Scorer {
public:
    std::vector <Float_t> data;

    void add(Float_t value);
    Float_t get();
    Float_t two_sum(Float_t &t, Float_t a, Float_t b);
};

