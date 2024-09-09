//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file SteppingAction.cc
/// \brief Implementation of the SteppingAction class


#include <g4analysis_defs.hh>
#include "SteppingAction.hh"
#include "EventAction.hh"
#include "DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4ParticleTypes.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction( const DetectorConstruction* detectorConstruction,EventAction* eventAction)
        : G4UserSteppingAction(),
          fEventAction(eventAction),
          fDetConstruction(detectorConstruction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* step)
{


    auto volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName();
      auto edep = step->GetTotalEnergyDeposit();
    auto Particle=step->GetTrack()->GetDefinition()->GetParticleName();
    G4String processName =step->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();
    auto ID = step->GetPreStepPoint()->GetPhysicalVolume()->GetCopyNo();
    G4int line=ID/338;//这里与DetectorCon文件一致
    G4int row=ID%338;



    G4AnalysisManager *analysis = G4AnalysisManager::Instance();
  
    G4float time=step->GetTrack()->GetGlobalTime();

    G4float energy=step->GetPreStepPoint()->GetKineticEnergy();
    
    if ( volume =="moderator")
    {
                 
            fEventAction->AddCellEdep(edep,line,row);//单元能量
    }
   

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

