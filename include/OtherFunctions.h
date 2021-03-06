#ifndef OtherFunctions_h
#define OtherFunctions_h

#include <iostream>
using namespace std;
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "Data.h"
#include "Lepton.h"
#include "Jet.h"
#include "mt2bisect.h"

TLorentzVector getllmetVector(TLorentzVector lept1, TLorentzVector lept2, float MET, float MET_phi);
float getMeff(std::vector<Jet>& jets, std::vector<Lepton>& leptons, float MET);
float getdPhiPtllbMet(TLorentzVector Ptllb, float MET, float MET_phi);
float getdPhiJetMet(std::vector<Jet>& jets, float MET, float MET_phi);
float getdPhiLepMet(TLorentzVector lep, float MET, float MET_phi);
float getdPhiLepJet(TLorentzVector lep, TLorentzVector jet);
float getdPhill(TLorentzVector lep1, TLorentzVector lep2);

float getMT2(TLorentzVector lept1, TLorentzVector lept2, float theMET, float theMETphi);

float getMT2_80(TLorentzVector lept1, TLorentzVector lept2, float theMET, float theMETphi);

float getMT2bb(std::vector<Jet>& jets, std::vector<Lepton>& leptons, float theMET, float theMETphi);

float getMT2lblb(std::vector<Jet>& jets, std::vector<Lepton>& leptons, float theMET, float theMETphi);

float getDiTopMass(std::vector<Jet>& jets, std::vector<Lepton>& leptons, float MET, float MET_phi);

int nthdigit(int x, int n);

bool LeptonPTSorter(Lepton lep1, Lepton lep2);

bool LeptonIsoSorter(Lepton lep1, Lepton lep2);

bool JetPTSorter(Jet jet1, Jet jet2) ;

#endif
