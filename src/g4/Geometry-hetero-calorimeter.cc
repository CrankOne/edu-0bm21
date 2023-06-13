#include <G4NistManager.hh>
#include <G4Box.hh>
#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4PVReplica.hh>

#include "g4/Geometry-hetero-calorimeter.hh"

G4LogicalVolume *
create_hetero_calorimeter( bool checkOverlaps ) {
    // NOTE: albeit `checkOverlaps' is not used here, for more elaborated
    // examples it can be used still, when placements appear
    float sensitiveAreaWidth  = 3*CLHEP::cm
        , sensitiveAreaHeight = 3*CLHEP::cm
        , slabDepth = 0.3*CLHEP::cm
        ;
    int nSlabs = 100;
    int nCells = 6;

    // create encompassing volume (layer):
    // - solid
    G4VSolid * solidCalorimeterPlane
        = new G4Box( "calorimeterPlane"
                   , sensitiveAreaWidth/2
                   , sensitiveAreaHeight/2
                   , slabDepth*nSlabs/2
                   );

    // - logic
    G4LogicalVolume * logicCalorimeterPlane
        = new G4LogicalVolume(
                   solidCalorimeterPlane  // its solid
                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR")  // its material
                 , "calorimeterPlane");   // its name

    // create calorimeter row volume
    // - solid
    G4VSolid * solidCalorimeterRow
        = new G4Box( "calorimeterRow"
                 , sensitiveAreaWidth * nCells/2
                 , sensitiveAreaHeight/2
                 , slabDepth*nSlabs/2
                 );
    // - logic
    G4LogicalVolume * logicCalorimeterRow
        = new G4LogicalVolume(
                   solidCalorimeterRow  // its solid
                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR")  // its material
                 , "calorimeterRow");   // its name

    // create calorimeter whole volume
    // - solid
    G4VSolid * solidCalorimeterWhole
        = new G4Box( "calorimeterWhole"
                 , sensitiveAreaWidth * nCells/2
                 , sensitiveAreaHeight * nCells/2
                 , slabDepth*nSlabs/2
                 );
    // - logic
    G4LogicalVolume * logicCalorimeterWhole
        = new G4LogicalVolume(
                   solidCalorimeterWhole  // its solid
                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR")  // its material
                 , "calorimeterWhole");   // its name

    // Create single slab
    // - solid (absorber plane)
    G4VSolid * AbsorberCalorimeterPlane
        = new G4Box( "absorberPlane"
                   , sensitiveAreaWidth/2
                   , sensitiveAreaHeight/2
                   , slabDepth/3
                   );
    // - logic (absorber plane)
    G4LogicalVolume * logicAbsorberPlane
        = new G4LogicalVolume(
                    AbsorberCalorimeterPlane
                  , G4NistManager::Instance()->FindOrBuildMaterial("G4_Pb")  // its material
                  , "absorberPlane");
    // - solid (scintillator plane)
    G4VSolid * ScintillatorCalorimeterPlane
        = new G4Box( "scintillatorPlane"
                   , sensitiveAreaWidth/2
                   , sensitiveAreaHeight/2
                   , slabDepth/6
                   );
    // - logic (scintillator plane)
    G4LogicalVolume * logicScintillatorPlane
        = new G4LogicalVolume(
                     ScintillatorCalorimeterPlane
                   , G4NistManager::Instance()->FindOrBuildMaterial("G4_PLEXIGLASS")  // its material
                   , "scintillatorPlane");



    // - placement

    // Create single slab
    // - solid (single slab)
    G4VSolid * solidCalorimeterSlab
        = new G4Box( "calorimeterSlab"
                   , (sensitiveAreaWidth)/2.
                   , sensitiveAreaHeight/2
                   , (slabDepth)/2
                   );
    // - logic (single slab)
    G4LogicalVolume * logicCalorimeterSlab
        = new G4LogicalVolume(
                   solidCalorimeterSlab  // its solid
                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR")  // its material, TODO
                 , "calorimeterSlab");   // its name
    // - absorber slab placement
    new G4PVPlacement(nullptr  // no rotation
                 , G4ThreeVector(0,0,-slabDepth/6)        // at (0,0,0)
                 , logicAbsorberPlane    // its logical volume
                 , "absorberPlane"       // its name
                 , logicCalorimeterSlab  // its mother  volume
                 , false                  // no boolean operation
                 , 0                      // copy number
                 , checkOverlaps );        // checking overlaps
    // - scintillator slab placement
    new G4PVPlacement(nullptr  // no rotation
                 , G4ThreeVector(0,0,slabDepth/3)        // at (0,0,0)
                 , logicScintillatorPlane    // its logical volume
                 , "scintillatorPlane"       // its name
                 , logicCalorimeterSlab  // its mother  volume
                 , false                  // no boolean operation
                 , 0                      // copy number
                 , checkOverlaps );        // checking overlaps

    // - replica
    new G4PVReplica( "calorimeterSlabReplica"  // name
                , logicCalorimeterSlab  // logical vol to replicate
                , logicCalorimeterPlane // mother logical volume (encompassing volume)
                , kZAxis  // replication axis (we divide width here, so Z)
                , nSlabs  // # replicas
                , slabDepth  // width of replica (stride)
                );
    // - Replica for Row
    new G4PVReplica( "calorimeterReplicaRow"  // name
                , logicCalorimeterPlane  // logical vol to replicate
                , logicCalorimeterRow // mother logical volume (encompassing volume)
                , kXAxis  // replication axis (we divide width here, so Z)
                , nCells  // # replicas
                , sensitiveAreaWidth  // width of replica (stride)
                );

    // - Replica for Row
    new G4PVReplica( "calorimeterReplicaWhole"  // name
                , logicCalorimeterRow  // logical vol to replicate
                , logicCalorimeterWhole // mother logical volume (encompassing volume)
                , kYAxis  // replication axis (we divide width here, so Z)
                , nCells  // # replicas
                , sensitiveAreaHeight  // width of replica (stride)
                );

    return logicCalorimeterWhole;
}

