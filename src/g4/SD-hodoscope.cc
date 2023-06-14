#include "g4/SD-hodoscope.hh"

HodoscopeSensitiveDetector::HodoscopeSensitiveDetector(const G4String & sdName,
        const std::string & scorerName)
    : G4VSensitiveDetector(sdName)
    , _scorerName(scorerName)
    {}

void
HodoscopeSensitiveDetector::Initialize(G4HCofThisEvent* hitCollection) {
    // ... TODO: init collections to accumulate energy deposition per slab
}

G4bool
HodoscopeSensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory* history) {
    // omit neutral particles
    //if( step->GetTrack()->GetDefinition()->GetPDGCharge() == 0. ) return true;
    // get deposited energy
    G4double eDep = step->GetTotalEnergyDeposit() - step->GetNonIonizingEnergyDeposit();
    G4double stepLength = step->GetStepLength();
    // get slab number relying on replica ID
    G4int slabNumber = step
                      ->GetPreStepPoint()
                      ->GetTouchable()
                      ->GetReplicaNumber(0);

    // ... TODO: add to scorer
    G4cout << ">>> got hodoscope hit at slab #" << slabNumber
        << " with energy " << eDep/CLHEP::MeV << "MeV"
        << std::endl;  // XXX

    return true;
}

void
HodoscopeSensitiveDetector::EndOfEvent(G4HCofThisEvent* hitCollection) {
    // ... TODO: reset scorers, store result
}

