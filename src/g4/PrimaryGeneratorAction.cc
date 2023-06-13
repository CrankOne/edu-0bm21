#include <G4ParticleGun.hh>
#include <G4ParticleTable.hh>

#include "g4/PrimaryGeneratorAction.hh"

void
PrimaryGeneratorAction::GeneratePrimaries(G4Event * event) {
    _pGun->GeneratePrimaryVertex(event);
}

PrimaryGeneratorAction::PrimaryGeneratorAction()
        : _pGun(nullptr) {
    _pGun = new G4ParticleGun(1);

    _pGun->SetParticleDefinition( G4ParticleTable::GetParticleTable()
                ->FindParticle("J/psi") );
    _pGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
    _pGun->SetParticleEnergy(160*CLHEP::GeV);
    _pGun->SetParticlePosition(G4ThreeVector(0, 0, -12.5*CLHEP::m));
}

