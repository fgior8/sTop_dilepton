#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TDirectory.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TString.h"
#include "TDirectory.h"
#include "TROOT.h"
#include "TObject.h"
#include "TStopwatch.h"
#include "TLegend.h"
#include <vector>
#include <string>

#include <fstream>
#include <vector>
#include <sys/stat.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <set>


/***********************
 Files and Directories
************************/

//TString dirnameIn= "/home/brochero/ttbar/TopCode/TopResults/";
//TString dirnameIn= "/gpfs/csic_users/albertog/New_StopAnalysis_Nov2012/PAF/TopResults/compareSelections_ttbarVsStop_12mar2013/ttbar/";
TString dirnameIn= "/gpfs/csic_users/fgior8/sTop/PAF/StopResults/stop/";
//TString fl  = "v1_TreeAnalysisTop_isocorr_19602.9pb-1";  
//TString fl  = "v1_TreeAnalysisTop_btag_19602.9pb-1";  
//TString fl  = "NoJetCut_TreeAnalysisTop_btag_19602.9pb-1";  
TString fl  = "_LooseMuonIso9999p0_LooseElecIso9999p0TreeAnalysisStop_19602.9pb-1";  

//SUSY Plots
bool SUSY=true;
//bool SUSY=false;

/******************
  SF Efficiencies
*****************/
//30-10-2012
float SF_trigger_mumu=0.965;// +/- 0.0102;
float SF_trigger_ee  =0.962;// +/- 0.0130;
float SF_trigger_mue =0.943;// +/- 0.0120;
//02-11-2012
float SF_IDISO_mumu=0.997;// +/- 0.00085;
float SF_IDISO_ee  =0.975;// +/- 0.0006;
float SF_IDISO_mue =0.986;// +/- 0.0007;

/* //ICHEP */
/* float SF_trigger_mumu=0.994;// +/- 0.0102; */
/* float SF_trigger_ee  =0.955;// +/- 0.0130; */
/* float SF_trigger_mue =0.978;// +/- 0.0120; */
/* //ICHEP */
/* float SF_IDISO_mumu=0.993;// +/- 0.00085; */
/* float SF_IDISO_ee  =0.970;// +/- 0.0006; */
/* float SF_IDISO_mue =0.986;// +/- 0.0007; */

Float_t SFmumu=SF_trigger_mumu*SF_IDISO_mumu;
Float_t SFee  =SF_trigger_ee*SF_IDISO_ee;
Float_t SFmue =SF_trigger_mue*SF_IDISO_mue;

//MET No Jet Cut
/* Float_t SFmumu=SF_trigger_mumu*SF_IDISO_mumu*(25947.0-19989.1)/(26153.3-19989.1); */
/* Float_t SFee  =SF_trigger_ee*SF_IDISO_ee*(20621.0-17308.5)/(22543.4-17308.5); */
/* Float_t SFmue =SF_trigger_mue*SF_IDISO_mue*(30703)/(28236.7); */



float SF_BR=(0.108*9)*(0.108*9);

/******************
  Efficiencies
*****************/
// lepton selection model (ISO, ID, trigger)->06/11/2012
double lept_uncer = ( (1.1 + 1.4 + 2.0*1.3)/4 )/100.0; 

float SF_BR_uncer = 1.7/100.;

float XsecTTbar_uncer = 15.0/100.;
float XsecTWVV_uncer  = 20.0/100.;

double SF_uncer[5];//btag[bin]

double lumi_error = 4.4/100.;

double theoryQ2_error      =2.1/100.;
double theoryMatching_error=1.4/100.;

double dd_dd_uncer     = 30./100.; //DY Data Driven
double dd_tautau_uncer = 0.;
double fake_uncer      = 0.;

//Uncertainties->06/11/2012
/* double LES_uncer= 0.2/100.0; */
/* double JES_uncer= ( (3.2 + 2.9 + 2.0*2.5)/4 )/100.0; */
/* double JER_uncer= ( (1.6 + 1.3 + 2.0*1.3)/4 )/100.0; */
/* double PU_uncer = ( (0.3 + 0.4 + 0.7*1.4)/4 )/100.0; */
//Uncertainties->20/12/2012
double LES_uncer= 0.2/100.0;
double JES_uncer= ( (3.2 + 3.1 + 2.0*2.4)/4 )/100.0;
double JER_uncer= ( (1.6 + 1.3 + 2.0*1.2)/4 )/100.0;
double PU_uncer = ( (0.5 + 0.5 + 2.0*0.6)/4 )/100.0;
  
/******************
     Samples
******************/


typedef struct {
  
  //[histo][channel];
  
/*   TH1F     *hist[15][5]; */
/*   THStack  *mc[15][5]; */

  TH1F     *hist[20][5];
  THStack  *mc[20][5];
//FG addition
  TH2F     *hist2D[3][5];
  TH2F     *mc2D[3][5];
  
} Histograms;


Histograms DoubleMuon;
Histograms DoubleElectron;
Histograms MuEG;  
Histograms Data;

Histograms DYJets;
Histograms DY;

Histograms TbarW;
Histograms TW;
Histograms SingleT;

Histograms TTbar;

Histograms TTbarBkg;
Histograms WJets;
Histograms NONWZ;

Histograms WW;
Histograms WZ;
Histograms ZZ;
Histograms VV;

Histograms TTZJets;
Histograms TTWJets;
Histograms WgammaToLNuG;
Histograms ZgammaToLLG;
Histograms HWW125;
Histograms WWGJets;
Histograms TTGJets;
Histograms RareBkg;

Histograms ZJets;
Histograms Z;
Histograms ZDY;

Histograms STop; //Signal

Histograms ratio;     //Ratio

Histograms MCStack ; //MC Stack
