#include "Analyzer.h"
#include "FillTandG.h"

Analyzer::Analyzer() {

  if (debug) cout<<"inizio"<<endl;

  // PILEUP //
  reweightPU = new ReweightPU("/gpfs/csic_projects/cms/fgior8/PileUpDistr/EnDataPileupHistogram.root");
  //if (debug) cout<< "PU histos loaded" <<endl;
  // Tracker HIP //
  HIP_muon = TFile::Open("/gpfs/csic_projects/cms/fgior8/ScaleFactors/ratios.root");
  hHIP_muon = (TGraphAsymmErrors*) HIP_muon->Get("ratio_eta")->Clone("HIP_muon");
  // Scale Factors ///
  // --first for the trigger-- //
  MuSF_trig   = TFile::Open("/gpfs/csic_projects/cms/fgior8/ScaleFactors/HLT_Efficiencies_4fb_2016.root"); 
  ElSF_trig   = TFile::Open("/gpfs/csic_projects/cms/fgior8/ScaleFactors/HLT_Efficiencies_4fb_2016.root");
  MuElSF_trig = TFile::Open("/gpfs/csic_projects/cms/fgior8/ScaleFactors/triggerSummary_emu_13TeV_RunD.root");
  if(!MuElSF_trig)
    cout << "ERROR [MuonSF_trig]: Could not open file " << MuSF_trig << " or " << ElSF_trig << " or " << MuElSF_trig << "!"  << endl;
  // --second for the ID and Isolation-- //
  MuSF_ID      = TFile::Open("/gpfs/csic_projects/cms/fgior8/ScaleFactors/MuonID_Z_RunBCD_prompt80X_7p65.root");
  MuSF_ISO     = TFile::Open("/gpfs/csic_projects/cms/fgior8/ScaleFactors/MuonIso_Z_RunBCD_prompt80X_7p65.root");
  ElSF_IDISO   = TFile::Open("/gpfs/csic_projects/cms/fgior8/ScaleFactors/egammaEffi_tight_SF2D.root");
  if(!MuSF_ISO || !MuSF_ID || !ElSF_IDISO)
    cout << "ERROR [MuonSF_IDISO]: Could not open file " << MuSF_ID << " or " << MuSF_ISO << " or " << ElSF_IDISO << "!"  << endl;
  if (debug) cout<< "all files loaded" <<endl;
  
  MuSF_ID->cd("MC_NUM_TightIDandIPCut_DEN_genTracks_PAR_pt_spliteta_bin1");
  TDirectory *dirID = gDirectory;
  hmuIDSF = (TH2F*) dirID->Get("abseta_pt_ratio")->Clone("muIDSF");
  MuSF_ISO->cd("MC_NUM_TightRelIso_DEN_TightID_PAR_pt_spliteta_bin1");
  TDirectory *dirISO = gDirectory;
  hmuISOSF         = (TH2F*) dirISO->Get("abseta_pt_ratio")->Clone("muISOSF");
  hmumuTriggerSF8  = (TH2F*) MuSF_trig->Get("hist2dnum_Mu8__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL")->Clone("mumuTriggerSF8");
  hmumuTriggerSF17 = (TH2F*) MuSF_trig->Get("hist2dnum_Mu17__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL")->Clone("mumuTriggerSF17");
  if(!hmuIDSF || !hmuISOSF || !hmumuTriggerSF8 || !hmumuTriggerSF17)
    cout << "ERROR [MuonSF]: Could not find histogram for SF reweighting" << endl;
  
  heIDSF         = (TH2F*) ElSF_IDISO->Get("EGamma_SF2D")->Clone("eIDSF");
  heeTriggerSF12 = (TH2F*) ElSF_trig ->Get("hist2dnum_Ele12_CaloIdL_TrackIdL_IsoVL__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL")->Clone("eeTriggerSF12");
  heeTriggerSF23 = (TH2F*) ElSF_trig ->Get("hist2dnum_Ele23_CaloIdL_TrackIdL_IsoVL__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL")->Clone("eeTriggerSF23");
  if(!heIDSF || !heeTriggerSF12 || !heeTriggerSF23)
    cout << "ERROR [ElectronSF]: Could not find histogram for SF reweighting" << endl;

  hmueTriggerSF = (TH2F*) MuElSF_trig->Get("scalefactor_eta2d_with_syst")->Clone("mueTriggerSF");
  if(!hmueTriggerSF)
    cout << "ERROR [MuonElectronSF]: Could not find histogram for SF reweighting" << endl;
  
  h_prova = new TH1F("h_prova","p_T",100,0,1000);
  h_VertexNoReweight = new TH1F("h_VertexNoReweight","n Vertices no reweighted", 60,0,60);
  h_VertexPostReweight = new TH1F("h_VertexPostReweight","n Vertices reweighted", 60,0,60);
 
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

void Analyzer::SetWeight(TString name, Long64_t eventProcessed) {
  // lumi *  cs(pb) * gen filter efficiency / MCevents
  MCweight = integratedlumi * getXS_D(name, eventProcessed);
  name.Contains("Muon") || name.Contains("EG") ? isData=true : isData=false;
  name.Contains("MCatNLO") ? MCatNLO=true : MCatNLO=false;
  name.Contains("DoubleEG") ? isDoubleEl=true : isDoubleEl=false;
  name.Contains("MuEG") ? isMuEG=true : isMuEG=false;
  name.Contains("DoubleMuon") ? isDoubleMu=true : isDoubleMu=false;
  if(isData) MCweight = 1;
  cout<<"MCweight = "<<MCweight<<endl;
}

void Analyzer::SetEvtN(Long64_t events) {
  entrieslimit = events;
  cout<<"Processing "<<events<<endl;
}

void Analyzer::Loop() {
  AnalysisTree = new TTree("sTopTree","Optimization tree");
  FillTandG TangG(AnalysisTree);
  cout << "total number of entries " <<nentries<<endl;

  if (debug) cout<< "loop begins" <<endl;

  BTagSF = new BTagSFUtil("mujets", "CSVv2", "Loose");

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


    /// T2tt  SELECT MASS POINT ///
    //if (fabs(GenSusyMScan1-950)>110) continue;  //Stop mass
    //if (fabs(GenSusyMScan2-450)>110) continue;  //LSP mass

    weight = MCweight;
 
    /// only for MC atNLO normalization ///
    if (MCatNLO && !isData)
      weight *= genWeight;
    //genWeight>0 ? weight *= 1. : weight *= -1.;
    
    // MET filters
    //----------------------------------------------------------------------------
    if (!(Flag_HBHENoiseFilter && Flag_CSCTightHaloFilter && Flag_goodVertices && Flag_eeBadScFilter && Flag_EcalDeadCellTriggerPrimitiveFilter)) continue;

    // Vertex Select
    numberVertices = nVert;

    Float_t valueMET[] = {met_pt, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    Float_t valueMETPhi[] = {met_phi, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    h_VertexNoReweight->Fill(numberVertices, weight);
    /// ***PU reweghting*** ///
    if (!isData)
      weight *= reweightPU->GetWeight(nTrueInt);
      //weight *= puWeight;
    h_VertexPostReweight->Fill(numberVertices, weight);


    if(debug) cout<< "object selection" <<endl;
    
    //cleaning all collections at the beginning of each event///
    muonColl.clear(); muonCollLoose.clear(); electronColl.clear(); electronCollLoose.clear();
    genElec.clear(); genNuElec.clear(); genMuon.clear(); genNuMuon.clear(); hardBquark.clear(); genLightquark.clear();
    jetGenColl.clear(); leptonGenColl.clear();
    ///cleaning vectors//
    for (UInt_t kk=0;kk<nsystematics+1;kk++) {//nsystematics
      jetColl[kk].clear(); bjetColl[kk].clear(); jetHTColl[kk].clear();
    }
    //cleaning selection vectors
    selectionStep.clear();    selectChannel.clear();   selectionStepZDY.clear();
    jetSelect.clear();    leptonSelect.clear();
    
    Muon.SetPt(15);
    Muon.SetEta(2.4);
    Muon.SetRelIso(0.15);
    Muon.SetChiNdof(10);
    Muon.SetBSdxy(0.20);
    Muon.SetBSdz(0.50);
    Muon.MuonSelectionWithLoose(nLepGood, LepGood_pdgId, LepGood_pfMuonId, LepGood_isGlobalMuon, LepGood_isTrackerMuon, LepGood_eta, LepGood_pt, LepGood_px, LepGood_py, LepGood_pz, LepGood_energy, LepGood_relIso04, LepGood_charge, LepGood_trackerHits, LepGood_pixelLayers, LepGood_nStations, LepGood_trackerLayers, LepGood_globalTrackChi2, LepGood_dxy, LepGood_dz, LepGood_mcMatchId, muonColl, muonCollLoose);

    Electron.SetPt(15);
    Electron.SetEta(2.5);
    Electron.SetRelIso(0.15);
    Electron.SetBSdxy(0.02);
    Electron.SetBSdz(0.10);
    Electron.ElectronSelectionWithLoose(nLepGood, LepGood_pdgId, LepGood_etaSc, LepGood_pt, LepGood_px, LepGood_py, LepGood_pz, LepGood_energy, LepGood_relIso03, LepGood_charge, LepGood_convVeto, LepGood_lostHits, LepGood_dEtaScTrkIn, LepGood_dPhiScTrkIn, LepGood_sigmaIEtaIEta, LepGood_hadronicOverEm, LepGood_eInvMinusPInv, LepGood_dxy, LepGood_dz, LepGood_mcMatchId, electronColl, electronCollLoose);

    if ( (electronColl.size()+muonColl.size())>1 )
      h_prova->Fill(10);
    // check MC matching ID
    if (!isData) {
      for (UInt_t i=0;i<electronColl.size();i++) {
	if (fabs(LepGood_mcMatchId[electronColl[i].ilepton()]==0))
	  electronColl.erase(electronColl.begin()+i);
      }
      for (UInt_t i=0;i<muonColl.size();i++) {
	if (fabs(LepGood_mcMatchId[muonColl[i].ilepton()]==0))
	  muonColl.erase(muonColl.begin()+i);
      }
    }
    if ( (electronColl.size()+muonColl.size())>1 )
      h_prova->Fill(100);

    GenPart.GenPartSelection(nGenPart, GenPart_pdgId, GenPart_status, GenPart_motherId, GenPart_grandmotherId, GenPart_sourceId, GenPart_charge, GenPart_pt, GenPart_eta, GenPart_phi, GenPart_mass, genElec, genNuElec, genMuon, genNuMuon, hardBquark, genLightquark);
    
    if(debug) cout<< "selecting jets" <<endl;
    Float_t tmp_sys[] = {0,0};
    Jets.SetPt(10);
    Jets.SetEta(5.0);
    Jets.JetSelectionLeptonVeto_JU(nJet, tmp_sys, Jet_id, Jet_pt, Jet_eta, Jet_px, Jet_py, Jet_pz, Jet_energy, Jet_btagCMVA, Jet_hadronFlavour, electronColl, muonColl, jetHTColl);
    
    Jets.SetPt(30);
    Jets.SetEta(2.4);
    Jets.SetBdisc(0.605);
    Jets.JetSelectionLeptonVeto_andB_JU(nJet, tmp_sys, Jet_id, Jet_pt, Jet_eta, Jet_px, Jet_py, Jet_pz, Jet_energy, Jet_btagCSV, Jet_hadronFlavour, electronColl, muonColl, jetColl, bjetColl);

    bjetColl[0].clear();
    for(UInt_t i=0;i<jetColl[0].size();i++) {
      if (!isData && Jet_hadronFlavour[jetColl[0][i].ijet()]!=Jet_mcMatchFlav[jetColl[0][i].ijet()])
	jetColl[0].erase(jetColl[0].begin()+i);
      if(isData) {
	if( BTagSF->IsTagged(jetColl[0][i].btag_disc(), -999999, jetColl[0][i].lorentzVec().Pt(), jetColl[0][i].lorentzVec().Eta()) )
	  bjetColl[0].push_back(jetColl[0][i]);
      }
      else {
	if( BTagSF->IsTagged(jetColl[0][i].btag_disc(), jetColl[0][i].flavour(), jetColl[0][i].lorentzVec().Pt(), jetColl[0][i].lorentzVec().Eta()) )
	  bjetColl[0].push_back(jetColl[0][i]);
      }
    }
    if ( jetColl[0].size()>1 )
      h_prova->Fill(1000);

    ///Filling standard particle plots
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
    if(jetHTColl[0].size()>0)
      for (int i=0; i<jetHTColl[0].size(); i++) {
	index=jetHTColl[0][i].ijet();
	h_HTjets[0][0]->Fill(weight, (Int_t) jetHTColl[0].size(), jetHTColl[0][i].lorentzVec(), Jet_btagCSV[index], Jet_btagCMVA[index] );
      }
    if(jetColl[0].size()>0)
      for (int i=0; i<jetColl[0].size(); i++) {
	index=jetColl[0][i].ijet();
	h_jets[0][0]->Fill(weight, (Int_t) jetColl[0].size(), jetColl[0][i].lorentzVec(), Jet_btagCSV[index], Jet_btagCMVA[index] );
      }
    if(bjetColl[0].size()>0)
      for (int i=0; i<bjetColl[0].size(); i++) {
	index=bjetColl[0][i].ijet();
	h_bjets[0][0]->Fill(weight, (Int_t) bjetColl[0].size(), bjetColl[0][i].lorentzVec(), Jet_btagCSV[index], Jet_btagCMVA[index] );
      }
    if(debug) cout<< "generic plots FILLED" <<endl;
    ///Filling standard particle plots END


    invMtemp=0.;
    if (electronCollLoose.size()==2 && muonCollLoose.size()==0 && electronColl.size()==2 && (!isData || (isDoubleEl && HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v>0) ) ) {
      if (electronColl[0].charge()*electronColl[1].charge()<0 && electronColl[0].lorentzVec().Pt()>25) 
	invMtemp = (electronColl[0].lorentzVec()+electronColl[1].lorentzVec()).M();
      if (invMtemp>15) {
	leptonSelect.clear();
	leptonSelect.push_back(electronColl[0]);
	leptonSelect.push_back(electronColl[1]);
	selectChannel.push_back(0);
	selectChannel.push_back(1);
	selectChannel.push_back(2);
	if (!isData) {
	  weight *= ElTriggersLumi/integratedlumi;
	  //Trigger EE Eff
	  electronColl[0].lorentzVec().Pt()>=500. ? ptSFlimit=499. : ptSFlimit=electronColl[0].lorentzVec().Pt();
	  weight *= heeTriggerSF23->GetBinContent( heeTriggerSF23->FindBin( fabs(ptSFlimit), fabs(electronColl[0].lorentzVec().Eta()) ) );
	  electronColl[1].lorentzVec().Pt()>=500. ? ptSFlimit=499. : ptSFlimit=electronColl[1].lorentzVec().Pt();
	  weight *= heeTriggerSF12->GetBinContent( heeTriggerSF12->FindBin( fabs(ptSFlimit), fabs(electronColl[1].lorentzVec().Eta()) ) );
	}
	goto channelfound;
      }
    }
    if (electronCollLoose.size()==0 && muonCollLoose.size()==2 && muonColl.size()==2 && (!isData || (isDoubleMu && HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v>0) ) ) {
      if (muonColl[0].charge()*muonColl[1].charge()<0 && muonColl[0].lorentzVec().Pt()>25) 
	invMtemp = (muonColl[0].lorentzVec()+muonColl[1].lorentzVec()).M();
      if (invMtemp>15) {
	leptonSelect.push_back(muonColl[0]);
	leptonSelect.push_back(muonColl[1]);
	selectChannel.push_back(0);
	selectChannel.push_back(1);
	selectChannel.push_back(3);
	if (!isData) {
	  weight *= MuTriggersLumi/integratedlumi;
	  //Trigger MuMu Eff
	  muonColl[0].lorentzVec().Pt()>=500. ? ptSFlimit=499. : ptSFlimit=muonColl[0].lorentzVec().Pt();
	  weight *= hmumuTriggerSF17->GetBinContent( hmumuTriggerSF17->FindBin( fabs(ptSFlimit), fabs(muonColl[0].lorentzVec().Eta()) ) );
	  muonColl[1].lorentzVec().Pt()>=500. ? ptSFlimit=499. : ptSFlimit=muonColl[1].lorentzVec().Pt();
	  weight *= hmumuTriggerSF8->GetBinContent( hmumuTriggerSF8->FindBin( fabs(ptSFlimit), fabs(muonColl[1].lorentzVec().Eta()) ) );
	}
	goto channelfound;
      }
    }
    if (electronCollLoose.size()==1 && electronColl.size()==1 && muonCollLoose.size()==1 && muonColl.size()==1 && (!isData || (isMuEG && (HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v>0 || HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v>0) ) ) ) {
      if (muonColl[0].charge()*electronColl[0].charge()<0 && (electronColl[0].lorentzVec().Pt()>25 || muonColl[0].lorentzVec().Pt()>25)) 
	invMtemp = (muonColl[0].lorentzVec()+electronColl[0].lorentzVec()).M();
      if (invMtemp>15) {
	leptonSelect.clear();
	leptonSelect.push_back(muonColl[0]);
	leptonSelect.push_back(electronColl[0]);
	selectChannel.push_back(0);
	selectChannel.push_back(4);
	//Trigger SF
	if (!isData) {
	  weight *= hmueTriggerSF->GetBinContent( hmueTriggerSF->FindBin( fabs(leptonSelect[0].lorentzVec().Eta()),fabs(leptonSelect[1].lorentzVec().Eta()) ) );
	}
	goto channelfound;
      }
    }
  channelfound:
    if (leptonSelect.size()<2) continue; // no less than two leptons
    if(debug) cout<< "two leptons found" <<endl;

    // applying scaling factor for ID
    if (!isData) {
      for (UInt_t i=0; i<leptonSelect.size(); i++) {
	//ID SF applied per lepton
	leptonSelect[i].lorentzVec().Pt()>199. ? ptSFlimit=199. : ptSFlimit=leptonSelect[i].lorentzVec().Pt();
	if (leptonSelect[i].leptonType()==1) {
	  weight *= heIDSF->GetBinContent( heIDSF->FindBin( leptonSelect[i].lorentzVec().Eta(),ptSFlimit ) );
	}
	if (leptonSelect[i].leptonType()==0) {
	  if (ptSFlimit!=199.) leptonSelect[i].lorentzVec().Pt()<21. ? ptSFlimit=21. : ptSFlimit=leptonSelect[i].lorentzVec().Pt();
	  weight *= hmuIDSF->GetBinContent( hmuIDSF->FindBin( fabs(leptonSelect[i].lorentzVec().Eta()),ptSFlimit ) );		    
	  weight *= hmuISOSF->GetBinContent( hmuISOSF->FindBin( fabs(leptonSelect[i].lorentzVec().Eta()),ptSFlimit ) );
	  weight *= hHIP_muon->Eval(leptonSelect[i].lorentzVec().Eta());
	}
      }
    }
    if(debug) cout<< "trigger and ID weights applied" <<endl;
  
    if(debug) cout<< "DONE object selection" <<endl;
    for (Variation sysvar=(Analyzer::Variation)0;sysvar<nsystematics+1;sysvar=(Analyzer::Variation)(sysvar+1)) {
      if (debug) cout << "Looking at sys n " << sysvar << endl;
      
      HT=0;
      for (int i=0; i<jetHTColl[sysvar].size(); i++) 
	HT += jetHTColl[sysvar][i].lorentzVec().Pt();

      // Z veto applied only for same flavor
      if ( ((leptonSelect[0].leptonType()==0 && leptonSelect[1].leptonType()==0) || (leptonSelect[0].leptonType()==1 && leptonSelect[1].leptonType()==1)) &&
	   ( fabs((leptonSelect[0].lorentzVec()+leptonSelect[1].lorentzVec()).M()-Mass_Z)<15 ) )
	Zveto=false;
      else
	Zveto=true;
    
      // filling plots for the dilepton selection
      for (UInt_t n=0;n<selectChannel.size();n++) {
	UInt_t channel = selectChannel[n];
	if (sysvar==CentralValue) {
	  h_signal[1][channel]->Fill(numberVertices, valueMET[sysvar], valueMETPhi[sysvar], leptonSelect, jetSelect, weight, channel, 1);
	  for (Int_t i=0; i<muonColl.size(); i++) {
	    index=muonColl[i].ilepton();
	    h_muons[1][channel]->Fill(weight, (Int_t) muonColl.size(), muonColl[i].lorentzVec(), muonColl[i].charge(), muonColl[i].relIso(), muonColl[i].chiNdof(), muonColl[i].dxy_BS(), muonColl[i].dz_BS());
	  }
	  for (UInt_t i=0; i<electronColl.size(); i++) {
	    index=electronColl[i].ilepton();
	    h_electrons[1][channel]->Fill(weight, (Int_t) electronColl.size(), electronColl[i].lorentzVec(), electronColl[i].charge(), electronColl[i].relIso(), electronColl[i].dxy_BS(), electronColl[i].dz_BS());
	  }
	  for (int i=0; i<jetColl[sysvar].size(); i++) {
	    index=jetColl[sysvar][i].ijet();
	    h_jets[1][channel]->Fill(weight, (Int_t) jetColl[sysvar].size(), jetColl[sysvar][i].lorentzVec(), Jet_btagCSV[index], Jet_btagCMVA[index] );
	  }
	  for (int i=0; i<bjetColl[sysvar].size(); i++) {
	    index=bjetColl[sysvar][i].ijet();
	    h_bjets[1][channel]->Fill(weight, (Int_t) bjetColl[sysvar].size(), bjetColl[sysvar][i].lorentzVec(), Jet_btagCSV[index], Jet_btagCMVA[index] );
	  }
	}
	else
	  h_systematics[1][channel][sysvar-1]->Fill(numberVertices, valueMET[sysvar], valueMETPhi[sysvar], leptonSelect, jetSelect, weight, channel, 1);
	
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

      //  GenPart.GenJetSelection(Jet_mcPx, Jet_mcPy, Jet_mcPz, Jet_mcEnergy, Jet_mcFlavour, hardBquark, jetSelect, jetGenColl);
      TLorentzVector lVec;
      Float_t dummy = 0.0;
      for (UInt_t i=0; i<2; i++) {
	lVec.SetPxPyPzE(Jet_mcPx[jetSelect[i].ijet()],Jet_mcPy[jetSelect[i].ijet()],Jet_mcPz[jetSelect[i].ijet()],Jet_mcEnergy[jetSelect[i].ijet()]);
	jetGenColl.push_back( Jet(lVec, Jet_mcFlavour[jetSelect[i].ijet()], 0.0, jetSelect[i].ijet()) );
	lVec.SetPxPyPzE(LepGood_mcPx[leptonSelect[i].ilepton()],LepGood_mcPy[leptonSelect[i].ilepton()],LepGood_mcPz[leptonSelect[i].ilepton()],LepGood_mcEnergy[leptonSelect[i].ilepton()]);
	leptonGenColl.push_back( Lepton(leptonSelect[i].leptonType(), leptonSelect[i].ilepton(), lVec, dummy, dummy, dummy, dummy, leptonSelect[i].charge(), leptonSelect[i].fakeType(), leptonSelect[i].looseTight(), dummy) );
      }

      if (debug) cout << "gen jets and leptons CHECKED" << endl;

      float vetoMT2ll = getMT2(leptonSelect[0].lorentzVec(), leptonSelect[1].lorentzVec(), valueMET[0], valueMETPhi[0]);
      float vetoMT2bb = getMT2bb(jetSelect, leptonSelect, valueMET[0], valueMETPhi[0]);
      float vetoMT2lblb = getMT2lblb(jetSelect, leptonSelect, valueMET[0], valueMETPhi[0]);

      // filling all tree variables
      if (sysvar==CentralValue && SaveTree) {
	//	if (!isData && (genElec.size()>0 || genMuon.size()>0) )
	TangG.SetGenVariables(AnalysisTree, genElec, genNuElec, genMuon, genNuMuon, hardBquark, leptonGenColl, jetGenColl, met_genPt, met_genPhi);
	//	if (jetSelect.size()>1 && leptonSelect.size()>1) 
	TangG.SetRecoVariables(AnalysisTree, weight, numberVertices, jetSelect, leptonSelect, valueMET[0], valueMETPhi[0], HT, muonColl, electronColl, jetColl[0], bjetColl[0]);
	TangG.FillVariables(AnalysisTree);
      }
      /// filled the tree
      if (debug) cout << "-- tree filled --" << endl;

      if (Blind && (vetoMT2ll>80 || vetoMT2bb>180 || vetoMT2lblb>180)) continue;
      
      met_cut = 40;

      // selection events, signal and control regions
      if (leptonSelect.size()>1 && Zveto && jetSelect.size()>1)
	selectionStep.push_back(2);
      if (leptonSelect.size()>1 && Zveto && jetSelect.size()>1 && valueMET[sysvar]>met_cut)
	selectionStep.push_back(3);
      if (leptonSelect.size()>1 && Zveto && jetSelect.size()>1 && valueMET[sysvar]>met_cut && bjetColl[sysvar].size()>0)
	selectionStep.push_back(4);
      if (leptonSelect.size()>1 && Zveto && jetSelect.size()>1 && valueMET[sysvar]>met_cut && bjetColl[sysvar].size()>1)
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
      if (leptonSelect.size()>1 && jetSelect.size()>1)
	selectionStepZDY.push_back(2);
      if (leptonSelect.size()>1 && jetSelect.size()>1 && valueMET[sysvar]>met_cut)
	selectionStepZDY.push_back(3);
      if (leptonSelect.size()>1 && jetSelect.size()>1 && valueMET[sysvar]>met_cut && bjetColl[sysvar].size()>0)
	selectionStepZDY.push_back(4);
      if (leptonSelect.size()>1 && jetSelect.size()>1 && valueMET[sysvar]>met_cut && bjetColl[sysvar].size()>1)
	selectionStepZDY.push_back(5);
      if (debug) cout << "Filling final histos" << endl;
      if (sysvar==CentralValue) {
	for (UInt_t n=0;n<selectChannel.size();n++){
	  channel = selectChannel[n];
	  for (UInt_t m=0;m<selectionStep.size();m++) {
	    cut = selectionStep[m];
	    h_signal[cut][channel]->Fill(numberVertices, valueMET[sysvar], valueMETPhi[sysvar], leptonSelect, jetSelect, weight, channel, cut);
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
    TangG.WriteVariables(AnalysisTree);
    outfileTree->Close();
    cout<<"tree written."<<endl;
  }

  outfile->cd();
  h_prova->Write();
  h_VertexNoReweight->Write();
  h_VertexPostReweight->Write();
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

