#ifndef ElectronSelection_h
#define ElectronSelection_h

#include "LeptonSelection.h"

class ElectronSel : public Lep {
  
  Bool_t ElectronID;
  Double_t ElTkIso, ElEcalIso, ElHcalIso;
  static const Double_t AreaTrackerEle[2];
  static const Double_t AreaEcalEle[2];
  static const Double_t AreaHcalEle[2];
  static const Double_t PHONH[7];

 public:
  ElectronSel();
  ~ElectronSel();

  void ElectronSelection(std::vector<Bool_t> isEB, std::vector<Bool_t> isEE, std::vector<Float_t> Eta, std::vector<Float_t> Pt, std::vector<Float_t> E, std::vector<Float_t> Px, std::vector<Float_t> Py, std::vector<Float_t> Pz, std::vector<Float_t> TrkIso, std::vector<Float_t> ECalIso, std::vector<Float_t> HCalIso, std::vector<Int_t> Charge, std::vector<Int_t> MissingHits, std::vector<Bool_t> passConversionVeto, std::vector<Float_t> DeltaEtaTrkSC, std::vector<Float_t> DeltaPhiTrkSC, std::vector<Float_t> SigmaIEtaIEta, std::vector<Float_t> HoE, std::vector<Float_t> caloEnergy, std::vector<Float_t> SuperClusterOverP, std::vector<Float_t> Trkdxy, std::vector<Float_t> Trkdz, std::vector<Float_t> PUpt, std::vector<Lepton>& leptonColl); 

void ElectronSelectionLoose(std::vector<Int_t> isID, std::vector<Bool_t> isEB, std::vector<Bool_t> isEE, std::vector<Bool_t> TrackerDrivenSeed, std::vector<Bool_t> EcalDrivenSeed, std::vector<Double_t> Eta, std::vector<Double_t> Phi, std::vector<Double_t> Pt, std::vector<Double_t> E, std::vector<Double_t> TrkIso, std::vector<Double_t> ECalIso, std::vector<Double_t> HCalIso, std::vector<Int_t> Charge, std::vector<Bool_t> ChargeConsistency, std::vector<Int_t> MissingHits, std::vector<Bool_t> HasMatchedConvPhot, std::vector<Double_t> DeltaEtaTrkSC, std::vector<Double_t> DeltaPhiTrkSC, std::vector<Double_t> SigmaIEtaIEta, std::vector<Double_t> HoE, std::vector<Double_t> caloEnergy, std::vector<Double_t> SuperClusterOverP, std::vector<Double_t> Trkdx, std::vector<Double_t> Trkdy, std::vector<Double_t> Trkdz, Double_t Vertex_X, Double_t Vertex_Y, Double_t Vertex_Z, Double_t rho, std::vector<Lepton>& leptonColl);

};

//const Double_t ElectronSel::AreaTrackerEle[2] = {0., 0.};         //   barrel/endcap
//const Double_t ElectronSel::AreaEcalEle[2]    = {0.101, 0.046};   //   barrel/endcap
//const Double_t ElectronSel::AreaHcalEle[2]    = {0.021 , 0.040};  //   barrel/endcap
//const Double_t ElectronSel::PHONH[7]          = {0.13, 0.14, 0.07, 0.09, 0.11, 0.11, 0.14};

#endif
