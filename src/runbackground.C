{
  gROOT->ProcessLine(".L Reweight.cc+g");
  gROOT->ProcessLine(".L Data.cc+g");
  gROOT->ProcessLine(".L BTagSFUtil.C+g");
  gROOT->ProcessLine(".L ChainMaker.C+g");
  gROOT->ProcessLine(".L Analyzer.cc+g");


  //////////////////////////////////////////////////////////
  //                          MC                          //
  //////////////////////////////////////////////////////////

  if (1) {
    TChain* chain = ChainMaker("/uscms_data/d2/fgior8/SubStructure/CMSSW_5_3_14_patch2/src/AWhitbeck/DataSetList/ZJetsToNuNu_400HTinf.txt");
    Analyzer Pippo; Pippo.Init(chain); Pippo.SetName("prova",1);
    Pippo.SetWeight(1, 1);
    std::cout << "Wgamma\n";  Pippo.Loop();
  }

  

  //////////////////////////////////////////////////////////
  //                        Data                          //
  //////////////////////////////////////////////////////////


  if (0) {
     TChain* chain = ChainMaker("/uscms_data/d2/fgior8/LQntuple_18/CMSSW_5_3_14_patch2_LQ/src/code/DataSetList/DoubleMuA.txt");
     FRCalculator Pippo; Pippo.Init(chain); Pippo.SetName("SingleMuA_del",1); //Pippo.SetWeight(.02);
     std::cout << "mu\n";  Pippo.LoopFR();
     //Pippo.~Analyzer();
  }


}

