#ifndef ElectronSelection_h
#define ElectronSelection_h

#include "LeptonSelection.h"

class ElectronSel : public Lep {
  
  Bool_t ElectronID, ElectronIDLoose, isEB, isEE;
  Double_t ElTkIso, ElEcalIso, ElHcalIso;

 public:
  ElectronSel();
  ~ElectronSel();

  void ElectronSelection(Int_t nElectron, Int_t *pdgId, Float_t *EtaSc, Float_t *Pt, Float_t *Px, Float_t *Py, Float_t *Pz, Float_t *E, Float_t *relIso, Int_t *Charge, Int_t *passConversionVeto, Int_t *MissingHits, Float_t *DeltaEtaTrkSC, Float_t *DeltaPhiTrkSC, Float_t *SigmaIEtaIEta, Float_t *HoE, Float_t *eInvMinusPInv, Float_t *dxy_var, Float_t *dz_var, std::vector<Lepton>& leptonColl); 

  void ElectronSelectionWithLoose(Int_t nElectron, Int_t *pdgId, Float_t *EtaSc, Float_t *Pt, Float_t *Px, Float_t *Py, Float_t *Pz, Float_t *E, Float_t *relIso, Int_t *Charge, Int_t *passConversionVeto, Int_t *MissingHits, Float_t *DeltaEtaTrkSC, Float_t *DeltaPhiTrkSC, Float_t *SigmaIEtaIEta, Float_t *HoE, Float_t *eInvMinusPInv, Float_t *dxy_var, Float_t *dz_var, Int_t *mcMatchId, std::vector<Lepton>& leptonColl, std::vector<Lepton>& leptonCollLoose);

};

#endif
