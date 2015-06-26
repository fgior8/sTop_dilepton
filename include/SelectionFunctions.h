#ifndef SelectionFunctions_h
#define SelectionFunctions_h

#include <iostream>
using namespace std;

#include "Lepton.h"
#include <vector>

static const Float_t Mass_Z = 91.1876;
static const Float_t Mass_W = 80.398;

Bool_t isGoodEvent(Int_t nVertex, std::vector<Float_t> Vertex_Ndof, std::vector<Float_t> Vertex_X,  std::vector<Float_t> Vertex_Y, std::vector<Float_t> Vertex_Z, Float_t beamspot_x, Float_t beamspot_y, Bool_t *goodVerticies);

Bool_t isGoodEvent(Int_t nVertex, std::vector<Bool_t> Vertex_Fake, std::vector<Float_t> Vertex_Ndof, std::vector<Float_t> Vertex_X,  std::vector<Float_t> Vertex_Y, std::vector<Float_t> Vertex_Z, Bool_t *goodVerticies);

Bool_t ZandWveto(std::vector<Lepton>& leptonColl, Float_t MET, Float_t METPhi);

Bool_t Zselection(std::vector<Lepton>& leptonColl, Float_t MET);

Bool_t TriggerSelector (std::vector<TString> triggernames, std::vector<string> inputtriggers, std::vector<Bool_t> triggerdecision, std::vector<Int_t> HLTPrescales, Int_t &prescaler);
 
#endif

