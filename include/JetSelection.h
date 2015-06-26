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
  Bool_t jetIsOK;
  Float_t pt_cut_min, pt_cut_max, eta_cut, bdisc_cut;
  
 public:
  JJ();
  ~JJ();
 
  void JetSelection(std::vector<Bool_t> Jet_Id_loose, std::vector<Float_t> Jet_Eta, std::vector<Float_t> Jet_Px, std::vector<Float_t> Jet_Py, std::vector<Float_t> Jet_Pz, std::vector<Float_t> Jet_Pt, std::vector<Float_t> Jet_E, std::vector<Float_t> Jet_neutralEmEnergyFraction, std::vector<Float_t> Jet_neutralHadronEnergyFraction, std::vector<Float_t> Jet_chargedEmEnergyFraction, std::vector<Float_t> Jet_chargedHadronEnergyFraction, std::vector<Int_t> Jet_chargedMultiplicity, std::vector<Int_t> Jet_NConstituents, std::vector<Float_t> Jet_BTag, std::vector<Jet>& jetColl);
  
  void JetSelectionLeptonVeto(std::vector<Bool_t> Jet_Id_loose, std::vector<Float_t> Jet_Eta, std::vector<Float_t> Jet_Px, std::vector<Float_t> Jet_Py, std::vector<Float_t> Jet_Pz, std::vector<Float_t> Jet_Pt, std::vector<Float_t> Jet_E, std::vector<Float_t> Jet_neutralEmEnergyFraction, std::vector<Float_t> Jet_neutralHadronEnergyFraction, std::vector<Float_t> Jet_chargedEmEnergyFraction, std::vector<Float_t> Jet_chargedHadronEnergyFraction, std::vector<Int_t> Jet_chargedMultiplicity, std::vector<Int_t> Jet_NConstituents, std::vector<Float_t> Jet_BTag, std::vector<Lepton>& leptonColl1, std::vector<Lepton>& leptonColl2, std::vector<Jet>& jetColl);

  void BJetSelectionLeptonVeto(std::vector<Bool_t> Jet_Id_loose, std::vector<Float_t> Jet_Eta, std::vector<Float_t> Jet_Px, std::vector<Float_t> Jet_Py, std::vector<Float_t> Jet_Pz, std::vector<Float_t> Jet_Pt, std::vector<Float_t> Jet_E, std::vector<Float_t> Jet_neutralEmEnergyFraction, std::vector<Float_t> Jet_neutralHadronEnergyFraction, std::vector<Float_t> Jet_chargedEmEnergyFraction, std::vector<Float_t> Jet_chargedHadronEnergyFraction, std::vector<Int_t> Jet_chargedMultiplicity, std::vector<Int_t> Jet_NConstituents, std::vector<Float_t> Jet_BTag, std::vector<Lepton>& leptonColl1, std::vector<Lepton>& leptonColl2, std::vector<Jet>& jetColl);

  void SetPt(Float_t minPt, Float_t maxPt);
  void SetPt(Float_t minPt);
  void SetEta(Float_t Eta);
  void SetBdisc(Float_t Bdisc);
 
};

#endif
