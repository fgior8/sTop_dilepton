#include "MuonSelection.h"

MuonSel::MuonSel() {};


MuonSel::~MuonSel() {};

void MuonSel::MuonSelection(Int_t *pdgId, Int_t *IsPF, Float_t *Eta, Float_t *Pt, Float_t *Px, Float_t *Py, Float_t *Pz, Float_t *E, Float_t *relIso, Int_t *Charge, Int_t *ValidHits, Int_t *PixelValidHits, Float_t *ValidStations, Int_t *LayersWithMeasurement, Float_t *GlobalChi2, Float_t *dxy_ver, Float_t *dz_ver, std::vector<Lepton>& leptonColl) {

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

void MuonSel::LooseMuonSelection(std::vector<Int_t> IsPF, std::vector<Int_t> IsTracker, vector<Int_t> IsGlobal, std::vector<Double_t> Eta, std::vector<Double_t> Phi, std::vector<Double_t> Pt, std::vector<Double_t> PtErr, std::vector<Double_t> E, std::vector<Double_t> TrkIso, std::vector<Double_t> ECalIso, std::vector<Double_t> HCalIso, std::vector<Double_t> ECalIsoDeposit, std::vector<Double_t> HCalIsoDeposit, std::vector<Int_t> Charge, std::vector<Int_t> ValidHits, std::vector<Int_t> PixelValidHits, std::vector<Int_t> ValidStations, std::vector<Int_t> LayersWithMeasurement, std::vector<Double_t> GlobalChi2, std::vector<Double_t> Trkdx, std::vector<Double_t> Trkdy, std::vector<Double_t> Trkdz, std::vector<Double_t> TrkIPToolsIP, std::vector<Double_t> TrkIPToolsIPError, Double_t Vertex_X, Double_t Vertex_Y, Double_t Vertex_Z, std::vector<Double_t> PUpt, std::vector<Lepton>& leptonColl) {
  /*

  for (UInt_t ilep=0; ilep<Pt.size(); ilep++) {

 
    LeptonchiNdof = GlobalChi2[ilep]; 

    dz = fabs(Trkdz[ilep]-Vertex_Z);
    dxy = sqrt(pow(Trkdx[ilep]-Vertex_X,2)+pow(Trkdy[ilep]-Vertex_Y,2));
    D0 = fabs( TrkIPToolsIP[ilep] );
    D0Error = TrkIPToolsIPError[ilep];
     
    vLepton.SetPtEtaPhiE(Pt[ilep], Eta[ilep], Phi[ilep], E[ilep]);

    fakeType = Lepton::unknown;
    looseTight = Lepton::Other;
    leptonType = Lepton::Muon;
 
    if (Pt[ilep] > 0.01)
      LeptonRelIso = (TrkIso[ilep] + std::max(0.0, ECalIso[ilep] + HCalIso[ilep] - 0.5*PUpt[ilep]))/Pt[ilep];
    else LeptonRelIso = 9999.;
    if (LeptonRelIso<0) LeptonRelIso=0.0001;
    
    if (D0Error < 1E-6) D0Error = 1E-6;


    (IsPF[ilep] && (IsTracker[ilep]==1 || IsGlobal[ilep]==1) ) ? individual = true :individual = false;

    (fabs(Eta[ilep]) < eta_cut && Pt[ilep] >= pt_cut_min && Pt[ilep] < pt_cut_max) ? etaPt=true : etaPt =false;

    (LeptonchiNdof<chiNdof_cut && LeptonRelIso < relIso_cut && fabs(dz-Vz)<dz_cut && fabs(dxy-Vxy)<dxy_cut && ( LeptonRelIso >= relIsoMIN_cut || LeptonchiNdof>=chiNdofMIN_cut || fabs(dxy-Vxy)>=dxyMIN_cut) ) ? RelIsod0Chi2=true : RelIsod0Chi2=false;
    //(LeptonchiNdof<chiNdof_cut && LeptonRelIso < relIso_cut && fabs(dz-Vz)<dz_cut && fabs(dxy-Vxy)<dxy_cut && ( LeptonRelIso >= relIsoMIN_cut || fabs(dxy-Vxy)>=dxyMIN_cut) ) ? RelIsod0Chi2=true : RelIsod0Chi2=false;
    //(LeptonchiNdof<chiNdof_cut && dz<dz_cut && dxy<dxy_cut && LeptonRelIso < relIso_cut && LeptonRelIso >= relIsoMIN_cut) ? RelIsod0Chi2=true : RelIsod0Chi2=false;

    if (etaPt && RelIsod0Chi2 && individual)
      leptonColl.push_back( Lepton(leptonType, ilep, vLepton, Eta[ilep], LeptonchiNdof, D0, D0Error, dxy, dz, Charge[ilep], fakeType, looseTight, LeptonRelIso) );
    
  }
  
  std::sort( leptonColl.begin(), leptonColl.end(), LeptonPTSorter );
  */
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
