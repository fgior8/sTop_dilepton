#include "ChainMaker.h"

TChain* ChainMaker(TString filelistT, Long64_t &eventProcessed) {

  std::string filelist;
  filelist = filelistT;
  TFile *Target;
  TH1D *Count;
  std::cout << "In ChainMaker\n";

  std::ifstream fin(filelist.c_str());
  std::string word;

  std::cout << "root file .txt list: input file stream bad? " << fin.bad()<<std::endl;

  TChain* chain = new TChain("tree");
  if (!chain) std::cout << "\n\nTChain is null!\n\n";

  while ( fin >> word ) {
    //std::cout << word << std::endl;
    chain->Add( word.c_str() );
    Target = TFile::Open( word.c_str() );
    if (Target->Get("SumGenWeights")) {
      Count = (TH1D*) Target->Get("SumGenWeights")->Clone("Count");
      //std::cout << Count->GetEntries() << std::endl;
      eventProcessed += Count->GetBinContent(1);
    }
  }
  fin.close();
  //std::cout << eventProcessed << std::endl;
  //std::cout << "#events = " << chain->GetEntries() << std::endl;
  return chain;

}
