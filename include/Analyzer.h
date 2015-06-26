#ifndef Analyzer_h
#define Analyzer_h

#include <set>
#include "TTree.h"
#include "Prova.h"
#include "TH2F.h"
#include "Reweight.h"
#include "BTagSFUtil.h"
#include "SignalPlots.h"
#include "MuonPlots.h"
#include "ElectronPlots.h"
#include "JetPlots.h"
#include "XSlist.h"

#include "Lepton.h"
#include "OtherFunctions.h"
#include "SelectionFunctions.h"
#include "MuonSelection.h"
#include "ElectronSelection.h"
#include "JetSelection.h"

#include <iostream>
#include <cmath>

using namespace std;

class Analyzer : public Prova {


  static const Bool_t debug = false; 
  static const Double_t integratedlumi = 19762.501;
//  static const Double_t integratedlumi = 1.0; //for Fakes
  static const Double_t Mass_Z = 91.1876;
  static const Double_t Mass_W = 80.398;

  TString completename, treename;
  TFile *outfile;
  Long64_t entrieslimit;
  ReweightPU *reweightPU;
  BTagSFUtil *fBTagSF;
  
  TDirectory *Dir;
  Int_t index;
  Bool_t *goodVerticies;
  Float_t HT;
  UInt_t numberVertices, VertexN;
  MuonSel Muon;
  ElectronSel Electron;
  JJ Jets;

  MuonPlots ***h_muons;
  ElectronPlots ***h_electrons;
  JetPlots ***h_jets, ***h_bjets;
  SignalPlots ***h_signal;
  
  UInt_t ncuts, nchannels;
  vector<Int_t> selectionStep;
  vector<Int_t> selectChannel;
  Bool_t Zveto;
  Float_t MCweight, weight;

 
  
  TH1F *h_prova;


  ///Tree for optimization//////
  TFile *outfileTree;
  // Trees
  TTree *AnalysisTree;
  // Branches
  int TNPV;
  int TNJets;     
  int TNJetsBtag;
  int TNMuon;
  int TNElec;
  float TWeight;
  float TMET;
  float TMET_Phi;
  float THT;
  float TMT2ll;
  float TMT2bb;
  float TMT2lblb;
  TLorentzVector TMuon_Lorentz[20];
  TLorentzVector TElec_Lorentz[20];
  TLorentzVector TJet_Lorentz[50];
  Float_t TJet_discriminant[50];
  TLorentzVector TBJet_Lorentz[30];
  Float_t TMuon_Charge[20];
  Float_t TElec_Charge[20];

  //done optimization tree variables

 public:
  static const Bool_t MC_pu = false; 


  Analyzer();
  ~Analyzer();
  void Loop();
  void SetWeight(TString name);
  void SetName(TString name, Int_t version);
  void SetEvtN(Long64_t events);

};
#endif
