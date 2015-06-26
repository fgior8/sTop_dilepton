#include "JetPlots.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

JetPlots::JetPlots(TString name) : StdPlots(name) {

  h_TCHPT              = new TH1F("h_"+name+"_TCHPT","Track Counting High Purity "+name,100,-3,5);
  h_CombSV                 = new TH1F("h_"+name+"_CombSVtxV2",name+" CombInclusiveSVtxV2",100,-1,2);
  h_CSV                = new TH1F("h_"+name+"_CSV",name+" Combined Seconday Vertex",100,-1,2);
}

JetPlots::~JetPlots() {
  // ~StdPlots();
  delete h_TCHPT;
  delete h_CombSV;
  delete h_CSV;
}

void JetPlots::Fill(Float_t weight, Int_t N, TLorentzVector vJet, Float_t TCHPT, Float_t CombSVtxV2, Float_t CSV) {

  StdPlots::Fill(weight, N, vJet.Pt(), vJet.Eta(), vJet.Phi());
 
  h_TCHPT->Fill(TCHPT, weight);
  h_CombSV->Fill(CombSVtxV2, weight);
  h_CSV->Fill(CSV, weight);
}

void JetPlots::Write() {
  StdPlots::Write();
  h_TCHPT->Write();
  h_CombSV->Write();
  h_CSV->Write();
}

