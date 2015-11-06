#ifndef JetPlots_h
#define JetPlots_h

#include "StdPlots.h"
#include "JetSelection.h"

class JetPlots : public StdPlots{
 public:
  TH1F *h_energy, *h_CombSV, *h_SC;
  JetPlots(TString name);
  ~JetPlots();
  void Fill(Float_t weight, Int_t N, TLorentzVector vJet, Float_t CombSVtxV2, Float_t SC);
  void Write();
};

#endif

