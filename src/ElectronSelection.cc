#include "ElectronSelection.h"

ElectronSel::ElectronSel() {};


ElectronSel::~ElectronSel() {};


void ElectronSel::ElectronSelection(Int_t *pdgId, Float_t *EtaSc, Float_t *Pt, Float_t *Px, Float_t *Py, Float_t *Pz, Float_t *E, Float_t *relIso, Int_t *Charge, Int_t *passConversionVeto, Int_t *MissingHits, Float_t *DeltaEtaTrkSC, Float_t *DeltaPhiTrkSC, Float_t *SigmaIEtaIEta, Float_t *HoE, Float_t *eInvMinusPInv, Float_t *dxy_var, Float_t *dz_var, std::vector<Lepton>& leptonColl) {

  D0=D0Error=0.;
   
  for (UInt_t ilep=0; ilep<sizeof(Pt); ilep++) {
    if (fabs(pdgId[ilep])!=11) continue;
    if ( fabs(EtaSc[ilep])>1.4442 && fabs(EtaSc[ilep])<1.566 ) continue;
    fabs(EtaSc[ilep])<=1.4442 ? isEB=true : isEB=false;
    fabs(EtaSc[ilep])>=1.566 ? isEE=true : isEE=false;  
    if (!(isEB || isEE)) continue;

    vLepton.SetPxPyPzE(Px[ilep], Py[ilep], Pz[ilep], E[ilep]);

    dz = dz_var[ilep];
    dxy = dxy_var[ilep];
    
    fakeType = Lepton::unknown;
    looseTight = Lepton::Other;
    leptonType = Lepton::Electron;

    LeptonRelIso = relIso[ilep];
    
    //// electron ID tight WP /// 
    
    ElectronID = false;
    if (isEB) {
      if (fabs(DeltaEtaTrkSC[ilep]) < 0.00926 &&
	  fabs(DeltaPhiTrkSC[ilep]) < 0.0336 &&
	  SigmaIEtaIEta[ilep] < 0.0101 &&
	  HoE[ilep] < 0.0597 &&
	  MissingHits[ilep] <= 2 &&
	  fabs(eInvMinusPInv[ilep]) < 0.012 &&
	  passConversionVeto[ilep] > 0 &&
	  LeptonRelIso < 0.0354 &&
	  fabs(dxy) < 0.0111 &&
	  fabs(dz) < 0.0466)
	ElectronID = true;
    }
    else if (isEE) {
      if (fabs(DeltaEtaTrkSC[ilep]) < 0.00724 &&
	  fabs(DeltaPhiTrkSC[ilep]) < 0.0918 &&
	  SigmaIEtaIEta[ilep] < 0.0279 &&
	  HoE[ilep] < 0.0615 &&
	  MissingHits[ilep] <= 1 &&
	  fabs(eInvMinusPInv[ilep]) < 0.00999 &&
	  passConversionVeto[ilep] > 0 &&
	  LeptonRelIso < 0.0646 &&
	  dxy < 0.0351 &&
	  dz < 0.417)
	ElectronID = true;
    }
    else
      cout<< "something wrong with electron ID" <<endl;
 
    //  (ChargeConsistency[ilep]) ? individual = true : individual = false;
 
    (fabs(vLepton.Eta()) < eta_cut && Pt[ilep] >= pt_cut_min && Pt[ilep] < pt_cut_max) ? etaPt=true : etaPt =false;
    
    // (dz<dz_cut && dxy<dxy_cut && LeptonRelIso < relIso_cut && LeptonRelIso >= relIsoMIN_cut) ? RelIsod0=true : RelIsod0=false;
    
    if (ElectronID && etaPt) {
      leptonColl.push_back( Lepton(leptonType, ilep, vLepton, EtaSc[ilep], LeptonchiNdof, dxy, dz, Charge[ilep], fakeType, looseTight, LeptonRelIso) );
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

