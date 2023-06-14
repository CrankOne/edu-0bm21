#pragma once

#include "G4VSensitiveDetector.hh"

class iScorer;

class CaloSensitiveDetector : public G4VSensitiveDetector {
private:
    /// Name of the scorer subclass in use
    std::string _scorerName;
    // ... TODO: std::vector<iScorer *> _scorers; or something
public:
    CaloSensitiveDetector(const G4String & sdName, const std::string & scorerName);

    void Initialize(G4HCofThisEvent* hitCollection) override;
    G4bool ProcessHits(G4Step* step, G4TouchableHistory* history) override;
    void EndOfEvent(G4HCofThisEvent* hitCollection) override;
};  // class SensitiveDetector

