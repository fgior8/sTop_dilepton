#include "XSlist.h"

float getXS_D(TString MCsample, Long64_t &eventProcessed) {
  float eventXS=-1.;
  
  if (MCsample.Contains("TTJets_MLM")) 
    eventXS=831.8/eventProcessed;//10259872;
  if (MCsample.Contains("TTbar_Powheg"))
    eventXS=831.8/eventProcessed;//92925926.;
  if (MCsample.Contains("TTbar2L_Powheg"))
    eventXS=88.3/eventProcessed;//104607105.;
  if (MCsample.Contains("TTLep_pow")) 
    eventXS=87.3/eventProcessed;//4997000;
  if (MCsample.Contains("TbarW")) 
    eventXS=35.6/eventProcessed;//985000;
  if (MCsample.Contains("TW")) 
    eventXS=35.6/eventProcessed;//998400;
  if (MCsample.Contains("DYJetsToLL_M10to50_aMCatNLO")) 
    eventXS=22635.1/eventProcessed;//30915886;
  if (MCsample.Contains("DYJetsToLL_M50_aMCatNLO")) 
    eventXS=6025.2/eventProcessed;//28696958;
  if (MCsample.Contains("DYJetsToLL_M50_MLM"))
    eventXS=6025.2/eventProcessed;//49877138;
  if (MCsample.Contains("WJetsToLNu_aMCatNLO")) 
    eventXS=61526.7/eventProcessed;//9908534;
  if (MCsample.Contains("TTWToLNu")) 
    eventXS=0.204/eventProcessed;//252673;
  if (MCsample.Contains("TTWToQQ")) 
    eventXS=0.406/eventProcessed;//833298;
  if (MCsample.Contains("TTZToLLNuNu")) //to be checked
    eventXS=0.2529/eventProcessed;//398600.;
  if (MCsample.Contains("TTZToQQ")) 
    eventXS=0.5297/eventProcessed;//749400;
  if (MCsample.Contains("WW")) 
    eventXS=115.0/eventProcessed;//993214; 
  if (MCsample.Contains("WZ")) 
    eventXS=47.1/eventProcessed;//1000000;
  if (MCsample.Contains("ZZ")) 
    eventXS=16.5/eventProcessed;//989312;
  if (MCsample.Contains("T2tt_850_100")) 
    eventXS=0.019/240685.;
  if (MCsample.Contains("T2tt_650LSP325")) 
    eventXS=0.107*1000./105672.;
  if (MCsample.Contains("T2tt_500_325")) 
    eventXS=0.518/388207.;
  if (MCsample.Contains("T2tt_425LSP325")) 
    eventXS=1.312*1000./1039030.;

  

  if (eventXS == -1.) {
    cout<<endl<<"NO CROSS-SECTION FOUND, PLEASE CHECK YOUR FILENAME OR LOOK INTO XSlis.cc"<<endl<<endl;
    return 0;
  }
  else
    return eventXS;
}



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
  if (MCsample == "T2tt_850LSP100") 
    eventXS=0.019*1000./102839.;
  if (MCsample == "T2tt_650LSP325") 
    eventXS=0.107*1000./105672.;
  if (MCsample == "T2tt_500LSP325") 
    eventXS=0.518*1000./109591.;
  if (MCsample == "T2tt_425LSP325") 
    eventXS=1.312*1000./1039030.;
  if (MCsample == "ZZ4L")
    eventXS=1.7*1000./1958600.;

  

  if (eventXS == -1.) {
    cout<<endl<<"NO CROSS-SECTION FOUND, PLEASE CHECK YOUR FILENAME OR LOOK INTO XSlis.cc"<<endl<<endl;
    return 0;
  }
  else
    return eventXS;
}


float getXSFIVE(TString MCsample) {
  float eventXS=-1.;

  if(MCsample.Contains("40"))
    eventXS=1.;
  
  if (MCsample == "TTbar_Powheg") 
    eventXS=0.04229604854;
  if (MCsample == "TTJets_aMCatNLO") 
    //eventXS=0.1665435251;
    eventXS=1000.*831.8/1.060e+10;
  if (MCsample == "TbarW") 
    eventXS=0.0356;
  if (MCsample == "TW") 
    eventXS=0.03565705128;

  if (MCsample == "DYJets_aMCatNLO")
    // eventXS=1.532400442;
    eventXS=1000.*22635.1/393416887212.;
  if (MCsample == "ZJets_aMCatNLO") 
    //eventXS=0.3031459467;
    eventXS=1000.*6025.2/312209331012.;
  if (MCsample == "WJets_aMCatNLO") 
    //eventXS=2.554035823;
    eventXS=1000.*61526.7/3.720e+12;
  
  if (MCsample == "TTWJets") 
    eventXS=0.72*1000./246521.;
  if (MCsample == "TTZJets") 
    eventXS=0.70*1000./249275.;
  
  if (MCsample == "WW") 
    eventXS=118.7*1000./989608.; 
  if (MCsample == "WZ") 
    eventXS=65.9*1000./996920.;
  if (MCsample == "ZZ") 
    eventXS=31.8*1000./998848.;
  
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
