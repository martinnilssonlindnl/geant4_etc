#include "stepping.hh"
#include "G4RunManager.hh"
#include "G4Neutron.hh"

MySteppingAction::MySteppingAction(MyEventAction *eventAction)
{
	fEventAction = eventAction;
	
}

MySteppingAction::~MySteppingAction()
{}

void MySteppingAction::UserSteppingAction(const G4Step *step)
{
	
	
	//KIKAR VILKEN VOLY VI BEFINNER OSS I
	G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
	
	const MyDetectorConstruction *detectorConstruction = static_cast<const
	
	MyDetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
	
	G4LogicalVolume *fScoringVolume = detectorConstruction->GetScoringVolume();
	
	if(volume != fScoringVolume)
		return;
		
	//if (step->GetTrack()->GetParticleDefinition()->GetParticleName() == "neutron")
	//{
	G4double edep = step-> GetTotalEnergyDeposit();
	//G4cout << "dE: " << edep << G4endl; OBS
	fEventAction->AddEdepp(edep);
	
	
	
	G4StepPoint *postStepPoint = step->GetPostStepPoint();
	G4ThreeVector posPhoton = postStepPoint->GetPosition();

	
	
	
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	if (edep != 0.0){
	//if (0.4*MeV > edep && edep > 0.2*MeV){
		man->FillNtupleDColumn(0,0,edep);
		man->FillNtupleDColumn(0,1,posPhoton[0]);
		man->FillNtupleDColumn(0,2,posPhoton[1]);
		man->FillNtupleDColumn(0,3,posPhoton[2]);
	

		man->AddNtupleRow(0);
	}
	
	//}
	
	
	
	
	

}
