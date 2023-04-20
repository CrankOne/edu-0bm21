#include "scorerP.hh"

void Scorer::add(Float_t value) { data.push_back(value); }

Float_t Scorer::get() {
  Float_t s = 0.0, c = 0.0, t;
  for (Float_t x : data) {
    s = two_sum(t, s, x);
    c += t;
  }
  return s + c;
}
Float_t Scorer::two_sum(Float_t &t, Float_t a, Float_t b) {
  Float_t s = a + b;
  Float_t bs = s - a;
  Float_t as = s - bs;
  t = (b - bs) + (a - as);
  return s;
}
