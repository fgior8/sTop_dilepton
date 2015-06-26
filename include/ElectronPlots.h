#ifndef ElectronPlots_h
#define ElectronPlots_h

#include "StdPlots.h"
#include "Data.h"
#include "LeptonSelection.h"

class ElectronPlots : public StdPlots{

 public:
  TH1F *h_charge, *h_PF_RelIso, *h_PF_RelIso_beta, *h_dxy, *h_dz, *h_photonIso, *h_chargedHadronIso, *h_neutralHadronIso, *h_PUpt;
  ElectronPlots(TString name);
  ~ElectronPlots();
  void Fill(Float_t weight, Int_t N, TLorentzVector vLepton, Int_t charge, Float_t chargedHadronIso, Float_t neutralHadronIso, Float_t photonIso, Float_t PUpt, Float_t dxy, Float_t dz);
  void Write();

};

#endif
