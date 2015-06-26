#include "MuonPlots.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

MuonPlots::MuonPlots(TString name) : StdPlots(name) {

  h_charge             = new TH1F("h_"+name+"_charge","Charge of "+name,5,-2,3);
  h_HCalIso            = new TH1F("h_"+name+"_HCalIso",name+" HCal Iso",100,0.,10.);
  h_ECalIso            = new TH1F("h_"+name+"_ECalIso",name+" ECal Iso",100,0.,10.);
  h_TrkIso             = new TH1F("h_"+name+"_TrkIso",name+" Tracker Iso",100,0.,10.);
  h_Detector_RelIso    = new TH1F("h_"+name+"_Detector_RelIso",name+" Detector_RelIso",100,0.,1.);
  h_Detector_RelIsorho = new TH1F("h_"+name+"_Detector_RelIso_rho",name+" Detector_RelIso #rho corrected",100,0.,1.);
  h_photonIso          = new TH1F("h_"+name+"_photonIso",name+" photon Iso",100,0.,1.);
  h_chargedHadronIso   = new TH1F("h_"+name+"_chargedHadronIso",name+" charged Hadron Iso",100,0.,1.);
  h_neutralHadronIso   = new TH1F("h_"+name+"_neutralHadronIso",name+" neutral Hadron Iso",100,0.,1.);
  h_PF_RelIso          = new TH1F("h_"+name+"_PF_RelIso",name+" Particle Flow RelIso",100,0.,1.);
  h_PF_RelIso_beta     = new TH1F("h_"+name+"_PF_RelIso_beta",name+" Particle Flow RelIso #beta corrected",100,0.,1.);
  h_PUpt	       = new TH1F("h_"+name+"_PUpt",name+" Particle Flow pileup correction",100,0.,1.);
  h_HCalIsoDeposit     = new TH1F("h_"+name+"_HCalIsoDeposit",name+" HCal Iso Deposit",100,0.,10.);
  h_ECalIsoDeposit     = new TH1F("h_"+name+"_ECalIsoDeposit",name+" ECal Iso Deposit",100,0.,10.);
  h_GlbChi2            = new TH1F("h_"+name+"_GlbChi2",name+" Global #chi^{2} per #DoF",120,0.,12.);
  h_dxy                = new TH1F("h_"+name+"_dxy",name+" transverse IP",300,0.0,0.3);
  h_dz                 = new TH1F("h_"+name+"_dz",name+" longitudinal IP",100,0.0,1.0);
}

MuonPlots::~MuonPlots() {
  // ~StdPlots();
  delete h_charge;
  delete h_HCalIso;
  delete h_ECalIso;
  delete h_TrkIso;
  delete h_Detector_RelIso;
  delete h_Detector_RelIsorho;
  delete h_HCalIsoDeposit;
  delete h_ECalIsoDeposit;  
  delete h_photonIso;
  delete h_chargedHadronIso;
  delete h_neutralHadronIso;
  delete h_PF_RelIso;
  delete h_PF_RelIso_beta;
  delete h_PUpt;
  delete h_GlbChi2;
  delete h_dxy;
  delete h_dz;
}

void MuonPlots::Fill(Float_t weight, Int_t N, TLorentzVector vLepton, Int_t charge, Float_t chargedHadronIso, Float_t neutralHadronIso, Float_t photonIso, Float_t PUpt, Float_t Muon_GlobalChi2, Float_t dxy, Float_t dz) {
  
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
  h_GlbChi2->Fill(Muon_GlobalChi2, weight);
  h_dxy->Fill(dxy, weight);
  h_dz->Fill(dz, weight);

}



void MuonPlots::Write() {
  StdPlots::Write();
  h_charge->Write();
  //h_HCalIso->Write();
  //h_ECalIso->Write();
  //h_TrkIso->Write();
  //h_Detector_RelIso->Write();
  //h_Detector_RelIsorho->Write();
  //h_HCalIsoDeposit->Write();
  //h_ECalIsoDeposit->Write();
  h_photonIso->Write();
  h_chargedHadronIso->Write();
  h_neutralHadronIso->Write();
  h_PF_RelIso->Write();
  h_PF_RelIso_beta->Write();
  h_PUpt->Write();
  h_GlbChi2->Write();
  h_dxy->Write();
  h_dz->Write();
}
