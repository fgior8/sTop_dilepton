#include "XSlist.h"

float getXS(TString MCsample) {
  float eventXS=-1.;
  
  if (MCsample == "TTJets_MadSpin") 
    eventXS=0.03269;
  if (MCsample == "TbarW") 
    eventXS=0.03663305207;
  if (MCsample == "TW") 
    eventXS=0.03610181523;
  if (MCsample == "ZJets_Madgraph") 
    eventXS=2.129675056;
  if (MCsample == "WJets_Madgraph") 
    eventXS=6.141944936;
  if (MCsample == "TTWJets") 
    eventXS=0.72*1000./246521.;
  if (MCsample == "TTZJets") 
    eventXS=0.70*1000./249275.;
  if (MCsample == "WZTo3LNu") 
    eventXS=2.2*1000./237484.;
  
  if (MCsample == "WZTo3LNu") 
    eventXS=2.2*1000./237484.;
      
  if (MCsample == "WZTo3LNu") 
    eventXS=2.2*1000./237484.;
  
  if (MCsample == "T2tt_850LSP100") 
    eventXS=0.019*1000./102839.;
  if (MCsample == "T2tt_650LSP325") 
    eventXS=0.107*1000./105672.;
  if (MCsample == "T2tt_500LSP325") 
    eventXS=0.518*1000./109591.;
  if (MCsample == "T2tt_425LSP325") 
    eventXS=1.312*1000./1039030.;
  
  if (eventXS == -1.) {
    cout<<endl<<"NO CROSS-SECTION FOUND, PLEASE CHECK YOUR FILENAME OR LOOK INTO XSlis.cc"<<endl<<endl;
    return 0;
  }
  else
    return eventXS;
}
