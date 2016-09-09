#include "ResAnalyzer.h"

ResAnalyzer::ResAnalyzer() {
  h_prova             = new TH1F("h_prova","p_T",100,0,1000);
  h2_jetPtRes_leading     = new TH2F("h2_jetPtRes_leading","leading jet p_{T} res",100,-500,500,100,0,1000);
  h2_jetERes_leading      = new TH2F("h2_jetERes_leading" ,"leading jet E res",100,-500,500,100,0,1000);
  h2_MT2bbRes_noB         = new TH2F("h2_MT2bbRes_noB"    ,"m_{T2}(bb) no B res",100,-50,50,40,50,250);
  h2_MT2bbRes_oneB        = new TH2F("h2_MT2bbRes_oneB"   ,"m_{T2}(bb) one B res",100,-50,50,40,50,250);   
  h2_MT2bbRes_twoB        = new TH2F("h2_MT2bbRes_twoB"   ,"m_{T2}(bb) two B res",100,-50,50,40,50,250);
  //  h_MT2bbRes_noB_150     = new TH2F("h_MT2bbRes_noB_150" ,"m_{T2}(bb) no B res above 150 (GeV)",100,-50,50,40,50,250);
  // h_MT2bbRes_oneB_150    = new TH2F("h_MT2bbRes_oneB_150","m_{T2}(bb) one B res above 150 (GeV)",100,-50,50,40,50,250);   
  // h_MT2bbRes_twoB_150    = new TH2F("h_MT2bbRes_twoB_150","m_{T2}(bb) two B res above 150 (GeV)",100,-50,50,40,50,250);
}

ResAnalyzer::~ResAnalyzer() { }

void ResAnalyzer::SetName(TString name, Int_t version) {

  completename = name + "_";
  completename += version;
  completename += ".root";
  outfile = new TFile("./Optimization/"+completename,"RECREATE");
}


void ResAnalyzer::Loop() {

  cout << "total number of entries " <<nentries<<endl;

  if (debug) cout<< "loop begins" <<endl;

  if (fChain == 0) 
    cout << "Ciao!" << endl;

  if (debug) cout<< "at the loop" <<endl;

  for (Long64_t jentry = 0; jentry < nentries; jentry++ ) {
     
    if (debug) cout<< "Event number " <<jentry<<endl;
    if (debug) cout<<"begin loop"<<endl;
    if (!(jentry % 10000)) 
      cout << jentry << endl;

    if (!fChain) cout<<"problems with the input file"<<endl;
    fChain->GetEntry(jentry);
    
    h_prova->Fill(TMET);

    fakeType = Lepton::unknown;
    looseTight = Lepton::Other;
    leptonType = Lepton::Muon;

    TLorentzVector GJet1, TJet1, lVec;
    vector<Jet> TBJets;
    vector<Lepton> GLeptons;
    vector<Lepton> HLeptons;
    vector<Jet> GJets;
    vector<Jet> HBJets;	
    vector<Jet> jetSelect;
    vector<Lepton> leptonSelect;
    Int_t charge=0;	
    for (UInt_t i=0; i<TNLepSel; i++) {
      lVec.SetPxPyPzE(TLepSel_Px[i],TLepSel_Py[i],TLepSel_Pz[i],TLepSel_E[i]);
      charge = TLepSel_Charge[i];
      leptonSelect.push_back( Lepton(leptonType, i, lVec, TLepSel_Pz[i], TLepSel_Pz[i], TLepSel_Pz[i], TLepSel_Pz[i], charge, fakeType, looseTight, TLepSel_Pz[i]) );
    }
    if (debug) cout << "leptons done" << endl;
    for (UInt_t i=0; i<TNJetSel; i++) {
      lVec.SetPxPyPzE(TJetSel_Px[i],TJetSel_Py[i],TJetSel_Pz[i],TJetSel_E[i]);
      Int_t discriminant = TJetSel_discriminant[i];
      if (TJet_discriminant[i]>0.605)
	TBJets.push_back( Jet(TJet1, -999, TJet_discriminant[i], i) );
      jetSelect.push_back( Jet(lVec, discriminant, 0.0, i) );
    }
    for (UInt_t i=0; i<GNJets; i++) {
      GJet1.SetPxPyPzE(GJet_Px[i],GJet_Py[i],GJet_Pz[i],GJet_E[i]);
      GJets.push_back( Jet(GJet1, -999, GJet_discriminant[i], i) );
    }
    for (UInt_t i=0; i<GNElec; i++) {
      lVec.SetPxPyPzE(GElec_Px[i],GElec_Py[i],GElec_Pz[i],GElec_E[i]);
      if (lVec.Pt()>0)
	GLeptons.push_back( Lepton(leptonType, i, lVec, TLepSel_Pz[i], TLepSel_Pz[i], TLepSel_Pz[i], TLepSel_Pz[i], charge, fakeType, looseTight, TLepSel_Pz[i]) );
    }
    if (debug) cout << "Gen done" << endl;
    ////HARD scattering process
    for (UInt_t i=0; i<HNBJets; i++) {
      GJet1.SetPxPyPzE(HBJet_Px[i],HBJet_Py[i],HBJet_Pz[i],HBJet_E[i]);
      HBJets.push_back( Jet(GJet1, -999, HBJet_discriminant[i], i) );
    }
    for (UInt_t i=0; i<HNElec; i++) {
      lVec.SetPxPyPzE(HElec_Px[i],HElec_Py[i],HElec_Pz[i],HElec_E[i]);
      if (lVec.Pt()>0)
	HLeptons.push_back( Lepton(leptonType, i, lVec, TLepSel_Pz[i], TLepSel_Pz[i], TLepSel_Pz[i], TLepSel_Pz[i], charge, fakeType, looseTight, TLepSel_Pz[i]) );
    }
    if (debug) cout << "Hard done" << endl;

    
    if ( TNJetSel>=2 && GLeptons.size()==2) {
      h2_jetERes_leading->Fill((jetSelect[0].lorentzVec().E()-GJets[0].lorentzVec().E()),jetSelect[0].lorentzVec().E());
      h2_jetPtRes_leading->Fill((jetSelect[0].lorentzVec().Pt()-GJets[0].lorentzVec().Pt()),jetSelect[0].lorentzVec().Pt());

      double MT2bb_reco = getMT2bb(jetSelect, leptonSelect, TMET, TMET_Phi);
      double MT2bb_gen = getMT2bb(GJets, GLeptons, TMET, TMET_Phi);

      if (MT2bb_reco>1 && MT2bb_gen>1) {
	h2_MT2bbRes_noB->Fill((TMT2bb-GMT2bb),TMT2bb);
	if (TBJets.size()>0)
	  h2_MT2bbRes_oneB->Fill((TMT2bb-GMT2bb),TMT2bb);
	if (TBJets.size()>1)
	  h2_MT2bbRes_twoB->Fill((TMT2bb-GMT2bb),TMT2bb);
      }
    }
  }

  if(debug) cout<< "out of the loop" <<endl;
  unsigned int outputWidth = 1600;
  unsigned int outputHeight = 1200;
  TCanvas* can2;
  can2 = new TCanvas("can2","",outputWidth,outputHeight);
  //can2->Draw();
  can2->SetRightMargin(0.14);

  TCutG *mycut;
  mycut = new TCutG("mycut",5);
  mycut->SetPoint(0,-50,150);
  mycut->SetPoint(1,-50,250);
  mycut->SetPoint(2,50,250);
  mycut->SetPoint(3,50,150);
  mycut->SetPoint(4,-50,150);
  h_MT2bbRes_noB=h2_MT2bbRes_noB->ProjectionX("h_MT2bbRes_noB",0,-1,"[mycut]");
  h_MT2bbRes_oneB=h2_MT2bbRes_oneB->ProjectionX("h_MT2bbRes_oneB",0,-1,"[mycut]");
  h_MT2bbRes_twoB=h2_MT2bbRes_twoB->ProjectionX("h_MT2bbRes_twoB",0,-1,"[mycut]");

  TF1 *g1 = new TF1("g1","gaus",-50,50);
  g1->SetLineColor(kBlue);
  TF1 *g2 = new TF1("g2","gaus",-50,50);
  g2->SetLineColor(kGreen);
  TF1 *g3 = new TF1("g3","gaus",-50,50);
  g3->SetLineColor(kRed);
  h_MT2bbRes_noB->Fit(g1);
  //TLegend *legend1=new TLegend(0.6,0.65,0.88,0.85);
  // legend1->AddEntry(g1,"no B","l");
  h_MT2bbRes_oneB->Fit(g2);
  h_MT2bbRes_twoB->Fit(g3);
  gROOT->SetStyle("Plain");
  gStyle->SetOptFit(1111);
  // h_MT2bbRes_noB->GetXaxis()->SetName("resolution (GeV)");
  h_MT2bbRes_oneB->SetLineColor(kGreen);
  h_MT2bbRes_twoB->SetLineColor(kRed);
  // legend1->Draw();
  //leg->SetFillColor(0);
  h_MT2bbRes_noB->Draw();
  can2->Print("Plots/h_MT2bbRes_noB.pdf");
  h_MT2bbRes_oneB->Draw();
  can2->Print("Plots/h_MT2bbRes_oneB.pdf");
  h_MT2bbRes_twoB->Draw();
  can2->Print("Plots/h_MT2bbRes_twoB.pdf");

  
  outfile->cd();
  h_prova->Write();
  h_MT2bbRes_noB->Write();
  h_MT2bbRes_oneB->Write();
  h_MT2bbRes_twoB->Write();    
  h2_jetERes_leading->Write();
  h2_jetPtRes_leading->Write();
  h2_MT2bbRes_noB->Write();
  h2_MT2bbRes_oneB->Write();
  h2_MT2bbRes_twoB->Write();
  outfile->Close();
  cout<<"histo written."<<endl;

  

}
