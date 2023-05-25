#include <G4VUserDetectorConstruction.hh>
#include <G4RunManagerFactory.hh>
#include <QBBC.hh>
#include <G4UImanager.hh>
#include <G4UIExecutive.hh>

//#include "DetectorConstruction.hh"

int
main(int argc, char * argv[]) {
    G4UIExecutive* ui = nullptr;
    if ( argc == 1 ) { ui = new G4UIExecutive(argc, argv); }

    if(argc != 2) {
        std::cerr << "Error: expected command line argument" << std::endl;
        return 1;
    }

    auto runMgr = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);

    //runManager->SetUserInitialization(new DetectorConstruction());
    G4VModularPhysicsList * physicsList = new QBBC;
    physicsList->SetVerboseLevel(1);
    //runManager->SetUserInitialization(physicsList);

    //runManager->SetUserInitialization(new ActionInitialization());

    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    if ( ! ui ) {
        // batch mode
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command+fileName);
    } else {
        // interactive mode
        UImanager->ApplyCommand("/control/execute init_vis.mac");
        ui->SessionStart();
        delete ui;
    }

    delete visManager;
    delete runManager;

    return 0;
}

