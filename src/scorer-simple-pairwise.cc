#include "scorer-simple-pairwise.hh"

void
ScorerSimplePairwise::add(Float_t value) {
  elements.push_back(value);
}

Float_t
ScorerSimplePairwise::get() const {
  Float_t sum = 0.;
  for (int i = 0; i < elements.size(); i+=2) {
    sum += elements[i];
    sum += elements[i+1];
  }
  return sum;
}
std::string
ScorerSimplePairwise::get_name() const {
  return "Simple Pairwise Scorer by BeHckuU";
}
