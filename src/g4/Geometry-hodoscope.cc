#include <G4NistManager.hh>
#include <G4Box.hh>
#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4PVReplica.hh>

#include "g4/Geometry-hodoscope.hh"

G4LogicalVolume *
create_hodoscope( bool checkOverlaps ) {
    // NOTE: albeit `checkOverlaps' is not used here, for more elaborated
    // examples it can be used still, when placements appear
    float sensitiveAreaWidth  = 10*CLHEP::cm
        , sensitiveAreaHeight = 10*CLHEP::cm
        , slabDepth = 1*CLHEP::cm
        ;
    int nSlabs = 10;

    // create encompassing volume (layer):
    // - solid
    G4VSolid * solidHodoscopePlane
        = new G4Box( "hodoscopePlane"
                   , sensitiveAreaWidth/2
                   , sensitiveAreaHeight/2
                   , slabDepth/2
                   );
    // - logic
    G4LogicalVolume * logicHodoscopePlane
        = new G4LogicalVolume(
                   solidHodoscopePlane  // its solid
                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR")  // its material
                 , "hodoscopePlane");   // its name
    // - placement
    //new G4PVPlacement(nullptr  // no rotation
    //    , G4ThreeVector()        // at (0,0,0)
    //    , logicHodoscopePlane    // its logical volume
    //    , "hodoscopePlane"       // its name
    //    , parentLogicVolumePtr   // its mother  volume
    //    , false                  // no boolean operation
    //    , 0                      // copy number
    //    , checkOverlaps );        // checking overlaps


    // Create single slab
    // - solid (single slab)
    G4VSolid * solidHodoscopeSlab
        = new G4Box( "hodoscopeSlab"
                   , (sensitiveAreaWidth/nSlabs)/2.
                   , sensitiveAreaHeight/2
                   , slabDepth/2
                   );
    // - logc (single slab)
    G4LogicalVolume * logicHodoscopeSlab
        = new G4LogicalVolume(
                   solidHodoscopeSlab  // its solid
                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR")  // its material, TODO
                 , "hodoscopeSlab");   // its name
    // - replica
    new G4PVReplica( "hodoscopeSlabReplicae"  // name
                , logicHodoscopeSlab  // logical vol to replicate
                , logicHodoscopePlane // mother logical volume (encompassing volume)
                , kXAxis  // replication axis (we divide width here, so X)
                , nSlabs  // # replicas
                , sensitiveAreaWidth/nSlabs  // width of replica (stride)
                );
    return logicHodoscopePlane;
}

