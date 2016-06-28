#ifndef JetSelection_h
#define JetSelection_h

#include <iostream>
using namespace std;

#include "TLorentzVector.h"
#include <vector>
#include "Jet.h"
#include "Lepton.h"
#include "OtherFunctions.h"

class JJ {

  TLorentzVector vJet;
  vector<Jet> pre_jetColl[3];
  Bool_t jetIsOK;
  Float_t pt_cut_min, pt_cut_max, eta_cut, bdisc_cut;
  
 public:
  JJ();
  ~JJ();
 
  void JetSelection(Int_t nJet, Int_t *Jet_Id_loose, Float_t *Jet_Pt, Float_t *Jet_Eta, Float_t *Jet_Px, Float_t *Jet_Py, Float_t *Jet_Pz, Float_t *Jet_E, Float_t *Jet_neutralEmEnergyFraction, Float_t *Jet_neutralHadronEnergyFraction, Float_t *Jet_chargedEmEnergyFraction, Float_t *Jet_chargedHadronEnergyFraction, Int_t *Jet_chargedMultiplicity, Int_t *Jet_NConstituents, Float_t* Jet_BTag, Int_t* Flavour, std::vector<Jet>& jetColl);
  
  void JetSelectionLeptonVeto(Int_t nJet, Int_t *Jet_Id_loose, Float_t *Jet_Pt, Float_t *Jet_Eta, Float_t *Jet_Px, Float_t *Jet_Py, Float_t *Jet_Pz, Float_t *Jet_E, Float_t *Jet_neutralEmEnergyFraction, Float_t *Jet_neutralHadronEnergyFraction, Float_t *Jet_chargedEmEnergyFraction, Float_t *Jet_chargedHadronEnergyFraction, Int_t *Jet_chargedMultiplicity, Int_t *Jet_NConstituents, Float_t* Jet_BTag, Int_t* Flavour, std::vector<Lepton>& leptonColl1, std::vector<Lepton>& leptonColl2, std::vector<Jet>& jetColl);

  void JetSelectionLeptonVeto_andB(Int_t nJet, Int_t *Jet_Id_loose, Float_t *Jet_Pt, Float_t *Jet_Eta, Float_t *Jet_Px, Float_t *Jet_Py, Float_t *Jet_Pz, Float_t *Jet_E, Float_t *Jet_neutralEmEnergyFraction, Float_t *Jet_neutralHadronEnergyFraction, Float_t *Jet_chargedEmEnergyFraction, Float_t *Jet_chargedHadronEnergyFraction, Int_t *Jet_chargedMultiplicity, Int_t *Jet_NConstituents, Float_t* Jet_BTag, Int_t* Flavour, std::vector<Lepton>& leptonColl1, std::vector<Lepton>& leptonColl2, std::vector<Jet>& jetColl, std::vector<Jet>& jetBColl);

  void SetPt(Float_t minPt, Float_t maxPt);
  void SetPt(Float_t minPt);
  void SetEta(Float_t Eta);
  void SetBdisc(Float_t Bdisc);

  //// SYSTEMATICS /////
  void JetSelectionLeptonVeto_JU(Int_t nJet, Float_t *Jet_JES, Int_t *Jet_Id_loose, Float_t *Jet_Pt, Float_t *Jet_Eta, Float_t *Jet_Px, Float_t *Jet_Py, Float_t *Jet_Pz, Float_t *Jet_E, Float_t *Jet_neutralEmEnergyFraction, Float_t *Jet_neutralHadronEnergyFraction, Float_t *Jet_chargedEmEnergyFraction, Float_t *Jet_chargedHadronEnergyFraction, Int_t *Jet_chargedMultiplicity, Int_t *Jet_NConstituents, Float_t* Jet_BTag, Int_t* Flavour, std::vector<Lepton>& leptonColl1, std::vector<Lepton>& leptonColl2, std::vector<Jet> *jetColl);

  void JetSelectionLeptonVeto_andB_JU(Int_t nJet, Float_t *Jet_JES, Int_t *Jet_Id_loose, Float_t *Jet_Pt, Float_t *Jet_Eta, Float_t *Jet_Px, Float_t *Jet_Py, Float_t *Jet_Pz, Float_t *Jet_E, Float_t *Jet_neutralEmEnergyFraction, Float_t *Jet_neutralHadronEnergyFraction, Float_t *Jet_chargedEmEnergyFraction, Float_t *Jet_chargedHadronEnergyFraction, Int_t *Jet_chargedMultiplicity, Int_t *Jet_NConstituents, Float_t* Jet_BTag, Int_t* Flavour, std::vector<Lepton>& leptonColl1, std::vector<Lepton>& leptonColl2, std::vector<Jet> *jetColl, std::vector<Jet> *jetBColl);
  
};

#endif
