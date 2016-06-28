#ifndef Lepton_h
#define Lepton_h

#include "TLorentzVector.h"

class Lepton {
 public:
  enum LeptonType {Muon, Electron} ;
  enum FakeType {notfake, unknown, jet, cjet, bjet, chargemisid};
  enum LooseTight {Loose, Tight, Other};
  
 Lepton(LeptonType leptonType00, unsigned int leptonIndex00, TLorentzVector& vLepton00, float& eta00, float& chiNdof00, float& dxy_BS00, float& dz_BS00, int charge00, FakeType fakeType00, LooseTight looseTight00, float& relIso00)
   : leptonType_(leptonType00), leptonIndex_(leptonIndex00), lorentzVec_(vLepton00), eta_(eta00), chiNdof_(chiNdof00), dxy_BS_(dxy_BS00), dz_BS_(dz_BS00), charge_(charge00), fakeType_(fakeType00), looseTight_(looseTight00), relIso_(relIso00) {};
  ~Lepton() {};

  LeptonType leptonType() {return leptonType_; };
  unsigned int ilepton() { return leptonIndex_; };
  
  TLorentzVector& lorentzVec() { return lorentzVec_; }
  
  //void set_relIso(float& reliso) { relIso_ = reliso; }
  void set_relpt_mindr(std::pair<float, float>& thepair) { pair_relpt_mindr_ = thepair; }
  
  int charge() { return charge_; }
  
  float eta() {return eta_; }
  float chiNdof() {return chiNdof_; }
  
  float dxy_BS() { return dxy_BS_; }
  float dz_BS() { return dz_BS_; }
  
  float relIso() { return relIso_; }
  std::pair<float, float>& relpt_mindr() { return pair_relpt_mindr_; }
  
  //void setfakeType(FakeType fakeType) { fakeType_ = fakeType; }
  FakeType fakeType() { return fakeType_; }
  
  LooseTight looseTight() { return looseTight_; }
  void setQuality(LooseTight lt) { looseTight_ = lt; }
  
  //  bool operator<(Lepton& lepton_other) {
  //    return lorentzVec_.Pt() < lepton_other.lorentzVec().Pt();
  //  }

 private:
  LeptonType leptonType_;
  unsigned int leptonIndex_;
  
  TLorentzVector lorentzVec_;
  
  float eta_;
  float chiNdof_;
  
  float dxy_BS_;
  float dz_BS_;
  
  int charge_;
    
  FakeType fakeType_;
  LooseTight looseTight_;

  float relIso_;
  std::pair<float, float> pair_relpt_mindr_;
};

#endif
