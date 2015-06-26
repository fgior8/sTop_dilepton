#include "ElectronSelection.h"

ElectronSel::ElectronSel() {};


ElectronSel::~ElectronSel() {};


void ElectronSel::ElectronSelection(std::vector<Bool_t> isEB, std::vector<Bool_t> isEE, std::vector<Float_t> Eta, std::vector<Float_t> Pt, std::vector<Float_t> E, std::vector<Float_t> Px, std::vector<Float_t> Py, std::vector<Float_t> Pz, std::vector<Float_t> TrkIso, std::vector<Float_t> ECalIso, std::vector<Float_t> HCalIso, std::vector<Int_t> Charge, std::vector<Int_t> MissingHits, std::vector<Bool_t> passConversionVeto, std::vector<Float_t> DeltaEtaTrkSC, std::vector<Float_t> DeltaPhiTrkSC, std::vector<Float_t> SigmaIEtaIEta, std::vector<Float_t> HoE, std::vector<Float_t> caloEnergy, std::vector<Float_t> SuperClusterOverP, std::vector<Float_t> Trkdxy, std::vector<Float_t> Trkdz, std::vector<Float_t> PUpt, std::vector<Lepton>& leptonColl) {

  D0=D0Error=0.;
   
  for (UInt_t ilep=0; ilep<Pt.size(); ilep++) {

    if ( fabs(Eta[ilep])>1.4442 && fabs(Eta[ilep])<1.566 ) continue;
    //if ( caloEnergy[ilep]==0 ) continue;

    vLepton.SetPxPyPzE(Px[ilep], Py[ilep], Pz[ilep], E[ilep]);

    dz = fabs(Trkdz[ilep]);
    dxy = fabs(Trkdxy[ilep]);
    
    fakeType = Lepton::unknown;
    looseTight = Lepton::Other;
    leptonType = Lepton::Electron;

    
    if (Pt[ilep] > 0.01)
      LeptonRelIso = ( HCalIso[ilep] + max( ECalIso[ilep] + TrkIso[ilep] - 0.5 * PUpt[ilep], 0.) ) / Pt[ilep];
    else LeptonRelIso = 9999.;
    
    //// electron ID medium WP /// 
    
    ElectronID = false;
    if (isEB[ilep]) {
      if (DeltaEtaTrkSC[ilep] < 0.007641 &&
	  DeltaPhiTrkSC[ilep] < 0.032643 &&
	  SigmaIEtaIEta[ilep] < 0.010399 &&
	  HoE[ilep] < 0.060662 &&
	  MissingHits[ilep] <= 1 &&
	  fabs( (1 - SuperClusterOverP[ilep])/caloEnergy[ilep] ) < 0.153897 &&
	  passConversionVeto[ilep] &&
	  LeptonRelIso < 0.097213 &&
	  dxy < 0.011811 &&
	  dz < 0.070775)
	ElectronID = true;
    }
    else if (isEE[ilep]) {
      if (DeltaEtaTrkSC[ilep] < 0.009285 &&
	  DeltaPhiTrkSC[ilep] < 0.042447 &&
	  SigmaIEtaIEta[ilep] < 0.029524 &&
	  HoE[ilep] < 0.104263 &&
	  MissingHits[ilep] <= 1 &&
	  fabs( (1 - SuperClusterOverP[ilep])/caloEnergy[ilep] ) < 0.137468 &&
	  passConversionVeto[ilep] &&
	  LeptonRelIso < 0.116708 &&
	  dxy < 0.051682 &&
	  dz < 0.180720)
	ElectronID = true;
    }
    else
      cout<< "something wrong with electron ID" <<endl;
 
    //  (ChargeConsistency[ilep]) ? individual = true : individual = false;
 
    (fabs(Eta[ilep]) < eta_cut && Pt[ilep] >= pt_cut_min && Pt[ilep] < pt_cut_max) ? etaPt=true : etaPt =false;
    
    // (dz<dz_cut && dxy<dxy_cut && LeptonRelIso < relIso_cut && LeptonRelIso >= relIsoMIN_cut) ? RelIsod0=true : RelIsod0=false;
    
    if (ElectronID && etaPt) {
      leptonColl.push_back( Lepton(leptonType, ilep, vLepton, Eta[ilep], LeptonchiNdof, dxy, dz, Charge[ilep], fakeType, looseTight, LeptonRelIso) );
    }
    
  }
  
  std::sort( leptonColl.begin(), leptonColl.end(), LeptonPTSorter );
  
}

void ElectronSel::ElectronSelectionLoose(std::vector<Int_t> isID, std::vector<Bool_t> isEB, std::vector<Bool_t> isEE, std::vector<Bool_t> TrackerDrivenSeed, std::vector<Bool_t> EcalDrivenSeed, std::vector<Double_t> Eta, std::vector<Double_t> Phi, std::vector<Double_t> Pt, std::vector<Double_t> E, std::vector<Double_t> TrkIso, std::vector<Double_t> ECalIso, std::vector<Double_t> HCalIso, std::vector<Int_t> Charge, std::vector<Bool_t> ChargeConsistency, std::vector<Int_t> MissingHits, std::vector<Bool_t> HasMatchedConvPhot, std::vector<Double_t> DeltaEtaTrkSC, std::vector<Double_t> DeltaPhiTrkSC, std::vector<Double_t> SigmaIEtaIEta, std::vector<Double_t> HoE, std::vector<Double_t> caloEnergy, std::vector<Double_t> SuperClusterOverP, std::vector<Double_t> Trkdx, std::vector<Double_t> Trkdy, std::vector<Double_t> Trkdz, Double_t Vertex_X, Double_t Vertex_Y, Double_t Vertex_Z, Double_t rho, std::vector<Lepton>& leptonColl) {
  /*
  D0=D0Error=0.;

  for (UInt_t ilep=0; ilep<Pt.size(); ilep++) {

    isID[ilep] ? ElectronID=true : ElectronID=false;

    vLepton.SetPtEtaPhiE(Pt[ilep], Eta[ilep], Phi[ilep], E[ilep]);

    fakeType = Lepton::unknown;
    looseTight = Lepton::Other;
    leptonType = Lepton::Electron;

    if (fabs(Eta[ilep]) < 1.0) ifid = 0;
    else if (fabs(Eta[ilep]) < 1.479) ifid = 1;
    else if (fabs(Eta[ilep]) < 2.0) ifid = 2;
    else if (fabs(Eta[ilep]) < 2.2) ifid = 3;
    else if (fabs(Eta[ilep]) < 2.3) ifid = 4;
    else if (fabs(Eta[ilep]) < 2.4) ifid = 5;
    else ifid = 6;

    if (Pt[ilep] > 0.01)
      LeptonRelIso = ( HCalIso[ilep] + max( ECalIso[ilep] + TrkIso[ilep] - rho * PHONH[ifid], 0.) ) / Pt[ilep];
    else LeptonRelIso = 9999.;

    dz = fabs(Trkdz[ilep] - Vertex_Z);
    dxy = sqrt(pow(Trkdx[ilep]-Vertex_X,2)+pow(Trkdy[ilep]-Vertex_Y,2));

    (fabs(Eta[ilep]) < eta_cut && Pt[ilep] >= pt_cut_min && Pt[ilep] < pt_cut_max) ? etaPt=true : etaPt =false;

    (dz<dz_cut && dxy<dxy_cut && LeptonRelIso < relIso_cut && LeptonRelIso >= relIsoMIN_cut) ? RelIsod0=true : RelIsod0=false;

    if (ElectronID && etaPt && RelIsod0 ) {
      leptonColl.push_back( Lepton(leptonType, ilep, vLepton, Eta[ilep], LeptonchiNdof, D0, D0Error, dxy, dz, Charge[ilep], fakeType, looseTight, TrkIso[ilep], LeptonRelIso) );
    }

  }

  std::sort( leptonColl.begin(), leptonColl.end(), LeptonPTSorter );
  */
}

