#include <G4VUserDetectorConstruction.hh>
#include <G4RunManagerFactory.hh>
#include <QBBC.hh>
#include <G4UImanager.hh>
#include <G4UIExecutive.hh>
#include <G4VisManager.hh>
#include <G4VisExecutive.hh>

#include "g4/DetectorConstruction.hh"
#include "g4/PrimaryGeneratorAction.hh"

int
main(int argc, char * argv[]) {
    G4UIExecutive * ui = nullptr;
    if(1 == argc) {
        // no arguments provided -- run interactive mode
        ui = new G4UIExecutive(argc, argv);
    }

    // Instantiate default run manager
    auto * runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);
    // ... and set 1) detector construction instance to create geometry
    //     and sensitive detectors:
    runManager->SetUserInitialization(new DetectorConstruction(true /*checkOverlaps*/));
    // ... 2) physics list to define considered simulation processes
    G4VModularPhysicsList* physicsList = new QBBC;
    runManager->SetUserInitialization(physicsList);
    // ... 3) initialization action
    //runManager->SetUserInitialization(new ActionInitialization());
    runManager->SetUserAction(new PrimaryGeneratorAction());  // < XXX, deprecated API

    // Instantiate visualization
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();

    // ptr to user interface manager
    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    if(!ui) {
        // batch mode (script to run was provided as command line argument)
        G4String cmd = G4String("/control/execute ") + argv[1];
        UImanager->ApplyCommand(cmd);
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

