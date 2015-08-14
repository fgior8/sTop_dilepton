#include "ZDYPlots.h"

ZDYPlots::ZDYPlots(TString name) {  
  h_DY_in     = new TH1F("h_"+name+"_DY_in" , "Invariant mass of the two leading muons within the Z window for "+name,  100,0,1000);
  h_DY_out    = new TH1F("h_"+name+"_DY_out", "Invariant mass of the two leading muons outside the Z window for "+name, 100,0,1000);
  h_DY_tot    = new TH1F("h_"+name+"_DY_tot", "Invariant mass of the two leading muons within the Z for "+name,         100,0,1000);
}

ZDYPlots::~ZDYPlots() {
  delete h_DY_in;
  delete h_DY_out;
  delete h_DY_tot;
}

void ZDYPlots::Fill(std::vector<Lepton>& leptons, Double_t weight, Bool_t Zveto) {
  i=0; j=1;
  if (Zveto) 
    h_DY_out->Fill( (leptons[i].lorentzVec()+leptons[j].lorentzVec()).M(), weight);
  else
    h_DY_in->Fill( (leptons[i].lorentzVec()+leptons[j].lorentzVec()).M(), weight);
  h_DY_tot->Fill( (leptons[i].lorentzVec()+leptons[j].lorentzVec()).M(), weight);
}

void ZDYPlots::Write() {
 h_DY_in->Write();
 h_DY_out->Write();
 h_DY_tot->Write();
}


