#ifndef SignalPlots_h
#define SignalPlots_h

#include <string>
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "Lepton.h"
#include "Jet.h"
#include "TVector3.h"
#include <iostream>
#include "OtherFunctions.h"

class SignalPlots {
  UInt_t i,j,m,n;
  Float_t dijetmass_tmp, dijetmass;
  static const Float_t Mass_W = 80.398;
  TLorentzVector MET_tv, lp, lm;
  TVector3 dilep_beta;
 
 public:
  TH1F *h_jjmass, *h_llmass, *h_lljjmass, *h_MET, *h_MET_phi, *h_METexp;
  TH1F *h_dilepPt, *h_HT, *h_MET2HT;
  TH1F *h_cosTheta1, *h_cosTheta2;
  TH1F *h_DeltaPhiLep1, *h_DeltaPhiLep2, *h_DeltaPhiZ, *h_DeltaPhiJet1, *h_DeltaPhiJet2, *h_DeltaPhiJetMin;
  TH1F *h_PV;
  TH1F *h_MT2ll, *h_MT2bb, *h_MT2lblb;
  TH2F *h_MT2ll_DeltaPhiZ, *h_MT2ll_DeltaPhiJetMin;
  TH2F *h_MT2ll_CosTheta;
  TH3F *h3_MT2;
  
  SignalPlots(TString name);
  ~SignalPlots();
  void Fill(UInt_t numberVertices, Float_t MET, Float_t MET_phi, Float_t HT, std::vector<Lepton>& leptons, std::vector<Jet>& jets, Float_t weight, Int_t channel, Int_t cut);
  void Write();

};


#endif
