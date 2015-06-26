#include "ElectronPlots.h"

ElectronPlots::ElectronPlots(TString name) : StdPlots(name) {

  h_charge             = new TH1F("h_"+name+"_charge","Charge of "+name,5,-2,3);
  h_PF_RelIso    = new TH1F("h_"+name+"__PF_RelIso",name+" Particle Flow RelIso",100,0.,1.);
  h_PF_RelIso_beta = new TH1F("h_"+name+"__PF_RelIso_beta",name+" Particle Flow RelIso #beta corrected",100,0.,1.);
  h_dxy                = new TH1F("h_"+name+"_dxy",name+" transverse IP",100,0.0,0.5);
  h_dz                 = new TH1F("h_"+name+"_dz",name+" longitudinal IP",100,0.0,1.0);
  h_photonIso          = new TH1F("h_"+name+"_photonIso",name+" photon Iso",100,0.,10.);
  h_PUpt               = new TH1F("h_"+name+"_PUpt",name+" Particle Flow pileup correction",100,0.,1.);
  h_chargedHadronIso   = new TH1F("h_"+name+"_chargedHadronIso",name+" charged Hadron Iso",100,0.,10.);
  h_neutralHadronIso   = new TH1F("h_"+name+"_neutralHadronIso",name+" neutral Hadron Iso",100,0.,10.);
  h_PF_RelIso          = new TH1F("h_"+name+"_PF_RelIso",name+" Particle Flow RelIso",100,0.,1.);
}
ElectronPlots::~ElectronPlots() {
  //StdPlots::~StdPlots();
  delete h_charge;
  delete h_PF_RelIso;
  delete h_PF_RelIso_beta;
  delete h_dxy;
  delete h_dz; 
  delete h_photonIso;
  delete h_chargedHadronIso;
  delete h_neutralHadronIso;
  delete h_PF_RelIso;
  delete h_PUpt;
}

void ElectronPlots::Fill(Float_t weight, Int_t N, TLorentzVector vLepton, Int_t charge, Float_t chargedHadronIso, Float_t neutralHadronIso, Float_t photonIso, Float_t PUpt, Float_t dxy, Float_t dz) {
  StdPlots::Fill(weight, N, vLepton.Pt(), vLepton.Eta(), vLepton.Phi());
  h_charge->Fill(charge, weight);
  if (vLepton.Pt()>0.01) {
    h_photonIso->Fill(photonIso, weight);
    h_chargedHadronIso->Fill(chargedHadronIso, weight);
    h_neutralHadronIso->Fill(neutralHadronIso, weight);
    h_PUpt->Fill(PUpt, weight);
  }
  if (vLepton.Pt()>0.01) {
    h_PF_RelIso->Fill( (photonIso+chargedHadronIso+neutralHadronIso)/ vLepton.Pt() , weight);
    h_PF_RelIso_beta->Fill( (chargedHadronIso + max(0.0, neutralHadronIso + photonIso - 0.5*PUpt))/ vLepton.Pt() , weight);
  }
  h_dxy->Fill(dxy, weight);
  h_dz->Fill(dz, weight);
}


void ElectronPlots::Write() {
  StdPlots::Write();
  h_charge->Write();
  h_PF_RelIso->Write();
  h_PF_RelIso_beta->Write();
  h_dxy->Write();
  h_dz->Write();
  h_photonIso->Write();
  h_chargedHadronIso->Write();
  h_neutralHadronIso->Write();
  h_PUpt->Write();
}
