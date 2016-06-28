//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon May 16 18:26:09 2016 by ROOT version 5.34/02
// from TTree sTopTree/Optimization tree
// found on file: trees/TTJets_tree_5.root
//////////////////////////////////////////////////////////

#ifndef ResolutionTree_h
#define ResolutionTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class ResolutionTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
   Long64_t nentries;

   // Declaration of leaf types
   Float_t         TWeight;
   Int_t           TNPV;
   Float_t         TMET;
   Float_t         TMET_Phi;
   Float_t         TMT2ll;
   Float_t         TMT2bb;
   Float_t         TMT2lblb;
   Float_t         THT;
   Float_t         TMll;
   Float_t         TMeff;
   Float_t         TPtllb;
   Float_t         TdPhiPtllbMET;
   Float_t         TdPhiJetMet;
   Float_t         TdPhiLepMet;
   Float_t         TdPhiLepJet;
   Float_t         TdPhill;
   Float_t         TcosThetap;
   Float_t         TcosThetam;
   Int_t           TNLepSel;
   Int_t           TNJetSel;
   Int_t           TNMuon;
   Int_t           TNElec;
   Int_t           TNJets;
   Int_t           TNJetsBtag;
   Float_t         TJetSel_discriminant[2];   //[TNJetSel]
   Float_t         TJetSel_Px[2];   //[TNJetSel]
   Float_t         TJetSel_Py[2];   //[TNJetSel]
   Float_t         TJetSel_Pz[2];   //[TNJetSel]
   Float_t         TJetSel_E[2];   //[TNJetSel]
   Float_t         TLepSel_Charge[2];   //[TNLepSel]
   Float_t         TLepSel_Px[2];   //[TNLepSel]
   Float_t         TLepSel_Py[2];   //[TNLepSel]
   Float_t         TLepSel_Pz[2];   //[TNLepSel]
   Float_t         TLepSel_E[2];   //[TNLepSel]
   Float_t         TMuon_Charge[2];   //[TNMuon]
   Float_t         TMuon_Px[2];   //[TNMuon]
   Float_t         TMuon_Py[2];   //[TNMuon]
   Float_t         TMuon_Pz[2];   //[TNMuon]
   Float_t         TMuon_E[2];   //[TNMuon]
   Float_t         TElec_Charge[2];   //[TNElec]
   Float_t         TElec_Px[2];   //[TNElec]
   Float_t         TElec_Py[2];   //[TNElec]
   Float_t         TElec_Pz[2];   //[TNElec]
   Float_t         TElec_E[2];   //[TNElec]
   Float_t         TJet_discriminant[14];   //[TNJets]
   Float_t         TJet_Px[14];   //[TNJets]
   Float_t         TJet_Py[14];   //[TNJets]
   Float_t         TJet_Pz[14];   //[TNJets]
   Float_t         TJet_E[14];   //[TNJets]
   Float_t         TBJet_Px[7];   //[TNJetsBtag]
   Float_t         TBJet_Py[7];   //[TNJetsBtag]
   Float_t         TBJet_Pz[7];   //[TNJetsBtag]
   Float_t         TBJet_E[7];   //[TNJetsBtag]
   Int_t           GNMuon;
   Int_t           GNElec;
   Int_t           GNJets;
   Float_t         GMET;
   Float_t         GMET_Phi;
   Float_t         GMT2ll;
   Float_t         GMT2bb;
   Float_t         GMT2lblb;
   Float_t         GJet_discriminant[2];   //[GNJets]
   Float_t         GJet_Px[2];   //[GNJets]
   Float_t         GJet_Py[2];   //[GNJets]
   Float_t         GJet_Pz[2];   //[GNJets]
   Float_t         GJet_E[2];   //[GNJets]
   Float_t         GMuon_Px[3];   //[GNMuon]
   Float_t         GMuon_Py[3];   //[GNMuon]
   Float_t         GMuon_Pz[3];   //[GNMuon]
   Float_t         GMuon_E[3];   //[GNMuon]
   Float_t         GElec_Px[3];   //[GNElec]
   Float_t         GElec_Py[3];   //[GNElec]
   Float_t         GElec_Pz[3];   //[GNElec]
   Float_t         GElec_E[3];   //[GNElec]
   Int_t           HNMuon;
   Int_t           HNElec;
   Int_t           HNJetsBtag;
   Float_t         HMT2ll;
   Float_t         HMT2bb;
   Float_t         HMT2lblb;
   Float_t         HBJet_Px[4];   //[HNJetsBtag]
   Float_t         HBJet_Py[4];   //[HNJetsBtag]
   Float_t         HBJet_Pz[4];   //[HNJetsBtag]
   Float_t         HBJet_E[4];   //[HNJetsBtag]
   Float_t         HMuon_Px[3];   //[HNMuon]
   Float_t         HMuon_Py[3];   //[HNMuon]
   Float_t         HMuon_Pz[3];   //[HNMuon]
   Float_t         HMuon_E[3];   //[HNMuon]
   Float_t         HElec_Px[3];   //[HNElec]
   Float_t         HElec_Py[3];   //[HNElec]
   Float_t         HElec_Pz[3];   //[HNElec]
   Float_t         HElec_E[3];   //[HNElec]

   // List of branches
   TBranch        *b_TWeight;   //!
   TBranch        *b_TNPV;   //!
   TBranch        *b_TMET;   //!
   TBranch        *b_TMET_Phi;   //!
   TBranch        *b_TMT2ll;   //!
   TBranch        *b_TMT2bb;   //!
   TBranch        *b_TMT2lblb;   //!
   TBranch        *b_THT;   //!
   TBranch        *b_TMll;   //!
   TBranch        *b_TMeff;   //!
   TBranch        *b_TPtllb;   //!
   TBranch        *b_TdPhiPtllbMET;   //!
   TBranch        *b_TdPhiJetMet;   //!
   TBranch        *b_TdPhiLepMet;   //!
   TBranch        *b_TdPhiLepJet;   //!
   TBranch        *b_TdPhill;   //!
   TBranch        *b_TcosThetap;   //!
   TBranch        *b_TcosThetam;   //!
   TBranch        *b_TNLepSel;   //!
   TBranch        *b_TNJetSel;   //!
   TBranch        *b_TNMuon;   //!
   TBranch        *b_TNElec;   //!
   TBranch        *b_TNJets;   //!
   TBranch        *b_TNJetsBtag;   //!
   TBranch        *b_TJetSel_discriminant;   //!
   TBranch        *b_TJetSel_Px;   //!
   TBranch        *b_TJetSel_Py;   //!
   TBranch        *b_TJetSel_Pz;   //!
   TBranch        *b_TJetSel_E;   //!
   TBranch        *b_TLepSel_Charge;   //!
   TBranch        *b_TLepSel_Px;   //!
   TBranch        *b_TLepSel_Py;   //!
   TBranch        *b_TLepSel_Pz;   //!
   TBranch        *b_TLepSel_E;   //!
   TBranch        *b_TMuon_Charge;   //!
   TBranch        *b_TMuon_Px;   //!
   TBranch        *b_TMuon_Py;   //!
   TBranch        *b_TMuon_Pz;   //!
   TBranch        *b_TMuon_E;   //!
   TBranch        *b_TElec_Charge;   //!
   TBranch        *b_TElec_Px;   //!
   TBranch        *b_TElec_Py;   //!
   TBranch        *b_TElec_Pz;   //!
   TBranch        *b_TElec_E;   //!
   TBranch        *b_TJet_discriminant;   //!
   TBranch        *b_TJet_Px;   //!
   TBranch        *b_TJet_Py;   //!
   TBranch        *b_TJet_Pz;   //!
   TBranch        *b_TJet_E;   //!
   TBranch        *b_TBJet_Px;   //!
   TBranch        *b_TBJet_Py;   //!
   TBranch        *b_TBJet_Pz;   //!
   TBranch        *b_TBJet_E;   //!
   TBranch        *b_GNMuon;   //!
   TBranch        *b_GNElec;   //!
   TBranch        *b_GNJets;   //!
   TBranch        *b_GMET;   //!
   TBranch        *b_GMET_Phi;   //!
   TBranch        *b_GMT2ll;   //!
   TBranch        *b_GMT2bb;   //!
   TBranch        *b_GMT2lblb;   //!
   TBranch        *b_GJet_discriminant;   //!
   TBranch        *b_GJet_Px;   //!
   TBranch        *b_GJet_Py;   //!
   TBranch        *b_GJet_Pz;   //!
   TBranch        *b_GJet_E;   //!
   TBranch        *b_GMuon_Px;   //!
   TBranch        *b_GMuon_Py;   //!
   TBranch        *b_GMuon_Pz;   //!
   TBranch        *b_GMuon_E;   //!
   TBranch        *b_GElec_Px;   //!
   TBranch        *b_GElec_Py;   //!
   TBranch        *b_GElec_Pz;   //!
   TBranch        *b_GElec_E;   //!
   TBranch        *b_HNMuon;   //!
   TBranch        *b_HNElec;   //!
   TBranch        *b_HNJetsBtag;   //!
   TBranch        *b_HMT2ll;   //!
   TBranch        *b_HMT2bb;   //!
   TBranch        *b_HMT2lblb;   //!
   TBranch        *b_HBJet_Px;   //!
   TBranch        *b_HBJet_Py;   //!
   TBranch        *b_HBJet_Pz;   //!
   TBranch        *b_HBJet_E;   //!
   TBranch        *b_HMuon_Px;   //!
   TBranch        *b_HMuon_Py;   //!
   TBranch        *b_HMuon_Pz;   //!
   TBranch        *b_HMuon_E;   //!
   TBranch        *b_HElec_Px;   //!
   TBranch        *b_HElec_Py;   //!
   TBranch        *b_HElec_Pz;   //!
   TBranch        *b_HElec_E;   //!

   ResolutionTree(TTree *tree=0);
   virtual ~ResolutionTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef ResolutionTree_cxx
ResolutionTree::ResolutionTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("trees/TTJets_tree_5.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("trees/TTJets_tree_5.root");
      }
      f->GetObject("sTopTree",tree);

   }
   Init(tree);
}

ResolutionTree::~ResolutionTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t ResolutionTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t ResolutionTree::LoadTree(Long64_t entry)
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

void ResolutionTree::Init(TTree *tree)
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

   fChain->SetBranchAddress("TWeight", &TWeight, &b_TWeight);
   fChain->SetBranchAddress("TNPV", &TNPV, &b_TNPV);
   fChain->SetBranchAddress("TMET", &TMET, &b_TMET);
   fChain->SetBranchAddress("TMET_Phi", &TMET_Phi, &b_TMET_Phi);
   fChain->SetBranchAddress("TMT2ll", &TMT2ll, &b_TMT2ll);
   fChain->SetBranchAddress("TMT2bb", &TMT2bb, &b_TMT2bb);
   fChain->SetBranchAddress("TMT2lblb", &TMT2lblb, &b_TMT2lblb);
   fChain->SetBranchAddress("THT", &THT, &b_THT);
   fChain->SetBranchAddress("TMll", &TMll, &b_TMll);
   fChain->SetBranchAddress("TMeff", &TMeff, &b_TMeff);
   fChain->SetBranchAddress("TPtllb", &TPtllb, &b_TPtllb);
   fChain->SetBranchAddress("TdPhiPtllbMET", &TdPhiPtllbMET, &b_TdPhiPtllbMET);
   fChain->SetBranchAddress("TdPhiJetMet", &TdPhiJetMet, &b_TdPhiJetMet);
   fChain->SetBranchAddress("TdPhiLepMet", &TdPhiLepMet, &b_TdPhiLepMet);
   fChain->SetBranchAddress("TdPhiLepJet", &TdPhiLepJet, &b_TdPhiLepJet);
   fChain->SetBranchAddress("TdPhill", &TdPhill, &b_TdPhill);
   fChain->SetBranchAddress("TcosThetap", &TcosThetap, &b_TcosThetap);
   fChain->SetBranchAddress("TcosThetam", &TcosThetam, &b_TcosThetam);
   fChain->SetBranchAddress("TNLepSel", &TNLepSel, &b_TNLepSel);
   fChain->SetBranchAddress("TNJetSel", &TNJetSel, &b_TNJetSel);
   fChain->SetBranchAddress("TNMuon", &TNMuon, &b_TNMuon);
   fChain->SetBranchAddress("TNElec", &TNElec, &b_TNElec);
   fChain->SetBranchAddress("TNJets", &TNJets, &b_TNJets);
   fChain->SetBranchAddress("TNJetsBtag", &TNJetsBtag, &b_TNJetsBtag);
   fChain->SetBranchAddress("TJetSel_discriminant", TJetSel_discriminant, &b_TJetSel_discriminant);
   fChain->SetBranchAddress("TJetSel_Px", TJetSel_Px, &b_TJetSel_Px);
   fChain->SetBranchAddress("TJetSel_Py", TJetSel_Py, &b_TJetSel_Py);
   fChain->SetBranchAddress("TJetSel_Pz", TJetSel_Pz, &b_TJetSel_Pz);
   fChain->SetBranchAddress("TJetSel_E", TJetSel_E, &b_TJetSel_E);
   fChain->SetBranchAddress("TLepSel_Charge", TLepSel_Charge, &b_TLepSel_Charge);
   fChain->SetBranchAddress("TLepSel_Px", TLepSel_Px, &b_TLepSel_Px);
   fChain->SetBranchAddress("TLepSel_Py", TLepSel_Py, &b_TLepSel_Py);
   fChain->SetBranchAddress("TLepSel_Pz", TLepSel_Pz, &b_TLepSel_Pz);
   fChain->SetBranchAddress("TLepSel_E", TLepSel_E, &b_TLepSel_E);
   fChain->SetBranchAddress("TMuon_Charge", TMuon_Charge, &b_TMuon_Charge);
   fChain->SetBranchAddress("TMuon_Px", TMuon_Px, &b_TMuon_Px);
   fChain->SetBranchAddress("TMuon_Py", TMuon_Py, &b_TMuon_Py);
   fChain->SetBranchAddress("TMuon_Pz", TMuon_Pz, &b_TMuon_Pz);
   fChain->SetBranchAddress("TMuon_E", TMuon_E, &b_TMuon_E);
   fChain->SetBranchAddress("TElec_Charge", TElec_Charge, &b_TElec_Charge);
   fChain->SetBranchAddress("TElec_Px", TElec_Px, &b_TElec_Px);
   fChain->SetBranchAddress("TElec_Py", TElec_Py, &b_TElec_Py);
   fChain->SetBranchAddress("TElec_Pz", TElec_Pz, &b_TElec_Pz);
   fChain->SetBranchAddress("TElec_E", TElec_E, &b_TElec_E);
   fChain->SetBranchAddress("TJet_discriminant", TJet_discriminant, &b_TJet_discriminant);
   fChain->SetBranchAddress("TJet_Px", TJet_Px, &b_TJet_Px);
   fChain->SetBranchAddress("TJet_Py", TJet_Py, &b_TJet_Py);
   fChain->SetBranchAddress("TJet_Pz", TJet_Pz, &b_TJet_Pz);
   fChain->SetBranchAddress("TJet_E", TJet_E, &b_TJet_E);
   fChain->SetBranchAddress("TBJet_Px", TBJet_Px, &b_TBJet_Px);
   fChain->SetBranchAddress("TBJet_Py", TBJet_Py, &b_TBJet_Py);
   fChain->SetBranchAddress("TBJet_Pz", TBJet_Pz, &b_TBJet_Pz);
   fChain->SetBranchAddress("TBJet_E", TBJet_E, &b_TBJet_E);
   fChain->SetBranchAddress("GNMuon", &GNMuon, &b_GNMuon);
   fChain->SetBranchAddress("GNElec", &GNElec, &b_GNElec);
   fChain->SetBranchAddress("GNJets", &GNJets, &b_GNJets);
   fChain->SetBranchAddress("GMET", &GMET, &b_GMET);
   fChain->SetBranchAddress("GMET_Phi", &GMET_Phi, &b_GMET_Phi);
   fChain->SetBranchAddress("GMT2ll", &GMT2ll, &b_GMT2ll);
   fChain->SetBranchAddress("GMT2bb", &GMT2bb, &b_GMT2bb);
   fChain->SetBranchAddress("GMT2lblb", &GMT2lblb, &b_GMT2lblb);
   fChain->SetBranchAddress("GJet_discriminant", GJet_discriminant, &b_GJet_discriminant);
   fChain->SetBranchAddress("GJet_Px", GJet_Px, &b_GJet_Px);
   fChain->SetBranchAddress("GJet_Py", GJet_Py, &b_GJet_Py);
   fChain->SetBranchAddress("GJet_Pz", GJet_Pz, &b_GJet_Pz);
   fChain->SetBranchAddress("GJet_E", GJet_E, &b_GJet_E);
   fChain->SetBranchAddress("GMuon_Px", GMuon_Px, &b_GMuon_Px);
   fChain->SetBranchAddress("GMuon_Py", GMuon_Py, &b_GMuon_Py);
   fChain->SetBranchAddress("GMuon_Pz", GMuon_Pz, &b_GMuon_Pz);
   fChain->SetBranchAddress("GMuon_E", GMuon_E, &b_GMuon_E);
   fChain->SetBranchAddress("GElec_Px", GElec_Px, &b_GElec_Px);
   fChain->SetBranchAddress("GElec_Py", GElec_Py, &b_GElec_Py);
   fChain->SetBranchAddress("GElec_Pz", GElec_Pz, &b_GElec_Pz);
   fChain->SetBranchAddress("GElec_E", GElec_E, &b_GElec_E);
   fChain->SetBranchAddress("HNMuon", &HNMuon, &b_HNMuon);
   fChain->SetBranchAddress("HNElec", &HNElec, &b_HNElec);
   fChain->SetBranchAddress("HNJetsBtag", &HNJetsBtag, &b_HNJetsBtag);
   fChain->SetBranchAddress("HMT2ll", &HMT2ll, &b_HMT2ll);
   fChain->SetBranchAddress("HMT2bb", &HMT2bb, &b_HMT2bb);
   fChain->SetBranchAddress("HMT2lblb", &HMT2lblb, &b_HMT2lblb);
   fChain->SetBranchAddress("HBJet_Px", HBJet_Px, &b_HBJet_Px);
   fChain->SetBranchAddress("HBJet_Py", HBJet_Py, &b_HBJet_Py);
   fChain->SetBranchAddress("HBJet_Pz", HBJet_Pz, &b_HBJet_Pz);
   fChain->SetBranchAddress("HBJet_E", HBJet_E, &b_HBJet_E);
   fChain->SetBranchAddress("HMuon_Px", HMuon_Px, &b_HMuon_Px);
   fChain->SetBranchAddress("HMuon_Py", HMuon_Py, &b_HMuon_Py);
   fChain->SetBranchAddress("HMuon_Pz", HMuon_Pz, &b_HMuon_Pz);
   fChain->SetBranchAddress("HMuon_E", HMuon_E, &b_HMuon_E);
   fChain->SetBranchAddress("HElec_Px", HElec_Px, &b_HElec_Px);
   fChain->SetBranchAddress("HElec_Py", HElec_Py, &b_HElec_Py);
   fChain->SetBranchAddress("HElec_Pz", HElec_Pz, &b_HElec_Pz);
   fChain->SetBranchAddress("HElec_E", HElec_E, &b_HElec_E);
   nentries = fChain->GetEntries();

   Notify();
}

Bool_t ResolutionTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void ResolutionTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t ResolutionTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef ResolutionTree_cxx
