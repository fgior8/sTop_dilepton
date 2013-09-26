#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataHist.h"
#include "RooGaussian.h"
#include "RooConstVar.h"
#include "RooAddPdf.h"
#include "RooPlot.h"
#include "RooWorkspace.h"
#include "RooHistPdf.h"

// #include <RooRealVar.h>
// #include <RooDataHist.h>

// #include <RooGaussian.h>
// #include <RooConstVar.h>
// #include <RooAddPdf.h>
// #include <RooPlot.h>
// #include <RooWorkspace.h>
// #include <RooHistPdf.h>

using namespace RooFit ;
using namespace std;

#include "General.h"
#include "ZmassFromLikelihoodFit.h"

//***********************************
//root -l ZmassFromLikelihoodFit.C+
//***********************************
//Fits the Zmass distribution in three different templates:
//   1) non-DY-MC: ttbar + single top + VV
//   2) DY: DY + ZJets
//   3) Data 
//   MM and EE are used as cross-checks; the goal is to estimate 
//   the SF in EM. 
//***********************************

void ZmassFromLikelihoodFit(){

  //std::vector<float> MM_dilepton;
  //ZmassFromLikelihoodFit("mumu","dilepton", MM_dilepton);
  //std::vector<float> EE_dilepton;
  //ZmassFromLikelihoodFit("ee","dilepton", EE_dilepton);
  //std::vector<float> ME_dilepton;
  //ZmassFromLikelihoodFit("mue","dilepton", ME_dilepton);

  //std::vector<float> MM_2jets;
  //ZmassFromLikelihoodFit("mumu","2Jets", MM_2jets);
  //std::vector<float> EE_2jets;
  //ZmassFromLikelihoodFit("ee","2Jets", EE_2jets);
//   std::vector<float> ME_2jets;
//   ZmassFromLikelihoodFit("mue","2Jets", ME_2jets);

  //std::vector<float> MM_MET;
  //ZmassFromLikelihoodFit("mumu","MET", MM_MET);
  //std::vector<float> EE_MET;
  //ZmassFromLikelihoodFit("ee","MET", EE_MET);

  //std::vector<float> MM_1btag;
  //ZmassFromLikelihoodFit("mumu","1btag", MM_1btag);
  //std::vector<float> EE_1btag;
  //ZmassFromLikelihoodFit("ee","1btag", EE_1btag);
  //std::vector<float> ME_1btag;
  //ZmassFromLikelihoodFit("mue","1btag", ME_1btag);

  std::vector<float> ME_MT2ll;
  ZmassFromLikelihoodFit("mue","MT2ll", ME_MT2ll);

}

int ZmassFromLikelihoodFit(TString channel, TString cut, std::vector<float> &result){

  if(cut != "dilepton" && cut != "2Jets" && cut != "MET" && cut != "1btag" && cut != "2btag" && cut != "MT2ll") return 1;

  if(cut == "2btag") return ZmassFromLikelihoodFit(channel,"1btag", result);

  // comment this line if you want to run for ZmassFromLikelihoodFit() -> mumu, ee
  if ( channel != "mue" ) return 1;

  result.clear();

  gStyle->SetPadRightMargin(0.13);
  gStyle->SetPadLeftMargin(0.13);
  
  TCanvas *c1 = new TCanvas("c1", "plots",400,400,800,600);
  c1->SetFillColor(10);
  c1->SetFillStyle(4000);
  c1->SetBorderSize(2); 
  c1->SetLogy(0);
 
  // MC: ttbar, single top, VV
  TFile *f_mc         = TFile::Open(dirnameIn + "h"+fl+"_MC.root");  // Merge all MC but TTbar and ZDY
  //TFile *f_mc_ttbar   = TFile::Open(dirnameIn + "h"+fl+"_TTbar_MassiveBinDECAY.root");
  TFile *f_mc_ttbar   = TFile::Open(dirnameIn + "h"+fl+"_TTbar_Powheg.root");
  //TFile *f_mc_ttbar   = TFile::Open(dirnameIn + "h"+fl+"_TTbar_FullLeptMG.root");
  //TFile *f_mc_ttbar   = TFile::Open(dirnameIn + "h"+fl+"_TTbar_MCatNLO.root");
  // MC: DYJets + ZJets
  TFile *f_dy   = TFile::Open(dirnameIn + "h"+fl+"_ZDY.root"); 
  // Data
  TFile *f_data = NULL;
  if ( channel == "mumu" ) {
       f_data = TFile::Open(dirnameIn + "h"+fl+"_DataMu12.root"); 
  }
  else if ( channel == "ee" ) {
       f_data = TFile::Open(dirnameIn + "h"+fl+"_DataEG12.root");
  }
  else if ( channel == "mue" ) {
       f_data = TFile::Open(dirnameIn + "h"+fl+"_DataMuEG12.root");
  }
  TString htitle        = "hInvMass_" + channel + "_" + cut;
  TH1F *zMass_MC        = (TH1F*) f_mc  ->Get(htitle); 
  TH1F *zMass_MC_ttbar  = (TH1F*) f_mc_ttbar  ->Get(htitle); 
  TH1F *zMass_MC_DY     = (TH1F*) f_dy  ->Get(htitle); 
  TH1F *zMass_Data      = (TH1F*) f_data->Get(htitle); 

  // Scale with W Branching Fraction
  zMass_MC_ttbar->Scale(SF_BR);
  zMass_MC->Add(zMass_MC_ttbar);
  // Scale MC but DY with SF_trig_lepEff
  if ( channel == "mumu" ) zMass_MC->Scale(SFmumu);  
  if ( channel == "ee" )   zMass_MC->Scale(SFee);  
  if ( channel == "mue" )  zMass_MC->Scale(SFmue);  

  // should the SFs be applied to MC_DY or not? If yes, then the SF_DD_mue will be even higher!
  //if ( channel == "mumu" ) zMass_MC_DY->Scale(SFmumu);
  //if ( channel == "ee" )   zMass_MC_DY->Scale(SFee);
  //if ( channel == "mue" )  zMass_MC_DY->Scale(SFmue);
  
  zMass_Data->SetMarkerStyle(20);
  zMass_Data->Draw("ep");
  zMass_MC->SetLineColor(2);
  zMass_MC->SetLineWidth(2); 
  zMass_MC->Draw("hsame");
  zMass_MC_DY->SetLineColor(4);
  zMass_MC_DY->SetLineWidth(0); 
  zMass_MC_DY->Draw("hsame");
  zMass_Data->Draw("epsame");
  
  //*********************************************
  // create the RooFit environement
  //RooWorkspace *w = new RooWorkspace("w",kTRUE) ; // is not being used!  

  //*********************************************
  // create a RooFit variable : 
  // the variable that will be used for the fit
  //*********************************************
  RooRealVar *LL_Zmass = NULL;
  if( channel == "mue")  LL_Zmass = new RooRealVar("LL_Zmass", "M_{ll,e#mu}",   zMass_Data->GetXaxis()->GetXmin(), zMass_Data->GetXaxis()->GetXmax());
  if( channel == "mumu")  LL_Zmass = new RooRealVar("LL_Zmass", "M_{ll,#mu#mu}", zMass_Data->GetXaxis()->GetXmin(), zMass_Data->GetXaxis()->GetXmax());
  if( channel == "ee")  LL_Zmass = new RooRealVar("LL_Zmass", "M_{ll,ee}",     zMass_Data->GetXaxis()->GetXmin(), zMass_Data->GetXaxis()->GetXmax());
  
  //create RooDataHisto for the data (to be fitted)
  RooDataHist* histoLL_Zmass   = new RooDataHist("histoFit_LL", "histoFit_LL",  *LL_Zmass,  zMass_Data); 
  //create RooDataHisto for the MC DY : will be used to create template 1
  RooDataHist* histoFit_Template_DYEM        = new RooDataHist("histoFit_Template_DYEM",       "histoFit_Template_DYEM",    *LL_Zmass, zMass_MC_DY);
  //create RooDataHisto for the MC DY : will be used to create template 2
  RooDataHist* histoFit_Template_OtherLL     = new RooDataHist("histoFit_Template_OtherLL",    "histoFit_Template_OtherLL", *LL_Zmass, zMass_MC);        
  
  //convert  RooDataHisto into the template 1
  RooHistPdf*  histoFit_Template_DYEM_pdf    = new RooHistPdf("histoFit_Template_DYEM_pdf",    "histoFit_Template_DYEM_pdf",    *LL_Zmass,  *histoFit_Template_DYEM);
  
  
  //convert  RooDataHisto into the template 2
  RooHistPdf*  histoFit_Template_OtherLL_pdf    = new RooHistPdf("histoFit_Template_OtherLL_pdf",    "histoFit_Template_OtherLL_pdf",    *LL_Zmass,  *histoFit_Template_OtherLL);
  
  // define a coefficient: it is the output of the fit
  // it represents the contribution (fraction) of one of the 2 templates with resepct to the data after the fit:
  // N(event ttbar) = coeff*N(event data)
  RooRealVar coeffModel("coeffModel", "coeffModel", 0.5, 0., 1.);
  //associate the templates, the data histo and the coeff.
  RooAddPdf *pdf_sum = new RooAddPdf("pdf_sum"," test pdf sum",RooArgSet(*histoFit_Template_DYEM_pdf, *histoFit_Template_OtherLL_pdf), coeffModel);
  //do the fit
  RooFitResult* myFitResults_all = pdf_sum->fitTo(*histoLL_Zmass, Save()) ;
  
  //create a "frame" : a kind of TCanvas used to display the result of the fit
  RooPlot* frame = LL_Zmass->frame() ;
  // Remove the title!
  frame->SetTitle("");
  //plot the data on the frame
  histoLL_Zmass->plotOn(frame) ;
  //plots the templates (after the fit) on the frame
  RooPlot *RooFitTot = pdf_sum->plotOn(frame, Components(*histoFit_Template_DYEM_pdf),    VisualizeError(*myFitResults_all), FillColor(kGreen), LineWidth(0) );
  RooFitTot->SetFillColor(4);
  pdf_sum->plotOn(frame, Components(*histoFit_Template_OtherLL_pdf), VisualizeError(*myFitResults_all), FillColor(kRed),   LineWidth(0) );
  pdf_sum->plotOn(frame, LineStyle(kSolid),                         VisualizeError(*myFitResults_all), FillColor(kBlue),  LineWidth(0) );
  histoLL_Zmass->plotOn(frame) ;
 
  //draw the frame
  frame->Draw() ;

  //print the coeff after the fit
  coeffModel.Print() ;

  //calculate the various contributions
  cout << " the DY is " << coeffModel.getVal()*zMass_Data->Integral(0,10000) << " +/- " << coeffModel.getError()*zMass_Data->Integral(0,10000) << endl;
  cout << " the other " << (1-coeffModel.getVal())*zMass_Data->Integral(0,10000) << " +/- " << coeffModel.getError()*zMass_Data->Integral(0,10000) << endl;
  
  cout << " initial DY component " << zMass_MC_DY->Integral(0,10000) << endl;
  
  cout << "scale factor " << coeffModel.getVal()*zMass_Data->Integral(0,10000)/(zMass_MC_DY->Integral(0,10000)) << " pm " <<
  coeffModel.getError()*zMass_Data->Integral(0,10000)/(zMass_MC_DY->Integral(0,10000))
   << endl;

  TH1F *histoFitTot   = new TH1F("histoFitTot",   "histoFitTot", 0, 1, 100);
  TH1F *histoFitDY    = new TH1F("histoFitDY",    "histoFitDY",    0, 1, 100);
  TH1F *histoFitOther = new TH1F("histoFitOther", "histoFitOther", 0, 1, 100);
  
  histoFitTot->SetFillColor(4);
  histoFitDY->SetFillColor(3);
  histoFitOther->SetFillColor(2);

  TString names[] = {
        "pdf_sum_Norm[LL_Zmass]_errorband",
        "pdf_sum_Norm[LL_Zmass]_errorband_Comp[histoFit_Template_OtherLL_pdf]",
        "pdf_sum_Norm[LL_Zmass]_errorband_Comp[histoFit_Template_DYEM_pdf]",
        "no_more_plots"
  };

  TString labels[] = {
	  "result of the fit",
	  "non-DY component",
	  "DY component" ,   
          "no_more_labels"
  };

  TLegend* qw = new TLegend(0.75,0.70,0.98,0.98);
  qw->AddEntry(zMass_Data, "data", "p");

  Int_t i=-1;
  while ( names[++i] != "no_more_plots" ) {
    TObject *obj = frame->findObject(names[i].Data());
    if (!obj) {
      continue;
    }
    qw->AddEntry(obj, labels[i], "f");
  }

  qw->Draw();

  //c1->SaveAs(Form("StopResults/figures/%s_fit.eps",htitle.Data()));
  //c1->SaveAs(Form("StopResults/figures/%s_fit.pdf",htitle.Data()));
  
  //c1->SaveAs(Form(dirnameIn+"figures/%s_fit.eps",htitle.Data()));
  //c1->SaveAs(Form(dirnameIn+"figures/%s_fit.pdf",htitle.Data()));

  TString saveName = dirnameIn + "figures/" + htitle.Data() + "_fit";
  c1->SaveAs(saveName + ".eps");
  c1->SaveAs(saveName + ".pdf");

  result.push_back(coeffModel.getVal()*zMass_Data->Integral(0,10000)/(zMass_MC_DY->Integral(0,10000)));
  result.push_back(coeffModel.getError()*zMass_Data->Integral(0,10000)/(zMass_MC_DY->Integral(0,10000)));

  return 0;
}

