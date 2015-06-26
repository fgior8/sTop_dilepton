#include "OtherFunctions.h"

float getMT2bb(std::vector<Jet>& jets, std::vector<Lepton>& leptons, float MET, float MET_phi) {
  float METx = MET*TMath::Cos(MET_phi);
  float METy = MET*TMath::Sin(MET_phi);
  TLorentzVector Lep0 = leptons[0].lorentzVec();
  TLorentzVector Lep1 = leptons[1].lorentzVec();
  TLorentzVector BtagJet0 = jets[0].lorentzVec();
  TLorentzVector BtagJet1 = jets[1].lorentzVec();
  return getMT2_80( BtagJet0, BtagJet1, sqrt(pow(METx+(Lep0+Lep1).Px(),2)+pow(METy+(Lep0+Lep1).Py(),2)), TMath::ATan2(METy+(Lep0+Lep1).Py(),METx+(Lep0+Lep1).Px()) );
}

float getMT2lblb(std::vector<Jet>& jets, std::vector<Lepton>& leptons, float MET, float MET_phi) {
  float MT2llbb00, MT2llbb01, MT2llbb;
  float METx = MET*TMath::Cos(MET_phi);
  float METy = MET*TMath::Sin(MET_phi);
  TLorentzVector Lep0 = leptons[0].lorentzVec();
  TLorentzVector Lep1 = leptons[1].lorentzVec();
  TLorentzVector BtagJet0 = jets[0].lorentzVec();
  TLorentzVector BtagJet1 = jets[1].lorentzVec();
  TLorentzVector LepPlusBtagJet00 = Lep0 + BtagJet0;
  TLorentzVector LepPlusBtagJet10 = Lep1 + BtagJet0;
  TLorentzVector LepPlusBtagJet11 = Lep1 + BtagJet1;
  TLorentzVector LepPlusBtagJet01 = Lep0 + BtagJet1;
  if (LepPlusBtagJet11.M()<173 && LepPlusBtagJet00.M()<173 && (LepPlusBtagJet10.M()>173 || LepPlusBtagJet01.M()>173))
    MT2llbb=getMT2(LepPlusBtagJet00, LepPlusBtagJet11, MET, MET_phi);
  else if ((LepPlusBtagJet11.M()>173 || LepPlusBtagJet00.M()>173) && LepPlusBtagJet10.M()<173 && LepPlusBtagJet01.M()<173)
    MT2llbb=getMT2(LepPlusBtagJet01, LepPlusBtagJet10, MET, MET_phi);
  else if (LepPlusBtagJet11.M()<173 && LepPlusBtagJet00.M()<173 && LepPlusBtagJet10.M()<173 && LepPlusBtagJet01.M()<173) {
    if ( fabs(LepPlusBtagJet11.M()-LepPlusBtagJet00.M()) < fabs(LepPlusBtagJet10.M()-LepPlusBtagJet01.M()) )
      MT2llbb=getMT2(LepPlusBtagJet00, LepPlusBtagJet11, MET, MET_phi);
    else
      MT2llbb=getMT2(LepPlusBtagJet01, LepPlusBtagJet10, MET, MET_phi);
  }
  else
    MT2llbb=0;
  return MT2llbb;
}

float getMT2(TLorentzVector lept1, TLorentzVector lept2, float theMET, float theMETphi) {
  // Calculate MT2 variable for two leptons and missing energy, assuming zero testmass
  double pa[3];
  double pb[3];
  double pmiss[3];

  TLorentzVector pmet;
  pmet.SetPtEtaPhiM(theMET, 0., theMETphi, 0.);
  pmiss[0] = 0.; // irrelevant
  pmiss[1] = pmet.Px();
  pmiss[2] = pmet.Py();

  pa[0] = lept1.M(); // setting the mass, just in case
  pa[1] = lept1.Px();
  pa[2] = lept1.Py();

  pb[0] = lept2.M(); // setting the mass, just in case
  pb[1] = lept2.Px();
  pb[2] = lept2.Py();

  mt2bisect* MT2bisect = new mt2bisect();
  MT2bisect->set_verbose(0);
  MT2bisect->set_momenta(pa, pb, pmiss);
  MT2bisect->set_mn(0.); // testmass
  double MT2 = MT2bisect->get_mt2();
  delete MT2bisect;
  return MT2;
}

float getMT2_80(TLorentzVector lept1, TLorentzVector lept2, float theMET, float theMETphi) {
  // Calculate MT2 variable for two leptons and missing energy, assuming zero testmass
  double pa[3];
  double pb[3];
  double pmiss[3];

  TLorentzVector pmet;
  pmet.SetPtEtaPhiM(theMET, 0., theMETphi, 0.);
  pmiss[0] = 0.; // irrelevant
  pmiss[1] = pmet.Px();
  pmiss[2] = pmet.Py();

  pa[0] = lept1.M(); // setting the mass, just in case
  pa[1] = lept1.Px();
  pa[2] = lept1.Py();

  pb[0] = lept2.M(); // setting the mass, just in case
  pb[1] = lept2.Px();
  pb[2] = lept2.Py();

  mt2bisect* MT2bisect = new mt2bisect();
  MT2bisect->set_verbose(0);
  MT2bisect->set_momenta(pa, pb, pmiss);
  MT2bisect->set_mn(80.398); // testmass
  double MT2 = MT2bisect->get_mt2();
  delete MT2bisect;
  return MT2;
}

bool LeptonPTSorter(Lepton lep1, Lepton lep2) {
  return lep1.lorentzVec().Pt() > lep2.lorentzVec().Pt();
}

bool LeptonIsoSorter(Lepton lep1, Lepton lep2) {
  return lep1.relIso() < lep2.relIso();
}

bool JetPTSorter(Jet jet1, Jet jet2) {
  return jet1.lorentzVec().Pt() > jet2.lorentzVec().Pt();
}
//bool LeptonIsolationSorter(Lepton lep1, Lepton lep2) {
//////  return (lep1.relIso() < 0.1) > (lep2.relIso() < 0.1);
////// true if lep1 earlier-sorted lepton is isolated
//////}
