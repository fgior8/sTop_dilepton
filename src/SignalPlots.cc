#include "SignalPlots.h"

const float pi = 3.14159265359;
SignalPlots::SignalPlots(TString name) {
  h_Ptllb =          new TH1F("h_Ptllb_"         + name,"P_{Tb}^{ll}", 70, 0, 700);
  h_Meff =           new TH1F("h_Meff_"          + name,"M_{Eff}", 200, 0, 2000);
  h_dPhill =         new TH1F("h_dPhill_"        + name,"|#Delta#Phi_{ll}| [rad / pi]", 50, 0, 1);
  h_dPhiLepMet =     new TH1F("h_dPhiLepMet_"    + name,"|#Delta#Phi_{l,MET}| [rad / pi]", 50, 0, 1);
  h_dPhiLepJet =     new TH1F("h_dPhiLepJet_"    + name,"|#Delta#Phi_{l,j}| [rad / pi]", 50, 0, 1);
  h_dPhiJetMet =     new TH1F("h_dPhiJetMet_"    + name,"|#Delta#Phi_{closest-jet,MET}| [rad / pi]", 50, 0, 1);
  h_dPhiPtllbMet =   new TH1F("h_dPhiPtllbMet_"  + name,"|#Delta#Phi_{P_{Tb}^{ll},MET}| [rad / pi]", 50, 0, 1);
  h_jjmass =         new TH1F("h_dijetsmass_"    + name,"Invariant mass of the two leading jets",100,0,1000);
  h_llmass =         new TH1F("h_llmass_"        + name,"Invariant mass of the two leading leptons",100,0,1000);
  h_lljjmass =       new TH1F("h_lljjmass_"      + name,"Invariant mass of the four particles",200,0,2000);
  h_HT =             new TH1F("h_HT_"            + name,"Jet sum p_{T}",500,0.0,5000.0);
  h_MET2HT =         new TH1F("h_MET2HT_"        + name,"E_{T}^{2}/HT ",100,0.0,1000.0);
  h_MET =            new TH1F("h_MET_"           + name,"Missing Et",100,0.0,500.0);
  h_MET_phi =        new TH1F("h_MET_phi_"       + name,"Missing Et #phi",100,-3.14,3.14);
  h_METexp =         new TH1F("h_METexp_"        + name,"MET * (MET/HT) * exp(-MET/HT)",100,0.0,500.0);
  h_MT2ll =          new TH1F("h_MT2ll_"         + name,"MT2(ll)",50,0.0,250.0);
  h_MT2bb =          new TH1F("h_MT2bb_"         + name,"MT2(bb)",100,80.0,580.0);
  h_MT2lblb =        new TH1F("h_MT2lblb_"       + name,"MT2(lblb)",110,0.0,550.0);
  h_dilepPt =        new TH1F("h_dilepPt_"       + name,"Sum dilepton p_{T}",100,0.0,500.0);
  h_cosTheta1 =      new TH1F("h_cosTheta1_"     + name,"cos#theta #mu^{+}",50,-1,1);
  h_cosTheta2 =      new TH1F("h_cosTheta2_"     + name,"cos#theta #mu^{-}",50,-1,1);
  h_DeltaPhiZ =      new TH1F("h_DeltaPhiZ_"     + name,"cos#phi between Z and MET",50,-1.,1.);
  h_DeltaPhiLep1 =   new TH1F("h_DeltaPhiLep1_"  + name,"cos#phi between lep_{1} and MET",50,-1.,1.);
  h_DeltaPhiLep2 =   new TH1F("h_DeltaPhiLep2_"  + name,"cos#phi between lep_{2} and MET",50,-1.,1.);
  h_DeltaPhiJet1 =   new TH1F("h_DeltaPhiJet1_"  + name,"cos#phi between jet_{1} and MET",50,-1.,1.);
  h_DeltaPhiJet2 =   new TH1F("h_DeltaPhiJet2_"  + name,"cos#phi between jet_{2} and MET",50,-1.,1.);
  h_DeltaPhiJetMin = new TH1F("h_DeltaPhiJetMin_"+ name,"cos#phi min (jet_{1} and jet_{2}) and MET",50,-1.,1.);
  h_MT2ll_DeltaPhiZ= new TH2F("h_MT2ll_DeltaPhiZ_"+ name,"MT2(ll) vs cos#theta #mu^{-}",50,0.0,250.,50,-1.,1.);
  h_MT2ll_DeltaPhiJetMin=new TH2F("h_MT2ll_DeltaPhiJetMin_"+ name,"MT2(ll) vs cos#phi min (jet_{1} and jet_{2}) and MET",50,0.0,250.,50,-1.,1.);
  h_MT2ll_CosTheta = new TH2F("h_MT2ll_CosTheta_"+ name,"MT2(ll) vs cos#phi between Z and MET",50,0.0,250.,50,-1.,1.);
  h_PV =             new TH1F("h_PV_"            + name,"number of primary vertices",60,0,60);
  h3_MT2 =           new TH3F("h3_MT2_"          + name,"MT2(ll) vs (lblb) vs (bb)",50,0.0,250.0,110,0.0,550.0,100,80.0,580.0);
  
}

SignalPlots::~SignalPlots() {
  delete h_Ptllb;
  delete h_Meff;
  delete h_dPhill;
  delete h_dPhiLepMet;
  delete h_dPhiLepJet;
  delete h_dPhiJetMet;
  delete h_dPhiPtllbMet;
  delete h_jjmass;
  delete h_llmass;
  delete h_lljjmass;
  delete h_HT;
  delete h_MET2HT;
  delete h_MET;
  delete h_MET_phi;
  delete h_METexp;
  delete h_MT2ll;
  delete h_MT2bb;
  delete h_MT2lblb;
  delete h_dilepPt;
  delete h_cosTheta1;
  delete h_cosTheta2;
  delete h_DeltaPhiZ;
  delete h_DeltaPhiLep1;
  delete h_DeltaPhiLep2;
  delete h_DeltaPhiJet1;
  delete h_DeltaPhiJet2;
  delete h_DeltaPhiJetMin;
  delete h_MT2ll_DeltaPhiZ;
  delete h_MT2ll_DeltaPhiJetMin;
  delete h_MT2ll_CosTheta;
  delete h_PV;
  delete h3_MT2;
}

void SignalPlots::Fill(UInt_t numberVertices, Float_t MET, Float_t MET_phi, Float_t HT, std::vector<Lepton>& leptons, std::vector<Jet>& jets, Float_t weight, Int_t channel, Int_t cut) {
  m=0; n=1; i=0; j=1;
    
  h_PV->Fill(numberVertices, weight);
  h_MET->Fill(MET, weight);
  h_MET_phi->Fill(MET_phi, weight);
  h_llmass->Fill( (leptons[i].lorentzVec()+leptons[j].lorentzVec()).M(),weight);
  h_dilepPt->Fill( leptons[i].lorentzVec().Pt()+leptons[j].lorentzVec().Pt(),weight);
  h_HT->Fill(HT,weight);
  if (HT>0) {
    h_MET2HT->Fill(pow(MET,2)/HT,weight);
    h_METexp->Fill(pow(MET,2)/HT * exp(-MET/HT), weight);
  }
  else {
    h_MET2HT->Fill(0);
    h_METexp->Fill(0);
  }
  h_MT2ll->Fill(getMT2(leptons[i].lorentzVec(), leptons[j].lorentzVec(), MET, MET_phi), weight);

  if (cut>1) {
    h_MT2bb->Fill( getMT2bb(jets, leptons, MET, MET_phi), weight);
    h_MT2lblb->Fill( getMT2lblb(jets, leptons, MET, MET_phi), weight);  
    h3_MT2->Fill(getMT2(leptons[i].lorentzVec(), leptons[j].lorentzVec(), MET, MET_phi), getMT2lblb(jets, leptons, MET, MET_phi), getMT2bb(jets, leptons, MET, MET_phi), weight);
    h_jjmass->Fill( (jets[m].lorentzVec()+jets[n].lorentzVec()).M(), weight);
    h_lljjmass->Fill( (leptons[i].lorentzVec()+leptons[j].lorentzVec()+jets[m].lorentzVec()+jets[n].lorentzVec()).M(), weight);
    h_Ptllb->Fill(getllmetVector(leptons[0].lorentzVec(), leptons[1].lorentzVec(), MET, MET_phi).Pt(), weight);
    h_Meff->Fill(getMeff(jets, leptons, MET), weight);
    h_dPhill->Fill(fabs(leptons[0].lorentzVec().DeltaPhi(leptons[1].lorentzVec()))/pi, weight);
    h_dPhiLepMet->Fill(fabs(getdPhiLepMet(leptons[0].lorentzVec(), MET, MET_phi))/pi, weight);
    h_dPhiLepJet->Fill(fabs(leptons[0].lorentzVec().DeltaPhi(jets[0].lorentzVec()))/pi, weight);
    h_dPhiJetMet->Fill(fabs(getdPhiJetMet(jets, MET, MET_phi))/pi, weight);
    h_dPhiPtllbMet->Fill(fabs(getdPhiPtllbMet(getllmetVector(leptons[0].lorentzVec(), leptons[1].lorentzVec(), MET, MET_phi), MET, MET_phi))/pi, weight);
  }
  //TLorentzVector MET_tv;
  MET_tv.SetPtEtaPhiE(MET,0.,MET_phi,MET);
  
  h_DeltaPhiLep1->Fill(cos(leptons[i].lorentzVec().DeltaPhi(MET_tv)),weight);
  h_DeltaPhiLep2->Fill(cos(leptons[j].lorentzVec().DeltaPhi(MET_tv)),weight);
  h_DeltaPhiZ->Fill(cos( (leptons[i].lorentzVec()+leptons[j].lorentzVec()).DeltaPhi(MET_tv) ),weight);
  h_MT2ll_DeltaPhiZ->Fill(getMT2(leptons[i].lorentzVec(), leptons[j].lorentzVec(), MET, MET_phi), cos( (leptons[i].lorentzVec()+leptons[j].lorentzVec()).DeltaPhi(MET_tv) ),weight);
  if (cut>1) {
    h_DeltaPhiJet1->Fill(cos(jets[i].lorentzVec().DeltaPhi(MET_tv)),weight);
    h_DeltaPhiJet2->Fill(cos(jets[j].lorentzVec().DeltaPhi(MET_tv)),weight);
    if ( jets[i].lorentzVec().DeltaPhi(MET_tv) < jets[j].lorentzVec().DeltaPhi(MET_tv) ) {
      h_DeltaPhiJetMin->Fill(cos(jets[i].lorentzVec().DeltaPhi(MET_tv)),weight);
      h_MT2ll_DeltaPhiJetMin->Fill(getMT2(leptons[i].lorentzVec(), leptons[j].lorentzVec(), MET, MET_phi), cos(jets[i].lorentzVec().DeltaPhi(MET_tv)),weight);
    }
    else {
      h_DeltaPhiJetMin->Fill(cos(jets[j].lorentzVec().DeltaPhi(MET_tv)),weight);
      h_MT2ll_DeltaPhiJetMin->Fill(getMT2(leptons[i].lorentzVec(), leptons[j].lorentzVec(), MET, MET_phi), cos(jets[i].lorentzVec().DeltaPhi(MET_tv)),weight);
    }
  }
  //Boost dilep_beta(-(leptons[i].lorentzVec()+leptons[j].lorentzVec()).Px()/(leptons[i].lorentzVec()+leptons[j].lorentzVec()).E(), -(leptons[i].lorentzVec()+leptons[j].lorentzVec()).Py()/(leptons[i].lorentzVec()+leptons[j].lorentzVec()).E(), -(leptons[i].lorentzVec()+leptons[j].lorentzVec()).Pz()/dilep_p4.E())
  dilep_beta = (leptons[i].lorentzVec()+leptons[j].lorentzVec()).BoostVector();
  //TLorentzVector lp,lm;
  if(leptons[i].charge() < 0) {
    lm = leptons[i].lorentzVec();
    lp = leptons[j].lorentzVec();
  }
  else {
    lm = leptons[j].lorentzVec();
    lp = leptons[i].lorentzVec();
  }
  lm.Boost(-dilep_beta);
  lp.Boost(-dilep_beta);

  h_cosTheta2->Fill( cos(lm.Theta()) ,weight);
  h_cosTheta1->Fill( cos(lp.Theta()) ,weight);
  h_MT2ll_CosTheta->Fill(getMT2(leptons[i].lorentzVec(), leptons[j].lorentzVec(), MET, MET_phi), cos(lm.Theta()) ,weight);
  
  // x1V = (leptons[i].lorentzVec().e() + leptons[j].lorentzVec().e() + leptons[i].lorentzVec().pz() + leptons[j].lorentzVec().pz())/13000.;
  // x2V = (leptons[i].lorentzVec().e() + leptons[j].lorentzVec().e() - leptons[i].lorentzVec().pz() - leptons[j].lorentzVec().pz())/13000.;
  /*
  Boost dilep_beta(-dilep_p4.px()/dilep_p4.e(), -dilep_p4.py()/dilep_p4.e(), -dilep_p4.pz()/dilep_p4.e());
  auto cm_p4 = lep1_id > 0 ? dilep_beta(lep1_p4) : dilep_beta(lep2_p4);
  costhetaV = cos(cm_p4.theta());
  x1V = (lep1_p4.e() + lep2_p4.e() + lep1_p4.pz() + lep1_p4.pz())/13000.;
  x2V = (lep1_p4.e() + lep2_p4.e() - lep1_p4.pz() - lep1_p4.pz())/13000.;
  */
}

void SignalPlots::Write() {
  h_jjmass->Write();
  h_llmass->Write();
  h_lljjmass->Write();
  h_HT->Write();
  h_MET2HT->Write();
  h_MET->Write();
  h_MET_phi->Write();
  h_METexp->Write();
  h_MT2ll->Write();
  h_MT2bb->Write();
  h_MT2lblb->Write();
  h_dilepPt->Write();
  h_cosTheta1->Write();
  h_cosTheta2->Write();
  h_DeltaPhiZ->Write();
  h_DeltaPhiLep1->Write();
  h_DeltaPhiLep2->Write();
  h_DeltaPhiJet1->Write();
  h_DeltaPhiJet2->Write();
  h_DeltaPhiJetMin->Write();
  h_MT2ll_DeltaPhiZ->Write();
  h_MT2ll_DeltaPhiJetMin->Write();
  h_MT2ll_CosTheta->Write();
  h_PV->Write();
  h3_MT2->Write();
  h_Ptllb->Write();
  h_Meff->Write();
  h_dPhill->Write();
  h_dPhiLepMet->Write();
  h_dPhiLepJet->Write();
  h_dPhiJetMet->Write();
  h_dPhiPtllbMet->Write();
}

