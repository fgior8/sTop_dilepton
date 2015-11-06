const int nBTagBins = 8;
float BTagEdge[nBTagBins+1] = {0., 20., 30., 50., 80., 120., 160., 210., 100000.};

float TotalEntries;

TH1F *GetTemplate(int fl, int tg, int ietab, int fetab) {

  if (tg==0) TotalEntries = 0.;

  TFile *InputFile = TFile::Open("./TreeAnalysisStop_Dilep_12103.3pb-1_TTbar_Madgraph_Pt20.root");

  TString HistoLabel = "BTagEff_"; HistoLabel += fl; HistoLabel += "_"; HistoLabel += tg;
  
  TString HistoTitle = HistoLabel; HistoTitle += "_"; HistoTitle += ietab; HistoTitle += "-"; HistoTitle += fetab;

  TH1F *HISTO = new TH1F(HistoTitle, "", nBTagBins, BTagEdge);

  float BinContent[nBTagBins];
  for (int jb = 1; jb<=nBTagBins; jb++)
    BinContent[jb-1] = 0.;

  for (int tetab = ietab; tetab<=fetab; tetab++) {

    TString HistoName = HistoLabel; HistoName += "_"; HistoName += tetab;
    TH1F *TEMP = (TH1F*) InputFile->Get(HistoName);

    if (tg==0) TotalEntries += TEMP->GetEntries();

    int nBinsX = TEMP->GetNbinsX();
    for (int ib = 1; ib<=nBinsX; ib++) {

      float xib = TEMP->GetBinCenter(ib);
      int jb = HISTO->FindBin(xib);
      BinContent[jb-1] += TEMP->GetBinContent(ib);

    }
    
  }

  for (int jb = 1; jb<=nBTagBins; jb++)
    HISTO->SetBinContent(jb, BinContent[jb-1]);  
  
  return HISTO;
  
}

void BTaggingEfficiencies(int fl, int tg, int ietab, int fetab) {
	
  TH1F *DEN = GetTemplate(fl,  0, ietab, fetab);
  TH1F *NUM = GetTemplate(fl, tg, ietab, fetab);
  
  NUM->Divide(DEN);
  
  NUM->Draw();
  
  float Scale = TotalEntries/DEN->Integral();
  
  for (int ib = 2; ib<=nBTagBins; ib++) {
    
    float eps = NUM->GetBinContent(ib);
    float den = Scale*DEN->GetBinContent(ib);
    float err = sqrt(eps*(1.-eps)/den);
    
    cout << BTagEdge[ib-1] << " - " << BTagEdge[ib] << " " << den << " " << 100.*eps << " " << 100.*err << endl;    
    
  }
  
}

void BTaggingEfficiencies(int fl, int tg) {

  TString TaggerName[4] = {"", "CSVL", "CSVM", "CSVT"};

  cout << "  if (TaggerName==" << TaggerName[tg] << ") {" << endl;

  for (int ib = 2; ib<=nBTagBins; ib++) {

    TString Else = "} else ";
    if (ib==2) Else = "";
    cout << "    " << Else << "if (" << BTagEdge[ib-1] << "<=JetPt && JetPt<" << BTagEdge[ib] << ") {" << endl;

    for (int etab = 11; etab>=0; etab--) {

      float den, eps, err = 1000.;
      
      int ietab = etab, fetab = etab;

      while (err>1. && ietab>=0) {

	TH1F *DEN = GetTemplate(fl,  0, ietab, fetab);
	TH1F *NUM = GetTemplate(fl, tg, ietab, fetab);
  
	float Scale = TotalEntries/DEN->Integral();
      
	float eps = NUM->GetBinContent(ib)/DEN->GetBinContent(ib);
	float den = Scale*DEN->GetBinContent(ib);
	float err = 100.*sqrt(eps*(1.-eps)/den);

	if (err>1.) ietab--;

      }

      TString ElseEta = "else ";
      if (etab==11) ElseEta = "";
      cout << "      " << ElseEta << "if (JetEta>=" << ietab*0.2 << ") return " << eps << "; // " << den << " " << err << endl;
      //cout << BTagEdge[ib-1] << " - " << BTagEdge[ib] << " " << den << " " << 100.*eps << " " << err << endl;

      etab = ietab;    
      
    }
    
  }

  cout << "    }" << endl;
  cout << "  }" << endl;
  
}


