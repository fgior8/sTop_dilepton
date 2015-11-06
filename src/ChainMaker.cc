#include "ChainMaker.h"

TChain* ChainMaker(TString filelistT) {

  std::string filelist;
  filelist = filelistT;

  std::cout << "In ChainMaker\n";

  std::ifstream fin(filelist.c_str());
  std::string word;

  std::cout << "root file .txt list: input file stream bad? " << fin.bad()<<std::endl;

  TChain* chain = new TChain("tree");

  if (!chain) std::cout << "\n\nTChain is null!\n\n";

  while ( fin >> word ) {
    //std::cout << word << std::endl;
    chain->Add( word.c_str() );
  }
  fin.close();

  //std::cout << "#events = " << chain->GetEntries() << std::endl;
  return chain;

}
