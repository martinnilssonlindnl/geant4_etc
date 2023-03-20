#include "run.hh"	


MyRunAction::MyRunAction()
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	

	man->CreateNtuple("Scoring", "Scoring");
	man->CreateNtupleDColumn("fEdep");
	man->CreateNtupleDColumn("fX");
	man->CreateNtupleDColumn("fY");
	man->CreateNtupleDColumn("fZ");
	man->FinishNtuple(0);
	
	
	//man->CreateNtuple("Trax", "Trax");
	//man->CreateNtupleDColumn("fX");
	//man->CreateNtupleDColumn("fY");
	//man->CreateNtupleDColumn("fZ");
	//man->FinishNtuple(1);
	
	man->CreateNtuple("Total_energy", "Total_energy");
	man->CreateNtupleDColumn("fE");
	man->FinishNtuple(1);
	
	

	
}
MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run* run)
{
	
	G4AnalysisManager *man = G4AnalysisManager::Instance();	
	
	G4int runID = run->GetRunID();
	man->SetNtupleMerging(true);
	
	std::stringstream strRunID;
	strRunID << runID;
	man->OpenFile("output1X"+strRunID.str()+".root");
	//man->OpenFile("10000beta10MeV.root");
}
void MyRunAction::EndOfRunAction(const G4Run*)
{

	G4AnalysisManager *man = G4AnalysisManager::Instance();
	
	//SKRIV UT FILEN 
	man->Write();
	man->CloseFile();

}
