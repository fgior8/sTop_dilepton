#include "MuonPlots.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

MuonPlots::MuonPlots(TString name) : StdPlots(name) {

  h_charge             = new TH1F("h_"+name+"_charge","Charge of "+name,5,-2,3);
  h_PF_RelIso          = new TH1F("h_"+name+"_PF_RelIso",name+" Particle Flow RelIso",100,0.,1.);
  h_GlbChi2            = new TH1F("h_"+name+"_GlbChi2",name+" Global #chi^{2} per #DoF",120,0.,12.);
  h_dxy                = new TH1F("h_"+name+"_dxy",name+" transverse IP",300,0.0,0.3);
  h_dz                 = new TH1F("h_"+name+"_dz",name+" longitudinal IP",100,0.0,1.0);
}

MuonPlots::~MuonPlots() {
  // ~StdPlots();
  delete h_charge;
  delete h_PF_RelIso;
  delete h_GlbChi2;
  delete h_dxy;
  delete h_dz;
}

void MuonPlots::Fill(Float_t weight, Int_t N, TLorentzVector vLepton, Int_t charge, Float_t relIso, Float_t Muon_GlobalChi2, Float_t dxy, Float_t dz) {
  
  StdPlots::Fill(weight, N, vLepton.Pt(), vLepton.Eta(), vLepton.Phi());
  h_charge->Fill(charge, weight);
  h_PF_RelIso->Fill( relIso, weight);
  h_GlbChi2->Fill(Muon_GlobalChi2, weight);
  h_dxy->Fill(dxy, weight);
  h_dz->Fill(dz, weight);
}



void MuonPlots::Write() {
  StdPlots::Write();
  h_charge->Write();
  h_PF_RelIso->Write();
  h_GlbChi2->Write();
  h_dxy->Write();
  h_dz->Write();
}
