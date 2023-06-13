#include "g4/SD-calorimeter.hh"
#include "G4Types.hh"

CaloSensitiveDetector::CaloSensitiveDetector(const G4String & sdName)
    : G4VSensitiveDetector(sdName)
    {}

void
CaloSensitiveDetector::Initialize(G4HCofThisEvent* hitCollection) {
    // ... TODO: init collections to accumulate energy deposition per slab
}

G4bool
CaloSensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory* history) {
    // omit neutral particles
    //if( step->GetTrack()->GetDefinition()->GetPDGCharge() == 0. ) return true;
    // get deposited energy
    G4double eDep = step->GetTotalEnergyDeposit() - step->GetNonIonizingEnergyDeposit();
    G4double stepLength = step->GetStepLength();
    // get slab number relying on replica ID
    G4int layerNumber = step
                      ->GetPreStepPoint()
                      ->GetTouchable()
                      ->GetReplicaNumber(1);
    // ... TODO: add to scorer
    return true;
}

void
CaloSensitiveDetector::EndOfEvent(G4HCofThisEvent* hitCollection) {
    // ... TODO: reset scorers, store result
}

