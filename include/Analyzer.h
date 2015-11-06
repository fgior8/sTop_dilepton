#ifndef Analyzer_h
#define Analyzer_h

#include <set>
#include "TTree.h"
#include "Data.h"
#include "TH2F.h"
#include "Reweight.h"
#include "BTagSFUtil.h"
#include "SignalPlots.h"
#include "MuonPlots.h"
#include "ElectronPlots.h"
#include "JetPlots.h"
#include "ZDYPlots.h"
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

class Analyzer : public Data {


  static const Bool_t debug = false;
  static const Bool_t SaveTree = false;
  static const Bool_t Blind = true;
  static const Double_t integratedlumi = 1260.;
//  static const Double_t integratedlumi = 1.0; //for Fakes
  static const Double_t Mass_Z = 91.1876;
  static const Double_t Mass_W = 80.398;
  enum Variation {CentralValue, JetEnUp, JetEnDown, JetResUp, JetResDown, MuonEnUp, MuonEnDow, ElectronEnUp, ElectronEnDown, TauEnUp, TauEnDown, UnclusteredEnUp, UnclusteredEnDown};

  //SF parametrization
  TFile *MuSF_trig, *ElSF_trig, *MuElSF_trig;
  TFile *MuSF_IDISO, *ElSF_IDISO;
  TH2F *hmuIDSF, *hmumuTriggerSF;
  TH2F *heIDSF, *heeTriggerSF;
  TH2F *hmueTriggerSF;
  //SF

  Bool_t isData, MCatNLO;
  Bool_t isDoubleEl, isMuEG, isDoubleMu;
  TString completename, treename;
  TFile *outfile;
  Long64_t entrieslimit;
  ReweightPU *reweightPU;
  BTagSFUtil *fBTagSF;
  
  TDirectory *Dir;
  Int_t index;
  UInt_t channel, cut, cutZDY;
  Bool_t *goodVerticies;
  UInt_t numberVertices, VertexN;
  MuonSel Muon;
  ElectronSel Electron;
  JJ Jets;

  MuonPlots ***h_muons;
  ElectronPlots ***h_electrons;
  JetPlots ***h_jets, ***h_bjets, ***h_HTjets;
  SignalPlots ***h_signal;
  SignalPlots ****h_systematics;
  ZDYPlots ***h_ZDYplots;
  
  UInt_t ncuts, nchannels, nsystematics;
  vector<Int_t> selectionStep; vector<Int_t> selectChannel; vector<Int_t> selectionStepZDY;
  vector<Lepton> muonColl; vector<Lepton> electronColl;
  vector<Jet> jetColl[14]; vector<Jet> bjetColl[14]; vector<Jet> jetHTColl[14];
  vector<Jet> jetSelect; vector<Lepton> leptonSelect;

  Float_t HT, met_cut;
  Bool_t Zveto;
  Float_t invMtemp;
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
