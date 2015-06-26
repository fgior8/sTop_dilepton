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

  h_MCmod_ = (TH1D*)h_Data_->Clone("h_MCmod_");
  for (Int_t i = 1; i < 61; i++) {
    h_MCmod_->SetBinContent(i, Summer2012_S10[i-1]);
  }

  double int_MC_ = h_MCmod_->Integral();
  double int_Data_ = h_Data_->Integral();

  h_Data_->Divide(h_MCmod_);
  h_Data_->Scale(int_MC_ / int_Data_);

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
}

double ReweightPU::GetWeight(double nvtx) {
      
  return h_Data_->GetBinContent( h_Data_->FindBin(nvtx) );
  
}
