#ifndef Jet_h
#define Jet_h

#include "TLorentzVector.h"

class Jet {
  public:
    Jet(TLorentzVector& lorentzVec00, int flavour00, float btag_disc00, unsigned int jetIndex00)
      : lorentzVec_(lorentzVec00), flavour_(flavour00), btag_disc_(btag_disc00), jetIndex_(jetIndex00) {};

    ~Jet() {}

    //void set_btagged(bool btagged) { btagged_ = btagged; }

    TLorentzVector& lorentzVec() { return lorentzVec_; }
    float flavour() {return flavour_; }
    unsigned int ijet() { return jetIndex_; }
    float btag_disc() { return btag_disc_; }


  private:
    TLorentzVector lorentzVec_;
    float flavour_;
    float btag_disc_;
    unsigned int jetIndex_;
}; 

#endif
