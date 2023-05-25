#include <G4VUserDetectorConstruction.hh>
#include <G4RunManagerFactory.hh>
#include <QBBC.hh>

//#include "DetectorConstruction.hh"

int
main(int argc, char * argv[]) {
    if(argc != 2) {
        std::cerr << "Error: expected command line argument" << std::endl;
        return 1;
    }

    auto runMgr = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);

    //runManager->SetUserInitialization(new DetectorConstruction());
    G4VModularPhysicsList* physicsList = new QBBC;
    physicsList->SetVerboseLevel(1);
    //runManager->SetUserInitialization(physicsList);

    //runManager->SetUserInitialization(new ActionInitialization());

    // ...

    return 0;
}

