#pragma once

#include "G4VSensitiveDetector.hh"

class CaloSensitiveDetector : public G4VSensitiveDetector {
public:
    CaloSensitiveDetector(const G4String & sdName);

    void Initialize(G4HCofThisEvent* hitCollection) override;
    G4bool ProcessHits(G4Step* step, G4TouchableHistory* history) override;
    void EndOfEvent(G4HCofThisEvent* hitCollection) override;
};  // class SensitiveDetector

