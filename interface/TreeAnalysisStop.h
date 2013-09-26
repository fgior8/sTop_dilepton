#ifndef TREEANALYSIS_STOP_H
#define TREEANALYSIS_STOP_H 1

// UNCOMMENT WHEN NOT RUNNING FROM ALTAMIRA
//#include "PAFAnalysis/PAFAnalysis.h"
#include "PAFAnalysis.h"
//#include "TCounterUI/TCounterUI.h"
#include "TCounterUI.h"
//#include "PUWeight/PUWeight.h"
#include "PUWeight.h"

//#include "packages/BTagSFUtil/BTagSFUtil.h"
//#include "BTagSFUtil/BTagSFUtil.h"
#include "BTagSFUtil.h"

#include "TH1F.h"
#include "TH2F.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TTree.h"

#include <fstream>
#include <iostream>
#include <vector>

Int_t nGoodVertex;

const UInt_t nChannels = 5;

enum {iMM, iEE, iEM, iLL, iMMEE};

TString sChannel[] = {"MM", "EE", "EM", "ALL", "MMEE"};

const UInt_t nTypes = 3;

enum {iAll, iSig, iBkg};

TString sType[] = {"all", "sig", "bkg"};

const UInt_t nCuts = 6;

enum {iDilepton, iZVeto, i2jets, iMET, i1btag, i2btag};

TString sCut[] = {"dilepton", "ZVeto", "2jets", "MET", "1btag", "2btag"};

const UInt_t nDYCR = 2;

enum {iDYin, iDYout};

TString sDYCR[] = {"In", "Out"};

enum {electronFlavor = 1, muonFlavor = 2};

enum sys_sources { sys_jes = 0, sys_jer, sys_les, sys_unenergy };
enum sys_directions { sys_Up = 0, sys_Nom, sys_Down};

struct PTRelIso {
	Double_t PT;
	bool passTightRelIso;
	Double_t RelIso;
};

// Forward declaration
class TLorentzVector;


class TreeAnalysisStop: public PAFAnalysis
{
 public:
  TreeAnalysisStop(TTree *tree=0);//, double loosemuiso, double looseeliso);
  virtual ~TreeAnalysisStop() {}

  double loose_mu_iso;
  double loose_el_iso;

 protected:
  virtual void Initialise();
  virtual void InsideLoop();
  virtual void SetDataMembersAtTermination();
  virtual void Summary();

  // Counters
  TCounterUI *nEvents;

  // My member functions
  //----------------------------------------------------------------------------
  void     GetParameters          ();
  Int_t    SelectedVertexIndex    ();

  PTRelIso SelectedPfMuonPt       (UInt_t iMuon, Int_t iVertex);
  Double_t SelectedMuonPt         (UInt_t iMuon, Int_t iVertex);

  PTRelIso SelectedPfElecPt       (UInt_t iElec, Int_t iVertex);
  Double_t SelectedElecPt         (UInt_t iElec, Int_t iVertex);

  Bool_t   PassTriggerMu          ();
  Bool_t   PassTriggerEG          ();
  Bool_t   PassTriggerEM          ();

  void     GetSelectedMuon        ();

  void     GetSelectedElec        ();

  void     SelectedGenLepton();

  void     FillTree               (const TLorentzVector& lepton1, 
				   const TLorentzVector& lepton2,
				   UInt_t                iChannel, bool, bool, float, float);
 
  Double_t GetEffectiveArea       (float eta); 

 public:

  // Histograms
  //----------------------------------------------------------------------------


  // Input parameters
  //----------------------------------------------------------------------------
  TString  sampleName;
  TString  fileSuffix;
  Double_t weight;
  Double_t weight_top, weight_antitop;
  Double_t fWeight;
  Double_t luminosity;
  bool doSS;

  PUWeight *fPUWeight;   //The PU weight utility

  BTagSFUtil *fBTagSF; // The BTag SF utility

  // Data members
  //----------------------------------------------------------------------------
  std::vector<Double_t>       Pt_clean;
  std::vector<Double_t>       Eta_clean;
  std::vector<Double_t>       Btag_clean;
  std::vector<Int_t>          PartonFlavour_clean;
  std::vector<Int_t>          JetNumber;
  std::vector<Int_t>          BtagJetNumber;
  std::vector<Double_t>       BtagJetPt;

  std::vector<Double_t>       S_Muon_Charge;
  std::vector<Double_t>       S_Elec_Charge;
  std::vector<Double_t>       S_Muon_IsTight;
  std::vector<Double_t>       S_Muon_RelIso;
  std::vector<Double_t>       S_Elec_IsTight;
  std::vector<Double_t>       S_Elec_RelIso;
  std::vector<Double_t>       S_Elec_SC_Et;

  std::vector<TLorentzVector> S_Muon;
  std::vector<TLorentzVector> S_Elec;

  Double_t                    missingEt;
  //Double_t                    missingEtMin;
  Double_t                    dileptonInvMass;
  Int_t                       iJet1;
  Int_t                       iJet2;
  Int_t                       iBtagJet1;
  Int_t                       iBtagJet2;
  UInt_t                      nJets;
  UInt_t                      nJetsBtag;
  Double_t                    HT;
  UInt_t                      nGenElec;
  UInt_t                      nGenMuon;
  UInt_t                      nGenTau;
  UInt_t                      nGenLepton;
  UInt_t                      nTauElec;
  UInt_t                      nTauMuon;
  UInt_t                      nSelMuon;
  UInt_t                      nSelElec;

  // Sys.
  Double_t metx; 
  Double_t mety; 

  Double_t metxSys;
  Double_t metySys; 

  Double_t MET_Sys;
  
  // Sys. source
  Int_t sys_source;
  Int_t sys_direction;
  Double_t wp;
  Double_t wp_b;
  Double_t wp_c;
  Double_t wp_l;
  //Double_t varSF;

  // Trees
  TTree      *AnalysisTree;

  // Branches
  int TEvent;  
  float TWeight;
  UInt_t TChannel;

  int TNPV;
  float TMET;
  float TMET_Phi;
  float TMETSig;

  float TLep0Px;
  float TLep0Py;
  float TLep0Pz;
  float TLep0Et;
  float TLep0E;
  bool TLep0isTight;
  float TLep0RelIso;
  float TLep1Px;
  float TLep1Py;
  float TLep1Pz;
  float TLep1Et;
  float TLep1E;
  bool TLep1isTight;
  float TLep1RelIso;

  float TNselMuons;
  float TNselElecs;

  float TNJets;     
  float THT;
  float TNJetsBtag; 
  float TBtagJet0;  
  float TBtagJet1;  

  float TJet0Px;    
  float TJet0Py;    
  float TJet0Pz;    
  float TJet0Et;    
  float TJet0E;    
  float TJet1Px;    
  float TJet1Py;    
  float TJet1Pz;    
  float TJet1Et;    
  float TJet1E;    

  float TBtagJet0Px;    
  float TBtagJet0Py;    
  float TBtagJet0Pz;    
  float TBtagJet0Et;    
  float TBtagJet0E;    
  float TBtagJet1Px;    
  float TBtagJet1Py;    
  float TBtagJet1Pz;    
  float TBtagJet1Et;    
  float TBtagJet1E;    

  float TGenStopMass0;
  float TGenStopMass1;
  float TGenChi0Mass0;
  float TGenChi0Mass1;

  ClassDef(TreeAnalysisStop,0);
};


#endif

/*  LocalWords:  ifndef
 */

