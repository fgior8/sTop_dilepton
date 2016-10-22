#include "MuonSelection.h"

MuonSel::MuonSel() {};


MuonSel::~MuonSel() {};

void MuonSel::MuonSelection(Int_t nMuon, Int_t *pdgId, Int_t *IsPF, Float_t *Eta, Float_t *Pt, Float_t *Px, Float_t *Py, Float_t *Pz, Float_t *E, Float_t *relIso, Int_t *Charge, Int_t *ValidHits, Int_t *PixelValidHits, Float_t *ValidStations, Int_t *LayersWithMeasurement, Float_t *GlobalChi2, Float_t *dxy_ver, Float_t *dz_ver, std::vector<Lepton>& leptonColl) {

  for (UInt_t ilep=0; ilep<sizeof(Pt); ilep++) {
    if (fabs(pdgId[ilep])!=13) continue;
    LeptonchiNdof = GlobalChi2[ilep]; 

    dz = dz_ver[ilep];
    dxy = dxy_ver[ilep];   
    vLepton.SetPxPyPzE(Px[ilep], Py[ilep], Pz[ilep], E[ilep]);

    fakeType = Lepton::unknown;
    looseTight = Lepton::Other;
    leptonType = Lepton::Muon;
 
    LeptonRelIso = relIso[ilep];
    
    (IsPF[ilep]>0 && ValidHits[ilep]>0 && PixelValidHits[ilep]>0 && ValidStations[ilep]>1 && LayersWithMeasurement[ilep]>5) ? individual = true :individual = false;

    (fabs(Eta[ilep]) < eta_cut && Pt[ilep] >= pt_cut_min && Pt[ilep] < pt_cut_max) ? etaPt=true : etaPt =false;

    (LeptonchiNdof<chiNdof_cut && LeptonRelIso < relIso_cut && fabs(dz)<dz_cut && fabs(dxy)<dxy_cut && ( LeptonRelIso >= relIsoMIN_cut || LeptonchiNdof>=chiNdofMIN_cut || fabs(dxy)>=dxyMIN_cut) ) ? RelIsod0Chi2=true : RelIsod0Chi2=false;
 
    if (etaPt && RelIsod0Chi2 && individual) 
      leptonColl.push_back( Lepton(leptonType, ilep, vLepton, Eta[ilep], LeptonchiNdof, dxy, dz, Charge[ilep], fakeType, looseTight, LeptonRelIso) );
   
  }
  
  std::sort( leptonColl.begin(), leptonColl.end(), LeptonPTSorter );
  
}

void MuonSel::MuonSelectionWithLoose(Int_t nMuon, Int_t *pdgId, Int_t *IsPF, Int_t *IsGlobal, Int_t *IsTracker, Float_t *Eta, Float_t *Pt, Float_t *Px, Float_t *Py, Float_t *Pz, Float_t *E, Float_t *relIso, Int_t *Charge, Int_t *ValidHits, Int_t *PixelValidHits, Float_t *ValidStations, Int_t *LayersWithMeasurement, Float_t *GlobalChi2, Float_t *dxy_ver, Float_t *dz_ver, Int_t *mcMatchId, std::vector<Lepton>& leptonColl, std::vector<Lepton>& leptonCollLoose) {

  for (UInt_t ilep=0; ilep<nMuon; ilep++) {
    if (fabs(pdgId[ilep])!=13) continue;
    LeptonchiNdof = GlobalChi2[ilep]; 

    dz = dz_ver[ilep];
    dxy = dxy_ver[ilep];   
    vLepton.SetPxPyPzE(Px[ilep], Py[ilep], Pz[ilep], E[ilep]);

    fakeType = Lepton::unknown;
    looseTight = Lepton::Other;
    leptonType = Lepton::Muon;
 
    LeptonRelIso = relIso[ilep];
    
    if (IsPF[ilep]<0) continue;
    if ((IsGlobal[ilep]+IsTracker[ilep])<1) continue;
    
    (IsGlobal[ilep]>0 && ValidHits[ilep]>0 && PixelValidHits[ilep]>0 && ValidStations[ilep]>1 && LayersWithMeasurement[ilep]>5) ? individual = true :individual = false;

    (fabs(Eta[ilep]) < eta_cut && Pt[ilep] >= pt_cut_min && Pt[ilep] < pt_cut_max) ? etaPt=true : etaPt =false;

    (LeptonchiNdof<chiNdof_cut && LeptonRelIso < relIso_cut && fabs(dz)<dz_cut && fabs(dxy)<dxy_cut && ( LeptonRelIso >= relIsoMIN_cut || LeptonchiNdof>=chiNdofMIN_cut || fabs(dxy)>=dxyMIN_cut) ) ? RelIsod0Chi2=true : RelIsod0Chi2=false;
 
    if (etaPt && RelIsod0Chi2 && individual) 
      leptonColl.push_back( Lepton(leptonType, ilep, vLepton, Eta[ilep], LeptonchiNdof, dxy, dz, Charge[ilep], fakeType, looseTight, LeptonRelIso) );
    if (fabs(Eta[ilep]) < 2.5 && Pt[ilep] >=10 &&  LeptonRelIso < 0.6)
      leptonCollLoose.push_back( Lepton(leptonType, ilep, vLepton, Eta[ilep], LeptonchiNdof, dxy, dz, Charge[ilep], fakeType, looseTight, LeptonRelIso) );
   
  }
  
  std::sort( leptonColl.begin(), leptonColl.end(), LeptonPTSorter );
  //std::sort( leptonCollLoose.begin(), leptonCollLoose.end(), LeptonPTSorter );

}

void MuonSel::SetDeposits(Double_t ECalDeposit , Double_t HCalDeposit) {
    ECalDeposit ? ECalDeposit_max = ECalDeposit : ECalDeposit_max=400.0;
    HCalDeposit ? HCalDeposit_max = HCalDeposit : HCalDeposit_max=600.0;
    ECalDeposit_min = 0.0;
    HCalDeposit_min = 0.0;
}

void MuonSel::SetDeposits(Double_t ECalDeposit1 , Double_t HCalDeposit1, Double_t ECalDeposit2 , Double_t HCalDeposit2) {
    ECalDeposit1 ? ECalDeposit_min = ECalDeposit1 : ECalDeposit_min=0.0;
    HCalDeposit1 ? HCalDeposit_min = HCalDeposit1 : HCalDeposit_min=0.0;
    ECalDeposit2 ? ECalDeposit_max = ECalDeposit2 : ECalDeposit_max=4.0;
    HCalDeposit2 ? HCalDeposit_max = HCalDeposit2 : HCalDeposit_max=6.0;
}
