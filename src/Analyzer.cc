#include "Analyzer.h"

Analyzer::Analyzer() {

  if (debug) cout<<"inizio"<<endl;
  
  h_prova = new TH1F("h_prova","p_T",100,0,1000);
 
  ncuts=10;
  nchannels=5;
  TString cut_name[] = {"particle", "twoLeptons", "twoJets", "MET", "oneBtag", "twoBtag", "Ctrl_Z", "Ctrl_noB", "Ctrl_ZornoB", "Ctrl_ZandnoB"};
  TString channel_name[] = {"all", "sameF","ee", "mumu", "emu"};
  // 0-all, 1-SF, 2 ee, 3 mumu, 4 emu, (5 mue if needed)
  h_muons = new MuonPlots**[ncuts];
  h_electrons = new ElectronPlots**[ncuts];
  h_jets = new JetPlots**[ncuts];
  h_bjets = new JetPlots**[ncuts];
  h_signal = new SignalPlots**[ncuts];

  for (UInt_t i=0;i<ncuts;i++) {
    h_muons[i] = new MuonPlots*[nchannels];
    h_electrons[i] = new ElectronPlots*[nchannels];
    h_jets[i] = new JetPlots*[nchannels];
    h_bjets[i] = new JetPlots*[nchannels];
    h_signal[i] = new SignalPlots*[nchannels];
  }
  
  for (UInt_t i=0;i<ncuts;i++)
    for (UInt_t j=0;j<nchannels;j++) {
    h_muons[i][j]     = new MuonPlots    ("muons_"    +cut_name[i]+"_"+channel_name[j]);
    h_electrons[i][j] = new ElectronPlots("electrons_"+cut_name[i]+"_"+channel_name[j]);
    h_jets[i][j]      = new JetPlots     ("jets_"     +cut_name[i]+"_"+channel_name[j]);
    h_bjets[i][j]     = new JetPlots     ("bjets_"    +cut_name[i]+"_"+channel_name[j]);
    h_signal[i][j]    = new SignalPlots  ("signal_"   +cut_name[i]+"_"+channel_name[j]);
  }
    
  if (debug) cout<<"fine"<<endl;
}

Analyzer::~Analyzer() { }

void Analyzer::SetName(TString name, Int_t version) {
  completename = name + "_";
  completename += version;
  completename += ".root";
  outfile = new TFile("histos/"+completename,"RECREATE");
  treename = name + "_tree_";
  treename += version;
  treename += ".root";
  outfileTree = new TFile("trees/"+treename,"RECREATE");
}

void Analyzer::SetWeight(TString name) {

  MCweight = integratedlumi * getXS(name);
  // lumi *  cs(pb) * gen filter efficiency / MCevents
  cout<<"MCweight = "<<MCweight<<endl;
 
}

void Analyzer::SetEvtN(Long64_t events) {
  entrieslimit = events;
  cout<<"Processing "<<events<<endl;
}

void Analyzer::Loop() {
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
  AnalysisTree->Branch("THT",&THT,"THT/F");
  AnalysisTree->Branch("TNMuon",&TNMuon,"TNMuon/I");
  AnalysisTree->Branch("TNElec",&TNElec,"TNElec/I");
  AnalysisTree->Branch("TNJets",&TNJets,"TNJets/I");
  AnalysisTree->Branch("TNJetsBtag",&TNJetsBtag,"TNJetsBtag/I");
  if (debug) cout<< "inizializing TLorentz" <<endl;
  AnalysisTree->Branch("TMuon_Charge", TMuon_Charge, "TMuon_Charge[TNMuon]/F");
  AnalysisTree->Branch("TMuon_Lorentz", "TLorentzVector", TMuon_Lorentz);
  AnalysisTree->Branch("TElec_Charge", TElec_Charge, "TElec_Charge[TNElec]/F");
  AnalysisTree->Branch("TElec_Lorentz", "TLorentzVector", TElec_Lorentz);
  AnalysisTree->Branch("TJet_Lorentz", "TLorentzVector", TJet_Lorentz);
  AnalysisTree->Branch("TJet_discriminant", TJet_discriminant, "TJet_discriminant[TNJets]/F");
  AnalysisTree->Branch("TBJet_Lorentz", "TLorentzVector", TBJet_Lorentz);
  //// done initialization

  cout << "total number of entries " <<nentries<<endl;

  if (debug) cout<< "loop begins" <<endl;

  fBTagSF = new BTagSFUtil("CSVM");

  // once we have data we must look a the pileup
  //  reweightPU = new ReweightPU("/uscms_data/d2/fgior8/LQntuple_18/CMSSW_5_3_14_patch2_LQ/src/code/MyDataPileupHistogram_69400.root");

  if (debug) cout<< "PU histos loaded" <<endl;


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
    if (!(jentry % 50000)) 
      cout << jentry << endl;

    if (!fChain) cout<<"problems with the input file"<<endl;
    fChain->GetEntry(jentry);
    
    // MET filters for now all OFF
    //----------------------------------------------------------------------------
    if (false) {
      if (T_EventF_trkPOG_logErrorTooManyClusters || T_EventF_trkPOG_toomanystripclus53X || T_EventF_trkPOG_manystripclus53X) return;
      if (!T_EventF_EcalDeadCellTriggerPrimitiveFilter || !T_EventF_trackingFailureFilter || !T_EventF_hcalLaserEventFilter || !T_EventF_ecalLaserCorrFilter || !T_EventF_eeBadScFilter) return;
    }

    // Vertex Select
    numberVertices = T_Vertex_ndof->size();
    goodVerticies = new Bool_t [numberVertices];
    if ( !isGoodEvent(numberVertices, *T_Vertex_isFake, *T_Vertex_ndof, *T_Vertex_x, *T_Vertex_y, *T_Vertex_z, goodVerticies) ) continue;
    
    for(UInt_t vv=0; vv<T_Vertex_ndof->size(); vv++) {
      if(goodVerticies[vv]) {
        VertexN=vv;
        break;
      }
    }

    if(debug) cout<< "object selection" <<endl;
    
    std::vector<Lepton> muonColl;
    Muon.SetPt(10);
    Muon.SetEta(2.4);
    Muon.SetRelIso(0.12);
    Muon.SetChiNdof(10);
    Muon.SetBSdxy(0.20);
    Muon.SetBSdz(0.50);
    Muon.MuonSelection(*T_Muon_IsPFMuon, *T_Muon_IsGlobalMuon, *T_Muon_Eta, *T_Muon_Pt, *T_Muon_deltaPt, *T_Muon_Px, *T_Muon_Py, *T_Muon_Pz, *T_Muon_Energy, *T_Muon_chargedHadronIsoR04, * T_Muon_neutralHadronIsoR04, * T_Muon_photonIsoR04, *T_Muon_Charge, *T_Muon_NValidHitsGTrk, *T_Muon_NValidPixelHitsInTrk, *T_Muon_NumOfMatchedStations, *T_Muon_NLayers, *T_Muon_NormChi2GTrk, *T_Muon_dxyInTrack, *T_Muon_dzInTrack, *T_Muon_sumPUPtR04, muonColl);
    
    std::vector<Lepton> electronColl;
    Electron.SetPt(10);
    Electron.SetEta(2.5);
    Electron.SetRelIso(0.15);
    Electron.SetBSdxy(0.02);
    Electron.SetBSdz(0.10);
    Electron.ElectronSelection(*T_Elec_isEB, *T_Elec_isEE, *T_Elec_SC_Eta, *T_Elec_Pt, *T_Elec_Energy, *T_Elec_Px, *T_Elec_Py, *T_Elec_Pz, *T_Elec_sumPhotonEt, *T_Elec_sumNeutralHadronEt, *T_Elec_sumChargedHadronPt, *T_Elec_Charge, *T_Elec_Charge, *T_Elec_passConversionVeto, *T_Elec_deltaEtaIn, *T_Elec_deltaEtaIn, *T_Elec_sigmaIetaIetaFull5by5, *T_Elec_HtoE, *T_Elec_ecalEnergy, *T_Elec_eSuperClusterOverP, *T_Elec_IPwrtPV, *T_Elec_dzwrtPV, *T_Elec_sumPUPt, electronColl);
    
    std::vector<Jet> jetColl;
    Jets.SetPt(30);
    Jets.SetEta(2.4);
    Jets.JetSelectionLeptonVeto(*T_JetAKCHS_IDLoose, *T_JetAKCHS_Eta, *T_JetAKCHS_Px, *T_JetAKCHS_Py, *T_JetAKCHS_Pz, *T_JetAKCHS_Et, *T_JetAKCHS_Energy, *T_JetAKCHS_NeutEmEnergyFrac, *T_JetAKCHS_NeutHadEnergyFrac, *T_JetAKCHS_CharEmEnergyFrac, *T_JetAKCHS_CharHadEnergyFrac, *T_JetAKCHS_ChargedMultiplicity, *T_JetAKCHS_nDaughters, *T_JetAKCHS_Tag_CombInclusiveSVtxV2, electronColl, muonColl, jetColl);

    std::vector<Jet> bjetColl;
    Jets.SetPt(30);
    Jets.SetEta(2.4);
    Jets.SetBdisc(0.423);
    Jets.BJetSelectionLeptonVeto(*T_JetAKCHS_IDLoose, *T_JetAKCHS_Eta, *T_JetAKCHS_Px, *T_JetAKCHS_Py, *T_JetAKCHS_Pz, *T_JetAKCHS_Et, *T_JetAKCHS_Energy, *T_JetAKCHS_NeutEmEnergyFrac, *T_JetAKCHS_NeutHadEnergyFrac, *T_JetAKCHS_CharEmEnergyFrac, *T_JetAKCHS_CharHadEnergyFrac, *T_JetAKCHS_ChargedMultiplicity, *T_JetAKCHS_nDaughters, *T_JetAKCHS_Tag_CombInclusiveSVtxV2, electronColl, muonColl, bjetColl);

    if(debug) cout<< "DONE object selection" <<endl;

    ///Filling standard particle plots
    
    if(muonColl.size()>0)
      for (Int_t i=0; i<muonColl.size(); i++) {
	TMuon_Lorentz[i] = muonColl[i].lorentzVec(); //tree variable
	TMuon_Charge[i] = muonColl[i].charge(); //tree variable
	index=muonColl[i].ilepton();
	h_muons[0][0]->Fill(weight, (Int_t) muonColl.size(), muonColl[i].lorentzVec(), muonColl[i].charge(), T_Muon_chargedHadronIsoR04->at(index), T_Muon_neutralHadronIsoR04->at(index), T_Muon_photonIsoR04->at(index), T_Muon_sumPUPtR04->at(index), muonColl[i].chiNdof(), muonColl[i].dxy_BS(), muonColl[i].dz_BS());
      }
    if (electronColl.size() > 0) {
      for (UInt_t i=0; i<electronColl.size(); i++) {
	TElec_Lorentz[i] = electronColl[i].lorentzVec(); //tree variable
	TElec_Charge[i] = electronColl[i].charge(); //tree variable
        index=electronColl[i].ilepton();
        h_electrons[0][0]->Fill(weight, (Int_t) electronColl.size(), electronColl[i].lorentzVec(), electronColl[i].charge(), T_Elec_chargedHadronIso->at(index), T_Elec_neutralHadronIso->at(index), T_Elec_photonIso->at(index), T_Elec_sumPUPt->at(index), electronColl[i].dxy_BS(), electronColl[i].dz_BS());
      }
    }
    HT=0;
    if(jetColl.size()>0)
      for (int i=0; i<jetColl.size(); i++) {
	TJet_Lorentz[i] = jetColl[i].lorentzVec(); //tree variable
	HT += jetColl[i].lorentzVec().Pt();
	index=jetColl[i].ijet();
	TJet_discriminant[i] = T_JetAKCHS_Tag_CombInclusiveSVtxV2->at(index); //tree variable
        h_jets[0][0]->Fill(weight, (Int_t) jetColl.size(), jetColl[i].lorentzVec(), T_JetAKCHS_Tag_HighPurTC->at(index), T_JetAKCHS_Tag_CombInclusiveSVtxV2->at(index), T_JetAKCHS_Tag_pfCombinedSVtx->at(index) );
      }
    if(bjetColl.size()>0)
      for (int i=0; i<bjetColl.size(); i++) {
	TBJet_Lorentz[i] = bjetColl[i].lorentzVec(); //tree variable
	index=bjetColl[i].ijet();
        h_bjets[0][0]->Fill(weight, (Int_t) bjetColl.size(), bjetColl[i].lorentzVec(), T_JetAKCHS_Tag_HighPurTC->at(index), T_JetAKCHS_Tag_CombInclusiveSVtxV2->at(index), T_JetAKCHS_Tag_pfCombinedSVtx->at(index) );
      }

    if(debug) cout<< "generic plots FILLED" <<endl;

    ///Filling standard particle plots END


    //Making leptons and jets selected collections
    std::vector<Jet> jetSelect;
    std::vector<Lepton> leptonSelect;
    Float_t invMtemp=0;
    Float_t ptSum_ee=0;
    Float_t ptSum_mm=0;
    Float_t ptSum_em=0;

    // it seems more convinent to take only two leptons, once the triggers are set we need to add the here FIXME 
    if (muonColl.size()==2 && electronColl.size()==0) {
      for (UInt_t i=0; i<muonColl.size()-1; i++)
	for (UInt_t j=i+1; j<muonColl.size(); j++) {
	  invMtemp=0;
	  if (muonColl[i].charge()*muonColl[j].charge()<0)
	    invMtemp = (muonColl[i].lorentzVec()+muonColl[j].lorentzVec()).M();
	  if (invMtemp>15) {
	    leptonSelect.push_back(muonColl[i]);
	    leptonSelect.push_back(muonColl[j]);
	    ptSum_mm = muonColl[i].lorentzVec().Pt() + muonColl[j].lorentzVec().Pt();
	    selectChannel.push_back(0);
	    selectChannel.push_back(1);
	    selectChannel.push_back(3);
	    goto twoMfound;
	  }
	}
    }
  twoMfound: 
    if (electronColl.size()==2 && muonColl.size()==0) {
      for (UInt_t i=0; i<electronColl.size()-1; i++)
	for (UInt_t j=i+1; j<electronColl.size(); j++) {
	  invMtemp=0;
	  if (electronColl[i].charge()*electronColl[j].charge()<0) {
	    invMtemp = (electronColl[i].lorentzVec()+electronColl[j].lorentzVec()).M();
	    ptSum_ee = electronColl[i].lorentzVec().Pt() + electronColl[j].lorentzVec().Pt();
	  }
	  if (invMtemp>15 && ptSum_ee>ptSum_mm) {
	    leptonSelect.clear();
	    leptonSelect.push_back(electronColl[i]);
	    leptonSelect.push_back(electronColl[j]);
	    selectChannel.push_back(0);
	    selectChannel.push_back(1);
	    selectChannel.push_back(2);
	    goto twoEfound;
	  }
	}
    }
  twoEfound:
    if (muonColl.size()==1 && electronColl.size()==1) {
      for (UInt_t i=0; i<muonColl.size(); i++)
	for (UInt_t j=0; j<electronColl.size(); j++) {
	  invMtemp=0;
	  if (muonColl[i].charge()*electronColl[j].charge()<0) {
	    invMtemp = (muonColl[i].lorentzVec()+electronColl[j].lorentzVec()).M();
	    ptSum_em= muonColl[i].lorentzVec().Pt() + electronColl[j].lorentzVec().Pt();
	  }
	  if (invMtemp>15 && ptSum_em>ptSum_ee && ptSum_em>ptSum_mm) {
	    leptonSelect.clear();
	    leptonSelect.push_back(muonColl[i]);
	    leptonSelect.push_back(electronColl[j]);
	    selectChannel.push_back(0);
	    selectChannel.push_back(4);
	    goto twoLfound;
	  }
	}
    }
  twoLfound:

    if (leptonSelect.size()<2) continue; // no less than two leptons


    // Z veto applied only for same flavor
    if ( ((leptonSelect[0].leptonType()==0 && leptonSelect[1].leptonType()==0) || (leptonSelect[0].leptonType()==1 && leptonSelect[1].leptonType()==1)) && ( fabs((leptonSelect[0].lorentzVec()+leptonSelect[1].lorentzVec()).M()-Mass_Z)<15 ) )
      Zveto=false;
    else
      Zveto=true;

    for (UInt_t n=0;n<selectChannel.size();n++) {
      UInt_t channel = selectChannel[n];	
      h_signal[1][channel]->Fill(numberVertices, T_MET_ET, T_MET_Phi, leptonSelect, jetSelect, weight, channel, 1);
    }
    
    if (debug) cout << "two leptons CHECKED" << endl;
    
    if (jetColl.size()<2) continue;
    
    if (bjetColl.size()==0) {
      jetSelect.push_back(jetColl[0]);
      jetSelect.push_back(jetColl[1]);
    }
    else if (bjetColl.size()==1) {
      if (bjetColl[0].ijet() != jetColl[0].ijet()) {
	jetSelect.push_back(jetColl[0]);
	jetSelect.push_back(bjetColl[0]);
      }
      else {
	jetSelect.push_back(jetColl[1]);
	jetSelect.push_back(bjetColl[0]);
      }
    }
    else if (bjetColl.size()>=2) {
      jetSelect.push_back(bjetColl[0]);
      jetSelect.push_back(bjetColl[1]);
    }

    if (debug) cout << "two jets CHECKED" << endl;

    // filling all tree variables
    if (jetSelect.size()>1 && leptonSelect.size()>1) {
      TWeight = weight;
      TNPV = numberVertices;
      TNJets = jetColl.size();     
      TNJetsBtag = bjetColl.size();
      TNMuon = muonColl.size();
      TNElec = electronColl.size();
      TMET = T_MET_ET;
      TMET_Phi = T_MET_Phi;
      THT = HT;
      TMT2ll = getMT2(leptonSelect[0].lorentzVec(), leptonSelect[1].lorentzVec(), T_MET_ET, T_MET_Phi);
      TMT2bb = getMT2bb(jetSelect, leptonSelect, T_MET_ET, T_MET_Phi);
      TMT2lblb = getMT2lblb(jetSelect, leptonSelect, T_MET_ET, T_MET_Phi);
      AnalysisTree->Fill();
    }


    // selection events, signal and control regions
    if (leptonSelect.size()>1 && Zveto && jetColl.size()>1)
      selectionStep.push_back(2);
    if (leptonSelect.size()>1 && Zveto && jetColl.size()>1 && T_MET_ET>40)
      selectionStep.push_back(3);
    if (leptonSelect.size()>1 && Zveto && jetColl.size()>1 && T_MET_ET>40 && bjetColl.size()>0)
      selectionStep.push_back(4);
    if (leptonSelect.size()>1 && Zveto && jetColl.size()>1 && T_MET_ET>40 && bjetColl.size()>1)
      selectionStep.push_back(5);
    if (leptonSelect.size()>1 && !Zveto && jetColl.size()>1)
      selectionStep.push_back(6);
    if (leptonSelect.size()>1 && jetColl.size()>1 && T_MET_ET>40 && bjetColl.size()==0)
      selectionStep.push_back(7);
    if (leptonSelect.size()>1 && jetColl.size()>1 && T_MET_ET>40 && (bjetColl.size()==0 || !Zveto))
      selectionStep.push_back(8);
    if (leptonSelect.size()>1 && jetColl.size()>1 && T_MET_ET>40 && (bjetColl.size()==0 && !Zveto))
      selectionStep.push_back(9);

	
    for (UInt_t m=0;m<selectionStep.size();m++) {
      for (UInt_t n=0;n<selectChannel.size();n++) {
	UInt_t cut = selectionStep[m];
	UInt_t channel = selectChannel[n];
	
	h_signal[cut][channel]->Fill(numberVertices, T_MET_ET, T_MET_Phi, leptonSelect, jetSelect, weight, channel, cut);
	
	for (Int_t i=0; i<muonColl.size(); i++) {
	  index=muonColl[i].ilepton();
	  h_muons[cut][channel]->Fill(weight, (Int_t) muonColl.size(), muonColl[i].lorentzVec(), muonColl[i].charge(), T_Muon_chargedHadronIsoR04->at(index), T_Muon_neutralHadronIsoR04->at(index), T_Muon_photonIsoR04->at(index), T_Muon_sumPUPtR04->at(index), muonColl[i].chiNdof(), muonColl[i].dxy_BS(), muonColl[i].dz_BS());
	}
	for (UInt_t i=0; i<electronColl.size(); i++) {
	  index=electronColl[i].ilepton();
	  h_electrons[cut][channel]->Fill(weight, (Int_t) electronColl.size(), electronColl[i].lorentzVec(), electronColl[i].charge(), T_Elec_chargedHadronIso->at(index), T_Elec_neutralHadronIso->at(index), T_Elec_photonIso->at(index), T_Elec_sumPUPt->at(index), electronColl[i].dxy_BS(), electronColl[i].dz_BS());
	}
	for (int i=0; i<jetColl.size(); i++) {
	  index=jetColl[i].ijet();
	  h_jets[cut][channel]->Fill(weight, (Int_t) jetColl.size(), jetColl[i].lorentzVec(), T_JetAKCHS_Tag_HighPurTC->at(index), T_JetAKCHS_Tag_CombInclusiveSVtxV2->at(index), T_JetAKCHS_Tag_pfCombinedSVtx->at(index) );
	}
	for (int i=0; i<bjetColl.size(); i++) {
	index=bjetColl[i].ijet();
	h_bjets[cut][channel]->Fill(weight, (Int_t) bjetColl.size(), bjetColl[i].lorentzVec(), T_JetAKCHS_Tag_HighPurTC->at(index), T_JetAKCHS_Tag_CombInclusiveSVtxV2->at(index), T_JetAKCHS_Tag_pfCombinedSVtx->at(index) );
	}
      }
    }
    selectionStep.clear();
    selectChannel.clear();
  }
  if(debug) cout<< "out of the loop" <<endl;
  outfileTree->cd();
  AnalysisTree->Write();
  outfileTree->Close();
  cout<<"program ends."<<endl;

  outfile->cd();
  h_prova->Write();
  Dir = outfile->mkdir("Signal");
  Dir = outfile->mkdir("Muons");
  Dir = outfile->mkdir("Electrons");
  Dir = outfile->mkdir("Jets");

  for(UInt_t i=0;i<ncuts;i++)
    for(UInt_t j=0;j<nchannels;j++){
    outfile->cd( "Signal" );
    if (i>0) h_signal[i][j]->Write();
    
    outfile->cd( "Muons" );
    h_muons[i][j]->Write();

    outfile->cd( "Electrons" );
    h_electrons[i][j]->Write();

    outfile->cd( "Jets" );
    h_jets[i][j]->Write();
    h_bjets[i][j]->Write();
  }
  outfile->cd();
  outfile->Close();
  cout<<"histo written."<<endl;

  
}

