void plot()
{

	TCanvas *ci = new TCanvas();
	
	TFile *input = new TFile ("outputX0.root", "read");
	
	TTree *tree = (TTree*)input->Get("Scoring");
	
	
	double fX,fY;
	tree->SetBranchAddress("fX", &fX);
	tree->SetBranchAddress("fY", &fY);


	int entries = tree->GetEntries();
	
	TH2F *hist = new TH2F("hist", "Histogram", 400, -500,500, 400, -500,500);

	for(int i = 0; i < entries; i++)
	{
		tree->GetEntry(i);
		
		//cout << x << y << endl;
		
		hist->Fill(fX,fY);
	}
	
	hist->Draw("colz");
	

}
