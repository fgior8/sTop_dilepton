#ifndef MuonSelection_h
#define MuonSelection_h

#include "LeptonSelection.h"

class MuonSel : public Lep {
  Int_t numVer, leptoni;
  Double_t ECalDeposit_max, HCalDeposit_max, ECalDeposit_min, HCalDeposit_min;
//  Double_t MuTkIso, MuEcalIso, MuHcalIso;
  static const Double_t AreaTrackerMu[5];
  static const Double_t AreaEcalMu[5];
  static const Double_t AreaHcalMu[5];

 public:
  MuonSel();
  ~MuonSel();

  void MuonSelection(Int_t nMuon, Int_t *pdgId, Int_t *IsPF, Float_t *Eta, Float_t *Pt, Float_t *Px, Float_t *Py, Float_t *Pz, Float_t *E, Float_t *relIso, Int_t *Charge, Int_t *ValidHits, Int_t *PixelValidHits, Float_t *ValidStations, Int_t *LayersWithMeasurement, Float_t *GlobalChi2, Float_t *dxy_ver, Float_t *dz_ver, std::vector<Lepton>& leptonColl);

  void MuonSelectionWithLoose(Int_t nMuon, Int_t *pdgId, Int_t *IsPF, Int_t *IsGlobal, Int_t *IsTracker, Float_t *Eta, Float_t *Pt, Float_t *Px, Float_t *Py, Float_t *Pz, Float_t *E, Float_t *relIso, Int_t *Charge, Int_t *ValidHits, Int_t *PixelValidHits, Float_t *ValidStations, Int_t *LayersWithMeasurement, Float_t *GlobalChi2, Float_t *dxy_ver, Float_t *dz_ver, Int_t *mcMatchId, std::vector<Lepton>& leptonColl, std::vector<Lepton>& leptonCollLoose);

  void SetDeposits(Double_t ECalDeposit, Double_t HCalDeposit);
  void SetDeposits(Double_t ECalDeposit1 , Double_t HCalDeposit1, Double_t ECalDeposit2 , Double_t HCalDeposit2);

};

#endif
