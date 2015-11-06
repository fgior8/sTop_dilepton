#ifndef ElectronSelection_h
#define ElectronSelection_h

#include "LeptonSelection.h"

class ElectronSel : public Lep {
  
  Bool_t ElectronID, isEB, isEE;
  Double_t ElTkIso, ElEcalIso, ElHcalIso;

 public:
  ElectronSel();
  ~ElectronSel();

  void ElectronSelection(Int_t *pdgId, Float_t *EtaSc, Float_t *Pt, Float_t *Px, Float_t *Py, Float_t *Pz, Float_t *E, Float_t *relIso, Int_t *Charge, Int_t *passConversionVeto, Int_t *MissingHits, Float_t *DeltaEtaTrkSC, Float_t *DeltaPhiTrkSC, Float_t *SigmaIEtaIEta, Float_t *HoE, Float_t *eInvMinusPInv, Float_t *dxy_var, Float_t *dz_var, std::vector<Lepton>& leptonColl); 

void ElectronSelectionLoose(std::vector<Int_t> isID, std::vector<Bool_t> isEB, std::vector<Bool_t> isEE, std::vector<Bool_t> TrackerDrivenSeed, std::vector<Bool_t> EcalDrivenSeed, std::vector<Double_t> Eta, std::vector<Double_t> Phi, std::vector<Double_t> Pt, std::vector<Double_t> E, std::vector<Double_t> TrkIso, std::vector<Double_t> ECalIso, std::vector<Double_t> HCalIso, std::vector<Int_t> Charge, std::vector<Bool_t> ChargeConsistency, std::vector<Int_t> MissingHits, std::vector<Bool_t> HasMatchedConvPhot, std::vector<Double_t> DeltaEtaTrkSC, std::vector<Double_t> DeltaPhiTrkSC, std::vector<Double_t> SigmaIEtaIEta, std::vector<Double_t> HoE, std::vector<Double_t> caloEnergy, std::vector<Double_t> SuperClusterOverP, std::vector<Double_t> Trkdx, std::vector<Double_t> Trkdy, std::vector<Double_t> Trkdz, Double_t Vertex_X, Double_t Vertex_Y, Double_t Vertex_Z, Double_t rho, std::vector<Lepton>& leptonColl);

};

#endif
