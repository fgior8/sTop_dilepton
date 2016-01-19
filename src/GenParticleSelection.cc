#include "GenParticleSelection.h"

GenSelection::GenSelection() { }
GenSelection::~GenSelection() { }

void GenSelection::GenPartSelection(Int_t nGen, Int_t *Gen_pdgId, Int_t *Gen_status, Int_t * Gen_motherId, Int_t * Gen_grammaId, Float_t *Gen_charge, Float_t *Gen_pt, Float_t *Gen_eta, Float_t *Gen_phi, Float_t *Gen_mass, std::vector<TLorentzVector>& electronColl, std::vector<TLorentzVector>& muonColl, std::vector<TLorentzVector>& bquarkColl, std::vector<TLorentzVector>& lightquarkColl) {

  for (UInt_t ipart = 0; ipart < nGen; ++ipart) {
    pt_cut_min = 10.;
    pt_cut_max = 1000000000.;
    eta_cut = 3.0;
    if (Gen_pt[ipart] >= pt_cut_min && Gen_pt[ipart] < pt_cut_max
        && fabs(Gen_eta[ipart]) < eta_cut) { 
      vPart.SetPtEtaPhiM(Gen_pt[ipart], Gen_eta[ipart], Gen_phi[ipart], Gen_mass[ipart]);
      if (fabs(Gen_pdgId[ipart])==11 && Gen_status[ipart]==1)
	electronColl.push_back(vPart);
      if (fabs(Gen_pdgId[ipart])==13 && Gen_status[ipart]==1)
	muonColl.push_back(vPart);
      if (fabs(Gen_pdgId[ipart])==5)
	bquarkColl.push_back(vPart);
      if (fabs(Gen_pdgId[ipart])>0 && fabs(Gen_pdgId[ipart])<5)
	lightquarkColl.push_back(vPart);
    }
  }
  // std::sort( jetColl.begin(), jetColl.end(), JetPTSorter );
}
