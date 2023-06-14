#pragma once

#include <G4VUserDetectorConstruction.hh>

// This class implements interface defined in `G4VUserDetectorConstruction`.
// The main function of `G4VUserDetectorConstruction` interface that has to
// be defined is `DetectorConstruction::Construct()`. It shall create
// simulation geometry and return pointer to topmost volume in the hierarchy.
class DetectorConstruction : public G4VUserDetectorConstruction {
public:
    // implements interface's abstract method -- creates geometry and returns
    // topmost volume in the hierarchy
    G4VPhysicalVolume* Construct() override;

    // overrides virtual method -- constructs and binds sensitive detector
    // instances with certain volumes
    void ConstructSDandField() override;

    // ctr
    DetectorConstruction(bool doCheckOverlaps, const std::string & scorerName);
private:
    bool _doCheckOverlaps;
    const std::string _scorerName;
};  // class DetectorConstruction

