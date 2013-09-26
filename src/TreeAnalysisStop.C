#include "TreeAnalysisStop.h"

#include <fstream>
#include <iostream>
#include <math.h>

#if !defined(__CINT__)
ClassImp(TreeAnalysisStop);
#endif

#define DO_LOOSE_SELECTION 1
#define DO_STOP 1

TreeAnalysisStop::TreeAnalysisStop(TTree* tree) : PAFAnalysis(tree)
{
}

//------------------------------------------------------------------------------
// Initialise
//------------------------------------------------------------------------------
void TreeAnalysisStop::Initialise()
{
  GetParameters();

  nEvents = InitCounterUI("nEvents","Number of analyzed events",0);

  /********************
     Tree Branches 
  ********************/ 
 
  AnalysisTree = CreateTree("AnalysisTree","sTopTree");
  
  AnalysisTree->Branch("TEvent",&TEvent,"TEvent/I");
  AnalysisTree->Branch("TWeight",&TWeight,"TWeight/F");
  AnalysisTree->Branch("TChannel",&TChannel,"TChannel/I");
  
  AnalysisTree->Branch("TNPV",&TNPV,"TNPV/I");
  AnalysisTree->Branch("TMET",&TMET,"TMET/F");
  AnalysisTree->Branch("TMET_Phi",&TMET_Phi,"TMET_Phi/F");
  AnalysisTree->Branch("TMETSig",&TMETSig,"TMETSig/F");

  AnalysisTree->Branch("TLep0Px",&TLep0Px,"TLep0Px/F");
  AnalysisTree->Branch("TLep0Py",&TLep0Py,"TLep0Py/F");
  AnalysisTree->Branch("TLep0Pz",&TLep0Pz,"TLep0Pz/F");
  AnalysisTree->Branch("TLep0E",&TLep0E,"TLep0E/F");
  AnalysisTree->Branch("TLep0isTight",&TLep0isTight,"TLep0isTight/B");
  AnalysisTree->Branch("TLep0RelIso",&TLep0RelIso,"TLep0RelIso/F");
  AnalysisTree->Branch("TLep1Px",&TLep1Px,"TLep1Px/F");
  AnalysisTree->Branch("TLep1Py",&TLep1Py,"TLep1Py/F");
  AnalysisTree->Branch("TLep1Pz",&TLep1Pz,"TLep1Pz/F");
  AnalysisTree->Branch("TLep1E",&TLep1E,"TLep1E/F");
  AnalysisTree->Branch("TLep1isTight",&TLep1isTight,"TLep1isTight/B");
  AnalysisTree->Branch("TLep1RelIso",&TLep1RelIso,"TLep1RelIso/F");

  AnalysisTree->Branch("TNselMuons",&TNselMuons,"TNselMuons/F");
  AnalysisTree->Branch("TNselElecs",&TNselElecs,"TNselElecs/F");

  AnalysisTree->Branch("TNJets",&TNJets,"TNJets/F");
  AnalysisTree->Branch("THT",&THT,"THT/F");
  AnalysisTree->Branch("TNJetsBtag",&TNJetsBtag,"TNJetsBtag/F");
  AnalysisTree->Branch("TBtagJet0",&TBtagJet0,"TBtagJet0/F");
  AnalysisTree->Branch("TBtagJet1",&TBtagJet1,"TBtagJet1/F");

  AnalysisTree->Branch("TJet0Px",&TJet0Px,"TJet0Px/F");
  AnalysisTree->Branch("TJet0Py",&TJet0Py,"TJet0Py/F");
  AnalysisTree->Branch("TJet0Pz",&TJet0Pz,"TJet0Pz/F");
  AnalysisTree->Branch("TJet0Et",&TJet0Et,"TJet0Et/T");
  AnalysisTree->Branch("TJet0E",&TJet0E,"TJet0E/F");
  AnalysisTree->Branch("TJet1Px",&TJet1Px,"TJet1Px/F");
  AnalysisTree->Branch("TJet1Py",&TJet1Py,"TJet1Py/F");
  AnalysisTree->Branch("TJet1Pz",&TJet1Pz,"TJet1Pz/F");
  AnalysisTree->Branch("TJet1Et",&TJet1Et,"TJet1Et/F");
  AnalysisTree->Branch("TJet1E",&TJet1E,"TJet1E/F");

  AnalysisTree->Branch("TBtagJet0Px",&TBtagJet0Px,"TBtagJet0Px/F");
  AnalysisTree->Branch("TBtagJet0Py",&TBtagJet0Py,"TBtagJet0Py/F");
  AnalysisTree->Branch("TBtagJet0Pz",&TBtagJet0Pz,"TBtagJet0Pz/F");
  AnalysisTree->Branch("TBtagJet0Et",&TBtagJet0Et,"TBtagJet0Et/F");
  AnalysisTree->Branch("TBtagJet0E",&TBtagJet0E,"TBtagJet0E/F");
  AnalysisTree->Branch("TBtagJet1Px",&TBtagJet1Px,"TBtagJet1Px/F");
  AnalysisTree->Branch("TBtagJet1Py",&TBtagJet1Py,"TBtagJet1Py/F");
  AnalysisTree->Branch("TBtagJet1Pz",&TBtagJet1Pz,"TBtagJet1Pz/F");
  AnalysisTree->Branch("TBtagJet1Et",&TBtagJet1Et,"TBtagJet1Et/F");
  AnalysisTree->Branch("TBtagJet1E",&TBtagJet1E,"TBtagJet1E/F");


//   // comment it out when not running on stop MC
  if(sampleName.Contains("Stop")){
    AnalysisTree->Branch("TGenStopMass0",&TGenStopMass0,"TGenStopMass0/F");
    AnalysisTree->Branch("TGenStopMass1",&TGenStopMass1,"TGenStopMass1/F");
    AnalysisTree->Branch("TGenChi0Mass0",&TGenChi0Mass0,"TGenChi0Mass0/F");
    AnalysisTree->Branch("TGenChi0Mass1",&TGenChi0Mass1,"TGenChi0Mass1/F");
  }


}

//------------------------------------------------------------------------------
// InsideLoop
//------------------------------------------------------------------------------
void TreeAnalysisStop::InsideLoop(){

  for (UInt_t i=0; i<T_Gen_tSt3_pdgId->size(); i++) {
    if (sampleName.Contains("TTbar")) {
      if (T_Gen_tSt3_pdgId->at(i)==6) 
	weight_top = exp(0.156 - 0.00137*T_Gen_tSt3_pt->at(i));
      if (T_Gen_tSt3_pdgId->at(i)==-6) 
	weight_antitop = exp(0.156 - 0.00137*T_Gen_tSt3_pt->at(i));
    }
  }

  // Weight
  if (sampleName.Contains("Data")) 
    weight = fWeight;
  else if (sampleName.Contains("TTbar")) {
    // WARNING: fPUWeight has the same name for Stop as for the other samples, but the definition is different (S7 vs S10 PU). Look for its definition here below!
    weight = fWeight * fPUWeight->GetWeight((float)T_Event_nTruePU) * sqrt(weight_top * weight_antitop);//True      
    //weight = fWeight * fPUWeight->GetWeight((float)T_Event_nPU);//Observed      
  }
  else  {
    // WARNING: fPUWeight has the same name for Stop as for the other samples, but the definition is different (S7 vs S10 PU). Look for its definition here below!
    weight = fWeight * fPUWeight->GetWeight((float)T_Event_nTruePU);//True      
    //weight = fWeight * fPUWeight->GetWeight((float)T_Event_nPU);//Observed      
  }

  (*nEvents)++;

  // Reset data members
  //----------------------------------------------------------------------------
  JetNumber.clear();
  BtagJetNumber.clear();

  Pt_clean   .clear();
  Eta_clean  .clear();
  Btag_clean .clear();
  PartonFlavour_clean.clear();

  S_Muon_Charge.clear();
  S_Muon_IsTight.clear();
  S_Muon_RelIso.clear();
  S_Elec_Charge.clear();
  S_Elec_IsTight.clear();
  S_Elec_RelIso.clear();
  S_Elec_SC_Et .clear();

  S_Muon.clear();
  S_Elec.clear();

  HT              =0.0;
  missingEt       =  0;
  //missingEtMin    =  0;
  dileptonInvMass =  0;
  iJet1           = -1;
  iJet2           = -1;
  nJets           =  0;
  nJetsBtag       =  0;
  nGenMuon        =  0;
  nGenElec        =  0;
  nSelMuon        =  0;
  nSelElec        =  0;

  TNselMuons = 0;
  TNselElecs = 0;

  // MET 
  //metx = T_METPF_ET*TMath::Cos(T_METPF_Phi);
  //mety = T_METPF_ET*TMath::Sin(T_METPF_Phi);

  // MET Type I
//  metx = T_METPFTypeI_ET*TMath::Cos(T_METPF_Phi);
//  mety = T_METPFTypeI_ET*TMath::Sin(T_METPF_Phi);

   // MET Type I + Phi corrections
   if (sampleName.Contains("Data")) {
     metx = T_METPFTypeI_ET*TMath::Cos(T_METPFTypeI_Phi) - (+4.83642e-02 + 2.48870e-01*T_Vertex_z->size());
     mety = T_METPFTypeI_ET*TMath::Sin(T_METPFTypeI_Phi) - (-1.50135e-01 - 8.27917e-02*T_Vertex_z->size());
   }
   else {
     metx = T_METPFTypeI_ET*TMath::Cos(T_METPFTypeI_Phi) - (+1.62861e-01 - 2.38517e-02*T_Vertex_z->size());
     mety = T_METPFTypeI_ET*TMath::Sin(T_METPFTypeI_Phi) - (+3.60860e-01 - 1.30335e-01*T_Vertex_z->size());
   }


  metxSys  = metx;
  metySys = mety;

  // Accept only events with a good vertex
  //----------------------------------------------------------------------------
  if (SelectedVertexIndex() < 0) return;

  // MET filters
  //----------------------------------------------------------------------------
  if (T_EventF_logErrorTooManyClusters || T_EventF_toomanystripclus || T_EventF_manystripclus) return;
  if (!T_EventF_EcalDeadCell || !T_EventF_trackingFailure || !T_EventF_hcalLaser || !T_EventF_ecalLaserCorr || !T_EventF_eeBadSc) return;

  // Select muons and electrons
  //----------------------------------------------------------------------------
  GetSelectedMuon();
  GetSelectedElec();

  // Get number of generated leptons 
  //----------------------------------------------------------------------------
  SelectedGenLepton();

  // Select the pair of leptons
  //----------------------------------------------------------------------------
  TLorentzVector Muon1;
  TLorentzVector Muon2;

  TLorentzVector Elec1;
  TLorentzVector Elec2;

  bool IsTight1;
  bool IsTight2;
  float RelIso1;
  float RelIso2;

  Double_t Elec1_SC_Et = 0;

  Bool_t mumuEvent = false;
  Bool_t eeEvent   = false;
  Bool_t emuEvent  = false;

  Int_t flav_seleclep1 = -1;
  Int_t flav_seleclep2 = -1;
  Int_t ind_seleclep1  = -1;
  Int_t ind_seleclep2  = -1;
  
  Double_t Wpair_max = -1;  // Max pt1 + pt2

  TNselMuons = nSelMuon;
  TNselElecs = nSelElec;

  // Loop over the 1st lepton
  //----------------------------------------------------------------------------
  for (UInt_t i=0; i<nSelElec+nSelMuon; i++) {

    Double_t charge_lep1, charge_lep2, pt_lep1, pt_lep2;
    Int_t    flav_lep1, flav_lep2;
    
    if (i < nSelElec) {

      charge_lep1 = S_Elec_Charge[i];
      pt_lep1     = S_Elec[i].Pt();
      flav_lep1   = electronFlavor;

    } else {

      charge_lep1 = S_Muon_Charge[i-nSelElec];
      pt_lep1     = S_Muon[i-nSelElec].Pt();
      flav_lep1   = muonFlavor;    
    }

    // Loop over the 2nd lepton
    //--------------------------------------------------------------------------
    for (UInt_t j=i+1; j<nSelElec+nSelMuon; j++) {
      
      if  (j < nSelElec)  { 
	
	charge_lep2 = S_Elec_Charge[j];
	pt_lep2     = S_Elec[j].Pt();
	flav_lep2   = electronFlavor;

      } else { 

	charge_lep2 = S_Muon_Charge[j-nSelElec];
	pt_lep2     = S_Muon[j-nSelElec].Pt();
	flav_lep2   = muonFlavor;    	
      }

      // Check for opposite charge leptons
      //------------------------------------------------------------------------
      if ( (doSS &&(charge_lep1*charge_lep2 > 0)) || (!doSS &&(charge_lep1*charge_lep2 < 0)) ) {  // FIXME!!!!!
	
	Double_t W_pair = pt_lep1 + pt_lep2;
	
	if (W_pair> Wpair_max) {
	  
	  Wpair_max      = W_pair;
	  ind_seleclep1  = i;
	  ind_seleclep2  = j;
	  flav_seleclep1 = flav_lep1;
	  flav_seleclep2 = flav_lep2;
	}
      }
    }
  }

  // Select the lepton pair with highest weight
  //----------------------------------------------------------------------------
  if (Wpair_max > 0) {
    
    Int_t indfinal_seleclep1 = -1;
    Int_t indfinal_seleclep2 = -1;
    
    if (flav_seleclep1 == 1) indfinal_seleclep1 = ind_seleclep1;
    if (flav_seleclep1 == 2) indfinal_seleclep1 = ind_seleclep1 - nSelElec;
    
    if (flav_seleclep2 == 1) indfinal_seleclep2 = ind_seleclep2;
    if (flav_seleclep2 == 2) indfinal_seleclep2 = ind_seleclep2 - nSelElec;
    
    // Final classification
   //--------------------------------------------------------------------------
    if (flav_seleclep1 == 2 && flav_seleclep2 == 2) {

      mumuEvent = true;

      Muon1 = S_Muon[indfinal_seleclep1];
      Muon2 = S_Muon[indfinal_seleclep2];

      IsTight1 = S_Muon_IsTight[indfinal_seleclep1];
      IsTight2 = S_Muon_IsTight[indfinal_seleclep2];
      RelIso1 = S_Muon_RelIso[indfinal_seleclep1];
      RelIso2 = S_Muon_RelIso[indfinal_seleclep2];

    } else if (flav_seleclep1 == 1 && flav_seleclep2 == 1) {

      eeEvent = true;

      Elec1 = S_Elec[indfinal_seleclep1];
      Elec2 = S_Elec[indfinal_seleclep2];

      IsTight1 = S_Elec_IsTight[indfinal_seleclep1];
      IsTight2 = S_Elec_IsTight[indfinal_seleclep2];
      RelIso1 = S_Elec_RelIso[indfinal_seleclep1];
      RelIso2 = S_Elec_RelIso[indfinal_seleclep2];
      
    } else if (flav_seleclep1 == 1 && flav_seleclep2 == 2) {

      emuEvent = true;
      
      Elec1 = S_Elec[indfinal_seleclep1];
      Muon1 = S_Muon[indfinal_seleclep2];

      IsTight1 = S_Elec_IsTight[indfinal_seleclep1];
      IsTight2 = S_Muon_IsTight[indfinal_seleclep2];
      RelIso1 = S_Elec_RelIso[indfinal_seleclep1];
      RelIso2 = S_Muon_RelIso[indfinal_seleclep2];
      Elec1_SC_Et = S_Elec_SC_Et[indfinal_seleclep1];

    } else if (flav_seleclep1 == 2 && flav_seleclep2 == 1) {

      emuEvent = true;
      
      Muon1 = S_Muon[indfinal_seleclep1];
      Elec1 = S_Elec[indfinal_seleclep2];

      IsTight1 = S_Muon_IsTight[indfinal_seleclep1];
      IsTight2 = S_Elec_IsTight[indfinal_seleclep2];
      RelIso1 = S_Muon_RelIso[indfinal_seleclep1];
      RelIso2 = S_Elec_RelIso[indfinal_seleclep2];
      Elec1_SC_Et = S_Elec_SC_Et[indfinal_seleclep2];
    }
  }
  
  // Jet cleaning
  //----------------------------------------------------------------------------
  TVector3 p_particle_jc[2];

  if (mumuEvent){

    p_particle_jc[0].SetXYZ(Muon1.Px(), Muon1.Py(), Muon1.Pz());
    p_particle_jc[1].SetXYZ(Muon2.Px(), Muon2.Py(), Muon2.Pz());
    
  } 
  else if(eeEvent){
    
    p_particle_jc[0].SetXYZ(Elec1.Px(), Elec1.Py(), Elec1.Pz());
    p_particle_jc[1].SetXYZ(Elec2.Px(), Elec2.Py(), Elec2.Pz());
    
  } 
  else if (emuEvent){
    
    p_particle_jc[0].SetXYZ(Elec1.Px(), Elec1.Py(), Elec1.Pz());
    p_particle_jc[1].SetXYZ(Muon1.Px(), Muon1.Py(), Muon1.Pz());
  }

  TVector3 vJet;
  // JER
  //------------------------------------------------------------------------
  TVector3 vGenJet;

  Double_t ptjmax1 = -999;  
  Double_t ptjmax2 = -999;
  UInt_t   jSize   =    0;

  jSize = T_JetAKCHS_Px->size(); 

  // MET
  //missingEt = T_METPF_ET;

  // MET type I
  missingEt = T_METPFTypeI_ET;

  if (mumuEvent || eeEvent || emuEvent) {

    for (UInt_t jt=0; jt<jSize; jt++) {

      vJet.SetXYZ(T_JetAKCHS_Px ->at(jt), T_JetAKCHS_Py ->at(jt), T_JetAKCHS_Pz ->at(jt));

      //------------------------------------------------------------------------
      // Jet ID
      //------------------------------------------------------------------------
      Bool_t jetID     = false;

      jetID =  (/*T_JetAKCHS_nDaughters->at(jt) > 1 &&*/
		T_JetAKCHS_NeutHadEnergyFrac->at(jt) < 0.99 && 
                T_JetAKCHS_NeutEmEnergyFrac->at(jt) < 0.99 &&
                (fabs(T_JetAKCHS_Eta->at(jt)) < 2.4 ? (T_JetAKCHS_CharEmEnergyFrac->at(jt) < 0.99 && 
						       T_JetAKCHS_CharHadEnergyFrac->at(jt) > 0. && T_JetAKCHS_ChargedMultiplicity->at(jt) > 0.) : true)); 
     
      // SYS
      Double_t var = 0; 
      Double_t PtVar = 0; 

      //------------------------------------------------------------------------
      // JER
      //------------------------------------------------------------------------
      if ( sys_source == sys_jer ) {  
	// Jet Generation Level (JER)
	vGenJet.SetXYZ(T_JetAKCHS_GenJet_Px ->at(jt), T_JetAKCHS_GenJet_Py ->at(jt), T_JetAKCHS_GenJet_Pz ->at(jt));
	if ( vGenJet.Pt() < 15 ) continue;
      }

      //------------------------------------------------------------------------
      // JES OR JER
      //------------------------------------------------------------------------
      if ( sys_source == sys_jes || sys_source == sys_jer || sys_source == sys_unenergy ){

	Double_t jecCorr = 1.0; //this other part is not present in new ntuple T_JetAKCHS_Corr->at(jt); 

	if ( sys_source == sys_jes ) {
	
	  Double_t jecUnc  = 1.;
	  //Double_t jecUnc  = T_JetAKCHS_Uncertainty->at(jt); // Only defined for MC TTbar (JEC) 
	
	  Double_t unc = sqrt(jecUnc*jecUnc);

	  if ( sys_direction == sys_Up)  var  = 1. + unc;
	  else if ( sys_direction == sys_Down ) var = 1. - unc;

	  // Variation in Pt -> comment for computing MET ONLY!
	  PtVar   = var*vJet.Pt();
	
	}

	if ( sys_source == sys_jer ) {
	
	  Double_t deltaPt = (vJet.Pt() - vGenJet.Pt());
	  Double_t factor_up=0, factor_nom=0, factor_down=0;
	
	  /***********************************
          New Twiky Recipe (February 2012)
	  ***********************************/
	  if (fabs (vJet.Eta()) < 1.1 ) {
	    factor_up   = (1.066-1.0) + 0.10; 
	    factor_nom  = (1.066-1.0);// +/-0.10 
	    factor_down = (1.066-1.0) - 0.10;
	  } 
	  else if (fabs (vJet.Eta()) < 1.7 ) {
	    factor_up   = (1.191-1.0) + 0.063;
	    factor_nom  = (1.191-1.0); // +/-0.063
	    factor_down = (1.191-1.0) - 0.063;
	  } 
	  else if (fabs (vJet.Eta()) < 2.3 ) {
	    factor_up   = (1.096-1.0) + 0.09;
	    factor_nom  = (1.096-1.0); // +/-0.09
	    factor_down = (1.096-1.0) - 0.09;
	  } 
	  else if (fabs (vJet.Eta()) > 2.3 ) {
	    factor_up   = (1.166-1) + 0.20;
	    factor_nom  = (1.166-1); // +/-0.20
	    factor_down = (1.166-1) - 0.20;
	  }
	
	  if ( sys_direction == sys_Up) var = max(0.0, (vJet.Pt() + deltaPt*factor_up)/vJet.Pt());
	  else if ( sys_direction == sys_Nom)  var = max(0.0, (vJet.Pt() + deltaPt*factor_nom)/vJet.Pt());
	  else if ( sys_direction == sys_Down) var = max(0.0, (vJet.Pt() + deltaPt*factor_down)/vJet.Pt());
	
	  // Variation in Pt -> comment for computing MET ONLY!
	  PtVar   = var*vJet.Pt();
	
	}
      
	// JES + MET OR JER + MET
	//------------------------------------------------------------------------
	Double_t jetuncorrectedx = T_JetAKCHS_Px->at(jt)/jecCorr;
	Double_t jetuncorrectedy = T_JetAKCHS_Py->at(jt)/jecCorr;
      
	// Only propagate to jets outside of a 0.4 cone from the leptons: jet cleanning, but not cut in pt, eta or ID
	TVector3 vJetpf;
	vJetpf.SetXYZ(T_JetAKCHS_Px->at(jt),T_JetAKCHS_Py->at(jt),T_JetAKCHS_Pz->at(jt));  
      
	Double_t dRminformet = 1.e9;
	for (UInt_t kkk=0; kkk<2; kkk++){
	  Double_t dRformet = vJetpf.DeltaR(p_particle_jc[kkk]);
	  if (dRformet < dRminformet) dRminformet = dRformet;
	}
      
	if ( sys_source != sys_unenergy ) {
	  if ( dRminformet > 0.4 ) {
	    metxSys += jetuncorrectedx;
	    metySys += jetuncorrectedy;
	  
	    metxSys -= jetuncorrectedx*var;
	    metySys -= jetuncorrectedy*var; 
	  }
	}
      
      }//if(JES || JER)   

      // Select jets outside of a 0.4 cone from the leptons
      //------------------------------------------------------------------------
      Double_t JetPt = vJet.Pt(); // Nominal
      
      if ( sys_source == sys_jes || sys_source == sys_jer )  JetPt = PtVar;
      
      if (JetPt > 30 && fabs(vJet.Eta()) < 2.4 && jetID) {  // in ttbar, |eta|<2.5
	
	Double_t dRmin = 999.;
	Double_t dR = 999.;
	
	for (UInt_t kk=0; kk<S_Muon.size(); kk++) {
	  //Double_t dR = vJet.DeltaR(p_particle_jc[kk]);
	  if (S_Muon_IsTight[kk])
	    dR = vJet.DeltaR(S_Muon[kk].Vect());
	  if (dR < dRmin) dRmin = dR;
	}
	for (UInt_t kk=0; kk<S_Elec.size(); kk++) {
	  if (S_Elec_IsTight[kk])
	    dR = vJet.DeltaR(S_Elec[kk].Vect());
	  if (dR < dRmin) dRmin = dR;
	}
	
	if (dRmin < 0.4) continue;
	
	// Fill the jets
	//----------------------------------------------------------------------
	nJets++;
	
	JetNumber.push_back(jt);
	Pt_clean.push_back (vJet.Pt());
	Eta_clean.push_back (vJet.Eta());
	
	HT+= T_JetAKCHS_Et ->at(jt);

	Btag_clean.push_back(T_JetAKCHS_Tag_CombSVtx->at(jt)); 
	PartonFlavour_clean.push_back(T_JetAKCHS_Parton_Flavour->at(jt)); 
	
      }
    }
    
    // Order the selected jets by pt. 
    
    for (int i=0;i<nJets;i++){
      for (int j=i;j<nJets;j++){
	if(Pt_clean[i]<Pt_clean[j]){
	  
	  float tempPt;
	  tempPt=Pt_clean[i];
	  Pt_clean[i]=Pt_clean[j];
	  Pt_clean[j]=tempPt;
	  
	  float tempN;
	  tempN=JetNumber[i];
	  JetNumber[i]=JetNumber[j];
	  JetNumber[j]=tempN;
	  
	  float tempEta;
	  tempEta=Eta_clean[i];
	  Eta_clean[i]=Eta_clean[j];
	  Eta_clean[j]=tempEta;
	  
	  
	  float tempBtag;
	  tempBtag=Btag_clean[i];
	  Btag_clean[i]=Btag_clean[j];
	  Btag_clean[j]=tempBtag;
	  
	  float tempPF;
	  tempPF=PartonFlavour_clean[i];
	  PartonFlavour_clean[i]=PartonFlavour_clean[j];
	  PartonFlavour_clean[j]=tempPF;

	}
      }
    }
    
    

    //--------------------------------------------------------------------------
    for (UInt_t l=0; l<nJets; l++) {

      //  recomended on Feb. 6-7, 2012
      //  WP 0.244
      //  CSVL
      //bSF = 0.984 --> cut = 0.285  (+2% : 0.240,     -2% : 0.330)
      //cSF = 0.984 --> cut = 0.285  (+4% : 0.2025,    -4% : 0.3825) 
      //lSF = 1.080 --> cut = 0.2325 (+8% : 0.2250,    -8% : 0.2475) 

      if (sampleName.Contains("Data")){
        //custom recipe 
	//if (Btag_clean[l] > wp){
        //official recipe
        if (fBTagSF->IsTagged(Btag_clean[l], -999999, Pt_clean[l], Eta_clean[l], 0) ){ 
	  
	  nJetsBtag++; 
	  BtagJetNumber.push_back(l);

	}
      }
      
      else { 

	//custom recipe 
	/*if ( (fabs(PartonFlavour_clean[l])==5 && Btag_clean[l]>wp_b)  ||  
	  (fabs(PartonFlavour_clean[l])==4 && Btag_clean[l]>wp_c)  ||
	  ((fabs(PartonFlavour_clean[l])==1 || fabs(PartonFlavour_clean[l])==2 || 
	  fabs(PartonFlavour_clean[l])==3 || fabs(PartonFlavour_clean[l])==21) && Btag_clean[l]>wp_l) )*/
	//official recipe
	if ( fBTagSF->IsTagged(Btag_clean[l], PartonFlavour_clean[l], Pt_clean[l], Eta_clean[l], 0) )
	  { 
	    nJetsBtag++; 
	    BtagJetNumber.push_back(l);
	  }
      }
          
      if (Pt_clean[l] > ptjmax1) {
	
	ptjmax1 = Pt_clean[l];
	iJet1   = l; 
      }
    }
    
    if (nJets > 1) {
      for (UInt_t p=0; p<nJets; p++) {
	if (p != UInt_t(iJet1)) {
	  
	  if (Pt_clean[p] > ptjmax2) {
	    
	    ptjmax2 = Pt_clean[p];
	    iJet2   = p;
	  }
	}      
      }
    }
  }
  
  // LES 
  //--------------------------------------------------------------------------
  if ( sys_source == sys_les ) {
    for (UInt_t i=0; i<T_Elec_Energy->size(); i++) {
      TLorentzVector Elec(T_Elec_Px    ->at(i),
			  T_Elec_Py    ->at(i),
			  T_Elec_Pz    ->at(i),
			  T_Elec_Energy->at(i));
      if ( fabs(Elec.Eta()) > 1.5 ) {
	if (sys_direction == sys_Up ) { metxSys += T_Elec_Px->at(i)*( 1 - (1+0.025) ); 
	  metySys += T_Elec_Py->at(i)*( 1 - (1+0.025) ); }
	else if (sys_direction == sys_Down ) { metxSys += T_Elec_Px->at(i)*( 1 - (1-0.025) ); 
	  metySys += T_Elec_Py->at(i)*( 1 - (1-0.025) ); }
      }
    }
  }//if(LES)
  
  if ( sys_source == sys_jes || sys_source == sys_jer || sys_source == sys_les || sys_source == sys_unenergy)  {

    // Variation in MET -> comment for computing Pt ONLY!
    MET_Sys   = sqrt(metxSys*metxSys + metySys*metySys);
    missingEt = MET_Sys;
  }

  // ANALYSIS - mumu channel
  //----------------------------------------------------------------------------
  if (PassTriggerMu() && mumuEvent) {
    
    //missingEtMin = 40;
    
    dileptonInvMass = (Muon1 + Muon2).M();
    
    //if ((fabs(Muon1.Eta()) < 2.1 || fabs(Muon2.Eta()) < 2.1) && dileptonInvMass > 20) {
    if ( dileptonInvMass > 20. ) {
      
      // Tree
      if (sampleName.Contains("TTbar")){ 
	if( fileSuffix.Contains("Bkg") && nGenMuon!=2) FillTree(Muon1, Muon2, iMM, IsTight1, IsTight2, RelIso1, RelIso2);//TTbar Bkg
	if(!fileSuffix.Contains("Bkg") && nGenMuon==2) FillTree(Muon1, Muon2, iMM, IsTight1, IsTight2, RelIso1, RelIso2);//TTbar Signal
      }      
      else FillTree(Muon1, Muon2, iMM, IsTight1, IsTight2, RelIso1, RelIso2);
      
    }
  }
  
  // ANALYSIS - ee channel
  //----------------------------------------------------------------------------
  if (PassTriggerEG() && eeEvent) {
    
    //missingEtMin = 40;
    
    dileptonInvMass = (Elec1 + Elec2).M();
    
    if (dileptonInvMass > 20.) {
      
      //Tree
      if (sampleName.Contains("TTbar")){ 
	if( fileSuffix.Contains("Bkg") && nGenElec!=2) FillTree(Elec1, Elec2, iEE, IsTight1, IsTight2, RelIso1, RelIso2);//TTbar Bkg
	if(!fileSuffix.Contains("Bkg") && nGenElec==2) FillTree(Elec1, Elec2, iEE, IsTight1, IsTight2, RelIso1, RelIso2);//TTbar Signal
      }      
      else FillTree(Elec1, Elec2, iEE, IsTight1, IsTight2, RelIso1, RelIso2);
      
    }
  }
  
  // ANALYSIS - em channel
  //----------------------------------------------------------------------------
  if (PassTriggerEM() && emuEvent) {
    
    //missingEtMin = 0;
    
    dileptonInvMass = (Elec1 + Muon1).M();
    
    //Bool_t triggerfid = true; 
    //if ( fabs(Muon1.Eta()) > 2.1) triggerfid = false;
    
    //if (triggerfid && dileptonInvMass > 20) { // also for emu
    if ( dileptonInvMass > 20. ) { // also for emu
 
      //Tree
      if (sampleName.Contains("TTbar")){ 
	if( fileSuffix.Contains("Bkg") && !(nGenMuon==1 && nGenElec==1)) FillTree(Elec1, Muon1, iEM, IsTight1, IsTight2, RelIso1, RelIso2);//TTbar Bkg
	if(!fileSuffix.Contains("Bkg") &&  (nGenMuon==1 && nGenElec==1)) FillTree(Elec1, Muon1, iEM, IsTight1, IsTight2, RelIso1, RelIso2);//TTbar Signal
      }      
      else FillTree(Elec1, Muon1, iEM, IsTight1, IsTight2, RelIso1, RelIso2);
    }
  }
  
}

//------------------------------------------------------------------------------
// SetDataMembersAtTermination
//------------------------------------------------------------------------------
void TreeAnalysisStop::SetDataMembersAtTermination(){
  GetParameters();
}
  
//------------------------------------------------------------------------------
// Summary
//------------------------------------------------------------------------------
void TreeAnalysisStop::Summary(){

  cout << "---------------------------------------------------" <<endl;
  cout << "Number of entries in the Tree= " << AnalysisTree->GetEntries() <<endl;  
  cout << "---------------------------------------------------" <<endl;

}

//------------------------------------------------------------------------------
// GetParameters
//------------------------------------------------------------------------------
void TreeAnalysisStop::GetParameters()
{
  sampleName   = GetInputParameters()->TheNamedString("sampleName");
  fileSuffix   = GetInputParameters()->TheNamedString("fileSuffix");
  GetInputParameters()->TheNamedInt("sys_source", sys_source);
  GetInputParameters()->TheNamedInt("sys_direction", sys_direction);
  GetInputParameters()->TheNamedBool("doSS", doSS);
 if(doSS) cout<<"Doing same sign"<<endl; 
 if(!doSS) cout<<"Doing opposite sign"<<endl; 

  GetInputParameters()->TheNamedDouble("wp",   wp); 
  GetInputParameters()->TheNamedDouble("wp_b", wp_b); 
  GetInputParameters()->TheNamedDouble("wp_c", wp_c); 
  GetInputParameters()->TheNamedDouble("wp_l", wp_l); 

  GetInputParameters()->TheNamedDouble("weight", fWeight); // cross section * luminosity / events in the sample
  GetInputParameters()->TheNamedDouble("luminosity", luminosity);

  /***********
  PU Reweight
  ***********/
  
  // Be careful! Stop samples are in 52X FastSim, they use 2012_Startup_inTimeOnly PU. See the numerical values on 
  // http://cmssw.cvs.cern.ch/cgi-bin/cmssw.cgi/CMSSW/FastSimulation/PileUpProducer/python/mix_2012_Startup_inTimeOnly_cff.py?revision=1.1&view=markup
  // They coincide with the S7 ones, whereas 53X data and bkg MC samples use S10. S7 corresponds to Summer12:
  // https://twiki.cern.ch/twiki/bin/view/CMS/Pileup_MC_Gen_Scenarios#2012_Pileup_Scenario_s
  // Please see also
  // https://twiki.cern.ch/twiki/bin/view/CMS/PdmVPileUpDescription#S7
  // https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideFastSimulation#Pileup_configuration

  if(sampleName.Contains("Stop")){
    fPUWeight = new PUWeight(luminosity,Summer12,"2012");
  }
  else{
    fPUWeight = new PUWeight(luminosity,Summer12_53X,"2012");
  }

  //fPUWeight = new PUWeight(luminosity,Summer12,"2012");
  //fPUWeight = new PUWeight(luminosity,Summer12,"2012Observed");
  //fPUWeight = new PUWeight(luminosity,Summer12,"2012A");
  //fPUWeight = new PUWeight(luminosity,Fall11,"2012A"); // W+Jets 7TeV

  fBTagSF = new BTagSFUtil("CSVM");
}

//------------------------------------------------------------------------------
// SelectedVertexIndex
//------------------------------------------------------------------------------
Int_t TreeAnalysisStop::SelectedVertexIndex()
{
  Int_t goodVertexIndex = -999;
  nGoodVertex           =    0;

  for (UInt_t iVertex=0; iVertex<T_Vertex_z->size(); iVertex++) {
      
    if (fabs(T_Vertex_z ->at(iVertex)) < 24 &&
	T_Vertex_rho    ->at(iVertex)  <  2 &&
	T_Vertex_ndof   ->at(iVertex)  >  4 &&
	!T_Vertex_isFake->at(iVertex)) {

      nGoodVertex++;
      
      if (nGoodVertex == 1) goodVertexIndex = iVertex;
    }
  }

  return goodVertexIndex;
}

//------------------------------------------------------------------------------
// SelectedPfMuonPt
//------------------------------------------------------------------------------
PTRelIso TreeAnalysisStop::SelectedPfMuonPt(UInt_t iMuon,
					   Int_t  iVertex)
{
  PTRelIso temp;

  Double_t muonPt = -999;

  temp.PT = muonPt;
  temp.passTightRelIso = false;
  temp.RelIso = -999;
  if (iVertex < 0) return temp;

  Bool_t pass = true;

  TLorentzVector Muon(T_Muon_Px    ->at(iMuon),
		      T_Muon_Py    ->at(iMuon),
		      T_Muon_Pz    ->at(iMuon),
		      T_Muon_Energy->at(iMuon));

  /****************
    Tight Muons
  ****************/

  // see https://twiki.cern.ch/twiki/bin/viewauth/CMS/SUSYstop
  // see https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideMuonId#Tight_Muon

  pass &= (T_Muon_IsGlobalMuon ->at(iMuon) || T_Muon_IsTrackerMuonArbitrated ->at(iMuon));
  pass &= ( T_Muon_IsGMPTMuons->at(iMuon) );

  pass &= ( T_Muon_isPFMuon->at(iMuon) );

  pass &= ( T_Muon_IPwrtAveBSInTrack->at(iMuon) < 0.2 );  // i.e. pat::Muon::dB()  // dxy cut
  //pass &= ( T_Muon_IPAbsInTrack->at(iMuon) < 0.2 );  // also supported for dxy, but dB() is more precisely computed

  //pass &= ( T_Muon_dzAbsInTrack->at(iMuon) < 0.5  ); //does not work substitue with the one below
  pass &= ( fabs(T_Muon_vz->at(iMuon) - T_Vertex_z->at(iVertex)) < 0.5  );
  
  //pass &= ( T_Muon_NValidHitsGTrk->at(iMuon) > 0);  // already in GMPT
  pass &= ( T_Muon_NValidPixelHitsInTrk->at(iMuon) > 0 );
  pass &= ( T_Muon_NLayers->at(iMuon) > 5 );
  //#if DO_STOP == 0
  //pass &= ( T_Muon_NumOfMatches->at(iMuon) > 1 );////////DKK 7/18/2013 FIXME CHANGED TO THE FOLLOWING LINE FOR STOP
  //#else
  pass &= ( T_Muon_NumOfMatchedStations->at(iMuon) > 1 );
  //#endif

  ///////////////////

  // dr<0.4 -> Muon POG
  //Double_t relIso = (T_Muon_chargedHadronIsoR04->at(iMuon) + max( 0.0, T_Muon_neutralHadronIsoR04->at(iMuon) + T_Muon_photonIsoR04->at(iMuon) - 0.5*T_Muon_sumPUPtR04->at(iMuon)))/Muon.Pt();  
  // dr<0.3 -> Stop selection, see https://twiki.cern.ch/twiki/bin/viewauth/CMS/SUSYstop
  Double_t relIso= (T_Muon_chargedHadronIsoR03->at(iMuon) + max( 0.0, T_Muon_neutralHadronIsoR03->at(iMuon) +T_Muon_photonIsoR03->at(iMuon) -0.5*T_Muon_sumPUPtR03->at(iMuon)))/Muon.Pt();

//#if DO_LOOSE_SELECTION == 0
//  pass &= (relIso < 0.15); //FG changed from 0.20 
//#else
//  pass &= (relIso < loose_mu_iso); //FG changed from 0.20 
//#endif
  if (relIso < 0.15) temp.passTightRelIso = true;
  else temp.passTightRelIso = false;

  temp.RelIso = relIso;

  pass &= (Muon.Pt() > 10.);  // Dileptonic stop: (20, 10). Require now that each muon have pT > 10 GeV, then ask one lepton to have > 20 later, in FillTree()
  pass &= (fabs(Muon.Eta()) < 2.4);

  // see https://twiki.cern.ch/twiki/bin/viewauth/CMS/SingleLepton2012#Muon_Selection
  pass &= ( fabs( Muon.Pt() - T_Muon_PFMuonPt->at(iMuon) ) < 5. );

  if (pass && relIso<0.15) muonPt = Muon.Pt();

  temp.PT = muonPt;

  return temp;  

}

//------------------------------------------------------------------------------
// SelectedPfElecPt
//------------------------------------------------------------------------------
PTRelIso TreeAnalysisStop::SelectedPfElecPt(UInt_t iElec,
					   Int_t  iVertex)
{
  PTRelIso temp; 

  Double_t electronPt = -999;

  temp.PT = electronPt;
  temp.passTightRelIso = false;
  temp.RelIso = -999;
  if (iVertex < 0) return temp;

  Bool_t pass = true;
	   
  TLorentzVector Elec(T_Elec_Px    ->at(iElec),
		      T_Elec_Py    ->at(iElec),
		      T_Elec_Pz    ->at(iElec),
		      T_Elec_Energy->at(iElec));
  
  // dr0.3 deltaBeta
  //Double_t relIso = (T_Elec_chargedHadronIso->at(iElec) + max(0.0, T_Elec_neutralHadronIso->at(iElec) + T_Elec_photonIso->at(iElec) - 0.5*T_Elec_puChargedHadronIso->at(iElec)))/Elec.Pt();

  // dr0.3 rho, see https://twiki.cern.ch/twiki/bin/viewauth/CMS/SingleLepton2012#electron_selection
  Double_t relIso = (T_Elec_chargedHadronIso->at(iElec) + max(0.0, T_Elec_neutralHadronIso->at(iElec) + T_Elec_photonIso->at(iElec) - (T_Event_RhoIso * GetEffectiveArea( T_Elec_SC_Eta->at(iElec) ) )))/Elec.Pt();

//#if DO_LOOSE_SELECTION == 0
//  pass &= (relIso < 0.15);
//#else
//  pass &= (relIso < loose_el_iso);
//#endif
  if (relIso < 0.15) temp.passTightRelIso = true;
  else temp.passTightRelIso = false;

  temp.RelIso = relIso;

  pass &= T_Elec_passConversionVeto->at(iElec);

  //----------------------------------------------------------------------------
  // Electron ID and/or MVA
  //----------------------------------------------------------------------------
  
  pass &= (Elec.Pt() > 10.); // Dileptonic stop: (20, 10). Require now that each electron have pT > 10 GeV, then ask one lepton to have > 20 later
  //pass &= (fabs(Elec.Eta()) < 2.5);

  pass &= ( (T_Elec_isEB->at(iElec) || T_Elec_isEE->at(iElec) ) && fabs(T_Elec_SC_Eta->at(iElec) ) < 2.5 ); 
  
  pass &= ( fabs(T_Elec_SC_Eta->at(iElec) ) < 1.4442 || fabs(T_Elec_SC_Eta->at(iElec)) > 1.566 ); 

  if( T_Elec_isEB->at(iElec) )
    pass &= ( fabs( T_Elec_deltaPhiIn->at(iElec) ) < 0.06 );
  else if( T_Elec_isEE->at(iElec) )
    pass &= ( fabs( T_Elec_deltaPhiIn->at(iElec) ) < 0.03 );

  if( T_Elec_isEB->at(iElec) )
    pass &= ( fabs( T_Elec_deltaEtaIn->at(iElec) ) < 0.004 );
  else if( T_Elec_isEE->at(iElec) )
    pass &= ( fabs( T_Elec_deltaEtaIn->at(iElec) ) < 0.007 );

  if( T_Elec_isEB->at(iElec) )
    pass &= ( T_Elec_sigmaIetaIeta->at(iElec) < 0.01 );
  else if( T_Elec_isEE->at(iElec) )  
    pass &= ( T_Elec_sigmaIetaIeta->at(iElec) < 0.03 );

  if( T_Elec_isEB->at(iElec) )
    pass &= ( T_Elec_HtoE->at(iElec) < 0.12 );
  else if (  T_Elec_isEE->at(iElec) ) 
    pass &= ( T_Elec_HtoE->at(iElec) < 0.10 );
  
  pass &= ( fabs( T_Elec_IPwrtPV->at(iElec) ) < 0.02 ); // Impact parameter
  pass &= ( T_Elec_dzwrtPV->at(iElec) < 0.1 );

  pass &= ( fabs( (1-T_Elec_eSuperClusterOverP->at(iElec))/T_Elec_ecalEnergy->at(iElec) ) < 0.05 );

  pass &= T_Elec_passConversionVeto->at(iElec);
  pass &= ( T_Elec_nHits->at(iElec) <= 1 );

  pass &= ( fabs( T_Elec_Pt->at(iElec) - T_Elec_PFElecPt->at(iElec) ) < 10 );

  pass &= ( T_Elec_isPF->at(iElec) );
  
  if (pass) electronPt = Elec.Pt();

  temp.PT = electronPt;

  return temp;
}

//------------------------------------------------------------------------------
// PassTriggerMu
//------------------------------------------------------------------------------
Bool_t TreeAnalysisStop::PassTriggerMu()
{
  Bool_t pass = T_passTriggerDoubleMu; 
  if (T_Event_RunNumber==191090 ||  T_Event_RunNumber==193112 || T_Event_RunNumber==193116) pass=false; 
  return pass;
}

//------------------------------------------------------------------------------
// PassTriggerEG
//------------------------------------------------------------------------------
Bool_t TreeAnalysisStop::PassTriggerEG()
{
  Bool_t pass = T_passTriggerDoubleEl; 
  if (T_Event_RunNumber==191090 ||  T_Event_RunNumber==193112 || T_Event_RunNumber==193116) pass=false; 
  return pass;
}

//------------------------------------------------------------------------------
// PassTriggerEM
//------------------------------------------------------------------------------
Bool_t TreeAnalysisStop::PassTriggerEM()
{
  Bool_t pass = T_passTriggerElMu; 
  if (T_Event_RunNumber==191090 ||  T_Event_RunNumber==193112 || T_Event_RunNumber==193116) pass=false; 
  return pass;
}

//------------------------------------------------------------------------------
// FillHistogramsAtCut
//------------------------------------------------------------------------------
void TreeAnalysisStop::FillTree(const TLorentzVector& lepton1, 
			       const TLorentzVector& lepton2,
			       UInt_t                iChannel, bool lepton1_istight, bool lepton2_istight, float lepton1_reliso, float lepton2_reliso){

  if( !( lepton1.Pt()>20. || lepton2.Pt()>20.) )
    return;   // Dileptonic stop: (20, 10). Each lepton must have pT > 10 GeV, then here we ask at least one lepton to have > 20


//   // comment it out when not running on stop MC
  if(sampleName.Contains("Stop")){
    TGenStopMass0 = T_Gen_StopMass->at(0);  // no sorting whatsoever
    TGenStopMass1 = T_Gen_StopMass->at(1);
    TGenChi0Mass0 = T_Gen_Chi0Mass->at(0);
    TGenChi0Mass1 = T_Gen_Chi0Mass->at(1);
  }
  
  
  TEvent=T_Event_EventNumber;
  TWeight=weight;
    
  TNPV=nGoodVertex;
//  TMET=T_METPFTypeI_ET;
//  TMET_Phi=T_METPFTypeI_Phi;
  TMETSig=T_METPF_Sig;

   TMET=sqrt(pow(metx,2)+pow(mety,2)); //T_METPFTypeI_ET; to apply Phi corrected MET
   if (metx>=0)
     TMET_Phi=TMath::ASin(mety/sqrt(pow(metx,2)+pow(mety,2)));//T_METPFTypeI_Phi;
   else if (mety>=0)
     TMET_Phi=TMath::ASin(mety/sqrt(pow(metx,2)+pow(mety,2))) + TMath::PiOver2();
   else if (mety<0)
     TMET_Phi=TMath::ASin(mety/sqrt(pow(metx,2)+pow(mety,2))) - TMath::PiOver2();
   else
     cout<< "ERROR for phi filling" <<endl;



    
  if(lepton1.Pt()>lepton2.Pt()){
      
    TLep0Px =lepton1.Px();
    TLep0Py =lepton1.Py();
    TLep0Pz =lepton1.Pz();
    TLep0E  =lepton1.E();
    TLep0isTight  =lepton1_istight;
    TLep0RelIso =lepton1_reliso;
      
    TLep1Px =lepton2.Px();
    TLep1Py =lepton2.Py();
    TLep1Pz =lepton2.Pz();
    TLep1E  =lepton2.E();
    TLep1isTight  =lepton2_istight;
    TLep1RelIso =lepton2_reliso;
      
  }
    
  else{
      
    TLep0Px =lepton2.Px();
    TLep0Py =lepton2.Py();
    TLep0Pz =lepton2.Pz();
    TLep0E  =lepton2.E();
    TLep0isTight  =lepton2_istight;
    TLep0RelIso =lepton2_reliso;
      
    TLep1Px =lepton1.Px();
    TLep1Py =lepton1.Py();
    TLep1Pz =lepton1.Pz();
    TLep1E  =lepton1.E();
    TLep1isTight  =lepton1_istight;
    TLep1RelIso =lepton1_reliso;
      
    if(iChannel==2) iChannel=-2; //emu=2;mue=-2
      
  }
    
    
  TChannel=iChannel;
    
  TNJets=nJets;
  THT=HT;
  TNJetsBtag=nJetsBtag;
     
    
  TJet0Px=0.0;
  TJet0Py=0.0;
  TJet0Pz=0.0;
  TJet0Et=0.0;
  TJet0E =0.0;

  TJet1Px=0.0;
  TJet1Py=0.0;
  TJet1Pz=0.0;
  TJet1Et=0.0;
  TJet1E =0.0;

  if(nJets>0){
    int Njet0=JetNumber[0];
      
    TJet0Px =T_JetAKCHS_Px     ->at(Njet0);
    TJet0Py =T_JetAKCHS_Py     ->at(Njet0);
    TJet0Pz =T_JetAKCHS_Pz     ->at(Njet0);
    TJet0Et =T_JetAKCHS_Et     ->at(Njet0);
    TJet0E  =T_JetAKCHS_Energy ->at(Njet0);
      
    TBtagJet0=Btag_clean[0];
  }//if(nJets>0)
    
  if(nJets>1){
    int Njet1=JetNumber[1];
      
    TJet1Px =T_JetAKCHS_Px     ->at(Njet1);
    TJet1Py =T_JetAKCHS_Py     ->at(Njet1);
    TJet1Pz =T_JetAKCHS_Pz     ->at(Njet1);
    TJet1Et =T_JetAKCHS_Et     ->at(Njet1);
    TJet1E  =T_JetAKCHS_Energy ->at(Njet1);

    TBtagJet1=Btag_clean[1];
  }//if(nJets>1)

  TBtagJet0Px=0.0;
  TBtagJet0Py=0.0;
  TBtagJet0Pz=0.0;
  TBtagJet0Et=0.0;
  TBtagJet0E =0.0;

  TBtagJet1Px=0.0;
  TBtagJet1Py=0.0;
  TBtagJet1Pz=0.0;
  TBtagJet1Et=0.0;
  TBtagJet1E =0.0;

  if(nJetsBtag>0){
    int Nbtagjet0=JetNumber[BtagJetNumber[0]];
      
    TBtagJet0Px =T_JetAKCHS_Px     ->at(Nbtagjet0);
    TBtagJet0Py =T_JetAKCHS_Py     ->at(Nbtagjet0);
    TBtagJet0Pz =T_JetAKCHS_Pz     ->at(Nbtagjet0);
    TBtagJet0Et =T_JetAKCHS_Et     ->at(Nbtagjet0);
    TBtagJet0E  =T_JetAKCHS_Energy ->at(Nbtagjet0);
  }
  if(nJetsBtag>1){
    int Nbtagjet1=JetNumber[BtagJetNumber[1]];
      
    TBtagJet1Px =T_JetAKCHS_Px     ->at(Nbtagjet1);
    TBtagJet1Py =T_JetAKCHS_Py     ->at(Nbtagjet1);
    TBtagJet1Pz =T_JetAKCHS_Pz     ->at(Nbtagjet1);
    TBtagJet1Et =T_JetAKCHS_Et     ->at(Nbtagjet1);
    TBtagJet1E  =T_JetAKCHS_Energy ->at(Nbtagjet1);
  }
    
  AnalysisTree->Fill();
  
}


//------------------------------------------------------------------------------
// GetSelectedMuon
//------------------------------------------------------------------------------
void TreeAnalysisStop::GetSelectedMuon()
{
  UInt_t muonSize = 0;

  muonSize = T_Muon_Energy->size();

  for (UInt_t i=0; i<muonSize; i++) {

    PTRelIso temp = (SelectedPfMuonPt(i, SelectedVertexIndex()));
    if (temp.PT > 0) {
      
      S_Muon_Charge.push_back(T_Muon_Charge->at(i));
      S_Muon_IsTight.push_back(temp.passTightRelIso);
      S_Muon_RelIso.push_back(temp.RelIso);

      // LES -> from data
      // ----------------------------------------
      // ------------------ only data -----------	
      // --- should split in encap and barrel --- 
      //Double_t scale =1.11; // ex. vary from 0.85 to 1.15	
      //TLorentzVector Muon(scale*T_Muon_Px    ->at(i),
      //		    scale*T_Muon_Py    ->at(i),
      //		    scale*T_Muon_Pz    ->at(i),
      //		    scale*T_Muon_Energy->at(i));
        
      // ---------------------------------------
	
      TLorentzVector Muon(T_Muon_Px    ->at(i),
			  T_Muon_Py    ->at(i),
			  T_Muon_Pz    ->at(i),
			  T_Muon_Energy->at(i));
	
      S_Muon.push_back(Muon);
    }
  }
  
  nSelMuon = S_Muon.size();
}

//------------------------------------------------------------------------------
// GetSelectedElec
//------------------------------------------------------------------------------
void TreeAnalysisStop::GetSelectedElec()
{
  UInt_t elecSize = 0;

  elecSize = T_Elec_Energy->size();

  for (UInt_t i=0; i<elecSize; i++) {

    PTRelIso temp = (SelectedPfElecPt(i, SelectedVertexIndex()));
    if (temp.PT > 0) {
	
      S_Elec_Charge.push_back(T_Elec_Charge->at(i));
      S_Elec_IsTight.push_back(temp.passTightRelIso);
      S_Elec_RelIso.push_back(temp.RelIso);
      S_Elec_SC_Et .push_back(T_Elec_SC_Et ->at(i));

      // LES -> from data
      // ----------------------------------------
      // ------------------ only data -----------	
      // --- should split in encap and barrel --- 
      //Double_t scale = 1.11; // ex. vary from 0.85 to 1.15	
      //TLorentzVector Elec(scale*T_Elec_Px    ->at(i),
      //		    scale*T_Elec_Py    ->at(i),
      //		    scale*T_Elec_Pz    ->at(i),
      //		    scale*T_Elec_Energy->at(i));
	
      // ---------------------------------------
	
      TLorentzVector Elec(T_Elec_Px    ->at(i),
			  T_Elec_Py    ->at(i),
			  T_Elec_Pz    ->at(i),
			  T_Elec_Energy->at(i));
		
      S_Elec.push_back(Elec);
    }
  }

  nSelElec = S_Elec.size();
}

//------------------------------------------------------------------------------
// SelectedGenLepton
//------------------------------------------------------------------------------
void TreeAnalysisStop::SelectedGenLepton()
{

  // Count generated muons and electrons
  //----------------------------------------------------------------------------
#if DO_STOP == 0
  nGenElec = T_Gen_ElecSt3_PID->size();
  nGenMuon = T_Gen_MuonSt3_PID->size();
  nGenTau  = T_Gen_TauSt3_PID->size();
#else
  nGenElec = T_Gen_ElecSt3_pdgId->size();
  nGenMuon = T_Gen_MuonSt3_pdgId->size();
  nGenTau  = T_Gen_TauSt3_pdgId->size();
#endif
  nGenLepton = nGenElec + nGenMuon + nGenTau;
  nTauElec = 0;
  nTauMuon = 0;

#if DO_STOP == 0
  for (UInt_t i=0; i<T_Gen_TauSt3_PID->size(); i++) {
#else
  for (UInt_t i=0; i<T_Gen_TauSt3_pdgId->size(); i++) {
#endif
    if (T_Gen_TauSt3_IsLepDec->at(i)) {
      if (abs(T_Gen_TauSt3_LepDec_PID->at(i)) == 11) nTauElec++;
      if (abs(T_Gen_TauSt3_LepDec_PID->at(i)) == 13) nTauMuon++;
    }
  }

  if ( nGenLepton == 2 ) {
    if ( nGenElec == 2 || (nGenElec == 1 && nTauElec == 1) || nTauElec == 2 ) nGenElec = 2; 
    if ( nGenMuon == 2 || (nGenMuon == 1 && nTauMuon == 1) || nTauMuon == 2 ) nGenMuon = 2; 
    if ( (nGenElec == 1 && nGenMuon == 1) || (nGenElec == 1 && nTauMuon == 1) ||
	 (nGenMuon == 1 && nTauElec == 1) || (nTauElec == 1 && nTauMuon == 1) ) { nGenElec = 1; nGenMuon = 1; }
  } 

}
 
 
 
//------------------------------------------------------------------------------
// Effective areas for rho correction to electron isolation
//------------------------------------------------------------------------------
Double_t TreeAnalysisStop::GetEffectiveArea(float eta)
{
  Double_t Aeff=0.;
   
  if( fabs(eta) < 1.0 )	        Aeff = 0.13; // +/- 0.001
  else if( fabs(eta)<1.479 )    Aeff = 0.14; // +/- 0.002
  else if( fabs(eta)<2.0 )      Aeff = 0.07; // +/- 0.001
  else if( fabs(eta)<2.2 )      Aeff = 0.09; // +/- 0.001
  else if( fabs(eta)<2.3 )      Aeff = 0.11; // +/- 0.002
  else if( fabs(eta)<2.4 )      Aeff = 0.11; // +/- 0.003
  if( fabs(eta) > 2.4 )         Aeff = 0.14; // +/- 0.004

  return Aeff;
}

