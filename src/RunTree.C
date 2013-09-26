////////////////////////////////////////////////////////////////////////////////
//
//    FILE: RunProof.C
// AUTHORS: I. Gonzalez Caballero, A.Y. Rodriguez Marrero
//    DATE: 2010
//
// CONTENT: Main macro to run over MiniTrees or TESCO Trees using PROOF
//          in PROOF-Lite, PROOF-Cluster or Sequential mode
//
////////////////////////////////////////////////////////////////////////////////

// #include "scripts/PAFUtils.C"

TProof* proof = 0;

Double_t G_Event_Weight = 1;
//Double_t G_Event_Lumi   = 5311.0;

void RunTree(TString  sampleName      = "TTbar_Madgraph",
	     //TString  selector       = "TreeAnalysisStop",
	     //TString  selector       = "TreeAnalysisStop_FR",
	     //TString  selector       = "TreeAnalysisTop_FR",
	     TString  selector       = "TreeAnalysisStop",
	     TString  fileSuffix     = "",
	     bool doSS=false, 
	     TString  sampleSys      = "", // for systematic samples, indicate which source is going to be studied -> to be added in the histo name
	     // 	     Double_t lumiForPUdata  = 12103.3, // luminosity in http://www.hep.uniovi.es/jfernan/PUhistos/Data2012/
	     //Double_t lumiForPUdata  = 5311.0, // luminosity in http://www.hep.uniovi.es/jfernan/PUhistos/Data2012/
	     Double_t lumiForPUdata  = 19468.3, // luminosity in http://www.hep.uniovi.es/jfernan/PUhistos/Data2012/
	     // 	     Double_t varSF          = 0,     // +/- 1 to compute the systematic uncertainty on the lepton efficiencies
	     Int_t    sys_source     = -1,    // -1 nominal; enum sys_sources { sys_jes = 0, sys_jer, sys_les, sys_unenergy };
	     Int_t    sys_direction  = -1,    // -1 nominal; enum sys_directions { sys_Up = 0, sys_Nom, sys_Down};
	     // 	     Double_t wp             = 0.244, // b-tagging wp in data 
	     // 	     Double_t wp_b           = 0.285, // b-tagging wp in MC for b's 
	     // 	     Double_t wp_c           = 0.285, // b-tagging wp in MC for c's 
	     // 	     Double_t wp_l           = 0.2325, // b-tagging wp in MC for light's
	     Long64_t nEvents        = -1)
{

  // This loads all the PROOF Analysis Framework utilities
  gROOT->LoadMacro("$PAFPATH/PAF.C");

  Double_t G_Event_Lumi   = 0.0;   
  //if (selector=="TreeAnalysisTop")  G_Event_Lumi   = 12103.3;   
  if (selector=="TreeAnalysisTop")     G_Event_Lumi   = 5311.0;   
  if (selector=="TreeAnalysisTop_FR")  G_Event_Lumi   = 5311.0;   
  if (selector=="TreeAnalysisStop")    G_Event_Lumi  = 19602.9;  // A+B+C+D
  if (selector=="TreeAnalysisStop_FR") G_Event_Lumi  = 19602.9; 

  cout << "Params: " << endl;
  cout << "sampleName      " << sampleName    << endl;
  cout << "selector        " << selector      << endl;
  cout << "fileSuffix      " << fileSuffix    << endl;
  cout << "sampleSys       " << sampleSys     << endl;
  cout << "lumiForNorm     " << G_Event_Lumi  << endl;
  cout << "lumiForPUdata   " << lumiForPUdata << endl;
  //   cout << "varSF           " << varSF         << endl;
  cout << "sys_source      " << sys_source    << endl;
  cout << "sys_direction   " << sys_direction << endl;
  //   cout << "wp              " << wp            << endl;
  //   cout << "wp_b            " << wp_b          << endl;
  //   cout << "wp_c            " << wp_c          << endl;
  //   cout << "wp_l            " << wp_l          << endl;
  cout << "nEvents         " << nEvents       << endl;

  // PROOF settings - see scripts/PAFOptions.h
  //----------------------------------------------------------------------------

  // PROOF mode
  //----------------------------------------------------------------------------
  gPAFOptions->proofMode = kLite;             // PROOF Lite
  //gPAFOptions->proofMode = kCluster;            // PROOF Cluster
  //gPAFOptions->proofMode = kSequential;       // No PROOF

  //gPAFOptions->NSlots = 20;                   // Number of slots
  gPAFOptions->NSlots = 10;                   // Number of slots

  // Optional parameters for PROOF Cluster mode
  // gPAFOptions->proofServer = "proof.ifca.es";  // PROOF server
  // gPAFOptions->proofServerPort = 1093;         // PROOF port
  // gPAFOptions->maxSlavesPerNode = 9999;        // Max number of slaves / node

  // PROOF start
  //----------------------------------------------------------------------------
  cout << ">> Starting PROOF..." << endl;
  proof = InitProof();
  if (!proof && gPAFOptions->proofMode != kSequential) {
    cerr << "ERROR: I could not initialise a PROOF session!" << endl;
    return;
  }
  if (gPAFOptions->proofMode != kSequential) gPAFOptions->proofSession->SetLogLevel(2, TProofDebug::kOutput); 
 
  // Tree type
  //----------------------------------------------------------------------------
  //gPAFOptions->treeType = kMiniTrees;

  gPAFOptions->SetTreeType(kMiniTrees);

  // Base path to input files
  //----------------------------------------------------------------------------
  //TString dataPath = "/hadoop";                            // UNIOVI (fanaeui)
  TString dataPath = "/gpfs/csic_projects/tier3data/MC_Summer12_53X/SUSY/";     // IFCA   (gridui)
  //TString dataPath = "/gpfs/csic_projects/cms/albertog";  
  // Read Data and MC information from the goBogle doc table
  //gROOT->LoadMacro("/gpfs/csic_users/arodrig/Analysis-Run2012/DatasetManager/DatasetManager.C+");
  //gROOT->LoadMacro("/gpfs/csic_users/albertog/DatasetManager/DatasetManager.C+");
  
  // NO DATASETMANAGER IN ALTAMIRA
  //gROOT->LoadMacro("/nfs/fanae/user/albertog/DatasetManager/DatasetManager.C+");


  //----------------------------------------------------------------------------
  if (sampleName.Contains("T2tt_finebin")) {

    if(fileSuffix=="1"){
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_0.root"); 
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_1.root"); 
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_2.root"); 
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_3.root"); 
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_4.root"); 
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_5.root"); 
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_6.root"); 
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_7.root"); 
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_8.root"); 
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_9.root"); 
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_10.root");
    }
    if(fileSuffix=="2"){
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_11.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_12.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_13.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_14.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_15.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_16.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_17.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_18.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_19.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_20.root");
    }
    if(fileSuffix=="3"){
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_21.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_22.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_23.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_24.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_25.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_26.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_27.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_28.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_29.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_30.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_FineBin_31.root");
    }
    
    G_Event_Weight = 1;

  }

  else if (sampleName.Contains("T2tt_massbinned")) {
    if(fileSuffix=="1"){
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_150to350LSP0to250_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_150to350LSP0to250_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_150to350LSP0to250_2.root");
    }
    if(fileSuffix=="2"){
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_375to475LSP0to375_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_375to475LSP0to375_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_375to475LSP0to375_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_375to475LSP0to375_3.root");
    }
    if(fileSuffix=="3"){
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_500to650LSP0to225_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_500to650LSP0to225_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_500to650LSP0to225_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_500to650LSP0to225_3.root");
    }
    if(fileSuffix=="4"){
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_675to800LSP0to275_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_675to800LSP0to275_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_675to800LSP0to275_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_675to800LSP0to275_3.root");
    }
   if(fileSuffix=="5"){
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_500to650LSP250to550_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_500to650LSP250to550_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_500to650LSP250to550_2.root");
    }
   if(fileSuffix=="6"){
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_675to800LSP300to700_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_675to800LSP300to700_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_675to800LSP300to700_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2tt_675to800LSP300to700_3.root");
   }

    G_Event_Weight = 1;
  }

  else if (sampleName.Contains("T2bw_finebin")) {
    if(fileSuffix=="0"){
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_3.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_4.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_5.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_6.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_7.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_8.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_9.root");
    }
    if(fileSuffix=="1"){
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_10.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_11.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_12.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_13.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_14.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_15.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_16.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_17.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_18.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_19.root");
    }
    if(fileSuffix=="2"){
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_20.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_21.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_22.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_23.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_24.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_25.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_26.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_27.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_28.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_29.root");
    }
    if(fileSuffix=="3"){
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_30.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_31.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_32.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_33.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_34.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_35.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_36.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_37.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_38.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_39.root");
    }
    if(fileSuffix=="4"){
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_40.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_41.root");
      gPAFOptions->dataFiles.push_back(dataPath + "SMS/Tree_T2bw_FineBin_42.root");
    }
    G_Event_Weight = 1;
  }

  else if (sampleName.Contains("DYJets")) {

    gPAFOptions->dataFiles.push_back(dataPath + "Tree_DYJets_Madgraph_0.root");
    gPAFOptions->dataFiles.push_back(dataPath + "Tree_DYJets_Madgraph_1.root");

    G_Event_Weight = 860.5 * G_Event_Lumi / 7132223.; //Cross section times luminosity divided by num events 
  }


  else if (sampleName.Contains("ZJets_Madgraph")) {

    // if(fileSuffix=="0")  gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_0.root");
    // if(fileSuffix=="1")  gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_1.root");
    // if(fileSuffix=="2")  gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_2.root");
    // if(fileSuffix=="3")  gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_3.root");
    // if(fileSuffix=="4")  gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_4.root");
    // if(fileSuffix=="5")  gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_5.root");
    // if(fileSuffix=="6")  gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_6.root");
    // if(fileSuffix=="7")  gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_7.root");
    // if(fileSuffix=="8")  gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_8.root");
    // if(fileSuffix=="9")  gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_9.root");
    // if(fileSuffix=="10") gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_10.root");

    if(fileSuffix=="0") {
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_3.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_4.root");
    }
    if(fileSuffix=="1") {
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_5.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_6.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_7.root");
    }
    if(fileSuffix=="2") {
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_8.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_9.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZJets_Madgraph_10.root");
    }


    //x-section = 3532.8
    //nevents = 30459503
    G_Event_Weight = 3532.8 * G_Event_Lumi / 30459503.;
   
  }

  else if (sampleName.Contains("ZJets_Madgraph_1Jet")) {

    if(fileSuffix=="0") {
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad1jet_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad1jet_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad1jet_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad1jet_3.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad1jet_4.root");
    }
    if(fileSuffix=="1") {
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad1jet_5.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad1jet_6.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad1jet_7.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad1jet_8.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad1jet_9.root");
    }

    G_Event_Weight = 671.830779661017 * G_Event_Lumi / 24045248.;

  }
  
  else if (sampleName.Contains("ZJets_Madgraph_2Jet")) {

    if(fileSuffix=="0") {
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad2jetV7C_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad2jetV7C_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad2jetV7C_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad2jetV7C_3.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad2jetV7C_4.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad2jetV7C_5.root");
    }
    if(fileSuffix=="1") {
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad2jetV7C_6.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad2jetV7C_7.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad2jetV7C_8.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad2jetV7C_9.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad2jetV7C_10.root");
    }

    G_Event_Weight =  216.758237288136 * G_Event_Lumi / 21852156.;

  }
  // cout << "QU!!!!I" << endl;

  else if (sampleName.Contains("ZJets_Madgraph_3Jet")) {

    if(fileSuffix=="0") {
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad3jet_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad3jet_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad3jet_2.root");
    }
    if(fileSuffix=="1") {
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad3jet_3.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad3jet_4.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad3jet_5.root");
    }
    G_Event_Weight =  61.1952813559322 * G_Event_Lumi / 11015445.;
    // cout << "QUI" << endl;
  }
    
  else if (sampleName.Contains("ZJets_Madgraph_4Jet")) {
    
    if(fileSuffix=="0") {
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad4jet_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad4jet_1.root");
    }
    if(fileSuffix=="1") {
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad4jet_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DY50toLLMad4jet_3.root");
    }
    G_Event_Weight =  27.591766779661 * G_Event_Lumi / 6402827.;
    
  }
  
  else if (sampleName.Contains("DataMu12")) {

    if(fileSuffix=="A"){
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuA_892_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuA_892_1.root");
    }
    if(fileSuffix=="B"){
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuB_4404_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuB_4404_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuB_4404_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuB_4404_3.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuB_4404_4.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuB_4404_5.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuB_4404_6.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuB_4404_7.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuB_4404_8.root");
    }
    if(fileSuffix=="C1"){
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuC_7032_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuC_7032_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuC_7032_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuC_7032_3.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuC_7032_4.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuC_7032_5.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuC_7032_6.root");
    }
    if(fileSuffix=="C2"){
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuC_7032_7.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuC_7032_8.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuC_7032_9.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuC_7032_10.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuC_7032_11.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuC_7032_12.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuC_7032_13.root");
    }
    if(fileSuffix=="D"){
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuD_7274_0.root");
    }
    if (false) {
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuD_7274_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuD_7274_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuD_7274_3.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuD_7274_4.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuD_7274_5.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuD_7274_6.root");
    }
    if(fileSuffix=="D2"){
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuD_7274_7.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuD_7274_8.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuD_7274_9.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuD_7274_10.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuD_7274_11.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuD_7274_12.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleMuD_7274_13.root");
    }

    G_Event_Weight = 1.;
  }

  else if (sampleName.Contains("DataEG12")) {
    
    if(fileSuffix=="A"){
      gPAFOptions->dataFiles.push_back(dataPath+"Tree_DoubleElectronA_892_0.root");
      gPAFOptions->dataFiles.push_back(dataPath+"Tree_DoubleElectronA_892_1.root");
    }
    if(fileSuffix=="B"){
      gPAFOptions->dataFiles.push_back(dataPath+"Tree_DoubleElectronB_4404_0.root");
      gPAFOptions->dataFiles.push_back(dataPath+"Tree_DoubleElectronB_4404_1.root");
      gPAFOptions->dataFiles.push_back(dataPath+"Tree_DoubleElectronB_4404_2.root");
      gPAFOptions->dataFiles.push_back(dataPath+"Tree_DoubleElectronB_4404_3.root");
      gPAFOptions->dataFiles.push_back(dataPath+"Tree_DoubleElectronB_4404_4.root");
    }
    if(fileSuffix=="C"){
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleElectronC_7032_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleElectronC_7032_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleElectronC_7032_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleElectronC_7032_3.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleElectronC_7032_4.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleElectronC_7032_5.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleElectronC_7032_6.root");
    }
    if(fileSuffix=="D"){
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleElD_7274_0.root");
    }
    if(false) {
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleElD_7274_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleElD_7274_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleElD_7274_3.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleElD_7274_4.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleElD_7274_5.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleElD_7274_6.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleElD_7274_7.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_DoubleElD_7274_8.root");
    }

    G_Event_Weight = 1.;
  }
  else if (sampleName.Contains("DataMuEG12")) {
        
    if(fileSuffix=="A"){
      gPAFOptions->dataFiles.push_back(dataPath+"Tree_MuEGA_892_0.root");					       
    }
    if(fileSuffix=="B"){
      gPAFOptions->dataFiles.push_back(dataPath+"Tree_MuEGB_4404_0.root");
      gPAFOptions->dataFiles.push_back(dataPath+"Tree_MuEGB_4404_1.root");
      gPAFOptions->dataFiles.push_back(dataPath+"Tree_MuEGB_4404_2.root");
      gPAFOptions->dataFiles.push_back(dataPath+"Tree_MuEGB_4404_3.root");
      gPAFOptions->dataFiles.push_back(dataPath+"Tree_MuEGB_4404_4.root");
      gPAFOptions->dataFiles.push_back(dataPath+"Tree_MuEGB_4404_5.root");
    }
    if(fileSuffix=="C"){
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGC_7032_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGC_7032_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGC_7032_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGC_7032_3.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGC_7032_4.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGC_7032_5.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGC_7032_6.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGC_7032_7.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGC_7032_8.root");			       
    }
    if(fileSuffix=="D"){
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGD_7274_0.root");
    }
    if (false) {
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGD_7274_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGD_7274_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGD_7274_3.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGD_7274_4.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGD_7274_5.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGD_7274_6.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGD_7274_7.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_MuEGD_7274_8.root");
    }

    G_Event_Weight = 1.;
    
  }
  else {

    // UNCOMMENT WHEN NOT RUNNING FROM ALTAMIRA
    
    //     DatasetManager *dm = new DatasetManager("Summer12_53X");

    //     // Use this if you know that the information on the google doc table has
    //     // changed and you need to update the information
    //     dm->RedownloadFiles();

    //     dm->LoadDataset(sampleName);  // Load information about a given dataset

    //     G_Event_Weight = dm->GetCrossSection() * G_Event_Lumi / dm->GetEventsInTheSample();
  
    //     cout << endl;
    //     cout << "      x-section = " << dm->GetCrossSection()      << endl;
    //     cout << "     luminosity = " << G_Event_Lumi               << endl;
    //     cout << "        nevents = " << dm->GetEventsInTheSample() << endl;
    //     cout << " base file name = " << dm->GetBaseFileName()      << endl;
    //     cout << endl;

    //     //gPAFOptions->dataFiles = dm->GetFiles();

    // END UNCOMMENT


    if (sampleName.Contains("TWDilep")) {
      
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TWDilep_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TWDilep_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TWDilep_2.root");

      // G_Event_Weight = 11.1773 * G_Event_Lumi / 497658.;        
      G_Event_Weight = 1.1733482448 * G_Event_Lumi / 2976510.;
    }

    if (sampleName.Contains("TbarWDilep")) {

      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TbarWDilep_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TbarWDilep_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TbarWDilep_2.root");

      //      G_Event_Weight = 11.1773 * G_Event_Lumi / 483460.;
      G_Event_Weight = 1.1733482448 * G_Event_Lumi / 2971482.; 
    }
    
    if (sampleName.Contains("TTbar") && (sampleName.Contains("MassiveBinDECAY"))) {

      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_Madgraph_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_Madgraph_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_Madgraph_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_Madgraph_3.root");

      // Weight for TTJets_MassiveBinDECAY
      G_Event_Weight = 245.8 * G_Event_Lumi / 6923750.;

      // Weight for TTJets_MassiveBinDECAY
      //G_Event_Weight = 245.8 * G_Event_Lumi / 6923652.;


    }

    if (sampleName.Contains("TTbar") && sampleName.Contains("FullLeptMG")) {

      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTJetsFullLeptMG_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTJetsFullLeptMG_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTJetsFullLeptMG_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTJetsFullLeptMG_3.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTJetsFullLeptMG_4.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTJetsFullLeptMG_5.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTJetsFullLeptMG_6.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTJetsFullLeptMG_7.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTJetsFullLeptMG_8.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTJetsFullLeptMG_9.root");      

      // Weight for TTJets_FullLeptMGDecays
      //      G_Event_Weight = 24.8 * G_Event_Lumi / 12119013.;  //dm->GetCrossSection() * G_Event_Lumi / dm->GetEventsInTheSample();      
      G_Event_Weight = 25.84 * G_Event_Lumi / 12119013.;  //dm->GetCrossSection() * G_Event_Lumi / dm->GetEventsInTheSample();
 
    }

    if (sampleName.Contains("TTbar") && sampleName.Contains("Powheg")) {

      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_Powheg_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_Powheg_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_Powheg_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_Powheg_3.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_Powheg_4.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_Powheg_5.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_Powheg_6.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_Powheg_7.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_Powheg_8.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_Powheg_9.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_Powheg_10.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_Powheg_11.root");

      // Weight for TTJets_Powheg
      G_Event_Weight = 245.8 * G_Event_Lumi / 28150723.;  //dm->GetCrossSection() * G_Event_Lumi / dm->GetEventsInTheSample();      
    }

    if (sampleName.Contains("TTbar") && sampleName.Contains("MCatNLO")) {

      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_MCatNLO_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_MCatNLO_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_MCatNLO_2.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_MCatNLO_3.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_MCatNLO_4.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_MCatNLO_5.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_MCatNLO_6.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_MCatNLO_7.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_MCatNLO_8.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_MCatNLO_9.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_MCatNLO_10.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_MCatNLO_11.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_MCatNLO_12.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_MCatNLO_13.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTbar_MCatNLO_14.root");

      // Weight for TTJets_MC@NLO
      G_Event_Weight = 245.8 * G_Event_Lumi / 32852589.;  //dm->GetCrossSection() * G_Event_Lumi / dm->GetEventsInTheSample();      
    }



    if (sampleName.Contains("WJets_Madgraph")) {

      gPAFOptions->dataFiles.push_back(dataPath + "Tree_WJets_Madgraph_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_WJets_Madgraph_1.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_WJets_Madgraph_2.root");

      G_Event_Weight = 37509. * G_Event_Lumi / 76102995.;  //dm->GetCrossSection() * G_Event_Lumi / dm->GetEventsInTheSample();      
    }

    if (sampleName.Contains("WWTo2L2Nu_Madgraph")) {

      gPAFOptions->dataFiles.push_back(dataPath + "Tree_WWTo2L2Nu_Madgraph_0.root");

      G_Event_Weight = 5.8123 * G_Event_Lumi / 1933235.;  //dm->GetCrossSection() * G_Event_Lumi / dm->GetEventsInTheSample();      

    }

    if (sampleName.Contains("WZ_pythia6_tauola")) {

      gPAFOptions->dataFiles.push_back(dataPath + "Tree_WZ_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_WZ_1.root");

      G_Event_Weight = 22.44 * G_Event_Lumi / 10000283.;  //dm->GetCrossSection() * G_Event_Lumi / dm->GetEventsInTheSample();  

    }

    if (sampleName.Contains("ZZ_pythia6_tauola")) {

      gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZZ_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZZ_1.root");

      G_Event_Weight = 9.03 * G_Event_Lumi / 9799908.;  //dm->GetCrossSection() * G_Event_Lumi / dm->GetEventsInTheSample();      

    }

    if (sampleName.Contains("TTGJets")) {

      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTGJets.root");

      G_Event_Weight = 1.44 * G_Event_Lumi / 71598.;  //dm->GetCrossSection() * G_Event_Lumi / dm->GetEventsInTheSample();      

    }

    if (sampleName.Contains("WWGJets")) {

      gPAFOptions->dataFiles.push_back(dataPath + "Tree_WWGJets.root");

      G_Event_Weight = 0.528 * G_Event_Lumi / 215121.;  //dm->GetCrossSection() * G_Event_Lumi / dm->GetEventsInTheSample();      

    }


    if (sampleName.Contains("HWW125")) {

      gPAFOptions->dataFiles.push_back(dataPath + "Tree_HWW125.root");

      G_Event_Weight = 0.444 * G_Event_Lumi / 299975.;  //dm->GetCrossSection() * G_Event_Lumi / dm->GetEventsInTheSample();      

    }

    if (sampleName.Contains("TTWJets")) {

      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTWJets.root");

      G_Event_Weight = 0.232 * G_Event_Lumi / 196046.;  //dm->GetCrossSection() * G_Event_Lumi / dm->GetEventsInTheSample();      

    }

    if (sampleName.Contains("TTZJets")) {

      cout << "Sto provando TTZJets" << endl;

      gPAFOptions->dataFiles.push_back(dataPath + "Tree_TTZJets.root");

      G_Event_Weight = 0.174 * G_Event_Lumi / 210160.;  //dm->GetCrossSection() * G_Event_Lumi / dm->GetEventsInTheSample();      

    }    

    if (sampleName.Contains("WgammaToLNuG")) {

      gPAFOptions->dataFiles.push_back(dataPath + "Tree_WgammaToLNuG.root");

      G_Event_Weight = 553.92 * G_Event_Lumi / 4802358.;  //dm->GetCrossSection() * G_Event_Lumi / dm->GetEventsInTheSample();      

    }

    if (sampleName.Contains("ZgammaToLLG")) {

      gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZgammaToLLG_0.root");
      gPAFOptions->dataFiles.push_back(dataPath + "Tree_ZgammaToLLG_1.root");

      G_Event_Weight = 132.6 * G_Event_Lumi / 6588161.;  //dm->GetCrossSection() * G_Event_Lumi / dm->GetEventsInTheSample();      

    }



  }

  cout << " G_Event_Weight = " << G_Event_Weight << endl;

  // Output file name
  //----------------------------------------------------------------------------
  //TString outputDir = "/gpfs/csic_users/arodrig/Analysis-Run2012/TopAnalysis/TopResults/Summer12/root";
  TString outputDir;
  if(selector=="TreeAnalysisTop")    outputDir = "/gpfs/csic_users/dkolchme/New_StopAnalysis_Nov2012/PAF/InputTrees/compareSelections_ttbar_official";
  if(selector=="TreeAnalysisTop_FR") outputDir="/gpfs/csic_users/dkolchme/New_StopAnalysis_Nov2012/PAF/InputTrees/LooseLepID-Trees_TreeAnalysisTopFR_runAddWJetsWeightsOnThis";
  //if(selector=="TreeAnalysisStop")    outputDir = "/gpfs/csic_users/albertog/PAFstop/PAF/InputTrees/stop/";
  if(selector=="TreeAnalysisStop")    outputDir = "/gpfs/csic_projects/cms/fgior8/InputTrees_stop_04sep2013/";
  if(selector=="TreeAnalysisStop_FR") outputDir = "/gpfs/csic_users/fgior8/PAFstop/PAF/InputTrees/stop_FR/";

  gSystem->mkdir(outputDir, kTRUE);
  
  std::ostringstream oss;      
  oss << G_Event_Lumi;

  TString LumiString = oss.str();

  TString outputFile;
  
  if(doSS) {
    outputFile = outputDir
      + "/SS/"
      + selector
      + "" 
      + "_"
      + LumiString
      + "pb-1_"
      + sampleName
      + sampleSys
      + fileSuffix
      + ".root";}

  else {
    outputFile = outputDir
      + selector
      + ""
      + "_"
      + LumiString
      + "pb-1_"
      + sampleName
      + sampleSys
      + fileSuffix
      + ".root";}

  
  gPAFOptions->outputFile = outputFile;

  // Parameters for the analysis
  //----------------------------------------------------------------------------
  // See packages/InputParameters/InputParameters.h for information on how
  // to use this class.

  gPAFOptions->inputParameters = new InputParameters();

  gPAFOptions->inputParameters->SetNamedString("sampleName",   sampleName.Data());
  gPAFOptions->inputParameters->SetNamedDouble("weight",       G_Event_Weight);
  gPAFOptions->inputParameters->SetNamedBool("doSS",      doSS);

  gPAFOptions->inputParameters->SetNamedInt("sys_source",     sys_source);
  gPAFOptions->inputParameters->SetNamedInt("sys_direction",  sys_direction);

  //   gPAFOptions->inputParameters->SetNamedDouble("wp",   wp);
  //   gPAFOptions->inputParameters->SetNamedDouble("wp_b", wp_b);
  //   gPAFOptions->inputParameters->SetNamedDouble("wp_c", wp_c);
  //   gPAFOptions->inputParameters->SetNamedDouble("wp_l", wp_l);

  gPAFOptions->inputParameters->SetNamedDouble("luminosity",   lumiForPUdata);  // PU 73.5mb

  //gPAFOptions->inputParameters->SetNamedDouble("varSF",     varSF); 

  gPAFOptions->inputParameters->SetNamedString("fileSuffix",   fileSuffix.Data());

  // Dynamic histograms
  //----------------------------------------------------------------------------
  //  gPAFOptions->dynamicHistograms.push_back("myHistogram");
  
  // Number of events (Long64_t)
  //----------------------------------------------------------------------------
  gPAFOptions->SetNEvents(nEvents);
  // First event (Long64_t)
  //----------------------------------------------------------------------------
  gPAFOptions->SetFirstEvent(0);
  
  // Name of analysis class
  //----------------------------------------------------------------------------
  // If 0 the default name schema will be used, i.e. depending on the value
  // of gPAFOptions->treeType: MyAnalysisTESCO or MyAnalsyisMiniTrees

  gPAFOptions->SetAnalysis(selector.Data());
  //gPAFOptions->myAnalysis = selector.Data();

  // Additional packages to be uploaded to PROOF
  //----------------------------------------------------------------------------
  //   if (gPAFOptions->treeType == kMiniTrees)
  //     gPAFOptions->packages.push_back("CMSAnalysisSelectorMiniTrees");
  //   else if (gPAFOptions->treeType == kTESCO)
  //     gPAFOptions->packages.push_back("CMSAnalysisSelectorTESCO");

  //   gPAFOptions->packages.push_back("PUWeight");
  //   gPAFOptions->packages.push_back("BTagSFUtil");


  gPAFOptions->AddPackage("PUWeight");
  gPAFOptions->AddPackage("BTagSFUtil");

  // Control output and checks
  //----------------------------------------------------------------------------
  // + If true (default) PAF checks for new version in CVS every time
  // gPAFOptions->checkVersion = true;
  // + If true (default) the output file is reopened so the objects in the
  //   file can be interactively accessed. The object in the output are also
  //   listed

  gPAFOptions->reopenOutputFile = false;

  // Run the analysis
  //----------------------------------------------------------------------------
  if (!RunAnalysis())
    cerr << "ERROR: There was a problem running the analysis!" << endl;
}
