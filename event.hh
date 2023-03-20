#ifndef EVENT_HH
#define EVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"

#include "G4AnalysisManager.hh"

#include "run.hh"

class MyEventAction : public G4UserEventAction
{
public: 
	MyEventAction(MyRunAction*);
	~MyEventAction();
	
	virtual void BeginOfEventAction(const G4Event*);
	virtual void EndOfEventAction(const G4Event*);
	
	void AddEdep(G4double edep) {fEdep += edep;}
	void AddEdepp(G4double edep) {fE+= edep;}
	//void setX(G4double xx) {fX = xx;}
	//void setY(G4double yy) {fY = yy;}
	//void setZ(G4double zz) {fZ = zz;}
	
private:
	G4double fEdep;
	G4double fE;
	//G4double fX;
	//G4double fY;
	//G4double fZ;

};

#endif
