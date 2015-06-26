#include "JetSelection.h"

JJ::JJ() { }
JJ::~JJ() { }

void JJ::JetSelection (std::vector<Bool_t> Jet_Id_loose, std::vector<Float_t> Jet_Eta, std::vector<Float_t> Jet_Px, std::vector<Float_t> Jet_Py, std::vector<Float_t> Jet_Pz, std::vector<Float_t> Jet_Pt, std::vector<Float_t> Jet_E, std::vector<Float_t> Jet_neutralEmEnergyFraction, std::vector<Float_t> Jet_neutralHadronEnergyFraction, std::vector<Float_t> Jet_chargedEmEnergyFraction, std::vector<Float_t> Jet_chargedHadronEnergyFraction, std::vector<Int_t> Jet_chargedMultiplicity, std::vector<Int_t> Jet_NConstituents, std::vector<Float_t> Jet_BTag, std::vector<Jet>& jetColl) {

  for (UInt_t ijet = 0; ijet < Jet_Pt.size(); ++ijet) {

    if (Jet_Pt[ijet] >= pt_cut_min && Jet_Pt[ijet] < pt_cut_max
	&& fabs(Jet_Eta[ijet]) < eta_cut
        && Jet_Id_loose[ijet]
        && Jet_neutralHadronEnergyFraction[ijet] < 0.99
        && Jet_neutralEmEnergyFraction[ijet] < 0.99
	&& Jet_NConstituents[ijet] > 1
	&& ( fabs( Jet_Eta[ijet] ) > 2.4 || ( Jet_chargedHadronEnergyFraction[ijet] > 0. && Jet_chargedMultiplicity[ijet] > 0. && Jet_chargedEmEnergyFraction[ijet] < 0.99 ) ) ) {
      //std::cout << "                             PASS\n";
      vJet.SetPxPyPzE(Jet_Px[ijet], Jet_Py[ijet], Jet_Pz[ijet], Jet_E[ijet]);
      jetColl.push_back( Jet(vJet, Jet_Eta[ijet], Jet_BTag[ijet], ijet) );
    }
  }
  std::sort( jetColl.begin(), jetColl.end(), JetPTSorter );
}

void JJ::JetSelectionLeptonVeto(std::vector<Bool_t> Jet_Id_loose, std::vector<Float_t> Jet_Eta, std::vector<Float_t> Jet_Px, std::vector<Float_t> Jet_Py, std::vector<Float_t> Jet_Pz, std::vector<Float_t> Jet_Pt, std::vector<Float_t> Jet_E, std::vector<Float_t> Jet_neutralEmEnergyFraction, std::vector<Float_t> Jet_neutralHadronEnergyFraction, std::vector<Float_t> Jet_chargedEmEnergyFraction, std::vector<Float_t> Jet_chargedHadronEnergyFraction, std::vector<Int_t> Jet_chargedMultiplicity, std::vector<Int_t> Jet_NConstituents, std::vector<Float_t> Jet_BTag, std::vector<Lepton>& leptonColl1, std::vector<Lepton>& leptonColl2, std::vector<Jet>& jetColl) {
  std::vector<Jet> pre_jetColl;

  for (UInt_t ijet = 0; ijet < Jet_Pt.size(); ijet++) {

    if (Jet_Pt[ijet] >= pt_cut_min && Jet_Pt[ijet] < pt_cut_max
	&& fabs(Jet_Eta[ijet]) < eta_cut
	&& Jet_Id_loose[ijet]
	&& Jet_neutralHadronEnergyFraction[ijet] < 0.99
	&& Jet_neutralEmEnergyFraction[ijet] < 0.99
	&& Jet_NConstituents[ijet] > 1
	&& ( fabs( Jet_Eta[ijet] ) > 2.4 || ( Jet_chargedHadronEnergyFraction[ijet] > 0. && Jet_chargedMultiplicity[ijet] > 0. && Jet_chargedEmEnergyFraction[ijet] < 0.99 ) ) ) {
      vJet.SetPxPyPzE(Jet_Px[ijet], Jet_Py[ijet], Jet_Pz[ijet], Jet_E[ijet]);
      pre_jetColl.push_back( Jet(vJet, Jet_Eta[ijet], Jet_BTag[ijet], ijet) );
    }
  }

  for (UInt_t ijet = 0; ijet < pre_jetColl.size(); ijet++) {
    jetIsOK = true;
    for (UInt_t ilep = 0; ilep < leptonColl1.size(); ilep++) {
      if (pre_jetColl[ijet].lorentzVec().DeltaR( leptonColl1[ilep].lorentzVec() ) < 0.4) {
	jetIsOK = false;
	break;
      }
    }
    for (UInt_t ilep = 0; ilep < leptonColl2.size(); ilep++) {
      if (pre_jetColl[ijet].lorentzVec().DeltaR( leptonColl2[ilep].lorentzVec() ) < 0.4 ) {
	jetIsOK = false;
	break;
      }
    }
    
    if (jetIsOK)
      jetColl.push_back( pre_jetColl[ijet] );
  }
  std::sort( jetColl.begin(), jetColl.end(), JetPTSorter );
}

void JJ::BJetSelectionLeptonVeto(std::vector<Bool_t> Jet_Id_loose, std::vector<Float_t> Jet_Eta, std::vector<Float_t> Jet_Px, std::vector<Float_t> Jet_Py, std::vector<Float_t> Jet_Pz, std::vector<Float_t> Jet_Pt, std::vector<Float_t> Jet_E, std::vector<Float_t> Jet_neutralEmEnergyFraction, std::vector<Float_t> Jet_neutralHadronEnergyFraction, std::vector<Float_t> Jet_chargedEmEnergyFraction, std::vector<Float_t> Jet_chargedHadronEnergyFraction, std::vector<Int_t> Jet_chargedMultiplicity, std::vector<Int_t> Jet_NConstituents, std::vector<Float_t> Jet_BTag, std::vector<Lepton>& leptonColl1, std::vector<Lepton>& leptonColl2, std::vector<Jet>& jetColl) {
  std::vector<Jet> pre_jetColl;

  for (UInt_t ijet = 0; ijet < Jet_Pt.size(); ijet++) {

    if (Jet_Pt[ijet] >= pt_cut_min && Jet_Pt[ijet] < pt_cut_max
	&& Jet_BTag[ijet] > bdisc_cut
	&& fabs(Jet_Eta[ijet]) < eta_cut
	&& Jet_Id_loose[ijet]
	&& Jet_neutralHadronEnergyFraction[ijet] < 0.99
	&& Jet_neutralEmEnergyFraction[ijet] < 0.99
	&& Jet_NConstituents[ijet] > 1
	&& ( fabs( Jet_Eta[ijet] ) > 2.4 || ( Jet_chargedHadronEnergyFraction[ijet] > 0. && Jet_chargedMultiplicity[ijet] > 0. && Jet_chargedEmEnergyFraction[ijet] < 0.99 ) ) ) {
      vJet.SetPxPyPzE(Jet_Px[ijet], Jet_Py[ijet], Jet_Pz[ijet], Jet_E[ijet]);
      pre_jetColl.push_back( Jet(vJet, Jet_Eta[ijet], Jet_BTag[ijet], ijet) );
    }
  }

  for (UInt_t ijet = 0; ijet < pre_jetColl.size(); ijet++) {
    jetIsOK = true;
    for (UInt_t ilep = 0; ilep < leptonColl1.size(); ilep++) {
      //      if (leptonColl1[ilep].leptonType()==Lepton::Muon)
	if (leptonColl1[ilep].lorentzVec().DeltaR( pre_jetColl[ijet].lorentzVec() ) < 0.4) {
	  jetIsOK = false;
	  ilep = leptonColl1.size();
	}
    }
    for (UInt_t ilep = 0; ilep < leptonColl2.size(); ilep++) {
      //      if (leptonColl2[ilep].leptonType()==Lepton::Electron)
	if (leptonColl2[ilep].lorentzVec().DeltaR( pre_jetColl[ijet].lorentzVec() ) < 0.4 ) {
	  jetIsOK = false;
	  ilep = leptonColl2.size();
	}
    }
    
    if (jetIsOK)
      jetColl.push_back( pre_jetColl[ijet] );
  }
  std::sort( jetColl.begin(), jetColl.end(), JetPTSorter );
}


void JJ::SetPt(Float_t minPt) {
  minPt ? pt_cut_min=minPt : pt_cut_min=0.0;
  pt_cut_max=10000.0;
}

void JJ::SetPt(Float_t minPt, Float_t maxPt) {
  minPt ? pt_cut_min=minPt : pt_cut_min=0.0;
  maxPt ? pt_cut_max=maxPt : pt_cut_max=10000.0;
}

void JJ::SetEta(Float_t Eta) {
  Eta ? eta_cut=Eta : eta_cut=3.0;
}

void JJ::SetBdisc(Float_t Bdisc) {
  Bdisc ? bdisc_cut=Bdisc : bdisc_cut=100000.0;
}
