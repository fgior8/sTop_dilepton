#ifndef ResAnalyzer_h
#define ResAnalyzer_h

#include <set>
#include "TTree.h"
#include "ResolutionTree.h"
#include "TH2F.h"
#include "TF1.h"
#include "TLorentzVector.h"
#include "TCutG.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "OtherFunctions.h"

#include <iostream>
#include <cmath>

using namespace std;

class ResAnalyzer : public ResolutionTree {

  static const Bool_t debug = false;
  Lepton::FakeType fakeType;
  Lepton::LooseTight looseTight;
  Lepton::LeptonType leptonType;
  
  TFile *outfile;
  TString completename;
  TH1F *h_prova;
  TH2F *h2_jetPtRes_leading, *h2_jetERes_leading;
  TH2F *h2_MT2bbRes_noB, *h2_MT2bbRes_oneB, *h2_MT2bbRes_twoB;
  TH1D *h_MT2bbRes_noB, *h_MT2bbRes_oneB, *h_MT2bbRes_twoB;

 public:
  ResAnalyzer();
  ~ResAnalyzer();
  void SetName(TString name, Int_t version);
  void Loop();
};

#endif
