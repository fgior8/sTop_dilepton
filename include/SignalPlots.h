#ifndef SignalPlots_h
#define SignalPlots_h

#include <string>
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "Lepton.h"
#include "Jet.h"
#include <iostream>
#include "OtherFunctions.h"

class SignalPlots {
  UInt_t i,j,m,n;
  Float_t dijetmass_tmp, dijetmass;
  static const Float_t Mass_W = 80.398;
 
 public:
  TH1F *h_jjmass, *h_llmass, *h_lljjmass, *h_MET, *h_MET_phi;
  TH1F  *h_dilepPt;
  TH1F *h_cosTheta1, *h_cosTheta2;
  TH1F *h_DeltaPhi;
  TH1F *h_PV;
  TH1F *h_MT2ll, *h_MT2bb, *h_MT2lblb;
  
  SignalPlots(TString name);
  ~SignalPlots();
  void Fill(UInt_t numberVertices, Float_t MET, Float_t MET_phi, std::vector<Lepton>& leptons, std::vector<Jet>& jets, Float_t weight, Int_t channel, Int_t cut);
  void Write();

};


#endif
