#include <vector>

typedef double Float_t;

// Pairwise sum implementation
class Scorer {
private:
    std::size_t _nValues;
    std::vector< std::pair<Float_t *, std::size_t> > _sums;
public:
    Scorer(unsigned char tierCapacity);

    ~Scorer();

    void add(Float_t value);
    Float_t get() const;
};

