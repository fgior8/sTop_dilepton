#ifndef ChainMaker_h
#define ChainMaker_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "TChain.h"
#include "TString.h"
#include "TFile.h"
#include "TH1D.h"

TChain* ChainMaker(TString filelist, Long64_t &eventProcessed);


#endif
