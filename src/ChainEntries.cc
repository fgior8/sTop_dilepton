#include "ChainEntries.h"

Long64_t ChainEntries(TString filelistT) {

  std::string filelist;
  filelist = filelistT;

  std::cout << "In ChainEntries\n";

  std::ifstream fin(filelist.c_str());
  std::string word;

  std::cout << "root file .txt list: input file stream bad? " << fin.bad()<<std::endl;

  TChain* chain = new TChain("tree");
  TH1D* Count = new TH1D("Count","Count",1,0.,2.);

  if (!chain) std::cout << "\n\nTChain is null!\n\n";

  while ( fin >> word ) {
    //std::cout << word << std::endl;
    // Count->Add( word.c_str() );
  }
  fin.close();

  //std::cout << "#events = " << chain->GetEntries() << std::endl;
  return Count->GetEntries();

}
