#include "GenParticleSelection.h"

GenSelection::GenSelection() { }
GenSelection::~GenSelection() { }

void GenSelection::GenPartSelection(Int_t nGen, Int_t *Gen_pdgId, Int_t *Gen_status, Int_t *Gen_motherId, Int_t *Gen_grammaId, Int_t *Gen_sourceId, Float_t *Gen_charge, Float_t *Gen_pt, Float_t *Gen_eta, Float_t *Gen_phi, Float_t *Gen_mass, std::vector<Lepton>& electronColl, std::vector<Lepton>& electronNuColl, std::vector<Lepton>& muonColl, std::vector<Lepton>& muonNuColl, std::vector<Jet>& bquarkColl, std::vector<TLorentzVector>& lightquarkColl) {

  fakeType = Lepton::unknown;
  looseTight = Lepton::Other;
  btag = 9999.;
	
  for (UInt_t ipart = 0; ipart < nGen; ++ipart) {
    //  if ((nthdigit( abs(Gen_pdgId[ipart]), 0)==5 || nthdigit( abs(Gen_pdgId[ipart]), 1)==5 || nthdigit( abs(Gen_pdgId[ipart]), 2)==5) )
    //cout << "Gen_pdgId[ipart] " << Gen_pdgId[ipart] << " Gen_mass[ipart] " << Gen_mass[ipart] << " Gen_motherId[ipart] " << Gen_motherId[ipart] <<endl;
    pt_cut_min = 10.;
    pt_cut_max = 1000000000.;
    eta_cut = 3.0;
    charge = Gen_charge[ipart];
    eta = Gen_grammaId[ipart];
    if (Gen_pt[ipart] >= pt_cut_min && Gen_pt[ipart] < pt_cut_max
        && fabs(Gen_eta[ipart]) < eta_cut) { 
      vPart.SetPtEtaPhiM(Gen_pt[ipart], Gen_eta[ipart], Gen_phi[ipart], Gen_mass[ipart]);
      if (fabs(Gen_pdgId[ipart])==11 && Gen_status[ipart]==1) {
	leptonType = Lepton::Electron;
	//	electronColl.push_back(vPart);
	electronColl.push_back( Lepton(leptonType, ipart, vPart, eta, btag, btag, btag, charge, fakeType, looseTight, btag) );
      }
      if (fabs(Gen_pdgId[ipart])==12 && Gen_status[ipart]==1) {
	leptonType = Lepton::Electron;
	electronNuColl.push_back( Lepton(leptonType, ipart, vPart, eta, btag, btag, btag, charge, fakeType, looseTight, btag) );
      }    
      if (fabs(Gen_pdgId[ipart])==13 && Gen_status[ipart]==1) {
	leptonType = Lepton::Muon;
	muonColl.push_back( Lepton(leptonType, ipart, vPart, eta, btag, btag, btag, charge, fakeType, looseTight, btag) );
      }
      if (fabs(Gen_pdgId[ipart])==14 && Gen_status[ipart]==1) {
	leptonType = Lepton::Muon;
	muonNuColl.push_back( Lepton(leptonType, ipart, vPart, eta, btag, btag, btag, charge, fakeType, looseTight, btag) );
      }
      if (fabs(Gen_pdgId[ipart])==5)
	bquarkColl.push_back( Jet(vPart, eta, btag, ipart));
      if ( (fabs(Gen_pdgId[ipart])>0 && fabs(Gen_pdgId[ipart])<5) || fabs(Gen_pdgId[ipart])==21)
	lightquarkColl.push_back(vPart);
    }
  }
  
  // std::sort( jetColl.begin(), jetColl.end(), JetPTSorter );
}


void GenSelection::GenJetSelection(Float_t *Gen_px, Float_t *Gen_py, Float_t *Gen_pz, Float_t *Gen_energy, Int_t *Gen_Flavour, vector<Jet>& bquarkColl, vector<Jet>& RecojetColl, vector<Jet>& GenjetColl) {

  for (UInt_t i = 0; i < RecojetColl.size(); i++) {
    partOK = false;
    UInt_t idx = RecojetColl[i].ijet();
    if (Gen_energy[idx]<=0.) continue;
    vPart.SetPxPyPzE(Gen_px[idx], Gen_py[idx], Gen_pz[idx], Gen_energy[idx]);
    eta = vPart.Eta();
    btag = Gen_Flavour[idx];
    for (UInt_t j=0; j<bquarkColl.size(); j++)
      if (vPart.DeltaR( bquarkColl[j].lorentzVec() ) < 0.1 )
	partOK = true;
    if (fabs(eta)<6.0 && partOK)
      GenjetColl.push_back( Jet(vPart, eta, btag, idx) );
  }
    
}
