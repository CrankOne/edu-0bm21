#include "scorer.hh"

#include <vector>
typedef double Float_t;

// Pairwise sum implementation
class ScorerP : public iScorer {
protected:
    std::vector <Float_t> data;
public:
    Float_t two_sum(Float_t &t, Float_t a, Float_t b) const;

    void add(Float_t value) override;
    Float_t get() const override;
    std::string get_name() const override { return "scorer p"; }

    virtual ~ScorerP() {}
};

