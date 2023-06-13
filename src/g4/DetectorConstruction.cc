#include "g4/DetectorConstruction.hh"

#include <G4NistManager.hh>
#include <G4Box.hh>
#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4SDManager.hh>

// include here your supplementary setup geometries, for instance
// - hodoscope
#include "g4/Geometry-hodoscope.hh"
#include "g4/SD-hodoscope.hh"
// - calorimeter
#include "g4/Geometry-calorimeter.hh"
#include "g4/SD-calorimeter.hh"

DetectorConstruction::DetectorConstruction( bool doCheckOverlaps )
    : _doCheckOverlaps(doCheckOverlaps) {
}

G4VPhysicalVolume *
DetectorConstruction::Construct() {
    // Create topmost (world) volume
    // - solid
    G4VSolid * solidHall = new G4Box( "World"  // name
            , 1*CLHEP::m/2  // size x
            , 1*CLHEP::m/2  // size y
            , 25.1*CLHEP::m/2  // size z
            );
    // - logical volume -- a solid filled with certain material
    G4LogicalVolume * logicHall = new G4LogicalVolume( solidHall  // solid (to fill)
            , G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR")  // material (to fill with)
            , "World"  // name of logic
            );
    // - physical volume -- a logical volume logical volume placed somewhere
    G4VPhysicalVolume * physHall = new G4PVPlacement(
              nullptr  // pointer to rotation matrix (null means "no rotation")
            , G4ThreeVector(0, 0, 0)  // position relative to parent
            , logicHall  // logical volume under operation
            , "World"  // logical volume name
            , nullptr  // mother volume name (null for topmost in hierarchy)
            , false  // `false' if no boolean operation should be applied
            , 0  // copy number
            , _doCheckOverlaps
            );

    #if 1
    // ... TODO: create other geometry here, for instance:
    G4LogicalVolume * logicHodoscope = create_hodoscope( _doCheckOverlaps );
    new G4PVPlacement(
              nullptr  // rotation matrix (no rotation)
            , G4ThreeVector(0, 0, 0)  // at (0,0,0)
            , logicHodoscope  // its logical volume
            , "hodoscope"  // its name
            , logicHall  // its mother volume
            , false  // no boolean operation
            , 0  // copy number
            , _doCheckOverlaps  // checking overlaps
            );
    #endif

    #if 0
    // ... TODO: create other geometry here, for instance:
    G4LogicalVolume * logicCalorimeter = create_calorimeter( _doCheckOverlaps );
    new G4PVPlacement(
              nullptr  // rotation matrix (no rotation)
            , G4ThreeVector(0, 0, 0)  // at (0,0,0)
            , logicHodoscope  // its logical volume
            , "hodoscope"  // its name
            , logicHall  // its mother volume
            , false  // no boolean operation
            , 0  // copy number
            , _doCheckOverlaps  // checking overlaps
            );
    #endif

    // return ptr to topmost (world) volume
    return physHall;
}

void
DetectorConstruction::ConstructSDandField() {
    #if 1
    auto hodoSD = new HodoscopeSensitiveDetector("hodoX");
    G4SDManager::GetSDMpointer()->AddNewDetector(hodoSD);
    SetSensitiveDetector( "hodoscopeSlab"  //< Note: must exist
                        , hodoSD
                        );
    #endif

    #if 0
    // ... TODO: bind calorimeter sensitive detector with scintillator volume
    auto caloSD = new CaloSensitiveDetector("caloScint");
    G4SDManager::GetSDMpointer()->AddNewDetector(hodoSD);
    SetSensitiveDetector( "caloScintVolume"  //< Note: must exist
                        , hodoSD
                        );
    #endif
}

