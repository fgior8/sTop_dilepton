#ifndef XSlist_h
#define XSlist_h

#include <TROOT.h>
#include <iostream>
using namespace std;

float getXS(TString MCsample);

float getXS_D(TString MCsample, Long64_t &eventProcessed);

float getXSFIVE(TString MCsample);


#endif

