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

float getMT2(TLorentzVector lept1, TLorentzVector lept2, float theMET, float theMETphi);

float getMT2_80(TLorentzVector lept1, TLorentzVector lept2, float theMET, float theMETphi);

float getMT2bb(std::vector<Jet>& jets, std::vector<Lepton>& leptons, float theMET, float theMETphi);

float getMT2lblb(std::vector<Jet>& jets, std::vector<Lepton>& leptons, float theMET, float theMETphi);

bool LeptonPTSorter(Lepton lep1, Lepton lep2);

bool LeptonIsoSorter(Lepton lep1, Lepton lep2);

bool JetPTSorter(Jet jet1, Jet jet2) ;

#endif
