#include <G4NistManager.hh>
#include <G4Box.hh>
#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4PVReplica.hh>

#include "g4/Geometry-homo-calorimeter.hh"

G4LogicalVolume *
create_homo_calorimeter( bool checkOverlaps ) {
    // NOTE: albeit `checkOverlaps' is not used here, for more elaborated
    // examples it can be used still, when placements appear
    float sensitiveAreaWidth  = 3*CLHEP::cm
        , sensitiveAreaHeight = 2*CLHEP::cm
        , slabDepth = 10*CLHEP::cm
        ;
    //int nSlabs = 10;
    //int nCells = 6;
    int nRow = 6;
    int nCol = 6;

    // create encompassing volume (layer):
    // - solid
   G4VSolid * solidcalorimeterPlane
        = new G4Box( "calorimeterPlane"
                   , sensitiveAreaWidth/2
                   , sensitiveAreaHeight/2
                   , slabDepth/2
                   );
    // - logic
    G4LogicalVolume * logiccalorimeterPlane
        = new G4LogicalVolume(
                   solidcalorimeterPlane  // its solid
                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR")  // its material
                 , "calorimeterPlane");   // its name 

    // - placement
    //new G4PVPlacement(nullptr  // no rotation
    //    , G4ThreeVector()        // at (0,0,0)
    //    , logiccalorimeterPlane    // its logical volume
    //    , "calorimeterPlane"       // its name
    //    , parentLogicVolumePtr   // its mother  volume
    //    , false                  // no boolean operation
    //    , 0                      // copy number
    //    , checkOverlaps );        // checking overlaps


    // Create single slab
    // - solid (single slab)
   /* G4VSolid * solidcalorimeterSlab
        = new G4Box( "calorimeterSlab"
                   , (sensitiveAreaWidth/nSlabs)/2.
                   , sensitiveAreaHeight/2
                   , slabDepth/2
                   );
    // - logc (single slab)
    G4LogicalVolume * logiccalorimeterSlab
        = new G4LogicalVolume(
                   solidcalorimeterSlab  // its solid
                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR")  // its material, TODO
                 , "calorimeterSlab");   // its name

    // - replica
    new G4PVReplica( "calorimeterSlabReplicae"  // name
                , logiccalorimeterSlab  // logical vol to replicate
                , logiccalorimeterPlane //, logiccalorimeterPlane // mother logical volume (encompassing volume)
                , kZAxis  // replication axis (we divide width here, so X)
                , nSlabs  // # replicas
                , sensitiveAreaWidth/nSlabs  // width of replica (stride)
                ); */

//Col
    G4VSolid * solidcalorimeterCol
        = new G4Box( "calorimeterCol"
                   , (sensitiveAreaWidth/nCol)/2
                   , sensitiveAreaHeight/2
                   , slabDepth/2
                   );
    // - logc (single slab)
    G4LogicalVolume * logiccalorimeterCol
        = new G4LogicalVolume(
                   solidcalorimeterCol // its solid
                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR")  // its material, TODO
                 , "logiccalorimeterCol");   // its name
       
    // - replica
    new G4PVReplica( "calorimeterColReplica"  // name
                , logiccalorimeterCol  // logical vol to replicate
                , logiccalorimeterPlane //, logiccalorimeterPlane // mother logical volume (encompassing volume)
                , kXAxis  // replication axis (we divide width here, so X)
                , nCol  // # replicas
                , sensitiveAreaWidth/nCol  // width of replica (stride)
                );

//Rows
    G4VSolid * solidcalorimeterRow
        = new G4Box( "calorimeterRow"
                   , (sensitiveAreaWidth/nCol)/2
                   , (sensitiveAreaHeight/nRow)/2
                   , slabDepth/2
                   );
    // - logc (single slab)
    G4LogicalVolume * logiccalorimeterRow
        = new G4LogicalVolume(
                   solidcalorimeterRow // its solid
                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR")  // its material, TODO
                 , "logiccalorimeterRow");   // its name
       
    // - replica
    new G4PVReplica( "calorimeterRowReplica"  // name
                , logiccalorimeterRow  // logical vol to replicate
                , logiccalorimeterCol //, logiccalorimeterPlane // mother logical volume (encompassing volume)
                , kYAxis  // replication axis (we divide width here, so X)
                , nRow // # replicas
                , sensitiveAreaHeight/nRow  // width of replica (stride)
                );

//Sensitive

   G4VSolid * solidcalorimeterCrystal
        = new G4Box( "calorimeterCrystal"
                   , (sensitiveAreaWidth/nCol)/2
                   , (sensitiveAreaHeight/nRow)/2
                   , slabDepth/2
                   );

    G4LogicalVolume * logiccalorimeterCrystal
        = new G4LogicalVolume(
                   solidcalorimeterCrystal  // its solid
                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_CESIUM_IODIDE")  // its material, TODO
                 , "logiccalorimeterCrystal");   // its name

    // - placement
    new G4PVPlacement(nullptr  // no rotation
       , G4ThreeVector(0,0, 0)        // at (0,0,0)
       , logiccalorimeterCrystal    // its logical volume
       , "calorimeterCrystal"       // its name
       , logiccalorimeterRow   // its mother  volume
       , false                  // no boolean operation
       , 0                      // copy number
       , checkOverlaps );        // checking overlaps


//absorber
/*
    G4VSolid * solidcalorimeterAbsorber
        = new G4Box( "calorimeterAbsorber"
                   , (sensitiveAreaWidth)/2.
                   , sensitiveAreaHeight/2
                   , (slabDepth/nSlabs)/4
                   );

    G4LogicalVolume * logiccalorimeterAbsorber
        = new G4LogicalVolume(
                   solidcalorimeterAbsorber  // its solid
                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR")  // its material, TODO
                 , "logiccalorimeterAbsorber");   // its name

    // - placement
    new G4PVPlacement(nullptr  // no rotation
       , G4ThreeVector(0,0, -(slabDepth/nSlabs)/4)        // at (0,0,0)
       , logiccalorimeterAbsorber    // its logical volume
       , "calorimeterAbsorber"       // its name
       , logiccalorimeterLayer   // its mother  volume
       , false                  // no boolean operation
       , 0                      // copy number
       , checkOverlaps );        // checking overlaps

//gap

    G4VSolid * solidcalorimeterGap
        = new G4Box( "calorimeterGap"
                   , (sensitiveAreaWidth)/2.
                   , sensitiveAreaHeight/2
                   , (slabDepth/nSlabs)/4
                   );

    G4LogicalVolume * logiccalorimeterGap
        = new G4LogicalVolume(
                   solidcalorimeterGap  // its solid
                 , G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR")  // its material, TODO
                 , "logiccalorimeterGap");   // its name

    // - placement
    new G4PVPlacement(nullptr  // no rotation
       , G4ThreeVector(0,0, (slabDepth/nSlabs)/4)        // at (0,0,0)
       , logiccalorimeterGap    // its logical volume
       , "calorimeterGap"       // its name
       , logiccalorimeterLayer   // its mother  volume
       , false                  // no boolean operation
       , 0                      // copy number
       , checkOverlaps );        // checking overlaps


   /* G4PVPlacement::G4PVPlacement 	( 	G4RotationMatrix *  	pRot,
		const G4ThreeVector &  	tlate,
		G4LogicalVolume *  	pCurrentLogical,
		const G4String &  	pName,
		G4LogicalVolume *  	pMotherLogical,
		G4bool  	pMany,
		G4int  	pCopyNo,
		G4bool  	pSurfChk = false	 
	) 	*/

    return logiccalorimeterPlane;
                   
    //return logiccalorimeterSlab;
}
