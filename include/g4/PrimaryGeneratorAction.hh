#pragma once

#include <G4VUserPrimaryGeneratorAction.hh>

class G4ParticleGun;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
    void GeneratePrimaries(G4Event *) override;

    PrimaryGeneratorAction();
protected:
    G4ParticleGun * _pGun;
};  // class PrimaryGeneratorAction

