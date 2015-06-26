#ifndef MuonPlots_h
#define MuonPlots_h

#include "StdPlots.h"
#include "LeptonSelection.h"

class MuonPlots : public StdPlots{
 public:
  TH1F *h_charge, *h_HCalIso, *h_ECalIso, *h_TrkIso, *h_Detector_RelIso, *h_Detector_RelIsorho, *h_HCalIsoDeposit, *h_ECalIsoDeposit, *h_photonIso, *h_chargedHadronIso, *h_neutralHadronIso, *h_PF_RelIso, *h_PF_RelIso_beta, *h_PUpt, *h_GlbChi2, *h_dxy, *h_dz;
  MuonPlots(TString name);
  ~MuonPlots();
  void Fill(Float_t weight, Int_t N, TLorentzVector vLepton, Int_t charge, Float_t chargedHadronIso, Float_t neutralHadronIso, Float_t photonIso, Float_t PUpt, Float_t Muon_GlobalChi2, Float_t dxy, Float_t dz);
  void Write();

};

#endif
