#ifndef MuonPlots_h
#define MuonPlots_h

#include "StdPlots.h"
#include "LeptonSelection.h"

class MuonPlots : public StdPlots{
 public:
  TH1F *h_charge, *h_PF_RelIso, *h_GlbChi2, *h_dxy, *h_dz;
  MuonPlots(TString name);
  ~MuonPlots();
  void Fill(Float_t weight, Int_t N, TLorentzVector vLepton, Int_t charge, Float_t relIso, Float_t Muon_GlobalChi2, Float_t dxy, Float_t dz);
  void Write();

};

#endif
