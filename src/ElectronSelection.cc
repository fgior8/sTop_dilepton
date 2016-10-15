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
    
    if (isEB) {
      if (fabs(DeltaEtaTrkSC[ilep]) < 0.00308 &&
	  fabs(DeltaPhiTrkSC[ilep]) < 0.0816 &&
	  SigmaIEtaIEta[ilep] < 0.00998 &&
	  HoE[ilep] < 0.0414 &&
	  MissingHits[ilep] <= 1 &&
	  fabs(eInvMinusPInv[ilep]) < 0.0129 &&
	  passConversionVeto[ilep] > 0 &&
	  LeptonRelIso < 0.0588 &&
	  fabs(dxy) < 0.05 &&
	  fabs(dz) < 0.10)
	ElectronID = true;
    }
    else if (isEE) {
      if (fabs(DeltaEtaTrkSC[ilep]) < 0.00605 &&
	  fabs(DeltaPhiTrkSC[ilep]) < 0.0394 &&
	  SigmaIEtaIEta[ilep] < 0.0292 &&
	  HoE[ilep] < 0.0641 &&
	  MissingHits[ilep] <= 1 &&
	  fabs(eInvMinusPInv[ilep]) < 0.0129 &&
	  passConversionVeto[ilep] > 0 &&
	  LeptonRelIso < 0.0571 &&
	  dxy < 0.10 &&
	  dz < 0.20)
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
      if (fabs(DeltaEtaTrkSC[ilep]) < 0.00749 &&
	  fabs(DeltaPhiTrkSC[ilep]) < 0.228 &&
	  SigmaIEtaIEta[ilep] < 0.0115 &&
	  HoE[ilep] < 0.356 &&
	  MissingHits[ilep] <= 2 &&
	  fabs(eInvMinusPInv[ilep]) < 0.299 &&
	  passConversionVeto[ilep] > 0 &&
	  LeptonRelIso < 0.175 &&
	  fabs(dxy) < 0.20 &&
	  fabs(dz) < 0.50)
	ElectronIDLoose = true;
    }
    else if (isEE) {
      if (fabs(DeltaEtaTrkSC[ilep]) < 0.00895 &&
	  fabs(DeltaPhiTrkSC[ilep]) < 0.213 &&
	  SigmaIEtaIEta[ilep] < 0.037 &&
	  HoE[ilep] < 0.211 &&
	  MissingHits[ilep] <= 3 &&
	  fabs(eInvMinusPInv[ilep]) < 0.15 &&
	  passConversionVeto[ilep] > 0 &&
	  LeptonRelIso < 0.159 &&
	  dxy < 0.20 &&
	  dz < 0.50)
	ElectronIDLoose = true;
    }
    else
      cout<< "something wrong with electron ID Loose" <<endl;
    
    if (isEB) {
      if (fabs(DeltaEtaTrkSC[ilep]) < 0.00308 &&
	  fabs(DeltaPhiTrkSC[ilep]) < 0.0816 &&
	  SigmaIEtaIEta[ilep] < 0.00998 &&
	  HoE[ilep] < 0.0414 &&
	  MissingHits[ilep] <= 1 &&
	  fabs(eInvMinusPInv[ilep]) < 0.0129 &&
	  passConversionVeto[ilep] > 0 &&
	  LeptonRelIso < 0.0588 &&
	  fabs(dxy) < 0.05 &&
	  fabs(dz) < 0.10)
	ElectronID = true;
    }
    else if (isEE) {
      if (fabs(DeltaEtaTrkSC[ilep]) < 0.00605 &&
	  fabs(DeltaPhiTrkSC[ilep]) < 0.0394 &&
	  SigmaIEtaIEta[ilep] < 0.0292 &&
	  HoE[ilep] < 0.0641 &&
	  MissingHits[ilep] <= 1 &&
	  fabs(eInvMinusPInv[ilep]) < 0.0129 &&
	  passConversionVeto[ilep] > 0 &&
	  LeptonRelIso < 0.0571 &&
	  dxy < 0.10 &&
	  dz < 0.20)
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

    if (ElectronIDLoose && fabs(vLepton.Eta()) < 2.5 && Pt[ilep] >= 10) {
      leptonCollLoose.push_back( Lepton(leptonType, ilep, vLepton, EtaSc[ilep], LeptonchiNdof, dxy, dz, Charge[ilep], fakeType, looseTight, LeptonRelIso) );
    }
    
  }
  
  std::sort( leptonColl.begin(), leptonColl.end(), LeptonPTSorter );
  
}
