
typedef double Float_t;
#include <vector>


// Pairwise sum implementation
class Scorer {
public:
    void add(Float_t value);
    Float_t get() const;
    double e = 0;
private:
    Float_t sum = 0;
};
