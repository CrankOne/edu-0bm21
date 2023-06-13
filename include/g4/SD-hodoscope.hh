#pragma once

#include <G4VSensitiveDetector.hh>

#include "util/scorer.hh"

class HodoscopeSensitiveDetector : public G4VSensitiveDetector {
public:
    HodoscopeSensitiveDetector(const G4String & sdName);

    void Initialize(G4HCofThisEvent* hitCollection) override;
    G4bool ProcessHits(G4Step* step, G4TouchableHistory* history) override;
    void EndOfEvent(G4HCofThisEvent* hitCollection) override;
private:
    std::map<G4int, iScorer *> _scorers;
};  // class SensitiveDetector

