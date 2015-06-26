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

  void MuonSelection(std::vector<Bool_t> IsPF, std::vector<Bool_t> IsGlobal, std::vector<Float_t> Eta, std::vector<Float_t> Pt, std::vector<Float_t> PtErr, std::vector<Float_t> Px, std::vector<Float_t> Py, std::vector<Float_t> Pz, std::vector<Float_t> E, std::vector<Float_t> ChargedIso, std::vector<Float_t> NeutralIso, std::vector<Float_t> PhotonIso, std::vector<Int_t> Charge, std::vector<Int_t> ValidHits, std::vector<Int_t> PixelValidHits, std::vector<Int_t> ValidStations, std::vector<Int_t> LayersWithMeasurement, std::vector<Float_t> GlobalChi2, std::vector<Float_t> TrkIPToolsIP, std::vector<Float_t> TrkIPToolsZ, std::vector<Float_t> PUpt, std::vector<Lepton>& leptonColl);

  void LooseMuonSelection(std::vector<Int_t> IsPF, std::vector<Int_t> IsTracker, std::vector<Int_t> IsGlobal, std::vector<Double_t> Eta, std::vector<Double_t> Phi, std::vector<Double_t> Pt, std::vector<Double_t> PtErr, std::vector<Double_t> E, std::vector<Double_t> TrkIso, std::vector<Double_t> ECalIso, std::vector<Double_t> HCalIso, std::vector<Double_t> ECalIsoDeposit, std::vector<Double_t> HCalIsoDeposit, std::vector<Int_t> Charge, std::vector<Int_t> ValidHits, std::vector<Int_t> PixelValidHits, std::vector<Int_t> ValidStations, std::vector<Int_t> LayersWithMeasurement, std::vector<Double_t> GlobalChi2, std::vector<Double_t> Trkdx, std::vector<Double_t> Trkdy, std::vector<Double_t> Trkdz, std::vector<Double_t> TrkIPToolsIP, std::vector<Double_t> TrkIPToolsIPError, Double_t Vertex_X, Double_t Vertex_Y, Double_t Vertex_Z, std::vector<Double_t> PUpt, std::vector<Lepton>& leptonColl);

  void SetDeposits(Double_t ECalDeposit, Double_t HCalDeposit);
  void SetDeposits(Double_t ECalDeposit1 , Double_t HCalDeposit1, Double_t ECalDeposit2 , Double_t HCalDeposit2);

};
/*
const Double_t MuonSel::AreaTrackerMu[5] = {0., 0., 0., 0., 0.};         	  //   barrel/endcap
const Double_t MuonSel::AreaEcalMu[5]    = {0.091, 0.077, 0.055, 0.034, 0.046};   //   barrel/endcap
const Double_t MuonSel::AreaHcalMu[5]    = {0.029, 0.027, 0.036, 0.040, 0.054};   //   barrel/endcap
*/
#endif
