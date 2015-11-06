#ifndef ElectronPlots_h
#define ElectronPlots_h

#include "StdPlots.h"
#include "LeptonSelection.h"

class ElectronPlots : public StdPlots{

 public:
  TH1F *h_charge, *h_PF_RelIso, *h_dxy, *h_dz;
  ElectronPlots(TString name);
  ~ElectronPlots();
  void Fill(Float_t weight, Int_t N, TLorentzVector vLepton, Int_t charge, Float_t relIso, Float_t dxy, Float_t dz);
  void Write();

};

#endif
