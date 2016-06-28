#include "JetSelection.h"

JJ::JJ() { }
JJ::~JJ() { }

void JJ::JetSelection(Int_t nJet, Int_t *Jet_Id_loose, Float_t *Jet_Pt, Float_t *Jet_Eta, Float_t *Jet_Px, Float_t *Jet_Py, Float_t *Jet_Pz, Float_t *Jet_E, Float_t *Jet_neutralEmEnergyFraction, Float_t *Jet_neutralHadronEnergyFraction, Float_t *Jet_chargedEmEnergyFraction, Float_t *Jet_chargedHadronEnergyFraction, Int_t *Jet_chargedMultiplicity, Int_t *Jet_NConstituents, Float_t* Jet_BTag, Int_t* Flavour, std::vector<Jet>& jetColl) {

  for (UInt_t ijet = 0; ijet < nJet; ++ijet) {

    if (Jet_Pt[ijet] >= pt_cut_min && Jet_Pt[ijet] < pt_cut_max
	&& fabs(Jet_Eta[ijet]) < eta_cut
        && Jet_Id_loose[ijet]
        && Jet_neutralHadronEnergyFraction[ijet] < 0.99
        && Jet_neutralEmEnergyFraction[ijet] < 0.99
	&& Jet_NConstituents[ijet] > 1
	&& ( fabs( Jet_Eta[ijet] ) > 2.4 || ( Jet_chargedHadronEnergyFraction[ijet] > 0. && Jet_chargedMultiplicity[ijet] > 0. && Jet_chargedEmEnergyFraction[ijet] < 0.99 ) ) ) {
      //std::cout << "                             PASS\n";
      vJet.SetPxPyPzE(Jet_Px[ijet], Jet_Py[ijet], Jet_Pz[ijet], Jet_E[ijet]);
      jetColl.push_back( Jet(vJet, Flavour[ijet], Jet_BTag[ijet], ijet) );
    }
  }
  std::sort( jetColl.begin(), jetColl.end(), JetPTSorter );
}

void JJ::JetSelectionLeptonVeto(Int_t nJet, Int_t *Jet_Id_loose, Float_t *Jet_Pt, Float_t *Jet_Eta, Float_t *Jet_Px, Float_t *Jet_Py, Float_t *Jet_Pz, Float_t *Jet_E, Float_t *Jet_neutralEmEnergyFraction, Float_t *Jet_neutralHadronEnergyFraction, Float_t *Jet_chargedEmEnergyFraction, Float_t *Jet_chargedHadronEnergyFraction, Int_t *Jet_chargedMultiplicity, Int_t *Jet_NConstituents, Float_t* Jet_BTag, Int_t* Flavour, std::vector<Lepton>& leptonColl1, std::vector<Lepton>& leptonColl2, std::vector<Jet>& jetColl) {
  std::vector<Jet> pre_jetColl;

  for (UInt_t ijet = 0; ijet < nJet; ijet++) {

    if (Jet_Pt[ijet] >= pt_cut_min && Jet_Pt[ijet] < pt_cut_max
	&& fabs(Jet_Eta[ijet]) < eta_cut
	&& Jet_Id_loose[ijet]>0
	&& Jet_neutralHadronEnergyFraction[ijet] < 0.99
	&& Jet_neutralEmEnergyFraction[ijet] < 0.99
	&& Jet_NConstituents[ijet] > 1
	&& ( fabs( Jet_Eta[ijet] ) > 2.4 || ( Jet_chargedHadronEnergyFraction[ijet] > 0. && Jet_chargedMultiplicity[ijet] > 0. && Jet_chargedEmEnergyFraction[ijet] < 0.99 ) ) ) {
      vJet.SetPxPyPzE(Jet_Px[ijet], Jet_Py[ijet], Jet_Pz[ijet], Jet_E[ijet]);
      pre_jetColl.push_back( Jet(vJet, Flavour[ijet], Jet_BTag[ijet], ijet) );
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

void JJ::JetSelectionLeptonVeto_andB(Int_t nJet, Int_t *Jet_Id_loose, Float_t *Jet_Pt, Float_t *Jet_Eta, Float_t *Jet_Px, Float_t *Jet_Py, Float_t *Jet_Pz, Float_t *Jet_E, Float_t *Jet_neutralEmEnergyFraction, Float_t *Jet_neutralHadronEnergyFraction, Float_t *Jet_chargedEmEnergyFraction, Float_t *Jet_chargedHadronEnergyFraction, Int_t *Jet_chargedMultiplicity, Int_t *Jet_NConstituents, Float_t* Jet_BTag, Int_t* Flavour, std::vector<Lepton>& leptonColl1, std::vector<Lepton>& leptonColl2, std::vector<Jet>& jetColl, std::vector<Jet>& jetBColl) {
  std::vector<Jet> pre_jetColl;

  for (UInt_t ijet = 0; ijet < nJet; ijet++) {

    if (Jet_Pt[ijet] >= pt_cut_min && Jet_Pt[ijet] < pt_cut_max
	&& fabs(Jet_Eta[ijet]) < eta_cut
	&& Jet_Id_loose[ijet]
	&& Jet_neutralHadronEnergyFraction[ijet] < 0.99
	&& Jet_neutralEmEnergyFraction[ijet] < 0.99
	&& Jet_NConstituents[ijet] > 1
	&& ( fabs( Jet_Eta[ijet] ) > 2.4 || ( Jet_chargedHadronEnergyFraction[ijet] > 0. && Jet_chargedMultiplicity[ijet] > 0. && Jet_chargedEmEnergyFraction[ijet] < 0.99 ) ) ) {
      vJet.SetPxPyPzE(Jet_Px[ijet], Jet_Py[ijet], Jet_Pz[ijet], Jet_E[ijet]);
      pre_jetColl.push_back( Jet(vJet, Flavour[ijet], Jet_BTag[ijet], ijet) );
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
    
    if (jetIsOK) {
      jetColl.push_back( pre_jetColl[ijet] );
      if(Jet_BTag[ijet] > bdisc_cut)
	jetBColl.push_back( pre_jetColl[ijet] );
    }
  }
  std::sort( jetColl.begin(), jetColl.end(), JetPTSorter );
  std::sort( jetBColl.begin(), jetColl.end(), JetPTSorter );
    
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


/// SYSTEMATICS ////

void JJ::JetSelectionLeptonVeto_JU(Int_t nJet, Float_t *Jet_JES, Int_t *Jet_Id_loose, Float_t *Jet_Pt, Float_t *Jet_Eta, Float_t *Jet_Px, Float_t *Jet_Py, Float_t *Jet_Pz, Float_t *Jet_E, Float_t *Jet_neutralEmEnergyFraction, Float_t *Jet_neutralHadronEnergyFraction, Float_t *Jet_chargedEmEnergyFraction, Float_t *Jet_chargedHadronEnergyFraction, Int_t *Jet_chargedMultiplicity, Int_t *Jet_NConstituents, Float_t* Jet_BTag, Int_t* Flavour, std::vector<Lepton>& leptonColl1, std::vector<Lepton>& leptonColl2, std::vector<Jet> *jetColl) {

  for (UInt_t sys=0; sys<3; sys++)
    pre_jetColl[sys].clear();
  for (UInt_t ijet = 0; ijet < nJet; ijet++) {
    if ( !( Jet_Id_loose[ijet]
	    && fabs(Jet_Eta[ijet]) < eta_cut
	    && Jet_neutralHadronEnergyFraction[ijet] < 0.99
	    && Jet_neutralEmEnergyFraction[ijet] < 0.99
	    && Jet_NConstituents[ijet] > 1
	    && ( fabs( Jet_Eta[ijet] ) > 2.4 || ( Jet_chargedHadronEnergyFraction[ijet] > 0. && Jet_chargedMultiplicity[ijet] > 0. && Jet_chargedEmEnergyFraction[ijet] < 0.99 ) ) )
	 ) continue;

    for (UInt_t sys = 0; sys<3; sys++) {
      if (sys==1) {
	if (Jet_Pt[ijet]*(1+Jet_JES[ijet]) >= pt_cut_min && Jet_Pt[ijet]*(1+Jet_JES[ijet]) < pt_cut_max) {
	  vJet.SetPxPyPzE(Jet_Px[ijet]*(1+Jet_JES[ijet]), Jet_Py[ijet]*(1+Jet_JES[ijet]), Jet_Pz[ijet]*(1+Jet_JES[ijet]), Jet_E[ijet]*(1+Jet_JES[ijet]));
	  pre_jetColl[sys].push_back( Jet(vJet, Flavour[ijet], Jet_BTag[ijet], ijet) );
	}
      }
      else if (sys==2) {
	if (Jet_Pt[ijet]*(1-Jet_JES[ijet]) >= pt_cut_min && Jet_Pt[ijet]*(1-Jet_JES[ijet]) < pt_cut_max) {
	  vJet.SetPxPyPzE(Jet_Px[ijet]*(1-Jet_JES[ijet]), Jet_Py[ijet]*(1-Jet_JES[ijet]), Jet_Pz[ijet]*(1-Jet_JES[ijet]), Jet_E[ijet]*(1-Jet_JES[ijet]));
	  pre_jetColl[sys].push_back( Jet(vJet, Flavour[ijet], Jet_BTag[ijet], ijet) );
	}
      }
      else {
	if (Jet_Pt[ijet] >= pt_cut_min && Jet_Pt[ijet] < pt_cut_max) {
	  vJet.SetPxPyPzE(Jet_Px[ijet], Jet_Py[ijet], Jet_Pz[ijet], Jet_E[ijet]);
	  pre_jetColl[sys].push_back( Jet(vJet, Flavour[ijet], Jet_BTag[ijet], ijet) );
	}
      }
    }
  }
  for (UInt_t sys = 0; sys<3; sys++) {
    for (UInt_t ijet = 0; ijet < pre_jetColl[sys].size(); ijet++) {
      jetIsOK = true;
      for (UInt_t ilep = 0; ilep < leptonColl1.size(); ilep++) {
	if (pre_jetColl[sys][ijet].lorentzVec().DeltaR( leptonColl1[ilep].lorentzVec() ) < 0.4) {
	  jetIsOK = false;
	  break;
	}
      }
      for (UInt_t ilep = 0; ilep < leptonColl2.size(); ilep++) {
	if (pre_jetColl[sys][ijet].lorentzVec().DeltaR( leptonColl2[ilep].lorentzVec() ) < 0.4 ) {
	  jetIsOK = false;
	  break;
	}
      }
      if (jetIsOK) 
	jetColl[sys].push_back( pre_jetColl[sys][ijet] );
    }
  }
  for (UInt_t sys=0; sys<14; sys++) {
    if (sys<3) 
      std::sort( jetColl[sys].begin(), jetColl[sys].end(), JetPTSorter );
    else 
      jetColl[sys] = jetColl[0];
  }
}


void JJ::JetSelectionLeptonVeto_andB_JU(Int_t nJet, Float_t *Jet_JES, Int_t *Jet_Id_loose, Float_t *Jet_Pt, Float_t *Jet_Eta, Float_t *Jet_Px, Float_t *Jet_Py, Float_t *Jet_Pz, Float_t *Jet_E, Float_t *Jet_neutralEmEnergyFraction, Float_t *Jet_neutralHadronEnergyFraction, Float_t *Jet_chargedEmEnergyFraction, Float_t *Jet_chargedHadronEnergyFraction, Int_t *Jet_chargedMultiplicity, Int_t *Jet_NConstituents, Float_t* Jet_BTag, Int_t* Flavour, std::vector<Lepton>& leptonColl1, std::vector<Lepton>& leptonColl2, std::vector<Jet> *jetColl, std::vector<Jet> *jetBColl) {

  for (UInt_t sys=0; sys<3; sys++)
    pre_jetColl[sys].clear();
  for (UInt_t ijet = 0; ijet < nJet; ijet++) {
    if ( !( Jet_Id_loose[ijet]
	    && fabs(Jet_Eta[ijet]) < eta_cut
	    && Jet_neutralHadronEnergyFraction[ijet] < 0.99
	    && Jet_neutralEmEnergyFraction[ijet] < 0.99
	    && Jet_NConstituents[ijet] > 1
	    && ( fabs( Jet_Eta[ijet] ) > 2.4 || ( Jet_chargedHadronEnergyFraction[ijet] > 0. && Jet_chargedMultiplicity[ijet] > 0. && Jet_chargedEmEnergyFraction[ijet] < 0.99 ) ) )
	 ) continue;
    for (UInt_t sys = 0; sys<3; sys++) {
      if (sys==1) {
	if (Jet_Pt[ijet]*(1+Jet_JES[ijet]) >= pt_cut_min && Jet_Pt[ijet]*(1+Jet_JES[ijet]) < pt_cut_max) {
	  vJet.SetPxPyPzE(Jet_Px[ijet]*(1+Jet_JES[ijet]), Jet_Py[ijet]*(1+Jet_JES[ijet]), Jet_Pz[ijet]*(1+Jet_JES[ijet]), Jet_E[ijet]*(1+Jet_JES[ijet]));
	  pre_jetColl[sys].push_back( Jet(vJet, Flavour[ijet], Jet_BTag[ijet], ijet) );
	}
      }
      else if (sys==2) {
	if (Jet_Pt[ijet]*(1-Jet_JES[ijet]) >= pt_cut_min && Jet_Pt[ijet]*(1-Jet_JES[ijet]) < pt_cut_max) {
	  vJet.SetPxPyPzE(Jet_Px[ijet]*(1-Jet_JES[ijet]), Jet_Py[ijet]*(1-Jet_JES[ijet]), Jet_Pz[ijet]*(1-Jet_JES[ijet]), Jet_E[ijet]*(1-Jet_JES[ijet]));
	  pre_jetColl[sys].push_back( Jet(vJet, Flavour[ijet], Jet_BTag[ijet], ijet) );
	}
      }
      else {
	if (Jet_Pt[ijet] >= pt_cut_min && Jet_Pt[ijet] < pt_cut_max) {
	  vJet.SetPxPyPzE(Jet_Px[ijet], Jet_Py[ijet], Jet_Pz[ijet], Jet_E[ijet]);
	  pre_jetColl[sys].push_back( Jet(vJet, Flavour[ijet], Jet_BTag[ijet], ijet) );
	}
      }
    }
  }
  for (UInt_t sys = 0; sys<3; sys++) {
    for (UInt_t ijet = 0; ijet < pre_jetColl[sys].size(); ijet++) {
      jetIsOK = true;
      for (UInt_t ilep = 0; ilep < leptonColl1.size(); ilep++) {
	if (pre_jetColl[sys][ijet].lorentzVec().DeltaR( leptonColl1[ilep].lorentzVec() ) < 0.4) {
	  jetIsOK = false;
	  break;
	}
      }
      for (UInt_t ilep = 0; ilep < leptonColl2.size(); ilep++) {
	if (pre_jetColl[sys][ijet].lorentzVec().DeltaR( leptonColl2[ilep].lorentzVec() ) < 0.4 ) {
	  jetIsOK = false;
	  break;
	}
      }
      if (jetIsOK) {
	jetColl[sys].push_back( pre_jetColl[sys][ijet] );
	if(pre_jetColl[sys][ijet].btag_disc() > bdisc_cut)
	  jetBColl[sys].push_back( pre_jetColl[sys][ijet] );
      }
    }
  }
  for (UInt_t sys=0; sys<14; sys++) {
    if (sys<3) {
      std::sort( jetColl[sys].begin(), jetColl[sys].end(), JetPTSorter );
      std::sort( jetBColl[sys].begin(), jetBColl[sys].end(), JetPTSorter );
    }
    else {
      jetColl[sys] = jetColl[0];
      jetBColl[sys] = jetBColl[0];
    }
  }
}
