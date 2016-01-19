#ifndef GenParticleSelection_h
#define GenParticleSelection_h

#include <iostream>
using namespace std;

#include "TLorentzVector.h"
#include <vector>

class GenSelection {

  Float_t pt_cut_min, pt_cut_max, eta_cut;
  TLorentzVector vPart;

 public:
  GenSelection();
  ~GenSelection();

  void GenPartSelection(Int_t nGen, Int_t *Gen_pdgId, Int_t *Gen_status, Int_t * Gen_motherId, Int_t * Gen_grammaId, Float_t *Gen_charge, Float_t *Gen_pt, Float_t *Gen_eta, Float_t *Gen_phi, Float_t *Gen_mass, std::vector<TLorentzVector>& electronColl, std::vector<TLorentzVector>& muonColl, std::vector<TLorentzVector>& bquarkColl, std::vector<TLorentzVector>& lightquarkColl);


};

#endif
