#ifndef FillTandG_h
#define FillTandG_h

#include "Analyzer.h"

class FillTandG {
  
  static const Bool_t debug = false;
  Bool_t noleptons;
  TLorentzVector lp, lm, MET;
  Float_t MET_pt, MET_phi;
  TVector3 dilep_beta;
  vector<Lepton> selectLept;

  // Branches
  Int_t TNPV;
  Int_t TNJets;     
  Int_t TNJetsBtag;
  Int_t TNLepSel;
  Int_t TNJetSel;
  Int_t TNMuon;
  Int_t TNElec;
  Float_t TWeight;
  Float_t TMET;
  Float_t TMET_Phi;
  Float_t THT;
  Float_t TMT2ll;
  Float_t TMT2bb;
  Float_t TMT2lblb;
  Float_t TMll;
  Float_t TPtllb;
  Float_t TMeff;
  Float_t TdPhiPtllbMET;
  Float_t TdPhiJetMet;
  Float_t TdPhiLepMet;
  Float_t TdPhiLepJet;
  Float_t TdPhill;
  Float_t TcosThetap;
  Float_t TcosThetam;
  Float_t TLepSel_Px[2];
  Float_t TLepSel_Py[2];
  Float_t TLepSel_Pz[2];
  Float_t TLepSel_E[2];
  Float_t TJetSel_discriminant[2];
  Float_t TJetSel_Px[2];
  Float_t TJetSel_Py[2];
  Float_t TJetSel_Pz[2];
  Float_t TJetSel_E[2];
  Float_t TMuon_Px[20];
  Float_t TMuon_Py[20];
  Float_t TMuon_Pz[20];
  Float_t TMuon_E[20];
  Float_t TElec_Px[20];
  Float_t TElec_Py[20];
  Float_t TElec_Pz[20];
  Float_t TElec_E[20];
  Float_t TJet_Px[50];
  Float_t TJet_Py[50];
  Float_t TJet_Pz[50];
  Float_t TJet_E[50];
  Float_t TJet_discriminant[50];
  Float_t TBJet_Px[30];
  Float_t TBJet_Py[30];
  Float_t TBJet_Pz[30];
  Float_t TBJet_E[30];
  Float_t TLepSel_Charge[2];
  Float_t TMuon_Charge[20];
  Float_t TElec_Charge[20];
  
  //Gen variables
  Int_t GNJets;     
  Int_t GNMuon;
  Int_t GNElec;
  // Float_t GWeight;
  Float_t GMET;
  Float_t GMET_Phi;
  //Float_t GHT;
  Float_t GMT2ll;
  Float_t GMT2bb;
  Float_t GMT2lblb;
  /*
  Float_t GMll;
  Float_t GPtllb;
  Float_t GMeff;
  Float_t GdPhiPtllbMET;
  Float_t GdPhiJetMet;
  Float_t GdPhiLepMet;
  Float_t GdPhiLepJet;
  Float_t GdPhill;
  Float_t GcosThetap;
  Float_t GcosThetam;
  */
  Float_t GMuon_Px[20];
  Float_t GMuon_Py[20];
  Float_t GMuon_Pz[20];
  Float_t GMuon_E[20];
  Float_t GElec_Px[20];
  Float_t GElec_Py[20];
  Float_t GElec_Pz[20];
  Float_t GElec_E[20];
  Float_t GJet_Px[50];
  Float_t GJet_Py[50];
  Float_t GJet_Pz[50];
  Float_t GJet_E[50];
  Float_t GJet_discriminant[50];
  
  //Float_t GMuon_Charge[20];
  //Float_t GElec_Charge[20];

  //Hard scattering variables
  // Int_t HNJets;     
  Int_t HNJetsBtag;
  Int_t HNMuon;
  Int_t HNElec;
  // Float_t HWeight;
  Float_t HMET;
  Float_t HMET_Phi;
  //Float_t HHT;
  Float_t HMT2ll;
  Float_t HMT2bb;
  Float_t HMT2lblb;
  /*
  Float_t GMll;
  Float_t GPtllb;
  Float_t GMeff;
  Float_t GdPhiPtllbMET;
  Float_t GdPhiJetMet;
  Float_t GdPhiLepMet;
  Float_t GdPhiLepJet;
  Float_t GdPhill;
  Float_t GcosThetap;
  Float_t GcosThetam;
  */
  Float_t HMuon_Px[20];
  Float_t HMuon_Py[20];
  Float_t HMuon_Pz[20];
  Float_t HMuon_E[20];
  Float_t HElec_Px[20];
  Float_t HElec_Py[20];
  Float_t HElec_Pz[20];
  Float_t HElec_E[20];
  Float_t HJet_Px[50];
  Float_t HJet_Py[50];
  Float_t HJet_Pz[50];
  Float_t HJet_E[50];
  Float_t HBJet_Px[30];
  Float_t HBJet_Py[30];
  Float_t HBJet_Pz[30];
  Float_t HBJet_E[30];
  
  //Float_t GMuon_Charge[20];
  //Float_t GElec_Charge[20];

 public:
  FillTandG(TTree *AnalysisTree);
  ~FillTandG();
  void SetRecoVariables(TTree *AnalysisTree, Float_t weight, Int_t numberVertices, vector<Jet>& jetSelect, vector<Lepton>& leptonSelect, Float_t theMET, Float_t theMETphi, Float_t HT, vector<Lepton>& muonColl, vector<Lepton>& electronColl, vector<Jet>& jetColl, vector<Jet>& bjetColl);
  void SetGenVariables(TTree *AnalysisTree, vector<Lepton>& genElec, vector<Lepton>& genNuElec, vector<Lepton>& genMuon, vector<Lepton>& genNuMuon, vector<Jet>& genBquark, vector<Lepton>& leptonGetColl, vector<Jet>& jetGetColl, Float_t met_genPt, Float_t met_genPhi);
  void FillVariables(TTree *AnalysisTree);
  void WriteVariables(TTree *AnalysisTree);
};
#endif
