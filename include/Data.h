//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Nov  4 21:29:28 2015 by ROOT version 5.34/02
// from TTree tree/treeProducerSusyMultilepton
// found on file: /gpfs/csic_projects/cms/palencia/heppyTrees/oct27/27Oct2015/Tree_TTLep_pow_0.root
//////////////////////////////////////////////////////////

#ifndef Data_h
#define Data_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class Data {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
   Long64_t nentries;

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          lumi;
   ULong64_t       evt;
   Int_t           isData;
   Float_t         xsec;
   Float_t         puWeight;
   Int_t           nTrueInt;
   Float_t         genWeight;
   Float_t         rho;
   Float_t         rhoCN;
   Int_t           nVert;
   Int_t           GenSusyMScan1;
   Int_t           GenSusyMScan2;
   Int_t           GenSusyMScan3;
   Int_t           GenSusyMScan4;
   Int_t           GenSusyMGluino;
   Int_t           GenSusyMGravitino;
   Int_t           GenSusyMStop;
   Int_t           GenSusyMSbottom;
   Int_t           GenSusyMStop2;
   Int_t           GenSusyMSbottom2;
   Int_t           GenSusyMSquark;
   Int_t           GenSusyMNeutralino;
   Int_t           GenSusyMNeutralino2;
   Int_t           GenSusyMNeutralino3;
   Int_t           GenSusyMNeutralino4;
   Int_t           GenSusyMChargino;
   Int_t           GenSusyMChargino2;
   Float_t         minDrllAFSS;
   Float_t         m3l;
   Int_t           hbheFilterNew50ns;
   Int_t           hbheFilterNew25ns;
   Int_t           hbheFilterIso;
   Float_t         met_trkPt;
   Float_t         met_trkPhi;
   Float_t         metNoHF_trkPt;
   Float_t         metNoHF_trkPhi;
   Float_t         HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v;
   Float_t         HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled;
   Float_t         HLT_DoubleElHT;
   Float_t         HLT_DoubleElHT_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v;
   Float_t         HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_isUnprescaled;
   Float_t         HLT_TripleEl;
   Float_t         HLT_TripleEl_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v;
   Float_t         HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled;
   Float_t         HLT_MuEGHT;
   Float_t         HLT_MuEGHT_isUnprescaled;
   Float_t         HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_NoiseCleaned_PFMHTNoMu90_IDTight_v;
   Float_t         HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_NoiseCleaned_PFMHTNoMu90_IDTight_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu90_IDTight_v;
   Float_t         HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu90_IDTight_v_isUnprescaled;
   Float_t         HLT_MonoJet80MET90;
   Float_t         HLT_MonoJet80MET90_isUnprescaled;
   Float_t         HLT_BIT_HLT_IsoMu24_eta2p1_v;
   Float_t         HLT_BIT_HLT_IsoMu24_eta2p1_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_IsoTkMu24_eta2p1_v;
   Float_t         HLT_BIT_HLT_IsoTkMu24_eta2p1_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_IsoMu18_v;
   Float_t         HLT_BIT_HLT_IsoMu18_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_IsoMu20_v;
   Float_t         HLT_BIT_HLT_IsoMu20_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_IsoTkMu20_v;
   Float_t         HLT_BIT_HLT_IsoTkMu20_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_IsoMu27_v;
   Float_t         HLT_BIT_HLT_IsoMu27_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_IsoTkMu27_v;
   Float_t         HLT_BIT_HLT_IsoTkMu27_v_isUnprescaled;
   Float_t         HLT_SingleMu;
   Float_t         HLT_SingleMu_isUnprescaled;
   Float_t         HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v;
   Float_t         HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_isUnprescaled;
   Float_t         HLT_DoubleMuEl;
   Float_t         HLT_DoubleMuEl_isUnprescaled;
   Float_t         HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v;
   Float_t         HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu120_IDTight_v;
   Float_t         HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu120_IDTight_v_isUnprescaled;
   Float_t         HLT_MonoJet80MET120;
   Float_t         HLT_MonoJet80MET120_isUnprescaled;
   Float_t         HLT_BIT_HLT_TripleMu_12_10_5_v;
   Float_t         HLT_BIT_HLT_TripleMu_12_10_5_v_isUnprescaled;
   Float_t         HLT_TripleMu;
   Float_t         HLT_TripleMu_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v;
   Float_t         HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_isUnprescaled;
   Float_t         HLT_DoubleElMu;
   Float_t         HLT_DoubleElMu_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu30_TkMu11_v;
   Float_t         HLT_BIT_HLT_Mu30_TkMu11_v_isUnprescaled;
   Float_t         HLT_DoubleMuNoIso;
   Float_t         HLT_DoubleMuNoIso_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu17_Mu8_SameSign_v;
   Float_t         HLT_BIT_HLT_Mu17_Mu8_SameSign_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v;
   Float_t         HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_isUnprescaled;
   Float_t         HLT_DoubleMuSS;
   Float_t         HLT_DoubleMuSS_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele23_WPLoose_Gsf_v;
   Float_t         HLT_BIT_HLT_Ele23_WPLoose_Gsf_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele27_WPLoose_Gsf_v;
   Float_t         HLT_BIT_HLT_Ele27_WPLoose_Gsf_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v;
   Float_t         HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v;
   Float_t         HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele27_WP85_Gsf_v;
   Float_t         HLT_BIT_HLT_Ele27_WP85_Gsf_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v;
   Float_t         HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v;
   Float_t         HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v_isUnprescaled;
   Float_t         HLT_SingleEl;
   Float_t         HLT_SingleEl_isUnprescaled;
   Float_t         HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v;
   Float_t         HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_isUnprescaled;
   Float_t         HLT_TripleMuA;
   Float_t         HLT_TripleMuA_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v;
   Float_t         HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v;
   Float_t         HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v;
   Float_t         HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v;
   Float_t         HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;
   Float_t         HLT_MuEG;
   Float_t         HLT_MuEG_isUnprescaled;
   Float_t         HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v;
   Float_t         HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_isUnprescaled;
   Float_t         HLT_DoubleMuHT;
   Float_t         HLT_DoubleMuHT_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;
   Float_t         HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;
   Float_t         HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled;
   Float_t         HLT_DoubleEl;
   Float_t         HLT_DoubleEl_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v;
   Float_t         HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v;
   Float_t         HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_isUnprescaled;
   Float_t         HLT_DoubleMu;
   Float_t         HLT_DoubleMu_isUnprescaled;
   Float_t         HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v;
   Float_t         HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v_isUnprescaled;
   Float_t         HLT_METMu5;
   Float_t         HLT_METMu5_isUnprescaled;
   Float_t         Flag_HBHENoiseIsoFilter;
   Float_t         Flag_EcalDeadCellTriggerPrimitiveFilter;
   Float_t         Flag_trkPOG_manystripclus53X;
   Float_t         Flag_ecalLaserCorrFilter;
   Float_t         Flag_trkPOG_toomanystripclus53X;
   Float_t         Flag_hcalLaserEventFilter;
   Float_t         Flag_trkPOG_logErrorTooManyClusters;
   Float_t         Flag_trkPOGFilters;
   Float_t         Flag_trackingFailureFilter;
   Float_t         Flag_CSCTightHaloFilter;
   Float_t         Flag_HBHENoiseFilter;
   Float_t         Flag_goodVertices;
   Float_t         Flag_METFilters;
   Float_t         Flag_eeBadScFilter;
   Float_t         met_pt;
   Float_t         met_eta;
   Float_t         met_phi;
   Float_t         met_mass;
   Float_t         met_sumEt;
   Float_t         met_rawPt;
   Float_t         met_rawPhi;
   Float_t         met_rawSumEt;
   Float_t         met_genPt;
   Float_t         met_genPhi;
   Float_t         met_genEta;
   Float_t         metNoHF_pt;
   Float_t         metNoHF_eta;
   Float_t         metNoHF_phi;
   Float_t         metNoHF_mass;
   Float_t         metNoHF_sumEt;
   Float_t         metNoHF_rawPt;
   Float_t         metNoHF_rawPhi;
   Float_t         metNoHF_rawSumEt;
   Float_t         metNoHF_genPt;
   Float_t         metNoHF_genPhi;
   Float_t         metNoHF_genEta;
   Int_t           nFatJet;
   Int_t           FatJet_id[6];   //[nFatJet]
   Int_t           FatJet_puId[6];   //[nFatJet]
   Float_t         FatJet_btagCSV[6];   //[nFatJet]
   Float_t         FatJet_btagCMVA[6];   //[nFatJet]
   Float_t         FatJet_rawPt[6];   //[nFatJet]
   Float_t         FatJet_mcPt[6];   //[nFatJet]
   Int_t           FatJet_mcFlavour[6];   //[nFatJet]
   Int_t           FatJet_mcMatchId[6];   //[nFatJet]
   Float_t         FatJet_corr_JECUp[6];   //[nFatJet]
   Float_t         FatJet_corr_JECDown[6];   //[nFatJet]
   Float_t         FatJet_corr[6];   //[nFatJet]
   Float_t         FatJet_px[6];   //[nFatJet]
   Float_t         FatJet_py[6];   //[nFatJet]
   Float_t         FatJet_pz[6];   //[nFatJet]
   Float_t         FatJet_energy[6];   //[nFatJet]
   Float_t         FatJet_mcPx[6];   //[nFatJet]
   Float_t         FatJet_mcPy[6];   //[nFatJet]
   Float_t         FatJet_mcPz[6];   //[nFatJet]
   Float_t         FatJet_mcEnergy[6];   //[nFatJet]
   Float_t         FatJet_pt[6];   //[nFatJet]
   Float_t         FatJet_eta[6];   //[nFatJet]
   Float_t         FatJet_phi[6];   //[nFatJet]
   Float_t         FatJet_mass[6];   //[nFatJet]
   Float_t         FatJet_prunedMass[6];   //[nFatJet]
   Float_t         FatJet_trimmedMass[6];   //[nFatJet]
   Float_t         FatJet_filteredMass[6];   //[nFatJet]
   Float_t         FatJet_tau1[6];   //[nFatJet]
   Float_t         FatJet_tau2[6];   //[nFatJet]
   Float_t         FatJet_tau3[6];   //[nFatJet]
   Float_t         FatJet_topMass[6];   //[nFatJet]
   Float_t         FatJet_minMass[6];   //[nFatJet]
   Float_t         FatJet_nSubJets[6];   //[nFatJet]
   Int_t           ngenTau;
   Int_t           genTau_motherId[2];   //[ngenTau]
   Int_t           genTau_grandmotherId[2];   //[ngenTau]
   Int_t           genTau_sourceId[2];   //[ngenTau]
   Float_t         genTau_charge[2];   //[ngenTau]
   Int_t           genTau_status[2];   //[ngenTau]
   Int_t           genTau_pdgId[2];   //[ngenTau]
   Float_t         genTau_pt[2];   //[ngenTau]
   Float_t         genTau_eta[2];   //[ngenTau]
   Float_t         genTau_phi[2];   //[ngenTau]
   Float_t         genTau_mass[2];   //[ngenTau]
   Int_t           genTau_motherIndex[2];   //[ngenTau]
   Int_t           nGenPart;
   Int_t           GenPart_motherId[21];   //[nGenPart]
   Int_t           GenPart_grandmotherId[21];   //[nGenPart]
   Int_t           GenPart_sourceId[21];   //[nGenPart]
   Float_t         GenPart_charge[21];   //[nGenPart]
   Int_t           GenPart_status[21];   //[nGenPart]
   Int_t           GenPart_pdgId[21];   //[nGenPart]
   Float_t         GenPart_pt[21];   //[nGenPart]
   Float_t         GenPart_eta[21];   //[nGenPart]
   Float_t         GenPart_phi[21];   //[nGenPart]
   Float_t         GenPart_mass[21];   //[nGenPart]
   Int_t           GenPart_motherIndex[21];   //[nGenPart]
   Int_t           nGenTop;
   Int_t           GenTop_pdgId[2];   //[nGenTop]
   Float_t         GenTop_pt[2];   //[nGenTop]
   Float_t         GenTop_eta[2];   //[nGenTop]
   Float_t         GenTop_phi[2];   //[nGenTop]
   Float_t         GenTop_mass[2];   //[nGenTop]
   Float_t         GenTop_charge[2];   //[nGenTop]
   Int_t           GenTop_status[2];   //[nGenTop]
   Int_t           nDiscJet;
   Float_t         DiscJet_area[6];   //[nDiscJet]
   Float_t         DiscJet_qgl[6];   //[nDiscJet]
   Float_t         DiscJet_ptd[6];   //[nDiscJet]
   Float_t         DiscJet_axis2[6];   //[nDiscJet]
   Int_t           DiscJet_mult[6];   //[nDiscJet]
   Int_t           DiscJet_partonId[6];   //[nDiscJet]
   Int_t           DiscJet_partonMotherId[6];   //[nDiscJet]
   Float_t         DiscJet_nLeptons[6];   //[nDiscJet]
   Int_t           DiscJet_id[6];   //[nDiscJet]
   Int_t           DiscJet_puId[6];   //[nDiscJet]
   Float_t         DiscJet_btagCSV[6];   //[nDiscJet]
   Float_t         DiscJet_btagCMVA[6];   //[nDiscJet]
   Float_t         DiscJet_rawPt[6];   //[nDiscJet]
   Float_t         DiscJet_mcPt[6];   //[nDiscJet]
   Int_t           DiscJet_mcFlavour[6];   //[nDiscJet]
   Int_t           DiscJet_mcMatchId[6];   //[nDiscJet]
   Float_t         DiscJet_corr_JECUp[6];   //[nDiscJet]
   Float_t         DiscJet_corr_JECDown[6];   //[nDiscJet]
   Float_t         DiscJet_corr[6];   //[nDiscJet]
   Float_t         DiscJet_px[6];   //[nDiscJet]
   Float_t         DiscJet_py[6];   //[nDiscJet]
   Float_t         DiscJet_pz[6];   //[nDiscJet]
   Float_t         DiscJet_energy[6];   //[nDiscJet]
   Float_t         DiscJet_mcPx[6];   //[nDiscJet]
   Float_t         DiscJet_mcPy[6];   //[nDiscJet]
   Float_t         DiscJet_mcPz[6];   //[nDiscJet]
   Float_t         DiscJet_mcEnergy[6];   //[nDiscJet]
   Float_t         DiscJet_pt[6];   //[nDiscJet]
   Float_t         DiscJet_eta[6];   //[nDiscJet]
   Float_t         DiscJet_phi[6];   //[nDiscJet]
   Float_t         DiscJet_mass[6];   //[nDiscJet]
   Int_t           DiscJet_mcMatchFlav[6];   //[nDiscJet]
   Float_t         DiscJet_charge[6];   //[nDiscJet]
   Int_t           nLepGood;
   Float_t         LepGood_mvaIdPhys14[7];   //[nLepGood]
   Float_t         LepGood_mvaIdSpring15[7];   //[nLepGood]
   Float_t         LepGood_mvaTTH[7];   //[nLepGood]
   Float_t         LepGood_jetPtRatiov1[7];   //[nLepGood]
   Float_t         LepGood_jetPtRelv1[7];   //[nLepGood]
   Float_t         LepGood_jetPtRatiov2[7];   //[nLepGood]
   Float_t         LepGood_jetPtRelv2[7];   //[nLepGood]
   Float_t         LepGood_jetBTagCSV[7];   //[nLepGood]
   Float_t         LepGood_jetBTagCMVA[7];   //[nLepGood]
   Float_t         LepGood_jetDR[7];   //[nLepGood]
   Int_t           LepGood_charge[7];   //[nLepGood]
   Float_t         LepGood_px[7];   //[nLepGood]
   Float_t         LepGood_py[7];   //[nLepGood]
   Float_t         LepGood_pz[7];   //[nLepGood]
   Float_t         LepGood_energy[7];   //[nLepGood]
   Int_t           LepGood_tightId[7];   //[nLepGood]
   Int_t           LepGood_eleCutIdCSA14_25ns_v1[7];   //[nLepGood]
   Int_t           LepGood_eleCutIdCSA14_50ns_v1[7];   //[nLepGood]
   Float_t         LepGood_dxy[7];   //[nLepGood]
   Float_t         LepGood_dz[7];   //[nLepGood]
   Float_t         LepGood_edxy[7];   //[nLepGood]
   Float_t         LepGood_edz[7];   //[nLepGood]
   Float_t         LepGood_ip3d[7];   //[nLepGood]
   Float_t         LepGood_sip3d[7];   //[nLepGood]
   Int_t           LepGood_convVeto[7];   //[nLepGood]
   Int_t           LepGood_lostHits[7];   //[nLepGood]
   Float_t         LepGood_relIso03[7];   //[nLepGood]
   Float_t         LepGood_relIso04[7];   //[nLepGood]
   Float_t         LepGood_miniRelIso[7];   //[nLepGood]
   Float_t         LepGood_relIsoAn04[7];   //[nLepGood]
   Int_t           LepGood_tightCharge[7];   //[nLepGood]
   Int_t           LepGood_mcMatchId[7];   //[nLepGood]
   Int_t           LepGood_mcMatchAny[7];   //[nLepGood]
   Int_t           LepGood_mcMatchTau[7];   //[nLepGood]
   Float_t         LepGood_mcPt[7];   //[nLepGood]
   Int_t           LepGood_mediumMuonId[7];   //[nLepGood]
   Int_t           LepGood_pdgId[7];   //[nLepGood]
   Float_t         LepGood_pt[7];   //[nLepGood]
   Float_t         LepGood_eta[7];   //[nLepGood]
   Float_t         LepGood_phi[7];   //[nLepGood]
   Float_t         LepGood_mass[7];   //[nLepGood]
   Float_t         LepGood_chargedHadRelIso03[7];   //[nLepGood]
   Float_t         LepGood_chargedHadRelIso04[7];   //[nLepGood]
   Int_t           LepGood_softMuonId[7];   //[nLepGood]
   Int_t           LepGood_pfMuonId[7];   //[nLepGood]
   Int_t           LepGood_eleCutId2012_full5x5[7];   //[nLepGood]
   Int_t           LepGood_trackerLayers[7];   //[nLepGood]
   Int_t           LepGood_pixelLayers[7];   //[nLepGood]
   Int_t           LepGood_trackerHits[7];   //[nLepGood]
   Int_t           LepGood_lostOuterHits[7];   //[nLepGood]
   Float_t         LepGood_innerTrackValidHitFraction[7];   //[nLepGood]
   Float_t         LepGood_innerTrackChi2[7];   //[nLepGood]
   Float_t         LepGood_nStations[7];   //[nLepGood]
   Float_t         LepGood_caloCompatibility[7];   //[nLepGood]
   Float_t         LepGood_globalTrackChi2[7];   //[nLepGood]
   Float_t         LepGood_trkKink[7];   //[nLepGood]
   Float_t         LepGood_segmentCompatibility[7];   //[nLepGood]
   Float_t         LepGood_chi2LocalPosition[7];   //[nLepGood]
   Float_t         LepGood_chi2LocalMomentum[7];   //[nLepGood]
   Float_t         LepGood_glbTrackProbability[7];   //[nLepGood]
   Float_t         LepGood_sigmaIEtaIEta[7];   //[nLepGood]
   Float_t         LepGood_dEtaScTrkIn[7];   //[nLepGood]
   Float_t         LepGood_dPhiScTrkIn[7];   //[nLepGood]
   Float_t         LepGood_hadronicOverEm[7];   //[nLepGood]
   Float_t         LepGood_eInvMinusPInv[7];   //[nLepGood]
   Float_t         LepGood_eInvMinusPInv_tkMom[7];   //[nLepGood]
   Float_t         LepGood_etaSc[7];   //[nLepGood]
   Float_t         LepGood_miniRelIsoCharged[7];   //[nLepGood]
   Float_t         LepGood_miniRelIsoNeutral[7];   //[nLepGood]
   Int_t           LepGood_hasSV[7];   //[nLepGood]
   Float_t         LepGood_svRedPt[7];   //[nLepGood]
   Float_t         LepGood_svRedM[7];   //[nLepGood]
   Float_t         LepGood_svLepSip3d[7];   //[nLepGood]
   Float_t         LepGood_svSip3d[7];   //[nLepGood]
   Float_t         LepGood_svNTracks[7];   //[nLepGood]
   Float_t         LepGood_svChi2n[7];   //[nLepGood]
   Float_t         LepGood_svDxy[7];   //[nLepGood]
   Float_t         LepGood_svMass[7];   //[nLepGood]
   Float_t         LepGood_svPt[7];   //[nLepGood]
   Float_t         LepGood_svMCMatchFraction[7];   //[nLepGood]
   Float_t         LepGood_svMva[7];   //[nLepGood]
   Float_t         LepGood_jetNDau[7];   //[nLepGood]
   Float_t         LepGood_jetNDauCharged[7];   //[nLepGood]
   Float_t         LepGood_jetNDauPV[7];   //[nLepGood]
   Float_t         LepGood_jetNDauNotPV[7];   //[nLepGood]
   Float_t         LepGood_jetmaxSignedSip3D[7];   //[nLepGood]
   Float_t         LepGood_jetmaxSip3D[7];   //[nLepGood]
   Float_t         LepGood_jetmaxSignedSip2D[7];   //[nLepGood]
   Float_t         LepGood_jetmaxSip2D[7];   //[nLepGood]
   Float_t         LepGood_jetPtRelv0[7];   //[nLepGood]
   Float_t         LepGood_jetMass[7];   //[nLepGood]
   Float_t         LepGood_jetPrunedMass[7];   //[nLepGood]
   Float_t         LepGood_jetDecDR[7];   //[nLepGood]
   Float_t         LepGood_jetDecPtRel[7];   //[nLepGood]
   Float_t         LepGood_jetDecPtRatio[7];   //[nLepGood]
   Float_t         LepGood_jetDecPrunedMass[7];   //[nLepGood]
   Float_t         LepGood_jetDecPrunedPtRatio[7];   //[nLepGood]
   Float_t         LepGood_jetDec02DR[7];   //[nLepGood]
   Float_t         LepGood_jetDec02PtRel[7];   //[nLepGood]
   Float_t         LepGood_jetDec02PtRatio[7];   //[nLepGood]
   Float_t         LepGood_jetDec02PrunedPtRatio[7];   //[nLepGood]
   Float_t         LepGood_jetDec02PrunedMass[7];   //[nLepGood]
   Float_t         LepGood_jetRawPt[7];   //[nLepGood]
   Float_t         LepGood_jetCorrFactor_L1[7];   //[nLepGood]
   Float_t         LepGood_jetCorrFactor_L1L2[7];   //[nLepGood]
   Float_t         LepGood_jetCorrFactor_L1L2L3[7];   //[nLepGood]
   Float_t         LepGood_jetCorrFactor_L1L2L3Res[7];   //[nLepGood]
   Float_t         LepGood_jetPtRatio_Raw[7];   //[nLepGood]
   Float_t         LepGood_jetPtRelHv2[7];   //[nLepGood]
   Float_t         LepGood_ecalPFClusterIso[7];   //[nLepGood]
   Float_t         LepGood_hcalPFClusterIso[7];   //[nLepGood]
   Float_t         LepGood_dr03TkSumPt[7];   //[nLepGood]
   Float_t         LepGood_trackIso[7];   //[nLepGood]
   Float_t         LepGood_jetLepAwareJEC_pt[7];   //[nLepGood]
   Float_t         LepGood_jetLepAwareJEC_eta[7];   //[nLepGood]
   Float_t         LepGood_jetLepAwareJEC_phi[7];   //[nLepGood]
   Float_t         LepGood_jetLepAwareJEC_energy[7];   //[nLepGood]
   Int_t           ngenLepFromTau;
   Int_t           genLepFromTau_motherId[4];   //[ngenLepFromTau]
   Int_t           genLepFromTau_grandmotherId[4];   //[ngenLepFromTau]
   Int_t           genLepFromTau_sourceId[4];   //[ngenLepFromTau]
   Float_t         genLepFromTau_charge[4];   //[ngenLepFromTau]
   Int_t           genLepFromTau_status[4];   //[ngenLepFromTau]
   Int_t           genLepFromTau_pdgId[4];   //[ngenLepFromTau]
   Float_t         genLepFromTau_pt[4];   //[ngenLepFromTau]
   Float_t         genLepFromTau_eta[4];   //[ngenLepFromTau]
   Float_t         genLepFromTau_phi[4];   //[ngenLepFromTau]
   Float_t         genLepFromTau_mass[4];   //[ngenLepFromTau]
   Int_t           genLepFromTau_motherIndex[4];   //[ngenLepFromTau]
   Int_t           nGenBHad;
   Float_t         GenBHad_charge[10];   //[nGenBHad]
   Int_t           GenBHad_status[10];   //[nGenBHad]
   Int_t           GenBHad_pdgId[10];   //[nGenBHad]
   Float_t         GenBHad_pt[10];   //[nGenBHad]
   Float_t         GenBHad_eta[10];   //[nGenBHad]
   Float_t         GenBHad_phi[10];   //[nGenBHad]
   Float_t         GenBHad_mass[10];   //[nGenBHad]
   Int_t           GenBHad_flav[10];   //[nGenBHad]
   Int_t           GenBHad_sourceId[10];   //[nGenBHad]
   Float_t         GenBHad_svMass[10];   //[nGenBHad]
   Float_t         GenBHad_svPt[10];   //[nGenBHad]
   Int_t           GenBHad_svCharge[10];   //[nGenBHad]
   Int_t           GenBHad_svNtracks[10];   //[nGenBHad]
   Float_t         GenBHad_svChi2[10];   //[nGenBHad]
   Float_t         GenBHad_svNdof[10];   //[nGenBHad]
   Float_t         GenBHad_svDxy[10];   //[nGenBHad]
   Float_t         GenBHad_svEdxy[10];   //[nGenBHad]
   Float_t         GenBHad_svIp3d[10];   //[nGenBHad]
   Float_t         GenBHad_svEip3d[10];   //[nGenBHad]
   Float_t         GenBHad_svSip3d[10];   //[nGenBHad]
   Float_t         GenBHad_svCosTheta[10];   //[nGenBHad]
   Float_t         GenBHad_svMva[10];   //[nGenBHad]
   Float_t         GenBHad_jetPt[10];   //[nGenBHad]
   Float_t         GenBHad_jetBTagCSV[10];   //[nGenBHad]
   Float_t         GenBHad_jetBTagCMVA[10];   //[nGenBHad]
   Int_t           nJet;
   Int_t           Jet_mcMatchFlav[14];   //[nJet]
   Float_t         Jet_charge[14];   //[nJet]
   Float_t         Jet_area[14];   //[nJet]
   Float_t         Jet_qgl[14];   //[nJet]
   Float_t         Jet_ptd[14];   //[nJet]
   Float_t         Jet_axis2[14];   //[nJet]
   Int_t           Jet_mult[14];   //[nJet]
   Int_t           Jet_partonId[14];   //[nJet]
   Int_t           Jet_partonMotherId[14];   //[nJet]
   Float_t         Jet_nLeptons[14];   //[nJet]
   Int_t           Jet_id[14];   //[nJet]
   Int_t           Jet_puId[14];   //[nJet]
   Float_t         Jet_btagCSV[14];   //[nJet]
   Float_t         Jet_btagCMVA[14];   //[nJet]
   Float_t         Jet_rawPt[14];   //[nJet]
   Float_t         Jet_mcPt[14];   //[nJet]
   Int_t           Jet_mcFlavour[14];   //[nJet]
   Int_t           Jet_mcMatchId[14];   //[nJet]
   Float_t         Jet_corr_JECUp[14];   //[nJet]
   Float_t         Jet_corr_JECDown[14];   //[nJet]
   Float_t         Jet_corr[14];   //[nJet]
   Float_t         Jet_px[14];   //[nJet]
   Float_t         Jet_py[14];   //[nJet]
   Float_t         Jet_pz[14];   //[nJet]
   Float_t         Jet_energy[14];   //[nJet]
   Float_t         Jet_mcPx[14];   //[nJet]
   Float_t         Jet_mcPy[14];   //[nJet]
   Float_t         Jet_mcPz[14];   //[nJet]
   Float_t         Jet_mcEnergy[14];   //[nJet]
   Float_t         Jet_pt[14];   //[nJet]
   Float_t         Jet_eta[14];   //[nJet]
   Float_t         Jet_phi[14];   //[nJet]
   Float_t         Jet_mass[14];   //[nJet]
   Float_t         Jet_prunedMass[14];   //[nJet]
   Int_t           Jet_mcNumPartons[14];   //[nJet]
   Int_t           Jet_mcNumLeptons[14];   //[nJet]
   Int_t           Jet_mcNumTaus[14];   //[nJet]
   Float_t         Jet_mcAnyPartonMass[14];   //[nJet]
   Int_t           Jet_nSubJets[14];   //[nJet]
   Int_t           Jet_nSubJets25[14];   //[nJet]
   Int_t           Jet_nSubJets30[14];   //[nJet]
   Int_t           Jet_nSubJets40[14];   //[nJet]
   Int_t           Jet_nSubJetsZ01[14];   //[nJet]
   Float_t         Jet_chHEF[14];   //[nJet]
   Float_t         Jet_neHEF[14];   //[nJet]
   Float_t         Jet_phEF[14];   //[nJet]
   Float_t         Jet_eEF[14];   //[nJet]
   Float_t         Jet_muEF[14];   //[nJet]
   Float_t         Jet_HFHEF[14];   //[nJet]
   Float_t         Jet_HFEMEF[14];   //[nJet]
   Int_t           Jet_chHMult[14];   //[nJet]
   Int_t           Jet_neHMult[14];   //[nJet]
   Int_t           Jet_phMult[14];   //[nJet]
   Int_t           Jet_eMult[14];   //[nJet]
   Int_t           Jet_muMult[14];   //[nJet]
   Int_t           Jet_HFHMult[14];   //[nJet]
   Int_t           Jet_HFEMMult[14];   //[nJet]
   Float_t         Jet_CorrFactor_L1[14];   //[nJet]
   Float_t         Jet_CorrFactor_L1L2[14];   //[nJet]
   Float_t         Jet_CorrFactor_L1L2L3[14];   //[nJet]
   Float_t         Jet_CorrFactor_L1L2L3Res[14];   //[nJet]
   Int_t           ngenLep;
   Int_t           genLep_motherId[2];   //[ngenLep]
   Int_t           genLep_grandmotherId[2];   //[ngenLep]
   Int_t           genLep_sourceId[2];   //[ngenLep]
   Float_t         genLep_charge[2];   //[ngenLep]
   Int_t           genLep_status[2];   //[ngenLep]
   Int_t           genLep_pdgId[2];   //[ngenLep]
   Float_t         genLep_pt[2];   //[ngenLep]
   Float_t         genLep_eta[2];   //[ngenLep]
   Float_t         genLep_phi[2];   //[ngenLep]
   Float_t         genLep_mass[2];   //[ngenLep]
   Int_t           genLep_motherIndex[2];   //[ngenLep]
   Int_t           nLHEweight;
   Int_t           LHEweight_id[222];   //[nLHEweight]
   Float_t         LHEweight_wgt[222];   //[nLHEweight]
   Int_t           nTauGood;
   Int_t           TauGood_charge[3];   //[nTauGood]
   Int_t           TauGood_decayMode[3];   //[nTauGood]
   Int_t           TauGood_idDecayMode[3];   //[nTauGood]
   Int_t           TauGood_idDecayModeNewDMs[3];   //[nTauGood]
   Float_t         TauGood_dxy[3];   //[nTauGood]
   Float_t         TauGood_dz[3];   //[nTauGood]
   Int_t           TauGood_idMVA[3];   //[nTauGood]
   Int_t           TauGood_idMVANewDM[3];   //[nTauGood]
   Int_t           TauGood_idCI3hit[3];   //[nTauGood]
   Int_t           TauGood_idAntiMu[3];   //[nTauGood]
   Int_t           TauGood_idAntiE[3];   //[nTauGood]
   Float_t         TauGood_isoCI3hit[3];   //[nTauGood]
   Int_t           TauGood_mcMatchId[3];   //[nTauGood]
   Int_t           TauGood_pdgId[3];   //[nTauGood]
   Float_t         TauGood_pt[3];   //[nTauGood]
   Float_t         TauGood_eta[3];   //[nTauGood]
   Float_t         TauGood_phi[3];   //[nTauGood]
   Float_t         TauGood_mass[3];   //[nTauGood]

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_isData;   //!
   TBranch        *b_xsec;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_nTrueInt;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_rhoCN;   //!
   TBranch        *b_nVert;   //!
   TBranch        *b_GenSusyMScan1;   //!
   TBranch        *b_GenSusyMScan2;   //!
   TBranch        *b_GenSusyMScan3;   //!
   TBranch        *b_GenSusyMScan4;   //!
   TBranch        *b_GenSusyMGluino;   //!
   TBranch        *b_GenSusyMGravitino;   //!
   TBranch        *b_GenSusyMStop;   //!
   TBranch        *b_GenSusyMSbottom;   //!
   TBranch        *b_GenSusyMStop2;   //!
   TBranch        *b_GenSusyMSbottom2;   //!
   TBranch        *b_GenSusyMSquark;   //!
   TBranch        *b_GenSusyMNeutralino;   //!
   TBranch        *b_GenSusyMNeutralino2;   //!
   TBranch        *b_GenSusyMNeutralino3;   //!
   TBranch        *b_GenSusyMNeutralino4;   //!
   TBranch        *b_GenSusyMChargino;   //!
   TBranch        *b_GenSusyMChargino2;   //!
   TBranch        *b_minDrllAFSS;   //!
   TBranch        *b_m3l;   //!
   TBranch        *b_hbheFilterNew50ns;   //!
   TBranch        *b_hbheFilterNew25ns;   //!
   TBranch        *b_hbheFilterIso;   //!
   TBranch        *b_met_trkPt;   //!
   TBranch        *b_met_trkPhi;   //!
   TBranch        *b_metNoHF_trkPt;   //!
   TBranch        *b_metNoHF_trkPhi;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled;   //!
   TBranch        *b_HLT_DoubleElHT;   //!
   TBranch        *b_HLT_DoubleElHT_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_isUnprescaled;   //!
   TBranch        *b_HLT_TripleEl;   //!
   TBranch        *b_HLT_TripleEl_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled;   //!
   TBranch        *b_HLT_MuEGHT;   //!
   TBranch        *b_HLT_MuEGHT_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_NoiseCleaned_PFMHTNoMu90_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_NoiseCleaned_PFMHTNoMu90_IDTight_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu90_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu90_IDTight_v_isUnprescaled;   //!
   TBranch        *b_HLT_MonoJet80MET90;   //!
   TBranch        *b_HLT_MonoJet80MET90_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu24_eta2p1_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu24_eta2p1_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu24_eta2p1_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu24_eta2p1_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu18_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu18_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu20_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu20_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu20_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu20_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu27_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu27_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu27_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu27_v_isUnprescaled;   //!
   TBranch        *b_HLT_SingleMu;   //!
   TBranch        *b_HLT_SingleMu_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_isUnprescaled;   //!
   TBranch        *b_HLT_DoubleMuEl;   //!
   TBranch        *b_HLT_DoubleMuEl_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu120_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu120_IDTight_v_isUnprescaled;   //!
   TBranch        *b_HLT_MonoJet80MET120;   //!
   TBranch        *b_HLT_MonoJet80MET120_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_TripleMu_12_10_5_v;   //!
   TBranch        *b_HLT_BIT_HLT_TripleMu_12_10_5_v_isUnprescaled;   //!
   TBranch        *b_HLT_TripleMu;   //!
   TBranch        *b_HLT_TripleMu_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_isUnprescaled;   //!
   TBranch        *b_HLT_DoubleElMu;   //!
   TBranch        *b_HLT_DoubleElMu_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu30_TkMu11_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu30_TkMu11_v_isUnprescaled;   //!
   TBranch        *b_HLT_DoubleMuNoIso;   //!
   TBranch        *b_HLT_DoubleMuNoIso_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_Mu8_SameSign_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_Mu8_SameSign_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_isUnprescaled;   //!
   TBranch        *b_HLT_DoubleMuSS;   //!
   TBranch        *b_HLT_DoubleMuSS_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_WPLoose_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_WPLoose_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_WP85_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_WP85_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_SingleEl;   //!
   TBranch        *b_HLT_SingleEl_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v;   //!
   TBranch        *b_HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_isUnprescaled;   //!
   TBranch        *b_HLT_TripleMuA;   //!
   TBranch        *b_HLT_TripleMuA_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;   //!
   TBranch        *b_HLT_MuEG;   //!
   TBranch        *b_HLT_MuEG_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_isUnprescaled;   //!
   TBranch        *b_HLT_DoubleMuHT;   //!
   TBranch        *b_HLT_DoubleMuHT_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled;   //!
   TBranch        *b_HLT_DoubleEl;   //!
   TBranch        *b_HLT_DoubleEl_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_isUnprescaled;   //!
   TBranch        *b_HLT_DoubleMu;   //!
   TBranch        *b_HLT_DoubleMu_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v_isUnprescaled;   //!
   TBranch        *b_HLT_METMu5;   //!
   TBranch        *b_HLT_METMu5_isUnprescaled;   //!
   TBranch        *b_Flag_HBHENoiseIsoFilter;   //!
   TBranch        *b_Flag_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_Flag_trkPOG_manystripclus53X;   //!
   TBranch        *b_Flag_ecalLaserCorrFilter;   //!
   TBranch        *b_Flag_trkPOG_toomanystripclus53X;   //!
   TBranch        *b_Flag_hcalLaserEventFilter;   //!
   TBranch        *b_Flag_trkPOG_logErrorTooManyClusters;   //!
   TBranch        *b_Flag_trkPOGFilters;   //!
   TBranch        *b_Flag_trackingFailureFilter;   //!
   TBranch        *b_Flag_CSCTightHaloFilter;   //!
   TBranch        *b_Flag_HBHENoiseFilter;   //!
   TBranch        *b_Flag_goodVertices;   //!
   TBranch        *b_Flag_METFilters;   //!
   TBranch        *b_Flag_eeBadScFilter;   //!
   TBranch        *b_met_pt;   //!
   TBranch        *b_met_eta;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_met_mass;   //!
   TBranch        *b_met_sumEt;   //!
   TBranch        *b_met_rawPt;   //!
   TBranch        *b_met_rawPhi;   //!
   TBranch        *b_met_rawSumEt;   //!
   TBranch        *b_met_genPt;   //!
   TBranch        *b_met_genPhi;   //!
   TBranch        *b_met_genEta;   //!
   TBranch        *b_metNoHF_pt;   //!
   TBranch        *b_metNoHF_eta;   //!
   TBranch        *b_metNoHF_phi;   //!
   TBranch        *b_metNoHF_mass;   //!
   TBranch        *b_metNoHF_sumEt;   //!
   TBranch        *b_metNoHF_rawPt;   //!
   TBranch        *b_metNoHF_rawPhi;   //!
   TBranch        *b_metNoHF_rawSumEt;   //!
   TBranch        *b_metNoHF_genPt;   //!
   TBranch        *b_metNoHF_genPhi;   //!
   TBranch        *b_metNoHF_genEta;   //!
   TBranch        *b_nFatJet;   //!
   TBranch        *b_FatJet_id;   //!
   TBranch        *b_FatJet_puId;   //!
   TBranch        *b_FatJet_btagCSV;   //!
   TBranch        *b_FatJet_btagCMVA;   //!
   TBranch        *b_FatJet_rawPt;   //!
   TBranch        *b_FatJet_mcPt;   //!
   TBranch        *b_FatJet_mcFlavour;   //!
   TBranch        *b_FatJet_mcMatchId;   //!
   TBranch        *b_FatJet_corr_JECUp;   //!
   TBranch        *b_FatJet_corr_JECDown;   //!
   TBranch        *b_FatJet_corr;   //!
   TBranch        *b_FatJet_px;   //!
   TBranch        *b_FatJet_py;   //!
   TBranch        *b_FatJet_pz;   //!
   TBranch        *b_FatJet_energy;   //!
   TBranch        *b_FatJet_mcPx;   //!
   TBranch        *b_FatJet_mcPy;   //!
   TBranch        *b_FatJet_mcPz;   //!
   TBranch        *b_FatJet_mcEnergy;   //!
   TBranch        *b_FatJet_pt;   //!
   TBranch        *b_FatJet_eta;   //!
   TBranch        *b_FatJet_phi;   //!
   TBranch        *b_FatJet_mass;   //!
   TBranch        *b_FatJet_prunedMass;   //!
   TBranch        *b_FatJet_trimmedMass;   //!
   TBranch        *b_FatJet_filteredMass;   //!
   TBranch        *b_FatJet_tau1;   //!
   TBranch        *b_FatJet_tau2;   //!
   TBranch        *b_FatJet_tau3;   //!
   TBranch        *b_FatJet_topMass;   //!
   TBranch        *b_FatJet_minMass;   //!
   TBranch        *b_FatJet_nSubJets;   //!
   TBranch        *b_ngenTau;   //!
   TBranch        *b_genTau_motherId;   //!
   TBranch        *b_genTau_grandmotherId;   //!
   TBranch        *b_genTau_sourceId;   //!
   TBranch        *b_genTau_charge;   //!
   TBranch        *b_genTau_status;   //!
   TBranch        *b_genTau_pdgId;   //!
   TBranch        *b_genTau_pt;   //!
   TBranch        *b_genTau_eta;   //!
   TBranch        *b_genTau_phi;   //!
   TBranch        *b_genTau_mass;   //!
   TBranch        *b_genTau_motherIndex;   //!
   TBranch        *b_nGenPart;   //!
   TBranch        *b_GenPart_motherId;   //!
   TBranch        *b_GenPart_grandmotherId;   //!
   TBranch        *b_GenPart_sourceId;   //!
   TBranch        *b_GenPart_charge;   //!
   TBranch        *b_GenPart_status;   //!
   TBranch        *b_GenPart_pdgId;   //!
   TBranch        *b_GenPart_pt;   //!
   TBranch        *b_GenPart_eta;   //!
   TBranch        *b_GenPart_phi;   //!
   TBranch        *b_GenPart_mass;   //!
   TBranch        *b_GenPart_motherIndex;   //!
   TBranch        *b_nGenTop;   //!
   TBranch        *b_GenTop_pdgId;   //!
   TBranch        *b_GenTop_pt;   //!
   TBranch        *b_GenTop_eta;   //!
   TBranch        *b_GenTop_phi;   //!
   TBranch        *b_GenTop_mass;   //!
   TBranch        *b_GenTop_charge;   //!
   TBranch        *b_GenTop_status;   //!
   TBranch        *b_nDiscJet;   //!
   TBranch        *b_DiscJet_area;   //!
   TBranch        *b_DiscJet_qgl;   //!
   TBranch        *b_DiscJet_ptd;   //!
   TBranch        *b_DiscJet_axis2;   //!
   TBranch        *b_DiscJet_mult;   //!
   TBranch        *b_DiscJet_partonId;   //!
   TBranch        *b_DiscJet_partonMotherId;   //!
   TBranch        *b_DiscJet_nLeptons;   //!
   TBranch        *b_DiscJet_id;   //!
   TBranch        *b_DiscJet_puId;   //!
   TBranch        *b_DiscJet_btagCSV;   //!
   TBranch        *b_DiscJet_btagCMVA;   //!
   TBranch        *b_DiscJet_rawPt;   //!
   TBranch        *b_DiscJet_mcPt;   //!
   TBranch        *b_DiscJet_mcFlavour;   //!
   TBranch        *b_DiscJet_mcMatchId;   //!
   TBranch        *b_DiscJet_corr_JECUp;   //!
   TBranch        *b_DiscJet_corr_JECDown;   //!
   TBranch        *b_DiscJet_corr;   //!
   TBranch        *b_DiscJet_px;   //!
   TBranch        *b_DiscJet_py;   //!
   TBranch        *b_DiscJet_pz;   //!
   TBranch        *b_DiscJet_energy;   //!
   TBranch        *b_DiscJet_mcPx;   //!
   TBranch        *b_DiscJet_mcPy;   //!
   TBranch        *b_DiscJet_mcPz;   //!
   TBranch        *b_DiscJet_mcEnergy;   //!
   TBranch        *b_DiscJet_pt;   //!
   TBranch        *b_DiscJet_eta;   //!
   TBranch        *b_DiscJet_phi;   //!
   TBranch        *b_DiscJet_mass;   //!
   TBranch        *b_DiscJet_mcMatchFlav;   //!
   TBranch        *b_DiscJet_charge;   //!
   TBranch        *b_nLepGood;   //!
   TBranch        *b_LepGood_mvaIdPhys14;   //!
   TBranch        *b_LepGood_mvaIdSpring15;   //!
   TBranch        *b_LepGood_mvaTTH;   //!
   TBranch        *b_LepGood_jetPtRatiov1;   //!
   TBranch        *b_LepGood_jetPtRelv1;   //!
   TBranch        *b_LepGood_jetPtRatiov2;   //!
   TBranch        *b_LepGood_jetPtRelv2;   //!
   TBranch        *b_LepGood_jetBTagCSV;   //!
   TBranch        *b_LepGood_jetBTagCMVA;   //!
   TBranch        *b_LepGood_jetDR;   //!
   TBranch        *b_LepGood_charge;   //!
   TBranch        *b_LepGood_px;   //!
   TBranch        *b_LepGood_py;   //!
   TBranch        *b_LepGood_pz;   //!
   TBranch        *b_LepGood_energy;   //!
   TBranch        *b_LepGood_tightId;   //!
   TBranch        *b_LepGood_eleCutIdCSA14_25ns_v1;   //!
   TBranch        *b_LepGood_eleCutIdCSA14_50ns_v1;   //!
   TBranch        *b_LepGood_dxy;   //!
   TBranch        *b_LepGood_dz;   //!
   TBranch        *b_LepGood_edxy;   //!
   TBranch        *b_LepGood_edz;   //!
   TBranch        *b_LepGood_ip3d;   //!
   TBranch        *b_LepGood_sip3d;   //!
   TBranch        *b_LepGood_convVeto;   //!
   TBranch        *b_LepGood_lostHits;   //!
   TBranch        *b_LepGood_relIso03;   //!
   TBranch        *b_LepGood_relIso04;   //!
   TBranch        *b_LepGood_miniRelIso;   //!
   TBranch        *b_LepGood_relIsoAn04;   //!
   TBranch        *b_LepGood_tightCharge;   //!
   TBranch        *b_LepGood_mcMatchId;   //!
   TBranch        *b_LepGood_mcMatchAny;   //!
   TBranch        *b_LepGood_mcMatchTau;   //!
   TBranch        *b_LepGood_mcPt;   //!
   TBranch        *b_LepGood_mediumMuonId;   //!
   TBranch        *b_LepGood_pdgId;   //!
   TBranch        *b_LepGood_pt;   //!
   TBranch        *b_LepGood_eta;   //!
   TBranch        *b_LepGood_phi;   //!
   TBranch        *b_LepGood_mass;   //!
   TBranch        *b_LepGood_chargedHadRelIso03;   //!
   TBranch        *b_LepGood_chargedHadRelIso04;   //!
   TBranch        *b_LepGood_softMuonId;   //!
   TBranch        *b_LepGood_pfMuonId;   //!
   TBranch        *b_LepGood_eleCutId2012_full5x5;   //!
   TBranch        *b_LepGood_trackerLayers;   //!
   TBranch        *b_LepGood_pixelLayers;   //!
   TBranch        *b_LepGood_trackerHits;   //!
   TBranch        *b_LepGood_lostOuterHits;   //!
   TBranch        *b_LepGood_innerTrackValidHitFraction;   //!
   TBranch        *b_LepGood_innerTrackChi2;   //!
   TBranch        *b_LepGood_nStations;   //!
   TBranch        *b_LepGood_caloCompatibility;   //!
   TBranch        *b_LepGood_globalTrackChi2;   //!
   TBranch        *b_LepGood_trkKink;   //!
   TBranch        *b_LepGood_segmentCompatibility;   //!
   TBranch        *b_LepGood_chi2LocalPosition;   //!
   TBranch        *b_LepGood_chi2LocalMomentum;   //!
   TBranch        *b_LepGood_glbTrackProbability;   //!
   TBranch        *b_LepGood_sigmaIEtaIEta;   //!
   TBranch        *b_LepGood_dEtaScTrkIn;   //!
   TBranch        *b_LepGood_dPhiScTrkIn;   //!
   TBranch        *b_LepGood_hadronicOverEm;   //!
   TBranch        *b_LepGood_eInvMinusPInv;   //!
   TBranch        *b_LepGood_eInvMinusPInv_tkMom;   //!
   TBranch        *b_LepGood_etaSc;   //!
   TBranch        *b_LepGood_miniRelIsoCharged;   //!
   TBranch        *b_LepGood_miniRelIsoNeutral;   //!
   TBranch        *b_LepGood_hasSV;   //!
   TBranch        *b_LepGood_svRedPt;   //!
   TBranch        *b_LepGood_svRedM;   //!
   TBranch        *b_LepGood_svLepSip3d;   //!
   TBranch        *b_LepGood_svSip3d;   //!
   TBranch        *b_LepGood_svNTracks;   //!
   TBranch        *b_LepGood_svChi2n;   //!
   TBranch        *b_LepGood_svDxy;   //!
   TBranch        *b_LepGood_svMass;   //!
   TBranch        *b_LepGood_svPt;   //!
   TBranch        *b_LepGood_svMCMatchFraction;   //!
   TBranch        *b_LepGood_svMva;   //!
   TBranch        *b_LepGood_jetNDau;   //!
   TBranch        *b_LepGood_jetNDauCharged;   //!
   TBranch        *b_LepGood_jetNDauPV;   //!
   TBranch        *b_LepGood_jetNDauNotPV;   //!
   TBranch        *b_LepGood_jetmaxSignedSip3D;   //!
   TBranch        *b_LepGood_jetmaxSip3D;   //!
   TBranch        *b_LepGood_jetmaxSignedSip2D;   //!
   TBranch        *b_LepGood_jetmaxSip2D;   //!
   TBranch        *b_LepGood_jetPtRelv0;   //!
   TBranch        *b_LepGood_jetMass;   //!
   TBranch        *b_LepGood_jetPrunedMass;   //!
   TBranch        *b_LepGood_jetDecDR;   //!
   TBranch        *b_LepGood_jetDecPtRel;   //!
   TBranch        *b_LepGood_jetDecPtRatio;   //!
   TBranch        *b_LepGood_jetDecPrunedMass;   //!
   TBranch        *b_LepGood_jetDecPrunedPtRatio;   //!
   TBranch        *b_LepGood_jetDec02DR;   //!
   TBranch        *b_LepGood_jetDec02PtRel;   //!
   TBranch        *b_LepGood_jetDec02PtRatio;   //!
   TBranch        *b_LepGood_jetDec02PrunedPtRatio;   //!
   TBranch        *b_LepGood_jetDec02PrunedMass;   //!
   TBranch        *b_LepGood_jetRawPt;   //!
   TBranch        *b_LepGood_jetCorrFactor_L1;   //!
   TBranch        *b_LepGood_jetCorrFactor_L1L2;   //!
   TBranch        *b_LepGood_jetCorrFactor_L1L2L3;   //!
   TBranch        *b_LepGood_jetCorrFactor_L1L2L3Res;   //!
   TBranch        *b_LepGood_jetPtRatio_Raw;   //!
   TBranch        *b_LepGood_jetPtRelHv2;   //!
   TBranch        *b_LepGood_ecalPFClusterIso;   //!
   TBranch        *b_LepGood_hcalPFClusterIso;   //!
   TBranch        *b_LepGood_dr03TkSumPt;   //!
   TBranch        *b_LepGood_trackIso;   //!
   TBranch        *b_LepGood_jetLepAwareJEC_pt;   //!
   TBranch        *b_LepGood_jetLepAwareJEC_eta;   //!
   TBranch        *b_LepGood_jetLepAwareJEC_phi;   //!
   TBranch        *b_LepGood_jetLepAwareJEC_energy;   //!
   TBranch        *b_ngenLepFromTau;   //!
   TBranch        *b_genLepFromTau_motherId;   //!
   TBranch        *b_genLepFromTau_grandmotherId;   //!
   TBranch        *b_genLepFromTau_sourceId;   //!
   TBranch        *b_genLepFromTau_charge;   //!
   TBranch        *b_genLepFromTau_status;   //!
   TBranch        *b_genLepFromTau_pdgId;   //!
   TBranch        *b_genLepFromTau_pt;   //!
   TBranch        *b_genLepFromTau_eta;   //!
   TBranch        *b_genLepFromTau_phi;   //!
   TBranch        *b_genLepFromTau_mass;   //!
   TBranch        *b_genLepFromTau_motherIndex;   //!
   TBranch        *b_nGenBHad;   //!
   TBranch        *b_GenBHad_charge;   //!
   TBranch        *b_GenBHad_status;   //!
   TBranch        *b_GenBHad_pdgId;   //!
   TBranch        *b_GenBHad_pt;   //!
   TBranch        *b_GenBHad_eta;   //!
   TBranch        *b_GenBHad_phi;   //!
   TBranch        *b_GenBHad_mass;   //!
   TBranch        *b_GenBHad_flav;   //!
   TBranch        *b_GenBHad_sourceId;   //!
   TBranch        *b_GenBHad_svMass;   //!
   TBranch        *b_GenBHad_svPt;   //!
   TBranch        *b_GenBHad_svCharge;   //!
   TBranch        *b_GenBHad_svNtracks;   //!
   TBranch        *b_GenBHad_svChi2;   //!
   TBranch        *b_GenBHad_svNdof;   //!
   TBranch        *b_GenBHad_svDxy;   //!
   TBranch        *b_GenBHad_svEdxy;   //!
   TBranch        *b_GenBHad_svIp3d;   //!
   TBranch        *b_GenBHad_svEip3d;   //!
   TBranch        *b_GenBHad_svSip3d;   //!
   TBranch        *b_GenBHad_svCosTheta;   //!
   TBranch        *b_GenBHad_svMva;   //!
   TBranch        *b_GenBHad_jetPt;   //!
   TBranch        *b_GenBHad_jetBTagCSV;   //!
   TBranch        *b_GenBHad_jetBTagCMVA;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_Jet_mcMatchFlav;   //!
   TBranch        *b_Jet_charge;   //!
   TBranch        *b_Jet_area;   //!
   TBranch        *b_Jet_qgl;   //!
   TBranch        *b_Jet_ptd;   //!
   TBranch        *b_Jet_axis2;   //!
   TBranch        *b_Jet_mult;   //!
   TBranch        *b_Jet_partonId;   //!
   TBranch        *b_Jet_partonMotherId;   //!
   TBranch        *b_Jet_nLeptons;   //!
   TBranch        *b_Jet_id;   //!
   TBranch        *b_Jet_puId;   //!
   TBranch        *b_Jet_btagCSV;   //!
   TBranch        *b_Jet_btagCMVA;   //!
   TBranch        *b_Jet_rawPt;   //!
   TBranch        *b_Jet_mcPt;   //!
   TBranch        *b_Jet_mcFlavour;   //!
   TBranch        *b_Jet_mcMatchId;   //!
   TBranch        *b_Jet_corr_JECUp;   //!
   TBranch        *b_Jet_corr_JECDown;   //!
   TBranch        *b_Jet_corr;   //!
   TBranch        *b_Jet_px;   //!
   TBranch        *b_Jet_py;   //!
   TBranch        *b_Jet_pz;   //!
   TBranch        *b_Jet_energy;   //!
   TBranch        *b_Jet_mcPx;   //!
   TBranch        *b_Jet_mcPy;   //!
   TBranch        *b_Jet_mcPz;   //!
   TBranch        *b_Jet_mcEnergy;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_mass;   //!
   TBranch        *b_Jet_prunedMass;   //!
   TBranch        *b_Jet_mcNumPartons;   //!
   TBranch        *b_Jet_mcNumLeptons;   //!
   TBranch        *b_Jet_mcNumTaus;   //!
   TBranch        *b_Jet_mcAnyPartonMass;   //!
   TBranch        *b_Jet_nSubJets;   //!
   TBranch        *b_Jet_nSubJets25;   //!
   TBranch        *b_Jet_nSubJets30;   //!
   TBranch        *b_Jet_nSubJets40;   //!
   TBranch        *b_Jet_nSubJetsZ01;   //!
   TBranch        *b_Jet_chHEF;   //!
   TBranch        *b_Jet_neHEF;   //!
   TBranch        *b_Jet_phEF;   //!
   TBranch        *b_Jet_eEF;   //!
   TBranch        *b_Jet_muEF;   //!
   TBranch        *b_Jet_HFHEF;   //!
   TBranch        *b_Jet_HFEMEF;   //!
   TBranch        *b_Jet_chHMult;   //!
   TBranch        *b_Jet_neHMult;   //!
   TBranch        *b_Jet_phMult;   //!
   TBranch        *b_Jet_eMult;   //!
   TBranch        *b_Jet_muMult;   //!
   TBranch        *b_Jet_HFHMult;   //!
   TBranch        *b_Jet_HFEMMult;   //!
   TBranch        *b_Jet_CorrFactor_L1;   //!
   TBranch        *b_Jet_CorrFactor_L1L2;   //!
   TBranch        *b_Jet_CorrFactor_L1L2L3;   //!
   TBranch        *b_Jet_CorrFactor_L1L2L3Res;   //!
   TBranch        *b_ngenLep;   //!
   TBranch        *b_genLep_motherId;   //!
   TBranch        *b_genLep_grandmotherId;   //!
   TBranch        *b_genLep_sourceId;   //!
   TBranch        *b_genLep_charge;   //!
   TBranch        *b_genLep_status;   //!
   TBranch        *b_genLep_pdgId;   //!
   TBranch        *b_genLep_pt;   //!
   TBranch        *b_genLep_eta;   //!
   TBranch        *b_genLep_phi;   //!
   TBranch        *b_genLep_mass;   //!
   TBranch        *b_genLep_motherIndex;   //!
   TBranch        *b_nLHEweight;   //!
   TBranch        *b_LHEweight_id;   //!
   TBranch        *b_LHEweight_wgt;   //!
   TBranch        *b_nTauGood;   //!
   TBranch        *b_TauGood_charge;   //!
   TBranch        *b_TauGood_decayMode;   //!
   TBranch        *b_TauGood_idDecayMode;   //!
   TBranch        *b_TauGood_idDecayModeNewDMs;   //!
   TBranch        *b_TauGood_dxy;   //!
   TBranch        *b_TauGood_dz;   //!
   TBranch        *b_TauGood_idMVA;   //!
   TBranch        *b_TauGood_idMVANewDM;   //!
   TBranch        *b_TauGood_idCI3hit;   //!
   TBranch        *b_TauGood_idAntiMu;   //!
   TBranch        *b_TauGood_idAntiE;   //!
   TBranch        *b_TauGood_isoCI3hit;   //!
   TBranch        *b_TauGood_mcMatchId;   //!
   TBranch        *b_TauGood_pdgId;   //!
   TBranch        *b_TauGood_pt;   //!
   TBranch        *b_TauGood_eta;   //!
   TBranch        *b_TauGood_phi;   //!
   TBranch        *b_TauGood_mass;   //!

   Data(TTree *tree=0);
   virtual ~Data();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Data_cxx
Data::Data(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/gpfs/csic_projects/cms/palencia/heppyTrees/oct27/27Oct2015/Tree_TTLep_pow_0.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/gpfs/csic_projects/cms/palencia/heppyTrees/oct27/27Oct2015/Tree_TTLep_pow_0.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

Data::~Data()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Data::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Data::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Data::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   fChain->SetBranchAddress("isData", &isData, &b_isData);
   fChain->SetBranchAddress("xsec", &xsec, &b_xsec);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   fChain->SetBranchAddress("nTrueInt", &nTrueInt, &b_nTrueInt);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("rhoCN", &rhoCN, &b_rhoCN);
   fChain->SetBranchAddress("nVert", &nVert, &b_nVert);
   fChain->SetBranchAddress("GenSusyMScan1", &GenSusyMScan1, &b_GenSusyMScan1);
   fChain->SetBranchAddress("GenSusyMScan2", &GenSusyMScan2, &b_GenSusyMScan2);
   fChain->SetBranchAddress("GenSusyMScan3", &GenSusyMScan3, &b_GenSusyMScan3);
   fChain->SetBranchAddress("GenSusyMScan4", &GenSusyMScan4, &b_GenSusyMScan4);
   fChain->SetBranchAddress("GenSusyMGluino", &GenSusyMGluino, &b_GenSusyMGluino);
   fChain->SetBranchAddress("GenSusyMGravitino", &GenSusyMGravitino, &b_GenSusyMGravitino);
   fChain->SetBranchAddress("GenSusyMStop", &GenSusyMStop, &b_GenSusyMStop);
   fChain->SetBranchAddress("GenSusyMSbottom", &GenSusyMSbottom, &b_GenSusyMSbottom);
   fChain->SetBranchAddress("GenSusyMStop2", &GenSusyMStop2, &b_GenSusyMStop2);
   fChain->SetBranchAddress("GenSusyMSbottom2", &GenSusyMSbottom2, &b_GenSusyMSbottom2);
   fChain->SetBranchAddress("GenSusyMSquark", &GenSusyMSquark, &b_GenSusyMSquark);
   fChain->SetBranchAddress("GenSusyMNeutralino", &GenSusyMNeutralino, &b_GenSusyMNeutralino);
   fChain->SetBranchAddress("GenSusyMNeutralino2", &GenSusyMNeutralino2, &b_GenSusyMNeutralino2);
   fChain->SetBranchAddress("GenSusyMNeutralino3", &GenSusyMNeutralino3, &b_GenSusyMNeutralino3);
   fChain->SetBranchAddress("GenSusyMNeutralino4", &GenSusyMNeutralino4, &b_GenSusyMNeutralino4);
   fChain->SetBranchAddress("GenSusyMChargino", &GenSusyMChargino, &b_GenSusyMChargino);
   fChain->SetBranchAddress("GenSusyMChargino2", &GenSusyMChargino2, &b_GenSusyMChargino2);
   fChain->SetBranchAddress("minDrllAFSS", &minDrllAFSS, &b_minDrllAFSS);
   fChain->SetBranchAddress("m3l", &m3l, &b_m3l);
   fChain->SetBranchAddress("hbheFilterNew50ns", &hbheFilterNew50ns, &b_hbheFilterNew50ns);
   fChain->SetBranchAddress("hbheFilterNew25ns", &hbheFilterNew25ns, &b_hbheFilterNew25ns);
   fChain->SetBranchAddress("hbheFilterIso", &hbheFilterIso, &b_hbheFilterIso);
   fChain->SetBranchAddress("met_trkPt", &met_trkPt, &b_met_trkPt);
   fChain->SetBranchAddress("met_trkPhi", &met_trkPhi, &b_met_trkPhi);
   fChain->SetBranchAddress("metNoHF_trkPt", &metNoHF_trkPt, &b_metNoHF_trkPt);
   fChain->SetBranchAddress("metNoHF_trkPhi", &metNoHF_trkPhi, &b_metNoHF_trkPhi);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v", &HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v, &b_HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled", &HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled, &b_HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_DoubleElHT", &HLT_DoubleElHT, &b_HLT_DoubleElHT);
   fChain->SetBranchAddress("HLT_DoubleElHT_isUnprescaled", &HLT_DoubleElHT_isUnprescaled, &b_HLT_DoubleElHT_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v", &HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v, &b_HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_isUnprescaled", &HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_isUnprescaled, &b_HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_TripleEl", &HLT_TripleEl, &b_HLT_TripleEl);
   fChain->SetBranchAddress("HLT_TripleEl_isUnprescaled", &HLT_TripleEl_isUnprescaled, &b_HLT_TripleEl_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v", &HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v, &b_HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled", &HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled, &b_HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_MuEGHT", &HLT_MuEGHT, &b_HLT_MuEGHT);
   fChain->SetBranchAddress("HLT_MuEGHT_isUnprescaled", &HLT_MuEGHT_isUnprescaled, &b_HLT_MuEGHT_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_NoiseCleaned_PFMHTNoMu90_IDTight_v", &HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_NoiseCleaned_PFMHTNoMu90_IDTight_v, &b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_NoiseCleaned_PFMHTNoMu90_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_NoiseCleaned_PFMHTNoMu90_IDTight_v_isUnprescaled", &HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_NoiseCleaned_PFMHTNoMu90_IDTight_v_isUnprescaled, &b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_NoiseCleaned_PFMHTNoMu90_IDTight_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu90_IDTight_v", &HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu90_IDTight_v, &b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu90_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu90_IDTight_v_isUnprescaled", &HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu90_IDTight_v_isUnprescaled, &b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu90_IDTight_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_MonoJet80MET90", &HLT_MonoJet80MET90, &b_HLT_MonoJet80MET90);
   fChain->SetBranchAddress("HLT_MonoJet80MET90_isUnprescaled", &HLT_MonoJet80MET90_isUnprescaled, &b_HLT_MonoJet80MET90_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu24_eta2p1_v", &HLT_BIT_HLT_IsoMu24_eta2p1_v, &b_HLT_BIT_HLT_IsoMu24_eta2p1_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu24_eta2p1_v_isUnprescaled", &HLT_BIT_HLT_IsoMu24_eta2p1_v_isUnprescaled, &b_HLT_BIT_HLT_IsoMu24_eta2p1_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu24_eta2p1_v", &HLT_BIT_HLT_IsoTkMu24_eta2p1_v, &b_HLT_BIT_HLT_IsoTkMu24_eta2p1_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu24_eta2p1_v_isUnprescaled", &HLT_BIT_HLT_IsoTkMu24_eta2p1_v_isUnprescaled, &b_HLT_BIT_HLT_IsoTkMu24_eta2p1_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu18_v", &HLT_BIT_HLT_IsoMu18_v, &b_HLT_BIT_HLT_IsoMu18_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu18_v_isUnprescaled", &HLT_BIT_HLT_IsoMu18_v_isUnprescaled, &b_HLT_BIT_HLT_IsoMu18_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu20_v", &HLT_BIT_HLT_IsoMu20_v, &b_HLT_BIT_HLT_IsoMu20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu20_v_isUnprescaled", &HLT_BIT_HLT_IsoMu20_v_isUnprescaled, &b_HLT_BIT_HLT_IsoMu20_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu20_v", &HLT_BIT_HLT_IsoTkMu20_v, &b_HLT_BIT_HLT_IsoTkMu20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu20_v_isUnprescaled", &HLT_BIT_HLT_IsoTkMu20_v_isUnprescaled, &b_HLT_BIT_HLT_IsoTkMu20_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu27_v", &HLT_BIT_HLT_IsoMu27_v, &b_HLT_BIT_HLT_IsoMu27_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu27_v_isUnprescaled", &HLT_BIT_HLT_IsoMu27_v_isUnprescaled, &b_HLT_BIT_HLT_IsoMu27_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu27_v", &HLT_BIT_HLT_IsoTkMu27_v, &b_HLT_BIT_HLT_IsoTkMu27_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu27_v_isUnprescaled", &HLT_BIT_HLT_IsoTkMu27_v_isUnprescaled, &b_HLT_BIT_HLT_IsoTkMu27_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_SingleMu", &HLT_SingleMu, &b_HLT_SingleMu);
   fChain->SetBranchAddress("HLT_SingleMu_isUnprescaled", &HLT_SingleMu_isUnprescaled, &b_HLT_SingleMu_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v", &HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v, &b_HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_isUnprescaled", &HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_isUnprescaled, &b_HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_DoubleMuEl", &HLT_DoubleMuEl, &b_HLT_DoubleMuEl);
   fChain->SetBranchAddress("HLT_DoubleMuEl_isUnprescaled", &HLT_DoubleMuEl_isUnprescaled, &b_HLT_DoubleMuEl_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v", &HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v, &b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v_isUnprescaled", &HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v_isUnprescaled, &b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu120_IDTight_v", &HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu120_IDTight_v, &b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu120_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu120_IDTight_v_isUnprescaled", &HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu120_IDTight_v_isUnprescaled, &b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu120_IDTight_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_MonoJet80MET120", &HLT_MonoJet80MET120, &b_HLT_MonoJet80MET120);
   fChain->SetBranchAddress("HLT_MonoJet80MET120_isUnprescaled", &HLT_MonoJet80MET120_isUnprescaled, &b_HLT_MonoJet80MET120_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_TripleMu_12_10_5_v", &HLT_BIT_HLT_TripleMu_12_10_5_v, &b_HLT_BIT_HLT_TripleMu_12_10_5_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_TripleMu_12_10_5_v_isUnprescaled", &HLT_BIT_HLT_TripleMu_12_10_5_v_isUnprescaled, &b_HLT_BIT_HLT_TripleMu_12_10_5_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_TripleMu", &HLT_TripleMu, &b_HLT_TripleMu);
   fChain->SetBranchAddress("HLT_TripleMu_isUnprescaled", &HLT_TripleMu_isUnprescaled, &b_HLT_TripleMu_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v", &HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v, &b_HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_isUnprescaled", &HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_DoubleElMu", &HLT_DoubleElMu, &b_HLT_DoubleElMu);
   fChain->SetBranchAddress("HLT_DoubleElMu_isUnprescaled", &HLT_DoubleElMu_isUnprescaled, &b_HLT_DoubleElMu_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu30_TkMu11_v", &HLT_BIT_HLT_Mu30_TkMu11_v, &b_HLT_BIT_HLT_Mu30_TkMu11_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu30_TkMu11_v_isUnprescaled", &HLT_BIT_HLT_Mu30_TkMu11_v_isUnprescaled, &b_HLT_BIT_HLT_Mu30_TkMu11_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_DoubleMuNoIso", &HLT_DoubleMuNoIso, &b_HLT_DoubleMuNoIso);
   fChain->SetBranchAddress("HLT_DoubleMuNoIso_isUnprescaled", &HLT_DoubleMuNoIso_isUnprescaled, &b_HLT_DoubleMuNoIso_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_Mu8_SameSign_v", &HLT_BIT_HLT_Mu17_Mu8_SameSign_v, &b_HLT_BIT_HLT_Mu17_Mu8_SameSign_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_Mu8_SameSign_v_isUnprescaled", &HLT_BIT_HLT_Mu17_Mu8_SameSign_v_isUnprescaled, &b_HLT_BIT_HLT_Mu17_Mu8_SameSign_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v", &HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v, &b_HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_isUnprescaled", &HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_isUnprescaled, &b_HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_DoubleMuSS", &HLT_DoubleMuSS, &b_HLT_DoubleMuSS);
   fChain->SetBranchAddress("HLT_DoubleMuSS_isUnprescaled", &HLT_DoubleMuSS_isUnprescaled, &b_HLT_DoubleMuSS_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele23_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele23_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_WPLoose_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele23_WPLoose_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele23_WPLoose_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele27_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele27_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_WPLoose_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele27_WPLoose_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele27_WPLoose_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_WP85_Gsf_v", &HLT_BIT_HLT_Ele27_WP85_Gsf_v, &b_HLT_BIT_HLT_Ele27_WP85_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_WP85_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele27_WP85_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele27_WP85_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v", &HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v, &b_HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v", &HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v, &b_HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_SingleEl", &HLT_SingleEl, &b_HLT_SingleEl);
   fChain->SetBranchAddress("HLT_SingleEl_isUnprescaled", &HLT_SingleEl_isUnprescaled, &b_HLT_SingleEl_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v", &HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v, &b_HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_isUnprescaled", &HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_isUnprescaled, &b_HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_TripleMuA", &HLT_TripleMuA, &b_HLT_TripleMuA);
   fChain->SetBranchAddress("HLT_TripleMuA_isUnprescaled", &HLT_TripleMuA_isUnprescaled, &b_HLT_TripleMuA_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled", &HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled", &HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled", &HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_MuEG", &HLT_MuEG, &b_HLT_MuEG);
   fChain->SetBranchAddress("HLT_MuEG_isUnprescaled", &HLT_MuEG_isUnprescaled, &b_HLT_MuEG_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v", &HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v, &b_HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_isUnprescaled", &HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_isUnprescaled, &b_HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_DoubleMuHT", &HLT_DoubleMuHT, &b_HLT_DoubleMuHT);
   fChain->SetBranchAddress("HLT_DoubleMuHT_isUnprescaled", &HLT_DoubleMuHT_isUnprescaled, &b_HLT_DoubleMuHT_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", &HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v, &b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled", &HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled, &b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", &HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v, &b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled", &HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled, &b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_DoubleEl", &HLT_DoubleEl, &b_HLT_DoubleEl);
   fChain->SetBranchAddress("HLT_DoubleEl_isUnprescaled", &HLT_DoubleEl_isUnprescaled, &b_HLT_DoubleEl_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_isUnprescaled", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_isUnprescaled, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_isUnprescaled", &HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_isUnprescaled, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_DoubleMu", &HLT_DoubleMu, &b_HLT_DoubleMu);
   fChain->SetBranchAddress("HLT_DoubleMu_isUnprescaled", &HLT_DoubleMu_isUnprescaled, &b_HLT_DoubleMu_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v", &HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v, &b_HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v_isUnprescaled", &HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v_isUnprescaled, &b_HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_METMu5", &HLT_METMu5, &b_HLT_METMu5);
   fChain->SetBranchAddress("HLT_METMu5_isUnprescaled", &HLT_METMu5_isUnprescaled, &b_HLT_METMu5_isUnprescaled);
   fChain->SetBranchAddress("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter, &b_Flag_HBHENoiseIsoFilter);
   fChain->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter, &b_Flag_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("Flag_trkPOG_manystripclus53X", &Flag_trkPOG_manystripclus53X, &b_Flag_trkPOG_manystripclus53X);
   fChain->SetBranchAddress("Flag_ecalLaserCorrFilter", &Flag_ecalLaserCorrFilter, &b_Flag_ecalLaserCorrFilter);
   fChain->SetBranchAddress("Flag_trkPOG_toomanystripclus53X", &Flag_trkPOG_toomanystripclus53X, &b_Flag_trkPOG_toomanystripclus53X);
   fChain->SetBranchAddress("Flag_hcalLaserEventFilter", &Flag_hcalLaserEventFilter, &b_Flag_hcalLaserEventFilter);
   fChain->SetBranchAddress("Flag_trkPOG_logErrorTooManyClusters", &Flag_trkPOG_logErrorTooManyClusters, &b_Flag_trkPOG_logErrorTooManyClusters);
   fChain->SetBranchAddress("Flag_trkPOGFilters", &Flag_trkPOGFilters, &b_Flag_trkPOGFilters);
   fChain->SetBranchAddress("Flag_trackingFailureFilter", &Flag_trackingFailureFilter, &b_Flag_trackingFailureFilter);
   fChain->SetBranchAddress("Flag_CSCTightHaloFilter", &Flag_CSCTightHaloFilter, &b_Flag_CSCTightHaloFilter);
   fChain->SetBranchAddress("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter, &b_Flag_HBHENoiseFilter);
   fChain->SetBranchAddress("Flag_goodVertices", &Flag_goodVertices, &b_Flag_goodVertices);
   fChain->SetBranchAddress("Flag_METFilters", &Flag_METFilters, &b_Flag_METFilters);
   fChain->SetBranchAddress("Flag_eeBadScFilter", &Flag_eeBadScFilter, &b_Flag_eeBadScFilter);
   fChain->SetBranchAddress("met_pt", &met_pt, &b_met_pt);
   fChain->SetBranchAddress("met_eta", &met_eta, &b_met_eta);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("met_mass", &met_mass, &b_met_mass);
   fChain->SetBranchAddress("met_sumEt", &met_sumEt, &b_met_sumEt);
   fChain->SetBranchAddress("met_rawPt", &met_rawPt, &b_met_rawPt);
   fChain->SetBranchAddress("met_rawPhi", &met_rawPhi, &b_met_rawPhi);
   fChain->SetBranchAddress("met_rawSumEt", &met_rawSumEt, &b_met_rawSumEt);
   fChain->SetBranchAddress("met_genPt", &met_genPt, &b_met_genPt);
   fChain->SetBranchAddress("met_genPhi", &met_genPhi, &b_met_genPhi);
   fChain->SetBranchAddress("met_genEta", &met_genEta, &b_met_genEta);
   fChain->SetBranchAddress("metNoHF_pt", &metNoHF_pt, &b_metNoHF_pt);
   fChain->SetBranchAddress("metNoHF_eta", &metNoHF_eta, &b_metNoHF_eta);
   fChain->SetBranchAddress("metNoHF_phi", &metNoHF_phi, &b_metNoHF_phi);
   fChain->SetBranchAddress("metNoHF_mass", &metNoHF_mass, &b_metNoHF_mass);
   fChain->SetBranchAddress("metNoHF_sumEt", &metNoHF_sumEt, &b_metNoHF_sumEt);
   fChain->SetBranchAddress("metNoHF_rawPt", &metNoHF_rawPt, &b_metNoHF_rawPt);
   fChain->SetBranchAddress("metNoHF_rawPhi", &metNoHF_rawPhi, &b_metNoHF_rawPhi);
   fChain->SetBranchAddress("metNoHF_rawSumEt", &metNoHF_rawSumEt, &b_metNoHF_rawSumEt);
   fChain->SetBranchAddress("metNoHF_genPt", &metNoHF_genPt, &b_metNoHF_genPt);
   fChain->SetBranchAddress("metNoHF_genPhi", &metNoHF_genPhi, &b_metNoHF_genPhi);
   fChain->SetBranchAddress("metNoHF_genEta", &metNoHF_genEta, &b_metNoHF_genEta);
   fChain->SetBranchAddress("nFatJet", &nFatJet, &b_nFatJet);
   fChain->SetBranchAddress("FatJet_id", FatJet_id, &b_FatJet_id);
   fChain->SetBranchAddress("FatJet_puId", FatJet_puId, &b_FatJet_puId);
   fChain->SetBranchAddress("FatJet_btagCSV", FatJet_btagCSV, &b_FatJet_btagCSV);
   fChain->SetBranchAddress("FatJet_btagCMVA", FatJet_btagCMVA, &b_FatJet_btagCMVA);
   fChain->SetBranchAddress("FatJet_rawPt", FatJet_rawPt, &b_FatJet_rawPt);
   fChain->SetBranchAddress("FatJet_mcPt", FatJet_mcPt, &b_FatJet_mcPt);
   fChain->SetBranchAddress("FatJet_mcFlavour", FatJet_mcFlavour, &b_FatJet_mcFlavour);
   fChain->SetBranchAddress("FatJet_mcMatchId", FatJet_mcMatchId, &b_FatJet_mcMatchId);
   fChain->SetBranchAddress("FatJet_corr_JECUp", FatJet_corr_JECUp, &b_FatJet_corr_JECUp);
   fChain->SetBranchAddress("FatJet_corr_JECDown", FatJet_corr_JECDown, &b_FatJet_corr_JECDown);
   fChain->SetBranchAddress("FatJet_corr", FatJet_corr, &b_FatJet_corr);
   fChain->SetBranchAddress("FatJet_px", FatJet_px, &b_FatJet_px);
   fChain->SetBranchAddress("FatJet_py", FatJet_py, &b_FatJet_py);
   fChain->SetBranchAddress("FatJet_pz", FatJet_pz, &b_FatJet_pz);
   fChain->SetBranchAddress("FatJet_energy", FatJet_energy, &b_FatJet_energy);
   fChain->SetBranchAddress("FatJet_mcPx", FatJet_mcPx, &b_FatJet_mcPx);
   fChain->SetBranchAddress("FatJet_mcPy", FatJet_mcPy, &b_FatJet_mcPy);
   fChain->SetBranchAddress("FatJet_mcPz", FatJet_mcPz, &b_FatJet_mcPz);
   fChain->SetBranchAddress("FatJet_mcEnergy", FatJet_mcEnergy, &b_FatJet_mcEnergy);
   fChain->SetBranchAddress("FatJet_pt", FatJet_pt, &b_FatJet_pt);
   fChain->SetBranchAddress("FatJet_eta", FatJet_eta, &b_FatJet_eta);
   fChain->SetBranchAddress("FatJet_phi", FatJet_phi, &b_FatJet_phi);
   fChain->SetBranchAddress("FatJet_mass", FatJet_mass, &b_FatJet_mass);
   fChain->SetBranchAddress("FatJet_prunedMass", FatJet_prunedMass, &b_FatJet_prunedMass);
   fChain->SetBranchAddress("FatJet_trimmedMass", FatJet_trimmedMass, &b_FatJet_trimmedMass);
   fChain->SetBranchAddress("FatJet_filteredMass", FatJet_filteredMass, &b_FatJet_filteredMass);
   fChain->SetBranchAddress("FatJet_tau1", FatJet_tau1, &b_FatJet_tau1);
   fChain->SetBranchAddress("FatJet_tau2", FatJet_tau2, &b_FatJet_tau2);
   fChain->SetBranchAddress("FatJet_tau3", FatJet_tau3, &b_FatJet_tau3);
   fChain->SetBranchAddress("FatJet_topMass", FatJet_topMass, &b_FatJet_topMass);
   fChain->SetBranchAddress("FatJet_minMass", FatJet_minMass, &b_FatJet_minMass);
   fChain->SetBranchAddress("FatJet_nSubJets", FatJet_nSubJets, &b_FatJet_nSubJets);
   fChain->SetBranchAddress("ngenTau", &ngenTau, &b_ngenTau);
   fChain->SetBranchAddress("genTau_motherId", genTau_motherId, &b_genTau_motherId);
   fChain->SetBranchAddress("genTau_grandmotherId", genTau_grandmotherId, &b_genTau_grandmotherId);
   fChain->SetBranchAddress("genTau_sourceId", genTau_sourceId, &b_genTau_sourceId);
   fChain->SetBranchAddress("genTau_charge", genTau_charge, &b_genTau_charge);
   fChain->SetBranchAddress("genTau_status", genTau_status, &b_genTau_status);
   fChain->SetBranchAddress("genTau_pdgId", genTau_pdgId, &b_genTau_pdgId);
   fChain->SetBranchAddress("genTau_pt", genTau_pt, &b_genTau_pt);
   fChain->SetBranchAddress("genTau_eta", genTau_eta, &b_genTau_eta);
   fChain->SetBranchAddress("genTau_phi", genTau_phi, &b_genTau_phi);
   fChain->SetBranchAddress("genTau_mass", genTau_mass, &b_genTau_mass);
   fChain->SetBranchAddress("genTau_motherIndex", genTau_motherIndex, &b_genTau_motherIndex);
   fChain->SetBranchAddress("nGenPart", &nGenPart, &b_nGenPart);
   fChain->SetBranchAddress("GenPart_motherId", GenPart_motherId, &b_GenPart_motherId);
   fChain->SetBranchAddress("GenPart_grandmotherId", GenPart_grandmotherId, &b_GenPart_grandmotherId);
   fChain->SetBranchAddress("GenPart_sourceId", GenPart_sourceId, &b_GenPart_sourceId);
   fChain->SetBranchAddress("GenPart_charge", GenPart_charge, &b_GenPart_charge);
   fChain->SetBranchAddress("GenPart_status", GenPart_status, &b_GenPart_status);
   fChain->SetBranchAddress("GenPart_pdgId", GenPart_pdgId, &b_GenPart_pdgId);
   fChain->SetBranchAddress("GenPart_pt", GenPart_pt, &b_GenPart_pt);
   fChain->SetBranchAddress("GenPart_eta", GenPart_eta, &b_GenPart_eta);
   fChain->SetBranchAddress("GenPart_phi", GenPart_phi, &b_GenPart_phi);
   fChain->SetBranchAddress("GenPart_mass", GenPart_mass, &b_GenPart_mass);
   fChain->SetBranchAddress("GenPart_motherIndex", GenPart_motherIndex, &b_GenPart_motherIndex);
   fChain->SetBranchAddress("nGenTop", &nGenTop, &b_nGenTop);
   fChain->SetBranchAddress("GenTop_pdgId", GenTop_pdgId, &b_GenTop_pdgId);
   fChain->SetBranchAddress("GenTop_pt", GenTop_pt, &b_GenTop_pt);
   fChain->SetBranchAddress("GenTop_eta", GenTop_eta, &b_GenTop_eta);
   fChain->SetBranchAddress("GenTop_phi", GenTop_phi, &b_GenTop_phi);
   fChain->SetBranchAddress("GenTop_mass", GenTop_mass, &b_GenTop_mass);
   fChain->SetBranchAddress("GenTop_charge", GenTop_charge, &b_GenTop_charge);
   fChain->SetBranchAddress("GenTop_status", GenTop_status, &b_GenTop_status);
   fChain->SetBranchAddress("nDiscJet", &nDiscJet, &b_nDiscJet);
   fChain->SetBranchAddress("DiscJet_area", DiscJet_area, &b_DiscJet_area);
   fChain->SetBranchAddress("DiscJet_qgl", DiscJet_qgl, &b_DiscJet_qgl);
   fChain->SetBranchAddress("DiscJet_ptd", DiscJet_ptd, &b_DiscJet_ptd);
   fChain->SetBranchAddress("DiscJet_axis2", DiscJet_axis2, &b_DiscJet_axis2);
   fChain->SetBranchAddress("DiscJet_mult", DiscJet_mult, &b_DiscJet_mult);
   fChain->SetBranchAddress("DiscJet_partonId", DiscJet_partonId, &b_DiscJet_partonId);
   fChain->SetBranchAddress("DiscJet_partonMotherId", DiscJet_partonMotherId, &b_DiscJet_partonMotherId);
   fChain->SetBranchAddress("DiscJet_nLeptons", DiscJet_nLeptons, &b_DiscJet_nLeptons);
   fChain->SetBranchAddress("DiscJet_id", DiscJet_id, &b_DiscJet_id);
   fChain->SetBranchAddress("DiscJet_puId", DiscJet_puId, &b_DiscJet_puId);
   fChain->SetBranchAddress("DiscJet_btagCSV", DiscJet_btagCSV, &b_DiscJet_btagCSV);
   fChain->SetBranchAddress("DiscJet_btagCMVA", DiscJet_btagCMVA, &b_DiscJet_btagCMVA);
   fChain->SetBranchAddress("DiscJet_rawPt", DiscJet_rawPt, &b_DiscJet_rawPt);
   fChain->SetBranchAddress("DiscJet_mcPt", DiscJet_mcPt, &b_DiscJet_mcPt);
   fChain->SetBranchAddress("DiscJet_mcFlavour", DiscJet_mcFlavour, &b_DiscJet_mcFlavour);
   fChain->SetBranchAddress("DiscJet_mcMatchId", DiscJet_mcMatchId, &b_DiscJet_mcMatchId);
   fChain->SetBranchAddress("DiscJet_corr_JECUp", DiscJet_corr_JECUp, &b_DiscJet_corr_JECUp);
   fChain->SetBranchAddress("DiscJet_corr_JECDown", DiscJet_corr_JECDown, &b_DiscJet_corr_JECDown);
   fChain->SetBranchAddress("DiscJet_corr", DiscJet_corr, &b_DiscJet_corr);
   fChain->SetBranchAddress("DiscJet_px", DiscJet_px, &b_DiscJet_px);
   fChain->SetBranchAddress("DiscJet_py", DiscJet_py, &b_DiscJet_py);
   fChain->SetBranchAddress("DiscJet_pz", DiscJet_pz, &b_DiscJet_pz);
   fChain->SetBranchAddress("DiscJet_energy", DiscJet_energy, &b_DiscJet_energy);
   fChain->SetBranchAddress("DiscJet_mcPx", DiscJet_mcPx, &b_DiscJet_mcPx);
   fChain->SetBranchAddress("DiscJet_mcPy", DiscJet_mcPy, &b_DiscJet_mcPy);
   fChain->SetBranchAddress("DiscJet_mcPz", DiscJet_mcPz, &b_DiscJet_mcPz);
   fChain->SetBranchAddress("DiscJet_mcEnergy", DiscJet_mcEnergy, &b_DiscJet_mcEnergy);
   fChain->SetBranchAddress("DiscJet_pt", DiscJet_pt, &b_DiscJet_pt);
   fChain->SetBranchAddress("DiscJet_eta", DiscJet_eta, &b_DiscJet_eta);
   fChain->SetBranchAddress("DiscJet_phi", DiscJet_phi, &b_DiscJet_phi);
   fChain->SetBranchAddress("DiscJet_mass", DiscJet_mass, &b_DiscJet_mass);
   fChain->SetBranchAddress("DiscJet_mcMatchFlav", DiscJet_mcMatchFlav, &b_DiscJet_mcMatchFlav);
   fChain->SetBranchAddress("DiscJet_charge", DiscJet_charge, &b_DiscJet_charge);
   fChain->SetBranchAddress("nLepGood", &nLepGood, &b_nLepGood);
   fChain->SetBranchAddress("LepGood_mvaIdPhys14", LepGood_mvaIdPhys14, &b_LepGood_mvaIdPhys14);
   fChain->SetBranchAddress("LepGood_mvaIdSpring15", LepGood_mvaIdSpring15, &b_LepGood_mvaIdSpring15);
   fChain->SetBranchAddress("LepGood_mvaTTH", LepGood_mvaTTH, &b_LepGood_mvaTTH);
   fChain->SetBranchAddress("LepGood_jetPtRatiov1", LepGood_jetPtRatiov1, &b_LepGood_jetPtRatiov1);
   fChain->SetBranchAddress("LepGood_jetPtRelv1", LepGood_jetPtRelv1, &b_LepGood_jetPtRelv1);
   fChain->SetBranchAddress("LepGood_jetPtRatiov2", LepGood_jetPtRatiov2, &b_LepGood_jetPtRatiov2);
   fChain->SetBranchAddress("LepGood_jetPtRelv2", LepGood_jetPtRelv2, &b_LepGood_jetPtRelv2);
   fChain->SetBranchAddress("LepGood_jetBTagCSV", LepGood_jetBTagCSV, &b_LepGood_jetBTagCSV);
   fChain->SetBranchAddress("LepGood_jetBTagCMVA", LepGood_jetBTagCMVA, &b_LepGood_jetBTagCMVA);
   fChain->SetBranchAddress("LepGood_jetDR", LepGood_jetDR, &b_LepGood_jetDR);
   fChain->SetBranchAddress("LepGood_charge", LepGood_charge, &b_LepGood_charge);
   fChain->SetBranchAddress("LepGood_px", LepGood_px, &b_LepGood_px);
   fChain->SetBranchAddress("LepGood_py", LepGood_py, &b_LepGood_py);
   fChain->SetBranchAddress("LepGood_pz", LepGood_pz, &b_LepGood_pz);
   fChain->SetBranchAddress("LepGood_energy", LepGood_energy, &b_LepGood_energy);
   fChain->SetBranchAddress("LepGood_tightId", LepGood_tightId, &b_LepGood_tightId);
   fChain->SetBranchAddress("LepGood_eleCutIdCSA14_25ns_v1", LepGood_eleCutIdCSA14_25ns_v1, &b_LepGood_eleCutIdCSA14_25ns_v1);
   fChain->SetBranchAddress("LepGood_eleCutIdCSA14_50ns_v1", LepGood_eleCutIdCSA14_50ns_v1, &b_LepGood_eleCutIdCSA14_50ns_v1);
   fChain->SetBranchAddress("LepGood_dxy", LepGood_dxy, &b_LepGood_dxy);
   fChain->SetBranchAddress("LepGood_dz", LepGood_dz, &b_LepGood_dz);
   fChain->SetBranchAddress("LepGood_edxy", LepGood_edxy, &b_LepGood_edxy);
   fChain->SetBranchAddress("LepGood_edz", LepGood_edz, &b_LepGood_edz);
   fChain->SetBranchAddress("LepGood_ip3d", LepGood_ip3d, &b_LepGood_ip3d);
   fChain->SetBranchAddress("LepGood_sip3d", LepGood_sip3d, &b_LepGood_sip3d);
   fChain->SetBranchAddress("LepGood_convVeto", LepGood_convVeto, &b_LepGood_convVeto);
   fChain->SetBranchAddress("LepGood_lostHits", LepGood_lostHits, &b_LepGood_lostHits);
   fChain->SetBranchAddress("LepGood_relIso03", LepGood_relIso03, &b_LepGood_relIso03);
   fChain->SetBranchAddress("LepGood_relIso04", LepGood_relIso04, &b_LepGood_relIso04);
   fChain->SetBranchAddress("LepGood_miniRelIso", LepGood_miniRelIso, &b_LepGood_miniRelIso);
   fChain->SetBranchAddress("LepGood_relIsoAn04", LepGood_relIsoAn04, &b_LepGood_relIsoAn04);
   fChain->SetBranchAddress("LepGood_tightCharge", LepGood_tightCharge, &b_LepGood_tightCharge);
   fChain->SetBranchAddress("LepGood_mcMatchId", LepGood_mcMatchId, &b_LepGood_mcMatchId);
   fChain->SetBranchAddress("LepGood_mcMatchAny", LepGood_mcMatchAny, &b_LepGood_mcMatchAny);
   fChain->SetBranchAddress("LepGood_mcMatchTau", LepGood_mcMatchTau, &b_LepGood_mcMatchTau);
   fChain->SetBranchAddress("LepGood_mcPt", LepGood_mcPt, &b_LepGood_mcPt);
   fChain->SetBranchAddress("LepGood_mediumMuonId", LepGood_mediumMuonId, &b_LepGood_mediumMuonId);
   fChain->SetBranchAddress("LepGood_pdgId", LepGood_pdgId, &b_LepGood_pdgId);
   fChain->SetBranchAddress("LepGood_pt", LepGood_pt, &b_LepGood_pt);
   fChain->SetBranchAddress("LepGood_eta", LepGood_eta, &b_LepGood_eta);
   fChain->SetBranchAddress("LepGood_phi", LepGood_phi, &b_LepGood_phi);
   fChain->SetBranchAddress("LepGood_mass", LepGood_mass, &b_LepGood_mass);
   fChain->SetBranchAddress("LepGood_chargedHadRelIso03", LepGood_chargedHadRelIso03, &b_LepGood_chargedHadRelIso03);
   fChain->SetBranchAddress("LepGood_chargedHadRelIso04", LepGood_chargedHadRelIso04, &b_LepGood_chargedHadRelIso04);
   fChain->SetBranchAddress("LepGood_softMuonId", LepGood_softMuonId, &b_LepGood_softMuonId);
   fChain->SetBranchAddress("LepGood_pfMuonId", LepGood_pfMuonId, &b_LepGood_pfMuonId);
   fChain->SetBranchAddress("LepGood_eleCutId2012_full5x5", LepGood_eleCutId2012_full5x5, &b_LepGood_eleCutId2012_full5x5);
   fChain->SetBranchAddress("LepGood_trackerLayers", LepGood_trackerLayers, &b_LepGood_trackerLayers);
   fChain->SetBranchAddress("LepGood_pixelLayers", LepGood_pixelLayers, &b_LepGood_pixelLayers);
   fChain->SetBranchAddress("LepGood_trackerHits", LepGood_trackerHits, &b_LepGood_trackerHits);
   fChain->SetBranchAddress("LepGood_lostOuterHits", LepGood_lostOuterHits, &b_LepGood_lostOuterHits);
   fChain->SetBranchAddress("LepGood_innerTrackValidHitFraction", LepGood_innerTrackValidHitFraction, &b_LepGood_innerTrackValidHitFraction);
   fChain->SetBranchAddress("LepGood_innerTrackChi2", LepGood_innerTrackChi2, &b_LepGood_innerTrackChi2);
   fChain->SetBranchAddress("LepGood_nStations", LepGood_nStations, &b_LepGood_nStations);
   fChain->SetBranchAddress("LepGood_caloCompatibility", LepGood_caloCompatibility, &b_LepGood_caloCompatibility);
   fChain->SetBranchAddress("LepGood_globalTrackChi2", LepGood_globalTrackChi2, &b_LepGood_globalTrackChi2);
   fChain->SetBranchAddress("LepGood_trkKink", LepGood_trkKink, &b_LepGood_trkKink);
   fChain->SetBranchAddress("LepGood_segmentCompatibility", LepGood_segmentCompatibility, &b_LepGood_segmentCompatibility);
   fChain->SetBranchAddress("LepGood_chi2LocalPosition", LepGood_chi2LocalPosition, &b_LepGood_chi2LocalPosition);
   fChain->SetBranchAddress("LepGood_chi2LocalMomentum", LepGood_chi2LocalMomentum, &b_LepGood_chi2LocalMomentum);
   fChain->SetBranchAddress("LepGood_glbTrackProbability", LepGood_glbTrackProbability, &b_LepGood_glbTrackProbability);
   fChain->SetBranchAddress("LepGood_sigmaIEtaIEta", LepGood_sigmaIEtaIEta, &b_LepGood_sigmaIEtaIEta);
   fChain->SetBranchAddress("LepGood_dEtaScTrkIn", LepGood_dEtaScTrkIn, &b_LepGood_dEtaScTrkIn);
   fChain->SetBranchAddress("LepGood_dPhiScTrkIn", LepGood_dPhiScTrkIn, &b_LepGood_dPhiScTrkIn);
   fChain->SetBranchAddress("LepGood_hadronicOverEm", LepGood_hadronicOverEm, &b_LepGood_hadronicOverEm);
   fChain->SetBranchAddress("LepGood_eInvMinusPInv", LepGood_eInvMinusPInv, &b_LepGood_eInvMinusPInv);
   fChain->SetBranchAddress("LepGood_eInvMinusPInv_tkMom", LepGood_eInvMinusPInv_tkMom, &b_LepGood_eInvMinusPInv_tkMom);
   fChain->SetBranchAddress("LepGood_etaSc", LepGood_etaSc, &b_LepGood_etaSc);
   fChain->SetBranchAddress("LepGood_miniRelIsoCharged", LepGood_miniRelIsoCharged, &b_LepGood_miniRelIsoCharged);
   fChain->SetBranchAddress("LepGood_miniRelIsoNeutral", LepGood_miniRelIsoNeutral, &b_LepGood_miniRelIsoNeutral);
   fChain->SetBranchAddress("LepGood_hasSV", LepGood_hasSV, &b_LepGood_hasSV);
   fChain->SetBranchAddress("LepGood_svRedPt", LepGood_svRedPt, &b_LepGood_svRedPt);
   fChain->SetBranchAddress("LepGood_svRedM", LepGood_svRedM, &b_LepGood_svRedM);
   fChain->SetBranchAddress("LepGood_svLepSip3d", LepGood_svLepSip3d, &b_LepGood_svLepSip3d);
   fChain->SetBranchAddress("LepGood_svSip3d", LepGood_svSip3d, &b_LepGood_svSip3d);
   fChain->SetBranchAddress("LepGood_svNTracks", LepGood_svNTracks, &b_LepGood_svNTracks);
   fChain->SetBranchAddress("LepGood_svChi2n", LepGood_svChi2n, &b_LepGood_svChi2n);
   fChain->SetBranchAddress("LepGood_svDxy", LepGood_svDxy, &b_LepGood_svDxy);
   fChain->SetBranchAddress("LepGood_svMass", LepGood_svMass, &b_LepGood_svMass);
   fChain->SetBranchAddress("LepGood_svPt", LepGood_svPt, &b_LepGood_svPt);
   fChain->SetBranchAddress("LepGood_svMCMatchFraction", LepGood_svMCMatchFraction, &b_LepGood_svMCMatchFraction);
   fChain->SetBranchAddress("LepGood_svMva", LepGood_svMva, &b_LepGood_svMva);
   fChain->SetBranchAddress("LepGood_jetNDau", LepGood_jetNDau, &b_LepGood_jetNDau);
   fChain->SetBranchAddress("LepGood_jetNDauCharged", LepGood_jetNDauCharged, &b_LepGood_jetNDauCharged);
   fChain->SetBranchAddress("LepGood_jetNDauPV", LepGood_jetNDauPV, &b_LepGood_jetNDauPV);
   fChain->SetBranchAddress("LepGood_jetNDauNotPV", LepGood_jetNDauNotPV, &b_LepGood_jetNDauNotPV);
   fChain->SetBranchAddress("LepGood_jetmaxSignedSip3D", LepGood_jetmaxSignedSip3D, &b_LepGood_jetmaxSignedSip3D);
   fChain->SetBranchAddress("LepGood_jetmaxSip3D", LepGood_jetmaxSip3D, &b_LepGood_jetmaxSip3D);
   fChain->SetBranchAddress("LepGood_jetmaxSignedSip2D", LepGood_jetmaxSignedSip2D, &b_LepGood_jetmaxSignedSip2D);
   fChain->SetBranchAddress("LepGood_jetmaxSip2D", LepGood_jetmaxSip2D, &b_LepGood_jetmaxSip2D);
   fChain->SetBranchAddress("LepGood_jetPtRelv0", LepGood_jetPtRelv0, &b_LepGood_jetPtRelv0);
   fChain->SetBranchAddress("LepGood_jetMass", LepGood_jetMass, &b_LepGood_jetMass);
   fChain->SetBranchAddress("LepGood_jetPrunedMass", LepGood_jetPrunedMass, &b_LepGood_jetPrunedMass);
   fChain->SetBranchAddress("LepGood_jetDecDR", LepGood_jetDecDR, &b_LepGood_jetDecDR);
   fChain->SetBranchAddress("LepGood_jetDecPtRel", LepGood_jetDecPtRel, &b_LepGood_jetDecPtRel);
   fChain->SetBranchAddress("LepGood_jetDecPtRatio", LepGood_jetDecPtRatio, &b_LepGood_jetDecPtRatio);
   fChain->SetBranchAddress("LepGood_jetDecPrunedMass", LepGood_jetDecPrunedMass, &b_LepGood_jetDecPrunedMass);
   fChain->SetBranchAddress("LepGood_jetDecPrunedPtRatio", LepGood_jetDecPrunedPtRatio, &b_LepGood_jetDecPrunedPtRatio);
   fChain->SetBranchAddress("LepGood_jetDec02DR", LepGood_jetDec02DR, &b_LepGood_jetDec02DR);
   fChain->SetBranchAddress("LepGood_jetDec02PtRel", LepGood_jetDec02PtRel, &b_LepGood_jetDec02PtRel);
   fChain->SetBranchAddress("LepGood_jetDec02PtRatio", LepGood_jetDec02PtRatio, &b_LepGood_jetDec02PtRatio);
   fChain->SetBranchAddress("LepGood_jetDec02PrunedPtRatio", LepGood_jetDec02PrunedPtRatio, &b_LepGood_jetDec02PrunedPtRatio);
   fChain->SetBranchAddress("LepGood_jetDec02PrunedMass", LepGood_jetDec02PrunedMass, &b_LepGood_jetDec02PrunedMass);
   fChain->SetBranchAddress("LepGood_jetRawPt", LepGood_jetRawPt, &b_LepGood_jetRawPt);
   fChain->SetBranchAddress("LepGood_jetCorrFactor_L1", LepGood_jetCorrFactor_L1, &b_LepGood_jetCorrFactor_L1);
   fChain->SetBranchAddress("LepGood_jetCorrFactor_L1L2", LepGood_jetCorrFactor_L1L2, &b_LepGood_jetCorrFactor_L1L2);
   fChain->SetBranchAddress("LepGood_jetCorrFactor_L1L2L3", LepGood_jetCorrFactor_L1L2L3, &b_LepGood_jetCorrFactor_L1L2L3);
   fChain->SetBranchAddress("LepGood_jetCorrFactor_L1L2L3Res", LepGood_jetCorrFactor_L1L2L3Res, &b_LepGood_jetCorrFactor_L1L2L3Res);
   fChain->SetBranchAddress("LepGood_jetPtRatio_Raw", LepGood_jetPtRatio_Raw, &b_LepGood_jetPtRatio_Raw);
   fChain->SetBranchAddress("LepGood_jetPtRelHv2", LepGood_jetPtRelHv2, &b_LepGood_jetPtRelHv2);
   fChain->SetBranchAddress("LepGood_ecalPFClusterIso", LepGood_ecalPFClusterIso, &b_LepGood_ecalPFClusterIso);
   fChain->SetBranchAddress("LepGood_hcalPFClusterIso", LepGood_hcalPFClusterIso, &b_LepGood_hcalPFClusterIso);
   fChain->SetBranchAddress("LepGood_dr03TkSumPt", LepGood_dr03TkSumPt, &b_LepGood_dr03TkSumPt);
   fChain->SetBranchAddress("LepGood_trackIso", LepGood_trackIso, &b_LepGood_trackIso);
   fChain->SetBranchAddress("LepGood_jetLepAwareJEC_pt", LepGood_jetLepAwareJEC_pt, &b_LepGood_jetLepAwareJEC_pt);
   fChain->SetBranchAddress("LepGood_jetLepAwareJEC_eta", LepGood_jetLepAwareJEC_eta, &b_LepGood_jetLepAwareJEC_eta);
   fChain->SetBranchAddress("LepGood_jetLepAwareJEC_phi", LepGood_jetLepAwareJEC_phi, &b_LepGood_jetLepAwareJEC_phi);
   fChain->SetBranchAddress("LepGood_jetLepAwareJEC_energy", LepGood_jetLepAwareJEC_energy, &b_LepGood_jetLepAwareJEC_energy);
   fChain->SetBranchAddress("ngenLepFromTau", &ngenLepFromTau, &b_ngenLepFromTau);
   fChain->SetBranchAddress("genLepFromTau_motherId", genLepFromTau_motherId, &b_genLepFromTau_motherId);
   fChain->SetBranchAddress("genLepFromTau_grandmotherId", genLepFromTau_grandmotherId, &b_genLepFromTau_grandmotherId);
   fChain->SetBranchAddress("genLepFromTau_sourceId", genLepFromTau_sourceId, &b_genLepFromTau_sourceId);
   fChain->SetBranchAddress("genLepFromTau_charge", genLepFromTau_charge, &b_genLepFromTau_charge);
   fChain->SetBranchAddress("genLepFromTau_status", genLepFromTau_status, &b_genLepFromTau_status);
   fChain->SetBranchAddress("genLepFromTau_pdgId", genLepFromTau_pdgId, &b_genLepFromTau_pdgId);
   fChain->SetBranchAddress("genLepFromTau_pt", genLepFromTau_pt, &b_genLepFromTau_pt);
   fChain->SetBranchAddress("genLepFromTau_eta", genLepFromTau_eta, &b_genLepFromTau_eta);
   fChain->SetBranchAddress("genLepFromTau_phi", genLepFromTau_phi, &b_genLepFromTau_phi);
   fChain->SetBranchAddress("genLepFromTau_mass", genLepFromTau_mass, &b_genLepFromTau_mass);
   fChain->SetBranchAddress("genLepFromTau_motherIndex", genLepFromTau_motherIndex, &b_genLepFromTau_motherIndex);
   fChain->SetBranchAddress("nGenBHad", &nGenBHad, &b_nGenBHad);
   fChain->SetBranchAddress("GenBHad_charge", GenBHad_charge, &b_GenBHad_charge);
   fChain->SetBranchAddress("GenBHad_status", GenBHad_status, &b_GenBHad_status);
   fChain->SetBranchAddress("GenBHad_pdgId", GenBHad_pdgId, &b_GenBHad_pdgId);
   fChain->SetBranchAddress("GenBHad_pt", GenBHad_pt, &b_GenBHad_pt);
   fChain->SetBranchAddress("GenBHad_eta", GenBHad_eta, &b_GenBHad_eta);
   fChain->SetBranchAddress("GenBHad_phi", GenBHad_phi, &b_GenBHad_phi);
   fChain->SetBranchAddress("GenBHad_mass", GenBHad_mass, &b_GenBHad_mass);
   fChain->SetBranchAddress("GenBHad_flav", GenBHad_flav, &b_GenBHad_flav);
   fChain->SetBranchAddress("GenBHad_sourceId", GenBHad_sourceId, &b_GenBHad_sourceId);
   fChain->SetBranchAddress("GenBHad_svMass", GenBHad_svMass, &b_GenBHad_svMass);
   fChain->SetBranchAddress("GenBHad_svPt", GenBHad_svPt, &b_GenBHad_svPt);
   fChain->SetBranchAddress("GenBHad_svCharge", GenBHad_svCharge, &b_GenBHad_svCharge);
   fChain->SetBranchAddress("GenBHad_svNtracks", GenBHad_svNtracks, &b_GenBHad_svNtracks);
   fChain->SetBranchAddress("GenBHad_svChi2", GenBHad_svChi2, &b_GenBHad_svChi2);
   fChain->SetBranchAddress("GenBHad_svNdof", GenBHad_svNdof, &b_GenBHad_svNdof);
   fChain->SetBranchAddress("GenBHad_svDxy", GenBHad_svDxy, &b_GenBHad_svDxy);
   fChain->SetBranchAddress("GenBHad_svEdxy", GenBHad_svEdxy, &b_GenBHad_svEdxy);
   fChain->SetBranchAddress("GenBHad_svIp3d", GenBHad_svIp3d, &b_GenBHad_svIp3d);
   fChain->SetBranchAddress("GenBHad_svEip3d", GenBHad_svEip3d, &b_GenBHad_svEip3d);
   fChain->SetBranchAddress("GenBHad_svSip3d", GenBHad_svSip3d, &b_GenBHad_svSip3d);
   fChain->SetBranchAddress("GenBHad_svCosTheta", GenBHad_svCosTheta, &b_GenBHad_svCosTheta);
   fChain->SetBranchAddress("GenBHad_svMva", GenBHad_svMva, &b_GenBHad_svMva);
   fChain->SetBranchAddress("GenBHad_jetPt", GenBHad_jetPt, &b_GenBHad_jetPt);
   fChain->SetBranchAddress("GenBHad_jetBTagCSV", GenBHad_jetBTagCSV, &b_GenBHad_jetBTagCSV);
   fChain->SetBranchAddress("GenBHad_jetBTagCMVA", GenBHad_jetBTagCMVA, &b_GenBHad_jetBTagCMVA);
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("Jet_mcMatchFlav", Jet_mcMatchFlav, &b_Jet_mcMatchFlav);
   fChain->SetBranchAddress("Jet_charge", Jet_charge, &b_Jet_charge);
   fChain->SetBranchAddress("Jet_area", Jet_area, &b_Jet_area);
   fChain->SetBranchAddress("Jet_qgl", Jet_qgl, &b_Jet_qgl);
   fChain->SetBranchAddress("Jet_ptd", Jet_ptd, &b_Jet_ptd);
   fChain->SetBranchAddress("Jet_axis2", Jet_axis2, &b_Jet_axis2);
   fChain->SetBranchAddress("Jet_mult", Jet_mult, &b_Jet_mult);
   fChain->SetBranchAddress("Jet_partonId", Jet_partonId, &b_Jet_partonId);
   fChain->SetBranchAddress("Jet_partonMotherId", Jet_partonMotherId, &b_Jet_partonMotherId);
   fChain->SetBranchAddress("Jet_nLeptons", Jet_nLeptons, &b_Jet_nLeptons);
   fChain->SetBranchAddress("Jet_id", Jet_id, &b_Jet_id);
   fChain->SetBranchAddress("Jet_puId", Jet_puId, &b_Jet_puId);
   fChain->SetBranchAddress("Jet_btagCSV", Jet_btagCSV, &b_Jet_btagCSV);
   fChain->SetBranchAddress("Jet_btagCMVA", Jet_btagCMVA, &b_Jet_btagCMVA);
   fChain->SetBranchAddress("Jet_rawPt", Jet_rawPt, &b_Jet_rawPt);
   fChain->SetBranchAddress("Jet_mcPt", Jet_mcPt, &b_Jet_mcPt);
   fChain->SetBranchAddress("Jet_mcFlavour", Jet_mcFlavour, &b_Jet_mcFlavour);
   fChain->SetBranchAddress("Jet_mcMatchId", Jet_mcMatchId, &b_Jet_mcMatchId);
   fChain->SetBranchAddress("Jet_corr_JECUp", Jet_corr_JECUp, &b_Jet_corr_JECUp);
   fChain->SetBranchAddress("Jet_corr_JECDown", Jet_corr_JECDown, &b_Jet_corr_JECDown);
   fChain->SetBranchAddress("Jet_corr", Jet_corr, &b_Jet_corr);
   fChain->SetBranchAddress("Jet_px", Jet_px, &b_Jet_px);
   fChain->SetBranchAddress("Jet_py", Jet_py, &b_Jet_py);
   fChain->SetBranchAddress("Jet_pz", Jet_pz, &b_Jet_pz);
   fChain->SetBranchAddress("Jet_energy", Jet_energy, &b_Jet_energy);
   fChain->SetBranchAddress("Jet_mcPx", Jet_mcPx, &b_Jet_mcPx);
   fChain->SetBranchAddress("Jet_mcPy", Jet_mcPy, &b_Jet_mcPy);
   fChain->SetBranchAddress("Jet_mcPz", Jet_mcPz, &b_Jet_mcPz);
   fChain->SetBranchAddress("Jet_mcEnergy", Jet_mcEnergy, &b_Jet_mcEnergy);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_mass", Jet_mass, &b_Jet_mass);
   fChain->SetBranchAddress("Jet_prunedMass", Jet_prunedMass, &b_Jet_prunedMass);
   fChain->SetBranchAddress("Jet_mcNumPartons", Jet_mcNumPartons, &b_Jet_mcNumPartons);
   fChain->SetBranchAddress("Jet_mcNumLeptons", Jet_mcNumLeptons, &b_Jet_mcNumLeptons);
   fChain->SetBranchAddress("Jet_mcNumTaus", Jet_mcNumTaus, &b_Jet_mcNumTaus);
   fChain->SetBranchAddress("Jet_mcAnyPartonMass", Jet_mcAnyPartonMass, &b_Jet_mcAnyPartonMass);
   fChain->SetBranchAddress("Jet_nSubJets", Jet_nSubJets, &b_Jet_nSubJets);
   fChain->SetBranchAddress("Jet_nSubJets25", Jet_nSubJets25, &b_Jet_nSubJets25);
   fChain->SetBranchAddress("Jet_nSubJets30", Jet_nSubJets30, &b_Jet_nSubJets30);
   fChain->SetBranchAddress("Jet_nSubJets40", Jet_nSubJets40, &b_Jet_nSubJets40);
   fChain->SetBranchAddress("Jet_nSubJetsZ01", Jet_nSubJetsZ01, &b_Jet_nSubJetsZ01);
   fChain->SetBranchAddress("Jet_chHEF", Jet_chHEF, &b_Jet_chHEF);
   fChain->SetBranchAddress("Jet_neHEF", Jet_neHEF, &b_Jet_neHEF);
   fChain->SetBranchAddress("Jet_phEF", Jet_phEF, &b_Jet_phEF);
   fChain->SetBranchAddress("Jet_eEF", Jet_eEF, &b_Jet_eEF);
   fChain->SetBranchAddress("Jet_muEF", Jet_muEF, &b_Jet_muEF);
   fChain->SetBranchAddress("Jet_HFHEF", Jet_HFHEF, &b_Jet_HFHEF);
   fChain->SetBranchAddress("Jet_HFEMEF", Jet_HFEMEF, &b_Jet_HFEMEF);
   fChain->SetBranchAddress("Jet_chHMult", Jet_chHMult, &b_Jet_chHMult);
   fChain->SetBranchAddress("Jet_neHMult", Jet_neHMult, &b_Jet_neHMult);
   fChain->SetBranchAddress("Jet_phMult", Jet_phMult, &b_Jet_phMult);
   fChain->SetBranchAddress("Jet_eMult", Jet_eMult, &b_Jet_eMult);
   fChain->SetBranchAddress("Jet_muMult", Jet_muMult, &b_Jet_muMult);
   fChain->SetBranchAddress("Jet_HFHMult", Jet_HFHMult, &b_Jet_HFHMult);
   fChain->SetBranchAddress("Jet_HFEMMult", Jet_HFEMMult, &b_Jet_HFEMMult);
   fChain->SetBranchAddress("Jet_CorrFactor_L1", Jet_CorrFactor_L1, &b_Jet_CorrFactor_L1);
   fChain->SetBranchAddress("Jet_CorrFactor_L1L2", Jet_CorrFactor_L1L2, &b_Jet_CorrFactor_L1L2);
   fChain->SetBranchAddress("Jet_CorrFactor_L1L2L3", Jet_CorrFactor_L1L2L3, &b_Jet_CorrFactor_L1L2L3);
   fChain->SetBranchAddress("Jet_CorrFactor_L1L2L3Res", Jet_CorrFactor_L1L2L3Res, &b_Jet_CorrFactor_L1L2L3Res);
   fChain->SetBranchAddress("ngenLep", &ngenLep, &b_ngenLep);
   fChain->SetBranchAddress("genLep_motherId", genLep_motherId, &b_genLep_motherId);
   fChain->SetBranchAddress("genLep_grandmotherId", genLep_grandmotherId, &b_genLep_grandmotherId);
   fChain->SetBranchAddress("genLep_sourceId", genLep_sourceId, &b_genLep_sourceId);
   fChain->SetBranchAddress("genLep_charge", genLep_charge, &b_genLep_charge);
   fChain->SetBranchAddress("genLep_status", genLep_status, &b_genLep_status);
   fChain->SetBranchAddress("genLep_pdgId", genLep_pdgId, &b_genLep_pdgId);
   fChain->SetBranchAddress("genLep_pt", genLep_pt, &b_genLep_pt);
   fChain->SetBranchAddress("genLep_eta", genLep_eta, &b_genLep_eta);
   fChain->SetBranchAddress("genLep_phi", genLep_phi, &b_genLep_phi);
   fChain->SetBranchAddress("genLep_mass", genLep_mass, &b_genLep_mass);
   fChain->SetBranchAddress("genLep_motherIndex", genLep_motherIndex, &b_genLep_motherIndex);
   fChain->SetBranchAddress("nLHEweight", &nLHEweight, &b_nLHEweight);
   fChain->SetBranchAddress("LHEweight_id", LHEweight_id, &b_LHEweight_id);
   fChain->SetBranchAddress("LHEweight_wgt", LHEweight_wgt, &b_LHEweight_wgt);
   fChain->SetBranchAddress("nTauGood", &nTauGood, &b_nTauGood);
   fChain->SetBranchAddress("TauGood_charge", TauGood_charge, &b_TauGood_charge);
   fChain->SetBranchAddress("TauGood_decayMode", TauGood_decayMode, &b_TauGood_decayMode);
   fChain->SetBranchAddress("TauGood_idDecayMode", TauGood_idDecayMode, &b_TauGood_idDecayMode);
   fChain->SetBranchAddress("TauGood_idDecayModeNewDMs", TauGood_idDecayModeNewDMs, &b_TauGood_idDecayModeNewDMs);
   fChain->SetBranchAddress("TauGood_dxy", TauGood_dxy, &b_TauGood_dxy);
   fChain->SetBranchAddress("TauGood_dz", TauGood_dz, &b_TauGood_dz);
   fChain->SetBranchAddress("TauGood_idMVA", TauGood_idMVA, &b_TauGood_idMVA);
   fChain->SetBranchAddress("TauGood_idMVANewDM", TauGood_idMVANewDM, &b_TauGood_idMVANewDM);
   fChain->SetBranchAddress("TauGood_idCI3hit", TauGood_idCI3hit, &b_TauGood_idCI3hit);
   fChain->SetBranchAddress("TauGood_idAntiMu", TauGood_idAntiMu, &b_TauGood_idAntiMu);
   fChain->SetBranchAddress("TauGood_idAntiE", TauGood_idAntiE, &b_TauGood_idAntiE);
   fChain->SetBranchAddress("TauGood_isoCI3hit", TauGood_isoCI3hit, &b_TauGood_isoCI3hit);
   fChain->SetBranchAddress("TauGood_mcMatchId", TauGood_mcMatchId, &b_TauGood_mcMatchId);
   fChain->SetBranchAddress("TauGood_pdgId", TauGood_pdgId, &b_TauGood_pdgId);
   fChain->SetBranchAddress("TauGood_pt", TauGood_pt, &b_TauGood_pt);
   fChain->SetBranchAddress("TauGood_eta", TauGood_eta, &b_TauGood_eta);
   fChain->SetBranchAddress("TauGood_phi", TauGood_phi, &b_TauGood_phi);
   fChain->SetBranchAddress("TauGood_mass", TauGood_mass, &b_TauGood_mass);
   nentries = fChain->GetEntries();

   Notify();
}

Bool_t Data::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Data::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Data::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Data_cxx
