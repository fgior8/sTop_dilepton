#include "StdPlots.h"

StdPlots::StdPlots(TString name) {  

  h_particles = new TH1F("h_N_"  +name  , "Number of "+name,   20,0,20);
  h_pt        = new TH1F("h_pt_" +name  , name+" p_{t} (GeV)", 100,0,1000);
  h_eta       = new TH1F("h_eta_"+name  , name+" #eta",        100,-5,5);
  h_phi       = new TH1F("h_phi_" +name  , name+" #phi",        100,-3.1415926535,3.1415926535);

}

StdPlots::~StdPlots() {
  delete h_particles;
  delete h_pt;
  delete h_eta;
  delete h_phi;
}

void StdPlots::Fill(Double_t weight, Int_t N, Double_t pt, Double_t eta, Double_t phi) {
  h_particles->Fill(N,weight/N);
  h_pt->Fill(pt,weight);
  h_eta->Fill(eta,weight);
  h_phi->Fill(phi,weight);
}

void StdPlots::Write() {
 h_particles->Write();
 h_pt->Write();
 h_eta->Write();
 h_phi->Write();
}

