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
  
  // Distribution used for Summer2012 MC.
  
  Double_t Summer2012_S10[60] = {
    2.560E-06,
    5.239E-06,
    1.420E-05,
    5.005E-05,
    1.001E-04,
    2.705E-04,
    1.999E-03,
    6.097E-03,
    1.046E-02,
    1.383E-02,
    1.685E-02,
    2.055E-02,
    2.572E-02,
    3.262E-02,
    4.121E-02,
    4.977E-02,
    5.539E-02,
    5.725E-02,
    5.607E-02,
    5.312E-02,
    5.008E-02,
    4.763E-02,
    4.558E-02,
    4.363E-02,
    4.159E-02,
    3.933E-02,
    3.681E-02,
    3.406E-02,
    3.116E-02,
    2.818E-02,
    2.519E-02,
    2.226E-02,
    1.946E-02,
    1.682E-02,
    1.437E-02,
    1.215E-02,
    1.016E-02,
    8.400E-03,
    6.873E-03,
    5.564E-03,
    4.457E-03,
    3.533E-03,
    2.772E-03,
    2.154E-03,
    1.656E-03,
    1.261E-03,
    9.513E-04,
    7.107E-04,
    5.259E-04,
    3.856E-04,
    2.801E-04,
    2.017E-04,
    1.439E-04,
    1.017E-04,
    7.126E-05,
    4.948E-05,
    3.405E-05,
    2.322E-05,
    1.570E-05,
    5.005E-06};

  Double_t Spring2015_50ns[53] = {
    4.71E-09,
    2.86E-06,
    4.85E-06,
    1.53E-05,
    3.14E-05,
    6.28E-05,
    1.26E-04,
    3.93E-04,
    1.42E-03,
    6.13E-03,
    1.40E-02,
    2.18E-02,
    2.94E-02,
    4.00E-02,
    5.31E-02,
    6.53E-02,
    7.64E-02,
    8.42E-02,
    8.43E-02,
    7.68E-02,
    6.64E-02,
    5.69E-02,
    4.94E-02,
    4.35E-02,
    3.84E-02,
    3.37E-02,
    2.92E-02,
    2.49E-02,
    2.10E-02,
    1.74E-02,
    1.43E-02,
    1.16E-02,
    9.33E-03,
    7.41E-03,
    5.81E-03,
    4.49E-03,
    3.43E-03,
    2.58E-03,
    1.91E-03,
    1.39E-03,
    1.00E-03,
    7.09E-04,
    4.93E-04,
    3.38E-04,
    2.28E-04,
    1.51E-04,
    9.83E-05,
    6.29E-05,
    3.96E-05,
    2.45E-05,
    1.49E-05,
    4.71E-06,
    2.36E-06};

  Double_t Spring2015_25ns[53] = {
    4.8551E-07,
    1.74806E-06,
    3.30868E-06,
    1.62972E-05,
    4.95667E-05,
    0.000606966,
    0.003307249,
    0.010340741,
    0.022852296,
    0.041948781,
    0.058609363,
    0.067475755,
    0.072817826,
    0.075931405,
    0.076782504,
    0.076202319,
    0.074502547,
    0.072355135,
    0.069642102,
    0.064920999,
    0.05725576,
    0.047289348,
    0.036528446,
    0.026376131,
    0.017806872,
    0.011249422,
    0.006643385,
    0.003662904,
    0.001899681,
    0.00095614,
    0.00050028,
    0.000297353,
    0.000208717,
    0.000165856,
    0.000139974,
    0.000120481,
    0.000103826,
    8.88868E-05,
    7.53323E-05,
    6.30863E-05,
    5.21356E-05,
    4.24754E-05,
    3.40876E-05,
    2.69282E-05,
    2.09267E-05,
    1.5989E-05,
    4.8551E-06,
    2.42755E-06,
    4.8551E-07,
    2.42755E-07,
    1.21378E-07,
    4.8551E-08};

  h_MCmod_ = (TH1D*)h_Data_->Clone("h_MCmod_");
  h_Datamod_ = (TH1D*)h_Data_->Clone("h_MCmod_");
  for (Int_t i = 1; i < 61; i++) {
    if (i<53) {
      h_MCmod_->SetBinContent(i, Spring2015_25ns[i-1]);
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
