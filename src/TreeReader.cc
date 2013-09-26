/*
  TreeReader.cpp

  Compilation: gcc -I`root-config --incdir` -o TreeReader.run TreeReader.cc mt2bisect.cc `root-config --libs` 
             
  Arguments: Name of the cut
  Options:   -o Name of the output root file
  -i Name of the input root file
	   

*/

#ifndef __CINT__

#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <set>
#include <vector>

#include "TDirectory.h"
#include "TROOT.h"
#endif

//#include "TKey.h"
#include "TObject.h"
//#include "TPrint.h"
#include "TCanvas.h"
#include "TStopwatch.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TProfile.h"
#include "TFile.h"
#include "TChain.h"
#include "TLorentzVector.h"
#include "TSystem.h"
#include "TTree.h"
//#include <exception>
#include <sys/stat.h>

//CONTROLREGION
#define NUM_CUTS 24

#include "mt2bisect.h" 

typedef struct {
  float stopProdXsec;
  float stopProdXsecUncert;  
} StopXSec;

#ifndef __CINT__

void display_usage()
{
  std::cout << "\033[1;37musage:\033[1;m skimfile cutindex [options]" << std::endl;
  std::cout << "" << std::endl;
  std::cout << "Options:" << std::endl;
  std::cout << "    -i inputfile.root  Input file" << std::endl;
  std::cout << "    -o name in the output file \"h_\"" << std::endl;
  std::cout << "    -d Input file directory. Default directory: InputTrees" << std::endl;
  std::cout << "    -h                 displays this help message and exits " << std::endl;
  std::cout << "" << std::endl;
}

StopXSec getCrossSectionStop(float);
float    getMT2(TLorentzVector, TLorentzVector, float, float);

int main(int argc, const char* argv[]){
  
  gSystem->Load("libTree");
  
  const char * _output   = 0;
  const char * _input    = 0;
  double muiso=0;
  double eliso=0;
  //const char * _dir      = "InputTrees/stop/";
  const char * _dir      = "/gpfs/csic_projects/cms/fgior8/InputTrees_stop_04sep2013/";

  // Arguments used
  //std::set<int> usedargs;
  //Parsing input options
  if(argc == 1){
    display_usage();
    return -1;
  }
  
  else{
    //Argument 1 must be a valid input fileName
    for (int i = 1; i < argc; i++){
      if( strcmp(argv[i],"-i") == 0 ){
	_input = argv[i+1];
	i++;
      }
      if( strcmp(argv[i],"-d") == 0 ){
	_dir = argv[i+1];
	i++;
      }
      if( strcmp(argv[i],"-o") == 0 ){
	_output= argv[i+1];
	i++;
      }
      if( strcmp(argv[i],"-muiso") == 0 ){
        muiso= atof(argv[i+1]);
        i++;
      }
      if( strcmp(argv[i],"-eliso") == 0 ){
        eliso= atof(argv[i+1]);
        i++;
      }
      if( strcmp(argv[i],"-h") == 0 ||
	  strcmp(argv[i],"--help") == 0 ){
	display_usage();
	return 0;
      }
    }
  }//else
  if( _input ==0 || muiso == 0 || eliso == 0){
    std::cerr << "\033[1;31mskimfile ERROR:\033[1;m The '-i' option is mandatory!"
	      << std::endl;
    display_usage();
    return -1;
  }

  // reassigning
  TString fname(_input);
  TString hname(_output);
  TString fdir(_dir);
  
  TChain theTree("AnalysisTree"); 
  
  std::cout << "Signal: ";
  std::cout << fname << std::endl;
  
  theTree.Add(fdir+fname);
  std::cout<<"Adding "<<fdir<<fname<<std::endl; 
 
  int   Event,Type,PV;
  float PUWeight;
  float MET,MET_Phi,METSig;
  float Lep0Px,Lep0Py,Lep0Pz,Lep0E,Lep1Px,Lep1Py,Lep1Pz,Lep1E;
  float NJets,HT,NBtagJets,Btag_j0,Btag_j1;
  float Jet0Px,Jet0Py,Jet0Pz,Jet0E,/*Jet0Et,*/Jet1Px,Jet1Py,Jet1Pz,Jet1E,Jet1Et;
  float BtagJet0Px,BtagJet0Py,BtagJet0Pz,BtagJet0E,/*BtagJet0Et,*/BtagJet1Px,BtagJet1Py,BtagJet1Pz,BtagJet1E,BtagJet1Et;
  bool  Lep0isTight, Lep1isTight;
  float Lep0RelIso, Lep1RelIso;

  float SysVarJet0,SysVarJet1,SysVarBtagJet0,SysVarBtagJet1;
  float UncJet0,UncJet1,UncBtagJet0,UncBtagJet1;

  float TGenStopMass0,TGenStopMass1,TGenChi0Mass0,TGenChi0Mass1;
  
  theTree.SetBranchAddress( "TEvent",   &Event );
  theTree.SetBranchAddress( "TWeight",  &PUWeight );
  theTree.SetBranchAddress( "TChannel", &Type );
  theTree.SetBranchAddress( "TNPV",     &PV );

  theTree.SetBranchAddress( "TMET",     &MET );
  theTree.SetBranchAddress( "TMET_Phi", &MET_Phi );
  theTree.SetBranchAddress( "TMETSig",  &METSig );

  theTree.SetBranchAddress( "TLep0Px", &Lep0Px );
  theTree.SetBranchAddress( "TLep0Py", &Lep0Py );
  theTree.SetBranchAddress( "TLep0Pz", &Lep0Pz );
  theTree.SetBranchAddress( "TLep0E",  &Lep0E );
  theTree.SetBranchAddress( "TLep0isTight",&Lep0isTight );
  theTree.SetBranchAddress( "TLep0RelIso",&Lep0RelIso );

  theTree.SetBranchAddress( "TLep1Px", &Lep1Px );
  theTree.SetBranchAddress( "TLep1Py", &Lep1Py );
  theTree.SetBranchAddress( "TLep1Pz", &Lep1Pz );
  theTree.SetBranchAddress( "TLep1E",  &Lep1E );
  theTree.SetBranchAddress( "TLep1isTight",&Lep1isTight );
  theTree.SetBranchAddress( "TLep1RelIso",&Lep1RelIso );

  theTree.SetBranchAddress( "TNJets",    &NJets );
  theTree.SetBranchAddress( "THT",       &HT );
  theTree.SetBranchAddress( "TNJetsBtag",&NBtagJets );
  theTree.SetBranchAddress( "TBtagJet0", &Btag_j0 );
  theTree.SetBranchAddress( "TBtagJet1", &Btag_j1 );

  theTree.SetBranchAddress( "TJet0Px", &Jet0Px );
  theTree.SetBranchAddress( "TJet0Py", &Jet0Py );
  theTree.SetBranchAddress( "TJet0Pz", &Jet0Pz );
  theTree.SetBranchAddress( "TJet0E", &Jet0E );
  //theTree.SetBranchAddress( "TJet0Et", &Jet0Et );

  theTree.SetBranchAddress( "TJet1Px", &Jet1Px );
  theTree.SetBranchAddress( "TJet1Py", &Jet1Py );
  theTree.SetBranchAddress( "TJet1Pz", &Jet1Pz );
  theTree.SetBranchAddress( "TJet1E", &Jet1E );  
  theTree.SetBranchAddress( "TJet1Et", &Jet1Et );

  theTree.SetBranchAddress( "TBtagJet0Px", &BtagJet0Px );
  theTree.SetBranchAddress( "TBtagJet0Py", &BtagJet0Py );
  theTree.SetBranchAddress( "TBtagJet0Pz", &BtagJet0Pz );
  theTree.SetBranchAddress( "TBtagJet0E", &BtagJet0E );
  //theTree.SetBranchAddress( "TBtagJet0Et", &BtagJet0Et );

  theTree.SetBranchAddress( "TBtagJet1Px", &BtagJet1Px );
  theTree.SetBranchAddress( "TBtagJet1Py", &BtagJet1Py );
  theTree.SetBranchAddress( "TBtagJet1Pz", &BtagJet1Pz );
  theTree.SetBranchAddress( "TBtagJet1E", &BtagJet1E );
  theTree.SetBranchAddress( "TBtagJet1Et", &BtagJet1Et );

  if (theTree.GetBranch("TGenStopMass0")){
    theTree.SetBranchAddress( "TGenStopMass0", &TGenStopMass0 );
    theTree.SetBranchAddress( "TGenStopMass1", &TGenStopMass1 );
    theTree.SetBranchAddress( "TGenChi0Mass0", &TGenChi0Mass0 );
    theTree.SetBranchAddress( "TGenChi0Mass1", &TGenChi0Mass1 );
  }
  else{
    TGenStopMass0 = -99.;
    TGenStopMass1 = -99.;
    TGenChi0Mass0 = -99.;
    TGenChi0Mass1 = -99.;
  }

  if(fname.Contains("JES") || fname.Contains("JER")){

    theTree.SetBranchAddress( "TSysVarJet0", &SysVarJet0 );
    theTree.SetBranchAddress( "TSysVarJet1", &SysVarJet1 );
    theTree.SetBranchAddress( "TSysVarBtagJet0", &SysVarBtagJet0 );
    theTree.SetBranchAddress( "TSysVarBtagJet1", &SysVarBtagJet1 );

    theTree.SetBranchAddress( "TUncJet0", &UncJet0 );
    theTree.SetBranchAddress( "TUncJet1", &UncJet1 );
    theTree.SetBranchAddress( "TUncBtagJet0", &UncBtagJet0 );
    theTree.SetBranchAddress( "TUncBtagJet1", &UncBtagJet1 );

  }

  else {

    SysVarJet0=1.0;
    SysVarJet1=1.0;
    SysVarBtagJet0=1.0;
    SysVarBtagJet1=1.0;

    UncJet0=1.0;
    UncJet1=1.0;
    UncBtagJet0=1.0;
    UncBtagJet1=1.0;

  }  
  
  std::cout << "--- Processing: " << theTree.GetEntries() << " events" << std::endl;
  
  /*********************************
             Histograms
  **********************************/

  //FG addition
  TH2F *hMT2ll_MT2lb[NUM_CUTS][3];
  TH2F *hMT2ll_MT2bb[NUM_CUTS][3];
  TH2F *hMT2ll_MT2llbb[NUM_CUTS][3];
  TH1F *hMT2bb[NUM_CUTS][3];
  
  TH1F *hPV[NUM_CUTS][3];
  TH1F *hMET[NUM_CUTS][3],*hMET_Phi[NUM_CUTS][3],*hMETSig[NUM_CUTS][3];
  TH1F *hInvMass[NUM_CUTS][3],*hDiLepPt[NUM_CUTS][3],*hLep0Pt[NUM_CUTS][3],*hLep1Pt[NUM_CUTS][3],*hLep0Eta[NUM_CUTS][3],*hLep1Eta[NUM_CUTS][3];
  TH1F *hNJets[NUM_CUTS][3],*hHT[NUM_CUTS][3],*hNBtagJets[NUM_CUTS][3],*hNBtagJets5[NUM_CUTS][3],*hJet0Pt[NUM_CUTS][3],*hJet1Pt[NUM_CUTS][3],*hBtagJet0Pt[NUM_CUTS][3];
  TH1F *hMT2ll[NUM_CUTS][3],*hMT2lb[NUM_CUTS][3];
  TH1F *hLep0RelIso[NUM_CUTS][3],*hLep1RelIso[NUM_CUTS][3];

  TH1F *hDeltaPhiLep[NUM_CUTS][3],*hDeltaEtaLep[NUM_CUTS][3],*hDeltaPhiLepMET[NUM_CUTS][3],*hDeltaPhiLepBtag[NUM_CUTS][3],*hDeltaPhiMETBtag[NUM_CUTS][3];
  TH1F *hInvMassLepBtag[NUM_CUTS][3],*hInvTMassMETBtag[NUM_CUTS][3];

  TH1F *hDYIn[NUM_CUTS][3],*hDYOut[NUM_CUTS][3];
  TH2F *hDY_NPV[NUM_CUTS][3];
  TH2F *hDY_NJets[NUM_CUTS][3];

  TH1F *hSysVarJet0[NUM_CUTS][3]        ,*hUncJet0[NUM_CUTS][3];
  TH1F *hSysVarJet1[NUM_CUTS][3]        ,*hUncJet1[NUM_CUTS][3];
  TH1F *hSysVarBtagJet0[NUM_CUTS][3]    ,*hUncBtagJet0[NUM_CUTS][3];
  TH2F *hSysVarJet0Pt[NUM_CUTS][3]      ,*hUncJet0Pt[NUM_CUTS][3];
  TH2F *hSysVarJet1Pt[NUM_CUTS][3]      ,*hUncJet1Pt[NUM_CUTS][3];
  TH2F *hSysVarBtagJet0Pt[NUM_CUTS][3]  ,*hUncBtagJet0Pt[NUM_CUTS][3];

  TString namech[3];
  namech[0]="mumu";
  namech[1]="ee";
  namech[2]="mue";

  //CONTROLREGION
  TString namecut[NUM_CUTS];
  namecut[0]="dilepton";
  namecut[1]="2Jets";
  namecut[2]="MET";
  namecut[3]="1btag";//UNBLINDED
  namecut[4]="MT2ll";
  namecut[5]="MT2ll_looseSel";
  namecut[6]="2Jets_looseSel";
  namecut[7]="Ctrl_1Jet_0BJet_lt10MET";
  namecut[8]="Ctrl_1Jet_0BJet_lt10MET_looseSel";
  namecut[9]="Ctrl_2Jets_0BJet_lt10MET_OffZ";
  namecut[10]="Ctrl_2Jets_0BJet_lt10MET_looseSel_OffZ";
  namecut[11]="Ctrl_2Jets_0BJet_lt40MET_OffZ";
  namecut[12]="Ctrl_2Jets_0BJet_lt40MET_looseSel_OffZ";
  namecut[13]="Ctrl_2Jets_OnZ";
  namecut[14]="Ctrl_2Jets_PhiSmall_OnZ";
  namecut[15]="Ctrl_2Jets_PhiMiddle_OnZ";
  namecut[16]="Ctrl_2Jets_PhiLarge_OnZ";
  namecut[17]="1btag_looseSel";//UNBLINDED
  
  namecut[18]="Ctrl_METgt60_0BJet";
  namecut[19]="Ctrl_METgt60_0BJet_looseSel";
  namecut[20]="Ctrl_METgt40_0BJet";
  namecut[21]="Ctrl_METgt40_0BJet_looseSel";
  namecut[22]="Ctrl_METgt40_0BJet_OffZ";
  namecut[23]="Ctrl_METgt40_0BJet_OffZ_looseSel";

  TString titlenamech[3];
  titlenamech[0]="#mu#mu";
  titlenamech[1]="ee";
  titlenamech[2]="e#mu";
  
  for(int j=0; j<NUM_CUTS; j++){
    for(int i=0; i<3; i++){
      hPV[j][i]         = new TH1F("hPV_"+namech[i]+"_"+namecut[j],"PV Distribution  " + titlenamech[i],50,0,50);
      
      //hMET[j][i]        = new TH1F("hMET_"+namech[i]+"_"+namecut[j],"MET " + titlenamech[i],80,0,400);
      hMET[j][i]        = new TH1F("hMET_"+namech[i]+"_"+namecut[j],"MET " + titlenamech[i],30,0,300);
      hMET_Phi[j][i]    = new TH1F("hMET_Phi_"+namech[i]+"_"+namecut[j],"#Phi_{MET} " + titlenamech[i],160,-4,4);
      hMETSig[j][i]     = new TH1F("hMETSig_"+namech[i]+"_"+namecut[j],"MET Significance " + titlenamech[i],50,0,200);
      
      if(j==0) hInvMass[j][i]    = new TH1F("hInvMass_"+namech[i]+"_"+namecut[j],"Invariant Mass " + titlenamech[i],60,0.0,300.0);
      else hInvMass[j][i]    = new TH1F("hInvMass_"+namech[i]+"_"+namecut[j],"Invariant Mass " + titlenamech[i],60,6.0,300.0);
      hDiLepPt[j][i]    = new TH1F("hDiLepPt_"+namech[i]+"_"+namecut[j],"Dilepton P_{T} " + titlenamech[i],50,0,300);
      hLep0Pt[j][i]     = new TH1F("hLep0Pt_"+namech[i]+"_"+namecut[j],"Pt^{Lep0} " + titlenamech[i],50,0.0,300.0);
      hLep1Pt[j][i]     = new TH1F("hLep1Pt_"+namech[i]+"_"+namecut[j],"Pt^{Lep1} " + titlenamech[i],50,0.0,300.0);
      hLep0Eta[j][i]    = new TH1F("hLep0Eta_"+namech[i]+"_"+namecut[j],"#eta_{Lep0} " + titlenamech[i],160,-8,8);
      hLep1Eta[j][i]    = new TH1F("hLep1Eta_"+namech[i]+"_"+namecut[j],"#eta_{Lep1} " + titlenamech[i],160,-8,8);
      hLep0RelIso[j][i]    = new TH1F("hLep0RelIso_"+namech[i]+"_"+namecut[j],"RelIso_{Lep0} " + titlenamech[i],2000,0,10);
      hLep1RelIso[j][i]    = new TH1F("hLep1RelIso_"+namech[i]+"_"+namecut[j],"RelIso_{Lep1} " + titlenamech[i],2000,0,10);
      
      hNJets[j][i]      = new TH1F("hNJets_"+namech[i]+"_"+namecut[j],"Jet Multiplicity " + titlenamech[i],5,-0.5,4.5);
      hNJets[j][i]->GetXaxis()->SetBinLabel(1,"0");
      hNJets[j][i]->GetXaxis()->SetBinLabel(2,"1");
      hNJets[j][i]->GetXaxis()->SetBinLabel(3,"2");
      hNJets[j][i]->GetXaxis()->SetBinLabel(4,"3");
      hNJets[j][i]->GetXaxis()->SetBinLabel(5,"#geq 4");

      hNBtagJets5[j][i]  = new TH1F("hNBtagJets5_"+namech[i]+"_"+namecut[j],"Btag Jet Multiplicity " + titlenamech[i],5,-0.5,4.5);
      hNBtagJets5[j][i]->GetXaxis()->SetBinLabel(1,"0");
      hNBtagJets5[j][i]->GetXaxis()->SetBinLabel(2,"1");
      hNBtagJets5[j][i]->GetXaxis()->SetBinLabel(3,"2");
      hNBtagJets5[j][i]->GetXaxis()->SetBinLabel(4,"3");
      hNBtagJets5[j][i]->GetXaxis()->SetBinLabel(5,"#geq 4");

      hNBtagJets[j][i]  = new TH1F("hNBtagJets_"+namech[i]+"_"+namecut[j],"Btag Jet Multiplicity " + titlenamech[i],4,-0.5,3.5);
      hNBtagJets[j][i]->GetXaxis()->SetBinLabel(1,"0");
      hNBtagJets[j][i]->GetXaxis()->SetBinLabel(2,"1");
      hNBtagJets[j][i]->GetXaxis()->SetBinLabel(3,"2");
      hNBtagJets[j][i]->GetXaxis()->SetBinLabel(4,"#geq 3");


      hHT[j][i]         = new TH1F("hHT_"+namech[i]+"_"+namecut[j],"H_{T} " + titlenamech[i],300,0,600);
      hJet0Pt[j][i]     = new TH1F("hJet0Pt_"+namech[i]+"_"+namecut[j],"P_{t}^{Jet0} " + titlenamech[i],50,0,300);
      hJet1Pt[j][i]     = new TH1F("hJet1Pt_"+namech[i]+"_"+namecut[j],"P_{t}^{Jet1} " + titlenamech[i],50,0,300);
      hBtagJet0Pt[j][i] = new TH1F("hBtagJet0Pt_"+namech[i]+"_"+namecut[j],"P_{t}^{BtagJet0} " + titlenamech[i],50,0,300);
      
      /***************************
                 DY-DD
      ***************************/
      hDYIn[j][i]             = new TH1F("hDYIn_"+namech[i]+"_"+namecut[j],"DY In " + titlenamech[i],100,0,1000);    
      hDYOut[j][i]            = new TH1F("hDYOut_"+namech[i]+"_"+namecut[j],"DY Out " + titlenamech[i],100,0,1000);    

      hDY_NPV[j][i]         = new TH2F("hDY_vs_NPV_"+namech[i]+"_"+namecut[j],"DY vs NPV" + titlenamech[i],750,0.,750.,31,-0.5,30.5);    
      hDY_NJets[j][i]       = new TH2F("hDY_vs_NJets_"+namech[i]+"_"+namecut[j],"DY vs NJets" + titlenamech[i],750,0.,750.,5,-0.5,4.5);    

      /***************************
              Systematics
      ***************************/
      hSysVarJet0[j][i]       = new TH1F("hSysVarJet0_"+namech[i]+"_"+namecut[j],"Systematic Variation: Jet0 " + titlenamech[i],100,0.9,1.1);    
      hSysVarJet1[j][i]       = new TH1F("hSysVarJet1_"+namech[i]+"_"+namecut[j],"Systematic Variation: Jet1 " + titlenamech[i],100,0.9,1.1);    
      hSysVarBtagJet0[j][i]   = new TH1F("hSysVarBtagJet0_"+namech[i]+"_"+namecut[j],"Systematic Variation: BtagJet0 " + titlenamech[i],100,0.9,1.1);    
      
      hUncJet0[j][i]          = new TH1F("hUncJet0_"+namech[i]+"_"+namecut[j],"Jet0 Uncertainty " + titlenamech[i],100,0.0,0.1);    
      hUncJet1[j][i]          = new TH1F("hUncJet1_"+namech[i]+"_"+namecut[j],"Jet1 Uncertainty " + titlenamech[i],100,0.0,0.1);    
      hUncBtagJet0[j][i]      = new TH1F("hUncBtagJet0_"+namech[i]+"_"+namecut[j],"BtagJet0 Uncertainty " + titlenamech[i],100,0.0,0.1);

      hSysVarJet0Pt[j][i]     = new TH2F("hSysVarJet0Pt_"+namech[i]+"_"+namecut[j],"Systematic Variation Vs P_{t}^{Jet0} " + titlenamech[i],120,0.0,120.0,100,0.9,1.1);    
      hSysVarJet1Pt[j][i]     = new TH2F("hSysVarJet1Pt_"+namech[i]+"_"+namecut[j],"Systematic Variation Vs P_{t}^{Jet1} " + titlenamech[i],120,0.0,120.0,100,0.9,1.1);    
      hSysVarBtagJet0Pt[j][i] = new TH2F("hSysVarBtagJet0Pt_"+namech[i]+"_"+namecut[j],"Systematic Variation Vs P_{t}^{BtagJet0} " + titlenamech[i],120,0.0,120,100,0.9,1.1);    

      hUncJet0Pt[j][i]        = new TH2F("hUncJet0Pt_"+namech[i]+"_"+namecut[j],"Jet Uncertainty Vs P_{t}^{Jet0} " + titlenamech[i],120,0.0,120.0,100,0.0,0.1);    
      hUncJet1Pt[j][i]        = new TH2F("hUncJet1Pt_"+namech[i]+"_"+namecut[j],"Jet Uncertainty Vs P_{t}^{Jet1} " + titlenamech[i],120,0.0,120.0,100,0.0,0.1);    
      hUncBtagJet0Pt[j][i]    = new TH2F("hUncBtagJet0Pt_"+namech[i]+"_"+namecut[j],"Jet Uncertainty Vs P_{t}^{BtagJet0} " + titlenamech[i],120,0.0,120.0,100,0.0,0.1);    

      /***************************
              Stop-only
      ***************************/
      
      hDeltaPhiLep[j][i]      = new TH1F("hDeltaPhiLep_"+namech[i]+"_"+namecut[j],"#Delta#Phi_{Lep} " + titlenamech[i],70,-7,7);
      hDeltaEtaLep[j][i]      = new TH1F("hDeltaEtaLep_"+namech[i]+"_"+namecut[j],"#Delta#eta_{Lep} " + titlenamech[i],80,-8,8);
      hDeltaPhiLepMET[j][i]   = new TH1F("hDeltaPhiLepMET_" +namech[i]+"_"+namecut[j],"#Delta#Phi_{Lep}^{MET} "  + titlenamech[i],70,-7,7);
      hDeltaPhiLepBtag[j][i]  = new TH1F("hDeltaPhiLepBtag_"+namech[i]+"_"+namecut[j],"#Delta#Phi_{Lep}^{btag} " + titlenamech[i],70,-7,7);
      hDeltaPhiMETBtag[j][i]  = new TH1F("hDeltaPhiMETBtag_"+namech[i]+"_"+namecut[j],"#Delta#Phi_{MET}^{btag} " + titlenamech[i],70,-7,7);
      
      hInvMassLepBtag[j][i]   = new TH1F("hInvMassLepBtag_"+namech[i]+"_"+namecut[j],"Invariant Mass^{2} (Lep,Btag) " + titlenamech[i],200,-4000,4000);
      hInvTMassMETBtag[j][i]  = new TH1F("hInvTMassMETBtag_"+namech[i]+"_"+namecut[j],"Invariant Transverse Mass^{2} (MET,Btag) " + titlenamech[i],200,-4000,4000);
      
      hMT2ll[j][i]              = new TH1F("hMT2ll_"+namech[i]+"_"+namecut[j],"MT_{2}(ll) " + titlenamech[i],60,0,300);      
      hMT2lb[j][i]              = new TH1F("hMT2lb_"+namech[i]+"_"+namecut[j],"MT_{2}(lb) "   + titlenamech[i],60,0,300);

      //FG addition
      hMT2bb[j][i]              = new TH1F("hMT2bb_"+namech[i]+"_"+namecut[j],"MT_{2}(bb) "   + titlenamech[i],60,0,300);
      hMT2ll_MT2lb[j][i]        = new TH2F("hMT2ll_MT2lb_"+namech[i]+"_"+namecut[j],"MT_{2}(ll) vs MT_{2}(lb)  "+ titlenamech[i],60,0,300,60,0,300);
      hMT2ll_MT2bb[j][i]        = new TH2F("hMT2ll_MT2bb_"+namech[i]+"_"+namecut[j],"MT_{2}(ll) vs MT_{2}(bb)  "+ titlenamech[i],60,0,300,60,0,300);
      hMT2ll_MT2llbb[j][i]        = new TH2F("hMT2ll_MT2llbb_"+namech[i]+"_"+namecut[j],"MT_{2}(ll) vs MT_{2}(llbb)  "+ titlenamech[i],60,0,300,80,0,400);   
      
    }//for(i)
  }//for(j)

  TLorentzVector Lep0,Lep1;
  TLorentzVector Jet0,Jet1,BtagJet0,BtagJet1;
  //FG addition
  TLorentzVector LepPlusBtagJet00,LepPlusBtagJet01,LepPlusBtagJet10,LepPlusBtagJet11;

  float lumi = 19602.9; //5311.0; //5296.3; // ipb
  const float genStopMassMin = 295, genStopMassMax = 355, genDeltaM_stopChi0_Min = 195, genDeltaM_stopChi0_Max = 255; // add 5 GeV safety margin (deltaM = 10 GeV in the FineBin sample)

  //  300 < m_stop < 350;
  //  200 < deltaM(stop, chi0) < 250   // minimum is 180 GeV at generator level

  float Nevt_stop_oneMassPoint = 50000 * ( (genStopMassMax-genStopMassMin)/10. ) * ( (genDeltaM_stopChi0_Max-genDeltaM_stopChi0_Min)/10. );  // 50k evts per point x Npoints  

  TStopwatch sw;
  sw.Start(kTRUE);

  ///////////////////////////////////////
  // Please, IGNORE. Temporary solution //
  ///////////////////////////////////////
  TCanvas *mydummycanvas=new TCanvas();// 
  ///////////////////////////////////////
  
  /*******************
   SF Parametrization
  ******************/
  
  TH2F *hmuIDSF, *hmumuTriggerSF;
  TH2F *heIDSF, *heeTriggerSF;
  TH2F *hmueTriggerSF;  

  // Lepton SFs: ID and Iso w/ stat. + syst. Errors
  
  TFile *MuSF = TFile::Open("/gpfs/csic_users/fgior8/sTop/PAF/leptonSF/SF_Mu.root");
  if(!MuSF){
    std::cerr << "ERROR [MuonSF]: Could not open file " << MuSF << "!"  << std::endl;
  }
  TFile *ElSF = TFile::Open("/gpfs/csic_users/fgior8/sTop/PAF/leptonSF/SF_EG.root");
  if(!ElSF){
    std::cerr << "ERROR [ElectronSF]: Could not open file " << ElSF << "!"  << std::endl;
  }
  TFile *MuElSF = TFile::Open("/gpfs/csic_users/fgior8/sTop/PAF/leptonSF/trigger_SF_emu.root");
  if(!ElSF){
    std::cerr << "ERROR [MuonElectronSF]: Could not open file " << MuElSF << "!"  << std::endl;
  }

  //hmuIDSF = (TH2F*) MuSF->Get("GlobalSF")->Clone("muIDSF"); ////FG why this? FIXME
  hmuIDSF = (TH2F*) MuSF->Get("MuonSFtop12028")->Clone("muIDSF");  

  hmumuTriggerSF = (TH2F*) MuSF->Get("scalefactor_eta2d_with_syst")->Clone("mumuTriggerSF");
  if(!hmuIDSF || !hmumuTriggerSF){
    std::cerr << "ERROR [MuonSF]: Could not find histogram for SF reweighting" << std::endl;
  }

  heIDSF = (TH2F*) ElSF->Get("GlobalSF")->Clone("eIDSF");
  heeTriggerSF = (TH2F*) ElSF->Get("scalefactor_eta2d_with_syst")->Clone("eeTriggerSF");
  if(!heIDSF || !heeTriggerSF){
    std::cerr << "ERROR [ElectronSF]: Could not find histogram for SF reweighting" << std::endl;
  }
  hmueTriggerSF = (TH2F*) ElSF->Get("scalefactor_eta2d_with_syst")->Clone("mueTriggerSF");
  if(!hmueTriggerSF){
    std::cerr << "ERROR [MuonElectronSF]: Could not find histogram for SF reweighting" << std::endl;
  }

  Long64_t nEntries = theTree.GetEntries();
  
  for (Long64_t ievt=0; ievt<nEntries; ievt++) {
    
    if (ievt%100000 == 0) std::cout << "--- ... Processing event: " << ievt << std::endl;
    
    theTree.GetEntry(ievt);

    //std::cout<<Lep0Px<<" "<<Lep0isTight<<" "<<Lep0RelIso<<std::endl;

    //emu=2;mue=-2
    int channel=Type; // SF/bin
    if(Type==-2) Type=2;// Fill Histograms MuonElectron=ElectronMuon    
    
    //std::cout<<Lep0Px<<Lep0Py<<Lep0Pz<<Lep0E<<std::endl;
    //std::cout<<Lep1Px<<Lep1Py<<Lep1Pz<<Lep1E<<std::endl;

    Lep0.SetPxPyPzE(Lep0Px,Lep0Py,Lep0Pz,Lep0E);
    Lep1.SetPxPyPzE(Lep1Px,Lep1Py,Lep1Pz,Lep1E);

    float InvMass=(Lep0+Lep1).M();       
    //std::cout<<InvMass<<std::endl<<std::endl;

    Jet0.SetPxPyPzE(Jet0Px*SysVarJet0,Jet0Py*SysVarJet0,Jet0Pz,Jet0E);
    Jet1.SetPxPyPzE(Jet1Px*SysVarJet1,Jet1Py*SysVarJet1,Jet1Pz,Jet1E);
    
    BtagJet0.SetPxPyPzE(BtagJet0Px*SysVarBtagJet0,BtagJet0Py*SysVarBtagJet0,BtagJet0Pz,BtagJet0E);
    BtagJet1.SetPxPyPzE(BtagJet1Px*SysVarBtagJet1,BtagJet1Py*SysVarBtagJet1,BtagJet1Pz,BtagJet1E);

    bool ZVeto=false;
    if(InvMass<76. || InvMass>106.) ZVeto=true;


    /***************************
       Systematic Variations
    ***************************/

    //NJets=0;
    //NBtagJets=0;

    //if(Jet0.Pt()>30. && Jet1.Pt()>30. && BtagJet0.Pt()>30.) {
    //  NJets=2;
    //  NBtagJets=1;
    //}

    //*****************************************
    // SELECT THE SIGNAL MASS POINT (if signal)
    //*****************************************  

    if( (TGenStopMass0 > genStopMassMin && TGenStopMass0 < genStopMassMax && 
	 TGenStopMass1 > genStopMassMin && TGenStopMass1 < genStopMassMax && // Stop mass limits
	 (TGenStopMass0-TGenChi0Mass0) > genDeltaM_stopChi0_Min && (TGenStopMass0-TGenChi0Mass0) < genDeltaM_stopChi0_Max && 
	 (TGenStopMass1-TGenChi0Mass1) > genDeltaM_stopChi0_Min && (TGenStopMass1-TGenChi0Mass1) < genDeltaM_stopChi0_Max) || // Neutralino mass limits
	(TGenStopMass0 == -99. && TGenStopMass1 == -99. && 
	 TGenChi0Mass0 == -99. && TGenChi0Mass1 == -99.) ) { // Background or data
      
      //*****************************************
      // NORMALIZE STOP SIGNAL TO INTEGRATED LUMI
      //*****************************************    
      
      float stopWeight = 0.;      
      if (theTree.GetBranch("TGenStopMass0")){
	
	//float roundedStopMass = floor((TGenStopMass0+12.5)/25.)*25.; // assuming delta_Mstop = 25 GeV, this rounds the stop mass to the closest value divisible by 25
	float roundedStopMass = floor((TGenStopMass0+5.)/10.)*10.;     // assuming delta_Mstop = 10 GeV, this rounds the stop mass to the closest value divisible by 10
	StopXSec theStopXSec = getCrossSectionStop(roundedStopMass);
	stopWeight = theStopXSec.stopProdXsec * lumi / Nevt_stop_oneMassPoint; //equivalent to G_Event_Weight= dm->GetCrossSection()* G_Event_Lumi/ dm->GetEventsInTheSample();
      }  
      
      if(theTree.GetBranch("TGenStopMass0"))
	PUWeight *= stopWeight;       

      //FG addition
      float MT2ll=getMT2(Lep0, Lep1, MET, MET_Phi);
      float MT2lb=getMT2(Lep0, BtagJet0, MET, MET_Phi);
      float MT2bb, MT2llbb00, MT2llbb01, MT2llbb;
      if(NBtagJets>1)
	MT2bb=getMT2(BtagJet0, BtagJet1, MET+(Lep0+Lep1).Pt(), MET_Phi+(Lep0+Lep1).Phi());
      else
	MT2bb=0;//getMT2(BtagJet0, Jet0, MET, MET_Phi);
      LepPlusBtagJet00 = Lep0 + BtagJet0;
      LepPlusBtagJet10 = Lep1 + BtagJet0;
      if (NBtagJets>1) {
	LepPlusBtagJet11 = Lep1 + BtagJet1;
        LepPlusBtagJet01 = Lep0 + BtagJet1;
        if (LepPlusBtagJet11.M()<173 && LepPlusBtagJet00.M()<173 && (LepPlusBtagJet10.M()>173 || LepPlusBtagJet01.M()>173))
	  MT2llbb=getMT2(LepPlusBtagJet00, LepPlusBtagJet11, MET, MET_Phi);
	else if ((LepPlusBtagJet11.M()>173 || LepPlusBtagJet00.M()>173) && LepPlusBtagJet10.M()<173 && LepPlusBtagJet01.M()<173)
          MT2llbb=getMT2(LepPlusBtagJet01, LepPlusBtagJet10, MET, MET_Phi);
        else if (LepPlusBtagJet11.M()<173 && LepPlusBtagJet00.M()<173 && LepPlusBtagJet10.M()<173 && LepPlusBtagJet01.M()<173) {
          if ( fabs(LepPlusBtagJet11.M()-LepPlusBtagJet00.M()) < fabs(LepPlusBtagJet10.M()-LepPlusBtagJet01.M()) )
            MT2llbb=getMT2(LepPlusBtagJet00, LepPlusBtagJet11, MET, MET_Phi);
          else
            MT2llbb=getMT2(LepPlusBtagJet01, LepPlusBtagJet10, MET, MET_Phi);
	}
	else
	  MT2llbb=0;
      }
      else
        MT2llbb=0;

      Double_t lep0isothreshold;
      Double_t lep1isothreshold;

      if(     channel== 0) { lep0isothreshold = muiso; lep1isothreshold = muiso; } // mm
      else if(channel==-2) { lep0isothreshold = muiso; lep1isothreshold = eliso; } // me
      else if(channel== 2) { lep0isothreshold = eliso; lep1isothreshold = muiso; } // em
      else if(channel== 1) { lep0isothreshold = eliso; lep1isothreshold = eliso; }  // ee
      else { std::cout<<"HUGE ERROR"<<std::endl; return -1; }

      bool passloose;
      if(Lep0RelIso > lep0isothreshold || Lep1RelIso > lep1isothreshold)
	{
          passloose = false;
	}
      else passloose = true;

      //if( fname.Contains("Data") && MT2ll>80. )	continue;  // FIXME!!! blinding policy, only for stop. Uncomment for ttbar
     
      /***************************
      DY Data Driven: Rout/in
      ***************************/
      // DY/bin
      //int DYbin=0;
      
      //if(fname.Contains("Data") || fname.Contains("ZDY"))
      if(fname.Contains("Data") || fname.Contains("ZDY") || fname.Contains("AllMC")){
	
	int cut=-1; // Dilepton
	//DKK
	//std::cout<<"NJets "<<NJets<<std::endl;	
        if(Lep0isTight && Lep1isTight /*&& MT2ll < 80*/)                                       cut=0;
	if(Lep0isTight && Lep1isTight && MT2ll < 80 && NJets>1)                            cut=1; // 2 Jets
	if(Lep0isTight && Lep1isTight && MT2ll < 80 && NJets>1 && MET>40.0)                cut=2; // + MET
	if(Lep0isTight && Lep1isTight && /*MT2ll < 80 &&*/ NJets>1 && MET>40.0 && NBtagJets>1) cut=3; // + 1 Btag
	if(Lep0isTight && Lep1isTight && MT2ll < 80 && NJets>1 && MET>40.0 && NBtagJets>0) cut=4; // + 1 Btag
	
	//(DY_DD_mumu & DY_DD_ee)/bin
	// if(NJets>1 && NBtagJets==DYbin)                            cut=1; // 2 Jets
	// if(NJets>1 && MET>40.0 && NBtagJets==DYbin)                cut=2; // + MET
	// if(NJets>1 && MET>40.0 && NBtagJets==DYbin)                cut=3; // + 1 Btag
	//std::cout<<"Made it here and cut is "<<cut<<std::endl;	
	for(int icut=0; icut<cut+1; icut++){
	  if(icut == 0)            hDY_NPV[icut][Type]  ->Fill(InvMass,PV,PUWeight);
	  if(icut == 0 && MET<10 ) hDY_NJets[icut][Type]->Fill(InvMass,NJets,PUWeight);
	  
	  if(ZVeto) hDYOut[icut][Type]->Fill(InvMass,PUWeight);
	  else      hDYIn[icut][Type] ->Fill(InvMass,PUWeight);
	}

// 	std::vector<int> fillindex;

// 	//CONTROLREGION
// 	if(passloose && MT2ll < 80. && NJets>1 && MET>40.0 && NBtagJets>0 && MT2ll < 80.) { fillindex.push_back(5); }
// 	if(passloose && MT2ll < 80. && NJets>1 ) { fillindex.push_back(6); }
// 	if(Lep0isTight && Lep1isTight && MT2ll < 80. && NJets==1 && NBtagJets == 0 && MET < 10) { fillindex.push_back(7); }
// 	if(passloose && MT2ll < 80. && NJets==1 && NBtagJets == 0 && MET < 10) { fillindex.push_back(8); }
// 	if(Lep0isTight && Lep1isTight && MT2ll < 80. && NJets>1 && NBtagJets == 0 && MET < 10 /*&& (ZVeto || Type==2)*/) { fillindex.push_back(9); }
// 	if(passloose && MT2ll < 80. && NJets>1 && NBtagJets == 0 && MET < 10 /*&& (ZVeto || Type==2)*/) { fillindex.push_back(10); }
// 	if(Lep0isTight && Lep1isTight && MT2ll < 80. && NJets>1 && NBtagJets == 0 && MET < 40 /*&& (ZVeto || Type==2)*/) { fillindex.push_back(11); }
// 	if(passloose && MT2ll < 80. && NJets>1 && NBtagJets == 0 && MET < 40 /*&& (ZVeto || Type==2)*/) { fillindex.push_back(12); }
      
// 	if(Lep0isTight && Lep1isTight && NJets==1 && /*!ZVeto &&*/ fabs(MET_Phi) > 1.0471975512 && fabs(MET_Phi) < 2.09439510239) { fillindex.push_back(13); }
// 	if(passloose && NJets==1 && /*!ZVeto &&*/ fabs(MET_Phi) > 1.0471975512 && fabs(MET_Phi) < 2.09439510239) { fillindex.push_back(14); }
// 	if(Lep0isTight && Lep1isTight && NJets>1 && /*!ZVeto &&*/ fabs(MET_Phi) > 1.0471975512 && fabs(MET_Phi) < 2.09439510239) { fillindex.push_back(15); }
// 	if(passloose && NJets>1 && /*!ZVeto &&*/ fabs(MET_Phi) > 1.0471975512 && fabs(MET_Phi) < 2.09439510239) { fillindex.push_back(16); }
// 	if(passloose && /*MT2ll < 80 &&*/ NJets>1 && MET>40.0 && NBtagJets>0) { fillindex.push_back(17); }
// 	if(Lep0isTight && Lep1isTight && MET > 60 && NBtagJets == 0 ) { fillindex.push_back(18);}
// 	if(passloose && MET > 60 && NBtagJets == 0 ) { fillindex.push_back(19);}
// 	if(Lep0isTight && Lep1isTight && MET > 40 && NBtagJets == 0 ) { fillindex.push_back(20);}
// 	if(passloose && MET > 40 && NBtagJets == 0 ) { fillindex.push_back(21);}
// 	if(Lep0isTight && Lep1isTight && MET > 40 && NBtagJets == 0 /*&& (ZVeto || Type==2 || Type==-2)*/ ) { fillindex.push_back(22);}
// 	if(passloose && MET > 40 && NBtagJets == 0 /*&& (ZVeto || Type==2 || Type==-2)*/ ) { fillindex.push_back(23);}
      
// 	for(int m = 0; m < fillindex.size(); m++) {
// 	  int icut = fillindex[m];
//           if(icut == 0)            hDY_NPV[icut][Type]  ->Fill(InvMass,PV,PUWeight);
//           if(icut == 0 && MET<10 ) hDY_NJets[icut][Type]->Fill(InvMass,NJets,PUWeight);

//           if(ZVeto) hDYOut[icut][Type]->Fill(InvMass,PUWeight);
//           else      hDYIn[icut][Type] ->Fill(InvMass,PUWeight);

// 	}
	
      }
      
      /***************************
               Selection
      ***************************/
     
      ///////////////////////
      int cut=-1;

      //      std::cout<<Lep0isTight<<" "<<Lep1isTight<<" "<<MT2ll<<std::endl;

      if(Lep0isTight && Lep1isTight /*&& MT2ll < 80.*/) 								    cut=0; 
      if(Lep0isTight && Lep1isTight && MT2ll < 80. && NJets>1 && (Type==2 || ZVeto))                              cut=1; // 2Jets and ZVeto 
      if(Lep0isTight && Lep1isTight && MT2ll < 80. && NJets>1 && (Type==2 || (MET>40.0 && ZVeto)))                cut=2; // + MET
      if(Lep0isTight && Lep1isTight && /*MT2ll < 80. &&*/ NJets>1 && (Type==2 || (MET>40.0 && ZVeto)) && NBtagJets>1) cut=3; // + 1 Btag
      if(Lep0isTight && Lep1isTight && MT2ll < 80. && NJets>1 && (Type==2 || (MET>40.0 && ZVeto)) && NBtagJets>0) cut=4; // + MT2ll < 80 GeV (blinding policy)
      /////////////////////////

      /*ORIGINAL int cut=0; // Dilepton
      
      if(NJets>1 && (Type==2 || ZVeto))                              cut=1; // 2Jets and ZVeto 
      if(NJets>1 && (Type==2 || (MET>40.0 && ZVeto)))                cut=2; // + MET
      if(NJets>1 && (Type==2 || (MET>40.0 && ZVeto)) && NBtagJets>0) cut=3; // + 1 Btag
      if(NJets>1 && (Type==2 || (MET>40.0 && ZVeto)) && NBtagJets>0 && MT2ll < 80.) cut=4; // + MT2ll < 80 GeV (blinding policy)*/
      
      //DY_DD_mue/bin
      // if(NJets>1 && (Type==2 || ZVeto) && NBtagJets==DYbin)                              cut=1; // 2Jets and ZVeto 
      // if(NJets>1 && (Type==2 || (MET>40.0 && ZVeto)) && NBtagJets==DYbin)                cut=2; // MET
      // if(NJets>1 && (Type==2 || (MET>40.0 && ZVeto)) && NBtagJets==DYbin)                cut=3; // 1 Btag

      float bbPt=(BtagJet0+BtagJet1).Pt();
      float DiLepPt=(Lep0+Lep1).Pt();  

      float DeltaPhiLep=Lep0.DeltaPhi(Lep1);
      float DeltaEtaLep=Lep0.Eta()-Lep1.Eta();
    
      float DeltaPhiLepMET =Lep0.Phi()-MET_Phi;
      float DeltaPhiLepBtag=Lep0.DeltaPhi(BtagJet0);
      float DeltaPhiMETBtag=MET_Phi-BtagJet0.Phi();
    
      float InvMassLepBtag=((Lep0.Et()+BtagJet0.Et())*(Lep0.Et()+BtagJet0.Et())
			    -(Lep0.Pt()+BtagJet0.Pt())*(Lep0.Pt()+BtagJet0.Pt()));
      float InvMassMETBtag=((MET+BtagJet0.Et())*(MET+BtagJet0.Et())
			    -(MET+BtagJet0.Pt())*(MET+BtagJet0.Pt()));
    
      /***************************
         SF: ID, ISO and Trigger
      ***************************/
      
      float SF_ID_ISO_Tr=1.0;        
      
      if (!fname.Contains("Data")) {
	
	int NbinmuEta=6;
	int NbinmuPt =4;
	float VbinmuEta[7]={-2.4 , -1.2 , -0.9 , 0.0 , 0.9 , 1.2 , 2.4}; // muon Eta values
	float VbinmuPt[5] ={20 , 30 , 40 , 60 , 1000}; // muon Pt values
	
	int NbineEta=10;
	int NbinePt =4;
	float VbineEta[11]={-2.5 , -2.0 , -1.556 , -1.442 , -0.8 , 0.0 , 0.8 , 1.442 , 1.556 , 2.0 , 2.5}; // electron Eta values
	float VbinePt[5] ={20 , 30 , 40 , 50 , 1000}; // electron Pt values
	
	float SFLep0[2]={0.0 , 0.0};// [0]=muon && [1]=electron 
	float SFLep1[2]={1.0 , 1.0};   // FIXME!!! it was {0.0, 0.0} // useful for stop, because (pT1, pT2) > (20, 10) GeV // look below for SFLep1
	float SFErrorLep0[2]={0.0 , 0.0};// [0]=muon && [1]=electron 
	float SFErrorLep1[2]={0.0 , 0.0};
	
	/***************************
               Lepton 0: muon 
	***************************/
	
	for(int binmuPt=0;binmuPt<NbinmuPt;binmuPt++){
	  if(Lep0.Pt()>VbinmuPt[binmuPt] && Lep0.Pt()<=VbinmuPt[binmuPt+1]){ 
	    
	    for(int binmuEta=0;binmuEta<NbinmuEta;binmuEta++){
	      if(Lep0.Eta()>VbinmuEta[binmuEta] && Lep0.Eta()<=VbinmuEta[binmuEta+1]){ 
		SFLep0[0]=hmuIDSF->GetBinContent(binmuEta+1,binmuPt+1);
		SFErrorLep0[0]=hmuIDSF->GetBinError(binmuEta+1,binmuPt+1);
		break;
	      }// if(Lep0.Eta())
	    }// for(binmuEta)
	    
	  }// if(Lep0.Pt())
	}// for(binmuPt)
      
	/***************************
            Lepton 0: electron
	***************************/
	
	for(int binePt=0;binePt<NbinePt;binePt++){
	  if(Lep0.Pt()>VbinePt[binePt] && Lep0.Pt()<=VbinePt[binePt+1]){ 
	    
	    for(int bineEta=0;bineEta<NbineEta;bineEta++){
	      if(Lep0.Eta()>VbineEta[bineEta] && Lep0.Eta()<=VbineEta[bineEta+1]){ 
		SFLep0[1]=heIDSF->GetBinContent(bineEta+1,binePt+1);
		SFErrorLep0[1]=heIDSF->GetBinError(bineEta+1,binePt+1);
		break;
	      }// if(Lep0.Eta())
	    }// for(bineEta)
	    
	  }// if(Lep0.Pt())
	}// for(binePt)
	
	
	/***************************
              Lepton 1: muon 
	***************************/

	for(int binmuPt=0;binmuPt<NbinmuPt;binmuPt++){
	  
	  //if(Lep1.Pt()>10. && Lep1.Pt()<=20.) binmuPt=0;   // FIXME!!! Alberto 12mar2013 //added // if 10<pTlep1<20, use the SFs used for pT=20 GeV
	  
	  //if( (Lep1.Pt()>10. && Lep1.Pt()<=20.) || (Lep1.Pt()>VbinmuPt[binmuPt] && Lep1.Pt()<=VbinmuPt[binmuPt+1])   ) // FIXME!!! it was...
	  
	  if(Lep1.Pt()>VbinmuPt[binmuPt] && Lep1.Pt()<=VbinmuPt[binmuPt+1]){     // ...like this
	    
	    for(int binmuEta=0;binmuEta<NbinmuEta;binmuEta++){
	      if(Lep1.Eta()>VbinmuEta[binmuEta] && Lep1.Eta()<=VbinmuEta[binmuEta+1]){ 
		SFLep1[0]=hmuIDSF->GetBinContent(binmuEta+1,binmuPt+1);
		SFErrorLep1[0]=hmuIDSF->GetBinError(binmuEta+1,binmuPt+1);
		break;
	      }// if(Lep1.Eta())
	    }// for(binmuEta)
	    
	  }// if(Lep1.Pt())
	}// for(binmuPt)
	
	/***************************
             Lepton 1: electron 
	***************************/

	for(int binePt=0;binePt<NbinePt;binePt++){
	  
	  //if(Lep1.Pt()>10. && Lep1.Pt()<=20.) binePt=0;  // FIXME!!! Alberto 12mar2013 //added  // if 10<pTlep1<20, use the SFs used for pT=20 GeV
	  
	  //if( (Lep1.Pt()>10. && Lep1.Pt()<=20.) ||  (Lep1.Pt()>VbinePt[binePt] && Lep1.Pt()<=VbinePt[binePt+1]) )  // FIXME!!! it was...
	  
	  if(Lep1.Pt()>VbinePt[binePt] && Lep1.Pt()<=VbinePt[binePt+1]){  // ...like this
	    for(int bineEta=0;bineEta<NbineEta;bineEta++){
	      if(Lep1.Eta()>VbineEta[bineEta] && Lep1.Eta()<=VbineEta[bineEta+1]){ 
		SFLep1[1]=heIDSF->GetBinContent(bineEta+1,binePt+1);
		SFErrorLep1[1]=heIDSF->GetBinError(bineEta+1,binePt+1);
		break;
	      }// if(Lep1.Eta())
	    }// for(bineEta)
	    
	  }// if(Lep1.Pt())
	}// for(binePt)
	
	
	float VbinTrmumuEta[5]={0.0 , 0.9 , 1.2 , 2.1 , 2.4};
	float VbinTreeEta[3]  ={0.0 , 1.479 , 2.5};
	float VbinXTrmueEta[3]={0.0 , 1.479 , 2.5};
	float VbinYTrmueEta[3]={0.0 , 0.9 , 2.4};
	
	int NXTrmumubinEta=4;
	int NYTrmumubinEta=4;
	
	int NXTreebinEta=2;
	int NYTreebinEta=2;
	
	int NXTrmuebinEta=2;
	int NYTrmuebinEta=2;
	
	float SFTrmumu=0.0;
	float SFTree=0.0;
	float SFTrmue=0.0;
	float SFTremu=0.0;
	
	float SFErrorTrmumu=0.0;
	float SFErrorTree=0.0;
	float SFErrorTrmue=0.0;
	float SFErrorTremu=0.0;
	
	//////////////////
	// Trigger mumu //
	//////////////////
      
	for(int binXTrEta=0;binXTrEta<NXTrmumubinEta;binXTrEta++){
	  if(fabs(Lep0.Eta())>VbinTrmumuEta[binXTrEta] && fabs(Lep0.Eta())<=VbinTrmumuEta[binXTrEta+1]){ 
	    
	    for(int binYTrEta=0;binYTrEta<NYTrmumubinEta;binYTrEta++){
	      if(fabs(Lep1.Eta())>VbinTrmumuEta[binYTrEta] && fabs(Lep1.Eta())<=VbinTrmumuEta[binYTrEta+1]){ 
		
		SFTrmumu=hmumuTriggerSF->GetBinContent(binXTrEta+1,binYTrEta+1);
		SFErrorTrmumu=hmumuTriggerSF->GetBinError(binXTrEta+1,binYTrEta+1);
		break;
		
	      }// if(Lep1.Eta())
	    }// for(binYTrEta)
	    
	  }// if(Lep0.Eta())
	}// for(binXTrEta)
	
	
	/////////////////
	// Trigger ee //
	/////////////////
	
	for(int binXTrEta=0;binXTrEta<NXTreebinEta;binXTrEta++){
	  if(fabs(Lep0.Eta())>VbinTreeEta[binXTrEta] && fabs(Lep0.Eta())<=VbinTreeEta[binXTrEta+1]){ 
	    
	    for(int binYTrEta=0;binYTrEta<NYTreebinEta;binYTrEta++){
	      if(fabs(Lep1.Eta())>VbinTreeEta[binYTrEta] && fabs(Lep1.Eta())<=VbinTreeEta[binYTrEta+1]){ 
		
		SFTree=heeTriggerSF->GetBinContent(binXTrEta+1,binYTrEta+1);
		SFErrorTree=heeTriggerSF->GetBinError(binXTrEta+1,binYTrEta+1);
		break;
		
	      }// if(Lep1.Eta())
	    }// for(binYTrEta)
	    
	  }// if(Lep0.Eta())
	}// for(binXTrEta)
	
	/////////////////
	// Trigger emu //
	/////////////////
	
	for(int binXTrEta=0;binXTrEta<NXTrmuebinEta;binXTrEta++){
	  if(fabs(Lep0.Eta())>VbinXTrmueEta[binXTrEta] && fabs(Lep0.Eta())<=VbinXTrmueEta[binXTrEta+1]){ 
	    
	    for(int binYTrEta=0;binYTrEta<NYTreebinEta;binYTrEta++){
	      if(fabs(Lep1.Eta())>VbinYTrmueEta[binYTrEta] && fabs(Lep1.Eta())<=VbinYTrmueEta[binYTrEta+1]){ 
		
		SFTremu=hmueTriggerSF->GetBinContent(binXTrEta+1,binYTrEta+1);
		SFErrorTremu=hmueTriggerSF->GetBinError(binXTrEta+1,binYTrEta+1);
		break;
		
	      }// if(Lep1.Eta())
	    }// for(binYTrEta)
	    
	  }// if(Lep0.Eta())
	}// for(binXTrEta)
	
	/////////////////
	// Trigger mue //
	/////////////////
	
	for(int binXTrEta=0;binXTrEta<NXTrmuebinEta;binXTrEta++){
	  if(fabs(Lep1.Eta())>VbinXTrmueEta[binXTrEta] && fabs(Lep1.Eta())<=VbinXTrmueEta[binXTrEta+1]){ 
	    
	    for(int binYTrEta=0;binYTrEta<NYTreebinEta;binYTrEta++){
	      if(fabs(Lep0.Eta())>VbinYTrmueEta[binYTrEta] && fabs(Lep0.Eta())<=VbinYTrmueEta[binYTrEta+1]){ 
		
		SFTrmue=hmueTriggerSF->GetBinContent(binXTrEta+1,binYTrEta+1);
		SFErrorTrmue=hmueTriggerSF->GetBinError(binXTrEta+1,binYTrEta+1);
		break;
		
	      }// if(Lep0.Eta())
	    }// for(binYTrEta)
	    
	  }// if(Lep1.Eta())
	}// for(binXTrEta)
	
	
	
	
	//emu=2;mue=-2
	if(channel==0)  SF_ID_ISO_Tr=SFLep0[0]*SFLep1[0]*SFTrmumu;// mumu
	if(channel==1)  SF_ID_ISO_Tr=SFLep0[1]*SFLep1[1]*SFTree;  // ee
	if(channel==2)  SF_ID_ISO_Tr=SFLep0[1]*SFLep1[0]*SFTremu; // emu
	if(channel==-2) SF_ID_ISO_Tr=SFLep0[0]*SFLep1[1]*SFTrmue; // mue
	//SF: Systematic Errors
	// if(channel==0)  SF_ID_ISO_Tr=(SFLep0[0]*SFLep1[0]-2.0*SFLep0[0]*SFLep1[0]*0.01)*(SFTrmumu-SFErrorTrmumu);// mumu
	// if(channel==1)  SF_ID_ISO_Tr=(SFLep0[1]*SFLep1[1]-2.0*SFLep0[1]*SFLep1[1]*0.01)*(SFTree-SFErrorTree);    // ee
	// if(channel==2)  SF_ID_ISO_Tr=(SFLep0[1]*SFLep1[0]-sqrt(2.0)*SFLep0[1]*SFLep1[0]*0.01)*(SFTremu-SFErrorTremu);  // emu
	// if(channel==-2) SF_ID_ISO_Tr=(SFLep0[0]*SFLep1[1]-sqrt(2.0)*SFLep0[0]*SFLep1[1]*0.01)*(SFTrmue-SFErrorTrmue);  // mue
	
	// std::cout << "-----------------------------------" << std::endl;      
	// std::cout << "channel=" << channel << std::endl;      
	// std::cout << "Pt Lep0=" << Lep0.Pt() << std::endl;      
	// std::cout << "Pt Lep1=" << Lep1.Pt() << std::endl;      
	// std::cout << "Eta Lep0=" << Lep0.Eta() << std::endl;      
	// std::cout << "Eta Lep1=" << Lep1.Eta() << std::endl;      
	// std::cout << "SF_ID_ISO Lep0[0]=" << SFLep0[0] << std::endl;      
	// std::cout << "SF_ID_ISO Lep0[1]=" << SFLep0[1] << std::endl;      
	// std::cout << "SF_ID_ISO Lep1[0]=" << SFLep1[0] << std::endl;      
	// std::cout << "SF_ID_ISO Lep1[1]=" << SFLep1[1] << std::endl;      
	// std::cout << "SF_Trigger mumu=" << SFTrmumu << std::endl;      
	// std::cout << "SF_Trigger ee=" << SFTree << std::endl;      
	// std::cout << "SF_Trigger mue=" << SFTrmue << std::endl;      
	// std::cout << "SF_Trigger emu=" << SFTremu << std::endl;      
	// std::cout << "SF_ID_ISO_Trigger=" << SF_ID_ISO_Tr << std::endl;      
	
      }// if(!Contain("Data"))

      /**************************
        Scale Factors/bin(Pt,Eta)
      ***************************/
     
      PUWeight=PUWeight*SF_ID_ISO_Tr; 
      
      /*******************
        Fill Histograms
      ******************/
      for(int icut=0; icut<cut+1; icut++){
	hPV[icut][Type]->Fill(PV,PUWeight);
	
	hMET[icut][Type]->Fill(MET,PUWeight);
	hMET_Phi[icut][Type]->Fill(MET_Phi,PUWeight);
	hMETSig[icut][Type]->Fill(METSig,PUWeight);
	
	hInvMass[icut][Type]->Fill(InvMass,PUWeight);
	hDiLepPt[icut][Type]->Fill(DiLepPt,PUWeight);
	hLep0Pt[icut][Type]->Fill(Lep0.Pt(),PUWeight);
	hLep1Pt[icut][Type]->Fill(Lep1.Pt(),PUWeight);
	hLep0Eta[icut][Type]->Fill(Lep0.Eta(),PUWeight);
	hLep1Eta[icut][Type]->Fill(Lep1.Eta(),PUWeight);
	hLep0RelIso[icut][Type]->Fill(Lep0RelIso,PUWeight);
	hLep1RelIso[icut][Type]->Fill(Lep1RelIso,PUWeight);
	
	if(NJets>4) hNJets[icut][Type]->Fill(4,PUWeight);
	else hNJets[icut][Type]->Fill(NJets,PUWeight); 
	
	if(NBtagJets>4) hNBtagJets5[icut][Type]->Fill(4,PUWeight);
	else hNBtagJets5[icut][Type]->Fill(NBtagJets,PUWeight);
	
	if(NBtagJets>3) hNBtagJets[icut][Type]->Fill(3,PUWeight);
	else hNBtagJets[icut][Type]->Fill(NBtagJets,PUWeight);
	
	hHT[icut][Type]->Fill(HT,PUWeight);
	hJet0Pt[icut][Type]->Fill(Jet0.Pt(),PUWeight);
	hJet1Pt[icut][Type]->Fill(Jet1.Pt(),PUWeight);
	hBtagJet0Pt[icut][Type]->Fill(BtagJet0.Pt(),PUWeight);

	hDeltaPhiLep[icut][Type]->Fill(DeltaPhiLep,PUWeight);
	hDeltaEtaLep[icut][Type]->Fill(DeltaEtaLep,PUWeight);
	hDeltaPhiLepMET[icut][Type] ->Fill(DeltaPhiLepMET, PUWeight);
	hDeltaPhiLepBtag[icut][Type]->Fill(DeltaPhiLepBtag,PUWeight);
	hDeltaPhiMETBtag[icut][Type]->Fill(DeltaPhiMETBtag,PUWeight);
       
	hInvMassLepBtag[icut][Type]->Fill(InvMassLepBtag,PUWeight);
	hInvTMassMETBtag[icut][Type]->Fill(InvMassMETBtag,PUWeight);

        //if (!fname.Contains("Data") || (fname.Contains("Data") && MT2ll<80) )
	hMT2ll[icut][Type]->Fill(MT2ll,PUWeight);
	hMT2lb[icut][Type]->Fill(MT2llbb,PUWeight);
        hMT2bb[icut][Type]->Fill(MT2bb,PUWeight);
	//FG addition
	if(MT2ll>-1) {
	  if(MT2lb>-1)
	    hMT2ll_MT2lb[icut][Type]->Fill(MT2ll,MT2lb,PUWeight);
	  if(MT2bb>-1)
	    hMT2ll_MT2bb[icut][Type]->Fill(MT2ll,MT2bb,PUWeight);
	  if(MT2llbb>-1)
	    hMT2ll_MT2llbb[icut][Type]->Fill(MT2ll,MT2llbb,PUWeight);
	}

	
	/***************************
            Systematic Histograms
	***************************/
	hUncJet0[icut][Type]->Fill(UncJet0,PUWeight);
	hUncJet1[icut][Type]->Fill(UncJet1,PUWeight);
	hUncBtagJet0[icut][Type]->Fill(UncBtagJet0,PUWeight);
	
	hSysVarJet0[icut][Type]->Fill(SysVarJet0,PUWeight);
	hSysVarJet1[icut][Type]->Fill(SysVarJet1,PUWeight);
	hSysVarBtagJet0[icut][Type]->Fill(SysVarBtagJet0,PUWeight);
	
	hUncJet0Pt[icut][Type]->Fill(Jet0.Pt(),UncJet0);
	hUncJet1Pt[icut][Type]->Fill(Jet1.Pt(),UncJet1);
	hUncBtagJet0Pt[icut][Type]->Fill(BtagJet0.Pt(),UncBtagJet0);
	
	hSysVarJet0Pt[icut][Type]->Fill(Jet0.Pt(),SysVarJet0);
	hSysVarJet1Pt[icut][Type]->Fill(Jet1.Pt(),SysVarJet1);
	hSysVarBtagJet0Pt[icut][Type]->Fill(BtagJet0.Pt(),SysVarBtagJet0);
	
	
      }//for(icuts)    
      /*
	Double_t lep0isothreshold;
	Double_t lep1isothreshold;


	if(channel== 0) { lep0isothreshold = muiso; lep1isothreshold = muiso; } // mm
	else if(channel== 2) { lep0isothreshold = muiso; lep1isothreshold = eliso; } // me
	else if(channel==-2) { lep0isothreshold = eliso; lep1isothreshold = muiso; } // em
	else if(channel== 1) { lep0isothreshold = eliso; lep1isothreshold = eliso; }  // ee
	else { std::cout<<"HUGE ERROR"<<std::endl; return -1; }

	bool passloose;
	if(Lep0RelIso > lep0isothreshold || Lep1RelIso > lep1isothreshold)
	{
	passloose = false;
	}
	else passloose = true;*////moved above


      std::vector<int> fillindex;
      
      //CONTROLREGION 
      if(passloose && MT2ll < 80. && NJets>1 && (Type==2 || (MET>40.0 && ZVeto)) && NBtagJets>0 && MT2ll < 80.) { //The full selection except the leptons can be loose
	fillindex.push_back(5); }
      if(passloose && MT2ll < 80. && NJets>1 && (Type==2 || ZVeto)) fillindex.push_back(6);
      if(Lep0isTight && Lep1isTight && MT2ll < 80. && NJets==1 && NBtagJets == 0 && MET < 10) { fillindex.push_back(7); }
      if(passloose && MT2ll < 80. && NJets==1 && NBtagJets == 0 && MET < 10) { fillindex.push_back(8); }
      if(Lep0isTight && Lep1isTight && MT2ll < 80. && NJets>1 && NBtagJets == 0 && MET < 10 && (ZVeto || Type==2)) { fillindex.push_back(9); }
      if(passloose && MT2ll < 80. && NJets>1 && NBtagJets == 0 && MET < 10 && (ZVeto || Type==2) ) { fillindex.push_back(10); }
      if(Lep0isTight && Lep1isTight && MT2ll < 80. && NJets>1 && NBtagJets == 0 && MET < 40 && (ZVeto || Type==2)) { fillindex.push_back(11); }
      if(passloose && MT2ll < 80. && NJets>1 && NBtagJets == 0 && MET < 40 && (ZVeto || Type==2) ) { fillindex.push_back(12); }

      if(Lep0isTight && Lep1isTight && NJets>1 && !ZVeto && MET>40.0 /* && fabs(MET_Phi) > 1.0471975512 && fabs(MET_Phi) < 2.09439510239*/) { fillindex.push_back(13); }
      if(Lep0isTight && Lep1isTight && NJets>1 && !ZVeto && MET>40.0 && fabs((Lep0+Lep1).Phi()-MET_Phi) < 1.0471975512) { fillindex.push_back(14); }
      if(Lep0isTight && Lep1isTight && NJets>1 && !ZVeto && MET>40.0 && fabs((Lep0+Lep1).Phi()-MET_Phi) > 1.0471975512 && fabs((Lep0+Lep1).Phi()-MET_Phi) < 2.09439510239) { fillindex.push_back(15); }
      if(Lep0isTight && Lep1isTight && NJets>1 && !ZVeto && MET>40.0 && fabs((Lep0+Lep1).Phi()-MET_Phi) > 2.09439510239) { fillindex.push_back(16); }
      if(passloose && /*MT2ll < 80. &&*/ NJets>1 && (Type==2 || (MET>40.0 && ZVeto)) && NBtagJets>0) { fillindex.push_back(17); }
      
      if(Lep0isTight && Lep1isTight && MET > 60 && NBtagJets == 0 ) { fillindex.push_back(18);}
      if(passloose && MET > 60 && NBtagJets == 0 ) { fillindex.push_back(19);}
      if(Lep0isTight && Lep1isTight && MET > 40 && NBtagJets == 0 ) { fillindex.push_back(20);}
      if(passloose && MET > 40 && NBtagJets == 0 ) { fillindex.push_back(21);}
      if(Lep0isTight && Lep1isTight && MET > 40 && NBtagJets == 0 && (ZVeto || Type==2 || Type==-2) ) { fillindex.push_back(22);}
      if(passloose && MET > 40 && NBtagJets == 0 && (ZVeto || Type==2 || Type==-2) ) { fillindex.push_back(23);}
      


      for(int m = 0; m < fillindex.size(); m++) {
	int icut = fillindex[m];
	hPV[icut][Type]->Fill(PV,PUWeight);
	
	hMET[icut][Type]->Fill(MET,PUWeight);
	hMET_Phi[icut][Type]->Fill(MET_Phi,PUWeight);
	hMETSig[icut][Type]->Fill(METSig,PUWeight);
	
	hInvMass[icut][Type]->Fill(InvMass,PUWeight);
	hDiLepPt[icut][Type]->Fill(DiLepPt,PUWeight);
	hLep0Pt[icut][Type]->Fill(Lep0.Pt(),PUWeight);
	hLep1Pt[icut][Type]->Fill(Lep1.Pt(),PUWeight);
	hLep0Eta[icut][Type]->Fill(Lep0.Eta(),PUWeight);
	hLep1Eta[icut][Type]->Fill(Lep1.Eta(),PUWeight);
	hLep0RelIso[icut][Type]->Fill(Lep0RelIso,PUWeight);
	hLep1RelIso[icut][Type]->Fill(Lep1RelIso,PUWeight);
	
	if(NJets>4) hNJets[icut][Type]->Fill(4,PUWeight);
	else hNJets[icut][Type]->Fill(NJets,PUWeight); 
	
	if(NBtagJets>4) hNBtagJets5[icut][Type]->Fill(4,PUWeight);
	else hNBtagJets5[icut][Type]->Fill(NBtagJets,PUWeight);
	
	if(NBtagJets>3) hNBtagJets[icut][Type]->Fill(3,PUWeight);
	else hNBtagJets[icut][Type]->Fill(NBtagJets,PUWeight);
	
	hHT[icut][Type]->Fill(HT,PUWeight);
	hJet0Pt[icut][Type]->Fill(Jet0.Pt(),PUWeight);
	hJet1Pt[icut][Type]->Fill(Jet1.Pt(),PUWeight);
	hBtagJet0Pt[icut][Type]->Fill(BtagJet0.Pt(),PUWeight);

	hDeltaPhiLep[icut][Type]->Fill(DeltaPhiLep,PUWeight);
	hDeltaEtaLep[icut][Type]->Fill(DeltaEtaLep,PUWeight);
	hDeltaPhiLepMET[icut][Type] ->Fill(DeltaPhiLepMET, PUWeight);
	hDeltaPhiLepBtag[icut][Type]->Fill(DeltaPhiLepBtag,PUWeight);
	hDeltaPhiMETBtag[icut][Type]->Fill(DeltaPhiMETBtag,PUWeight);
       
	hInvMassLepBtag[icut][Type]->Fill(InvMassLepBtag,PUWeight);
	hInvTMassMETBtag[icut][Type]->Fill(InvMassMETBtag,PUWeight);

        //if (!fname.Contains("Data") || (fname.Contains("Data") && MT2ll<80) )
	hMT2ll[icut][Type]->Fill(MT2ll,PUWeight);
	hMT2lb[icut][Type]->Fill(MT2llbb,PUWeight);
        hMT2bb[icut][Type]->Fill(MT2bb,PUWeight);
	//FG addition
	if(MT2ll>-1) {
	  if(MT2lb>-1)
	    hMT2ll_MT2lb[icut][Type]->Fill(MT2ll,MT2lb,PUWeight);
	  if(MT2bb>-1)
	    hMT2ll_MT2bb[icut][Type]->Fill(MT2ll,MT2bb,PUWeight);
	  if(MT2llbb>-1)
	    hMT2ll_MT2llbb[icut][Type]->Fill(MT2ll,MT2llbb,PUWeight);
	}
	
	/***************************
            Systematic Histograms
	***************************/
	hUncJet0[icut][Type]->Fill(UncJet0,PUWeight);
	hUncJet1[icut][Type]->Fill(UncJet1,PUWeight);
	hUncBtagJet0[icut][Type]->Fill(UncBtagJet0,PUWeight);
	
	hSysVarJet0[icut][Type]->Fill(SysVarJet0,PUWeight);
	hSysVarJet1[icut][Type]->Fill(SysVarJet1,PUWeight);
	hSysVarBtagJet0[icut][Type]->Fill(SysVarBtagJet0,PUWeight);
	
	hUncJet0Pt[icut][Type]->Fill(Jet0.Pt(),UncJet0);
	hUncJet1Pt[icut][Type]->Fill(Jet1.Pt(),UncJet1);
	hUncBtagJet0Pt[icut][Type]->Fill(BtagJet0.Pt(),UncBtagJet0);
	
	hSysVarJet0Pt[icut][Type]->Fill(Jet0.Pt(),SysVarJet0);
	hSysVarJet1Pt[icut][Type]->Fill(Jet1.Pt(),SysVarJet1);
	hSysVarBtagJet0Pt[icut][Type]->Fill(BtagJet0.Pt(),SysVarBtagJet0);
	
	
      }//for(icuts)    

 
    }// stop signal phase space point selection
  }//for(events)
  
  // Get elapsed time
  sw.Stop();
  std::cout << "--- End of event loop: "; sw.Print();
  
  // --- Write histograms
  
  TString dirname="StopResults/stop";
  // make a dir if it does not exist!!
  struct stat st;
  if(stat(dirname,&st) != 0) system("mkdir " + dirname);
  
  //std::ostringstream sout; sout<<dirname<<"/"<<fname<<"_LooseMuonIso"<<(int)muiso<<"p"<<((int)((muiso-(double)((int)muiso))*100))<<"_LooseElecIso"<<(int)eliso<<"p"<<((int)((eliso-(double)((int)eliso))*100))<<".root";

  std::ostringstream sout; sout<<dirname<<"/"<<"h_LooseMuonIso"<<(int)muiso<<"p"<<((int)((muiso-(double)((int)muiso))*100))<<"_LooseElecIso"<<(int)eliso<<"p"<<((int)((eliso-(double)((int)eliso))*100))<<fname;
  

  TString outfname=sout.str();//dirname + "/" + hname +;// + "h_" + fname;
  TFile *target  = new TFile(outfname,"RECREATE" );  

  for(int j=0; j<NUM_CUTS; j++){
    for(int i=0; i<3; i++){
      
      hPV[j][i]->Write();
    
      hMET[j][i]->Write();
      hMET_Phi[j][i]->Write();
      hMETSig[j][i]->Write();
      
      hInvMass[j][i]->Write();
      hDiLepPt[j][i]->Write();
      hLep0Pt[j][i]->Write();
      hLep1Pt[j][i]->Write();
      hLep0Eta[j][i]->Write();
      hLep1Eta[j][i]->Write();
      hLep0RelIso[j][i]->Write();
      hLep1RelIso[j][i]->Write();
      
      hNJets[j][i]->Write();
      hHT[j][i]->Write();
      hNBtagJets5[j][i]->Write();
      hNBtagJets[j][i]->Write();
      hJet0Pt[j][i]->Write();    
      hJet1Pt[j][i]->Write();    
      hBtagJet0Pt[j][i]->Write();    
        
      hDeltaPhiLep[j][i]->Write();
      hDeltaEtaLep[j][i]->Write();
      hDeltaPhiLepMET[j][i] ->Write();
      hDeltaPhiLepBtag[j][i]->Write();
      hDeltaPhiMETBtag[j][i]->Write();
      
      hInvMassLepBtag[j][i]->Write();
      hInvTMassMETBtag[j][i]->Write();

      hMT2ll[j][i]->Write();
      hMT2lb[j][i]->Write();
      //FG addition
      hMT2bb[j][i]->Write();
      hMT2ll_MT2lb[j][i]->Write();
      hMT2ll_MT2bb[j][i]->Write();
      hMT2ll_MT2llbb[j][i]->Write();
    
      hDYIn[j][i]->Write();
      hDYOut[j][i]->Write();
      hDY_NPV[j][i]->Write();
      hDY_NJets[j][i]->Write();

      hUncJet0[j][i]->Write();
      hUncJet1[j][i]->Write();
      hUncBtagJet0[j][i]->Write();

      hSysVarJet0[j][i]->Write();
      hSysVarJet1[j][i]->Write();
      hSysVarBtagJet0[j][i]->Write();

      hUncJet0Pt[j][i]->Write();
      hUncJet1Pt[j][i]->Write();
      hUncBtagJet0Pt[j][i]->Write();

      hSysVarJet0Pt[j][i]->Write();
      hSysVarJet1Pt[j][i]->Write();
      hSysVarBtagJet0Pt[j][i]->Write();
      
    }//for(i)
  }//for(j)
  
  std::cout << "File saved as " << outfname << std::endl;

}


StopXSec getCrossSectionStop(float stopMass){

  // taken from https://twiki.cern.ch/twiki/bin/view/LHCPhysics/SUSYCrossSections8TeVstopsbottom
  // values are in pb

  float xsecStopPairProd=0., xsecUncert=0.;

  if(stopMass==100) {xsecStopPairProd =	559.757;       xsecUncert = 16.1085/100.;}
  if(stopMass==105) {xsecStopPairProd = 448.456;       xsecUncert = 15.9732/100.;}
  if(stopMass==110) {xsecStopPairProd = 361.917;       xsecUncert = 16.1134/100.;}
  if(stopMass==115) {xsecStopPairProd = 293.281;       xsecUncert = 15.9763/100.;}
  if(stopMass==120) {xsecStopPairProd =	240.077;       xsecUncert = 15.9212/100.;}
  if(stopMass==125) {xsecStopPairProd = 197.122;       xsecUncert = 15.7303/100.;}
  if(stopMass==130) {xsecStopPairProd =	163.376;       xsecUncert = 15.8101/100.;}
  if(stopMass==135) {xsecStopPairProd = 135.791;       xsecUncert = 15.8086/100.;}
  if(stopMass==140) {xsecStopPairProd =	113.319;       xsecUncert = 15.7234/100.;}
  if(stopMass==145) {xsecStopPairProd =  95.0292;      xsecUncert = 15.649/100.;}
  if(stopMass==150) {xsecStopPairProd =	 80.268;       xsecUncert = 15.5946/100.;}
  if(stopMass==155) {xsecStopPairProd =  68.0456;      xsecUncert = 15.5232/100.;}
  if(stopMass==160) {xsecStopPairProd =	 58.01;        xsecUncert = 15.3899/100.;}
  if(stopMass==165) {xsecStopPairProd =  49.6639;      xsecUncert = 15.3711/100.;}
  if(stopMass==170) {xsecStopPairProd =	 42.6441;      xsecUncert = 15.3017/100.;}
  if(stopMass==175) {xsecStopPairProd =  36.7994;      xsecUncert = 15.1749/100.;}
  if(stopMass==180) {xsecStopPairProd =	 31.8695;      xsecUncert = 15.2449/100.;}
  if(stopMass==185) {xsecStopPairProd =  27.7028;      xsecUncert = 15.063/100.;}
  if(stopMass==190) {xsecStopPairProd =	 24.1585;      xsecUncert = 15.16/100.;}
  if(stopMass==195) {xsecStopPairProd =  21.1597;      xsecUncert = 14.9422/100.;}
  if(stopMass==200) {xsecStopPairProd =	 18.5245;      xsecUncert = 14.9147/100.;}
  if(stopMass==205) {xsecStopPairProd =  16.2439;      xsecUncert = 15.117/100.;}
  if(stopMass==210) {xsecStopPairProd =	 14.3201;      xsecUncert = 14.8495/100.;}
  if(stopMass==215) {xsecStopPairProd =  12.6497;      xsecUncert = 14.8689/100.;}
  if(stopMass==220) {xsecStopPairProd =	 11.1808;      xsecUncert = 14.9108/100.;}
  if(stopMass==225) {xsecStopPairProd =   9.90959;     xsecUncert = 14.9662/100.;}
  if(stopMass==230) {xsecStopPairProd =	  8.78125;     xsecUncert = 14.796/100.;}
  if(stopMass==235) {xsecStopPairProd =   7.81646;     xsecUncert = 14.7983/100.;}
  if(stopMass==240) {xsecStopPairProd =	  6.96892;     xsecUncert = 14.7878/100.;}
  if(stopMass==245) {xsecStopPairProd =	  6.22701;     xsecUncert = 14.7897/100.;}
  if(stopMass==250) {xsecStopPairProd =	  5.57596;     xsecUncert = 14.7529/100.;}
  if(stopMass==255) {xsecStopPairProd =   5.00108;     xsecUncert = 14.729/100.;}
  if(stopMass==260) {xsecStopPairProd =	  4.48773;     xsecUncert = 14.6782/100.;}
  if(stopMass==265) {xsecStopPairProd =	  4.03416;     xsecUncert = 14.7964/100.;}
  if(stopMass==270) {xsecStopPairProd =	  3.63085;     xsecUncert = 14.6565/100.;}
  if(stopMass==275) {xsecStopPairProd =   3.2781;      xsecUncert = 14.7341/100.;}
  if(stopMass==280) {xsecStopPairProd =	  2.95613;     xsecUncert = 14.7816/100.;}
  if(stopMass==285) {xsecStopPairProd =   2.67442;     xsecUncert = 14.7661/100.;}
  if(stopMass==290) {xsecStopPairProd =	  2.42299;     xsecUncert = 14.6805/100.;}
  if(stopMass==295) {xsecStopPairProd =   2.19684;     xsecUncert = 14.8465/100.;}
  if(stopMass==300) {xsecStopPairProd =	  1.99608;     xsecUncert = 14.6905/100.;}
  if(stopMass==305) {xsecStopPairProd =   1.81486;     xsecUncert = 14.4434/100.;}
  if(stopMass==310) {xsecStopPairProd =	  1.64956;     xsecUncert = 14.4769/100.;}
  if(stopMass==315) {xsecStopPairProd =   1.50385;     xsecUncert = 14.4549/100.;}
  if(stopMass==320) {xsecStopPairProd =	  1.3733;      xsecUncert = 14.7503/100.;}
  if(stopMass==325) {xsecStopPairProd =   1.25277;     xsecUncert = 14.2875/100.;}
  if(stopMass==330) {xsecStopPairProd =	  1.14277;     xsecUncert = 14.578/100.;}
  if(stopMass==335) {xsecStopPairProd =   1.04713;     xsecUncert = 14.3659/100.;}
  if(stopMass==340) {xsecStopPairProd =	  0.959617;    xsecUncert = 14.3896/100.;}
  if(stopMass==345) {xsecStopPairProd =   0.879793;    xsecUncert = 14.3881/100.;}
  if(stopMass==350) {xsecStopPairProd =	  0.807323;    xsecUncert = 14.3597/100.;}
  if(stopMass==355) {xsecStopPairProd =   0.74141;     xsecUncert = 14.368/100.;}
  if(stopMass==360) {xsecStopPairProd =	  0.681346;    xsecUncert = 14.3357/100.;}
  if(stopMass==365) {xsecStopPairProd =   0.626913;    xsecUncert = 14.3627/100.;}
  if(stopMass==370) {xsecStopPairProd =	  0.576882;    xsecUncert = 14.2712/100.;}
  if(stopMass==375) {xsecStopPairProd =   0.531443;    xsecUncert = 14.266/100.;}
  if(stopMass==380) {xsecStopPairProd =	  0.489973;    xsecUncert = 14.3962/100.;}
  if(stopMass==385) {xsecStopPairProd =   0.452072;    xsecUncert = 14.2234/100.;}
  if(stopMass==390) {xsecStopPairProd =	  0.4176;      xsecUncert = 14.3166/100.;}
  if(stopMass==395) {xsecStopPairProd =   0.385775;    xsecUncert = 14.3112/100.;}
  if(stopMass==400) {xsecStopPairProd =	  0.35683;     xsecUncert = 14.2848/100.;}
  if(stopMass==405) {xsecStopPairProd =   0.329881;    xsecUncert = 14.2072/100.;}
  if(stopMass==410) {xsecStopPairProd =	  0.305512;    xsecUncert = 14.2648/100.;}
  if(stopMass==415) {xsecStopPairProd =   0.283519;    xsecUncert = 14.102/100.;}
  if(stopMass==420) {xsecStopPairProd =	  0.262683;    xsecUncert = 14.3075/100.;}
  if(stopMass==425) {xsecStopPairProd =   0.243755;    xsecUncert = 14.0504/100.;}
  if(stopMass==430) {xsecStopPairProd =	  0.226367;    xsecUncert = 14.0494/100.;}
  if(stopMass==435) {xsecStopPairProd =   0.209966;    xsecUncert = 14.0334/100.;}
  if(stopMass==440) {xsecStopPairProd =	  0.195812;    xsecUncert = 14.0772/100.;}
  if(stopMass==445) {xsecStopPairProd =   0.181783;    xsecUncert = 14.1771/100.;}
  if(stopMass==450) {xsecStopPairProd =	  0.169668;    xsecUncert = 14.2368/100.;}
  if(stopMass==455) {xsecStopPairProd =   0.158567;    xsecUncert = 14.2609/100.;}
  if(stopMass==460) {xsecStopPairProd =	  0.147492;    xsecUncert = 14.4105/100.;}
  if(stopMass==465) {xsecStopPairProd =   0.137392;    xsecUncert = 14.4772/100.;}
  if(stopMass==470) {xsecStopPairProd =	  0.128326;    xsecUncert = 14.5144/100.;}
  if(stopMass==475) {xsecStopPairProd =   0.119275;    xsecUncert = 14.6664/100.;}
  if(stopMass==480) {xsecStopPairProd =	  0.112241;    xsecUncert = 14.6307/100.;}
  if(stopMass==485) {xsecStopPairProd =   0.104155;    xsecUncert = 14.7581/100.;}
  if(stopMass==490) {xsecStopPairProd =	  0.0977878;   xsecUncert = 14.7977/100.;}
  if(stopMass==495) {xsecStopPairProd =   0.091451;    xsecUncert = 14.8963/100.;}
  if(stopMass==500) {xsecStopPairProd =	  0.0855847;   xsecUncert = 14.9611/100.;}
  if(stopMass==505) {xsecStopPairProd =   0.0801322;   xsecUncert = 15.0389/100.;}
  if(stopMass==510) {xsecStopPairProd =   0.0751004;   xsecUncert = 15.1402/100.;}
  if(stopMass==515) {xsecStopPairProd =   0.0703432;   xsecUncert = 15.2139/100.;}
  if(stopMass==520) {xsecStopPairProd =   0.0660189;   xsecUncert = 15.3368/100.;}
  if(stopMass==525) {xsecStopPairProd =   0.0618641;   xsecUncert = 15.4135/100.;}
  if(stopMass==530) {xsecStopPairProd =   0.0580348;   xsecUncert = 15.4422/100.;}
  if(stopMass==535) {xsecStopPairProd =   0.0545113;   xsecUncert = 15.5446/100.;}
  if(stopMass==540) {xsecStopPairProd =   0.0511747;   xsecUncert = 15.6283/100.;}
  if(stopMass==545) {xsecStopPairProd =   0.0481537;   xsecUncert = 15.726/100.;}
  if(stopMass==550) {xsecStopPairProd =   0.0452067;   xsecUncert = 15.8177/100.;}
  if(stopMass==555) {xsecStopPairProd =   0.0424781;   xsecUncert = 15.9022/100.;}
  if(stopMass==560) {xsecStopPairProd =   0.0399591;   xsecUncert = 16.0067/100.;}
  if(stopMass==565) {xsecStopPairProd =   0.0376398;   xsecUncert = 16.0367/100.;}
  if(stopMass==570) {xsecStopPairProd =   0.0354242;   xsecUncert = 16.137/100.;}
  if(stopMass==575) {xsecStopPairProd =   0.0333988;   xsecUncert = 16.2132/100.;}
  if(stopMass==580) {xsecStopPairProd =   0.0313654;   xsecUncert = 16.3135/100.;}
  if(stopMass==585) {xsecStopPairProd =   0.0295471;   xsecUncert = 16.4264/100.;}
  if(stopMass==590) {xsecStopPairProd =   0.0279395;   xsecUncert = 16.4546/100.;}
  if(stopMass==595) {xsecStopPairProd =   0.0263263;   xsecUncert = 16.567/100.;}
  if(stopMass==600) {xsecStopPairProd =   0.0248009;   xsecUncert = 16.6406/100.;}
  if(stopMass==605) {xsecStopPairProd =   0.0233806;   xsecUncert = 16.7295/100.;}
  if(stopMass==610) {xsecStopPairProd =   0.0220672;   xsecUncert = 16.8447/100.;}
  if(stopMass==615) {xsecStopPairProd =   0.0208461;   xsecUncert = 16.9276/100.;}
  if(stopMass==620) {xsecStopPairProd =   0.0196331;   xsecUncert = 17.0459/100.;}
  if(stopMass==625) {xsecStopPairProd =   0.0185257;   xsecUncert = 17.0835/100.;}
  if(stopMass==630) {xsecStopPairProd =   0.0175075;   xsecUncert = 17.1478/100.;}
  if(stopMass==635) {xsecStopPairProd =   0.0164955;   xsecUncert = 17.2753/100.;}
  if(stopMass==640) {xsecStopPairProd =   0.0155809;   xsecUncert = 17.3814/100.;}
  if(stopMass==645) {xsecStopPairProd =   0.0147721;   xsecUncert = 17.4885/100.;}
  if(stopMass==650) {xsecStopPairProd =   0.0139566;   xsecUncert = 17.56/100.;}
  if(stopMass==655) {xsecStopPairProd =   0.0132456;   xsecUncert = 17.6129/100.;}
  if(stopMass==660) {xsecStopPairProd =   0.0125393;   xsecUncert = 17.7363/100.;}
  if(stopMass==665) {xsecStopPairProd =   0.0118287;   xsecUncert = 17.7959/100.;}
  if(stopMass==670) {xsecStopPairProd =   0.0112223;   xsecUncert = 17.8974/100.;}
  if(stopMass==675) {xsecStopPairProd =   0.0106123;   xsecUncert = 17.9891/100.;}
  if(stopMass==680) {xsecStopPairProd =   0.0100516;   xsecUncert = 18.0618/100.;}
  if(stopMass==685) {xsecStopPairProd =   0.0095256;   xsecUncert = 18.1714/100.;}
  if(stopMass==690) {xsecStopPairProd =   0.0090306;   xsecUncert = 18.2108/100.;}
  if(stopMass==695) {xsecStopPairProd =   0.00856339;  xsecUncert = 18.3365/100.;}
  if(stopMass==700) {xsecStopPairProd =   0.0081141;   xsecUncert = 18.4146/100.;}
  if(stopMass==705) {xsecStopPairProd =   0.00769525;  xsecUncert = 18.4937/100.;}
  if(stopMass==710) {xsecStopPairProd =   0.00730084;  xsecUncert = 18.6195/100.;}
  if(stopMass==715) {xsecStopPairProd =   0.00692243;  xsecUncert = 18.7005/100.;}
  if(stopMass==720) {xsecStopPairProd =   0.00656729;  xsecUncert = 18.819/100.;}
  if(stopMass==725) {xsecStopPairProd =   0.00623244;  xsecUncert = 18.8796/100.;}
  if(stopMass==730) {xsecStopPairProd =   0.00591771;  xsecUncert = 18.996/100.;}
  if(stopMass==735) {xsecStopPairProd =   0.00561049;  xsecUncert = 19.0787/100.;}
  if(stopMass==740) {xsecStopPairProd =   0.00532605;  xsecUncert = 19.1995/100.;}
  if(stopMass==745) {xsecStopPairProd =   0.00506044;  xsecUncert = 19.2916/100.;}
  if(stopMass==750) {xsecStopPairProd =   0.00480639;  xsecUncert = 19.4088/100.;}
  if(stopMass==755) {xsecStopPairProd =   0.00455979;  xsecUncert = 19.508/100.;}
  if(stopMass==760) {xsecStopPairProd =   0.00433688;  xsecUncert = 19.632/100.;}
  if(stopMass==765) {xsecStopPairProd =   0.00412174;  xsecUncert = 19.7141/100.;}
  if(stopMass==770) {xsecStopPairProd =   0.00391839;  xsecUncert = 19.8299/100.;}
  if(stopMass==775) {xsecStopPairProd =   0.00372717;  xsecUncert = 19.9097/100.;}
  if(stopMass==780) {xsecStopPairProd =   0.00354211;  xsecUncert = 20.0016/100.;}
  if(stopMass==785) {xsecStopPairProd =   0.00336904;  xsecUncert = 20.123/100.;}
  if(stopMass==790) {xsecStopPairProd =   0.00320476;  xsecUncert = 20.2271/100.;}
  if(stopMass==795) {xsecStopPairProd =   0.00304935;  xsecUncert = 20.4479/100.;}
  if(stopMass==800) {xsecStopPairProd =   0.00289588;  xsecUncert = 20.516/100.;}
  if(stopMass==805) {xsecStopPairProd =   0.00275424;  xsecUncert = 20.5444/100.;}
  if(stopMass==810) {xsecStopPairProd =   0.0026184;   xsecUncert = 20.8204/100.;}
  if(stopMass==815) {xsecStopPairProd =   0.00249291;  xsecUncert = 21.0063/100.;}
  if(stopMass==820) {xsecStopPairProd =   0.00237168;  xsecUncert = 21.0865/100.;}
  if(stopMass==825) {xsecStopPairProd =   0.00226163;  xsecUncert = 21.0511/100.;}
  if(stopMass==830) {xsecStopPairProd =   0.00214607;  xsecUncert = 21.3705/100.;}
  if(stopMass==835) {xsecStopPairProd =   0.00204589;  xsecUncert = 21.3026/100.;}
  if(stopMass==840) {xsecStopPairProd =   0.00195172;  xsecUncert = 21.6053/100.;}
  if(stopMass==845) {xsecStopPairProd =   0.0018573;   xsecUncert = 21.8177/100.;}
  if(stopMass==850) {xsecStopPairProd =   0.00176742;  xsecUncert = 21.836/100.;}
  if(stopMass==855) {xsecStopPairProd =   0.00168383;  xsecUncert = 22.1411/100.;}
  if(stopMass==860) {xsecStopPairProd =   0.00160403;  xsecUncert = 22.0506/100.;}
  if(stopMass==865) {xsecStopPairProd =   0.00153063;  xsecUncert = 22.3461/100.;}
  if(stopMass==870) {xsecStopPairProd =   0.00145772;  xsecUncert = 22.6206/100.;}
  if(stopMass==875) {xsecStopPairProd =   0.0013878;   xsecUncert = 22.5422/100.;}
  if(stopMass==880) {xsecStopPairProd =   0.00132077;  xsecUncert = 23.2161/100.;}
  if(stopMass==885) {xsecStopPairProd =   0.00126234;  xsecUncert = 23.1283/100.;}
  if(stopMass==890) {xsecStopPairProd =   0.00120568;  xsecUncert = 23.8404/100.;}
  if(stopMass==895) {xsecStopPairProd =   0.00114627;  xsecUncert = 23.7327/100.;}
  if(stopMass==900) {xsecStopPairProd =   0.00109501;  xsecUncert = 23.9439/100.;}
  if(stopMass==905) {xsecStopPairProd =   0.001044;    xsecUncert = 24.1049/100.;}
  if(stopMass==910) {xsecStopPairProd =   0.000996193; xsecUncert = 24.2789/100.;}
  if(stopMass==915) {xsecStopPairProd =   0.00095071;  xsecUncert = 24.5443/100.;}
  if(stopMass==920) {xsecStopPairProd =   0.000907494; xsecUncert = 24.7597/100.;}
  if(stopMass==925) {xsecStopPairProd =   0.000866391; xsecUncert = 24.877/100.;}
  if(stopMass==930) {xsecStopPairProd =   0.000826533; xsecUncert = 25.0849/100.;}
  if(stopMass==935) {xsecStopPairProd =   0.000789573; xsecUncert = 25.2885/100.;}
  if(stopMass==940) {xsecStopPairProd =   0.000753768; xsecUncert = 25.4768/100.;}
  if(stopMass==945) {xsecStopPairProd =   0.000719675; xsecUncert = 25.6582/100.;}
  if(stopMass==950) {xsecStopPairProd =   0.000687022; xsecUncert = 25.8341/100.;}
  if(stopMass==955) {xsecStopPairProd =   0.000656279; xsecUncert = 26.0372/100.;}
  if(stopMass==960) {xsecStopPairProd =   0.000626876; xsecUncert = 26.2059/100.;}
  if(stopMass==965) {xsecStopPairProd =   0.000598955; xsecUncert = 26.3653/100.;}
  if(stopMass==970) {xsecStopPairProd =   0.000571551; xsecUncert = 26.5169/100.;}
  if(stopMass==975) {xsecStopPairProd =   0.000546728; xsecUncert = 26.7985/100.;}
  if(stopMass==980) {xsecStopPairProd =   0.000522495; xsecUncert = 26.9218/100.;}
  if(stopMass==985) {xsecStopPairProd =   0.000499017; xsecUncert = 27.1036/100.;}
  if(stopMass==990) {xsecStopPairProd =   0.000476255; xsecUncert = 27.3032/100.;}
  if(stopMass==995) {xsecStopPairProd =   0.000455959; xsecUncert = 27.4544/100.;}
  if(stopMass==1000) {xsecStopPairProd =  0.000435488; xsecUncert = 27.6595/100.;}

  StopXSec stopCrossSection;
  stopCrossSection.stopProdXsec = xsecStopPairProd;
  stopCrossSection.stopProdXsecUncert = xsecUncert;
  
  if(xsecStopPairProd==0. || xsecUncert==0.)    
    std::cout << "no xsec available for this mass point - choose another one!" << std::endl;
  
  return stopCrossSection;
}




float getMT2(TLorentzVector lept1, TLorentzVector lept2, float theMET, float theMETphi){
  // Calculate MT2 variable for two leptons and missing energy, assuming zero testmass
  double pa[3];
  double pb[3];
  double pmiss[3];
  
  TLorentzVector pmet;
  pmet.SetPtEtaPhiM(theMET, 0., theMETphi, 0.);
  pmiss[0] = 0.; // irrelevant
  pmiss[1] = pmet.Px();
  pmiss[2] = pmet.Py();
  
  pa[0] = 0.;
  pa[1] = lept1.Px();
  pa[2] = lept1.Py();
  
  pb[0] = 0.;
  pb[1] = lept2.Px();
  pb[2] = lept2.Py();
  
  mt2bisect* MT2bisect = new mt2bisect();
  MT2bisect->set_verbose(0);
  MT2bisect->set_momenta(pa, pb, pmiss);
  MT2bisect->set_mn(0.); // testmass
  double MT2 = MT2bisect->get_mt2();
  delete MT2bisect;
  return MT2;  
}





#endif

