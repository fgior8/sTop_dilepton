#ifndef ZDYPlots_h
#define ZDYPlots_h

#include <string>
#include "TH1F.h"
#include "Lepton.h"


class ZDYPlots {
  UInt_t i,j;
  
 public:
  TH1F *h_DY_in, *h_DY_out, *h_DY_tot;
 
  ZDYPlots(TString name);
  ~ZDYPlots();
  void Fill(std::vector<Lepton>& leptons, Double_t weight, Bool_t Zveto);
  void Write();

};


#endif
