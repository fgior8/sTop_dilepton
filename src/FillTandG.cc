#include "FillTandG.h"

FillTandG::FillTandG(TTree *AnalysisTree) {

  if (debug) cout<< "inizializing tree" <<endl;
  ///Initialize tree for optimization
  AnalysisTree->Branch("TWeight",&TWeight,"TWeight/F");
  AnalysisTree->Branch("TNPV",&TNPV,"TNPV/I");
  AnalysisTree->Branch("TMET",&TMET,"TMET/F");
  AnalysisTree->Branch("TMET_Phi",&TMET_Phi,"TMET_Phi/F");
  AnalysisTree->Branch("TMT2ll",&TMT2ll,"TMT2ll/F");
  AnalysisTree->Branch("TMT2bb",&TMT2bb,"TMT2bb/F");
  AnalysisTree->Branch("TMT2lblb",&TMT2lblb,"TMT2lblb/F");
  AnalysisTree->Branch("THT",&THT,"THT/F");
  AnalysisTree->Branch("TMll",&TMll,"TMll/F");
  AnalysisTree->Branch("TMeff",&TMeff,"TMeff/F");
  AnalysisTree->Branch("TPtllb",&TPtllb,"TPtllb/F");
  AnalysisTree->Branch("TdPhiPtllbMET",&TdPhiPtllbMET,"TdPhiPtllbMET/F");
  AnalysisTree->Branch("TdPhiJetMet",&TdPhiJetMet,"TdPhiJetMet/F");
  AnalysisTree->Branch("TdPhiLepMet",&TdPhiLepMet,"TdPhiLepMet/F");
  AnalysisTree->Branch("TdPhiLepJet",&TdPhiLepJet,"TdPhiLepJet/F");
  AnalysisTree->Branch("TdPhill",&TdPhill,"TdPhill/F");
  AnalysisTree->Branch("TcosThetap",&TcosThetap,"TcosThetap/F");
  AnalysisTree->Branch("TcosThetam",&TcosThetam,"TcosThetam/F");

  AnalysisTree->Branch("TNLepSel",&TNLepSel,"TNLepSel/I");
  AnalysisTree->Branch("TNJetSel",&TNJetSel,"TNJetSel/I");
  AnalysisTree->Branch("TNMuon",&TNMuon,"TNMuon/I");
  AnalysisTree->Branch("TNElec",&TNElec,"TNElec/I");
  AnalysisTree->Branch("TNJets",&TNJets,"TNJets/I");
  AnalysisTree->Branch("TNJetsBtag",&TNJetsBtag,"TNJetsBtag/I");
  if (debug) cout<< "inizializing variables for TLorentz vectors" <<endl;
  AnalysisTree->Branch("TJetSel_discriminant", TJetSel_discriminant, "TJetSel_discriminant[TNJetSel]/F");
  AnalysisTree->Branch("TJetSel_Px", TJetSel_Px, "TJetSel_Px[TNJetSel]/F");
  AnalysisTree->Branch("TJetSel_Py", TJetSel_Py, "TJetSel_Py[TNJetSel]/F");
  AnalysisTree->Branch("TJetSel_Pz", TJetSel_Pz, "TJetSel_Pz[TNJetSel]/F");
  AnalysisTree->Branch("TJetSel_E", TJetSel_E, "TJetSel_E[TNJetSel]/F");
  AnalysisTree->Branch("TLepSel_Charge", TLepSel_Charge, "TLepSel_Charge[TNLepSel]/F");
  AnalysisTree->Branch("TLepSel_Px", TLepSel_Px, "TLepSel_Px[TNLepSel]/F");
  AnalysisTree->Branch("TLepSel_Py", TLepSel_Py, "TLepSel_Py[TNLepSel]/F");
  AnalysisTree->Branch("TLepSel_Pz", TLepSel_Pz, "TLepSel_Pz[TNLepSel]/F");
  AnalysisTree->Branch("TLepSel_E", TLepSel_E, "TLepSel_E[TNLepSel]/F");
  AnalysisTree->Branch("TMuon_Charge", TMuon_Charge, "TMuon_Charge[TNMuon]/F");
  AnalysisTree->Branch("TMuon_Px", TMuon_Px, "TMuon_Px[TNMuon]/F");
  AnalysisTree->Branch("TMuon_Py", TMuon_Py, "TMuon_Py[TNMuon]/F");
  AnalysisTree->Branch("TMuon_Pz", TMuon_Pz, "TMuon_Pz[TNMuon]/F");
  AnalysisTree->Branch("TMuon_E", TMuon_E, "TMuon_E[TNMuon]/F");
  AnalysisTree->Branch("TElec_Charge", TElec_Charge, "TElec_Charge[TNElec]/F");
  AnalysisTree->Branch("TElec_Px", TElec_Px, "TElec_Px[TNElec]/F");
  AnalysisTree->Branch("TElec_Py", TElec_Py, "TElec_Py[TNElec]/F");
  AnalysisTree->Branch("TElec_Pz", TElec_Pz, "TElec_Pz[TNElec]/F");
  AnalysisTree->Branch("TElec_E", TElec_E, "TElec_E[TNElec]/F");
  AnalysisTree->Branch("TJet_discriminant", TJet_discriminant, "TJet_discriminant[TNJets]/F");
  AnalysisTree->Branch("TJet_Px", TJet_Px, "TJet_Px[TNJets]/F");
  AnalysisTree->Branch("TJet_Py", TJet_Py, "TJet_Py[TNJets]/F");
  AnalysisTree->Branch("TJet_Pz", TJet_Pz, "TJet_Pz[TNJets]/F");
  AnalysisTree->Branch("TJet_E", TJet_E, "TJet_E[TNJets]/F");
  AnalysisTree->Branch("TBJet_Px", TBJet_Px, "TBJet_Px[TNJetsBtag]/F");
  AnalysisTree->Branch("TBJet_Py", TBJet_Py, "TBJet_Py[TNJetsBtag]/F");
  AnalysisTree->Branch("TBJet_Pz", TBJet_Pz, "TBJet_Pz[TNJetsBtag]/F");
  AnalysisTree->Branch("TBJet_E", TBJet_E, "TBJet_E[TNJetsBtag]/F");

  //Gen variables
  AnalysisTree->Branch("GNMuon",&GNMuon,"GNMuon/I");
  AnalysisTree->Branch("GNElec",&GNElec,"GNElec/I");
  AnalysisTree->Branch("GNJets",&GNJets,"GNJets/I");
  AnalysisTree->Branch("GMET",&GMET,"GMET/F");
  AnalysisTree->Branch("GMET_Phi",&GMET_Phi,"GMET_Phi/F");
  AnalysisTree->Branch("GMT2ll",&GMT2ll,"GMT2ll/F");
  AnalysisTree->Branch("GMT2bb",&GMT2bb,"GMT2bb/F");
  AnalysisTree->Branch("GMT2lblb",&GMT2lblb,"GMT2lblb/F");
  AnalysisTree->Branch("GJet_discriminant", GJet_discriminant, "GJet_discriminant[GNJets]/F");
  AnalysisTree->Branch("GJet_Px", GJet_Px, "GJet_Px[GNJets]/F");
  AnalysisTree->Branch("GJet_Py", GJet_Py, "GJet_Py[GNJets]/F");
  AnalysisTree->Branch("GJet_Pz", GJet_Pz, "GJet_Pz[GNJets]/F");
  AnalysisTree->Branch("GJet_E", GJet_E, "GJet_E[GNJets]/F");
  AnalysisTree->Branch("GMuon_Px", GMuon_Px, "GMuon_Px[GNMuon]/F");
  AnalysisTree->Branch("GMuon_Py", GMuon_Py, "GMuon_Py[GNMuon]/F");
  AnalysisTree->Branch("GMuon_Pz", GMuon_Pz, "GMuon_Pz[GNMuon]/F");
  AnalysisTree->Branch("GMuon_E", GMuon_E, "GMuon_E[GNMuon]/F");
  AnalysisTree->Branch("GElec_Px", GElec_Px, "GElec_Px[GNElec]/F");
  AnalysisTree->Branch("GElec_Py", GElec_Py, "GElec_Py[GNElec]/F");
  AnalysisTree->Branch("GElec_Pz", GElec_Pz, "GElec_Pz[GNElec]/F");
  AnalysisTree->Branch("GElec_E", GElec_E, "GElec_E[GNElec]/F");

  //Hard scattering variables
  
  AnalysisTree->Branch("HNMuon",&HNMuon,"HNMuon/I");
  AnalysisTree->Branch("HNElec",&HNElec,"HNElec/I");
  AnalysisTree->Branch("HNJetsBtag",&HNJetsBtag,"HNJetsBtag/I");
  AnalysisTree->Branch("HMT2ll",&HMT2ll,"HMT2ll/F");
  AnalysisTree->Branch("HMT2bb",&HMT2bb,"HMT2bb/F");
  AnalysisTree->Branch("HMT2lblb",&HMT2lblb,"HMT2lblb/F");
  /*
  AnalysisTree->Branch("HJet_discriminant", HJet_discriminant, "HJet_discriminant[HNJets]/F");
  AnalysisTree->Branch("HJet_Px",  HJet_Px,  "HJet_Px[HNJets]/F");
  AnalysisTree->Branch("HJet_Py",  HJet_Py,  "HJet_Py[HNJets]/F");
  AnalysisTree->Branch("HJet_Pz",  HJet_Pz,  "HJet_Pz[HNJets]/F");
  AnalysisTree->Branch("HJet_E",   HJet_E,   "HJet_E[HNJets]/F");
  */
  AnalysisTree->Branch("HBJet_Px", HBJet_Px, "HBJet_Px[HNJetsBtag]/F");
  AnalysisTree->Branch("HBJet_Py", HBJet_Py, "HBJet_Py[HNJetsBtag]/F");
  AnalysisTree->Branch("HBJet_Pz", HBJet_Pz, "HBJet_Pz[HNJetsBtag]/F");
  AnalysisTree->Branch("HBJet_E",  HBJet_E,  "HBJet_E[HNJetsBtag]/F");
  AnalysisTree->Branch("HMuon_Px", HMuon_Px, "HMuon_Px[HNMuon]/F");
  AnalysisTree->Branch("HMuon_Py", HMuon_Py, "HMuon_Py[HNMuon]/F");
  AnalysisTree->Branch("HMuon_Pz", HMuon_Pz, "HMuon_Pz[HNMuon]/F");
  AnalysisTree->Branch("HMuon_E",  HMuon_E,  "HMuon_E[HNMuon]/F");
  AnalysisTree->Branch("HElec_Px", HElec_Px, "HElec_Px[HNElec]/F");
  AnalysisTree->Branch("HElec_Py", HElec_Py, "HElec_Py[HNElec]/F");
  AnalysisTree->Branch("HElec_Pz", HElec_Pz, "HElec_Pz[HNElec]/F");
  AnalysisTree->Branch("HElec_E",  HElec_E,  "HElec_E[HNElec]/F");

}

FillTandG::~FillTandG() { }

void FillTandG::SetRecoVariables(TTree *AnalysisTree, Float_t weight, Int_t numberVertices, vector<Jet>& jetSelect, vector<Lepton>& leptonSelect, Float_t theMET, Float_t theMETphi, Float_t HT, vector<Lepton>& muonColl, vector<Lepton>& electronColl, vector<Jet>& jetColl, vector<Jet>& bjetColl) {
  
  TWeight = weight;
  TNPV = numberVertices;
  //cout << "Fill numberVertices " << numberVertices << endl;
  TNJets = jetColl.size();     
  TNJetsBtag = bjetColl.size();
  TNLepSel = leptonSelect.size();
  TNJetSel = jetSelect.size();
  TNMuon = muonColl.size();
  TNElec = electronColl.size();
  TMET = theMET;
  TMET_Phi = theMETphi;
  THT = HT; 
  TMT2ll = getMT2(leptonSelect[0].lorentzVec(), leptonSelect[1].lorentzVec(), theMET, theMETphi);
  TMT2bb = getMT2bb(jetSelect, leptonSelect, theMET, theMETphi);
  TMT2lblb = getMT2lblb(jetSelect, leptonSelect, theMET, theMETphi);
  TMll = (leptonSelect[0].lorentzVec()+leptonSelect[1].lorentzVec()).M();
  TPtllb = getllmetVector(leptonSelect[0].lorentzVec(), leptonSelect[1].lorentzVec(), theMET, theMETphi).Pt();
  TMeff = getMeff(jetSelect, leptonSelect, theMET);
  TdPhiPtllbMET = getdPhiPtllbMet(getllmetVector(leptonSelect[0].lorentzVec(), leptonSelect[1].lorentzVec(), theMET, theMETphi), theMET, theMETphi);
  TdPhiJetMet = getdPhiJetMet(jetSelect, theMET, theMETphi); //Closest Jet
  TdPhiLepMet = getdPhiLepMet(leptonSelect[0].lorentzVec(), theMET, theMETphi);
  TdPhiLepJet = leptonSelect[0].lorentzVec().DeltaPhi(jetSelect[0].lorentzVec());
  TdPhill = leptonSelect[0].lorentzVec().DeltaPhi(leptonSelect[1].lorentzVec());
  dilep_beta = (leptonSelect[0].lorentzVec()+leptonSelect[1].lorentzVec()).BoostVector();
  if(leptonSelect[0].charge() < 0) {
    lm = leptonSelect[0].lorentzVec();
    lp = leptonSelect[1].lorentzVec();
  }
  else {
    lm = leptonSelect[1].lorentzVec();
    lp = leptonSelect[0].lorentzVec();
  }
  lm.Boost(-dilep_beta);
  lp.Boost(-dilep_beta);
 
  TcosThetam = cos(lm.Theta());
  TcosThetap = cos(lp.Theta());
 
  for (Int_t i=0; i<leptonSelect.size(); i++) {
    TLepSel_Charge[i] = leptonSelect[i].charge();
    TLepSel_Px[i] = leptonSelect[i].lorentzVec().Px();
    TLepSel_Py[i] = leptonSelect[i].lorentzVec().Py();
    TLepSel_Pz[i] = leptonSelect[i].lorentzVec().Pz();
    TLepSel_E[i] = leptonSelect[i].lorentzVec().E();
  }
  for (Int_t i=0; i<jetSelect.size(); i++) {
    TJetSel_discriminant[i] = jetSelect[i].btag_disc();
    TJetSel_Px[i] = jetSelect[i].lorentzVec().Px();
    TJetSel_Py[i] = jetSelect[i].lorentzVec().Py();
    TJetSel_Pz[i] = jetSelect[i].lorentzVec().Pz();
    TJetSel_E[i] = jetSelect[i].lorentzVec().E();
  }
    
  for (Int_t i=0; i<muonColl.size(); i++) {
    TMuon_Charge[i] = muonColl[i].charge();
    TMuon_Px[i] = muonColl[i].lorentzVec().Px();
    TMuon_Py[i] = muonColl[i].lorentzVec().Py();
    TMuon_Pz[i] = muonColl[i].lorentzVec().Pz();
    TMuon_E[i] = muonColl[i].lorentzVec().E();
  }
  for (UInt_t i=0; i<electronColl.size(); i++) {
    TElec_Charge[i] = electronColl[i].charge();
    TElec_Px[i] = electronColl[i].lorentzVec().Px();
    TElec_Py[i] = electronColl[i].lorentzVec().Py();
    TElec_Pz[i] = electronColl[i].lorentzVec().Pz();
    TElec_E[i] = electronColl[i].lorentzVec().E();
  }
  for (int i=0; i<jetColl.size(); i++) {
    TJet_discriminant[i] = jetColl[i].btag_disc();
    TJet_Px[i] = jetColl[i].lorentzVec().Px();
    TJet_Py[i] = jetColl[i].lorentzVec().Py();
    TJet_Pz[i] = jetColl[i].lorentzVec().Pz();
    TJet_E[i] = jetColl[i].lorentzVec().E();
  }
  for (int i=0; i<bjetColl.size(); i++) {
    TBJet_Px[i] = bjetColl[i].lorentzVec().Px();
    TBJet_Py[i] = bjetColl[i].lorentzVec().Py();
    TBJet_Pz[i] = bjetColl[i].lorentzVec().Pz();
    TBJet_E[i] = bjetColl[i].lorentzVec().E();		
  }
  AnalysisTree->Fill();
}
void FillTandG::SetGenVariables(TTree *AnalysisTree, vector<Lepton>& genElec, vector<Lepton>& genNuElec, vector<Lepton>& genMuon, vector<Lepton>& genNuMuon,vector<Jet>& genBquark, vector<Lepton>& leptonGetColl, vector<Jet>& jetGetColl, Float_t met_genPt, Float_t met_genPhi) {

  ///Gen matched collection
  noleptons = false;
  selectLept.clear();
  GMT2lblb = -10.;
  GMT2bb = -10.;
  GMT2ll = -10.;
  GMET = met_genPt;
  GMET_Phi = met_genPhi;
  GNJets = jetGetColl.size();
  GNMuon = genMuon.size();
  GNElec = leptonGetColl.size();
  if (genMuon.size()==2 && genElec.size()==0) {
    selectLept.push_back(genMuon[0]);
    selectLept.push_back(genMuon[1]);
    // MET = genNuMuon[0].lorentzVec()+genNuMuon[1].lorentzVec();
    // MET_pt = genNuMuon[0].lorentzVec().Pt()+genNuMuon[1].lorentzVec().Pt();
    // MET_phi = genNuMuon[0].lorentzVec().Phi()+genNuMuon[1].lorentzVec().Phi();
  }
  else if (genMuon.size()==0 && genElec.size()==2) {
    selectLept.push_back(genElec[0]);
    selectLept.push_back(genElec[1]);
    // MET = genNuElec[0].lorentzVec()+genNuElec[1].lorentzVec();
    //  MET_pt = genNuElec[0].lorentzVec().Pt()+genNuElec[1].lorentzVec().Pt();
    //  MET_phi = genNuElec[0].lorentzVec().Phi()+genNuElec[1].lorentzVec().Phi();
  }
  else if (genMuon.size()==1 && genElec.size()==1) {
    selectLept.push_back(genMuon[0]);
    selectLept.push_back(genElec[0]);
    //   MET = genNuMuon[0].lorentzVec()+genNuElec[0].lorentzVec();
    //  MET_pt = genNuMuon[0].lorentzVec().Pt()+genNuElec[0].lorentzVec().Pt();
    //  MET_phi = genNuMuon[0].lorentzVec().Phi()+genNuElec[0].lorentzVec().Phi();
  }
  else
    noleptons = true;

  if(!noleptons) {
    GMT2ll = getMT2(leptonGetColl[0].lorentzVec(), leptonGetColl[1].lorentzVec(), met_genPt, met_genPhi);
    if (jetGetColl.size()>1) {
      GMT2bb = getMT2bb(jetGetColl, leptonGetColl, met_genPt, met_genPhi);
      GMT2lblb = getMT2lblb(jetGetColl, leptonGetColl, met_genPt, met_genPhi);
    }
  }
  for (int i=0; i<leptonGetColl.size(); i++) {
    if (true) {
      GElec_Px[i] = leptonGetColl[i].lorentzVec().Px();
      GElec_Py[i] = leptonGetColl[i].lorentzVec().Py();
      GElec_Pz[i] = leptonGetColl[i].lorentzVec().Pz();
      GElec_E[i] = leptonGetColl[i].lorentzVec().E();
    }
    else if (leptonGetColl[i].leptonType()==0) {
      GMuon_Px[i] = leptonGetColl[i].lorentzVec().Px();
      GMuon_Py[i] = leptonGetColl[i].lorentzVec().Py();
      GMuon_Pz[i] = leptonGetColl[i].lorentzVec().Pz();
      GMuon_E[i] = leptonGetColl[i].lorentzVec().E();
    }
    else {
      cout << "lepton not defined in FillTandG" << endl;
      return;
    }
  }
  
  for (int i=0; i<jetGetColl.size(); i++) {
    GJet_discriminant[i] = jetGetColl[i].btag_disc();
    GJet_Px[i] = jetGetColl[i].lorentzVec().Px();
    GJet_Py[i] = jetGetColl[i].lorentzVec().Py();
    GJet_Pz[i] = jetGetColl[i].lorentzVec().Pz();
    GJet_E[i] = jetGetColl[i].lorentzVec().E();
  }

  HMT2lblb = -10.;
  HMT2bb = -10.;
  HMT2ll = -10.;
  HNJetsBtag = genBquark.size();
  HNMuon = genMuon.size();
  HNElec = genElec.size();

  /// from the hard scattering process
  for (int i=0; i<genBquark.size(); i++) {
    HBJet_Px[i] = genBquark[i].lorentzVec().Px();
    HBJet_Py[i] = genBquark[i].lorentzVec().Py();
    HBJet_Pz[i] = genBquark[i].lorentzVec().Pz();
    HBJet_E[i] = genBquark[i].lorentzVec().E();		
  }
  for (Int_t i=0; i<genMuon.size(); i++) {
    HMuon_Px[i] = genMuon[i].lorentzVec().Px();
    HMuon_Py[i] = genMuon[i].lorentzVec().Py();
    HMuon_Pz[i] = genMuon[i].lorentzVec().Pz();
    HMuon_E[i] = genMuon[i].lorentzVec().E();
  }
  for (UInt_t i=0; i<genElec.size(); i++) {
    HElec_Px[i] = genElec[i].lorentzVec().Px();
    HElec_Py[i] = genElec[i].lorentzVec().Py();
    HElec_Pz[i] = genElec[i].lorentzVec().Pz();
    HElec_E[i] = genElec[i].lorentzVec().E();
  }
  HMET = MET.Pt();
  HMET_Phi = MET.Phi();
  if(!noleptons) {
    HMT2ll = getMT2(selectLept[0].lorentzVec(), selectLept[1].lorentzVec(), met_genPt, met_genPhi);
    if (genBquark.size()>1) {
      HMT2bb = getMT2bb(genBquark, selectLept, met_genPt, met_genPhi);
      HMT2lblb = getMT2lblb(genBquark, selectLept, met_genPt, met_genPhi);
    }
  }
}

void FillTandG::FillVariables(TTree *AnalysisTree) {
  AnalysisTree->Fill();
}

void FillTandG::WriteVariables(TTree *AnalysisTree) {
  AnalysisTree->Write();
}
