//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Nov  5 06:50:59 2014 by ROOT version 5.32/00
// from TTree AnalysisTree/AnalysisTree
// found on file: /eos/uscms/store/user/awhitbe1/SuSySubstructureAnalysisNtuples_V10/TTJets_SemiLeptMGDecays_LPCSUSYPAT_SLIM_44_SumJetMass_AnalysisTree.root
//////////////////////////////////////////////////////////

#ifndef Data_h
#define Data_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.
using namespace std;


class Data {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   Long64_t nentries;

   // Declaration of leaf types
   Int_t           event;
   Int_t           run;
   Int_t           lumi;
   Int_t           nVrtx;
   Double_t        MET;
   Double_t        METsig;
   vector<double>  *electronPt;
   vector<double>  *electronEta;
   vector<double>  *electronPhi;
   vector<double>  *electronE;
   vector<double>  *electronsRelIso;
   vector<bool>    *electronPassID;
   Int_t           NElectrons;
   vector<double>  *muonPt;
   vector<double>  *muonEta;
   vector<double>  *muonPhi;
   vector<double>  *muonE;
   vector<double>  *muonRelIso;
   vector<bool>    *muonPassID;
   Int_t           NMuons;
   vector<double>  *photonPt;
   vector<double>  *photonEta;
   vector<double>  *photonPhi;
   vector<double>  *photonE;
   vector<double>  *photon_hadTowOverEm;
   vector<double>  *photon_sigmaIetaIeta;
   vector<double>  *photon_pfChargedIso;
   vector<double>  *photon_pfNeutralIso;
   vector<double>  *photon_pfGammaIso;
   vector<bool>    *photon_passElectronConvVeto;
   vector<double>  *pt_patJetsAK5PFPt30;
   vector<double>  *eta_patJetsAK5PFPt30;
   vector<double>  *mass_patJetsAK5PFPt30;
   vector<double>  *phi_patJetsAK5PFPt30;
   Int_t           NJets_patJetsAK5PFPt30;
   Double_t        sumJetMass_patJetsAK5PFPt30;
   Double_t        MHT_patJetsAK5PFPt30;
   Double_t        MHTphi_patJetsAK5PFPt30;
   Double_t        HT_patJetsAK5PFPt30;
   vector<double>  *pt_patJetsAK5PFPt50Eta25;
   vector<double>  *eta_patJetsAK5PFPt50Eta25;
   vector<double>  *mass_patJetsAK5PFPt50Eta25;
   vector<double>  *phi_patJetsAK5PFPt50Eta25;
   Int_t           NJets_patJetsAK5PFPt50Eta25;
   Double_t        sumJetMass_patJetsAK5PFPt50Eta25;
   Double_t        MHT_patJetsAK5PFPt50Eta25;
   Double_t        MHTphi_patJetsAK5PFPt50Eta25;
   Double_t        HT_patJetsAK5PFPt50Eta25;
   vector<double>  *pt_ak1p2Jets;
   vector<double>  *eta_ak1p2Jets;
   vector<double>  *mass_ak1p2Jets;
   vector<double>  *phi_ak1p2Jets;
   Int_t           NJets_ak1p2Jets;
   Double_t        sumJetMass_ak1p2Jets;
   Double_t        MHT_ak1p2Jets;
   Double_t        MHTphi_ak1p2Jets;
   Double_t        HT_ak1p2Jets;
   vector<double>  *pt_fatJetSubjets;
   vector<double>  *eta_fatJetSubjets;
   vector<double>  *mass_fatJetSubjets;
   vector<double>  *phi_fatJetSubjets;
   Int_t           NJets_fatJetSubjets;
   Double_t        sumJetMass_fatJetSubjets;
   Double_t        MHT_fatJetSubjets;
   Double_t        MHTphi_fatJetSubjets;
   Double_t        HT_fatJetSubjets;
   vector<double>  *pt_fattenedJets;
   vector<double>  *eta_fattenedJets;
   vector<double>  *mass_fattenedJets;
   vector<double>  *phi_fattenedJets;
   Int_t           NJets_fattenedJets;
   Double_t        sumJetMass_fattenedJets;
   Double_t        MHT_fattenedJets;
   Double_t        MHTphi_fattenedJets;
   Double_t        HT_fattenedJets;
   Double_t        eventWeight;

   // List of branches
   TBranch        *b_event;   //!
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_nVrtx;   //!
   TBranch        *b_MET;   //!
   TBranch        *b_METsig;   //!
   TBranch        *b_electronPt;   //!
   TBranch        *b_electronEta;   //!
   TBranch        *b_electronPhi;   //!
   TBranch        *b_electronE;   //!
   TBranch        *b_electronsRelIso;   //!
   TBranch        *b_electronPassID;   //!
   TBranch        *b_NElectrons;   //!
   TBranch        *b_muonPt;   //!
   TBranch        *b_muonEta;   //!
   TBranch        *b_muonPhi;   //!
   TBranch        *b_muonE;   //!
   TBranch        *b_muonRelIso;   //!
   TBranch        *b_muonPassID;   //!
   TBranch        *b_NMuons;   //!
   TBranch        *b_photonPt;   //!
   TBranch        *b_photonEta;   //!
   TBranch        *b_photonPhi;   //!
   TBranch        *b_photonE;   //!
   TBranch        *b_photon_hadTowOverEm;   //!
   TBranch        *b_photon_sigmaIetaIeta;   //!
   TBranch        *b_photon_pfChargedIso;   //!
   TBranch        *b_photon_pfNeutralIso;   //!
   TBranch        *b_photon_pfGammaIso;   //!
   TBranch        *b_photon_passElectronConvVeto;   //!
   TBranch        *b_pt_patJetsAK5PFPt30;   //!
   TBranch        *b_eta_patJetsAK5PFPt30;   //!
   TBranch        *b_mass_patJetsAK5PFPt30;   //!
   TBranch        *b_phi_patJetsAK5PFPt30;   //!
   TBranch        *b_NJets_patJetsAK5PFPt30;   //!
   TBranch        *b_sumJetMass_patJetsAK5PFPt30;   //!
   TBranch        *b_MHT_patJetsAK5PFPt30;   //!
   TBranch        *b_MHTphi_patJetsAK5PFPt30;   //!
   TBranch        *b_HT_patJetsAK5PFPt30;   //!
   TBranch        *b_pt_patJetsAK5PFPt50Eta25;   //!
   TBranch        *b_eta_patJetsAK5PFPt50Eta25;   //!
   TBranch        *b_mass_patJetsAK5PFPt50Eta25;   //!
   TBranch        *b_phi_patJetsAK5PFPt50Eta25;   //!
   TBranch        *b_NJets_patJetsAK5PFPt50Eta25;   //!
   TBranch        *b_sumJetMass_patJetsAK5PFPt50Eta25;   //!
   TBranch        *b_MHT_patJetsAK5PFPt50Eta25;   //!
   TBranch        *b_MHTphi_patJetsAK5PFPt50Eta25;   //!
   TBranch        *b_HT_patJetsAK5PFPt50Eta25;   //!
   TBranch        *b_pt_ak1p2Jets;   //!
   TBranch        *b_eta_ak1p2Jets;   //!
   TBranch        *b_mass_ak1p2Jets;   //!
   TBranch        *b_phi_ak1p2Jets;   //!
   TBranch        *b_NJets_ak1p2Jets;   //!
   TBranch        *b_sumJetMass_ak1p2Jets;   //!
   TBranch        *b_MHT_ak1p2Jets;   //!
   TBranch        *b_MHTphi_ak1p2Jets;   //!
   TBranch        *b_HT_ak1p2Jets;   //!
   TBranch        *b_pt_fatJetSubjets;   //!
   TBranch        *b_eta_fatJetSubjets;   //!
   TBranch        *b_mass_fatJetSubjets;   //!
   TBranch        *b_phi_fatJetSubjets;   //!
   TBranch        *b_NJets_fatJetSubjets;   //!
   TBranch        *b_sumJetMass_fatJetSubjets;   //!
   TBranch        *b_MHT_fatJetSubjets;   //!
   TBranch        *b_MHTphi_fatJetSubjets;   //!
   TBranch        *b_HT_fatJetSubjets;   //!
   TBranch        *b_pt_fattenedJets;   //!
   TBranch        *b_eta_fattenedJets;   //!
   TBranch        *b_mass_fattenedJets;   //!
   TBranch        *b_phi_fattenedJets;   //!
   TBranch        *b_NJets_fattenedJets;   //!
   TBranch        *b_sumJetMass_fattenedJets;   //!
   TBranch        *b_MHT_fattenedJets;   //!
   TBranch        *b_MHTphi_fattenedJets;   //!
   TBranch        *b_HT_fattenedJets;   //!
   TBranch        *b_eventWeight;   //!

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
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/uscms/store/user/awhitbe1/SuSySubstructureAnalysisNtuples_V10/TTJets_SemiLeptMGDecays_LPCSUSYPAT_SLIM_44_SumJetMass_AnalysisTree.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/eos/uscms/store/user/awhitbe1/SuSySubstructureAnalysisNtuples_V10/TTJets_SemiLeptMGDecays_LPCSUSYPAT_SLIM_44_SumJetMass_AnalysisTree.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/eos/uscms/store/user/awhitbe1/SuSySubstructureAnalysisNtuples_V10/TTJets_SemiLeptMGDecays_LPCSUSYPAT_SLIM_44_SumJetMass_AnalysisTree.root:/TreeFiller");
      dir->GetObject("AnalysisTree",tree);

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

   // Set object pointer
   electronPt = 0;
   electronEta = 0;
   electronPhi = 0;
   electronE = 0;
   electronsRelIso = 0;
   electronPassID = 0;
   muonPt = 0;
   muonEta = 0;
   muonPhi = 0;
   muonE = 0;
   muonRelIso = 0;
   muonPassID = 0;
   photonPt = 0;
   photonEta = 0;
   photonPhi = 0;
   photonE = 0;
   photon_hadTowOverEm = 0;
   photon_sigmaIetaIeta = 0;
   photon_pfChargedIso = 0;
   photon_pfNeutralIso = 0;
   photon_pfGammaIso = 0;
   photon_passElectronConvVeto = 0;
   pt_patJetsAK5PFPt30 = 0;
   eta_patJetsAK5PFPt30 = 0;
   mass_patJetsAK5PFPt30 = 0;
   phi_patJetsAK5PFPt30 = 0;
   pt_patJetsAK5PFPt50Eta25 = 0;
   eta_patJetsAK5PFPt50Eta25 = 0;
   mass_patJetsAK5PFPt50Eta25 = 0;
   phi_patJetsAK5PFPt50Eta25 = 0;
   pt_ak1p2Jets = 0;
   eta_ak1p2Jets = 0;
   mass_ak1p2Jets = 0;
   phi_ak1p2Jets = 0;
   pt_fatJetSubjets = 0;
   eta_fatJetSubjets = 0;
   mass_fatJetSubjets = 0;
   phi_fatJetSubjets = 0;
   pt_fattenedJets = 0;
   eta_fattenedJets = 0;
   mass_fattenedJets = 0;
   phi_fattenedJets = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("nVrtx", &nVrtx, &b_nVrtx);
   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("METsig", &METsig, &b_METsig);
   fChain->SetBranchAddress("electronPt", &electronPt, &b_electronPt);
   fChain->SetBranchAddress("electronEta", &electronEta, &b_electronEta);
   fChain->SetBranchAddress("electronPhi", &electronPhi, &b_electronPhi);
   fChain->SetBranchAddress("electronE", &electronE, &b_electronE);
   fChain->SetBranchAddress("electronsRelIso", &electronsRelIso, &b_electronsRelIso);
   fChain->SetBranchAddress("electronPassID", &electronPassID, &b_electronPassID);
   fChain->SetBranchAddress("NElectrons", &NElectrons, &b_NElectrons);
   fChain->SetBranchAddress("muonPt", &muonPt, &b_muonPt);
   fChain->SetBranchAddress("muonEta", &muonEta, &b_muonEta);
   fChain->SetBranchAddress("muonPhi", &muonPhi, &b_muonPhi);
   fChain->SetBranchAddress("muonE", &muonE, &b_muonE);
   fChain->SetBranchAddress("muonRelIso", &muonRelIso, &b_muonRelIso);
   fChain->SetBranchAddress("muonPassID", &muonPassID, &b_muonPassID);
   fChain->SetBranchAddress("NMuons", &NMuons, &b_NMuons);
   fChain->SetBranchAddress("photonPt", &photonPt, &b_photonPt);
   fChain->SetBranchAddress("photonEta", &photonEta, &b_photonEta);
   fChain->SetBranchAddress("photonPhi", &photonPhi, &b_photonPhi);
   fChain->SetBranchAddress("photonE", &photonE, &b_photonE);
   fChain->SetBranchAddress("photon_hadTowOverEm", &photon_hadTowOverEm, &b_photon_hadTowOverEm);
   fChain->SetBranchAddress("photon_sigmaIetaIeta", &photon_sigmaIetaIeta, &b_photon_sigmaIetaIeta);
   fChain->SetBranchAddress("photon_pfChargedIso", &photon_pfChargedIso, &b_photon_pfChargedIso);
   fChain->SetBranchAddress("photon_pfNeutralIso", &photon_pfNeutralIso, &b_photon_pfNeutralIso);
   fChain->SetBranchAddress("photon_pfGammaIso", &photon_pfGammaIso, &b_photon_pfGammaIso);
   fChain->SetBranchAddress("photon_passElectronConvVeto", &photon_passElectronConvVeto, &b_photon_passElectronConvVeto);
   fChain->SetBranchAddress("pt_patJetsAK5PFPt30", &pt_patJetsAK5PFPt30, &b_pt_patJetsAK5PFPt30);
   fChain->SetBranchAddress("eta_patJetsAK5PFPt30", &eta_patJetsAK5PFPt30, &b_eta_patJetsAK5PFPt30);
   fChain->SetBranchAddress("mass_patJetsAK5PFPt30", &mass_patJetsAK5PFPt30, &b_mass_patJetsAK5PFPt30);
   fChain->SetBranchAddress("phi_patJetsAK5PFPt30", &phi_patJetsAK5PFPt30, &b_phi_patJetsAK5PFPt30);
   fChain->SetBranchAddress("NJets_patJetsAK5PFPt30", &NJets_patJetsAK5PFPt30, &b_NJets_patJetsAK5PFPt30);
   fChain->SetBranchAddress("sumJetMass_patJetsAK5PFPt30", &sumJetMass_patJetsAK5PFPt30, &b_sumJetMass_patJetsAK5PFPt30);
   fChain->SetBranchAddress("MHT_patJetsAK5PFPt30", &MHT_patJetsAK5PFPt30, &b_MHT_patJetsAK5PFPt30);
   fChain->SetBranchAddress("MHTphi_patJetsAK5PFPt30", &MHTphi_patJetsAK5PFPt30, &b_MHTphi_patJetsAK5PFPt30);
   fChain->SetBranchAddress("HT_patJetsAK5PFPt30", &HT_patJetsAK5PFPt30, &b_HT_patJetsAK5PFPt30);
   fChain->SetBranchAddress("pt_patJetsAK5PFPt50Eta25", &pt_patJetsAK5PFPt50Eta25, &b_pt_patJetsAK5PFPt50Eta25);
   fChain->SetBranchAddress("eta_patJetsAK5PFPt50Eta25", &eta_patJetsAK5PFPt50Eta25, &b_eta_patJetsAK5PFPt50Eta25);
   fChain->SetBranchAddress("mass_patJetsAK5PFPt50Eta25", &mass_patJetsAK5PFPt50Eta25, &b_mass_patJetsAK5PFPt50Eta25);
   fChain->SetBranchAddress("phi_patJetsAK5PFPt50Eta25", &phi_patJetsAK5PFPt50Eta25, &b_phi_patJetsAK5PFPt50Eta25);
   fChain->SetBranchAddress("NJets_patJetsAK5PFPt50Eta25", &NJets_patJetsAK5PFPt50Eta25, &b_NJets_patJetsAK5PFPt50Eta25);
   fChain->SetBranchAddress("sumJetMass_patJetsAK5PFPt50Eta25", &sumJetMass_patJetsAK5PFPt50Eta25, &b_sumJetMass_patJetsAK5PFPt50Eta25);
   fChain->SetBranchAddress("MHT_patJetsAK5PFPt50Eta25", &MHT_patJetsAK5PFPt50Eta25, &b_MHT_patJetsAK5PFPt50Eta25);
   fChain->SetBranchAddress("MHTphi_patJetsAK5PFPt50Eta25", &MHTphi_patJetsAK5PFPt50Eta25, &b_MHTphi_patJetsAK5PFPt50Eta25);
   fChain->SetBranchAddress("HT_patJetsAK5PFPt50Eta25", &HT_patJetsAK5PFPt50Eta25, &b_HT_patJetsAK5PFPt50Eta25);
   fChain->SetBranchAddress("pt_ak1p2Jets", &pt_ak1p2Jets, &b_pt_ak1p2Jets);
   fChain->SetBranchAddress("eta_ak1p2Jets", &eta_ak1p2Jets, &b_eta_ak1p2Jets);
   fChain->SetBranchAddress("mass_ak1p2Jets", &mass_ak1p2Jets, &b_mass_ak1p2Jets);
   fChain->SetBranchAddress("phi_ak1p2Jets", &phi_ak1p2Jets, &b_phi_ak1p2Jets);
   fChain->SetBranchAddress("NJets_ak1p2Jets", &NJets_ak1p2Jets, &b_NJets_ak1p2Jets);
   fChain->SetBranchAddress("sumJetMass_ak1p2Jets", &sumJetMass_ak1p2Jets, &b_sumJetMass_ak1p2Jets);
   fChain->SetBranchAddress("MHT_ak1p2Jets", &MHT_ak1p2Jets, &b_MHT_ak1p2Jets);
   fChain->SetBranchAddress("MHTphi_ak1p2Jets", &MHTphi_ak1p2Jets, &b_MHTphi_ak1p2Jets);
   fChain->SetBranchAddress("HT_ak1p2Jets", &HT_ak1p2Jets, &b_HT_ak1p2Jets);
   fChain->SetBranchAddress("pt_fatJetSubjets", &pt_fatJetSubjets, &b_pt_fatJetSubjets);
   fChain->SetBranchAddress("eta_fatJetSubjets", &eta_fatJetSubjets, &b_eta_fatJetSubjets);
   fChain->SetBranchAddress("mass_fatJetSubjets", &mass_fatJetSubjets, &b_mass_fatJetSubjets);
   fChain->SetBranchAddress("phi_fatJetSubjets", &phi_fatJetSubjets, &b_phi_fatJetSubjets);
   fChain->SetBranchAddress("NJets_fatJetSubjets", &NJets_fatJetSubjets, &b_NJets_fatJetSubjets);
   fChain->SetBranchAddress("sumJetMass_fatJetSubjets", &sumJetMass_fatJetSubjets, &b_sumJetMass_fatJetSubjets);
   fChain->SetBranchAddress("MHT_fatJetSubjets", &MHT_fatJetSubjets, &b_MHT_fatJetSubjets);
   fChain->SetBranchAddress("MHTphi_fatJetSubjets", &MHTphi_fatJetSubjets, &b_MHTphi_fatJetSubjets);
   fChain->SetBranchAddress("HT_fatJetSubjets", &HT_fatJetSubjets, &b_HT_fatJetSubjets);
   fChain->SetBranchAddress("pt_fattenedJets", &pt_fattenedJets, &b_pt_fattenedJets);
   fChain->SetBranchAddress("eta_fattenedJets", &eta_fattenedJets, &b_eta_fattenedJets);
   fChain->SetBranchAddress("mass_fattenedJets", &mass_fattenedJets, &b_mass_fattenedJets);
   fChain->SetBranchAddress("phi_fattenedJets", &phi_fattenedJets, &b_phi_fattenedJets);
   fChain->SetBranchAddress("NJets_fattenedJets", &NJets_fattenedJets, &b_NJets_fattenedJets);
   fChain->SetBranchAddress("sumJetMass_fattenedJets", &sumJetMass_fattenedJets, &b_sumJetMass_fattenedJets);
   fChain->SetBranchAddress("MHT_fattenedJets", &MHT_fattenedJets, &b_MHT_fattenedJets);
   fChain->SetBranchAddress("MHTphi_fattenedJets", &MHTphi_fattenedJets, &b_MHTphi_fattenedJets);
   fChain->SetBranchAddress("HT_fattenedJets", &HT_fattenedJets, &b_HT_fattenedJets);
   fChain->SetBranchAddress("eventWeight", &eventWeight, &b_eventWeight);

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
