#include "JetPlots.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

JetPlots::JetPlots(TString name) : StdPlots(name) {

  h_CombSV                 = new TH1F("h_"+name+"_CombSVtxV2",name+" Comb Inclusive SVtxV2",100,-1,2);
  h_SC                = new TH1F("h_"+name+"_SC",name+" Combined MVA",100,-1,2);
}

JetPlots::~JetPlots() {
  // ~StdPlots();
  delete h_CombSV;
  delete h_SC;
}

void JetPlots::Fill(Float_t weight, Int_t N, TLorentzVector vJet, Float_t CombSVtxV2, Float_t SC) {

  StdPlots::Fill(weight, N, vJet.Pt(), vJet.Eta(), vJet.Phi());
 
  h_CombSV->Fill(CombSVtxV2, weight);
  h_SC->Fill(SC, weight);
}

void JetPlots::Write() {
  StdPlots::Write();
  h_CombSV->Write();
  h_SC->Write();
}

