//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jul 30 11:40:45 2015 by ROOT version 5.34/02
// from TTree Tree/Tree
// found on file: /gpfs/csic_projects/tier3data/TreesDR74X/50ns/Tree_TbarW_0.root
//////////////////////////////////////////////////////////

#ifndef FIVEns_h
#define FIVEns_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.
using namespace std;


class FIVEns {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   Long64_t nentries;
   
   // Declaration of leaf types
   Int_t           T_Event_RunNumber;
   Int_t           T_Event_EventNumber;
   Int_t           T_Event_LuminosityBlock;
   Int_t           T_Event_processID;
   Float_t         T_Event_Rho;
   Float_t         T_Event_RhoFastJet;
   Int_t           T_Event_nPU;
   Int_t           T_Event_nPUm;
   Int_t           T_Event_nPUp;
   Float_t         T_Event_nTruePU;
   Float_t         T_Event_AveNTruePU;
   Bool_t          T_EventF_HBHENoiseFilter;
   Bool_t          T_EventF_CSCTightHaloFilter;
   Bool_t          T_EventF_hcalLaserEventFilter;
   Bool_t          T_EventF_EcalDeadCellTriggerPrimitiveFilter;
   Bool_t          T_EventF_goodVertices;
   Bool_t          T_EventF_trackingFailureFilter;
   Bool_t          T_EventF_eeBadScFilter;
   Bool_t          T_EventF_ecalLaserCorrFilter;
   Bool_t          T_EventF_trkPOGFilters;
   Bool_t          T_EventF_trkPOG_manystripclus53X;
   Bool_t          T_EventF_trkPOG_toomanystripclus53X;
   Bool_t          T_EventF_trkPOG_logErrorTooManyClusters;
   Bool_t          T_EventF_METFilters;
   vector<float>   *T_Gen_StopMass;
   vector<float>   *T_Gen_Chi0Mass;
   vector<float>   *T_Gen_CharginoMass;
   vector<int>     *T_Gen_PromptMuon_pdgId;
   vector<float>   *T_Gen_PromptMuon_Px;
   vector<float>   *T_Gen_PromptMuon_Py;
   vector<float>   *T_Gen_PromptMuon_Pz;
   vector<float>   *T_Gen_PromptMuon_Energy;
   vector<int>     *T_Gen_PromptMuon_MpdgId;
   vector<float>   *T_Gen_PromptMuon_MPx;
   vector<float>   *T_Gen_PromptMuon_MPy;
   vector<float>   *T_Gen_PromptMuon_MPz;
   vector<float>   *T_Gen_PromptMuon_MEnergy;
   vector<int>     *T_Gen_PromptMuon_MSt;
   vector<int>     *T_Gen_PromptElec_pdgId;
   vector<float>   *T_Gen_PromptElec_Px;
   vector<float>   *T_Gen_PromptElec_Py;
   vector<float>   *T_Gen_PromptElec_Pz;
   vector<float>   *T_Gen_PromptElec_Energy;
   vector<int>     *T_Gen_PromptElec_MpdgId;
   vector<float>   *T_Gen_PromptElec_MPx;
   vector<float>   *T_Gen_PromptElec_MPy;
   vector<float>   *T_Gen_PromptElec_MPz;
   vector<float>   *T_Gen_PromptElec_MEnergy;
   vector<int>     *T_Gen_PromptElec_MSt;
   vector<int>     *T_Gen_Promptb_pdgId;
   vector<float>   *T_Gen_Promptb_Px;
   vector<float>   *T_Gen_Promptb_Py;
   vector<float>   *T_Gen_Promptb_Pz;
   vector<float>   *T_Gen_Promptb_Energy;
   vector<int>     *T_Gen_Promptb_MpdgId;
   vector<float>   *T_Gen_Promptb_MPx;
   vector<float>   *T_Gen_Promptb_MPy;
   vector<float>   *T_Gen_Promptb_MPz;
   vector<float>   *T_Gen_Promptb_MEnergy;
   vector<int>     *T_Gen_Promptb_MSt;
   vector<int>     *T_Gen_Muon_pdgId;
   vector<float>   *T_Gen_Muon_Px;
   vector<float>   *T_Gen_Muon_Py;
   vector<float>   *T_Gen_Muon_Pz;
   vector<float>   *T_Gen_Muon_Energy;
   vector<int>     *T_Gen_Muon_MpdgId;
   vector<float>   *T_Gen_Muon_MPx;
   vector<float>   *T_Gen_Muon_MPy;
   vector<float>   *T_Gen_Muon_MPz;
   vector<float>   *T_Gen_Muon_MEnergy;
   vector<int>     *T_Gen_Muon_MSt;
   vector<int>     *T_Gen_FinalMuon_pdgId;
   vector<float>   *T_Gen_FinalMuon_Px;
   vector<float>   *T_Gen_FinalMuon_Py;
   vector<float>   *T_Gen_FinalMuon_Pz;
   vector<float>   *T_Gen_FinalMuon_Energy;
   vector<int>     *T_Gen_Elec_pdgId;
   vector<float>   *T_Gen_Elec_Px;
   vector<float>   *T_Gen_Elec_Py;
   vector<float>   *T_Gen_Elec_Pz;
   vector<float>   *T_Gen_Elec_Energy;
   vector<int>     *T_Gen_Elec_MpdgId;
   vector<float>   *T_Gen_Elec_MPx;
   vector<float>   *T_Gen_Elec_MPy;
   vector<float>   *T_Gen_Elec_MPz;
   vector<float>   *T_Gen_Elec_MEnergy;
   vector<int>     *T_Gen_Elec_MSt;
   vector<int>     *T_Gen_FinalElec_pdgId;
   vector<float>   *T_Gen_FinalElec_Px;
   vector<float>   *T_Gen_FinalElec_Py;
   vector<float>   *T_Gen_FinalElec_Pz;
   vector<float>   *T_Gen_FinalElec_Energy;
   vector<int>     *T_Gen_b_pdgId;
   vector<float>   *T_Gen_b_Px;
   vector<float>   *T_Gen_b_Py;
   vector<float>   *T_Gen_b_Pz;
   vector<float>   *T_Gen_b_Energy;
   vector<int>     *T_Gen_b_MpdgId;
   vector<float>   *T_Gen_b_MPx;
   vector<float>   *T_Gen_b_MPy;
   vector<float>   *T_Gen_b_MPz;
   vector<float>   *T_Gen_b_MEnergy;
   vector<int>     *T_Gen_b_MSt;
   vector<int>     *T_Gen_Stop_pdgId;
   vector<int>     *T_Gen_Stop_MpdgId;
   vector<float>   *T_Gen_Stop_energy;
   vector<float>   *T_Gen_Stop_pt;
   vector<float>   *T_Gen_Stop_eta;
   vector<float>   *T_Gen_Stop_phi;
   vector<int>     *T_Gen_Chi0_pdgId;
   vector<int>     *T_Gen_Chi0_MpdgId;
   vector<float>   *T_Gen_Chi0_energy;
   vector<float>   *T_Gen_Chi0_pt;
   vector<float>   *T_Gen_Chi0_eta;
   vector<float>   *T_Gen_Chi0_phi;
   vector<int>     *T_Gen_ChiPM_pdgId;
   vector<int>     *T_Gen_ChiPM_MpdgId;
   vector<float>   *T_Gen_ChiPM_energy;
   vector<float>   *T_Gen_ChiPM_pt;
   vector<float>   *T_Gen_ChiPM_eta;
   vector<float>   *T_Gen_ChiPM_phi;
   vector<int>     *T_Gen_t_pdgId;
   vector<int>     *T_Gen_t_MpdgId;
   vector<float>   *T_Gen_t_energy;
   vector<float>   *T_Gen_t_pt;
   vector<float>   *T_Gen_t_eta;
   vector<float>   *T_Gen_t_phi;
   vector<int>     *T_Gen_Nu_pdgId;
   vector<int>     *T_Gen_Nu_MpdgId;
   vector<float>   *T_Gen_Nu_energy;
   vector<float>   *T_Gen_Nu_pt;
   vector<float>   *T_Gen_Nu_eta;
   vector<float>   *T_Gen_Nu_phi;
   vector<int>     *T_Gen_Z_pdgId;
   vector<int>     *T_Gen_Z_MpdgId;
   vector<float>   *T_Gen_Z_energy;
   vector<float>   *T_Gen_Z_pt;
   vector<float>   *T_Gen_Z_eta;
   vector<float>   *T_Gen_Z_phi;
   vector<int>     *T_Gen_W_pdgId;
   vector<int>     *T_Gen_W_MpdgId;
   vector<float>   *T_Gen_W_energy;
   vector<float>   *T_Gen_W_pt;
   vector<float>   *T_Gen_W_eta;
   vector<float>   *T_Gen_W_phi;
   vector<int>     *T_Gen_PromptTau_pdgId;
   vector<float>   *T_Gen_PromptTau_Energy;
   vector<float>   *T_Gen_PromptTau_Px;
   vector<float>   *T_Gen_PromptTau_Py;
   vector<float>   *T_Gen_PromptTau_Pz;
   vector<int>     *T_Gen_PromptTau_MpdgId;
   vector<float>   *T_Gen_PromptTau_MEnergy;
   vector<float>   *T_Gen_PromptTau_MPx;
   vector<float>   *T_Gen_PromptTau_MPy;
   vector<float>   *T_Gen_PromptTau_MPz;
   vector<int>     *T_Gen_PromptTau_MSt;
   vector<bool>    *T_Gen_PromptTau_IsLepDec;
   vector<int>     *T_Gen_PromptTau_LepDec_pdgId;
   vector<float>   *T_Gen_PromptTau_LepDec_Px;
   vector<float>   *T_Gen_PromptTau_LepDec_Py;
   vector<float>   *T_Gen_PromptTau_LepDec_Pz;
   vector<float>   *T_Gen_PromptTau_LepDec_Energy;
   vector<int>     *T_Gen_Tau_pdgId;
   vector<float>   *T_Gen_Tau_Energy;
   vector<float>   *T_Gen_Tau_Px;
   vector<float>   *T_Gen_Tau_Py;
   vector<float>   *T_Gen_Tau_Pz;
   vector<int>     *T_Gen_Tau_MpdgId;
   vector<float>   *T_Gen_Tau_MEnergy;
   vector<float>   *T_Gen_Tau_MPx;
   vector<float>   *T_Gen_Tau_MPy;
   vector<float>   *T_Gen_Tau_MPz;
   vector<int>     *T_Gen_Tau_MSt;
   vector<bool>    *T_Gen_Tau_IsLepDec;
   vector<int>     *T_Gen_Tau_LepDec_pdgId;
   vector<float>   *T_Gen_Tau_LepDec_Px;
   vector<float>   *T_Gen_Tau_LepDec_Py;
   vector<float>   *T_Gen_Tau_LepDec_Pz;
   vector<float>   *T_Gen_Tau_LepDec_Energy;
   Float_t         T_Event_weight;
   vector<float>   *T_Vertex_x;
   vector<float>   *T_Vertex_y;
   vector<float>   *T_Vertex_z;
   vector<float>   *T_Vertex_Chi2Prob;
   vector<float>   *T_Vertex_ndof;
   vector<float>   *T_Vertex_rho;
   vector<bool>    *T_Vertex_isFake;
   vector<int>     *T_Vertex_tracksSize;
   vector<int>     *T_Vertex_nTracks;
   vector<bool>    *T_Vertex_isGood;
   vector<bool>    *T_Muon_IsTightMuon;
   vector<bool>    *T_Muon_IsMediumMuon;
   vector<bool>    *T_Muon_IsPFMuon;
   vector<bool>    *T_Muon_IsGlobalMuon;
   vector<bool>    *T_Muon_IsTrackerMuon;
   vector<bool>    *T_Muon_IsStandAloneMuon;
   vector<bool>    *T_Muon_IsTrackerMuonArbitrated;
   vector<bool>    *T_Muon_IsAllArbitrated;
   vector<bool>    *T_Muon_IsGMPTMuons;
   vector<bool>    *T_Muon_IsTMLastStationTight;
   vector<bool>    *T_Muon_IsTrackHighPurity;
   vector<float>   *T_Muon_Eta;
   vector<float>   *T_Muon_Px;
   vector<float>   *T_Muon_Py;
   vector<float>   *T_Muon_Pz;
   vector<float>   *T_Muon_Pt;
   vector<float>   *T_Muon_BestTrack_Px;
   vector<float>   *T_Muon_BestTrack_Py;
   vector<float>   *T_Muon_BestTrack_Pz;
   vector<float>   *T_Muon_BestTrack_Pt;
   vector<float>   *T_Muon_BestTrack_Phi;
   vector<float>   *T_Muon_BestTrack_vx;
   vector<float>   *T_Muon_BestTrack_vy;
   vector<float>   *T_Muon_BestTrack_vz;
   vector<float>   *T_Muon_deltaPt;
   vector<float>   *T_Muon_Energy;
   vector<int>     *T_Muon_Charge;
   vector<float>   *T_Muon_vz;
   vector<float>   *T_Muon_vy;
   vector<float>   *T_Muon_vx;
   vector<float>   *T_Muon_NormChi2GTrk;
   vector<float>   *T_Muon_Chi2InTrk;
   vector<float>   *T_Muon_StaTrkChi2LocalPos;
   vector<float>   *T_Muon_dofInTrk;
   vector<int>     *T_Muon_NValidHitsInTrk;
   vector<int>     *T_Muon_NValidPixelHitsInTrk;
   vector<float>   *T_Muon_ValidFractionInTrk;
   vector<int>     *T_Muon_NValidHitsSATrk;
   vector<int>     *T_Muon_NValidHitsGTrk;
   vector<int>     *T_Muon_NLayers;
   vector<int>     *T_Muon_InnerTrackFound;
   vector<int>     *T_Muon_NumOfMatchedStations;
   vector<float>   *T_Muon_SegmentCompatibility;
   vector<float>   *T_Muon_trkKink;
   vector<float>   *T_Muon_dxyGTrack;
   vector<float>   *T_Muon_dxyInTrack;
   vector<float>   *T_Muon_BestTrack_dxy;
   vector<float>   *T_Muon_IPwrtAveBSInTrack;
   vector<float>   *T_Muon_dzGTrack;
   vector<float>   *T_Muon_dzInTrack;
   vector<float>   *T_Muon_BestTrack_dz;
   vector<int>     *T_Muon_fromPV;
   vector<float>   *T_Muon_chargedHadronIsoR04;
   vector<float>   *T_Muon_neutralHadronIsoR04;
   vector<float>   *T_Muon_neutralIsoPFweightR04;
   vector<float>   *T_Muon_neutralIsoPUPPIR04;
   vector<float>   *T_Muon_photonIsoR04;
   vector<float>   *T_Muon_sumPUPtR04;
   vector<float>   *T_Muon_chargedParticleIsoR03;
   vector<float>   *T_Muon_chargedHadronIsoR03;
   vector<float>   *T_Muon_neutralHadronIsoR03;
   vector<float>   *T_Muon_neutralIsoPFweightR03;
   vector<float>   *T_Muon_neutralIsoPUPPIR03;
   vector<float>   *T_Muon_photonIsoR03;
   vector<float>   *T_Muon_sumPUPtR03;
   vector<float>   *T_Tau_Px;
   vector<float>   *T_Tau_Py;
   vector<float>   *T_Tau_Pz;
   vector<float>   *T_Tau_Energy;
   vector<int>     *T_Tau_Charge;
   vector<float>   *T_Elec_Eta;
   vector<float>   *T_Elec_IPwrtAveBS;
   vector<float>   *T_Elec_IPwrtPV;
   vector<float>   *T_Elec_dzwrtPV;
   vector<float>   *T_Elec_Px;
   vector<float>   *T_Elec_Py;
   vector<float>   *T_Elec_Pz;
   vector<float>   *T_Elec_Pt;
   vector<float>   *T_Elec_Energy;
   vector<int>     *T_Elec_Charge;
   vector<int>     *T_Elec_nBrems;
   vector<float>   *T_Elec_fBrem;
   vector<float>   *T_Elec_eSuperClusterOverP;
   vector<float>   *T_Elec_ecalEnergy;
   vector<float>   *T_Elec_dr03TkSumPt;
   vector<float>   *T_Elec_dr03EcalSumEt;
   vector<float>   *T_Elec_dr03HcalSumEt;
   vector<bool>    *T_Elec_isEB;
   vector<bool>    *T_Elec_isEE;
   vector<float>   *T_Elec_chargedHadronIso;
   vector<float>   *T_Elec_neutralHadronIso;
   vector<float>   *T_Elec_neutralIsoPFweight;
   vector<float>   *T_Elec_neutralIsoPUPPI;
   vector<float>   *T_Elec_photonIso;
   vector<float>   *T_Elec_puChargedHadronIso;
   vector<float>   *T_Elec_sumChargedHadronPt;
   vector<float>   *T_Elec_sumNeutralHadronEt;
   vector<float>   *T_Elec_sumPhotonEt;
   vector<float>   *T_Elec_sumPUPt;
   vector<bool>    *T_Elec_passConversionVeto;
   vector<bool>    *T_Elec_hasMatchedConversion;
   vector<float>   *T_Elec_sigmaIetaIeta;
   vector<float>   *T_Elec_sigmaIetaIetaFull5by5;
   vector<float>   *T_Elec_deltaPhiIn;
   vector<float>   *T_Elec_deltaEtaIn;
   vector<bool>    *T_Elec_isEcalDriven;
   vector<float>   *T_Elec_HtoE;
   vector<float>   *T_Elec_vz;
   vector<float>   *T_Elec_vy;
   vector<float>   *T_Elec_vx;
   vector<int>     *T_Elec_nLost;
   vector<int>     *T_Elec_nHits;
   vector<float>   *T_Elec_SC_Et;
   vector<float>   *T_Elec_SC_Eta;
   vector<float>   *T_Elec_PFElecPt;
   vector<float>   *T_Elec_PFElecPx;
   vector<float>   *T_Elec_PFElecPy;
   vector<float>   *T_Elec_PFElecPz;
   vector<float>   *T_Elec_PFElecE;
   vector<bool>    *T_Elec_isPF;
   vector<float>   *T_Elec_MVAoutput;
   vector<float>   *T_JetAKCHS_Px;
   vector<float>   *T_JetAKCHS_Py;
   vector<float>   *T_JetAKCHS_Pz;
   vector<float>   *T_JetAKCHS_Et;
   vector<float>   *T_JetAKCHS_Eta;
   vector<float>   *T_JetAKCHS_Energy;
   vector<float>   *T_JetAKCHS_Corr;
   vector<float>   *T_JetAKCHS_Tag_HighEffTC;
   vector<float>   *T_JetAKCHS_Tag_CombInclusiveSVtxV2;
   vector<float>   *T_JetAKCHS_Tag_CombMVA;
   vector<float>   *T_JetAKCHS_Tag_CombSVtx;
   vector<float>   *T_JetAKCHS_Tag_pfCombinedSVtx;
   vector<float>   *T_JetAKCHS_Tag_JetBProb;
   vector<float>   *T_JetAKCHS_Tag_JetProb;
   vector<float>   *T_JetAKCHS_Tag_HighEffSimpSVtx;
   vector<float>   *T_JetAKCHS_Tag_HighPurSimpSVtx;
   vector<float>   *T_JetAKCHS_Tag_HighPurTC;
   vector<float>   *T_JetAKCHS_Parton_Px;
   vector<float>   *T_JetAKCHS_Parton_Py;
   vector<float>   *T_JetAKCHS_Parton_Pz;
   vector<float>   *T_JetAKCHS_Parton_Energy;
   vector<int>     *T_JetAKCHS_Parton_Flavour;
   vector<float>   *T_JetAKCHS_Uncertainty;
   vector<float>   *T_JetAKCHS_PileupPt;
   vector<float>   *T_JetAKCHS_MPFInSitu;
   vector<float>   *T_JetAKCHS_bJES;
   vector<float>   *T_JetAKCHS_Flavor;
   vector<float>   *T_JetAKCHS_Intercalibration;
   vector<float>   *T_JetAKCHS_Uncorrelated;
   vector<float>   *T_JetAKCHS_MuonEnergyFrac;
   vector<float>   *T_JetAKCHS_CharHadEnergyFrac;
   vector<float>   *T_JetAKCHS_NeutHadEnergyFrac;
   vector<float>   *T_JetAKCHS_CharEmEnergyFrac;
   vector<float>   *T_JetAKCHS_NeutEmEnergyFrac;
   vector<float>   *T_JetAKCHS_CharHadEnergy;
   vector<float>   *T_JetAKCHS_NeutHadEnergy;
   vector<float>   *T_JetAKCHS_CharEmEnergy;
   vector<float>   *T_JetAKCHS_NeutEmEnergy;
   vector<int>     *T_JetAKCHS_MuonMultiplicity;
   vector<int>     *T_JetAKCHS_NeutralMultiplicity;
   vector<int>     *T_JetAKCHS_ChargedMultiplicity;
   vector<int>     *T_JetAKCHS_nDaughters;
   vector<bool>    *T_JetAKCHS_IDLoose;
   vector<float>   *T_JetAKCHS_GenJet_InvisibleE;
   vector<float>   *T_JetAKCHS_GenJet_Px;
   vector<float>   *T_JetAKCHS_GenJet_Py;
   vector<float>   *T_JetAKCHS_GenJet_Pz;
   vector<float>   *T_JetAKCHS_GenJet_Et;
   vector<float>   *T_JetAKCHS_GenJet_Eta;
   vector<float>   *T_JetAKCHS_GenJet_Energy;
   vector<bool>    *T_JetAKCHS_IsGenJet;
   Float_t         T_MET_Significance;
   Float_t         T_MET_ET;
   Float_t         T_MET_ET_JetEnUp;
   Float_t         T_MET_ET_JetEnDown;
   Float_t         T_MET_ET_JetResUp;
   Float_t         T_MET_ET_JetResDown;
   Float_t         T_MET_ET_MuonEnUp;
   Float_t         T_MET_ET_MuonEnDown;
   Float_t         T_MET_ET_ElectronEnUp;
   Float_t         T_MET_ET_ElectronEnDown;
   Float_t         T_MET_ET_TauEnUp;
   Float_t         T_MET_ET_TauEnDown;
   Float_t         T_MET_ET_UnclusteredEnUp;
   Float_t         T_MET_ET_UnclusteredEnDown;
   Float_t         T_MET_Phi;
   Float_t         T_MET_Phi_JetEnUp;
   Float_t         T_MET_Phi_JetEnDown;
   Float_t         T_MET_Phi_JetResUp;
   Float_t         T_MET_Phi_JetResDown;
   Float_t         T_MET_Phi_MuonEnUp;
   Float_t         T_MET_Phi_MuonEnDown;
   Float_t         T_MET_Phi_ElectronEnUp;
   Float_t         T_MET_Phi_ElectronEnDown;
   Float_t         T_MET_Phi_TauEnUp;
   Float_t         T_MET_Phi_TauEnDown;
   Float_t         T_MET_Phi_UnclusteredEnUp;
   Float_t         T_MET_Phi_UnclusteredEnDown;
   Float_t         T_METgen_ET;
   Float_t         T_METgen_Phi;
   Bool_t          T_passTriggerDoubleMu;
   Bool_t          T_passTriggerDoubleEl;
   Bool_t          T_passTriggerSingleMu;
   Bool_t          T_passTriggerSingleEl;
   Bool_t          T_passTriggerElMu;

   // List of branches
   TBranch        *b_T_Event_RunNumber;   //!
   TBranch        *b_T_Event_EventNumber;   //!
   TBranch        *b_T_Event_LuminosityBlock;   //!
   TBranch        *b_T_Event_processID;   //!
   TBranch        *b_T_Event_Rho;   //!
   TBranch        *b_T_Event_RhoFastJet;   //!
   TBranch        *b_T_Event_nPU;   //!
   TBranch        *b_T_Event_nPUm;   //!
   TBranch        *b_T_Event_nPUp;   //!
   TBranch        *b_T_Event_nTruePU;   //!
   TBranch        *b_T_Event_AveNTruePU;   //!
   TBranch        *b_T_EventF_HBHENoiseFilter;   //!
   TBranch        *b_T_EventF_CSCTightHaloFilter;   //!
   TBranch        *b_T_EventF_hcalLaserEventFilter;   //!
   TBranch        *b_T_EventF_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_T_EventF_goodVertices;   //!
   TBranch        *b_T_EventF_trackingFailureFilter;   //!
   TBranch        *b_T_EventF_eeBadScFilter;   //!
   TBranch        *b_T_EventF_ecalLaserCorrFilter;   //!
   TBranch        *b_T_EventF_trkPOGFilters;   //!
   TBranch        *b_T_EventF_trkPOG_manystripclus53X;   //!
   TBranch        *b_T_EventF_trkPOG_toomanystripclus53X;   //!
   TBranch        *b_T_EventF_trkPOG_logErrorTooManyClusters;   //!
   TBranch        *b_T_EventF_METFilters;   //!
   TBranch        *b_T_Gen_StopMass;   //!
   TBranch        *b_T_Gen_Chi0Mass;   //!
   TBranch        *b_T_Gen_CharginoMass;   //!
   TBranch        *b_T_Gen_PromptMuon_pdgId;   //!
   TBranch        *b_T_Gen_PromptMuon_Px;   //!
   TBranch        *b_T_Gen_PromptMuon_Py;   //!
   TBranch        *b_T_Gen_PromptMuon_Pz;   //!
   TBranch        *b_T_Gen_PromptMuon_Energy;   //!
   TBranch        *b_T_Gen_PromptMuon_MpdgId;   //!
   TBranch        *b_T_Gen_PromptMuon_MPx;   //!
   TBranch        *b_T_Gen_PromptMuon_MPy;   //!
   TBranch        *b_T_Gen_PromptMuon_MPz;   //!
   TBranch        *b_T_Gen_PromptMuon_MEnergy;   //!
   TBranch        *b_T_Gen_PromptMuon_MSt;   //!
   TBranch        *b_T_Gen_PromptElec_pdgId;   //!
   TBranch        *b_T_Gen_PromptElec_Px;   //!
   TBranch        *b_T_Gen_PromptElec_Py;   //!
   TBranch        *b_T_Gen_PromptElec_Pz;   //!
   TBranch        *b_T_Gen_PromptElec_Energy;   //!
   TBranch        *b_T_Gen_PromptElec_MpdgId;   //!
   TBranch        *b_T_Gen_PromptElec_MPx;   //!
   TBranch        *b_T_Gen_PromptElec_MPy;   //!
   TBranch        *b_T_Gen_PromptElec_MPz;   //!
   TBranch        *b_T_Gen_PromptElec_MEnergy;   //!
   TBranch        *b_T_Gen_PromptElec_MSt;   //!
   TBranch        *b_T_Gen_Promptb_pdgId;   //!
   TBranch        *b_T_Gen_Promptb_Px;   //!
   TBranch        *b_T_Gen_Promptb_Py;   //!
   TBranch        *b_T_Gen_Promptb_Pz;   //!
   TBranch        *b_T_Gen_Promptb_Energy;   //!
   TBranch        *b_T_Gen_Promptb_MpdgId;   //!
   TBranch        *b_T_Gen_Promptb_MPx;   //!
   TBranch        *b_T_Gen_Promptb_MPy;   //!
   TBranch        *b_T_Gen_Promptb_MPz;   //!
   TBranch        *b_T_Gen_Promptb_MEnergy;   //!
   TBranch        *b_T_Gen_Promptb_MSt;   //!
   TBranch        *b_T_Gen_Muon_pdgId;   //!
   TBranch        *b_T_Gen_Muon_Px;   //!
   TBranch        *b_T_Gen_Muon_Py;   //!
   TBranch        *b_T_Gen_Muon_Pz;   //!
   TBranch        *b_T_Gen_Muon_Energy;   //!
   TBranch        *b_T_Gen_Muon_MpdgId;   //!
   TBranch        *b_T_Gen_Muon_MPx;   //!
   TBranch        *b_T_Gen_Muon_MPy;   //!
   TBranch        *b_T_Gen_Muon_MPz;   //!
   TBranch        *b_T_Gen_Muon_MEnergy;   //!
   TBranch        *b_T_Gen_Muon_MSt;   //!
   TBranch        *b_T_Gen_FinalMuon_pdgId;   //!
   TBranch        *b_T_Gen_FinalMuon_Px;   //!
   TBranch        *b_T_Gen_FinalMuon_Py;   //!
   TBranch        *b_T_Gen_FinalMuon_Pz;   //!
   TBranch        *b_T_Gen_FinalMuon_Energy;   //!
   TBranch        *b_T_Gen_Elec_pdgId;   //!
   TBranch        *b_T_Gen_Elec_Px;   //!
   TBranch        *b_T_Gen_Elec_Py;   //!
   TBranch        *b_T_Gen_Elec_Pz;   //!
   TBranch        *b_T_Gen_Elec_Energy;   //!
   TBranch        *b_T_Gen_Elec_MpdgId;   //!
   TBranch        *b_T_Gen_Elec_MPx;   //!
   TBranch        *b_T_Gen_Elec_MPy;   //!
   TBranch        *b_T_Gen_Elec_MPz;   //!
   TBranch        *b_T_Gen_Elec_MEnergy;   //!
   TBranch        *b_T_Gen_Elec_MSt;   //!
   TBranch        *b_T_Gen_FinalElec_pdgId;   //!
   TBranch        *b_T_Gen_FinalElec_Px;   //!
   TBranch        *b_T_Gen_FinalElec_Py;   //!
   TBranch        *b_T_Gen_FinalElec_Pz;   //!
   TBranch        *b_T_Gen_FinalElec_Energy;   //!
   TBranch        *b_T_Gen_b_pdgId;   //!
   TBranch        *b_T_Gen_b_Px;   //!
   TBranch        *b_T_Gen_b_Py;   //!
   TBranch        *b_T_Gen_b_Pz;   //!
   TBranch        *b_T_Gen_b_Energy;   //!
   TBranch        *b_T_Gen_b_MpdgId;   //!
   TBranch        *b_T_Gen_b_MPx;   //!
   TBranch        *b_T_Gen_b_MPy;   //!
   TBranch        *b_T_Gen_b_MPz;   //!
   TBranch        *b_T_Gen_b_MEnergy;   //!
   TBranch        *b_T_Gen_b_MSt;   //!
   TBranch        *b_T_Gen_Stop_pdgId;   //!
   TBranch        *b_T_Gen_Stop_MpdgId;   //!
   TBranch        *b_T_Gen_Stop_energy;   //!
   TBranch        *b_T_Gen_Stop_pt;   //!
   TBranch        *b_T_Gen_Stop_eta;   //!
   TBranch        *b_T_Gen_Stop_phi;   //!
   TBranch        *b_T_Gen_Chi0_pdgId;   //!
   TBranch        *b_T_Gen_Chi0_MpdgId;   //!
   TBranch        *b_T_Gen_Chi0_energy;   //!
   TBranch        *b_T_Gen_Chi0_pt;   //!
   TBranch        *b_T_Gen_Chi0_eta;   //!
   TBranch        *b_T_Gen_Chi0_phi;   //!
   TBranch        *b_T_Gen_ChiPM_pdgId;   //!
   TBranch        *b_T_Gen_ChiPM_MpdgId;   //!
   TBranch        *b_T_Gen_ChiPM_energy;   //!
   TBranch        *b_T_Gen_ChiPM_pt;   //!
   TBranch        *b_T_Gen_ChiPM_eta;   //!
   TBranch        *b_T_Gen_ChiPM_phi;   //!
   TBranch        *b_T_Gen_t_pdgId;   //!
   TBranch        *b_T_Gen_t_MpdgId;   //!
   TBranch        *b_T_Gen_t_energy;   //!
   TBranch        *b_T_Gen_t_pt;   //!
   TBranch        *b_T_Gen_t_eta;   //!
   TBranch        *b_T_Gen_t_phi;   //!
   TBranch        *b_T_Gen_Nu_pdgId;   //!
   TBranch        *b_T_Gen_Nu_MpdgId;   //!
   TBranch        *b_T_Gen_Nu_energy;   //!
   TBranch        *b_T_Gen_Nu_pt;   //!
   TBranch        *b_T_Gen_Nu_eta;   //!
   TBranch        *b_T_Gen_Nu_phi;   //!
   TBranch        *b_T_Gen_Z_pdgId;   //!
   TBranch        *b_T_Gen_Z_MpdgId;   //!
   TBranch        *b_T_Gen_Z_energy;   //!
   TBranch        *b_T_Gen_Z_pt;   //!
   TBranch        *b_T_Gen_Z_eta;   //!
   TBranch        *b_T_Gen_Z_phi;   //!
   TBranch        *b_T_Gen_W_pdgId;   //!
   TBranch        *b_T_Gen_W_MpdgId;   //!
   TBranch        *b_T_Gen_W_energy;   //!
   TBranch        *b_T_Gen_W_pt;   //!
   TBranch        *b_T_Gen_W_eta;   //!
   TBranch        *b_T_Gen_W_phi;   //!
   TBranch        *b_T_Gen_PromptTau_pdgId;   //!
   TBranch        *b_T_Gen_PromptTau_Energy;   //!
   TBranch        *b_T_Gen_PromptTau_Px;   //!
   TBranch        *b_T_Gen_PromptTau_Py;   //!
   TBranch        *b_T_Gen_PromptTau_Pz;   //!
   TBranch        *b_T_Gen_PromptTau_MpdgId;   //!
   TBranch        *b_T_Gen_PromptTau_MEnergy;   //!
   TBranch        *b_T_Gen_PromptTau_MPx;   //!
   TBranch        *b_T_Gen_PromptTau_MPy;   //!
   TBranch        *b_T_Gen_PromptTau_MPz;   //!
   TBranch        *b_T_Gen_PromptTau_MSt;   //!
   TBranch        *b_T_Gen_PromptTau_IsLepDec;   //!
   TBranch        *b_T_Gen_PromptTau_LepDec_pdgId;   //!
   TBranch        *b_T_Gen_PromptTau_LepDec_Px;   //!
   TBranch        *b_T_Gen_PromptTau_LepDec_Py;   //!
   TBranch        *b_T_Gen_PromptTau_LepDec_Pz;   //!
   TBranch        *b_T_Gen_PromptTau_LepDec_Energy;   //!
   TBranch        *b_T_Gen_Tau_pdgId;   //!
   TBranch        *b_T_Gen_Tau_Energy;   //!
   TBranch        *b_T_Gen_Tau_Px;   //!
   TBranch        *b_T_Gen_Tau_Py;   //!
   TBranch        *b_T_Gen_Tau_Pz;   //!
   TBranch        *b_T_Gen_Tau_MpdgId;   //!
   TBranch        *b_T_Gen_Tau_MEnergy;   //!
   TBranch        *b_T_Gen_Tau_MPx;   //!
   TBranch        *b_T_Gen_Tau_MPy;   //!
   TBranch        *b_T_Gen_Tau_MPz;   //!
   TBranch        *b_T_Gen_Tau_MSt;   //!
   TBranch        *b_T_Gen_Tau_IsLepDec;   //!
   TBranch        *b_T_Gen_Tau_LepDec_pdgId;   //!
   TBranch        *b_T_Gen_Tau_LepDec_Px;   //!
   TBranch        *b_T_Gen_Tau_LepDec_Py;   //!
   TBranch        *b_T_Gen_Tau_LepDec_Pz;   //!
   TBranch        *b_T_Gen_Tau_LepDec_Energy;   //!
   TBranch        *b_T_Event_weight;   //!
   TBranch        *b_T_Vertex_x;   //!
   TBranch        *b_T_Vertex_y;   //!
   TBranch        *b_T_Vertex_z;   //!
   TBranch        *b_T_Vertex_Chi2Prob;   //!
   TBranch        *b_T_Vertex_ndof;   //!
   TBranch        *b_T_Vertex_rho;   //!
   TBranch        *b_T_Vertex_isFake;   //!
   TBranch        *b_T_Vertex_tracksSize;   //!
   TBranch        *b_T_Vertex_nTracks;   //!
   TBranch        *b_T_Vertex_isGood;   //!
   TBranch        *b_T_Muon_IsTightMuon;   //!
   TBranch        *b_T_Muon_IsMediumMuon;   //!
   TBranch        *b_T_Muon_IsPFMuon;   //!
   TBranch        *b_T_Muon_IsGlobalMuon;   //!
   TBranch        *b_T_Muon_IsTrackerMuon;   //!
   TBranch        *b_T_Muon_IsStandAloneMuon;   //!
   TBranch        *b_T_Muon_IsTrackerMuonArbitrated;   //!
   TBranch        *b_T_Muon_IsAllArbitrated;   //!
   TBranch        *b_T_Muon_IsGMPTMuons;   //!
   TBranch        *b_T_Muon_IsTMLastStationTight;   //!
   TBranch        *b_T_Muon_IsTrackHighPurity;   //!
   TBranch        *b_T_Muon_Eta;   //!
   TBranch        *b_T_Muon_Px;   //!
   TBranch        *b_T_Muon_Py;   //!
   TBranch        *b_T_Muon_Pz;   //!
   TBranch        *b_T_Muon_Pt;   //!
   TBranch        *b_T_Muon_BestTrack_Px;   //!
   TBranch        *b_T_Muon_BestTrack_Py;   //!
   TBranch        *b_T_Muon_BestTrack_Pz;   //!
   TBranch        *b_T_Muon_BestTrack_Pt;   //!
   TBranch        *b_T_Muon_BestTrack_Phi;   //!
   TBranch        *b_T_Muon_BestTrack_vx;   //!
   TBranch        *b_T_Muon_BestTrack_vy;   //!
   TBranch        *b_T_Muon_BestTrack_vz;   //!
   TBranch        *b_T_Muon_deltaPt;   //!
   TBranch        *b_T_Muon_Energy;   //!
   TBranch        *b_T_Muon_Charge;   //!
   TBranch        *b_T_Muon_vz;   //!
   TBranch        *b_T_Muon_vy;   //!
   TBranch        *b_T_Muon_vx;   //!
   TBranch        *b_T_Muon_NormChi2GTrk;   //!
   TBranch        *b_T_Muon_Chi2InTrk;   //!
   TBranch        *b_T_Muon_StaTrkChi2LocalPos;   //!
   TBranch        *b_T_Muon_dofInTrk;   //!
   TBranch        *b_T_Muon_NValidHitsInTrk;   //!
   TBranch        *b_T_Muon_NValidPixelHitsInTrk;   //!
   TBranch        *b_T_Muon_ValidFractionInTrk;   //!
   TBranch        *b_T_Muon_NValidHitsSATrk;   //!
   TBranch        *b_T_Muon_NValidHitsGTrk;   //!
   TBranch        *b_T_Muon_NLayers;   //!
   TBranch        *b_T_Muon_InnerTrackFound;   //!
   TBranch        *b_T_Muon_NumOfMatchedStations;   //!
   TBranch        *b_T_Muon_SegmentCompatibility;   //!
   TBranch        *b_T_Muon_trkKink;   //!
   TBranch        *b_T_Muon_dxyGTrack;   //!
   TBranch        *b_T_Muon_dxyInTrack;   //!
   TBranch        *b_T_Muon_BestTrack_dxy;   //!
   TBranch        *b_T_Muon_IPwrtAveBSInTrack;   //!
   TBranch        *b_T_Muon_dzGTrack;   //!
   TBranch        *b_T_Muon_dzInTrack;   //!
   TBranch        *b_T_Muon_BestTrack_dz;   //!
   TBranch        *b_T_Muon_fromPV;   //!
   TBranch        *b_T_Muon_chargedHadronIsoR04;   //!
   TBranch        *b_T_Muon_neutralHadronIsoR04;   //!
   TBranch        *b_T_Muon_neutralIsoPFweightR04;   //!
   TBranch        *b_T_Muon_neutralIsoPUPPIR04;   //!
   TBranch        *b_T_Muon_photonIsoR04;   //!
   TBranch        *b_T_Muon_sumPUPtR04;   //!
   TBranch        *b_T_Muon_chargedParticleIsoR03;   //!
   TBranch        *b_T_Muon_chargedHadronIsoR03;   //!
   TBranch        *b_T_Muon_neutralHadronIsoR03;   //!
   TBranch        *b_T_Muon_neutralIsoPFweightR03;   //!
   TBranch        *b_T_Muon_neutralIsoPUPPIR03;   //!
   TBranch        *b_T_Muon_photonIsoR03;   //!
   TBranch        *b_T_Muon_sumPUPtR03;   //!
   TBranch        *b_T_Tau_Px;   //!
   TBranch        *b_T_Tau_Py;   //!
   TBranch        *b_T_Tau_Pz;   //!
   TBranch        *b_T_Tau_Energy;   //!
   TBranch        *b_T_Tau_Charge;   //!
   TBranch        *b_T_Elec_Eta;   //!
   TBranch        *b_T_Elec_IPwrtAveBS;   //!
   TBranch        *b_T_Elec_IPwrtPV;   //!
   TBranch        *b_T_Elec_dzwrtPV;   //!
   TBranch        *b_T_Elec_Px;   //!
   TBranch        *b_T_Elec_Py;   //!
   TBranch        *b_T_Elec_Pz;   //!
   TBranch        *b_T_Elec_Pt;   //!
   TBranch        *b_T_Elec_Energy;   //!
   TBranch        *b_T_Elec_Charge;   //!
   TBranch        *b_T_Elec_nBrems;   //!
   TBranch        *b_T_Elec_fBrem;   //!
   TBranch        *b_T_Elec_eSuperClusterOverP;   //!
   TBranch        *b_T_Elec_ecalEnergy;   //!
   TBranch        *b_T_Elec_dr03TkSumPt;   //!
   TBranch        *b_T_Elec_dr03EcalSumEt;   //!
   TBranch        *b_T_Elec_dr03HcalSumEt;   //!
   TBranch        *b_T_Elec_isEB;   //!
   TBranch        *b_T_Elec_isEE;   //!
   TBranch        *b_T_Elec_chargedHadronIso;   //!
   TBranch        *b_T_Elec_neutralHadronIso;   //!
   TBranch        *b_T_Elec_neutralIsoPFweight;   //!
   TBranch        *b_T_Elec_neutralIsoPUPPI;   //!
   TBranch        *b_T_Elec_photonIso;   //!
   TBranch        *b_T_Elec_puChargedHadronIso;   //!
   TBranch        *b_T_Elec_sumChargedHadronPt;   //!
   TBranch        *b_T_Elec_sumNeutralHadronEt;   //!
   TBranch        *b_T_Elec_sumPhotonEt;   //!
   TBranch        *b_T_Elec_sumPUPt;   //!
   TBranch        *b_T_Elec_passConversionVeto;   //!
   TBranch        *b_T_Elec_hasMatchedConversion;   //!
   TBranch        *b_T_Elec_sigmaIetaIeta;   //!
   TBranch        *b_T_Elec_sigmaIetaIetaFull5by5;   //!
   TBranch        *b_T_Elec_deltaPhiIn;   //!
   TBranch        *b_T_Elec_deltaEtaIn;   //!
   TBranch        *b_T_Elec_isEcalDriven;   //!
   TBranch        *b_T_Elec_HtoE;   //!
   TBranch        *b_T_Elec_vz;   //!
   TBranch        *b_T_Elec_vy;   //!
   TBranch        *b_T_Elec_vx;   //!
   TBranch        *b_T_Elec_nLost;   //!
   TBranch        *b_T_Elec_nHits;   //!
   TBranch        *b_T_Elec_SC_Et;   //!
   TBranch        *b_T_Elec_SC_Eta;   //!
   TBranch        *b_T_Elec_PFElecPt;   //!
   TBranch        *b_T_Elec_PFElecPx;   //!
   TBranch        *b_T_Elec_PFElecPy;   //!
   TBranch        *b_T_Elec_PFElecPz;   //!
   TBranch        *b_T_Elec_PFElecE;   //!
   TBranch        *b_T_Elec_isPF;   //!
   TBranch        *b_T_Elec_MVAoutput;   //!
   TBranch        *b_T_JetAKCHS_Px;   //!
   TBranch        *b_T_JetAKCHS_Py;   //!
   TBranch        *b_T_JetAKCHS_Pz;   //!
   TBranch        *b_T_JetAKCHS_Et;   //!
   TBranch        *b_T_JetAKCHS_Eta;   //!
   TBranch        *b_T_JetAKCHS_Energy;   //!
   TBranch        *b_T_JetAKCHS_Corr;   //!
   TBranch        *b_T_JetAKCHS_Tag_HighEffTC;   //!
   TBranch        *b_T_JetAKCHS_Tag_CombInclusiveSVtxV2;   //!
   TBranch        *b_T_JetAKCHS_Tag_CombMVA;   //!
   TBranch        *b_T_JetAKCHS_Tag_CombSVtx;   //!
   TBranch        *b_T_JetAKCHS_Tag_pfCombinedSVtx;   //!
   TBranch        *b_T_JetAKCHS_Tag_JetBProb;   //!
   TBranch        *b_T_JetAKCHS_Tag_JetProb;   //!
   TBranch        *b_T_JetAKCHS_Tag_HighEffSimpSVtx;   //!
   TBranch        *b_T_JetAKCHS_Tag_HighPurSimpSVtx;   //!
   TBranch        *b_T_JetAKCHS_Tag_HighPurTC;   //!
   TBranch        *b_T_JetAKCHS_Parton_Px;   //!
   TBranch        *b_T_JetAKCHS_Parton_Py;   //!
   TBranch        *b_T_JetAKCHS_Parton_Pz;   //!
   TBranch        *b_T_JetAKCHS_Parton_Energy;   //!
   TBranch        *b_T_JetAKCHS_Parton_Flavour;   //!
   TBranch        *b_T_JetAKCHS_Uncertainty;   //!
   TBranch        *b_T_JetAKCHS_PileupPt;   //!
   TBranch        *b_T_JetAKCHS_MPFInSitu;   //!
   TBranch        *b_T_JetAKCHS_bJES;   //!
   TBranch        *b_T_JetAKCHS_Flavor;   //!
   TBranch        *b_T_JetAKCHS_Intercalibration;   //!
   TBranch        *b_T_JetAKCHS_Uncorrelated;   //!
   TBranch        *b_T_JetAKCHS_MuonEnergyFrac;   //!
   TBranch        *b_T_JetAKCHS_CharHadEnergyFrac;   //!
   TBranch        *b_T_JetAKCHS_NeutHadEnergyFrac;   //!
   TBranch        *b_T_JetAKCHS_CharEmEnergyFrac;   //!
   TBranch        *b_T_JetAKCHS_NeutEmEnergyFrac;   //!
   TBranch        *b_T_JetAKCHS_CharHadEnergy;   //!
   TBranch        *b_T_JetAKCHS_NeutHadEnergy;   //!
   TBranch        *b_T_JetAKCHS_CharEmEnergy;   //!
   TBranch        *b_T_JetAKCHS_NeutEmEnergy;   //!
   TBranch        *b_T_JetAKCHS_MuonMultiplicity;   //!
   TBranch        *b_T_JetAKCHS_NeutralMultiplicity;   //!
   TBranch        *b_T_JetAKCHS_ChargedMultiplicity;   //!
   TBranch        *b_T_JetAKCHS_nDaughters;   //!
   TBranch        *b_T_JetAKCHS_IDLoose;   //!
   TBranch        *b_T_JetAKCHS_GenJet_InvisibleE;   //!
   TBranch        *b_T_JetAKCHS_GenJet_Px;   //!
   TBranch        *b_T_JetAKCHS_GenJet_Py;   //!
   TBranch        *b_T_JetAKCHS_GenJet_Pz;   //!
   TBranch        *b_T_JetAKCHS_GenJet_Et;   //!
   TBranch        *b_T_JetAKCHS_GenJet_Eta;   //!
   TBranch        *b_T_JetAKCHS_GenJet_Energy;   //!
   TBranch        *b_T_JetAKCHS_IsGenJet;   //!
   TBranch        *b_T_MET_Significance;   //!
   TBranch        *b_T_MET_ET;   //!
   TBranch        *b_T_MET_ET_JetEnUp;   //!
   TBranch        *b_T_MET_ET_JetEnDown;   //!
   TBranch        *b_T_MET_ET_JetResUp;   //!
   TBranch        *b_T_MET_ET_JetResDown;   //!
   TBranch        *b_T_MET_ET_MuonEnUp;   //!
   TBranch        *b_T_MET_ET_MuonEnDown;   //!
   TBranch        *b_T_MET_ET_ElectronEnUp;   //!
   TBranch        *b_T_MET_ET_ElectronEnDown;   //!
   TBranch        *b_T_MET_ET_TauEnUp;   //!
   TBranch        *b_T_MET_ET_TauEnDown;   //!
   TBranch        *b_T_MET_ET_UnclusteredEnUp;   //!
   TBranch        *b_T_MET_ET_UnclusteredEnDown;   //!
   TBranch        *b_T_MET_Phi;   //!
   TBranch        *b_T_MET_Phi_JetEnUp;   //!
   TBranch        *b_T_MET_Phi_JetEnDown;   //!
   TBranch        *b_T_MET_Phi_JetResUp;   //!
   TBranch        *b_T_MET_Phi_JetResDown;   //!
   TBranch        *b_T_MET_Phi_MuonEnUp;   //!
   TBranch        *b_T_MET_Phi_MuonEnDown;   //!
   TBranch        *b_T_MET_Phi_ElectronEnUp;   //!
   TBranch        *b_T_MET_Phi_ElectronEnDown;   //!
   TBranch        *b_T_MET_Phi_TauEnUp;   //!
   TBranch        *b_T_MET_Phi_TauEnDown;   //!
   TBranch        *b_T_MET_Phi_UnclusteredEnUp;   //!
   TBranch        *b_T_MET_Phi_UnclusteredEnDown;   //!
   TBranch        *b_T_METgen_ET;   //!
   TBranch        *b_T_METgen_Phi;   //!
   TBranch        *b_T_passTriggerDoubleMu;   //!
   TBranch        *b_T_passTriggerDoubleEl;   //!
   TBranch        *b_T_passTriggerSingleMu;   //!
   TBranch        *b_T_passTriggerSingleEl;   //!
   TBranch        *b_T_passTriggerElMu;   //!

   FIVEns(TTree *tree=0);
   virtual ~FIVEns();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef FIVEns_cxx
FIVEns::FIVEns(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/gpfs/csic_projects/tier3data/TreesDR74X/50ns/Tree_TbarW_0.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/gpfs/csic_projects/tier3data/TreesDR74X/50ns/Tree_TbarW_0.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/gpfs/csic_projects/tier3data/TreesDR74X/50ns/Tree_TbarW_0.root:/demo");
      dir->GetObject("Tree",tree);

   }
   Init(tree);
}

FIVEns::~FIVEns()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t FIVEns::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t FIVEns::LoadTree(Long64_t entry)
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

void FIVEns::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   T_Gen_StopMass = 0;
   T_Gen_Chi0Mass = 0;
   T_Gen_CharginoMass = 0;
   T_Gen_PromptMuon_pdgId = 0;
   T_Gen_PromptMuon_Px = 0;
   T_Gen_PromptMuon_Py = 0;
   T_Gen_PromptMuon_Pz = 0;
   T_Gen_PromptMuon_Energy = 0;
   T_Gen_PromptMuon_MpdgId = 0;
   T_Gen_PromptMuon_MPx = 0;
   T_Gen_PromptMuon_MPy = 0;
   T_Gen_PromptMuon_MPz = 0;
   T_Gen_PromptMuon_MEnergy = 0;
   T_Gen_PromptMuon_MSt = 0;
   T_Gen_PromptElec_pdgId = 0;
   T_Gen_PromptElec_Px = 0;
   T_Gen_PromptElec_Py = 0;
   T_Gen_PromptElec_Pz = 0;
   T_Gen_PromptElec_Energy = 0;
   T_Gen_PromptElec_MpdgId = 0;
   T_Gen_PromptElec_MPx = 0;
   T_Gen_PromptElec_MPy = 0;
   T_Gen_PromptElec_MPz = 0;
   T_Gen_PromptElec_MEnergy = 0;
   T_Gen_PromptElec_MSt = 0;
   T_Gen_Promptb_pdgId = 0;
   T_Gen_Promptb_Px = 0;
   T_Gen_Promptb_Py = 0;
   T_Gen_Promptb_Pz = 0;
   T_Gen_Promptb_Energy = 0;
   T_Gen_Promptb_MpdgId = 0;
   T_Gen_Promptb_MPx = 0;
   T_Gen_Promptb_MPy = 0;
   T_Gen_Promptb_MPz = 0;
   T_Gen_Promptb_MEnergy = 0;
   T_Gen_Promptb_MSt = 0;
   T_Gen_Muon_pdgId = 0;
   T_Gen_Muon_Px = 0;
   T_Gen_Muon_Py = 0;
   T_Gen_Muon_Pz = 0;
   T_Gen_Muon_Energy = 0;
   T_Gen_Muon_MpdgId = 0;
   T_Gen_Muon_MPx = 0;
   T_Gen_Muon_MPy = 0;
   T_Gen_Muon_MPz = 0;
   T_Gen_Muon_MEnergy = 0;
   T_Gen_Muon_MSt = 0;
   T_Gen_FinalMuon_pdgId = 0;
   T_Gen_FinalMuon_Px = 0;
   T_Gen_FinalMuon_Py = 0;
   T_Gen_FinalMuon_Pz = 0;
   T_Gen_FinalMuon_Energy = 0;
   T_Gen_Elec_pdgId = 0;
   T_Gen_Elec_Px = 0;
   T_Gen_Elec_Py = 0;
   T_Gen_Elec_Pz = 0;
   T_Gen_Elec_Energy = 0;
   T_Gen_Elec_MpdgId = 0;
   T_Gen_Elec_MPx = 0;
   T_Gen_Elec_MPy = 0;
   T_Gen_Elec_MPz = 0;
   T_Gen_Elec_MEnergy = 0;
   T_Gen_Elec_MSt = 0;
   T_Gen_FinalElec_pdgId = 0;
   T_Gen_FinalElec_Px = 0;
   T_Gen_FinalElec_Py = 0;
   T_Gen_FinalElec_Pz = 0;
   T_Gen_FinalElec_Energy = 0;
   T_Gen_b_pdgId = 0;
   T_Gen_b_Px = 0;
   T_Gen_b_Py = 0;
   T_Gen_b_Pz = 0;
   T_Gen_b_Energy = 0;
   T_Gen_b_MpdgId = 0;
   T_Gen_b_MPx = 0;
   T_Gen_b_MPy = 0;
   T_Gen_b_MPz = 0;
   T_Gen_b_MEnergy = 0;
   T_Gen_b_MSt = 0;
   T_Gen_Stop_pdgId = 0;
   T_Gen_Stop_MpdgId = 0;
   T_Gen_Stop_energy = 0;
   T_Gen_Stop_pt = 0;
   T_Gen_Stop_eta = 0;
   T_Gen_Stop_phi = 0;
   T_Gen_Chi0_pdgId = 0;
   T_Gen_Chi0_MpdgId = 0;
   T_Gen_Chi0_energy = 0;
   T_Gen_Chi0_pt = 0;
   T_Gen_Chi0_eta = 0;
   T_Gen_Chi0_phi = 0;
   T_Gen_ChiPM_pdgId = 0;
   T_Gen_ChiPM_MpdgId = 0;
   T_Gen_ChiPM_energy = 0;
   T_Gen_ChiPM_pt = 0;
   T_Gen_ChiPM_eta = 0;
   T_Gen_ChiPM_phi = 0;
   T_Gen_t_pdgId = 0;
   T_Gen_t_MpdgId = 0;
   T_Gen_t_energy = 0;
   T_Gen_t_pt = 0;
   T_Gen_t_eta = 0;
   T_Gen_t_phi = 0;
   T_Gen_Nu_pdgId = 0;
   T_Gen_Nu_MpdgId = 0;
   T_Gen_Nu_energy = 0;
   T_Gen_Nu_pt = 0;
   T_Gen_Nu_eta = 0;
   T_Gen_Nu_phi = 0;
   T_Gen_Z_pdgId = 0;
   T_Gen_Z_MpdgId = 0;
   T_Gen_Z_energy = 0;
   T_Gen_Z_pt = 0;
   T_Gen_Z_eta = 0;
   T_Gen_Z_phi = 0;
   T_Gen_W_pdgId = 0;
   T_Gen_W_MpdgId = 0;
   T_Gen_W_energy = 0;
   T_Gen_W_pt = 0;
   T_Gen_W_eta = 0;
   T_Gen_W_phi = 0;
   T_Gen_PromptTau_pdgId = 0;
   T_Gen_PromptTau_Energy = 0;
   T_Gen_PromptTau_Px = 0;
   T_Gen_PromptTau_Py = 0;
   T_Gen_PromptTau_Pz = 0;
   T_Gen_PromptTau_MpdgId = 0;
   T_Gen_PromptTau_MEnergy = 0;
   T_Gen_PromptTau_MPx = 0;
   T_Gen_PromptTau_MPy = 0;
   T_Gen_PromptTau_MPz = 0;
   T_Gen_PromptTau_MSt = 0;
   T_Gen_PromptTau_IsLepDec = 0;
   T_Gen_PromptTau_LepDec_pdgId = 0;
   T_Gen_PromptTau_LepDec_Px = 0;
   T_Gen_PromptTau_LepDec_Py = 0;
   T_Gen_PromptTau_LepDec_Pz = 0;
   T_Gen_PromptTau_LepDec_Energy = 0;
   T_Gen_Tau_pdgId = 0;
   T_Gen_Tau_Energy = 0;
   T_Gen_Tau_Px = 0;
   T_Gen_Tau_Py = 0;
   T_Gen_Tau_Pz = 0;
   T_Gen_Tau_MpdgId = 0;
   T_Gen_Tau_MEnergy = 0;
   T_Gen_Tau_MPx = 0;
   T_Gen_Tau_MPy = 0;
   T_Gen_Tau_MPz = 0;
   T_Gen_Tau_MSt = 0;
   T_Gen_Tau_IsLepDec = 0;
   T_Gen_Tau_LepDec_pdgId = 0;
   T_Gen_Tau_LepDec_Px = 0;
   T_Gen_Tau_LepDec_Py = 0;
   T_Gen_Tau_LepDec_Pz = 0;
   T_Gen_Tau_LepDec_Energy = 0;
   T_Vertex_x = 0;
   T_Vertex_y = 0;
   T_Vertex_z = 0;
   T_Vertex_Chi2Prob = 0;
   T_Vertex_ndof = 0;
   T_Vertex_rho = 0;
   T_Vertex_isFake = 0;
   T_Vertex_tracksSize = 0;
   T_Vertex_nTracks = 0;
   T_Vertex_isGood = 0;
   T_Muon_IsTightMuon = 0;
   T_Muon_IsMediumMuon = 0;
   T_Muon_IsPFMuon = 0;
   T_Muon_IsGlobalMuon = 0;
   T_Muon_IsTrackerMuon = 0;
   T_Muon_IsStandAloneMuon = 0;
   T_Muon_IsTrackerMuonArbitrated = 0;
   T_Muon_IsAllArbitrated = 0;
   T_Muon_IsGMPTMuons = 0;
   T_Muon_IsTMLastStationTight = 0;
   T_Muon_IsTrackHighPurity = 0;
   T_Muon_Eta = 0;
   T_Muon_Px = 0;
   T_Muon_Py = 0;
   T_Muon_Pz = 0;
   T_Muon_Pt = 0;
   T_Muon_BestTrack_Px = 0;
   T_Muon_BestTrack_Py = 0;
   T_Muon_BestTrack_Pz = 0;
   T_Muon_BestTrack_Pt = 0;
   T_Muon_BestTrack_Phi = 0;
   T_Muon_BestTrack_vx = 0;
   T_Muon_BestTrack_vy = 0;
   T_Muon_BestTrack_vz = 0;
   T_Muon_deltaPt = 0;
   T_Muon_Energy = 0;
   T_Muon_Charge = 0;
   T_Muon_vz = 0;
   T_Muon_vy = 0;
   T_Muon_vx = 0;
   T_Muon_NormChi2GTrk = 0;
   T_Muon_Chi2InTrk = 0;
   T_Muon_StaTrkChi2LocalPos = 0;
   T_Muon_dofInTrk = 0;
   T_Muon_NValidHitsInTrk = 0;
   T_Muon_NValidPixelHitsInTrk = 0;
   T_Muon_ValidFractionInTrk = 0;
   T_Muon_NValidHitsSATrk = 0;
   T_Muon_NValidHitsGTrk = 0;
   T_Muon_NLayers = 0;
   T_Muon_InnerTrackFound = 0;
   T_Muon_NumOfMatchedStations = 0;
   T_Muon_SegmentCompatibility = 0;
   T_Muon_trkKink = 0;
   T_Muon_dxyGTrack = 0;
   T_Muon_dxyInTrack = 0;
   T_Muon_BestTrack_dxy = 0;
   T_Muon_IPwrtAveBSInTrack = 0;
   T_Muon_dzGTrack = 0;
   T_Muon_dzInTrack = 0;
   T_Muon_BestTrack_dz = 0;
   T_Muon_fromPV = 0;
   T_Muon_chargedHadronIsoR04 = 0;
   T_Muon_neutralHadronIsoR04 = 0;
   T_Muon_neutralIsoPFweightR04 = 0;
   T_Muon_neutralIsoPUPPIR04 = 0;
   T_Muon_photonIsoR04 = 0;
   T_Muon_sumPUPtR04 = 0;
   T_Muon_chargedParticleIsoR03 = 0;
   T_Muon_chargedHadronIsoR03 = 0;
   T_Muon_neutralHadronIsoR03 = 0;
   T_Muon_neutralIsoPFweightR03 = 0;
   T_Muon_neutralIsoPUPPIR03 = 0;
   T_Muon_photonIsoR03 = 0;
   T_Muon_sumPUPtR03 = 0;
   T_Tau_Px = 0;
   T_Tau_Py = 0;
   T_Tau_Pz = 0;
   T_Tau_Energy = 0;
   T_Tau_Charge = 0;
   T_Elec_Eta = 0;
   T_Elec_IPwrtAveBS = 0;
   T_Elec_IPwrtPV = 0;
   T_Elec_dzwrtPV = 0;
   T_Elec_Px = 0;
   T_Elec_Py = 0;
   T_Elec_Pz = 0;
   T_Elec_Pt = 0;
   T_Elec_Energy = 0;
   T_Elec_Charge = 0;
   T_Elec_nBrems = 0;
   T_Elec_fBrem = 0;
   T_Elec_eSuperClusterOverP = 0;
   T_Elec_ecalEnergy = 0;
   T_Elec_dr03TkSumPt = 0;
   T_Elec_dr03EcalSumEt = 0;
   T_Elec_dr03HcalSumEt = 0;
   T_Elec_isEB = 0;
   T_Elec_isEE = 0;
   T_Elec_chargedHadronIso = 0;
   T_Elec_neutralHadronIso = 0;
   T_Elec_neutralIsoPFweight = 0;
   T_Elec_neutralIsoPUPPI = 0;
   T_Elec_photonIso = 0;
   T_Elec_puChargedHadronIso = 0;
   T_Elec_sumChargedHadronPt = 0;
   T_Elec_sumNeutralHadronEt = 0;
   T_Elec_sumPhotonEt = 0;
   T_Elec_sumPUPt = 0;
   T_Elec_passConversionVeto = 0;
   T_Elec_hasMatchedConversion = 0;
   T_Elec_sigmaIetaIeta = 0;
   T_Elec_sigmaIetaIetaFull5by5 = 0;
   T_Elec_deltaPhiIn = 0;
   T_Elec_deltaEtaIn = 0;
   T_Elec_isEcalDriven = 0;
   T_Elec_HtoE = 0;
   T_Elec_vz = 0;
   T_Elec_vy = 0;
   T_Elec_vx = 0;
   T_Elec_nLost = 0;
   T_Elec_nHits = 0;
   T_Elec_SC_Et = 0;
   T_Elec_SC_Eta = 0;
   T_Elec_PFElecPt = 0;
   T_Elec_PFElecPx = 0;
   T_Elec_PFElecPy = 0;
   T_Elec_PFElecPz = 0;
   T_Elec_PFElecE = 0;
   T_Elec_isPF = 0;
   T_Elec_MVAoutput = 0;
   T_JetAKCHS_Px = 0;
   T_JetAKCHS_Py = 0;
   T_JetAKCHS_Pz = 0;
   T_JetAKCHS_Et = 0;
   T_JetAKCHS_Eta = 0;
   T_JetAKCHS_Energy = 0;
   T_JetAKCHS_Corr = 0;
   T_JetAKCHS_Tag_HighEffTC = 0;
   T_JetAKCHS_Tag_CombInclusiveSVtxV2 = 0;
   T_JetAKCHS_Tag_CombMVA = 0;
   T_JetAKCHS_Tag_CombSVtx = 0;
   T_JetAKCHS_Tag_pfCombinedSVtx = 0;
   T_JetAKCHS_Tag_JetBProb = 0;
   T_JetAKCHS_Tag_JetProb = 0;
   T_JetAKCHS_Tag_HighEffSimpSVtx = 0;
   T_JetAKCHS_Tag_HighPurSimpSVtx = 0;
   T_JetAKCHS_Tag_HighPurTC = 0;
   T_JetAKCHS_Parton_Px = 0;
   T_JetAKCHS_Parton_Py = 0;
   T_JetAKCHS_Parton_Pz = 0;
   T_JetAKCHS_Parton_Energy = 0;
   T_JetAKCHS_Parton_Flavour = 0;
   T_JetAKCHS_Uncertainty = 0;
   T_JetAKCHS_PileupPt = 0;
   T_JetAKCHS_MPFInSitu = 0;
   T_JetAKCHS_bJES = 0;
   T_JetAKCHS_Flavor = 0;
   T_JetAKCHS_Intercalibration = 0;
   T_JetAKCHS_Uncorrelated = 0;
   T_JetAKCHS_MuonEnergyFrac = 0;
   T_JetAKCHS_CharHadEnergyFrac = 0;
   T_JetAKCHS_NeutHadEnergyFrac = 0;
   T_JetAKCHS_CharEmEnergyFrac = 0;
   T_JetAKCHS_NeutEmEnergyFrac = 0;
   T_JetAKCHS_CharHadEnergy = 0;
   T_JetAKCHS_NeutHadEnergy = 0;
   T_JetAKCHS_CharEmEnergy = 0;
   T_JetAKCHS_NeutEmEnergy = 0;
   T_JetAKCHS_MuonMultiplicity = 0;
   T_JetAKCHS_NeutralMultiplicity = 0;
   T_JetAKCHS_ChargedMultiplicity = 0;
   T_JetAKCHS_nDaughters = 0;
   T_JetAKCHS_IDLoose = 0;
   T_JetAKCHS_GenJet_InvisibleE = 0;
   T_JetAKCHS_GenJet_Px = 0;
   T_JetAKCHS_GenJet_Py = 0;
   T_JetAKCHS_GenJet_Pz = 0;
   T_JetAKCHS_GenJet_Et = 0;
   T_JetAKCHS_GenJet_Eta = 0;
   T_JetAKCHS_GenJet_Energy = 0;
   T_JetAKCHS_IsGenJet = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("T_Event_RunNumber", &T_Event_RunNumber, &b_T_Event_RunNumber);
   fChain->SetBranchAddress("T_Event_EventNumber", &T_Event_EventNumber, &b_T_Event_EventNumber);
   fChain->SetBranchAddress("T_Event_LuminosityBlock", &T_Event_LuminosityBlock, &b_T_Event_LuminosityBlock);
   fChain->SetBranchAddress("T_Event_processID", &T_Event_processID, &b_T_Event_processID);
   fChain->SetBranchAddress("T_Event_Rho", &T_Event_Rho, &b_T_Event_Rho);
   fChain->SetBranchAddress("T_Event_RhoFastJet", &T_Event_RhoFastJet, &b_T_Event_RhoFastJet);
   fChain->SetBranchAddress("T_Event_nPU", &T_Event_nPU, &b_T_Event_nPU);
   fChain->SetBranchAddress("T_Event_nPUm", &T_Event_nPUm, &b_T_Event_nPUm);
   fChain->SetBranchAddress("T_Event_nPUp", &T_Event_nPUp, &b_T_Event_nPUp);
   fChain->SetBranchAddress("T_Event_nTruePU", &T_Event_nTruePU, &b_T_Event_nTruePU);
   fChain->SetBranchAddress("T_Event_AveNTruePU", &T_Event_AveNTruePU, &b_T_Event_AveNTruePU);
   fChain->SetBranchAddress("T_EventF_HBHENoiseFilter", &T_EventF_HBHENoiseFilter, &b_T_EventF_HBHENoiseFilter);
   fChain->SetBranchAddress("T_EventF_CSCTightHaloFilter", &T_EventF_CSCTightHaloFilter, &b_T_EventF_CSCTightHaloFilter);
   fChain->SetBranchAddress("T_EventF_hcalLaserEventFilter", &T_EventF_hcalLaserEventFilter, &b_T_EventF_hcalLaserEventFilter);
   fChain->SetBranchAddress("T_EventF_EcalDeadCellTriggerPrimitiveFilter", &T_EventF_EcalDeadCellTriggerPrimitiveFilter, &b_T_EventF_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("T_EventF_goodVertices", &T_EventF_goodVertices, &b_T_EventF_goodVertices);
   fChain->SetBranchAddress("T_EventF_trackingFailureFilter", &T_EventF_trackingFailureFilter, &b_T_EventF_trackingFailureFilter);
   fChain->SetBranchAddress("T_EventF_eeBadScFilter", &T_EventF_eeBadScFilter, &b_T_EventF_eeBadScFilter);
   fChain->SetBranchAddress("T_EventF_ecalLaserCorrFilter", &T_EventF_ecalLaserCorrFilter, &b_T_EventF_ecalLaserCorrFilter);
   fChain->SetBranchAddress("T_EventF_trkPOGFilters", &T_EventF_trkPOGFilters, &b_T_EventF_trkPOGFilters);
   fChain->SetBranchAddress("T_EventF_trkPOG_manystripclus53X", &T_EventF_trkPOG_manystripclus53X, &b_T_EventF_trkPOG_manystripclus53X);
   fChain->SetBranchAddress("T_EventF_trkPOG_toomanystripclus53X", &T_EventF_trkPOG_toomanystripclus53X, &b_T_EventF_trkPOG_toomanystripclus53X);
   fChain->SetBranchAddress("T_EventF_trkPOG_logErrorTooManyClusters", &T_EventF_trkPOG_logErrorTooManyClusters, &b_T_EventF_trkPOG_logErrorTooManyClusters);
   fChain->SetBranchAddress("T_EventF_METFilters", &T_EventF_METFilters, &b_T_EventF_METFilters);
   fChain->SetBranchAddress("T_Gen_StopMass", &T_Gen_StopMass, &b_T_Gen_StopMass);
   fChain->SetBranchAddress("T_Gen_Chi0Mass", &T_Gen_Chi0Mass, &b_T_Gen_Chi0Mass);
   fChain->SetBranchAddress("T_Gen_CharginoMass", &T_Gen_CharginoMass, &b_T_Gen_CharginoMass);
   fChain->SetBranchAddress("T_Gen_PromptMuon_pdgId", &T_Gen_PromptMuon_pdgId, &b_T_Gen_PromptMuon_pdgId);
   fChain->SetBranchAddress("T_Gen_PromptMuon_Px", &T_Gen_PromptMuon_Px, &b_T_Gen_PromptMuon_Px);
   fChain->SetBranchAddress("T_Gen_PromptMuon_Py", &T_Gen_PromptMuon_Py, &b_T_Gen_PromptMuon_Py);
   fChain->SetBranchAddress("T_Gen_PromptMuon_Pz", &T_Gen_PromptMuon_Pz, &b_T_Gen_PromptMuon_Pz);
   fChain->SetBranchAddress("T_Gen_PromptMuon_Energy", &T_Gen_PromptMuon_Energy, &b_T_Gen_PromptMuon_Energy);
   fChain->SetBranchAddress("T_Gen_PromptMuon_MpdgId", &T_Gen_PromptMuon_MpdgId, &b_T_Gen_PromptMuon_MpdgId);
   fChain->SetBranchAddress("T_Gen_PromptMuon_MPx", &T_Gen_PromptMuon_MPx, &b_T_Gen_PromptMuon_MPx);
   fChain->SetBranchAddress("T_Gen_PromptMuon_MPy", &T_Gen_PromptMuon_MPy, &b_T_Gen_PromptMuon_MPy);
   fChain->SetBranchAddress("T_Gen_PromptMuon_MPz", &T_Gen_PromptMuon_MPz, &b_T_Gen_PromptMuon_MPz);
   fChain->SetBranchAddress("T_Gen_PromptMuon_MEnergy", &T_Gen_PromptMuon_MEnergy, &b_T_Gen_PromptMuon_MEnergy);
   fChain->SetBranchAddress("T_Gen_PromptMuon_MSt", &T_Gen_PromptMuon_MSt, &b_T_Gen_PromptMuon_MSt);
   fChain->SetBranchAddress("T_Gen_PromptElec_pdgId", &T_Gen_PromptElec_pdgId, &b_T_Gen_PromptElec_pdgId);
   fChain->SetBranchAddress("T_Gen_PromptElec_Px", &T_Gen_PromptElec_Px, &b_T_Gen_PromptElec_Px);
   fChain->SetBranchAddress("T_Gen_PromptElec_Py", &T_Gen_PromptElec_Py, &b_T_Gen_PromptElec_Py);
   fChain->SetBranchAddress("T_Gen_PromptElec_Pz", &T_Gen_PromptElec_Pz, &b_T_Gen_PromptElec_Pz);
   fChain->SetBranchAddress("T_Gen_PromptElec_Energy", &T_Gen_PromptElec_Energy, &b_T_Gen_PromptElec_Energy);
   fChain->SetBranchAddress("T_Gen_PromptElec_MpdgId", &T_Gen_PromptElec_MpdgId, &b_T_Gen_PromptElec_MpdgId);
   fChain->SetBranchAddress("T_Gen_PromptElec_MPx", &T_Gen_PromptElec_MPx, &b_T_Gen_PromptElec_MPx);
   fChain->SetBranchAddress("T_Gen_PromptElec_MPy", &T_Gen_PromptElec_MPy, &b_T_Gen_PromptElec_MPy);
   fChain->SetBranchAddress("T_Gen_PromptElec_MPz", &T_Gen_PromptElec_MPz, &b_T_Gen_PromptElec_MPz);
   fChain->SetBranchAddress("T_Gen_PromptElec_MEnergy", &T_Gen_PromptElec_MEnergy, &b_T_Gen_PromptElec_MEnergy);
   fChain->SetBranchAddress("T_Gen_PromptElec_MSt", &T_Gen_PromptElec_MSt, &b_T_Gen_PromptElec_MSt);
   fChain->SetBranchAddress("T_Gen_Promptb_pdgId", &T_Gen_Promptb_pdgId, &b_T_Gen_Promptb_pdgId);
   fChain->SetBranchAddress("T_Gen_Promptb_Px", &T_Gen_Promptb_Px, &b_T_Gen_Promptb_Px);
   fChain->SetBranchAddress("T_Gen_Promptb_Py", &T_Gen_Promptb_Py, &b_T_Gen_Promptb_Py);
   fChain->SetBranchAddress("T_Gen_Promptb_Pz", &T_Gen_Promptb_Pz, &b_T_Gen_Promptb_Pz);
   fChain->SetBranchAddress("T_Gen_Promptb_Energy", &T_Gen_Promptb_Energy, &b_T_Gen_Promptb_Energy);
   fChain->SetBranchAddress("T_Gen_Promptb_MpdgId", &T_Gen_Promptb_MpdgId, &b_T_Gen_Promptb_MpdgId);
   fChain->SetBranchAddress("T_Gen_Promptb_MPx", &T_Gen_Promptb_MPx, &b_T_Gen_Promptb_MPx);
   fChain->SetBranchAddress("T_Gen_Promptb_MPy", &T_Gen_Promptb_MPy, &b_T_Gen_Promptb_MPy);
   fChain->SetBranchAddress("T_Gen_Promptb_MPz", &T_Gen_Promptb_MPz, &b_T_Gen_Promptb_MPz);
   fChain->SetBranchAddress("T_Gen_Promptb_MEnergy", &T_Gen_Promptb_MEnergy, &b_T_Gen_Promptb_MEnergy);
   fChain->SetBranchAddress("T_Gen_Promptb_MSt", &T_Gen_Promptb_MSt, &b_T_Gen_Promptb_MSt);
   fChain->SetBranchAddress("T_Gen_Muon_pdgId", &T_Gen_Muon_pdgId, &b_T_Gen_Muon_pdgId);
   fChain->SetBranchAddress("T_Gen_Muon_Px", &T_Gen_Muon_Px, &b_T_Gen_Muon_Px);
   fChain->SetBranchAddress("T_Gen_Muon_Py", &T_Gen_Muon_Py, &b_T_Gen_Muon_Py);
   fChain->SetBranchAddress("T_Gen_Muon_Pz", &T_Gen_Muon_Pz, &b_T_Gen_Muon_Pz);
   fChain->SetBranchAddress("T_Gen_Muon_Energy", &T_Gen_Muon_Energy, &b_T_Gen_Muon_Energy);
   fChain->SetBranchAddress("T_Gen_Muon_MpdgId", &T_Gen_Muon_MpdgId, &b_T_Gen_Muon_MpdgId);
   fChain->SetBranchAddress("T_Gen_Muon_MPx", &T_Gen_Muon_MPx, &b_T_Gen_Muon_MPx);
   fChain->SetBranchAddress("T_Gen_Muon_MPy", &T_Gen_Muon_MPy, &b_T_Gen_Muon_MPy);
   fChain->SetBranchAddress("T_Gen_Muon_MPz", &T_Gen_Muon_MPz, &b_T_Gen_Muon_MPz);
   fChain->SetBranchAddress("T_Gen_Muon_MEnergy", &T_Gen_Muon_MEnergy, &b_T_Gen_Muon_MEnergy);
   fChain->SetBranchAddress("T_Gen_Muon_MSt", &T_Gen_Muon_MSt, &b_T_Gen_Muon_MSt);
   fChain->SetBranchAddress("T_Gen_FinalMuon_pdgId", &T_Gen_FinalMuon_pdgId, &b_T_Gen_FinalMuon_pdgId);
   fChain->SetBranchAddress("T_Gen_FinalMuon_Px", &T_Gen_FinalMuon_Px, &b_T_Gen_FinalMuon_Px);
   fChain->SetBranchAddress("T_Gen_FinalMuon_Py", &T_Gen_FinalMuon_Py, &b_T_Gen_FinalMuon_Py);
   fChain->SetBranchAddress("T_Gen_FinalMuon_Pz", &T_Gen_FinalMuon_Pz, &b_T_Gen_FinalMuon_Pz);
   fChain->SetBranchAddress("T_Gen_FinalMuon_Energy", &T_Gen_FinalMuon_Energy, &b_T_Gen_FinalMuon_Energy);
   fChain->SetBranchAddress("T_Gen_Elec_pdgId", &T_Gen_Elec_pdgId, &b_T_Gen_Elec_pdgId);
   fChain->SetBranchAddress("T_Gen_Elec_Px", &T_Gen_Elec_Px, &b_T_Gen_Elec_Px);
   fChain->SetBranchAddress("T_Gen_Elec_Py", &T_Gen_Elec_Py, &b_T_Gen_Elec_Py);
   fChain->SetBranchAddress("T_Gen_Elec_Pz", &T_Gen_Elec_Pz, &b_T_Gen_Elec_Pz);
   fChain->SetBranchAddress("T_Gen_Elec_Energy", &T_Gen_Elec_Energy, &b_T_Gen_Elec_Energy);
   fChain->SetBranchAddress("T_Gen_Elec_MpdgId", &T_Gen_Elec_MpdgId, &b_T_Gen_Elec_MpdgId);
   fChain->SetBranchAddress("T_Gen_Elec_MPx", &T_Gen_Elec_MPx, &b_T_Gen_Elec_MPx);
   fChain->SetBranchAddress("T_Gen_Elec_MPy", &T_Gen_Elec_MPy, &b_T_Gen_Elec_MPy);
   fChain->SetBranchAddress("T_Gen_Elec_MPz", &T_Gen_Elec_MPz, &b_T_Gen_Elec_MPz);
   fChain->SetBranchAddress("T_Gen_Elec_MEnergy", &T_Gen_Elec_MEnergy, &b_T_Gen_Elec_MEnergy);
   fChain->SetBranchAddress("T_Gen_Elec_MSt", &T_Gen_Elec_MSt, &b_T_Gen_Elec_MSt);
   fChain->SetBranchAddress("T_Gen_FinalElec_pdgId", &T_Gen_FinalElec_pdgId, &b_T_Gen_FinalElec_pdgId);
   fChain->SetBranchAddress("T_Gen_FinalElec_Px", &T_Gen_FinalElec_Px, &b_T_Gen_FinalElec_Px);
   fChain->SetBranchAddress("T_Gen_FinalElec_Py", &T_Gen_FinalElec_Py, &b_T_Gen_FinalElec_Py);
   fChain->SetBranchAddress("T_Gen_FinalElec_Pz", &T_Gen_FinalElec_Pz, &b_T_Gen_FinalElec_Pz);
   fChain->SetBranchAddress("T_Gen_FinalElec_Energy", &T_Gen_FinalElec_Energy, &b_T_Gen_FinalElec_Energy);
   fChain->SetBranchAddress("T_Gen_b_pdgId", &T_Gen_b_pdgId, &b_T_Gen_b_pdgId);
   fChain->SetBranchAddress("T_Gen_b_Px", &T_Gen_b_Px, &b_T_Gen_b_Px);
   fChain->SetBranchAddress("T_Gen_b_Py", &T_Gen_b_Py, &b_T_Gen_b_Py);
   fChain->SetBranchAddress("T_Gen_b_Pz", &T_Gen_b_Pz, &b_T_Gen_b_Pz);
   fChain->SetBranchAddress("T_Gen_b_Energy", &T_Gen_b_Energy, &b_T_Gen_b_Energy);
   fChain->SetBranchAddress("T_Gen_b_MpdgId", &T_Gen_b_MpdgId, &b_T_Gen_b_MpdgId);
   fChain->SetBranchAddress("T_Gen_b_MPx", &T_Gen_b_MPx, &b_T_Gen_b_MPx);
   fChain->SetBranchAddress("T_Gen_b_MPy", &T_Gen_b_MPy, &b_T_Gen_b_MPy);
   fChain->SetBranchAddress("T_Gen_b_MPz", &T_Gen_b_MPz, &b_T_Gen_b_MPz);
   fChain->SetBranchAddress("T_Gen_b_MEnergy", &T_Gen_b_MEnergy, &b_T_Gen_b_MEnergy);
   fChain->SetBranchAddress("T_Gen_b_MSt", &T_Gen_b_MSt, &b_T_Gen_b_MSt);
   fChain->SetBranchAddress("T_Gen_Stop_pdgId", &T_Gen_Stop_pdgId, &b_T_Gen_Stop_pdgId);
   fChain->SetBranchAddress("T_Gen_Stop_MpdgId", &T_Gen_Stop_MpdgId, &b_T_Gen_Stop_MpdgId);
   fChain->SetBranchAddress("T_Gen_Stop_energy", &T_Gen_Stop_energy, &b_T_Gen_Stop_energy);
   fChain->SetBranchAddress("T_Gen_Stop_pt", &T_Gen_Stop_pt, &b_T_Gen_Stop_pt);
   fChain->SetBranchAddress("T_Gen_Stop_eta", &T_Gen_Stop_eta, &b_T_Gen_Stop_eta);
   fChain->SetBranchAddress("T_Gen_Stop_phi", &T_Gen_Stop_phi, &b_T_Gen_Stop_phi);
   fChain->SetBranchAddress("T_Gen_Chi0_pdgId", &T_Gen_Chi0_pdgId, &b_T_Gen_Chi0_pdgId);
   fChain->SetBranchAddress("T_Gen_Chi0_MpdgId", &T_Gen_Chi0_MpdgId, &b_T_Gen_Chi0_MpdgId);
   fChain->SetBranchAddress("T_Gen_Chi0_energy", &T_Gen_Chi0_energy, &b_T_Gen_Chi0_energy);
   fChain->SetBranchAddress("T_Gen_Chi0_pt", &T_Gen_Chi0_pt, &b_T_Gen_Chi0_pt);
   fChain->SetBranchAddress("T_Gen_Chi0_eta", &T_Gen_Chi0_eta, &b_T_Gen_Chi0_eta);
   fChain->SetBranchAddress("T_Gen_Chi0_phi", &T_Gen_Chi0_phi, &b_T_Gen_Chi0_phi);
   fChain->SetBranchAddress("T_Gen_ChiPM_pdgId", &T_Gen_ChiPM_pdgId, &b_T_Gen_ChiPM_pdgId);
   fChain->SetBranchAddress("T_Gen_ChiPM_MpdgId", &T_Gen_ChiPM_MpdgId, &b_T_Gen_ChiPM_MpdgId);
   fChain->SetBranchAddress("T_Gen_ChiPM_energy", &T_Gen_ChiPM_energy, &b_T_Gen_ChiPM_energy);
   fChain->SetBranchAddress("T_Gen_ChiPM_pt", &T_Gen_ChiPM_pt, &b_T_Gen_ChiPM_pt);
   fChain->SetBranchAddress("T_Gen_ChiPM_eta", &T_Gen_ChiPM_eta, &b_T_Gen_ChiPM_eta);
   fChain->SetBranchAddress("T_Gen_ChiPM_phi", &T_Gen_ChiPM_phi, &b_T_Gen_ChiPM_phi);
   fChain->SetBranchAddress("T_Gen_t_pdgId", &T_Gen_t_pdgId, &b_T_Gen_t_pdgId);
   fChain->SetBranchAddress("T_Gen_t_MpdgId", &T_Gen_t_MpdgId, &b_T_Gen_t_MpdgId);
   fChain->SetBranchAddress("T_Gen_t_energy", &T_Gen_t_energy, &b_T_Gen_t_energy);
   fChain->SetBranchAddress("T_Gen_t_pt", &T_Gen_t_pt, &b_T_Gen_t_pt);
   fChain->SetBranchAddress("T_Gen_t_eta", &T_Gen_t_eta, &b_T_Gen_t_eta);
   fChain->SetBranchAddress("T_Gen_t_phi", &T_Gen_t_phi, &b_T_Gen_t_phi);
   fChain->SetBranchAddress("T_Gen_Nu_pdgId", &T_Gen_Nu_pdgId, &b_T_Gen_Nu_pdgId);
   fChain->SetBranchAddress("T_Gen_Nu_MpdgId", &T_Gen_Nu_MpdgId, &b_T_Gen_Nu_MpdgId);
   fChain->SetBranchAddress("T_Gen_Nu_energy", &T_Gen_Nu_energy, &b_T_Gen_Nu_energy);
   fChain->SetBranchAddress("T_Gen_Nu_pt", &T_Gen_Nu_pt, &b_T_Gen_Nu_pt);
   fChain->SetBranchAddress("T_Gen_Nu_eta", &T_Gen_Nu_eta, &b_T_Gen_Nu_eta);
   fChain->SetBranchAddress("T_Gen_Nu_phi", &T_Gen_Nu_phi, &b_T_Gen_Nu_phi);
   fChain->SetBranchAddress("T_Gen_Z_pdgId", &T_Gen_Z_pdgId, &b_T_Gen_Z_pdgId);
   fChain->SetBranchAddress("T_Gen_Z_MpdgId", &T_Gen_Z_MpdgId, &b_T_Gen_Z_MpdgId);
   fChain->SetBranchAddress("T_Gen_Z_energy", &T_Gen_Z_energy, &b_T_Gen_Z_energy);
   fChain->SetBranchAddress("T_Gen_Z_pt", &T_Gen_Z_pt, &b_T_Gen_Z_pt);
   fChain->SetBranchAddress("T_Gen_Z_eta", &T_Gen_Z_eta, &b_T_Gen_Z_eta);
   fChain->SetBranchAddress("T_Gen_Z_phi", &T_Gen_Z_phi, &b_T_Gen_Z_phi);
   fChain->SetBranchAddress("T_Gen_W_pdgId", &T_Gen_W_pdgId, &b_T_Gen_W_pdgId);
   fChain->SetBranchAddress("T_Gen_W_MpdgId", &T_Gen_W_MpdgId, &b_T_Gen_W_MpdgId);
   fChain->SetBranchAddress("T_Gen_W_energy", &T_Gen_W_energy, &b_T_Gen_W_energy);
   fChain->SetBranchAddress("T_Gen_W_pt", &T_Gen_W_pt, &b_T_Gen_W_pt);
   fChain->SetBranchAddress("T_Gen_W_eta", &T_Gen_W_eta, &b_T_Gen_W_eta);
   fChain->SetBranchAddress("T_Gen_W_phi", &T_Gen_W_phi, &b_T_Gen_W_phi);
   fChain->SetBranchAddress("T_Gen_PromptTau_pdgId", &T_Gen_PromptTau_pdgId, &b_T_Gen_PromptTau_pdgId);
   fChain->SetBranchAddress("T_Gen_PromptTau_Energy", &T_Gen_PromptTau_Energy, &b_T_Gen_PromptTau_Energy);
   fChain->SetBranchAddress("T_Gen_PromptTau_Px", &T_Gen_PromptTau_Px, &b_T_Gen_PromptTau_Px);
   fChain->SetBranchAddress("T_Gen_PromptTau_Py", &T_Gen_PromptTau_Py, &b_T_Gen_PromptTau_Py);
   fChain->SetBranchAddress("T_Gen_PromptTau_Pz", &T_Gen_PromptTau_Pz, &b_T_Gen_PromptTau_Pz);
   fChain->SetBranchAddress("T_Gen_PromptTau_MpdgId", &T_Gen_PromptTau_MpdgId, &b_T_Gen_PromptTau_MpdgId);
   fChain->SetBranchAddress("T_Gen_PromptTau_MEnergy", &T_Gen_PromptTau_MEnergy, &b_T_Gen_PromptTau_MEnergy);
   fChain->SetBranchAddress("T_Gen_PromptTau_MPx", &T_Gen_PromptTau_MPx, &b_T_Gen_PromptTau_MPx);
   fChain->SetBranchAddress("T_Gen_PromptTau_MPy", &T_Gen_PromptTau_MPy, &b_T_Gen_PromptTau_MPy);
   fChain->SetBranchAddress("T_Gen_PromptTau_MPz", &T_Gen_PromptTau_MPz, &b_T_Gen_PromptTau_MPz);
   fChain->SetBranchAddress("T_Gen_PromptTau_MSt", &T_Gen_PromptTau_MSt, &b_T_Gen_PromptTau_MSt);
   fChain->SetBranchAddress("T_Gen_PromptTau_IsLepDec", &T_Gen_PromptTau_IsLepDec, &b_T_Gen_PromptTau_IsLepDec);
   fChain->SetBranchAddress("T_Gen_PromptTau_LepDec_pdgId", &T_Gen_PromptTau_LepDec_pdgId, &b_T_Gen_PromptTau_LepDec_pdgId);
   fChain->SetBranchAddress("T_Gen_PromptTau_LepDec_Px", &T_Gen_PromptTau_LepDec_Px, &b_T_Gen_PromptTau_LepDec_Px);
   fChain->SetBranchAddress("T_Gen_PromptTau_LepDec_Py", &T_Gen_PromptTau_LepDec_Py, &b_T_Gen_PromptTau_LepDec_Py);
   fChain->SetBranchAddress("T_Gen_PromptTau_LepDec_Pz", &T_Gen_PromptTau_LepDec_Pz, &b_T_Gen_PromptTau_LepDec_Pz);
   fChain->SetBranchAddress("T_Gen_PromptTau_LepDec_Energy", &T_Gen_PromptTau_LepDec_Energy, &b_T_Gen_PromptTau_LepDec_Energy);
   fChain->SetBranchAddress("T_Gen_Tau_pdgId", &T_Gen_Tau_pdgId, &b_T_Gen_Tau_pdgId);
   fChain->SetBranchAddress("T_Gen_Tau_Energy", &T_Gen_Tau_Energy, &b_T_Gen_Tau_Energy);
   fChain->SetBranchAddress("T_Gen_Tau_Px", &T_Gen_Tau_Px, &b_T_Gen_Tau_Px);
   fChain->SetBranchAddress("T_Gen_Tau_Py", &T_Gen_Tau_Py, &b_T_Gen_Tau_Py);
   fChain->SetBranchAddress("T_Gen_Tau_Pz", &T_Gen_Tau_Pz, &b_T_Gen_Tau_Pz);
   fChain->SetBranchAddress("T_Gen_Tau_MpdgId", &T_Gen_Tau_MpdgId, &b_T_Gen_Tau_MpdgId);
   fChain->SetBranchAddress("T_Gen_Tau_MEnergy", &T_Gen_Tau_MEnergy, &b_T_Gen_Tau_MEnergy);
   fChain->SetBranchAddress("T_Gen_Tau_MPx", &T_Gen_Tau_MPx, &b_T_Gen_Tau_MPx);
   fChain->SetBranchAddress("T_Gen_Tau_MPy", &T_Gen_Tau_MPy, &b_T_Gen_Tau_MPy);
   fChain->SetBranchAddress("T_Gen_Tau_MPz", &T_Gen_Tau_MPz, &b_T_Gen_Tau_MPz);
   fChain->SetBranchAddress("T_Gen_Tau_MSt", &T_Gen_Tau_MSt, &b_T_Gen_Tau_MSt);
   fChain->SetBranchAddress("T_Gen_Tau_IsLepDec", &T_Gen_Tau_IsLepDec, &b_T_Gen_Tau_IsLepDec);
   fChain->SetBranchAddress("T_Gen_Tau_LepDec_pdgId", &T_Gen_Tau_LepDec_pdgId, &b_T_Gen_Tau_LepDec_pdgId);
   fChain->SetBranchAddress("T_Gen_Tau_LepDec_Px", &T_Gen_Tau_LepDec_Px, &b_T_Gen_Tau_LepDec_Px);
   fChain->SetBranchAddress("T_Gen_Tau_LepDec_Py", &T_Gen_Tau_LepDec_Py, &b_T_Gen_Tau_LepDec_Py);
   fChain->SetBranchAddress("T_Gen_Tau_LepDec_Pz", &T_Gen_Tau_LepDec_Pz, &b_T_Gen_Tau_LepDec_Pz);
   fChain->SetBranchAddress("T_Gen_Tau_LepDec_Energy", &T_Gen_Tau_LepDec_Energy, &b_T_Gen_Tau_LepDec_Energy);
   fChain->SetBranchAddress("T_Event_weight", &T_Event_weight, &b_T_Event_weight);
   fChain->SetBranchAddress("T_Vertex_x", &T_Vertex_x, &b_T_Vertex_x);
   fChain->SetBranchAddress("T_Vertex_y", &T_Vertex_y, &b_T_Vertex_y);
   fChain->SetBranchAddress("T_Vertex_z", &T_Vertex_z, &b_T_Vertex_z);
   fChain->SetBranchAddress("T_Vertex_Chi2Prob", &T_Vertex_Chi2Prob, &b_T_Vertex_Chi2Prob);
   fChain->SetBranchAddress("T_Vertex_ndof", &T_Vertex_ndof, &b_T_Vertex_ndof);
   fChain->SetBranchAddress("T_Vertex_rho", &T_Vertex_rho, &b_T_Vertex_rho);
   fChain->SetBranchAddress("T_Vertex_isFake", &T_Vertex_isFake, &b_T_Vertex_isFake);
   fChain->SetBranchAddress("T_Vertex_tracksSize", &T_Vertex_tracksSize, &b_T_Vertex_tracksSize);
   fChain->SetBranchAddress("T_Vertex_nTracks", &T_Vertex_nTracks, &b_T_Vertex_nTracks);
   fChain->SetBranchAddress("T_Vertex_isGood", &T_Vertex_isGood, &b_T_Vertex_isGood);
   fChain->SetBranchAddress("T_Muon_IsTightMuon", &T_Muon_IsTightMuon, &b_T_Muon_IsTightMuon);
   fChain->SetBranchAddress("T_Muon_IsMediumMuon", &T_Muon_IsMediumMuon, &b_T_Muon_IsMediumMuon);
   fChain->SetBranchAddress("T_Muon_IsPFMuon", &T_Muon_IsPFMuon, &b_T_Muon_IsPFMuon);
   fChain->SetBranchAddress("T_Muon_IsGlobalMuon", &T_Muon_IsGlobalMuon, &b_T_Muon_IsGlobalMuon);
   fChain->SetBranchAddress("T_Muon_IsTrackerMuon", &T_Muon_IsTrackerMuon, &b_T_Muon_IsTrackerMuon);
   fChain->SetBranchAddress("T_Muon_IsStandAloneMuon", &T_Muon_IsStandAloneMuon, &b_T_Muon_IsStandAloneMuon);
   fChain->SetBranchAddress("T_Muon_IsTrackerMuonArbitrated", &T_Muon_IsTrackerMuonArbitrated, &b_T_Muon_IsTrackerMuonArbitrated);
   fChain->SetBranchAddress("T_Muon_IsAllArbitrated", &T_Muon_IsAllArbitrated, &b_T_Muon_IsAllArbitrated);
   fChain->SetBranchAddress("T_Muon_IsGMPTMuons", &T_Muon_IsGMPTMuons, &b_T_Muon_IsGMPTMuons);
   fChain->SetBranchAddress("T_Muon_IsTMLastStationTight", &T_Muon_IsTMLastStationTight, &b_T_Muon_IsTMLastStationTight);
   fChain->SetBranchAddress("T_Muon_IsTrackHighPurity", &T_Muon_IsTrackHighPurity, &b_T_Muon_IsTrackHighPurity);
   fChain->SetBranchAddress("T_Muon_Eta", &T_Muon_Eta, &b_T_Muon_Eta);
   fChain->SetBranchAddress("T_Muon_Px", &T_Muon_Px, &b_T_Muon_Px);
   fChain->SetBranchAddress("T_Muon_Py", &T_Muon_Py, &b_T_Muon_Py);
   fChain->SetBranchAddress("T_Muon_Pz", &T_Muon_Pz, &b_T_Muon_Pz);
   fChain->SetBranchAddress("T_Muon_Pt", &T_Muon_Pt, &b_T_Muon_Pt);
   fChain->SetBranchAddress("T_Muon_BestTrack_Px", &T_Muon_BestTrack_Px, &b_T_Muon_BestTrack_Px);
   fChain->SetBranchAddress("T_Muon_BestTrack_Py", &T_Muon_BestTrack_Py, &b_T_Muon_BestTrack_Py);
   fChain->SetBranchAddress("T_Muon_BestTrack_Pz", &T_Muon_BestTrack_Pz, &b_T_Muon_BestTrack_Pz);
   fChain->SetBranchAddress("T_Muon_BestTrack_Pt", &T_Muon_BestTrack_Pt, &b_T_Muon_BestTrack_Pt);
   fChain->SetBranchAddress("T_Muon_BestTrack_Phi", &T_Muon_BestTrack_Phi, &b_T_Muon_BestTrack_Phi);
   fChain->SetBranchAddress("T_Muon_BestTrack_vx", &T_Muon_BestTrack_vx, &b_T_Muon_BestTrack_vx);
   fChain->SetBranchAddress("T_Muon_BestTrack_vy", &T_Muon_BestTrack_vy, &b_T_Muon_BestTrack_vy);
   fChain->SetBranchAddress("T_Muon_BestTrack_vz", &T_Muon_BestTrack_vz, &b_T_Muon_BestTrack_vz);
   fChain->SetBranchAddress("T_Muon_deltaPt", &T_Muon_deltaPt, &b_T_Muon_deltaPt);
   fChain->SetBranchAddress("T_Muon_Energy", &T_Muon_Energy, &b_T_Muon_Energy);
   fChain->SetBranchAddress("T_Muon_Charge", &T_Muon_Charge, &b_T_Muon_Charge);
   fChain->SetBranchAddress("T_Muon_vz", &T_Muon_vz, &b_T_Muon_vz);
   fChain->SetBranchAddress("T_Muon_vy", &T_Muon_vy, &b_T_Muon_vy);
   fChain->SetBranchAddress("T_Muon_vx", &T_Muon_vx, &b_T_Muon_vx);
   fChain->SetBranchAddress("T_Muon_NormChi2GTrk", &T_Muon_NormChi2GTrk, &b_T_Muon_NormChi2GTrk);
   fChain->SetBranchAddress("T_Muon_Chi2InTrk", &T_Muon_Chi2InTrk, &b_T_Muon_Chi2InTrk);
   fChain->SetBranchAddress("T_Muon_StaTrkChi2LocalPos", &T_Muon_StaTrkChi2LocalPos, &b_T_Muon_StaTrkChi2LocalPos);
   fChain->SetBranchAddress("T_Muon_dofInTrk", &T_Muon_dofInTrk, &b_T_Muon_dofInTrk);
   fChain->SetBranchAddress("T_Muon_NValidHitsInTrk", &T_Muon_NValidHitsInTrk, &b_T_Muon_NValidHitsInTrk);
   fChain->SetBranchAddress("T_Muon_NValidPixelHitsInTrk", &T_Muon_NValidPixelHitsInTrk, &b_T_Muon_NValidPixelHitsInTrk);
   fChain->SetBranchAddress("T_Muon_ValidFractionInTrk", &T_Muon_ValidFractionInTrk, &b_T_Muon_ValidFractionInTrk);
   fChain->SetBranchAddress("T_Muon_NValidHitsSATrk", &T_Muon_NValidHitsSATrk, &b_T_Muon_NValidHitsSATrk);
   fChain->SetBranchAddress("T_Muon_NValidHitsGTrk", &T_Muon_NValidHitsGTrk, &b_T_Muon_NValidHitsGTrk);
   fChain->SetBranchAddress("T_Muon_NLayers", &T_Muon_NLayers, &b_T_Muon_NLayers);
   fChain->SetBranchAddress("T_Muon_InnerTrackFound", &T_Muon_InnerTrackFound, &b_T_Muon_InnerTrackFound);
   fChain->SetBranchAddress("T_Muon_NumOfMatchedStations", &T_Muon_NumOfMatchedStations, &b_T_Muon_NumOfMatchedStations);
   fChain->SetBranchAddress("T_Muon_SegmentCompatibility", &T_Muon_SegmentCompatibility, &b_T_Muon_SegmentCompatibility);
   fChain->SetBranchAddress("T_Muon_trkKink", &T_Muon_trkKink, &b_T_Muon_trkKink);
   fChain->SetBranchAddress("T_Muon_dxyGTrack", &T_Muon_dxyGTrack, &b_T_Muon_dxyGTrack);
   fChain->SetBranchAddress("T_Muon_dxyInTrack", &T_Muon_dxyInTrack, &b_T_Muon_dxyInTrack);
   fChain->SetBranchAddress("T_Muon_BestTrack_dxy", &T_Muon_BestTrack_dxy, &b_T_Muon_BestTrack_dxy);
   fChain->SetBranchAddress("T_Muon_IPwrtAveBSInTrack", &T_Muon_IPwrtAveBSInTrack, &b_T_Muon_IPwrtAveBSInTrack);
   fChain->SetBranchAddress("T_Muon_dzGTrack", &T_Muon_dzGTrack, &b_T_Muon_dzGTrack);
   fChain->SetBranchAddress("T_Muon_dzInTrack", &T_Muon_dzInTrack, &b_T_Muon_dzInTrack);
   fChain->SetBranchAddress("T_Muon_BestTrack_dz", &T_Muon_BestTrack_dz, &b_T_Muon_BestTrack_dz);
   fChain->SetBranchAddress("T_Muon_fromPV", &T_Muon_fromPV, &b_T_Muon_fromPV);
   fChain->SetBranchAddress("T_Muon_chargedHadronIsoR04", &T_Muon_chargedHadronIsoR04, &b_T_Muon_chargedHadronIsoR04);
   fChain->SetBranchAddress("T_Muon_neutralHadronIsoR04", &T_Muon_neutralHadronIsoR04, &b_T_Muon_neutralHadronIsoR04);
   fChain->SetBranchAddress("T_Muon_neutralIsoPFweightR04", &T_Muon_neutralIsoPFweightR04, &b_T_Muon_neutralIsoPFweightR04);
   fChain->SetBranchAddress("T_Muon_neutralIsoPUPPIR04", &T_Muon_neutralIsoPUPPIR04, &b_T_Muon_neutralIsoPUPPIR04);
   fChain->SetBranchAddress("T_Muon_photonIsoR04", &T_Muon_photonIsoR04, &b_T_Muon_photonIsoR04);
   fChain->SetBranchAddress("T_Muon_sumPUPtR04", &T_Muon_sumPUPtR04, &b_T_Muon_sumPUPtR04);
   fChain->SetBranchAddress("T_Muon_chargedParticleIsoR03", &T_Muon_chargedParticleIsoR03, &b_T_Muon_chargedParticleIsoR03);
   fChain->SetBranchAddress("T_Muon_chargedHadronIsoR03", &T_Muon_chargedHadronIsoR03, &b_T_Muon_chargedHadronIsoR03);
   fChain->SetBranchAddress("T_Muon_neutralHadronIsoR03", &T_Muon_neutralHadronIsoR03, &b_T_Muon_neutralHadronIsoR03);
   fChain->SetBranchAddress("T_Muon_neutralIsoPFweightR03", &T_Muon_neutralIsoPFweightR03, &b_T_Muon_neutralIsoPFweightR03);
   fChain->SetBranchAddress("T_Muon_neutralIsoPUPPIR03", &T_Muon_neutralIsoPUPPIR03, &b_T_Muon_neutralIsoPUPPIR03);
   fChain->SetBranchAddress("T_Muon_photonIsoR03", &T_Muon_photonIsoR03, &b_T_Muon_photonIsoR03);
   fChain->SetBranchAddress("T_Muon_sumPUPtR03", &T_Muon_sumPUPtR03, &b_T_Muon_sumPUPtR03);
   fChain->SetBranchAddress("T_Tau_Px", &T_Tau_Px, &b_T_Tau_Px);
   fChain->SetBranchAddress("T_Tau_Py", &T_Tau_Py, &b_T_Tau_Py);
   fChain->SetBranchAddress("T_Tau_Pz", &T_Tau_Pz, &b_T_Tau_Pz);
   fChain->SetBranchAddress("T_Tau_Energy", &T_Tau_Energy, &b_T_Tau_Energy);
   fChain->SetBranchAddress("T_Tau_Charge", &T_Tau_Charge, &b_T_Tau_Charge);
   fChain->SetBranchAddress("T_Elec_Eta", &T_Elec_Eta, &b_T_Elec_Eta);
   fChain->SetBranchAddress("T_Elec_IPwrtAveBS", &T_Elec_IPwrtAveBS, &b_T_Elec_IPwrtAveBS);
   fChain->SetBranchAddress("T_Elec_IPwrtPV", &T_Elec_IPwrtPV, &b_T_Elec_IPwrtPV);
   fChain->SetBranchAddress("T_Elec_dzwrtPV", &T_Elec_dzwrtPV, &b_T_Elec_dzwrtPV);
   fChain->SetBranchAddress("T_Elec_Px", &T_Elec_Px, &b_T_Elec_Px);
   fChain->SetBranchAddress("T_Elec_Py", &T_Elec_Py, &b_T_Elec_Py);
   fChain->SetBranchAddress("T_Elec_Pz", &T_Elec_Pz, &b_T_Elec_Pz);
   fChain->SetBranchAddress("T_Elec_Pt", &T_Elec_Pt, &b_T_Elec_Pt);
   fChain->SetBranchAddress("T_Elec_Energy", &T_Elec_Energy, &b_T_Elec_Energy);
   fChain->SetBranchAddress("T_Elec_Charge", &T_Elec_Charge, &b_T_Elec_Charge);
   fChain->SetBranchAddress("T_Elec_nBrems", &T_Elec_nBrems, &b_T_Elec_nBrems);
   fChain->SetBranchAddress("T_Elec_fBrem", &T_Elec_fBrem, &b_T_Elec_fBrem);
   fChain->SetBranchAddress("T_Elec_eSuperClusterOverP", &T_Elec_eSuperClusterOverP, &b_T_Elec_eSuperClusterOverP);
   fChain->SetBranchAddress("T_Elec_ecalEnergy", &T_Elec_ecalEnergy, &b_T_Elec_ecalEnergy);
   fChain->SetBranchAddress("T_Elec_dr03TkSumPt", &T_Elec_dr03TkSumPt, &b_T_Elec_dr03TkSumPt);
   fChain->SetBranchAddress("T_Elec_dr03EcalSumEt", &T_Elec_dr03EcalSumEt, &b_T_Elec_dr03EcalSumEt);
   fChain->SetBranchAddress("T_Elec_dr03HcalSumEt", &T_Elec_dr03HcalSumEt, &b_T_Elec_dr03HcalSumEt);
   fChain->SetBranchAddress("T_Elec_isEB", &T_Elec_isEB, &b_T_Elec_isEB);
   fChain->SetBranchAddress("T_Elec_isEE", &T_Elec_isEE, &b_T_Elec_isEE);
   fChain->SetBranchAddress("T_Elec_chargedHadronIso", &T_Elec_chargedHadronIso, &b_T_Elec_chargedHadronIso);
   fChain->SetBranchAddress("T_Elec_neutralHadronIso", &T_Elec_neutralHadronIso, &b_T_Elec_neutralHadronIso);
   fChain->SetBranchAddress("T_Elec_neutralIsoPFweight", &T_Elec_neutralIsoPFweight, &b_T_Elec_neutralIsoPFweight);
   fChain->SetBranchAddress("T_Elec_neutralIsoPUPPI", &T_Elec_neutralIsoPUPPI, &b_T_Elec_neutralIsoPUPPI);
   fChain->SetBranchAddress("T_Elec_photonIso", &T_Elec_photonIso, &b_T_Elec_photonIso);
   fChain->SetBranchAddress("T_Elec_puChargedHadronIso", &T_Elec_puChargedHadronIso, &b_T_Elec_puChargedHadronIso);
   fChain->SetBranchAddress("T_Elec_sumChargedHadronPt", &T_Elec_sumChargedHadronPt, &b_T_Elec_sumChargedHadronPt);
   fChain->SetBranchAddress("T_Elec_sumNeutralHadronEt", &T_Elec_sumNeutralHadronEt, &b_T_Elec_sumNeutralHadronEt);
   fChain->SetBranchAddress("T_Elec_sumPhotonEt", &T_Elec_sumPhotonEt, &b_T_Elec_sumPhotonEt);
   fChain->SetBranchAddress("T_Elec_sumPUPt", &T_Elec_sumPUPt, &b_T_Elec_sumPUPt);
   fChain->SetBranchAddress("T_Elec_passConversionVeto", &T_Elec_passConversionVeto, &b_T_Elec_passConversionVeto);
   fChain->SetBranchAddress("T_Elec_hasMatchedConversion", &T_Elec_hasMatchedConversion, &b_T_Elec_hasMatchedConversion);
   fChain->SetBranchAddress("T_Elec_sigmaIetaIeta", &T_Elec_sigmaIetaIeta, &b_T_Elec_sigmaIetaIeta);
   fChain->SetBranchAddress("T_Elec_sigmaIetaIetaFull5by5", &T_Elec_sigmaIetaIetaFull5by5, &b_T_Elec_sigmaIetaIetaFull5by5);
   fChain->SetBranchAddress("T_Elec_deltaPhiIn", &T_Elec_deltaPhiIn, &b_T_Elec_deltaPhiIn);
   fChain->SetBranchAddress("T_Elec_deltaEtaIn", &T_Elec_deltaEtaIn, &b_T_Elec_deltaEtaIn);
   fChain->SetBranchAddress("T_Elec_isEcalDriven", &T_Elec_isEcalDriven, &b_T_Elec_isEcalDriven);
   fChain->SetBranchAddress("T_Elec_HtoE", &T_Elec_HtoE, &b_T_Elec_HtoE);
   fChain->SetBranchAddress("T_Elec_vz", &T_Elec_vz, &b_T_Elec_vz);
   fChain->SetBranchAddress("T_Elec_vy", &T_Elec_vy, &b_T_Elec_vy);
   fChain->SetBranchAddress("T_Elec_vx", &T_Elec_vx, &b_T_Elec_vx);
   fChain->SetBranchAddress("T_Elec_nLost", &T_Elec_nLost, &b_T_Elec_nLost);
   fChain->SetBranchAddress("T_Elec_nHits", &T_Elec_nHits, &b_T_Elec_nHits);
   fChain->SetBranchAddress("T_Elec_SC_Et", &T_Elec_SC_Et, &b_T_Elec_SC_Et);
   fChain->SetBranchAddress("T_Elec_SC_Eta", &T_Elec_SC_Eta, &b_T_Elec_SC_Eta);
   fChain->SetBranchAddress("T_Elec_PFElecPt", &T_Elec_PFElecPt, &b_T_Elec_PFElecPt);
   fChain->SetBranchAddress("T_Elec_PFElecPx", &T_Elec_PFElecPx, &b_T_Elec_PFElecPx);
   fChain->SetBranchAddress("T_Elec_PFElecPy", &T_Elec_PFElecPy, &b_T_Elec_PFElecPy);
   fChain->SetBranchAddress("T_Elec_PFElecPz", &T_Elec_PFElecPz, &b_T_Elec_PFElecPz);
   fChain->SetBranchAddress("T_Elec_PFElecE", &T_Elec_PFElecE, &b_T_Elec_PFElecE);
   fChain->SetBranchAddress("T_Elec_isPF", &T_Elec_isPF, &b_T_Elec_isPF);
   fChain->SetBranchAddress("T_Elec_MVAoutput", &T_Elec_MVAoutput, &b_T_Elec_MVAoutput);
   fChain->SetBranchAddress("T_JetAKCHS_Px", &T_JetAKCHS_Px, &b_T_JetAKCHS_Px);
   fChain->SetBranchAddress("T_JetAKCHS_Py", &T_JetAKCHS_Py, &b_T_JetAKCHS_Py);
   fChain->SetBranchAddress("T_JetAKCHS_Pz", &T_JetAKCHS_Pz, &b_T_JetAKCHS_Pz);
   fChain->SetBranchAddress("T_JetAKCHS_Et", &T_JetAKCHS_Et, &b_T_JetAKCHS_Et);
   fChain->SetBranchAddress("T_JetAKCHS_Eta", &T_JetAKCHS_Eta, &b_T_JetAKCHS_Eta);
   fChain->SetBranchAddress("T_JetAKCHS_Energy", &T_JetAKCHS_Energy, &b_T_JetAKCHS_Energy);
   fChain->SetBranchAddress("T_JetAKCHS_Corr", &T_JetAKCHS_Corr, &b_T_JetAKCHS_Corr);
   fChain->SetBranchAddress("T_JetAKCHS_Tag_HighEffTC", &T_JetAKCHS_Tag_HighEffTC, &b_T_JetAKCHS_Tag_HighEffTC);
   fChain->SetBranchAddress("T_JetAKCHS_Tag_CombInclusiveSVtxV2", &T_JetAKCHS_Tag_CombInclusiveSVtxV2, &b_T_JetAKCHS_Tag_CombInclusiveSVtxV2);
   fChain->SetBranchAddress("T_JetAKCHS_Tag_CombMVA", &T_JetAKCHS_Tag_CombMVA, &b_T_JetAKCHS_Tag_CombMVA);
   fChain->SetBranchAddress("T_JetAKCHS_Tag_CombSVtx", &T_JetAKCHS_Tag_CombSVtx, &b_T_JetAKCHS_Tag_CombSVtx);
   fChain->SetBranchAddress("T_JetAKCHS_Tag_pfCombinedSVtx", &T_JetAKCHS_Tag_pfCombinedSVtx, &b_T_JetAKCHS_Tag_pfCombinedSVtx);
   fChain->SetBranchAddress("T_JetAKCHS_Tag_JetBProb", &T_JetAKCHS_Tag_JetBProb, &b_T_JetAKCHS_Tag_JetBProb);
   fChain->SetBranchAddress("T_JetAKCHS_Tag_JetProb", &T_JetAKCHS_Tag_JetProb, &b_T_JetAKCHS_Tag_JetProb);
   fChain->SetBranchAddress("T_JetAKCHS_Tag_HighEffSimpSVtx", &T_JetAKCHS_Tag_HighEffSimpSVtx, &b_T_JetAKCHS_Tag_HighEffSimpSVtx);
   fChain->SetBranchAddress("T_JetAKCHS_Tag_HighPurSimpSVtx", &T_JetAKCHS_Tag_HighPurSimpSVtx, &b_T_JetAKCHS_Tag_HighPurSimpSVtx);
   fChain->SetBranchAddress("T_JetAKCHS_Tag_HighPurTC", &T_JetAKCHS_Tag_HighPurTC, &b_T_JetAKCHS_Tag_HighPurTC);
   fChain->SetBranchAddress("T_JetAKCHS_Parton_Px", &T_JetAKCHS_Parton_Px, &b_T_JetAKCHS_Parton_Px);
   fChain->SetBranchAddress("T_JetAKCHS_Parton_Py", &T_JetAKCHS_Parton_Py, &b_T_JetAKCHS_Parton_Py);
   fChain->SetBranchAddress("T_JetAKCHS_Parton_Pz", &T_JetAKCHS_Parton_Pz, &b_T_JetAKCHS_Parton_Pz);
   fChain->SetBranchAddress("T_JetAKCHS_Parton_Energy", &T_JetAKCHS_Parton_Energy, &b_T_JetAKCHS_Parton_Energy);
   fChain->SetBranchAddress("T_JetAKCHS_Parton_Flavour", &T_JetAKCHS_Parton_Flavour, &b_T_JetAKCHS_Parton_Flavour);
   fChain->SetBranchAddress("T_JetAKCHS_Uncertainty", &T_JetAKCHS_Uncertainty, &b_T_JetAKCHS_Uncertainty);
   fChain->SetBranchAddress("T_JetAKCHS_PileupPt", &T_JetAKCHS_PileupPt, &b_T_JetAKCHS_PileupPt);
   fChain->SetBranchAddress("T_JetAKCHS_MPFInSitu", &T_JetAKCHS_MPFInSitu, &b_T_JetAKCHS_MPFInSitu);
   fChain->SetBranchAddress("T_JetAKCHS_bJES", &T_JetAKCHS_bJES, &b_T_JetAKCHS_bJES);
   fChain->SetBranchAddress("T_JetAKCHS_Flavor", &T_JetAKCHS_Flavor, &b_T_JetAKCHS_Flavor);
   fChain->SetBranchAddress("T_JetAKCHS_Intercalibration", &T_JetAKCHS_Intercalibration, &b_T_JetAKCHS_Intercalibration);
   fChain->SetBranchAddress("T_JetAKCHS_Uncorrelated", &T_JetAKCHS_Uncorrelated, &b_T_JetAKCHS_Uncorrelated);
   fChain->SetBranchAddress("T_JetAKCHS_MuonEnergyFrac", &T_JetAKCHS_MuonEnergyFrac, &b_T_JetAKCHS_MuonEnergyFrac);
   fChain->SetBranchAddress("T_JetAKCHS_CharHadEnergyFrac", &T_JetAKCHS_CharHadEnergyFrac, &b_T_JetAKCHS_CharHadEnergyFrac);
   fChain->SetBranchAddress("T_JetAKCHS_NeutHadEnergyFrac", &T_JetAKCHS_NeutHadEnergyFrac, &b_T_JetAKCHS_NeutHadEnergyFrac);
   fChain->SetBranchAddress("T_JetAKCHS_CharEmEnergyFrac", &T_JetAKCHS_CharEmEnergyFrac, &b_T_JetAKCHS_CharEmEnergyFrac);
   fChain->SetBranchAddress("T_JetAKCHS_NeutEmEnergyFrac", &T_JetAKCHS_NeutEmEnergyFrac, &b_T_JetAKCHS_NeutEmEnergyFrac);
   fChain->SetBranchAddress("T_JetAKCHS_CharHadEnergy", &T_JetAKCHS_CharHadEnergy, &b_T_JetAKCHS_CharHadEnergy);
   fChain->SetBranchAddress("T_JetAKCHS_NeutHadEnergy", &T_JetAKCHS_NeutHadEnergy, &b_T_JetAKCHS_NeutHadEnergy);
   fChain->SetBranchAddress("T_JetAKCHS_CharEmEnergy", &T_JetAKCHS_CharEmEnergy, &b_T_JetAKCHS_CharEmEnergy);
   fChain->SetBranchAddress("T_JetAKCHS_NeutEmEnergy", &T_JetAKCHS_NeutEmEnergy, &b_T_JetAKCHS_NeutEmEnergy);
   fChain->SetBranchAddress("T_JetAKCHS_MuonMultiplicity", &T_JetAKCHS_MuonMultiplicity, &b_T_JetAKCHS_MuonMultiplicity);
   fChain->SetBranchAddress("T_JetAKCHS_NeutralMultiplicity", &T_JetAKCHS_NeutralMultiplicity, &b_T_JetAKCHS_NeutralMultiplicity);
   fChain->SetBranchAddress("T_JetAKCHS_ChargedMultiplicity", &T_JetAKCHS_ChargedMultiplicity, &b_T_JetAKCHS_ChargedMultiplicity);
   fChain->SetBranchAddress("T_JetAKCHS_nDaughters", &T_JetAKCHS_nDaughters, &b_T_JetAKCHS_nDaughters);
   fChain->SetBranchAddress("T_JetAKCHS_IDLoose", &T_JetAKCHS_IDLoose, &b_T_JetAKCHS_IDLoose);
   fChain->SetBranchAddress("T_JetAKCHS_GenJet_InvisibleE", &T_JetAKCHS_GenJet_InvisibleE, &b_T_JetAKCHS_GenJet_InvisibleE);
   fChain->SetBranchAddress("T_JetAKCHS_GenJet_Px", &T_JetAKCHS_GenJet_Px, &b_T_JetAKCHS_GenJet_Px);
   fChain->SetBranchAddress("T_JetAKCHS_GenJet_Py", &T_JetAKCHS_GenJet_Py, &b_T_JetAKCHS_GenJet_Py);
   fChain->SetBranchAddress("T_JetAKCHS_GenJet_Pz", &T_JetAKCHS_GenJet_Pz, &b_T_JetAKCHS_GenJet_Pz);
   fChain->SetBranchAddress("T_JetAKCHS_GenJet_Et", &T_JetAKCHS_GenJet_Et, &b_T_JetAKCHS_GenJet_Et);
   fChain->SetBranchAddress("T_JetAKCHS_GenJet_Eta", &T_JetAKCHS_GenJet_Eta, &b_T_JetAKCHS_GenJet_Eta);
   fChain->SetBranchAddress("T_JetAKCHS_GenJet_Energy", &T_JetAKCHS_GenJet_Energy, &b_T_JetAKCHS_GenJet_Energy);
   fChain->SetBranchAddress("T_JetAKCHS_IsGenJet", &T_JetAKCHS_IsGenJet, &b_T_JetAKCHS_IsGenJet);
   fChain->SetBranchAddress("T_MET_Significance", &T_MET_Significance, &b_T_MET_Significance);
   fChain->SetBranchAddress("T_MET_ET", &T_MET_ET, &b_T_MET_ET);
   fChain->SetBranchAddress("T_MET_ET_JetEnUp", &T_MET_ET_JetEnUp, &b_T_MET_ET_JetEnUp);
   fChain->SetBranchAddress("T_MET_ET_JetEnDown", &T_MET_ET_JetEnDown, &b_T_MET_ET_JetEnDown);
   fChain->SetBranchAddress("T_MET_ET_JetResUp", &T_MET_ET_JetResUp, &b_T_MET_ET_JetResUp);
   fChain->SetBranchAddress("T_MET_ET_JetResDown", &T_MET_ET_JetResDown, &b_T_MET_ET_JetResDown);
   fChain->SetBranchAddress("T_MET_ET_MuonEnUp", &T_MET_ET_MuonEnUp, &b_T_MET_ET_MuonEnUp);
   fChain->SetBranchAddress("T_MET_ET_MuonEnDown", &T_MET_ET_MuonEnDown, &b_T_MET_ET_MuonEnDown);
   fChain->SetBranchAddress("T_MET_ET_ElectronEnUp", &T_MET_ET_ElectronEnUp, &b_T_MET_ET_ElectronEnUp);
   fChain->SetBranchAddress("T_MET_ET_ElectronEnDown", &T_MET_ET_ElectronEnDown, &b_T_MET_ET_ElectronEnDown);
   fChain->SetBranchAddress("T_MET_ET_TauEnUp", &T_MET_ET_TauEnUp, &b_T_MET_ET_TauEnUp);
   fChain->SetBranchAddress("T_MET_ET_TauEnDown", &T_MET_ET_TauEnDown, &b_T_MET_ET_TauEnDown);
   fChain->SetBranchAddress("T_MET_ET_UnclusteredEnUp", &T_MET_ET_UnclusteredEnUp, &b_T_MET_ET_UnclusteredEnUp);
   fChain->SetBranchAddress("T_MET_ET_UnclusteredEnDown", &T_MET_ET_UnclusteredEnDown, &b_T_MET_ET_UnclusteredEnDown);
   fChain->SetBranchAddress("T_MET_Phi", &T_MET_Phi, &b_T_MET_Phi);
   fChain->SetBranchAddress("T_MET_Phi_JetEnUp", &T_MET_Phi_JetEnUp, &b_T_MET_Phi_JetEnUp);
   fChain->SetBranchAddress("T_MET_Phi_JetEnDown", &T_MET_Phi_JetEnDown, &b_T_MET_Phi_JetEnDown);
   fChain->SetBranchAddress("T_MET_Phi_JetResUp", &T_MET_Phi_JetResUp, &b_T_MET_Phi_JetResUp);
   fChain->SetBranchAddress("T_MET_Phi_JetResDown", &T_MET_Phi_JetResDown, &b_T_MET_Phi_JetResDown);
   fChain->SetBranchAddress("T_MET_Phi_MuonEnUp", &T_MET_Phi_MuonEnUp, &b_T_MET_Phi_MuonEnUp);
   fChain->SetBranchAddress("T_MET_Phi_MuonEnDown", &T_MET_Phi_MuonEnDown, &b_T_MET_Phi_MuonEnDown);
   fChain->SetBranchAddress("T_MET_Phi_ElectronEnUp", &T_MET_Phi_ElectronEnUp, &b_T_MET_Phi_ElectronEnUp);
   fChain->SetBranchAddress("T_MET_Phi_ElectronEnDown", &T_MET_Phi_ElectronEnDown, &b_T_MET_Phi_ElectronEnDown);
   fChain->SetBranchAddress("T_MET_Phi_TauEnUp", &T_MET_Phi_TauEnUp, &b_T_MET_Phi_TauEnUp);
   fChain->SetBranchAddress("T_MET_Phi_TauEnDown", &T_MET_Phi_TauEnDown, &b_T_MET_Phi_TauEnDown);
   fChain->SetBranchAddress("T_MET_Phi_UnclusteredEnUp", &T_MET_Phi_UnclusteredEnUp, &b_T_MET_Phi_UnclusteredEnUp);
   fChain->SetBranchAddress("T_MET_Phi_UnclusteredEnDown", &T_MET_Phi_UnclusteredEnDown, &b_T_MET_Phi_UnclusteredEnDown);
   fChain->SetBranchAddress("T_METgen_ET", &T_METgen_ET, &b_T_METgen_ET);
   fChain->SetBranchAddress("T_METgen_Phi", &T_METgen_Phi, &b_T_METgen_Phi);
   fChain->SetBranchAddress("T_passTriggerDoubleMu", &T_passTriggerDoubleMu, &b_T_passTriggerDoubleMu);
   fChain->SetBranchAddress("T_passTriggerDoubleEl", &T_passTriggerDoubleEl, &b_T_passTriggerDoubleEl);
   fChain->SetBranchAddress("T_passTriggerSingleMu", &T_passTriggerSingleMu, &b_T_passTriggerSingleMu);
   fChain->SetBranchAddress("T_passTriggerSingleEl", &T_passTriggerSingleEl, &b_T_passTriggerSingleEl);
   fChain->SetBranchAddress("T_passTriggerElMu", &T_passTriggerElMu, &b_T_passTriggerElMu);

   nentries = fChain->GetEntries();

   Notify();
}

Bool_t FIVEns::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void FIVEns::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t FIVEns::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef FIVEns_cxx
