#include "ElectronPlots.h"

ElectronPlots::ElectronPlots(TString name) : StdPlots(name) {

  h_charge             = new TH1F("h_charge_"    +name ,"Charge of "+name,5,-2,3);
  h_PF_RelIso          = new TH1F("h_PF_RelIso_" +name ,name+" Particle Flow RelIso",100,0.,1.);
  h_dxy                = new TH1F("h_dxy_"       +name ,name+" transverse IP",100,0.0,0.5);
  h_dz                 = new TH1F("h_dz_"        +name ,name+" longitudinal IP",100,0.0,1.0);
 
}
ElectronPlots::~ElectronPlots() {
  //StdPlots::~StdPlots();
  delete h_charge;
  delete h_PF_RelIso;
  delete h_dxy;
  delete h_dz; 
}

void ElectronPlots::Fill(Float_t weight, Int_t N, TLorentzVector vLepton, Int_t charge, Float_t relIso, Float_t dxy, Float_t dz) {
  StdPlots::Fill(weight, N, vLepton.Pt(), vLepton.Eta(), vLepton.Phi());
  h_charge->Fill(charge, weight);
  h_PF_RelIso->Fill( relIso, weight);
  h_dxy->Fill(dxy, weight);
  h_dz->Fill(dz, weight);
}


void ElectronPlots::Write() {
  StdPlots::Write();
  h_charge->Write();
  h_PF_RelIso->Write();
  h_dxy->Write();
  h_dz->Write();
}
