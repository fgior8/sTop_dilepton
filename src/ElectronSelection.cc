#include "ElectronSelection.h"

ElectronSel::ElectronSel() {};


ElectronSel::~ElectronSel() {};


void ElectronSel::ElectronSelection(Int_t nElectron, Int_t *pdgId, Float_t *EtaSc, Float_t *Pt, Float_t *Px, Float_t *Py, Float_t *Pz, Float_t *E, Float_t *relIso, Int_t *Charge, Int_t *passConversionVeto, Int_t *MissingHits, Float_t *DeltaEtaTrkSC, Float_t *DeltaPhiTrkSC, Float_t *SigmaIEtaIEta, Float_t *HoE, Float_t *eInvMinusPInv, Float_t *dxy_var, Float_t *dz_var, std::vector<Lepton>& leptonColl) {

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

void ElectronSel::ElectronSelectionWithLoose(Int_t nElectron, Int_t *pdgId, Float_t *EtaSc, Float_t *Pt, Float_t *Px, Float_t *Py, Float_t *Pz, Float_t *E, Float_t *relIso, Int_t *Charge, Int_t *passConversionVeto, Int_t *MissingHits, Float_t *DeltaEtaTrkSC, Float_t *DeltaPhiTrkSC, Float_t *SigmaIEtaIEta, Float_t *HoE, Float_t *eInvMinusPInv, Float_t *dxy_var, Float_t *dz_var, std::vector<Lepton>& leptonColl, std::vector<Lepton>& leptonCollLoose) {

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
    
    ElectronID = ElectronIDLoose = false;
    if (isEB) {
      if (fabs(DeltaEtaTrkSC[ilep]) < 0.0126 &&
	  fabs(DeltaPhiTrkSC[ilep]) < 0.107 &&
	  SigmaIEtaIEta[ilep] < 0.012 &&
	  HoE[ilep] < 0.186 &&
	  MissingHits[ilep] <= 2 &&
	  fabs(eInvMinusPInv[ilep]) < 0.239 &&
	  passConversionVeto[ilep] > 0 &&
	  LeptonRelIso < 0.161 &&
	  fabs(dxy) < 0.0621 &&
	  fabs(dz) < 0.613)
	ElectronIDLoose = true;
    }
    else if (isEE) {
      if (fabs(DeltaEtaTrkSC[ilep]) < 0.0109 &&
	  fabs(DeltaPhiTrkSC[ilep]) < 0.219 &&
	  SigmaIEtaIEta[ilep] < 0.0339 &&
	  HoE[ilep] < 0.0962 &&
	  MissingHits[ilep] <= 3 &&
	  fabs(eInvMinusPInv[ilep]) < 0.141 &&
	  passConversionVeto[ilep] > 0 &&
	  LeptonRelIso < 0.193 &&
	  dxy < 0.279 &&
	  dz < 0.947)
	ElectronIDLoose = true;
    }
    else
      cout<< "something wrong with electron ID Loose" <<endl;
    
    if (isEB) {
      if (fabs(DeltaEtaTrkSC[ilep]) < 0.0094 &&
	  fabs(DeltaPhiTrkSC[ilep]) < 0.0296 &&
	  SigmaIEtaIEta[ilep] < 0.0101 &&
	  HoE[ilep] < 0.0372 &&
	  MissingHits[ilep] <= 2 &&
	  fabs(eInvMinusPInv[ilep]) < 0.118 &&
	  passConversionVeto[ilep] > 0 &&
	  LeptonRelIso < 0.0987 &&
	  fabs(dxy) < 0.0151 &&
	  fabs(dz) < 0.238)
	ElectronID = true;
    }
    else if (isEE) {
      if (fabs(DeltaEtaTrkSC[ilep]) < 0.00773 &&
	  fabs(DeltaPhiTrkSC[ilep]) < 0.148 &&
	  SigmaIEtaIEta[ilep] < 0.0287 &&
	  HoE[ilep] < 0.0546 &&
	  MissingHits[ilep] <= 1 &&
	  fabs(eInvMinusPInv[ilep]) < 0.104 &&
	  passConversionVeto[ilep] > 0 &&
	  LeptonRelIso < 0.0902 &&
	  dxy < 0.0535 &&
	  dz < 0.572)
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

    if (ElectronIDLoose && etaPt) {
      leptonCollLoose.push_back( Lepton(leptonType, ilep, vLepton, EtaSc[ilep], LeptonchiNdof, dxy, dz, Charge[ilep], fakeType, looseTight, LeptonRelIso) );
    }
    
  }
  
  std::sort( leptonColl.begin(), leptonColl.end(), LeptonPTSorter );
  
}
