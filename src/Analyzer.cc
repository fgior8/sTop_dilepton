#include "Analyzer.h"

Analyzer::Analyzer() {

  if (debug) cout<<"inizio"<<endl;

  // PILEUP //
  reweightPU = new ReweightPU("/gpfs/csic_projects/cms/fgior8/PileUpDistr/MyDataPileupHistogram.root");
  if (debug) cout<< "PU histos loaded" <<endl;

  // Scale Factors ///
  // --first for the trigger-- //
  //  MuSF_trig   = TFile::Open("/gpfs/csic_projects/cms/fgior8/ScaleFactors/triggerSummary_mumu_ttbar.root"); //only EMu for the moment //FIXME
  //  ElSF_trig   = TFile::Open("/gpfs/csic_projects/cms/fgior8/ScaleFactors/triggerSummary_ee_ttbar.root");
  MuElSF_trig = TFile::Open("/gpfs/csic_projects/cms/fgior8/ScaleFactors/triggerSummary_emu_13TeV_RunD.root");
  if(!MuElSF_trig)
    cout << "ERROR [MuonSF_trig]: Could not open file " << MuSF_trig << " or " << ElSF_trig << " or " << MuElSF_trig << "!"  << endl;
  // --second for the ID and Isolation-- //
  MuSF_IDISO   = TFile::Open("/gpfs/csic_projects/cms/fgior8/ScaleFactors/MuonSF_IDISO_Trigger_POG25ns.root");
  ElSF_IDISO   = TFile::Open("/gpfs/csic_projects/cms/fgior8/ScaleFactors/elec_tight_sf2D_13TeV_RunD.root");
  if(!MuSF_IDISO || !ElSF_IDISO)
    cout << "ERROR [MuonSF_IDISO]: Could not open file " << MuSF_IDISO << " or " << ElSF_IDISO << "!"  << endl;

  hmuIDSF        = (TH2F*) MuSF_IDISO->Get("GlobalSF")->Clone("muIDSF");
  //hmumuTriggerSF = (TH2F*) MuSF_trig ->Get("scalefactor_eta2d_with_syst")  ->Clone("mumuTriggerSF"); 
  if(!hmuIDSF)// || !hmumuTriggerSF)
    cout << "ERROR [MuonSF]: Could not find histogram for SF reweighting" << endl;
  heIDSF       = (TH2F*) ElSF_IDISO->Get("GlobalSF")->Clone("eIDSF");
  //heeTriggerSF = (TH2F*) ElSF_trig ->Get("scalefactor_eta2d_with_syst")  ->Clone("eeTriggerSF");
  if(!heIDSF)// || !heeTriggerSF)
    cout << "ERROR [ElectronSF]: Could not find histogram for SF reweighting" << endl;

  hmueTriggerSF = (TH2F*) MuElSF_trig->Get("scalefactor_eta2d_with_syst")->Clone("mueTriggerSF");
  if(!hmueTriggerSF)
    cout << "ERROR [MuonElectronSF]: Could not find histogram for SF reweighting" << endl;
  
  h_prova = new TH1F("h_prova","p_T",100,0,1000);
 
  ncuts=6;
  nchannels=5;
  nsystematics=2;
  TString cut_name[] = {"particle", "twoLeptons", "twoJets", "MET", "oneBtag", "twoBtag", "Ctrl_Z", "Ctrl_noB", "Ctrl_ZornoB", "Ctrl_ZandnoB"};
  TString channel_name[] = {"all", "sameF","ee", "mumu", "emu"};
  TString sys_name[] = {"JetEnUp", "JetEnDown", "JetResUp", "JetResDown", "MuonEnUp", "MuonEnDow", "ElectronEnUp", "ElectronEnDown", "TauEnUp", "TauEnDown", "UnclusteredEnUp", "UnclusteredEnDown"};
  
  // 0-all, 1-SF, 2 ee, 3 mumu, 4 emu, (5 mue if needed)
  h_muons = new MuonPlots**[ncuts];
  h_electrons = new ElectronPlots**[ncuts];
  h_jets = new JetPlots**[ncuts];
  h_bjets = new JetPlots**[ncuts];
  h_HTjets = new JetPlots**[ncuts];
  h_signal = new SignalPlots**[ncuts];
  h_systematics = new SignalPlots***[ncuts];
  h_ZDYplots = new ZDYPlots**[ncuts];

  for (UInt_t i=0;i<ncuts;i++) {
    h_muons[i] = new MuonPlots*[nchannels];
    h_electrons[i] = new ElectronPlots*[nchannels];
    h_jets[i] = new JetPlots*[nchannels];
    h_bjets[i] = new JetPlots*[nchannels];
    h_HTjets[i] = new JetPlots*[nchannels];
    h_signal[i] = new SignalPlots*[nchannels];
    h_ZDYplots[i] = new ZDYPlots*[nchannels];
    h_systematics[i] = new SignalPlots**[nchannels];
  }
  
  for (UInt_t i=0;i<ncuts;i++)
    for (UInt_t j=0;j<nchannels;j++) {
      h_muons[i][j]       = new MuonPlots    ("muons_"    +cut_name[i]+"_"+channel_name[j]);
      h_electrons[i][j]   = new ElectronPlots("electrons_"+cut_name[i]+"_"+channel_name[j]);
      h_jets[i][j]        = new JetPlots     ("jets_"     +cut_name[i]+"_"+channel_name[j]);
      h_bjets[i][j]       = new JetPlots     ("bjets_"    +cut_name[i]+"_"+channel_name[j]);
      h_HTjets[i][j]      = new JetPlots     ("HTjets_"   +cut_name[i]+"_"+channel_name[j]);
      h_signal[i][j]      = new SignalPlots  ("signal_"   +cut_name[i]+"_"+channel_name[j]);
      h_ZDYplots[i][j]    = new ZDYPlots     ("ZDY_"      +cut_name[i]+"_"+channel_name[j]);
      h_systematics[i][j] = new SignalPlots*[nsystematics];
    }

  for (UInt_t i=0;i<ncuts;i++)
    for (UInt_t j=0;j<nchannels;j++)
      for (UInt_t k=0;k<nsystematics;k++) {
	h_systematics[i][j][k] = new SignalPlots ("signal_"+cut_name[i]+"_"+channel_name[j]+"_sys_"+sys_name[k]);
      }
  // valueMET = new Float_t[nsystematics+1];
  // valueMETPhi = new Float_t[nsystematics+1];
  
  if (debug) cout<<"fine"<<endl;
}

Analyzer::~Analyzer() { }

void Analyzer::SetName(TString name, Int_t version) {
  completename = name + "_";
  completename += version;
  completename += ".root";
  outfile = new TFile("histos/"+completename,"RECREATE");
  if (SaveTree) {
    treename = name + "_tree_";
    treename += version;
    treename += ".root";
    outfileTree = new TFile("trees/"+treename,"RECREATE");
  }
}

void Analyzer::SetWeight(TString name) {
  // lumi *  cs(pb) * gen filter efficiency / MCevents
  MCweight = integratedlumi * getXS_D(name);
  name.Contains("Muon") || name.Contains("EG") ? isData=true : isData=false;
  name.Contains("MCatNLO") ? MCatNLO=true : MCatNLO=false;
  name.Contains("DoubleEG") ? isDoubleEl=true : isDoubleEl=false;
  name.Contains("MuonEG") ? isMuEG=true : isMuEG=false;
  name.Contains("DoubleMuon") ? isDoubleMu=true : isDoubleMu=false;
  if(isData) MCweight = 1;
  cout<<"MCweight = "<<MCweight<<endl;
}

void Analyzer::SetEvtN(Long64_t events) {
  entrieslimit = events;
  cout<<"Processing "<<events<<endl;
}

void Analyzer::Loop() {

  if (SaveTree) {
    if (debug) cout<< "inizializing tree" <<endl;
    ///Initialize tree for optimization
    AnalysisTree = new TTree("sTopTree","Optimization tree");
    AnalysisTree->Branch("TWeight",&TWeight,"TWeight/F");
    AnalysisTree->Branch("TNPV",&TNPV,"TNPV/I");
    AnalysisTree->Branch("TMET",&TMET,"TMET/F");
    AnalysisTree->Branch("TMET_Phi",&TMET_Phi,"TMET_Phi/F");
    AnalysisTree->Branch("TMT2ll",&TMT2ll,"TMT2ll/F");
    AnalysisTree->Branch("TMT2bb",&TMT2bb,"TMT2bb/F");
    AnalysisTree->Branch("TMT2lblb",&TMT2lblb,"TMT2lblb/F");
    AnalysisTree->Branch("GMT2ll",&GMT2ll,"GMT2ll/F");
    AnalysisTree->Branch("GMT2bb",&GMT2bb,"GMT2bb/F");
    AnalysisTree->Branch("GMT2lblb",&GMT2lblb,"GMT2lblb/F");
    AnalysisTree->Branch("THT",&THT,"THT/F");
    AnalysisTree->Branch("TMll",&TMll,"TMll/F");
    AnalysisTree->Branch("TMeff",&TMeff,"TMeff/F");
    AnalysisTree->Branch("TPtllb",&TPtllb,"TPtllb/F");
    AnalysisTree->Branch("TdPhiPtllbMET",&TdPhiPtllbMET,"TdPhiPtllbMET/F");
    AnalysisTree->Branch("TdPhiJetMet",&TdPhiJetMet,"TdPhiJetMet/F");
    AnalysisTree->Branch("TdPhiLepMet",&TdPhiLepMet,"TdPhiLepMet/F");
    AnalysisTree->Branch("TdPhiLepJet",&TdPhiLepJet,"TdPhiLepJet/F");
    AnalysisTree->Branch("TdPhill",&TdPhill,"TdPhill/F");
    AnalysisTree->Branch("TNMuon",&TNMuon,"TNMuon/I");
    AnalysisTree->Branch("TNElec",&TNElec,"TNElec/I");
    AnalysisTree->Branch("TNJets",&TNJets,"TNJets/I");
    AnalysisTree->Branch("TNJetsBtag",&TNJetsBtag,"TNJetsBtag/I");
    if (debug) cout<< "inizializing variables for TLorentz vectors" <<endl;
    AnalysisTree->Branch("TMuon_Charge", TMuon_Charge, "TMuon_Charge[TNMuon]/F");
    AnalysisTree->Branch("TMuon_Px", TMuon_Px, "TMuon_Px[TNMuon]/F");
    AnalysisTree->Branch("TMuon_Py", TMuon_Py, "TMuon_Py[TNMuon]/F");
    AnalysisTree->Branch("TMuon_Pz", TMuon_Pz, "TMuon_Pz[TNMuon]/F");
    AnalysisTree->Branch("TMuon_E", TMuon_E, "TMuon_E[TNMuon]/F");
    AnalysisTree->Branch("TElec_Charge", TElec_Charge, "TElec_Charge[TNElec]/F");
    AnalysisTree->Branch("TElec_Px", TElec_Px, "TElec_Px[TNElec]/F");
    AnalysisTree->Branch("TElec_Py", TElec_Py, "TElec_Py[TNElec]/F");
    AnalysisTree->Branch("TElec_Pz", TElec_Pz, "TElec_Pz[TNElec]/F");
    AnalysisTree->Branch("TElec_E", TElec_E, "TElec_E[TNElec]/F");
    AnalysisTree->Branch("TJet_discriminant", TJet_discriminant, "TJet_discriminant[TNJets]/F");
    AnalysisTree->Branch("TJet_Px", TJet_Px, "TJet_Px[TNJets]/F");
    AnalysisTree->Branch("TJet_Py", TJet_Py, "TJet_Py[TNJets]/F");
    AnalysisTree->Branch("TJet_Pz", TJet_Pz, "TJet_Pz[TNJets]/F");
    AnalysisTree->Branch("TJet_E", TJet_E, "TJet_E[TNJets]/F");
    AnalysisTree->Branch("TBJet_Px", TBJet_Px, "TBJet_Px[TNJetsBtag]/F");
    AnalysisTree->Branch("TBJet_Py", TBJet_Py, "TBJet_Py[TNJetsBtag]/F");
    AnalysisTree->Branch("TBJet_Pz", TBJet_Pz, "TBJet_Pz[TNJetsBtag]/F");
    AnalysisTree->Branch("TBJet_E", TBJet_E, "TBJet_E[TNJetsBtag]/F");
  }
  //// done initialization

  cout << "total number of entries " <<nentries<<endl;

  if (debug) cout<< "loop begins" <<endl;

  fBTagSF = new BTagSFUtil("comb", "CSVv2", "Medium", 0, "", 123);

  if(!MCweight) MCweight=1;   
  weight=MCweight;

  if (fChain == 0) 
    cout << "Ciao!" << endl;

  if (entrieslimit != -1)
    nentries=entrieslimit;

  if (debug) cout<< "at the loop" <<endl;
  std::set<int> runs;
  for (Long64_t jentry = 0; jentry < nentries; jentry++ ) {
     
    if (debug) cout<< "Event number " <<jentry<<endl;
    if (debug) cout<<"begin loop"<<endl;
    if (!(jentry % 10000)) 
      cout << jentry << endl;

    if (!fChain) cout<<"problems with the input file"<<endl;
    fChain->GetEntry(jentry);

    weight = MCweight;
 
    /// only for MC at NLO normalization ///
    if (MCatNLO && !isData) weight *= genWeight;
    
    // MET filters for now all OFF
    //----------------------------------------------------------------------------
    if (false) 
      if (!(Flag_HBHENoiseFilter && Flag_CSCTightHaloFilter && Flag_goodVertices && Flag_eeBadScFilter)) continue;

    // Vertex Select
    numberVertices = nVert;

    Float_t valueMET[] = {met_pt, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    Float_t valueMETPhi[] = {met_phi, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    

    if (!isData) {
      //weight *= puWeight;
      /// ***PU reweghting*** ///
      //h_nvtx_norw->Fill(PileUpInteractionsTrue->at(0), MCweight);
      weight *= reweightPU->GetWeight(nTrueInt);
      //h_nvtx_rw->Fill(PileUpInteractionsTrue->at(0), weight);
    }

    if(debug) cout<< "object selection" <<endl;
    muonColl.clear();    electronColl.clear();
    genElec.clear(); genMuon.clear(); genBquark.clear(); genLightquark.clear();
    
    Muon.SetPt(15);
    Muon.SetEta(2.4);
    Muon.SetRelIso(0.12);
    Muon.SetChiNdof(10);
    Muon.SetBSdxy(0.20);
    Muon.SetBSdz(0.50);
    Muon.MuonSelection(nLepGood, LepGood_pdgId, LepGood_pfMuonId, LepGood_eta, LepGood_pt, LepGood_px, LepGood_py, LepGood_pz, LepGood_energy, LepGood_relIso03, LepGood_charge, LepGood_trackerHits, LepGood_pixelLayers, LepGood_nStations, LepGood_trackerLayers, LepGood_globalTrackChi2, LepGood_dxy, LepGood_dz, muonColl);
    
    Electron.SetPt(15);
    Electron.SetEta(2.5);
    Electron.SetRelIso(0.15);
    Electron.SetBSdxy(0.02);
    Electron.SetBSdz(0.10);
    Electron.ElectronSelection(nLepGood, LepGood_pdgId, LepGood_etaSc, LepGood_pt, LepGood_px, LepGood_py, LepGood_pz, LepGood_energy, LepGood_relIso03, LepGood_charge, LepGood_convVeto, LepGood_lostHits, LepGood_dEtaScTrkIn, LepGood_dPhiScTrkIn, LepGood_sigmaIEtaIEta, LepGood_hadronicOverEm, LepGood_eInvMinusPInv, LepGood_dxy, LepGood_dz, electronColl);
    
    ///cleaning vectors//
    for (UInt_t kk=0;kk<nsystematics+1;kk++) {//nsystematics
      jetColl[kk].clear();    bjetColl[kk].clear(); jetHTColl[kk].clear();
    }
    if(debug) cout<< "selecting jets" <<endl;
    Float_t tmp_sys[] = {0,0};
    Jets.SetPt(10);
    Jets.SetEta(5.0);
    Jets.JetSelectionLeptonVeto_JU(nJet, tmp_sys, Jet_id, Jet_pt, Jet_eta, Jet_px, Jet_py, Jet_pz, Jet_energy, Jet_phEF, Jet_neHEF, Jet_eEF, Jet_chHEF, Jet_chHMult, Jet_mult, Jet_btagCMVA, electronColl, muonColl, jetHTColl);
    
    Jets.SetPt(30);
    Jets.SetEta(2.4);
    Jets.SetBdisc(0.605);
    Jets.JetSelectionLeptonVeto_andB_JU(nJet, tmp_sys, Jet_id, Jet_pt, Jet_eta, Jet_px, Jet_py, Jet_pz, Jet_energy, Jet_phEF, Jet_neHEF, Jet_eEF, Jet_chHEF, Jet_chHMult, Jet_mult, Jet_btagCSV, electronColl, muonColl, jetColl, bjetColl);

    GenPart.GenPartSelection(nGenPart, GenPart_pdgId, GenPart_status, GenPart_motherId, GenPart_grandmotherId, GenPart_charge, GenPart_pt, GenPart_eta, GenPart_phi, GenPart_mass, genElec, genMuon, genBquark, genLightquark);
   
    if(debug) cout<< "DONE object selection" <<endl;
    for (Variation sysvar=(Analyzer::Variation)0;sysvar<nsystematics+1;sysvar=(Analyzer::Variation)(sysvar+1)) {
      if (debug) cout << "Looking at sys n " << sysvar << endl;
      selectionStep.clear();    selectChannel.clear();   selectionStepZDY.clear();
      jetSelect.clear();    leptonSelect.clear();
      
      HT=0;
      for (int i=0; i<jetHTColl[sysvar].size(); i++) 
	HT += jetHTColl[sysvar][i].lorentzVec().Pt();
      
      ///Filling standard particle plots
      if (sysvar==CentralValue) {
	if(muonColl.size()>0)
	  for (Int_t i=0; i<muonColl.size(); i++) {
	    index=muonColl[i].ilepton();
	    h_muons[0][0]->Fill(weight, (Int_t) muonColl.size(), muonColl[i].lorentzVec(), muonColl[i].charge(), muonColl[i].relIso(), muonColl[i].chiNdof(), muonColl[i].dxy_BS(), muonColl[i].dz_BS());
	  }
	if (electronColl.size() > 0) {
	  for (UInt_t i=0; i<electronColl.size(); i++) {
	    index=electronColl[i].ilepton();
	    h_electrons[0][0]->Fill(weight, (Int_t) electronColl.size(), electronColl[i].lorentzVec(), electronColl[i].charge(), electronColl[i].relIso(), electronColl[i].dxy_BS(), electronColl[i].dz_BS());
	  }
	}  
	if(jetHTColl[sysvar].size()>0)
	  for (int i=0; i<jetHTColl[sysvar].size(); i++) {
	    index=jetHTColl[sysvar][i].ijet();
	    h_HTjets[0][0]->Fill(weight, (Int_t) jetHTColl[sysvar].size(), jetHTColl[sysvar][i].lorentzVec(), Jet_btagCSV[index], Jet_btagCMVA[index] );
	  }
	if(jetColl[sysvar].size()>0)
	  for (int i=0; i<jetColl[sysvar].size(); i++) {
	    index=jetColl[sysvar][i].ijet();
	    h_jets[0][0]->Fill(weight, (Int_t) jetColl[sysvar].size(), jetColl[sysvar][i].lorentzVec(), Jet_btagCSV[index], Jet_btagCMVA[index] );
	  }
	if(bjetColl[sysvar].size()>0)
	  for (int i=0; i<bjetColl[sysvar].size(); i++) {
	    index=bjetColl[sysvar][i].ijet();
	    h_bjets[0][0]->Fill(weight, (Int_t) bjetColl[sysvar].size(), bjetColl[sysvar][i].lorentzVec(), Jet_btagCSV[index], Jet_btagCMVA[index] );
	  }
      }
      if(debug) cout<< "generic plots FILLED" <<endl;

      ///Filling standard particle plots END

      //Making leptons and jets selected collections
      // it seems more convinent to take only two leptons, once the triggers are set we need to add the here FIXME 
      if (muonColl.size()==2 && electronColl.size()==0 && HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v>0 && (!isData || isDoubleMu)) {
	invMtemp=0;
	if (muonColl[0].charge()*muonColl[1].charge()<0 && muonColl[0].lorentzVec().Pt()>20) 
	  invMtemp = (muonColl[0].lorentzVec()+muonColl[1].lorentzVec()).M();
	if (invMtemp>15) {
	  leptonSelect.push_back(muonColl[0]);
	  leptonSelect.push_back(muonColl[1]);
	  selectChannel.push_back(0);
	  selectChannel.push_back(1);
	  selectChannel.push_back(3);
	}
      }
      if (electronColl.size()==2 && muonColl.size()==0 && HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v>0 && (!isData || isDoubleEl)) {
	invMtemp=0;
	if (electronColl[0].charge()*electronColl[1].charge()<0 && electronColl[0].lorentzVec().Pt()>20) 
	  invMtemp = (electronColl[0].lorentzVec()+electronColl[1].lorentzVec()).M();
	if (invMtemp>15) {
	  leptonSelect.clear();
	  leptonSelect.push_back(electronColl[0]);
	  leptonSelect.push_back(electronColl[1]);
	  selectChannel.push_back(0);
	  selectChannel.push_back(1);
	  selectChannel.push_back(2);
	}
      }
      if (muonColl.size()==1 && electronColl.size()==1 && (HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v>0 || HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v) && (!isData || isMuEG)) {
	invMtemp=0;
	if (muonColl[0].charge()*electronColl[0].charge()<0 && (electronColl[0].lorentzVec().Pt()>20 || muonColl[0].lorentzVec().Pt()>20)) 
	  invMtemp = (muonColl[0].lorentzVec()+electronColl[0].lorentzVec()).M();
	if (invMtemp>15) {
	  leptonSelect.clear();
	  leptonSelect.push_back(muonColl[0]);
	  leptonSelect.push_back(electronColl[0]);
	  selectChannel.push_back(0);
	  selectChannel.push_back(4);
	}
      }

      if (leptonSelect.size()<2) continue; // no less than two leptons
      if(debug) cout<< "two leptons found" <<endl;


      // applying scaling factor for ID and triggers (now that we have selected the event type)
      if (!isData && sysvar==CentralValue && true) {
	//trigger SF only for emu but applied to both FIXME
	weight *= hmueTriggerSF->GetBinContent( hmueTriggerSF->FindBin( fabs(leptonSelect[0].lorentzVec().Eta()),fabs(leptonSelect[1].lorentzVec().Eta()) ) );
      
	//ID SF applied per lepton
	for (UInt_t i=0; i<leptonSelect.size(); i++) {
	  if (leptonSelect[i].leptonType()=="Electron")
	    weight *= heIDSF->GetBinContent( hmueTriggerSF->FindBin( leptonSelect[i].lorentzVec().Eta(),fabs(leptonSelect[i].lorentzVec().Pt()) ) );
	  if (leptonSelect[i].leptonType()=="Muon")
	    weight *= hmuIDSF->GetBinContent( hmueTriggerSF->FindBin( leptonSelect[i].lorentzVec().Eta(),fabs(leptonSelect[i].lorentzVec().Pt()) ) );
	}
      }
      if(debug) cout<< "trigger and ID weights applied" <<endl;
      // Z veto applied only for same flavor
      if ( ((leptonSelect[0].leptonType()==0 && leptonSelect[1].leptonType()==0) || (leptonSelect[0].leptonType()==1 && leptonSelect[1].leptonType()==1)) &&
	   ( fabs((leptonSelect[0].lorentzVec()+leptonSelect[1].lorentzVec()).M()-Mass_Z)<15 ) )
	Zveto=false;
      else
	Zveto=true;
      
      // filling plots for the dilepton selection
      for (UInt_t n=0;n<selectChannel.size();n++) {
	UInt_t channel = selectChannel[n];
	if (sysvar==CentralValue)
	  h_signal[1][channel]->Fill(numberVertices, valueMET[sysvar], valueMETPhi[sysvar], HT, leptonSelect, jetSelect, weight, channel, 1);
	else
	  h_systematics[1][channel][sysvar-1]->Fill(numberVertices, valueMET[sysvar], valueMETPhi[sysvar], HT, leptonSelect, jetSelect, weight, channel, 1);
	
	if (sysvar==CentralValue) h_ZDYplots[1][channel]->Fill(leptonSelect, weight, Zveto); //ZDY plot only for re-normalization
      }
    
      if (debug) cout << "two leptons VETO" << endl;
    
      if (jetColl[sysvar].size()<2) continue;   /// from now on 2 jets are required
    
      if (bjetColl[sysvar].size()==0) {
	jetSelect.push_back(jetColl[sysvar][0]);
	jetSelect.push_back(jetColl[sysvar][1]);
      }
      else if (bjetColl[sysvar].size()==1) {
	if (bjetColl[sysvar][0].ijet() != jetColl[sysvar][0].ijet()) {
	  jetSelect.push_back(jetColl[sysvar][0]);
	  jetSelect.push_back(bjetColl[sysvar][0]);
	}
	else {
	  jetSelect.push_back(jetColl[sysvar][1]);
	  jetSelect.push_back(bjetColl[sysvar][0]);
	}
      }
      else if (bjetColl[sysvar].size()>=2) {
	jetSelect.push_back(bjetColl[sysvar][0]);
	jetSelect.push_back(bjetColl[sysvar][1]);
      }

      if (debug) cout << "two jets CHECKED" << endl;

      TMT2ll = getMT2(leptonSelect[0].lorentzVec(), leptonSelect[1].lorentzVec(), valueMET[0], valueMETPhi[0]);
      TMT2bb = getMT2bb(jetSelect, leptonSelect, valueMET[0], valueMETPhi[0]);
      TMT2lblb = getMT2lblb(jetSelect, leptonSelect, valueMET[0], valueMETPhi[0]);

      float gMETx = met_genPt*TMath::Cos(met_genPhi);
      float gMETy = met_genPt*TMath::Sin(met_genPhi);
      if (genMuon.size()>=2 && genElec.size()<1 && genBquark.size()>1) {
	GMT2ll = getMT2(genMuon[0], genMuon[1], met_genPt, met_genPhi);
	GMT2bb = getMT2_80(genBquark[0], genBquark[1], sqrt(pow(gMETx+(genMuon[0]+genMuon[1]).Px(),2)+pow(gMETy+(genMuon[0]+genMuon[1]).Py(),2)), TMath::ATan2(gMETy+(genMuon[0]+genMuon[1]).Py(),gMETx+(genMuon[0]+genMuon[1]).Px()) );
	//GMT2lblb = getMT2lblb(jetSelect, leptonSelect, valueMET[0], valueMETPhi[0]);
      }
      else if (genMuon.size()<1 && genElec.size()>=2 && genBquark.size()>1) {
	GMT2ll = getMT2(genElec[0], genElec[1], met_genPt, met_genPhi);
	GMT2bb = getMT2_80(genBquark[0], genBquark[1], sqrt(pow(gMETx+(genElec[0]+genElec[1]).Px(),2)+pow(gMETy+(genElec[0]+genElec[1]).Py(),2)), TMath::ATan2(gMETy+(genElec[0]+genElec[1]).Py(),gMETx+(genElec[0]+genElec[1]).Px()) );
	//GMT2lblb = getMT2lblb(jetSelect, leptonSelect, valueMET[0], valueMETPhi[0]);
      }
      else if (genMuon.size()>0 && genElec.size()>0 && genBquark.size()>1) {
	GMT2ll = getMT2(genMuon[0], genElec[0], met_genPt, met_genPhi);
	GMT2bb = getMT2_80(genBquark[0], genBquark[1], sqrt(pow(gMETx+(genMuon[0]+genElec[0]).Px(),2)+pow(gMETy+(genMuon[0]+genElec[0]).Py(),2)), TMath::ATan2(gMETy+(genMuon[0]+genElec[0]).Py(),gMETx+(genMuon[0]+genElec[0]).Px()) );
	//GMT2lblb = getMT2lblb(jetSelect, leptonSelect, valueMET[0], valueMETPhi[0]);
      }
      
      // filling all tree variables
      if (sysvar==CentralValue && SaveTree && jetSelect.size()>1 && leptonSelect.size()>1) {
	TWeight = weight;
	TNPV = numberVertices;
	TNJets = jetColl[sysvar].size();     
	TNJetsBtag = bjetColl[sysvar].size();
	TNMuon = muonColl.size();
	TNElec = electronColl.size();
	TMET = valueMET[0];
	TMET_Phi = valueMETPhi[0];
	THT = HT;
	
	TMll = (leptonSelect[0].lorentzVec()+leptonSelect[1].lorentzVec()).M();
	TPtllb = getllmetVector(leptonSelect[0].lorentzVec(), leptonSelect[1].lorentzVec(), valueMET[0], valueMETPhi[0]).Pt();
	TMeff = getMeff(jetSelect, leptonSelect, valueMET[0]);
	TdPhiPtllbMET = getdPhiPtllbMet(getllmetVector(leptonSelect[0].lorentzVec(), leptonSelect[1].lorentzVec(), valueMET[0], valueMETPhi[0]), valueMET[0], valueMETPhi[0]);
	TdPhiJetMet = getdPhiJetMet(jetSelect, valueMET[0], valueMETPhi[0]); //Closest Jet
	TdPhiLepMet = getdPhiLepMet(leptonSelect[0].lorentzVec(), valueMET[0], valueMETPhi[0]);
	TdPhiLepJet = leptonSelect[0].lorentzVec().DeltaPhi(jetSelect[0].lorentzVec());
	TdPhill = leptonSelect[0].lorentzVec().DeltaPhi(leptonSelect[1].lorentzVec());
	for (Int_t i=0; i<muonColl.size(); i++) {
	  TMuon_Charge[i] = muonColl[i].charge();
	  TMuon_Px[i] = muonColl[i].lorentzVec().Px();
	  TMuon_Py[i] = muonColl[i].lorentzVec().Py();
	  TMuon_Pz[i] = muonColl[i].lorentzVec().Pz();
	  TMuon_E[i] = muonColl[i].lorentzVec().E();
	}
	for (UInt_t i=0; i<electronColl.size(); i++) {
	  TElec_Charge[i] = electronColl[i].charge();
	  TElec_Px[i] = electronColl[i].lorentzVec().Px();
	  TElec_Py[i] = electronColl[i].lorentzVec().Py();
	  TElec_Pz[i] = electronColl[i].lorentzVec().Pz();
	  TElec_E[i] = electronColl[i].lorentzVec().E();
	}
	for (int i=0; i<jetColl[sysvar].size(); i++) {
	  TJet_discriminant[i] = jetColl[sysvar][i].btag_disc();
	  TJet_Px[i] = jetColl[sysvar][i].lorentzVec().Px();
	  TJet_Py[i] = jetColl[sysvar][i].lorentzVec().Py();
	  TJet_Pz[i] = jetColl[sysvar][i].lorentzVec().Pz();
	  TJet_E[i] = jetColl[sysvar][i].lorentzVec().E();
	}
	for (int i=0; i<bjetColl[sysvar].size(); i++) {
	  TBJet_Px[i] = bjetColl[sysvar][i].lorentzVec().Px();
	  TBJet_Py[i] = bjetColl[sysvar][i].lorentzVec().Py();
	  TBJet_Pz[i] = bjetColl[sysvar][i].lorentzVec().Pz();
	  TBJet_E[i] = bjetColl[sysvar][i].lorentzVec().E();		
	}
	AnalysisTree->Fill();	
      } /// filled the tree

      if (Blind && (TMT2ll>80 || TMT2bb>180 || TMT2lblb>180)) continue;
      
      met_cut = 40;

      // selection events, signal and control regions
      if (leptonSelect.size()>1 && Zveto && jetColl[sysvar].size()>1)
	selectionStep.push_back(2);
      if (leptonSelect.size()>1 && Zveto && jetColl[sysvar].size()>1 && valueMET[sysvar]>met_cut)
	selectionStep.push_back(3);
      if (leptonSelect.size()>1 && Zveto && jetColl[sysvar].size()>1 && valueMET[sysvar]>met_cut && bjetColl[sysvar].size()>0)
	selectionStep.push_back(4);
      if (leptonSelect.size()>1 && Zveto && jetColl[sysvar].size()>1 && valueMET[sysvar]>met_cut && bjetColl[sysvar].size()>1)
	selectionStep.push_back(5);
      /*
	if (leptonSelect.size()>1 && jetColl.size()>1 && !Zveto)
	selectionStep.push_back(6);
	if (leptonSelect.size()>1 && jetColl.size()>1 && bjetColl.size()==0)
	selectionStep.push_back(7);
	if (leptonSelect.size()>1 && jetColl.size()>1 && (bjetColl.size()==0 || !Zveto))
	selectionStep.push_back(8);
	if (leptonSelect.size()>1 && jetColl.size()>1 && (bjetColl.size()==0 && !Zveto))
	selectionStep.push_back(9);
      */
      // event selection for ZDY normalization 
      if (leptonSelect.size()>1 && jetColl[sysvar].size()>1)
	selectionStepZDY.push_back(2);
      if (leptonSelect.size()>1 && jetColl[sysvar].size()>1 && valueMET[sysvar]>met_cut)
	selectionStepZDY.push_back(3);
      if (leptonSelect.size()>1 && jetColl[sysvar].size()>1 && valueMET[sysvar]>met_cut && bjetColl[sysvar].size()>0)
	selectionStepZDY.push_back(4);
      if (leptonSelect.size()>1 && jetColl[sysvar].size()>1 && valueMET[sysvar]>met_cut && bjetColl[sysvar].size()>1)
	selectionStepZDY.push_back(5);
      if (debug) cout << "Filling final histos" << endl;
      if (sysvar==CentralValue) {
	for (UInt_t n=0;n<selectChannel.size();n++){
	  channel = selectChannel[n];
	  for (UInt_t m=0;m<selectionStep.size();m++) {
	    cut = selectionStep[m];
	    
	    h_signal[cut][channel]->Fill(numberVertices, valueMET[sysvar], valueMETPhi[sysvar], HT, leptonSelect, jetSelect, weight, channel, cut);
	    for (Int_t i=0; i<muonColl.size(); i++) {
	      index=muonColl[i].ilepton();
	      h_muons[cut][channel]->Fill(weight, (Int_t) muonColl.size(), muonColl[i].lorentzVec(), muonColl[i].charge(), muonColl[i].relIso(), muonColl[i].chiNdof(), muonColl[i].dxy_BS(), muonColl[i].dz_BS());
	    }
	    for (UInt_t i=0; i<electronColl.size(); i++) {
	      index=electronColl[i].ilepton();
	      h_electrons[cut][channel]->Fill(weight, (Int_t) electronColl.size(), electronColl[i].lorentzVec(), electronColl[i].charge(), electronColl[i].relIso(), electronColl[i].dxy_BS(), electronColl[i].dz_BS());
	    }
	    for (int i=0; i<jetColl[sysvar].size(); i++) {
	      index=jetColl[sysvar][i].ijet();
	      h_jets[cut][channel]->Fill(weight, (Int_t) jetColl[sysvar].size(), jetColl[sysvar][i].lorentzVec(), Jet_btagCSV[index], Jet_btagCMVA[index] );
	    }
	    for (int i=0; i<bjetColl[sysvar].size(); i++) {
	      index=bjetColl[sysvar][i].ijet();
	      h_bjets[cut][channel]->Fill(weight, (Int_t) bjetColl[sysvar].size(), bjetColl[sysvar][i].lorentzVec(), Jet_btagCSV[index], Jet_btagCMVA[index] );
	    }
	  }
	  for (UInt_t m=0;m<selectionStepZDY.size();m++) {
	    cutZDY = selectionStepZDY[m];
	    h_ZDYplots[cutZDY][channel]->Fill(leptonSelect, weight, Zveto);
	  }
	  if (debug) cout << "Filled channel " << channel << " cut " << cut << endl;
	}
      }/*
	 else {
	 for (UInt_t n=0;n<selectChannel.size();n++){
	 channel = selectChannel[n];
	 for (UInt_t m=0;m<selectionStep.size();m++) {
	 cut = selectionStep[m];
	 //  h_systematics[cut][channel][sysvar-1]->Fill(numberVertices, valueMET[sysvar], valueMETPhi[sysvar], HT, leptonSelect, jetSelect, weight, channel, cut);
	 }
	 }
	 }*/
    } //systematics
    if (debug) cout << "sys done, new event" << endl;
    //delete[] goodVerticies;
    // delete[] valueMET;
    // delete[] valueMETPhi;
  }
  if(debug) cout<< "out of the loop" <<endl;
  if (SaveTree) {
    outfileTree->cd();
    AnalysisTree->Write();
    outfileTree->Close();
    cout<<"tree written."<<endl;
  }

  outfile->cd();
  h_prova->Write();
  Dir = outfile->mkdir("Signal");
  Dir = outfile->mkdir("Muons");
  Dir = outfile->mkdir("Electrons");
  Dir = outfile->mkdir("Jets");
  Dir = outfile->mkdir("ZDY");
  Dir = outfile->mkdir("Systematics");

  for(UInt_t i=0;i<ncuts;i++)
    for(UInt_t j=0;j<nchannels;j++){
      outfile->cd("ZDY");
      if (i>0 && i<6) h_ZDYplots[i][j]->Write();
     
      outfile->cd( "Signal" );
      if (i>0) h_signal[i][j]->Write();
      
      outfile->cd( "Muons" );
      h_muons[i][j]->Write();
      
      outfile->cd( "Electrons" );
      h_electrons[i][j]->Write();
      
      outfile->cd( "Jets" );
      h_jets[i][j]->Write();
      h_bjets[i][j]->Write();

      outfile->cd( "Systematics" );
      if (i>0) for (Int_t k=0;k<nsystematics;k++) {
	  h_systematics[i][j][k]->Write();
	}
    }
  outfile->cd();
  outfile->Close();
  cout<<"histo written."<<endl;

  
}

