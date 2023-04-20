#include "scorerP.hh"

void ScorerP::add(Float_t value) { data.push_back(value); }

Float_t ScorerP::get() const {
  Float_t s = 0.0, c = 0.0, t;
  for (Float_t x : data) {
    s = two_sum(t, s, x);
    c += t;
  }
  return s + c;
}

Float_t ScorerP::two_sum(Float_t &t, Float_t a, Float_t b) const {
  Float_t s = a + b;
  Float_t bs = s - a;
  Float_t as = s - bs;
  t = (b - bs) + (a - as);
  return s;
}
std::string ScorerP::get_name() const {
    return typeid(*this).name();
}
