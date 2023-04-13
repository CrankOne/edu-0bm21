#include "scorer.hh"

#include <algorithm>

Scorer::Scorer(unsigned char tierCapacity)
        : _nValues(1 << tierCapacity) {}

static std::pair<bool, Float_t>
_add_to_tier(Float_t * values, Float_t val, size_t c, size_t maxLen) {
    // check number of elements at current tier
    if((++c) == maxLen) {
        // tier is full, calculate sum and collapse
        std::sort(values, values + maxLen, std::greater<Float_t>());
        // iterate with fixed stride calculating sums till the full tier
        // capacity is depleted
        size_t stride = 1;
        while(stride != maxLen) {
            for(std::size_t i = 0; i < maxLen; i += (stride << 1)) {
                values[i] += values[i + stride]
            }
            stride <<= 1;
        }
        // here all the values must be summed up in the first element
        return {true, values[0]};
    }
    values[c]
    return {false, 0};
}

void
Scorer::add(Float_t value) {
    auto it = _sums.begin();
    auto r = _add_to_tier(it->first, value, it->second, _nValues);
    if(!r.first) {
        ++(it->second);
        return;
    }
}

Float_t
Scorer::get() const {
    // ...
}

