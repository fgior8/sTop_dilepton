#include "General.h"

/*****************
      Files
 ****************/

void PlotsTree(TString plots="Ctrl_2Jets_PhiSmall_OnZ", int ch=4, TString sys="", bool EvtNorm=false){
  
  TString files  = dirnameIn + "h" + fl;  
  TString plots_for_DY = "MET";  

  /****************
      Channel
   ***************/
  
  TString channel;
  if(ch==0) channel="mumu";
  if(ch==1) channel="ee";  
  if(ch==2) channel="mue"; 
  if(ch==3) channel="all"; 
  if(ch==4) channel="mmee"; 
  
  gROOT->SetStyle("Plain");
  gStyle->SetOptFit(1000);
  gStyle->SetOptStat("emruo");
  gStyle->SetOptStat(kFALSE);
  gStyle->SetPadTickY(1);
  gStyle->SetPadTickX(1);


  /****************
      DY Macro
   ***************/

  //gSystem->CompileMacro("/home/brochero/ttbar/TopCode/DYestimate.C"); // mumu & ee
  //gROOT->ProcessLine(".L /home/brochero/ttbar/TopCode/ZmassFromLikelihoodFit.C"); // mue

  gSystem->CompileMacro("/gpfs/csic_users/fgior8/sTop/PAF/DYestimate.C"); // mumu & ee
  gROOT->ProcessLine(".L /gpfs/csic_users/fgior8/sTop/PAF/ZmassFromLikelihoodFit.C"); // mue

  
  if(plots=="dilepton") dd_dd_uncer=0.0;

  int histos=20; // it was 12
  int histos2D=3; //FG addition

  /****************
        Data
   ***************/
  DoubleMuon=loadhistograms(plots,files + "_DataMu12.root");
  DoubleMuon=addhistograms(DoubleMuon);

  DoubleElectron=loadhistograms(plots,files + "_DataEG12.root");
  DoubleElectron=addhistograms(DoubleElectron);

  MuEG=loadhistograms(plots,files + "_DataMuEG12.root");
  MuEG=addhistograms(MuEG);

  for(int j=0; j<histos; j++){
    
    Data.hist[j][0]=(TH1F*)DoubleMuon.hist[j][0]->Clone();
    Data.hist[j][1]=(TH1F*)DoubleElectron.hist[j][1]->Clone();
    Data.hist[j][2]=(TH1F*)MuEG.hist[j][2]->Clone();
    
  }

  for(int j=0; j<histos2D; j++){
    
    Data.hist2D[j][0]=(TH2F*)DoubleMuon.hist2D[j][0]->Clone();
    Data.hist2D[j][1]=(TH2F*)DoubleElectron.hist2D[j][1]->Clone();
    Data.hist2D[j][2]=(TH2F*)MuEG.hist2D[j][2]->Clone();
    
  }

  Data=addhistograms(Data);
  setupdraw(Data, kBlack); 

//   int NbinsData0 = Data.hist[0][0]->GetNbinsX() +1;   // to normalize stop to data
//   int NbinsData1 = Data.hist[0][1]->GetNbinsX() +1;
//   int NbinsData2 = Data.hist[0][2]->GetNbinsX() +1;
  
//   int NevtData_mumu = Data.hist[0][0]->Integral(1, NbinsData0 );
//   int NevtData_ee   = Data.hist[0][1]->Integral(1, NbinsData1 );
//   int NevtData_mue  = Data.hist[0][2]->Integral(1, NbinsData2 );

  /****************
       DY - DD
   ***************/  

  ZDY=loadhistograms(plots,files + "_ZDY.root");
   
  scalehistograms(ZDY, 0, SFmumu); // Scale Factors
  scalehistograms(ZDY, 1, SFee);   // Scale Factors
  scalehistograms(ZDY, 2, SFmue);  // Scale Factors

  float DY_DD_mumu_err=0.;
  float DY_DD_ee_err=0.;
  float DY_DD_mue_err=0.;

  std::vector<float> DY_DD_mumu;
  if (!DYestimate("mumu", plots_for_DY, DY_DD_mumu)) {
    scalehistograms(ZDY, 0, DY_DD_mumu[2]/DY_DD_mumu[0]); // DY-DD_mumu
    DY_DD_mumu_err=sqrt(DY_DD_mumu[2]*DY_DD_mumu[2]*dd_dd_uncer*dd_dd_uncer); // DY-DD Error
    cout << "Scaling MC-DY in mumu channel....." << endl << "SFDY=" << DY_DD_mumu[2]/DY_DD_mumu[0] << endl << "DY_mumu_err=" << DY_DD_mumu_err << endl;
  }

  std::vector<float> DY_DD_ee;
  if (!DYestimate("ee", plots_for_DY, DY_DD_ee)) {
    scalehistograms(ZDY, 1, DY_DD_ee[2]/DY_DD_ee[0]); // DY-DD_ee
    DY_DD_ee_err=sqrt(DY_DD_ee[2]*DY_DD_ee[2]*dd_dd_uncer*dd_dd_uncer); // DY-DD Error
    cout << "Scaling MC-DY in ee channel....." << endl << "SFDY=" << DY_DD_ee[2]/DY_DD_ee[0] << endl << "DY_ee_err=" << DY_DD_ee_err << endl;
  }

  std::vector<float> SF_DD_mue;
  if (!ZmassFromLikelihoodFit("mue", plots_for_DY, SF_DD_mue)) { // DY-DD_mue: SF_DD_mue[1] is the error on the SF_DD_mue and SF_DD_mue[2]=Evt.
    if (plots!="dilepton") {
      scalehistograms(ZDY, 2, SF_DD_mue[0]); // DY-DD
      DY_DD_mue_err=SF_DD_mue[1]; // DY-DD Error
      cout << "Scaling MC-DY in mue channel....." << endl << "SFDY=" << SF_DD_mue[0] << endl;
    }
  }

  // DY-DD_mue/bin: NbtagJets Plot 
  if (plots!="dilepton") {

    // DY/bin mumu
    float SFmumu0 = (ZDY.hist[6][0]->GetBinContent(1))*1.422/(DY_DD_mumu[2]/DY_DD_mumu[0]);
    float SFmumu1 = (ZDY.hist[6][0]->GetBinContent(2))*1.720/(DY_DD_mumu[2]/DY_DD_mumu[0]);
    float SFmumu2 = (ZDY.hist[6][0]->GetBinContent(3))*1.854/(DY_DD_mumu[2]/DY_DD_mumu[0]);
    float SFmumu3 = (ZDY.hist[6][0]->GetBinContent(4))*1.362/(DY_DD_mumu[2]/DY_DD_mumu[0]);

    ZDY.hist[6][0]->SetBinContent(1,SFmumu0);
    ZDY.hist[6][0]->SetBinContent(2,SFmumu1);
    ZDY.hist[6][0]->SetBinContent(3,SFmumu2);
    ZDY.hist[6][0]->SetBinContent(4,SFmumu3);

    // DY/bin ee
    float SFee0 = (ZDY.hist[6][1]->GetBinContent(1))*1.618/(DY_DD_ee[2]/DY_DD_ee[0]);
    float SFee1 = (ZDY.hist[6][1]->GetBinContent(2))*1.885/(DY_DD_ee[2]/DY_DD_ee[0]);
    float SFee2 = (ZDY.hist[6][1]->GetBinContent(3))*2.090/(DY_DD_ee[2]/DY_DD_ee[0]);
    float SFee3 = (ZDY.hist[6][1]->GetBinContent(4))*3.216/(DY_DD_ee[2]/DY_DD_ee[0]);

    ZDY.hist[6][1]->SetBinContent(1,SFee0);
    ZDY.hist[6][1]->SetBinContent(2,SFee1);
    ZDY.hist[6][1]->SetBinContent(3,SFee2);
    ZDY.hist[6][1]->SetBinContent(4,SFee3);

    // DY/bin mue    
    
    //btag
    // float SFmue0 = (ZDY.hist[6][2]->GetBinContent(1))*1.019/SF_DD_mue[0];
    // float SFmue1 = (ZDY.hist[6][2]->GetBinContent(2))*1.543/SF_DD_mue[0];
    // float SFmue2 = (ZDY.hist[6][2]->GetBinContent(3))*5.238/SF_DD_mue[0];
    // float SFmue3 = (ZDY.hist[6][2]->GetBinContent(4))*1.611/SF_DD_mue[0];
    // float SFmue4 = (ZDY.hist[6][2]->GetBinContent(5))*1.611/SF_DD_mue[0];

    //btag 21/12/2012
    float SFmue0 = (ZDY.hist[6][2]->GetBinContent(1))*0.994/SF_DD_mue[0];
    float SFmue1 = (ZDY.hist[6][2]->GetBinContent(2))*1.764/SF_DD_mue[0];
    float SFmue2 = (ZDY.hist[6][2]->GetBinContent(3))*4.943/SF_DD_mue[0];
    float SFmue3 = (ZDY.hist[6][2]->GetBinContent(4));
    float SFmue4 = (ZDY.hist[6][2]->GetBinContent(5));
        
    ZDY.hist[6][2]->SetBinContent(1,SFmue0);
    ZDY.hist[6][2]->SetBinContent(2,SFmue1);
    ZDY.hist[6][2]->SetBinContent(3,SFmue2);
    ZDY.hist[6][2]->SetBinContent(4,SFmue3);
    ZDY.hist[6][2]->SetBinContent(5,SFmue4);

  }


  ZDY=addhistograms(ZDY); // All Channels
  Z=ZDY;

  setupdraw(Z, kAzure-2);


  /****************
      MC Sample
   ***************/  

  TW=loadhistograms(plots,files + "_TWDilep" + sys + ".root");

  scalehistograms(TW, 0, SFmumu); // Scale Factors
  scalehistograms(TW, 1, SFee);   // Scale Factors
  scalehistograms(TW, 2, SFmue);  // Scale Factors

  TW=addhistograms(TW); // All Channels


  TbarW=loadhistograms(plots,files + "_TbarWDilep" + sys + ".root");

  scalehistograms(TbarW, 0, SFmumu); // Scale Factors
  scalehistograms(TbarW, 1, SFee);   // Scale Factors
  scalehistograms(TbarW, 2, SFmue);  // Scale Factors

  TbarW=addhistograms(TbarW); // All Channels

  for(int j=0; j<histos; j++){
    for(int k=0; k<5; k++){
      
      SingleT.hist[j][k]=(TH1F*)TW.hist[j][k]->Clone();
      SingleT.hist[j][k]->Add(SingleT.hist[j][k],TbarW.hist[j][k]);
      
    }
  }
  

  setupdraw(SingleT, kPink-3); //Select Histogram Color

  ///////////////////////////////////////////////////////////////

  //TTbar=loadhistograms(plots,files + "_TTbar_MCatNLO" + sys + ".root");
  //TTbar=loadhistograms(plots,files + "_TTbar_MassiveBinDECAY" + sys + ".root");
  //TTbar=loadhistograms(plots,files + "_TTbar_FullLeptMG" + sys + ".root");
  TTbar=loadhistograms(plots,files + "_TTbar_Powheg" + sys + ".root");
  //TTbar=loadhistograms(plots,files + "_TTbar" + sys + ".root");

  scalehistograms(TTbar, 0, SFmumu*SF_BR/*(234.0/225.0)*/);
  scalehistograms(TTbar, 1, SFee*SF_BR/*(234.0/225.0)*/);
  scalehistograms(TTbar, 2, SFmue*SF_BR/*(234.0/225.0)*/);
  
  TTbar=addhistograms(TTbar);
  setupdraw(TTbar, kRed+1);

  //////////////////////////////////////////////////////////////

  //TTbarBkg=loadhistograms(plots,files + "_TTbar_MCatNLOBkg.root");
  //TTbarBkg=loadhistograms(plots,files + "_TTbar_MassiveBinDECAYBkg.root");
  //TTbarBkg=loadhistograms(plots,files + "_TTbar_FullLeptMGBkg" + sys + ".root");
  TTbarBkg=loadhistograms(plots,files + "_TTbar_PowhegBkg.root");
  //TTbarBkg=loadhistograms(plots,files + "_TTbarBkg.root");

  scalehistograms(TTbarBkg, 0, SFmumu*SF_BR/*(234.0/225.0)*/);
  scalehistograms(TTbarBkg, 1, SFee*SF_BR/*(234.0/225.0)*/);
  scalehistograms(TTbarBkg, 2, SFmue*SF_BR/*(234.0/225.0)*/);

  TTbarBkg=addhistograms(TTbarBkg);

  WJets=loadhistograms(plots,files + "_WJets_Madgraph.root");

  scalehistograms(WJets, 0, SFmumu); // Scale Factors
  scalehistograms(WJets, 1, SFee);   // Scale Factors
  scalehistograms(WJets, 2, SFmue);  // Scale Factors

  WJets=addhistograms(WJets); // All Channels

  for(int j=0; j<histos; j++){
    for(int k=0; k<5; k++){
      
      NONWZ.hist[j][k]=(TH1F*)TTbarBkg.hist[j][k]->Clone();
      NONWZ.hist[j][k]->Add(NONWZ.hist[j][k],WJets.hist[j][k]);
      
    }
  }

  for(int j=0; j<histos2D; j++){
    for(int k=0; k<5; k++){
      
      NONWZ.hist2D[j][k]=(TH2F*)TTbarBkg.hist2D[j][k]->Clone();
      NONWZ.hist2D[j][k]->Add(NONWZ.hist2D[j][k],WJets.hist2D[j][k]);
      
    }
  }
  
  setupdraw(NONWZ, kGreen-3); //Select Histogram Color
  
  //////////////////////////////////////////////////////////////

  WW=loadhistograms(plots,files + "_WWTo2L2Nu_Madgraph" + sys + ".root");

  scalehistograms(WW, 0, SFmumu); // Scale Factors
  scalehistograms(WW, 1, SFee);   // Scale Factors
  scalehistograms(WW, 2, SFmue);  // Scale Factors

  WW=addhistograms(WW); // All Channels


  WZ=loadhistograms(plots,files + "_WZ_pythia6_tauola" + sys + ".root");

  scalehistograms(WZ, 0, SFmumu); // Scale Factors
  scalehistograms(WZ, 1, SFee);   // Scale Factors
  scalehistograms(WZ, 2, SFmue);  // Scale Factors

  WZ=addhistograms(WZ); // All Channels


  ZZ=loadhistograms(plots,files + "_ZZ_pythia6_tauola" + sys + ".root");

  scalehistograms(ZZ, 0, SFmumu); // Scale Factors
  scalehistograms(ZZ, 1, SFee);   // Scale Factors
  scalehistograms(ZZ, 2, SFmue);  // Scale Factors

  ZZ=addhistograms(ZZ); // All Channels


  for(int j=0; j<histos; j++){
    for(int k=0; k<5; k++){
      VV.hist[j][k]=(TH1F*)WW.hist[j][k]->Clone();
      VV.hist[j][k]->Add(VV.hist[j][k],WZ.hist[j][k]);
      VV.hist[j][k]->Add(VV.hist[j][k],ZZ.hist[j][k]);    
    }
  }

  for(int j=0; j<histos2D; j++){
    for(int k=0; k<5; k++){   
      VV.hist2D[j][k]=(TH2F*)WW.hist2D[j][k]->Clone();
      VV.hist2D[j][k]->Add(VV.hist2D[j][k],WZ.hist2D[j][k]);
      VV.hist2D[j][k]->Add(VV.hist2D[j][k],ZZ.hist2D[j][k]);
    }
  } 
  
  setupdraw(VV, kOrange-3); //Select Histogram Color
  
  ////////////////////////////////////////////////////
  ///////          RARE PROCESSES       //////////////
  ////////////////////////////////////////////////////

  TTZJets=loadhistograms(plots,files + "_TTZJets" + sys + ".root");

  scalehistograms(TTZJets, 0, SFmumu); // Scale Factors
  scalehistograms(TTZJets, 1, SFee);   // Scale Factors
  scalehistograms(TTZJets, 2, SFmue);  // Scale Factors

  TTZJets=addhistograms(TTZJets); // All Channels


  TTWJets=loadhistograms(plots,files + "_TTWJets" + sys + ".root");

  scalehistograms(TTWJets, 0, SFmumu); // Scale Factors
  scalehistograms(TTWJets, 1, SFee);   // Scale Factors
  scalehistograms(TTWJets, 2, SFmue);  // Scale Factors

  TTWJets=addhistograms(TTWJets); // All Channels


  WgammaToLNuG=loadhistograms(plots,files + "_WgammaToLNuG" + sys + ".root");

  scalehistograms(WgammaToLNuG, 0, SFmumu); // Scale Factors
  scalehistograms(WgammaToLNuG, 1, SFee);   // Scale Factors
  scalehistograms(WgammaToLNuG, 2, SFmue);  // Scale Factors

  WgammaToLNuG=addhistograms(WgammaToLNuG); // All Channels


  ZgammaToLNuG=loadhistograms(plots,files + "_ZgammaToLLG" + sys + ".root");

  scalehistograms(ZgammaToLNuG, 0, SFmumu); // Scale Factors
  scalehistograms(ZgammaToLNuG, 1, SFee);   // Scale Factors
  scalehistograms(ZgammaToLNuG, 2, SFmue);  // Scale Factors

  ZgammaToLNuG=addhistograms(ZgammaToLNuG); // All Channels


  HWW125=loadhistograms(plots,files + "_HWW125" + sys + ".root");

  scalehistograms(HWW125, 0, SFmumu); // Scale Factors
  scalehistograms(HWW125, 1, SFee);   // Scale Factors
  scalehistograms(HWW125, 2, SFmue);  // Scale Factors

  HWW125=addhistograms(HWW125); // All Channels


  WWGJets=loadhistograms(plots,files + "_WWGJets" + sys + ".root");

  scalehistograms(WWGJets, 0, SFmumu); // Scale Factors
  scalehistograms(WWGJets, 1, SFee);   // Scale Factors
  scalehistograms(WWGJets, 2, SFmue);  // Scale Factors

  WWGJets=addhistograms(WWGJets); // All Channels


  TTGJets=loadhistograms(plots,files + "_TTGJets" + sys + ".root");

  scalehistograms(TTGJets, 0, SFmumu); // Scale Factors
  scalehistograms(TTGJets, 1, SFee);   // Scale Factors
  scalehistograms(TTGJets, 2, SFmue);  // Scale Factors

  TTGJets=addhistograms(TTGJets); // All Channels


  for(int j=0; j<histos; j++){
    for(int k=0; k<5; k++){
      RareBkg.hist[j][k]=(TH1F*)TTZJets.hist[j][k]->Clone();
      RareBkg.hist[j][k]->Add(RareBkg.hist[j][k],TTWJets.hist[j][k]);
      RareBkg.hist[j][k]->Add(RareBkg.hist[j][k],WgammaToLNuG.hist[j][k]);
      RareBkg.hist[j][k]->Add(RareBkg.hist[j][k],ZgammaToLNuG.hist[j][k]);
      RareBkg.hist[j][k]->Add(RareBkg.hist[j][k],HWW125.hist[j][k]);
      RareBkg.hist[j][k]->Add(RareBkg.hist[j][k],WWGJets.hist[j][k]);
      RareBkg.hist[j][k]->Add(RareBkg.hist[j][k],TTGJets.hist[j][k]);
    }
  }

  for(int j=0; j<histos2D; j++){
    for(int k=0; k<5; k++){
      RareBkg.hist2D[j][k]=(TH2F*)TTZJets.hist2D[j][k]->Clone();
      RareBkg.hist2D[j][k]->Add(RareBkg.hist2D[j][k],TTWJets.hist2D[j][k]);
      RareBkg.hist2D[j][k]->Add(RareBkg.hist2D[j][k],WgammaToLNuG.hist2D[j][k]);
    }
  }

  setupdraw(RareBkg, kMagenta); //Select Histogram Color
  //////////////////////////////////////////////////////////

  if(SUSY){

    STop=loadhistograms(plots,files + "_Stop.root");

//     int NbinsSTop0 = STop.hist[0][0]->GetNbinsX() +1;    // to normalize stop to data
//     int NbinsSTop1 = STop.hist[0][1]->GetNbinsX() +1;
//     int NbinsSTop2 = STop.hist[0][2]->GetNbinsX() +1;
    
//     float NevtSTop_mumu = STop.hist[0][0]->Integral(1, NbinsSTop0 );
//     float NevtSTop_ee   = STop.hist[0][1]->Integral(1, NbinsSTop1 );
//     float NevtSTop_mue  = STop.hist[0][2]->Integral(1, NbinsSTop2 );
    
// //     cout << "STopScale_mumu = " << NevtData_mumu << "/" << NevtSTop_mumu << " = " << static_cast<float>(NevtData_mumu)/NevtSTop_mumu << endl;
// //     cout << "STopScale_ee = "   << NevtData_ee   << "/" << NevtSTop_ee   << " = " << static_cast<float>(NevtData_ee)/NevtSTop_ee     << endl;
// //     cout << "STopScale_mue = "  << NevtData_mue  << "/" << NevtSTop_mue  << " = " << static_cast<float>(NevtData_mue)/NevtSTop_mue   << endl;
// //     cout << "Data total = " << (NevtData_mumu + NevtData_ee + NevtData_mue) << endl;
// //     cout << "STop total = " << (NevtSTop_mumu + NevtSTop_ee + NevtSTop_mue) << endl;
    
//     float STopScale_mumu = static_cast<float>(NevtData_mumu)/NevtSTop_mumu; // to normalise stop signal MC to data 
//     float STopScale_ee   = static_cast<float>(NevtData_ee)/NevtSTop_ee;
//     float STopScale_mue  = static_cast<float>(NevtData_mue)/NevtSTop_mue;

    scalehistograms(STop, 0, SFmumu); // Scale Factors    
    scalehistograms(STop, 1, SFee);   // Scale Factors    
    scalehistograms(STop, 2, SFmue);  // Scale Factors

    // scalehistograms(STop, 0, STopScale_mumu);   // to normalize stop to data
    // scalehistograms(STop, 1, STopScale_ee);
    // scalehistograms(STop, 2, STopScale_mue);
    
    STop=addhistograms(STop);

    setupdraw(STop, 0);
  }

  /****************
    Normalization
   ***************/  

  if(EvtNorm){
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    cout << "!!!!Plots and yields normalized to DATA!!!" << endl;
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

    float EvData_mumu=Data.hist[5][0]->Integral();
    float EvData_ee  =Data.hist[5][1]->Integral();
    float EvData_mue =Data.hist[5][2]->Integral();
    
    float EvMC_mumu=TTbar.hist[5][0]->Integral() + SingleT.hist[5][0]->Integral() + NONWZ.hist[5][0]->Integral() + VV.hist[5][0]->Integral() + RareBkg.hist[5][0]->Integral();
    float EvMC_ee  =TTbar.hist[5][1]->Integral() + SingleT.hist[5][1]->Integral() + NONWZ.hist[5][1]->Integral() + VV.hist[5][1]->Integral() + RareBkg.hist[5][1]->Integral();
    float EvMC_mue =TTbar.hist[5][2]->Integral() + SingleT.hist[5][2]->Integral() + NONWZ.hist[5][2]->Integral() + VV.hist[5][2]->Integral() + RareBkg.hist[5][2]->Integral();
    
    float EvNorm_mumu = (EvData_mumu - Z.hist[5][0]->Integral())/EvMC_mumu;
    float EvNorm_ee   = (EvData_ee   - Z.hist[5][1]->Integral())/EvMC_ee;
    float EvNorm_mue  = (EvData_mue  - Z.hist[5][2]->Integral())/EvMC_mue;
    float EvNorm_mmee = (EvData_mumu + EvData_ee - Z.hist[5][0]->Integral() - Z.hist[5][1]->Integral())/(EvMC_mumu + EvMC_ee);
    float EvNorm_all  = (EvData_mumu + EvData_ee + EvData_mue - Z.hist[5][0]->Integral() - Z.hist[5][1]->Integral() - Z.hist[5][2]->Integral())/(EvMC_mumu + EvMC_ee + EvMC_mue);
    
    
    scalehistograms(TTbar, 0, EvNorm_mumu);
    scalehistograms(TTbar, 1, EvNorm_ee);
    scalehistograms(TTbar, 2, EvNorm_mue);
    scalehistograms(TTbar, 3, EvNorm_all);
    scalehistograms(TTbar, 4, EvNorm_mmee);
    
    scalehistograms(SingleT, 0, EvNorm_mumu);
    scalehistograms(SingleT, 1, EvNorm_ee);
    scalehistograms(SingleT, 2, EvNorm_mue);
    scalehistograms(SingleT, 3, EvNorm_all);
    scalehistograms(SingleT, 4, EvNorm_mmee);
    
    scalehistograms(NONWZ, 0, EvNorm_mumu);
    scalehistograms(NONWZ, 1, EvNorm_ee);
    scalehistograms(NONWZ, 2, EvNorm_mue);
    scalehistograms(NONWZ, 3, EvNorm_all);
    scalehistograms(NONWZ, 4, EvNorm_mmee);
    
    scalehistograms(VV, 0, EvNorm_mumu);
    scalehistograms(VV, 1, EvNorm_ee);	
    scalehistograms(VV, 2, EvNorm_mue);	
    scalehistograms(VV, 3, EvNorm_all);	
    scalehistograms(VV, 4, EvNorm_mmee);

    scalehistograms(RareBkg, 0, EvNorm_mumu);
    scalehistograms(RareBkg, 1, EvNorm_ee);
    scalehistograms(RareBkg, 2, EvNorm_mue);
    scalehistograms(RareBkg, 3, EvNorm_all);
    scalehistograms(RareBkg, 4, EvNorm_mmee);
  }  
  
  

  ////////////////////////////////////////////////////////////////////
  /////////////////////     THStack     //////////////////////////////
  ////////////////////////////////////////////////////////////////////

  for(int j=0; j<histos; j++){
    TString variable;
    for(int k=0; k<5; k++){
      MCStack.mc[j][k]=new THStack(variable, "");
      MCStack.mc[j][k]->SetHistogram(TTbar.hist[j][k]);
    }
  }

  for(int j=0; j<histos2D; j++){
    TString variable;
    for(int k=0; k<5; k++){
      MCStack.mc2D[j][k]=new TH2F(variable, "", TTbar.hist2D[j][k]->GetNbinsX(), TTbar.hist2D[j][k]->GetXaxis()->GetXmin(), TTbar.hist2D[j][k]->GetXaxis()->GetXmax(), TTbar.hist2D[j][k]->GetNbinsY(), TTbar.hist2D[j][k]->GetYaxis()->GetXmin(), TTbar.hist2D[j][k]->GetYaxis()->GetXmax());
      //MCStack.mc2D[j][k]=new TH2F(TTbar.hist2D[j][k]);
      //MCStack.mc2D[j][k]->SetHistogram(TTbar.hist2D[j][k]);
    }
  }


  ////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////

//  MCStack=addstack(MCStack,VV);

  MCStack=addstack(MCStack,NONWZ);

  MCStack=addstack(MCStack,VV);

  MCStack=addstack(MCStack,RareBkg);

  MCStack=addstack(MCStack,SingleT);

 // MCStack=addstack(MCStack,VV);

  MCStack=addstack(MCStack,Z);

  MCStack=addstack(MCStack,TTbar);

//  MCStack=addstack(MCStack,Z);

//  MCStack=addstack(MCStack,SingleT);

//  MCStack=addstack(MCStack,NONWZ);

//  MCStack=addstack(MCStack,VV);



  ///////////////////////////////////////////////////////////////////

  TCanvas *cPlots[20]; //it was 12  //histos
  
  for(int i=0;i<histos;i++){
    char can[200];
    sprintf(can,"canvas%i",i);
    cPlots[i]=new TCanvas(can,"Preselection Plots");
    cPlots[i]->Divide(1,2);  
  }
  
  TLegend *leg[20];  //it was 12
  TPad    *pad[20][2];  //it was 12

  for(int i=0; i<histos; i++){

    leg[i]=createlegend(leg[i],plots);//each Plot
    
    //Plot Pad
    pad[i][0] = (TPad*)cPlots[i]->GetPad(1); 
    pad[i][0]->SetPad(0.01, 0.25, 0.99, 0.96);
    pad[i][0]->SetTopMargin(0.1);
    pad[i][0]->SetRightMargin(0.04);
    
    //Division Pad
    pad[i][1] = (TPad*)cPlots[i]->GetPad(2);
    pad[i][1]->SetPad(0.01, 0.02, 0.99, 0.30);
    pad[i][1]->SetGridx();
    pad[i][1]->SetGridy();
    pad[i][1]->SetTopMargin(0.01);
    pad[i][1]->SetBottomMargin(0.4);
    pad[i][1]->SetRightMargin(0.04);
    
    pad[i][0]->cd();

    gPad->SetLogy(1); 
    
    TString htitleCMS=Data.hist[i][ch]->GetTitle();
    if(ch==3) htitleCMS = htitleCMS + " all channels";
    if(ch==4) htitleCMS = htitleCMS + " #mu#muee channel";
    else htitleCMS = htitleCMS + " channel";
 
    MCStack.mc[i][ch]->Draw("hist");
    MCStack.mc[i][ch]->GetYaxis()->SetTitle("Events");
    MCStack.mc[i][ch]->GetYaxis()->SetTitleOffset(0.9);
    MCStack.mc[i][ch]->GetYaxis()->SetTitleSize(0.08);
    MCStack.mc[i][ch]->GetYaxis()->SetLabelSize(0.08);
    MCStack.mc[i][ch]->GetXaxis()->SetLabelSize(0.0);
    MCStack.mc[i][ch]->GetXaxis()->SetTitle("");
    MCStack.mc[i][ch]->SetMinimum(0.1);   
 
    Data.hist[i][ch]->Sumw2();
    Data.hist[i][ch]->SetMarkerStyle(20);
    Data.hist[i][ch]->Draw("SAME");

    // Number of events in the Legend
    leg[i]=addlegend(leg[i],"Data      ", Data.hist[i][ch]);
    leg[i]=addlegend(leg[i],"VV        ", VV.hist[i][ch]);
    leg[i]=addlegend(leg[i],"RareBkg   ", RareBkg.hist[i][ch]);
    leg[i]=addlegend(leg[i],"Non W/Z   ", NONWZ.hist[i][ch]);
    leg[i]=addlegend(leg[i],"Single Top", SingleT.hist[i][ch]);
    leg[i]=addlegend(leg[i],"Z/#gamma* l^{+}l^{-}  ", Z.hist[i][ch]);
    leg[i]=addlegend(leg[i],"t#bar{t}        ", TTbar.hist[i][ch]);

    if(SUSY){
      STop.hist[i][ch]->SetLineStyle(9);
      STop.hist[i][ch]->SetLineWidth(2);
      STop.hist[i][ch]->SetLineColor(3);
      STop.hist[i][ch]->Draw("SAME");
    }
    
    //leg[i]=addlegend(leg[i],"Data", Data.hist[i][ch]);
    //leg[i]=addlegend(leg[i],"VV", VV.hist[i][ch]);
    //leg[i]=addlegend(leg[i],"Non W/Z", NONWZ.hist[i][ch]);
    //leg[i]=addlegend(leg[i],"Single Top", SingleT.hist[i][ch]);
    //leg[i]=addlegend(leg[i],"Z/#gamma* l^{+}l^{-}", Z.hist[i][ch]);
    //leg[i]=addlegend(leg[i],"t#bar{t}", TTbar.hist[i][ch]);
    if(SUSY) leg[i]=addlegend(leg[i],"Stop    ", STop.hist[i][ch]);
    leg[i]->Draw("SAME");
    
    float maxh=Data.hist[i][ch]->GetMaximum();
    if(maxh<MCStack.mc[i][ch]->GetMaximum()) maxh=MCStack.mc[i][ch]->GetMaximum();
    MCStack.mc[i][ch]->SetMaximum(1.7*maxh);
    
    /******************************************
     ******************************************
                  Uncertainties
    *******************************************
    *******************************************/

    TH1F *totalmc = (TH1F*) MCStack.mc[i][ch]->GetStack()->Last()->Clone();

    for (int nbin=0; nbin<totalmc->GetNbinsX(); nbin++){


      /***************************
       Theoretical  Uncertainties
      ***************************/

      float ThTTbarUnc=sqrt((TTbar.hist[i][ch]->GetBinContent(nbin+1)*theoryQ2_error)*
			    (TTbar.hist[i][ch]->GetBinContent(nbin+1)*theoryQ2_error)+
			    (TTbar.hist[i][ch]->GetBinContent(nbin+1)*theoryMatching_error)*
			    (TTbar.hist[i][ch]->GetBinContent(nbin+1)*theoryMatching_error)			   
			    );
      
      float ThSingleTUnc=sqrt((SingleT.hist[i][ch]->GetBinContent(nbin+1)*theoryQ2_error)*
			      (SingleT.hist[i][ch]->GetBinContent(nbin+1)*theoryQ2_error)+
			      (SingleT.hist[i][ch]->GetBinContent(nbin+1)*theoryMatching_error)*
			      (SingleT.hist[i][ch]->GetBinContent(nbin+1)*theoryMatching_error)			   
			      );
      
      float ThVVUnc=sqrt((VV.hist[i][ch]->GetBinContent(nbin+1)*theoryQ2_error)*
			 (VV.hist[i][ch]->GetBinContent(nbin+1)*theoryQ2_error)+
			 (VV.hist[i][ch]->GetBinContent(nbin+1)*theoryMatching_error)*
			 (VV.hist[i][ch]->GetBinContent(nbin+1)*theoryMatching_error)			   
			 );

      float ThRareBkgUnc=sqrt((RareBkg.hist[i][ch]->GetBinContent(nbin+1)*theoryQ2_error)*
                              (RareBkg.hist[i][ch]->GetBinContent(nbin+1)*theoryQ2_error)+
                              (RareBkg.hist[i][ch]->GetBinContent(nbin+1)*theoryMatching_error)*
                              (RareBkg.hist[i][ch]->GetBinContent(nbin+1)*theoryMatching_error)
                             );

      float ThTotalUnc=sqrt(ThTTbarUnc*ThTTbarUnc + ThSingleTUnc*ThSingleTUnc + ThVVUnc*ThVVUnc + ThRareBkgUnc*ThRareBkgUnc);
      
      /***************************
           Other Uncertainties
      ***************************/
    
      float LumUnc=totalmc->GetBinContent(nbin+1)*lumi_error;

      float XsecTTbarUnc=sqrt((TTbar.hist[i][ch]->GetBinContent(nbin+1)*SF_BR_uncer)*(TTbar.hist[i][ch]->GetBinContent(nbin+1)*SF_BR_uncer) + (TTbar.hist[i][ch]->GetBinContent(nbin+1)*XsecTTbar_uncer )*(TTbar.hist[i][ch]->GetBinContent(nbin+1)*XsecTTbar_uncer));
      float XsecSingleTUnc=SingleT.hist[i][ch]->GetBinContent(nbin+1)*XsecTWVV_uncer;
      float XsecVVUnc=VV.hist[i][ch]->GetBinContent(nbin+1)*XsecTWVV_uncer;
      float XsecRareBkgUnc=RareBkg.hist[i][ch]->GetBinContent(nbin+1)*XsecTWVV_uncer;
      float XsecTotalUnc=sqrt(XsecTTbarUnc*XsecTTbarUnc + XsecSingleTUnc*XsecSingleTUnc + XsecVVUnc*XsecVVUnc + XsecRareBkgUnc*XsecRareBkgUnc);
		      
      float PUUnc=totalmc->GetBinContent(nbin+1)*PU_uncer;

      float SFIDISOUnc=totalmc->GetBinContent(nbin+1)*lept_uncer;

      float DYDDUnc= Z.hist[i][ch]->GetBinContent(nbin+1)*dd_dd_uncer;
		        
      float btagUnc;
      
      if(i==6 && plots=="1btag"){//btag Plot
	for (int nbtagbin = 0; nbtagbin<5; nbtagbin++) SF_uncer[nbtagbin] = 0.;
	//Nov 30 (Systematics.ods)
	// SF_uncer[0] = 0.157;
	// SF_uncer[1] = 0.050;
	// SF_uncer[2] = 0.045;
	// SF_uncer[3] = 0.111;
	// SF_uncer[4] = 0.111;//Temporal

	//Dic 20 (Systematics.ods)
	SF_uncer[0] = 0.159;
	SF_uncer[1] = 0.049;
	SF_uncer[2] = 0.046;
	SF_uncer[3] = 0.109;
	SF_uncer[4] = 0.198;

	btagUnc=TTbar.hist[i][ch]->GetBinContent(nbin+1)*SF_uncer[nbin];

      }//if(btag plot)
      else btagUnc=0.0;      

      float EnergyUnc=sqrt((totalmc->GetBinContent(nbin+1)*LES_uncer)*
			   (totalmc->GetBinContent(nbin+1)*LES_uncer) +
			   (totalmc->GetBinContent(nbin+1)*JES_uncer)*
			   (totalmc->GetBinContent(nbin+1)*JES_uncer) +
			   (totalmc->GetBinContent(nbin+1)*JER_uncer)*
			   (totalmc->GetBinContent(nbin+1)*JER_uncer)
			   );

      float PlotUncer=0.0;
      // if (plots=="dilepton") PlotUncer=sqrt(totalmc->GetBinError(nbin+1)*totalmc->GetBinError(nbin+1) + LumUnc*LumUnc + PUUnc*PUUnc + SFIDISOUnc*SFIDISOUnc + XsecTotalUnc*XsecTotalUnc );
      // if (plots=="2Jets")    PlotUncer=sqrt(totalmc->GetBinError(nbin+1)*totalmc->GetBinError(nbin+1) + LumUnc*LumUnc + PUUnc*PUUnc + SFIDISOUnc*SFIDISOUnc + XsecTotalUnc*XsecTotalUnc + DYDDUnc*DYDDUnc);
      // if (plots=="MET")      PlotUncer=sqrt(totalmc->GetBinError(nbin+1)*totalmc->GetBinError(nbin+1) + LumUnc*LumUnc + PUUnc*PUUnc + SFIDISOUnc*SFIDISOUnc + XsecTotalUnc*XsecTotalUnc + DYDDUnc*DYDDUnc);
      // if (plots=="1btag" || (plots=="MET" && i==6))    PlotUncer=sqrt(totalmc->GetBinError(nbin+1)*totalmc->GetBinError(nbin+1) + LumUnc*LumUnc + PUUnc*PUUnc + SFIDISOUnc*SFIDISOUnc + XsecTotalUnc*XsecTotalUnc + DYDDUnc*DYDDUnc + EnergyUnc*EnergyUnc + btagUnc*btagUnc);

      if (plots=="dilepton") PlotUncer=totalmc->GetBinError(nbin+1);
      if (plots=="2Jets")    PlotUncer=totalmc->GetBinError(nbin+1);
      if (plots=="MET")      PlotUncer=totalmc->GetBinError(nbin+1);
      //if (plots=="1btag" || (plots=="MET" && i==6)) PlotUncer=sqrt(totalmc->GetBinError(nbin+1)*totalmc->GetBinError(nbin+1) + btagUnc*btagUnc);
      if (plots == "MT2ll" || plots=="1btag" || (plots=="MET" && i==6)) PlotUncer=sqrt(totalmc->GetBinError(nbin+1)*totalmc->GetBinError(nbin+1) + btagUnc*btagUnc);
      
      totalmc->SetBinError(nbin+1,PlotUncer);
    }

    TGraphErrors *thegraph = new TGraphErrors(totalmc);
    thegraph->SetFillStyle(3004);
    thegraph->SetFillColor(1);

    thegraph->Draw("e2SAME");

    /***********************
             Ratio
     **********************/

    pad[i][1]->cd();
    
    TH1F *Ra;
    Ra=(TH1F*)Data.hist[i][ch]->Clone();
    Ra->Divide(totalmc);
    ratio.hist[i][ch]=Ra;
    
    ratio.hist[i][ch]->SetMarkerStyle(20);
    ratio.hist[i][ch]->SetMarkerColor(1);
    ratio.hist[i][ch]->SetLineColor(0);
    ratio.hist[i][ch]->SetMaximum(2);
    ratio.hist[i][ch]->SetMinimum(0);
    ratio.hist[i][ch]->SetTitle("");

    //ratio.hist[i][ch]->GetYaxis()->SetTitle("Obs/Exp Ratio");
    ratio.hist[i][ch]->GetYaxis()->SetTitle("Obs/Exp");
    ratio.hist[i][ch]->GetYaxis()->CenterTitle();
    ratio.hist[i][ch]->GetYaxis()->SetTitleOffset(0.4);
    ratio.hist[i][ch]->GetYaxis()->SetTitleSize(0.16);
    ratio.hist[i][ch]->GetYaxis()->SetLabelSize(0.19);
    ratio.hist[i][ch]->GetYaxis()->SetNdivisions(605);
    ratio.hist[i][ch]->GetXaxis()->SetTitleOffset(0.9);
    ratio.hist[i][ch]->GetXaxis()->SetLabelSize(0.21);
    ratio.hist[i][ch]->GetXaxis()->SetTitleSize(0.18);

    ratio.hist[i][ch]->SetMinimum(0.5);
    ratio.hist[i][ch]->SetMaximum(1.79);

    ratio.hist[i][ch]->Draw();

    TGraphErrors *thegraphRatio = new TGraphErrors(ratio.hist[i][ch]);
    thegraphRatio->SetFillStyle(3001);
    thegraphRatio->SetFillColor(1);

    thegraphRatio->Draw("e2SAME");


    /***********************
           CMS Legend
     **********************/
    cPlots[i]->cd();
    pad[i][0]->cd();
    if(plots=="dilepton" && (i==3 || i==6) ) pad[i][0]->SetLogy();

    title  = new TLatex(20.,50.,"#splitline{" + htitleCMS + "}{CMS preliminary, 19.6 fb^{-1} @ #sqrt{s}=8TeV}");
    title->SetNDC();
    title->SetTextAlign(12);
    title->SetX(0.245);
    //title->SetY(0.784);
    title->SetY(0.90);
    title->SetTextFont(42);
    title->SetTextSize(0.050);
    title->SetTextSizePixels(24);
    title->Draw("SAME");

    TString dirfigname_eps=dirnameIn + "figures/eps/";
    TString dirfigname_pdf=dirnameIn + "figures/pdf/";
    // make a dir if it does not exist!!
    gSystem->mkdir(dirfigname_eps,       kTRUE);
    gSystem->mkdir(dirfigname_pdf,       kTRUE);

    char fig[200];
    sprintf(fig,"f_%s",TTbar.hist[i][ch]->GetName());

    if(ch==3){ // Change the name!
      for(int c=0;c<199;c++){
	if(fig[c]=='m' && fig[c+1]=='u'){ 
	  fig[c]='c';	
	  fig[c+1]='a';	
	  fig[c+2]='l';	
	  fig[c+3]='l';	
	}
      }
    }//if(channel=all)

    if(ch==4){ // Change the name!
      for(int c=0;c<199;c++){
	if(fig[c]=='m' && fig[c+1]=='u'){ 
	  fig[c+1]='m';	
	  fig[c+2]='e';	
	  fig[c+3]='e';	
	}
      }
    }//if(channel=mmee)

    dirfigname_eps=dirfigname_eps + fig;
    dirfigname_pdf=dirfigname_pdf + fig;
    cPlots[i]->SaveAs(dirfigname_eps + ".eps");
    cPlots[i]->SaveAs(dirfigname_pdf + ".pdf");

  }//for(histograms)

  //FG new part for TH2 plots!

  TCanvas *cPlots2D[3]; //histos2D

  for(int i=0;i<histos2D;i++){
    char can2D[200];
    sprintf(can2D,"canvas2D%i",i);
    cPlots2D[i]=new TCanvas(can2D,"Preselection Plots");
    //    cPlots2D[i]->Divide(1,2);  
  }

  TLegend *leg2D[3];  //it was 12
  //TPad    *pad[1][2];  //it was 12

  for(int i=0; i<histos2D; i++){
    
    cPlots2D[i]->cd();

    leg2D[i]=createlegend2D(leg2D[i],plots);//each Plot

    TString htitleCMS=Data.hist2D[i][ch]->GetTitle();
    if(ch==3) htitleCMS = htitleCMS + " all channels";
    if(ch==4) htitleCMS = htitleCMS + " #mu#muee channel";
    else htitleCMS = htitleCMS + " channel";

    MCStack.mc2D[i][ch]->SetLineColor(kRed); 
    MCStack.mc2D[i][ch]->Draw("CONT3");
    
    MCStack.mc2D[i][ch]->GetXaxis()->SetTitle("MT_{2}(ll) (GeV)");
    //    MCStack.mc2D[i][ch]->GetYaxis()->SetTitle("MT_{2}(lb) (GeV)");  
    if (i==0) MCStack.mc2D[i][ch]->GetYaxis()->SetTitle("MT_{2}(lb) (GeV)");
    if (i==1) MCStack.mc2D[i][ch]->GetYaxis()->SetTitle("MT_{2}(bb) (GeV)");
    if (i==2) MCStack.mc2D[i][ch]->GetYaxis()->SetTitle("MT_{2}(llbb) (GeV)");
    MCStack.mc2D[i][ch]->GetYaxis()->SetTitleOffset(1.1);
    //  MCStack.mc2D[i][ch]->GetYaxis()->SetTitleSize(0.08);
    // MCStack.mc2D[i][ch]->GetYaxis()->SetLabelSize(0.08);
    //MCStack.mc2D[i][ch]->GetXaxis()->SetLabelSize(0.0);
  
    Data.hist2D[i][ch]->Sumw2();
    //Data.hist2D[i][ch]->SetMarkerStyle(20);
    Data.hist2D[i][ch]->SetLineColor(kBlack);
    Data.hist2D[i][ch]->Draw("SAMECONT3");

    if(SUSY){
      // STop.hist2D[i][ch]->SetLineStyle(9);
      //STop.hist2D[i][ch]->SetLineWidth(2);
      STop.hist2D[i][ch]->SetLineColor(kGreen);
      STop.hist2D[i][ch]->Draw("SAMECONT3");
    }
    MCStack.mc2D[i][ch]->Draw("SAMECONT3Z");

    leg2D[i]=addlegend2D(leg2D[i],"Data", Data.hist2D[i][ch]);
    leg2D[i]=addlegend2D(leg2D[i],"MC", MCStack.mc2D[i][ch]);
    if(SUSY) leg2D[i]=addlegend2D(leg2D[i],"Stop    ", STop.hist2D[i][ch]);
    leg2D[i]->Draw("SAME");

    float maxh2D=Data.hist2D[i][ch]->GetMaximum();
    if(maxh2D<MCStack.mc2D[i][ch]->GetMaximum()) maxh2D=MCStack.mc2D[i][ch]->GetMaximum();
    MCStack.mc2D[i][ch]->SetMaximum(1.7*maxh2D);

    //gPad->SetLogz(1);

    if(plots=="dilepton" && (i==3 || i==6) ) pad[i][0]->SetLogy();

    title  = new TLatex(20.,50.,"#splitline{" + htitleCMS + "}{CMS preliminary, 19.6 fb^{-1} @ #sqrt{s}=8TeV}");
    title->SetNDC();
    title->SetTextAlign(12);
    title->SetX(0.245);
    title->SetY(0.90);
    title->SetTextFont(42);
    title->SetTextSize(0.040);
    title->SetTextSizePixels(20);
    title->Draw("SAME");

    TString dirfigname_eps=dirnameIn + "figures/eps/";
    TString dirfigname_pdf=dirnameIn + "figures/pdf/";
    // make a dir if it does not exist!!
    gSystem->mkdir(dirfigname_eps,       kTRUE);
    gSystem->mkdir(dirfigname_pdf,       kTRUE);

    char fig[200];
    sprintf(fig,"f_%s",TTbar.hist2D[i][ch]->GetName());

    if(ch==3){ // Change the name!
      for(int c=0;c<199;c++){
        if(fig[c]=='m' && fig[c+1]=='u'){
          fig[c]='c';
          fig[c+1]='a';
          fig[c+2]='l';
          fig[c+3]='l';
        }
      }
    }//if(channel=all)

    if(ch==4){ // Change the name!
      for(int c=0;c<199;c++){
        if(fig[c]=='m' && fig[c+1]=='u'){
          fig[c+1]='m';
          fig[c+2]='e';
          fig[c+3]='e';
        }
      }
    }//if(channel=mmee)

    dirfigname_eps=dirfigname_eps + fig;
    dirfigname_pdf=dirfigname_pdf + fig;
    cPlots2D[i]->SaveAs(dirfigname_eps + ".eps");
    cPlots2D[i]->SaveAs(dirfigname_pdf + ".pdf");

  }//for(histograms 2D)

/*****************************************/
  // MS addition for FOM
/*****************************************/

  TCanvas *cFOM2D[3]; //histos2D
  
  for(int i=0;i<histos2D;i++)
    {
      char canFOM2D[200];
      sprintf(canFOM2D,"canvas_FOM_2D%i",i);
      cFOM2D[i]=new TCanvas(canFOM2D,"Preselection Plots - FOM");
    }
  
  TH2F *histoFOM2D[3][5];
  
  for(int i=0; i<histos2D; i++)
    {
      for(int k=0; k<5; k++)
	{
	  histoFOM2D[i][k]= createFOM (MCStack.mc2D[i][k], STop.hist2D[i][k]) ;
	}
    }
  
  for(int i=0; i<histos2D; i++){
    
    cFOM2D[i]->cd();

    TString htitleCMS=Data.hist2D[i][ch]->GetTitle();
    if(ch==3) htitleCMS = htitleCMS + " all channels";
    if(ch==4) htitleCMS = htitleCMS + " #mu#muee channel";
    else htitleCMS = htitleCMS + " channel";
    
    histoFOM2D[i][ch]->GetXaxis()->SetTitle(MCStack.mc2D[i][ch]->GetXaxis()->GetTitle());
    histoFOM2D[i][ch]->GetYaxis()->SetTitle(MCStack.mc2D[i][ch]->GetYaxis()->GetTitle());  
    histoFOM2D[i][ch]->GetYaxis()->SetTitleOffset(1.1);
    histoFOM2D[i][ch]->GetZaxis()->SetRangeUser(0.1,0.9);

    histoFOM2D[i][ch]->Draw("colz") ;

    if(plots=="dilepton" && (i==3 || i==6) ) pad[i][0]->SetLogy();

    title  = new TLatex(20.,50.,"#splitline{" + htitleCMS + "}{CMS preliminary, 19.6 fb^{-1} @ #sqrt{s}=8TeV}");
    title->SetNDC();
    title->SetTextAlign(12);
    title->SetX(0.245);
    title->SetY(0.90);
    title->SetTextFont(42);
    title->SetTextSize(0.040);
    title->SetTextSizePixels(20);
    title->Draw("SAME");

    TString dirfigname_eps=dirnameIn + "figures/eps/";
    TString dirfigname_pdf=dirnameIn + "figures/pdf/";
    // make a dir if it does not exist!!
    gSystem->mkdir(dirfigname_eps,       kTRUE);
    gSystem->mkdir(dirfigname_pdf,       kTRUE);

    char fig[200];
    sprintf(fig,"f_%s",TTbar.hist2D[i][ch]->GetName());

    if(ch==3){ // Change the name!
      for(int c=0;c<199;c++){
        if(fig[c]=='m' && fig[c+1]=='u'){
          fig[c]='c';
          fig[c+1]='a';
          fig[c+2]='l';
          fig[c+3]='l';
        }
      }
    }//if(channel=all)

    if(ch==4){ // Change the name!
      for(int c=0;c<199;c++){
        if(fig[c]=='m' && fig[c+1]=='u'){
          fig[c+1]='m';
          fig[c+2]='e';
          fig[c+3]='e';
        }
      }
    }//if(channel=mmee)

    dirfigname_eps=dirfigname_eps + fig;
    dirfigname_pdf=dirfigname_pdf + fig;
    cFOM2D[i]->SaveAs(dirfigname_eps + "_fom.eps");
    cFOM2D[i]->SaveAs(dirfigname_pdf + "_fom.pdf");


}


  /***********************
       LaTex Yields
  **********************/
  //int pt=5;//NJets Plot
  int pt=3;//NbtagJets Plot
  float VV_err     =sqrt(VV.hist[pt][ch]->GetEntries())*VV.hist[pt][ch]->Integral()/VV.hist[pt][ch]->GetEntries();
  float RareBkg_err=sqrt(RareBkg.hist[pt][ch]->GetEntries())*RareBkg.hist[pt][ch]->Integral()/RareBkg.hist[pt][ch]->GetEntries();
  float TTbar_err  =sqrt(TTbar.hist[pt][ch]->GetEntries())*TTbar.hist[pt][ch]->Integral()/TTbar.hist[pt][ch]->GetEntries();
  float SingleT_err=sqrt(SingleT.hist[pt][ch]->GetEntries())*SingleT.hist[pt][ch]->Integral()/SingleT.hist[pt][ch]->GetEntries();
  float NONWZ_err  =sqrt(NONWZ.hist[pt][ch]->GetEntries())*NONWZ.hist[pt][ch]->Integral()/NONWZ.hist[pt][ch]->GetEntries();
  
  float STop_err=0.;
  if(SUSY) STop_err=sqrt(STop.hist[pt][ch]->GetEntries())*STop.hist[pt][ch]->Integral()/STop.hist[pt][ch]->GetEntries();

  //mue DD (30%)
  DY_DD_mue_err = dd_dd_uncer * ZDY.hist[pt][ch]->Integral();

  float DY_DD_err;

  if(channel=="mumu")      DY_DD_err = DY_DD_mumu_err;
  else if(channel=="ee")   DY_DD_err = DY_DD_ee_err;
  else if(channel=="mue")  DY_DD_err = DY_DD_mue_err;
  else if(channel=="mmee") DY_DD_err = sqrt(DY_DD_mumu_err*DY_DD_mumu_err + DY_DD_ee_err*DY_DD_ee_err);
  else if(channel=="all")  DY_DD_err = sqrt(DY_DD_mumu_err*DY_DD_mumu_err + DY_DD_ee_err*DY_DD_ee_err + DY_DD_mue_err*DY_DD_mue_err);

  if(plots=="dilepton") DY_DD_err = sqrt(Z.hist[pt][ch]->GetEntries())*Z.hist[pt][ch]->Integral()/Z.hist[pt][ch]->GetEntries();

  float Total_err=sqrt(VV_err*VV_err+RareBkg_err*RareBkg_err+TTbar_err*TTbar_err+SingleT_err*SingleT_err+NONWZ_err*NONWZ_err+DY_DD_err*DY_DD_err);

  TString dirtexname=dirnameIn + "tex/";
  // make a dir if it does not exist!!
  gSystem->mkdir(dirtexname,       kTRUE);

  TString texfile=dirtexname + "Yields_" + plots + "_" +channel + ".tex";

  FILE* fyout = fopen(texfile, "w");

  fprintf(fyout,"\{\\tiny\n");
  
  if(SUSY){
    fprintf(fyout,"\\begin\{tabular\}\{\|c\|c\|c\|c\|c\|c\|c\|c\|c\|\}\\hline\n");
    fprintf(fyout," Cut & Data & Total MC & \$ t\\bar\{t\}\_\{Sig\} \$ & \$ Z+Jets \$ & \$ tW \$ & \$ VV \$ RareBkg \$ & Non W/Z & \$Stop\$ \\\\\\hline\\hline\n");
  }
  else{

    fprintf(fyout,"\\begin\{tabular\}\{\|c\|c\|c\|c\|c\|c\|c\|c\|\}\\hline\n");
    fprintf(fyout," Cut & Data & Total MC & \$ t\\bar\{t\}\_\{Sig\} \$ & \$ Z+Jets \$ & \$ tW \$ & \$ VV \$ RareBkg \$ & Non W/Z \\\\\\hline\\hline\n");
  }
  fprintf(fyout," %s & ",plots.Data());
  fprintf(fyout," \$ %i \$ &",Data.hist[pt][ch]->Integral());
  fprintf(fyout," \$ %8.1f \\pm %6.1f \$ &",TTbar.hist[pt][ch]->Integral()+Z.hist[pt][ch]->Integral()+
	  SingleT.hist[pt][ch]->Integral()+VV.hist[pt][ch]->Integral()+ RareBkg.hist[pt][ch]->Integral() +
	  NONWZ.hist[pt][ch]->Integral(),Total_err);
  fprintf(fyout," \$ %8.1f \\pm %6.1f \$ &",TTbar.hist[pt][ch]->Integral(),TTbar_err);
  fprintf(fyout," \$ %8.1f \\pm %6.1f \$ &",Z.hist[pt][ch]->Integral(),DY_DD_err);
  fprintf(fyout," \$ %8.1f \\pm %6.1f \$ &",SingleT.hist[pt][ch]->Integral(),SingleT_err);
  fprintf(fyout," \$ %8.1f \\pm %6.1f \$ &",VV.hist[pt][ch]->Integral(),VV_err);
  fprintf(fyout," \$ %8.1f \\pm %6.1f \$ &",RareBkg.hist[pt][ch]->Integral(),RareBkg_err);
  fprintf(fyout," \$ %8.1f \\pm %6.1f \$ ",NONWZ.hist[pt][ch]->Integral(),NONWZ_err);
  
  if(SUSY) fprintf(fyout," & \$%8.1f \\pm %6.1f\$",STop.hist[pt][ch]->Integral(),STop_err);

  fprintf(fyout,"\\\\\\hline\n");
  fprintf(fyout,"\\end\{tabular\}\n");
  fprintf(fyout,"\}\n");
  fclose(fyout);

}

/////////////////  Functions  //////////////////////

/****************/
/*  MS addition */
/****************/

TH2F* createFOM (TH2F *bkg , TH2F *sig) {
  
  TH2F *rap = new TH2F("","",bkg->GetNbinsX(), bkg->GetXaxis()->GetXmin(), bkg->GetXaxis()->GetXmax(), bkg->GetNbinsY(), bkg->GetYaxis()->GetXmin(), bkg->GetYaxis()->GetXmax()) ;
  
  int nx = rap->GetNbinsX();
  int ny = rap->GetNbinsY();
  
  for (int i = 1 ; i <= nx ; i++)
    {
      for (int j = 1 ; j <= ny ; j++)
	{
	  
	  // Alternatives: AND / OR
	  
	  // AND-kind of filling: uncomment next two lines
	  
	  double s = sig->Integral(i, nx+1, j , ny+1) ;
	  double b = bkg->Integral(i, nx+1, j , ny+1) ;
	  
	  // OR-kind of filling: uncomment next two lines
	  
	  //	double s = sig->Integral(i, nx, j , ny ) +  sig->Integral(0, i, j , ny )  + sig->Integral(i, nx, 0 , j );
	  //	double b = bkg->Integral(i, nx, j , ny ) +  bkg->Integral(0, i, j , ny )  + bkg->Integral(i, nx, 0 , j );
	  
	double r ;
	if ((s+b)>0) 
	  r = s / sqrt(s+b) ;
	else 
	  r = 0 ;
	//r = s;
	rap->SetBinContent(i,j,r) ;
	}
    }
  
return rap ;
}

/***************/


TLegend* createlegend(TLegend *leg, TString plots=""){

  float legx1=0.75; // Yield in the legend
  //float legx1=0.80;
  float legy1=0.65;
  float legx2=0.99;
  float legy2=0.99;

  //if(plots=="dilepton") legx1=0.75;

  leg = new TLegend(legx1,legy1,legx2,legy2);
  //leg->SetTextAlign(32);
  leg->SetFillColor(0);
  leg->SetLineColor(1);
  //leg->SetTextFont(102);
  leg->SetTextSize(0.05);

  return leg;
}

TLegend* createlegend2D(TLegend *leg, TString plots=""){

  float legx1=0.75; // Yield in the legend
  float legy1=0.85;
  float legx2=0.99;
  float legy2=0.99;

  leg = new TLegend(legx1,legy1,legx2,legy2);
  //leg->SetTextAlign(32);
  leg->SetFillColor(0);
  leg->SetLineColor(1);
  //leg->SetTextFont(102);
  leg->SetTextSize(0.04);

  return leg;
}

TLegend* addlegend(TLegend *leg, TString name, TH1* histo){

  //Number of events
  /////////////////////////////////////////////
  char com[200];

  sprintf(com,"%i",(histo->Integral()));

  int cn=0;
  for(int i=0;i<200;i++){
    cn++;
    if(com[i]=='\0') break;
  }

  cn=6-cn;
  for(int i=0;i<cn;i++){
    name=name+" ";
  }
 
  name=name+com;
  ////////////////////////////////////////////

  if(name.Contains("Data") || name.Contains("STop")) leg->AddEntry(histo,name,"PL");
  else leg->AddEntry(histo,name,"F");

  return leg;
}

TLegend* addlegend2D(TLegend *leg, TString name, TH2* histo){

  if(name.Contains("Data") || name.Contains("STop")) leg->AddEntry(histo,name,"PL");
  else leg->AddEntry(histo,name,"F");

  return leg;
}


Histograms addhistogram(Histograms histo, Histograms histoIn){
  
  int histos=20; // it was 12;
  int histos2D=3;   // FG addition

    for(int j=0; j<histos; j++){
      for(int k=0; k<5; k++){
	histo.hist[j][k]->Add(histo.hist[j][k],histoIn.hist[j][k]);	
      }
    }
    for(int j=0; j<histos2D; j++){
      for(int k=0; k<5; k++){
	histo.hist2D[j][k]->Add(histo.hist2D[j][k],histoIn.hist2D[j][k]);	
      }
    }

  return histo;

}

Histograms addstack(Histograms stack, Histograms histoIn){

  int histos=20;   // it was 12;
  int histos2D=3;   // FG addition

  for(int j=0; j<histos; j++){
    for(int k=0; k<5; k++){
      stack.mc[j][k]->Add(histoIn.hist[j][k]);	
    }
  }
  for(int j=0; j<histos2D; j++){
    for(int k=0; k<5; k++){
      stack.mc2D[j][k]->Add(stack.mc2D[j][k],histoIn.hist2D[j][k]);	
    }
  }
  return stack;
}

void setupdraw(Histograms h, int color) {

  int histos=20;   // it was 12;

  int bin[20]=1.;//histos

  for(int j=0; j<histos; j++){
    for(int k=0; k<5; k++){
      
      //h.hist[j][k]->Rebin(bin[j]);

      h.hist[j][k]->GetXaxis()->SetTitle("GeV");
      TString htitle=h.hist[j][k]->GetTitle();
      if(htitle.Contains("Multiplicity")) h.hist[j][k]->GetXaxis()->SetTitle("Number of Jets");
      if(htitle.Contains("#Phi")) h.hist[j][k]->GetXaxis()->SetTitle("rad"); 
      if(htitle.Contains("PV")) h.hist[j][k]->GetXaxis()->SetTitle("PV");
      h.hist[j][k]->SetLineColor(1);
      h.hist[j][k]->SetFillColor(color);
      h.hist[j][k]->SetFillStyle(1001);
      h.hist[j][k]->SetBinContent(h.hist[j][k]->GetNbinsX(),
				     (h.hist[j][k]->GetBinContent(h.hist[j][k]->GetNbinsX()+1)+h.hist[j][k]->GetBinContent(h.hist[j][k]->GetNbinsX())));
      h.hist[j][k]->SetBinContent(h.hist[j][k]->GetNbinsX()+1,0);
    }
  }
  
  
}

Histograms addhistograms(Histograms histoIn){
  
  int histos=20;    // it was 12;
  int histos2D=3;   // FG addition
  
  for(int j=0; j<histos; j++){
    histoIn.hist[j][3]=(TH1F*)histoIn.hist[j][0]->Clone();
    histoIn.hist[j][4]=(TH1F*)histoIn.hist[j][0]->Clone();
    
    TString htitle=histoIn.hist[j][0]->GetTitle();
    htitle.Resize(htitle.Sizeof()-8);

    histoIn.hist[j][3]->SetTitle(htitle);
    histoIn.hist[j][3]->Add(histoIn.hist[j][3],histoIn.hist[j][1]);
    histoIn.hist[j][3]->Add(histoIn.hist[j][3],histoIn.hist[j][2]);

    histoIn.hist[j][4]->SetTitle(htitle);
    histoIn.hist[j][4]->Add(histoIn.hist[j][4],histoIn.hist[j][1]);
  }

  for(int j=0; j<histos2D; j++) {
    histoIn.hist2D[j][3]=(TH2F*)histoIn.hist2D[j][0]->Clone();
    histoIn.hist2D[j][4]=(TH2F*)histoIn.hist2D[j][0]->Clone();
    
    TString htitle=histoIn.hist2D[j][0]->GetTitle();
    htitle.Resize(htitle.Sizeof()-8);

    histoIn.hist2D[j][3]->SetTitle(htitle);
    histoIn.hist2D[j][3]->Add(histoIn.hist2D[j][3],histoIn.hist2D[j][1]);
    histoIn.hist2D[j][3]->Add(histoIn.hist2D[j][3],histoIn.hist2D[j][2]);

    histoIn.hist2D[j][4]->SetTitle(htitle);
    histoIn.hist2D[j][4]->Add(histoIn.hist2D[j][4],histoIn.hist2D[j][1]);
  }

  return histoIn;
}

void scalehistograms(Histograms histoIn, int channel, float SF){
  
  int histos=20;    // it was 12;
  int histos2D=3;   // FG addition  

    for(int j=0; j<histos; j++){
      histoIn.hist[j][channel]->Scale(SF);
    }
    for (int j=0; j<histos2D; j++)
      histoIn.hist2D[j][channel]->Scale(SF);
}


Histograms loadhistograms(TString plots,TString namefile){
  
  Histograms histofile;
  
  TFile *file=NULL;//new TFile(namefile);
  
  file = TFile::Open(namefile);
  cout << "loading " << plots << " " << namefile << endl; 
  
  TString channel[3];
  channel[0]="mumu";
  channel[1]="ee";
  channel[2]="mue";
  
  for(int ch=0;ch<3;ch++){

    histofile.hist[0][ch]=(TH1F*)file->Get("hPV_"+channel[ch]+"_"+plots);

    histofile.hist[1][ch]=(TH1F*)file->Get("hMET_"+channel[ch]+"_"+plots);
    histofile.hist[2][ch]=(TH1F*)file->Get("hMETSig_"+channel[ch]+"_"+plots);

    histofile.hist[3][ch]=(TH1F*)file->Get("hInvMass_"+channel[ch]+"_"+plots);
    histofile.hist[4][ch]=(TH1F*)file->Get("hDiLepPt_"+channel[ch]+"_"+plots);

    histofile.hist[5][ch]=(TH1F*)file->Get("hNJets_"+channel[ch]+"_"+plots);
    histofile.hist[6][ch]=(TH1F*)file->Get("hNBtagJets_"+channel[ch]+"_"+plots);    
    histofile.hist[7][ch]=(TH1F*)file->Get("hJet0Pt_"+channel[ch]+"_"+plots);
    histofile.hist[8][ch]=(TH1F*)file->Get("hJet1Pt_"+channel[ch]+"_"+plots);
    histofile.hist[9][ch]=(TH1F*)file->Get("hBtagJet0Pt_"+channel[ch]+"_"+plots);

    histofile.hist[10][ch]=(TH1F*)file->Get("hLep0Pt_"+channel[ch]+"_"+plots);
    histofile.hist[11][ch]=(TH1F*)file->Get("hLep1Pt_"+channel[ch]+"_"+plots);

    histofile.hist[12][ch]=(TH1F*)file->Get("hMET_Phi_"+channel[ch]+"_"+plots);

    histofile.hist[13][ch]=(TH1F*)file->Get("hMT2ll_"+channel[ch]+"_"+plots);
    histofile.hist[14][ch]=(TH1F*)file->Get("hMT2lb_"+channel[ch]+"_"+plots);

    histofile.hist[15][ch]=(TH1F*)file->Get("hDeltaPhiLep_"+channel[ch]+"_"+plots);
    histofile.hist[16][ch]=(TH1F*)file->Get("hDeltaPhiLepMET_"+channel[ch]+"_"+plots);
    histofile.hist[17][ch]=(TH1F*)file->Get("hDeltaPhiLepBtag_"+channel[ch]+"_"+plots);
    histofile.hist[18][ch]=(TH1F*)file->Get("hDeltaPhiMETBtag_"+channel[ch]+"_"+plots);
    //FG addition
    histofile.hist2D[0][ch]=(TH2F*)file->Get("hMT2ll_MT2lb_"+channel[ch]+"_"+plots);
    histofile.hist2D[1][ch]=(TH2F*)file->Get("hMT2ll_MT2bb_"+channel[ch]+"_"+plots);
    histofile.hist2D[2][ch]=(TH2F*)file->Get("hMT2ll_MT2llbb_"+channel[ch]+"_"+plots);
    histofile.hist[19][ch]=(TH1F*)file->Get("hMT2bb_"+channel[ch]+"_"+plots);
  }

  return histofile;
}
