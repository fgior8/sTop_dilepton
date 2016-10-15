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
#include "GenParticleSelection.h"
#include <iostream>
#include <cmath>

using namespace std;

class Analyzer : public Data {

  const Bool_t debug = false;
  const Bool_t SaveTree = true;
  const Bool_t Blind = true;
  const Double_t integratedlumi = 12888.609;
  const Double_t MuTriggersLumi = 12888.609;
  const Double_t ElTriggersLumi = 11394.929;
//  static const Double_t integratedlumi = 1.0; //for Fakes
  const Double_t Mass_Z = 91.1876;
  const Double_t Mass_W = 80.398;
  enum Variation {CentralValue, JetEnUp, JetEnDown, JetResUp, JetResDown, MuonEnUp, MuonEnDow, ElectronEnUp, ElectronEnDown, TauEnUp, TauEnDown, UnclusteredEnUp, UnclusteredEnDown};

  //SF parametrization
  TFile *MuSF_trig, *ElSF_trig, *MuElSF_trig;
  TFile *MuSF_ID, *MuSF_ISO, *ElSF_IDISO;
  TH2F *hmuIDSF, *hmuISOSF, *hmumuTriggerSF8, *hmumuTriggerSF17;
  TH2F *heIDSF, *heeTriggerSF12, *heeTriggerSF23;
  TH2F *hmueTriggerSF;
  Float_t ptSFlimit;
  //SF

  Bool_t isData, MCatNLO;
  Bool_t isDoubleEl, isMuEG, isDoubleMu;
  TString completename, treename;
  TFile *outfile;
  Long64_t entrieslimit;
  ReweightPU *reweightPU;
  BTagSFUtil *BTagSF;
  
  TDirectory *Dir;
  Int_t index;
  UInt_t channel, cut, cutZDY;
  Bool_t *goodVerticies;
  UInt_t numberVertices, VertexN;
  MuonSel Muon;
  ElectronSel Electron;
  JJ Jets;
  GenSelection GenPart;

  MuonPlots ***h_muons;
  ElectronPlots ***h_electrons;
  JetPlots ***h_jets, ***h_bjets, ***h_HTjets;
  SignalPlots ***h_signal;
  SignalPlots ****h_systematics;
  ZDYPlots ***h_ZDYplots;
  
  UInt_t ncuts, nchannels, nsystematics;
  vector<Int_t> selectionStep; vector<Int_t> selectChannel; vector<Int_t> selectionStepZDY;
  vector<Lepton> muonColl; vector<Lepton> muonCollLoose; vector<Lepton> electronColl; vector<Lepton> electronCollLoose;
  vector<Lepton> genElec, genMuon, genNuElec, genNuMuon;
  vector<Jet> jetColl[14]; vector<Jet> bjetColl[14]; vector<Jet> jetHTColl[14];
  vector<Jet> jetSelect; vector<Jet> jetGenColl; vector<Jet> hardBquark;
  vector<Lepton> leptonSelect;  vector<Lepton> leptonGenColl;
  vector<TLorentzVector> genLightquark;

  Float_t HT, met_cut;
  Bool_t Zveto;
  Float_t invMtemp;
  Float_t MCweight, weight;
 
  
  TH1F *h_prova;
  TH1F *h_VertexNoReweight, *h_VertexPostReweight;

 protected:
  ///Tree for optimization//////
  TFile *outfileTree;
  // Trees
  TTree *AnalysisTree;

  //done optimization tree variables

 public:
  static const Bool_t MC_pu = false; 


  Analyzer();
  ~Analyzer();
  void Loop();
  void SetWeight(TString name, Long64_t eventProcessed);
  void SetName(TString name, Int_t version);
  void SetEvtN(Long64_t events);

};
#endif
