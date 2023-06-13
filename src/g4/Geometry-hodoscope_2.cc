//#include <G4NistManager.hh>
//#include <G4Box.hh>
//#include <G4LogicalVolume.hh>
//#include <G4PVPlacement.hh>
//#include <G4PVReplica.hh>
//
//#include "g4/Geometry-hodoscope_2.hh"
//
//G4LogicalVolume *
//create_hodoscope( bool checkOverlaps ) {
//    // NOTE: albeit `checkOverlaps' is not used here, for more elaborated
//    // examples it can be used still, when placements appear
//    float sensitiveAreaWidth  = 10*CLHEP::cm
//        , sensitiveAreaHeight = 10*CLHEP::cm
//        , slabDepth = 1*CLHEP::cm
//        , slabDepth_1 = 3*CLHEP::cm
//        ;
//    int nSlabs = 10;
//
//    // create encompassing volume (layer):
//    // - solid
//    G4VSolid * solidHodoscopePlane_2
//        = new G4Box( "hodoscopePlane"
//                   , sensitiveAreaWidth/2
//                   , sensitiveAreaHeight/2
//                   , slabDepth/2
//                   );
//    // - logic
//    G4LogicalVolume * logicHodoscopePlane_2
//        = new G4LogicalVolume(
//                   solidHodoscopePlane_2  // its solid
//                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR")  // its material
//                 , "hodoscopePlane");
//    
//    // Create single slab
//    // - solid (single slab)
//    G4VSolid * solidHodoscopeSlab_2
//        = new G4Box( "hodoscopeSlab"
//                   , (sensitiveAreaWidth/nSlabs)/2.
//                   , sensitiveAreaHeight/2
//                   , slabDepth/2
//                   );
//    // - logc (single slab)
//    G4LogicalVolume * logicHodoscopeSlab_2
//        = new G4LogicalVolume(
//                   solidHodoscopeSlab_2  // its solid
//                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR")  // its material, TODO
//                 , "hodoscopeSlab_1");   // its name
//    // - replica
//    new G4PVReplica( "hodoscopeSlabReplicae_2"  // name
//                , logicHodoscopeSlab_2  // logical vol to replicate
//                , logicHodoscopePlane_2 // mother logical volume (encompassing volume)
//                , kXAxis  // replication axis (we divide width here, so X)
//                , nSlabs  // # replicas
//                , sensitiveAreaWidth/nSlabs  // width of replica (stride)
//                );
//
//////    G4VSolid * solidHodoscopePlane_mom
//////        = new G4Box( "hodoscopePlane"
//////                   , sensitiveAreaWidth/2
//////                   , sensitiveAreaHeight/2
//////                   , slabDepth_1/2
//////                   );
////    // - logic
////    G4LogicalVolume * logicHodoscopePlane_mom
////        = new G4LogicalVolume(
////                   solidHodoscopePlane_mom  // its solid
////                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR")  // its material
////                 , "hodoscopePlane");
//    
//////        Размещение
//////         - placement
////    new G4PVPlacement(
////          new G4RotationMatrix(90.*CLHEP::degree, 0, 0)
////        , G4ThreeVector(0,0,0)        // at (0,0,0)
////        , logicHodoscopePlane_1    // its logical volume
////        , "hodoscopePlane_1"       // its name
////        , logicHodoscopePlane   // its mother  volume
////        , false                  // no boolean operation
////        , 0                      // copy number
////        , checkOverlaps );        // checking overlaps
////    
////    new G4PVPlacement(
////          new G4RotationMatrix(90.*CLHEP::degree, 0, 0)
////        , G4ThreeVector(0,0,slabDepth_1/3)        // at (0,0,0)
////        , logicHodoscopePlane_1    // its logical volume
////        , "hodoscopePlane_2"       // its name
////        , logicHodoscopePlane_mom   // its mother  volume
////        , false                  // no boolean operation
////        , 0                      // copy number
////        , checkOverlaps );        // checking overlaps
//    
//    return logicHodoscopePlane_2;
//}
////
