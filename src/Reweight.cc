#include "Reweight.h"

ReweightPU::ReweightPU(TString filenameData) {

  fileData_ = 0;
  fileData_ = new TFile(filenameData, "READ");
  
  if (!fileData_) {
    cout << "\n\n Data file of the Nvtx reweighting could not be opened!" << endl;
  }
  
  h_Data_ = 0;
  h_Data_ = (TH1D*)fileData_->Get("pileup");
  if (!h_Data_) cout << "Can't open PU data reweight histo";
  
  // Distribution used for Summer2016 MC.
  Double_t Spring2016[60] = {
                0.000829312873542,
                0.00124276120498,
                0.00339329181587,
                0.00408224735376,
                0.00383036590008,
                0.00659159288946,
                0.00816022734493,
                0.00943640833116,
                0.0137777376066,
                0.017059392038,
                0.0213193035468,
                0.0247343174676,
                0.0280848773878,
                0.0323308476564,
                0.0370394341409,
                0.0456917721191,
                0.0558762890594,
                0.0576956187107,
                0.0625325287017,
                0.0591603758776,
                0.0656650815128,
                0.0678329011676,
                0.0625142146389,
                0.0548068448797,
                0.0503893295063,
                0.040209818868,
                0.0374446988111,
                0.0299661572042,
                0.0272024759921,
                0.0219328403791,
                0.0179586571619,
                0.0142926728247,
                0.00839941654725,
                0.00522366397213,
                0.00224457976761,
                0.000779274977993,
                0.000197066585944,
                7.16031761328e-05,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0};

  h_MCmod_ = (TH1D*)h_Data_->Clone("h_MCmod_");
  h_Datamod_ = (TH1D*)h_Data_->Clone("h_MCmod_");
  for (Int_t i = 1; i < 51; i++) {
    if (i<51) {
      h_MCmod_->SetBinContent(i, Spring2016[i-1]);
      h_Datamod_->SetBinContent(i, h_Data_->GetBinContent(i));
    }
    else {
      h_MCmod_->SetBinContent(i,0.);
      h_Datamod_->SetBinContent(i,0.);   
    }
  }

  double int_MC_ = h_MCmod_->Integral();
  double int_Data_ = h_Datamod_->Integral();

  h_Datamod_->Divide(h_MCmod_);
  h_Datamod_->Scale(int_MC_ / int_Data_);

  /*
    cout << endl;
    for (Int_t i = 1; i < 61; i++)
    cout << h_Data_->GetBinContent(i) <<endl;
  */
}

ReweightPU::~ReweightPU() {
  delete fileData_;
  delete h_MCmod_;
  delete h_Data_;
  delete h_Datamod_;
}

double ReweightPU::GetWeight(double nvtx) {
      
  return h_Datamod_->GetBinContent( h_Datamod_->FindBin(nvtx) );
  
}
