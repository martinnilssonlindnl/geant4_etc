void plot3D()
{

	TCanvas *ci = new TCanvas();
	
	TFile *input = new TFile ("output1X0.root", "read");
	
	TTree *tree = (TTree*)input->Get("Scoring");
	
	
	double fX,fY,fZ;
	tree->SetBranchAddress("fX", &fX);
	tree->SetBranchAddress("fY", &fY);
	tree->SetBranchAddress("fZ", &fZ);


	int entries = tree->GetEntries();
	
	TH3F *hist = new TH3F("hist", "Histogram", 100, -500,500, 100, -500,500, 100, -400,400);

	for(int i = 0; i < entries; i++)
	{
		tree->GetEntry(i);
		
		//cout << x << y << endl;
		
		hist->Fill(fX,fY, fZ);
	}
	
	hist->Draw();
	

}


