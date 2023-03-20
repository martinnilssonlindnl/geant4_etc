#include "event.hh"

MyEventAction::MyEventAction(MyRunAction*)
{
	fEdep = 0.0;
	//fTrackL = 0.0;
}

MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event*)
{
	fEdep = 0.0;
	fE = 0.0;
	//fX = 0.0;
	//fY = 0.0;
	//fZ = 0.0;
}

void MyEventAction::EndOfEventAction(const G4Event*)
{
	//G4cout << "Eneergy deposition: " << fEdep << G4endl;
	//G4cout << "x-position " << fX << G4endl;
	//G4cout << "y-position " << fY << G4endl;
	
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	//G4cout << "Eneergy deposition: " << fEdep << G4endl;
	
	
	if (fE != 0.0){
	//G4cout << "Eneergy deposition: " << fE << G4endl; OBS
	man->FillNtupleDColumn(1,0,fE);
	//man->FillNtupleDColumn(0,1,fX);
	//man->FillNtupleDColumn(0,2,fY);
	//man->FillNtupleDColumn(0,3,fZ);
	
	//man->FillNtupleDColumn(0,1,fTrackL);
	man->AddNtupleRow(1);
	}


}
