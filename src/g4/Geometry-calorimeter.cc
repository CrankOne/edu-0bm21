//#include <G4NistManager.hh>
//#include <G4Box.hh>
//#include <G4LogicalVolume.hh>
//#include <G4PVPlacement.hh>
//#include <G4PVReplica.hh>
//
//#include "g4/Geometry-calorimeter.hh"
//
//G4LogicalVolume *
//create_calorimeter( bool checkOverlaps ) {
//    // NOTE: albeit `checkOverlaps' is not used here, for more elaborated
//    // examples it can be used still, when placements appear
//    float sensitiveAreaWidth  = 3*CLHEP::cm
//        , sensitiveAreaHeight = 3*CLHEP::cm
//        , slabDepth = 3*CLHEP::mm
//        , slabDepth_1 = 3*CLHEP::cm
//        , slabDepth_pb = 2*CLHEP::mm
//        , slabDepth_air = 1*CLHEP::mm
//        ;
//    int nSlabs = 5;
//
//    //  объем для размещения
//    // create encompassing volume (layer):
//    // - solid
//    G4VSolid * solidCalorimeterPlane
//        = new G4Box( "calorimeterPlane"
//                   , sensitiveAreaWidth/2
//                   , sensitiveAreaHeight/2
//                   , slabDepth/2
//                   );
//    // - logic
//    G4LogicalVolume * logicCalorimeterPlane
//        = new G4LogicalVolume(
//                   solidCalorimeterPlane  // its solid
//                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_Air")  // its material
//                 , "calorimeterPlane");
//
//    // Cцинтиллятор
//    // - solid (single slab)
//    G4VSolid * solidScintillatorSlab
//        = new G4Box( "calorimeterScintillatorSlab"
////                   , (sensitiveAreaWidth/nSlabs)/2.
//                   ,sensitiveAreaWidth/2
//                   , sensitiveAreaHeight/2
//                   , slabDepth_air/2
//                   );
//    
//    // - logc (single slab)
//    G4LogicalVolume * logicScintillatorSlab
//        = new G4LogicalVolume(
//                   solidScintillatorSlab // its solid
//                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_PLEXIGLASS")  // its material, TODO
//                 , "calorimeterScintillatorSlab");   // its name
//
//    
//    // Свинец
//    G4VSolid * solidPbSlab
//        = new G4Box( "calorimeterPbSlab"
////                   , (sensitiveAreaWidth/nSlabs)/2.
//                   ,sensitiveAreaWidth/2
//                   , sensitiveAreaHeight/2
//                   , slabDepth_pb/2
//                   );
//    
//    // - logc (single slab)
//    G4LogicalVolume * logicPbSlab
//        = new G4LogicalVolume(
//                   solidPbSlab // its solid
//                 , G4NistManager::Instance()->FindOrBuildMaterial("-")  // its material, TODO
//                 , "calorimeterPbSlab");   // its name
//
//    // Размещение сцинтилятора
//    // - placement
//    new G4PVPlacement(nullptr  // no rotation
//        , G4ThreeVector(0,0,-slabDepth/3)        // at (0,0,0)
//        , logicScintillatorSlab    // its logical volume
//        , "calorimeterSlab"       // its name
//        , logicCalorimeterPlane   // its mother  volume
//        , false                  // no boolean operation
//        , 0                      // copy number
//        , checkOverlaps );        // checking overlaps
//
//    // Размещение поглотителя
//    // - placement
//    new G4PVPlacement(nullptr  // no rotation
//        , G4ThreeVector(0,0,slabDepth/6)        // at (0,0,0)
//        , logicPbSlab    // its logical volume
//        , "calorimeterSlab"       // its name
//        , logicCalorimeterPlane   // its mother  volume
//        , false                  // no boolean operation
//        , 0                      // copy number
//        , checkOverlaps );        // checking overlaps
//
//    // Материнский объем калориметра
//    G4VSolid * solidCalorimeterPill
//        = new G4Box( "calorimeterPillPlane"
//                   , sensitiveAreaWidth/2
//                   , sensitiveAreaHeight/2
//                   , slabDepth_1/2
//                   );
//    // - logic
//    G4LogicalVolume * logicCalorimeterPill
//        = new G4LogicalVolume(
//                   solidCalorimeterPill  // its solid
//                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_Air")  // its material
//                 , "calorimeterPlane");
//    
//    
//    //  - replica
//    new G4PVReplica( "calorimeterSlabReplicae"  // name
//                , logicCalorimeterPlane  // logical vol to replicate
//                , logicCalorimeterPill // mother logical volume (encompassing volume)
//                , kZAxis  // replication axis (we divide width here, so X)
//                , nSlabs  // # replicas
//                , 3*CLHEP::mm  // width of replica (stride)
//                );
//    
//    return logicCalorimeterPill;
//}

