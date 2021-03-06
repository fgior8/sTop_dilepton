// https://twiki.cern.ch/twiki/bin/viewauth/CMS/BTagCalibration
#include "BTagSFUtil.h"
#include "BTagCalibrationStandalone.cc"
#include "Fall15TTbar.C"
//#include "Run2015_74X.h"

BTagSFUtil::BTagSFUtil(string MeasurementType, string BTagAlgorithm, TString OperatingPoint, int SystematicIndex, TString FastSimDataset, int Seed) {

  rand_ = new TRandom3(Seed);

  string CSVFileName = "/gpfs/csic_users/fgior8/sTop/Juan/sTop_dilepton/test/" + BTagAlgorithm + ".csv";
  BTagCalibration calib(BTagAlgorithm, CSVFileName);

  string SystematicFlagBC = "central";
  string SystematicFlagL  = "central";
  if (abs(SystematicIndex)<10) {
    if (SystematicIndex==-1 || SystematicIndex==-2) SystematicFlagBC = "down";
    if (SystematicIndex==+1 || SystematicIndex==+2) SystematicFlagBC = "up";
    if (SystematicIndex==-3) SystematicFlagL = "down";
    if (SystematicIndex==+3) SystematicFlagL = "up";
  }

  TaggerCut = -999.;
  TaggerName = BTagAlgorithm;
  TaggerOP = BTagAlgorithm;

  for (int itg = 0; itg<nSupportedTaggers; itg++) 
    if (SupportedTaggerName[itg]==TaggerName) iTagger = itg; 

  if (iTagger<0) 
    cout << " " << TaggerName << " not supported for " << CampaignName << endl;

  if (OperatingPoint=="Loose")  {
    TaggerOP += "L";
    TaggerCut = TaggerWP[iTagger][0];
    reader_bc = new BTagCalibrationReader(&calib, BTagEntry::OP_LOOSE, MeasurementType, SystematicFlagBC);
    reader_l  = new BTagCalibrationReader(&calib, BTagEntry::OP_LOOSE, LightMeasurementType,          SystematicFlagL);
    reader_bc_central = new BTagCalibrationReader(&calib, BTagEntry::OP_LOOSE, MeasurementType, "central");
    reader_l_central  = new BTagCalibrationReader(&calib, BTagEntry::OP_LOOSE, LightMeasurementType, "central");
  } else if (OperatingPoint=="Medium")  {
    TaggerOP += "M";
    TaggerCut = TaggerWP[iTagger][1];
    reader_bc = new BTagCalibrationReader(&calib, BTagEntry::OP_MEDIUM, MeasurementType, SystematicFlagBC);
    reader_l  = new BTagCalibrationReader(&calib, BTagEntry::OP_MEDIUM, LightMeasurementType, SystematicFlagL);
    reader_bc_central = new BTagCalibrationReader(&calib, BTagEntry::OP_MEDIUM, MeasurementType, "central");
    reader_l_central  = new BTagCalibrationReader(&calib, BTagEntry::OP_MEDIUM, LightMeasurementType, "central");
  } else if (OperatingPoint=="Tight")  {
    TaggerOP += "T";
    TaggerCut = TaggerWP[iTagger][2];
    reader_bc = new BTagCalibrationReader(&calib, BTagEntry::OP_TIGHT, MeasurementType, SystematicFlagBC);
    reader_l  = new BTagCalibrationReader(&calib, BTagEntry::OP_TIGHT, LightMeasurementType, SystematicFlagL);
    reader_bc_central = new BTagCalibrationReader(&calib, BTagEntry::OP_TIGHT, MeasurementType, "central");
    reader_l_central  = new BTagCalibrationReader(&calib, BTagEntry::OP_TIGHT, LightMeasurementType, "central");
  } 

  if (TaggerCut==-999.) 
    cout << " " << TaggerName << " not supported for " << OperatingPoint << " WP" << endl;

  //FastSimSystematic = 0;
  //if (abs(SystematicIndex)>10) FastSimSystematic = SystematicIndex%10;
  //GetFastSimPayload(BTagAlgorithm, FastSimDataset); // Run1 style
  IsFastSimDataset = false;

  if (FastSimDataset!="") {

    IsFastSimDataset = true;

    string FastSimName = "";
    for (int idt = 0; idt<nFastSimDatasets; idt++)
      if (FastSimDataset==FastSimDatasetName[idt]) FastSimName = FastSimDatasetName[idt];
    
    string FastSimCSVFileName = "../BTagSFUtil/FastSimCorrectionFactors/" + CampaignName + "/" + BTagAlgorithm + FastSimName + ".csv";
    BTagCalibration fastsimcalib(BTagAlgorithm, FastSimCSVFileName);
    
    string FastSimSystematicFlagB = "central";
    string FastSimSystematicFlagC = "central";
    string FastSimSystematicFlagL = "central";
    if (abs(SystematicIndex)>=11) {
      if (SystematicIndex==-11) FastSimSystematicFlagB = "down";
      if (SystematicIndex==+11) FastSimSystematicFlagB = "up";
      if (SystematicIndex==-12) FastSimSystematicFlagC = "down";
      if (SystematicIndex==+12) FastSimSystematicFlagC = "up";
      if (SystematicIndex==-13) FastSimSystematicFlagL = "down";
      if (SystematicIndex==+13) FastSimSystematicFlagL = "up";
    }

    if (OperatingPoint=="Loose")  {
      fastsim_b = new BTagCalibrationReader(&fastsimcalib, BTagEntry::OP_LOOSE, "fastsim", FastSimSystematicFlagB);
      fastsim_c = new BTagCalibrationReader(&fastsimcalib, BTagEntry::OP_LOOSE, "fastsim", FastSimSystematicFlagC);
      fastsim_l = new BTagCalibrationReader(&fastsimcalib, BTagEntry::OP_LOOSE, "fastsim", FastSimSystematicFlagL);
      fastsim_central = new BTagCalibrationReader(&fastsimcalib, BTagEntry::OP_LOOSE, "fastsim", "central");
    } else if (OperatingPoint=="Medium")  {
      fastsim_b = new BTagCalibrationReader(&fastsimcalib, BTagEntry::OP_MEDIUM, "fastsim", FastSimSystematicFlagB);
      fastsim_c = new BTagCalibrationReader(&fastsimcalib, BTagEntry::OP_MEDIUM, "fastsim", FastSimSystematicFlagC);
      fastsim_l = new BTagCalibrationReader(&fastsimcalib, BTagEntry::OP_MEDIUM, "fastsim", FastSimSystematicFlagL);
      fastsim_central = new BTagCalibrationReader(&fastsimcalib, BTagEntry::OP_MEDIUM, "fastsim", "central");
    } else if (OperatingPoint=="Tight")  {
      fastsim_b = new BTagCalibrationReader(&fastsimcalib, BTagEntry::OP_TIGHT, "fastsim", FastSimSystematicFlagB);
      fastsim_c = new BTagCalibrationReader(&fastsimcalib, BTagEntry::OP_TIGHT, "fastsim", FastSimSystematicFlagC);
      fastsim_l = new BTagCalibrationReader(&fastsimcalib, BTagEntry::OP_TIGHT, "fastsim", FastSimSystematicFlagL);
      fastsim_central = new BTagCalibrationReader(&fastsimcalib, BTagEntry::OP_TIGHT, "fastsim", "central");
    }
    
  }
  
}

BTagSFUtil::~BTagSFUtil() {

  delete rand_;

}

float BTagSFUtil::FastSimCorrectionFactor(int JetFlavor, float JetPt, float JetEta) {

  float CF = 1.;

  if (JetEta>2.4) {

    cout << "FastSim CF not supported for jet eta>2.4" << endl;
    return 0.;

  }

  if (JetPt<AbsoluteMinJetPt) {

    cout << "FastSim CF not supported for jet Pt<" << AbsoluteMinJetPt << endl;
    return 0.;

  }

  float ThisJetPt = JetPt;

  //int JetFlavorFlag = 2;
  //if (abs(JetFlavor)==4) JetFlavorFlag = 1;
  //else if (abs(JetFlavor)==5) JetFlavorFlag = 0;

  if (JetPt<MinJetPtFastSim)
    ThisJetPt = MinJetPtFastSim;

  if (JetPt>=MaxJetPtFastSim)
    ThisJetPt = MaxJetPtFastSim - 0.01;

  if (abs(JetFlavor)==5) 
    CF = fastsim_b->evaluate(BTagEntry::FLAV_B, JetEta, ThisJetPt, -1.);
  else if (abs(JetFlavor)==4) 
    CF = fastsim_c->evaluate(BTagEntry::FLAV_C, JetEta, ThisJetPt, -1.);
  else 
    CF = fastsim_l->evaluate(BTagEntry::FLAV_UDSG, JetEta, ThisJetPt, -1.);

  if (ThisJetPt!=JetPt) {

    float CF_Central;
    if (abs(JetFlavor)==5) 
      CF_Central = fastsim_central->evaluate(BTagEntry::FLAV_B, JetEta, ThisJetPt, -1.);
    else if (abs(JetFlavor)==4) 
      CF_Central = fastsim_central->evaluate(BTagEntry::FLAV_C, JetEta, ThisJetPt, -1.);
    else 
      CF_Central = fastsim_central->evaluate(BTagEntry::FLAV_UDSG, JetEta, ThisJetPt, -1.);
    
    if (CF!=CF_Central) 
      CF += (CF - CF_Central);
    
  } 
 
  /* Run1 style
  if (JetPt<FastSimPtBinEdge[0]) { cout << "CF is not available for jet pt<" << FastSimPtBinEdge[0] << " GeV" << endl; return -1.; }
  if (fabs(JetEta)>2.4) { cout << "CF is not available for jet |eta|>2.4" << endl; return -1.; }

  int JetFlavorFlag = 2;
  if (abs(JetFlavor)==4) JetFlavorFlag = 1;
  else if (abs(JetFlavor)==5) JetFlavorFlag = 0;

  int ThisFastSimSystematic = 0;
  if (abs(FastSimSystematic)==JetFlavorFlag+1) 
    ThisFastSimSystematic = FastSimSystematic/abs(FastSimSystematic);
 
  int JetPtBin = -1;
  for (int ptbin = 0; ptbin<nFastSimPtBins; ptbin++) 
    if (JetPt>=FastSimPtBinEdge[ptbin]) JetPtBin++;

  if (JetPt>=FastSimPtBinEdge[nFastSimPtBins]) ThisFastSimSystematic *= 2;

  int JetEtaBin = -1;  
  for (int etabin = 0; etabin<nFastSimEtaBins[JetFlavorFlag]; etabin++) 
    if (fabs(JetEta)>=FastSimEtaBinEdge[etabin][JetFlavorFlag]) JetEtaBin++;
    
  CF = FastSimCF[JetPtBin][JetEtaBin][JetFlavorFlag] + ThisFastSimSystematic*FastSimCF_error[JetPtBin][JetEtaBin][JetFlavorFlag];

  if (CF<0.) CF = 0.; // Effect of large uncertainties on light CFs!

  */

  return CF;

}

float BTagSFUtil::JetTagEfficiency(int JetFlavor, float JetPt, float JetEta) {

  if (abs(JetFlavor)==5) return TagEfficiencyB(JetPt, JetEta);
  else if (abs(JetFlavor)==4) return TagEfficiencyC(JetPt, JetEta);
  else return TagEfficiencyLight(JetPt, JetEta);

}

float BTagSFUtil::GetJetSF(int JetFlavor, float JetPt, float JetEta) {

  if (JetEta>2.4) {

    cout << "SF not supported for jet eta>2.4" << endl;
    return 0.;

  }

  if (JetPt<AbsoluteMinJetPt) {

    cout << "SF not supported for jet Pt<" << AbsoluteMinJetPt << endl;
    return 0.;

  }
    
  float Btag_SF;

  float ThisJetPt = JetPt;

  int JetFlavorFlag = 2;
  if (abs(JetFlavor)==4) JetFlavorFlag = 1;
  else if (abs(JetFlavor)==5) JetFlavorFlag = 0;
   
  if (JetPt<MinJetPt[JetFlavorFlag][iTagger])
    ThisJetPt = MinJetPt[JetFlavorFlag][iTagger];

  if (JetPt>=MaxJetPt[JetFlavorFlag][iTagger])
    ThisJetPt = MaxJetPt[JetFlavorFlag][iTagger] - 0.01;

  if (abs(JetFlavor)==5) 
    Btag_SF = reader_bc->evaluate(BTagEntry::FLAV_B, JetEta, ThisJetPt, -1.);
  else if (abs(JetFlavor)==4) 
    Btag_SF = reader_bc->evaluate(BTagEntry::FLAV_C, JetEta, ThisJetPt, -1.);
  else 
    Btag_SF = reader_l->evaluate(BTagEntry::FLAV_UDSG, JetEta, ThisJetPt, -1.);

  if (ThisJetPt!=JetPt) {

    float Btag_SF_Central;
    if (abs(JetFlavor)==5) 
      Btag_SF_Central = reader_bc_central->evaluate(BTagEntry::FLAV_B, JetEta, ThisJetPt, -1.);
    else if (abs(JetFlavor)==4) 
      Btag_SF_Central = reader_bc_central->evaluate(BTagEntry::FLAV_C, JetEta, ThisJetPt, -1.);
    else 
      Btag_SF_Central = reader_l_central->evaluate(BTagEntry::FLAV_UDSG, JetEta, ThisJetPt, -1.);
    
    if (Btag_SF!=Btag_SF_Central) 
      Btag_SF += (Btag_SF - Btag_SF_Central);
    
  }

  if (IsFastSimDataset)
    Btag_SF *= FastSimCorrectionFactor(JetFlavor, JetPt, JetEta);
  
  return Btag_SF;
  
}

bool BTagSFUtil::IsTaggedMC(float JetDiscriminant) {

  return JetDiscriminant>TaggerCut;

}

bool BTagSFUtil::IsTagged(float JetDiscriminant, int JetFlavor, float JetPt, float JetEta) {
  
  bool isBTagged = JetDiscriminant>TaggerCut;

  if (JetFlavor==-999999) return isBTagged; // Data: no correction needed

  bool newBTag = isBTagged;

  float Btag_SF = GetJetSF(JetFlavor, JetPt, JetEta);
  
  if (Btag_SF == 1) return newBTag; //no correction needed 

  //throw die
  float coin = rand_->Uniform(1.);    
 
  if(Btag_SF > 1){  // use this if SF>1

    if( !isBTagged ) {

      float Btag_eff = JetTagEfficiency(JetFlavor, JetPt, fabs(JetEta));

      //fraction of jets that need to be upgraded
      float mistagPercent = (1.0 - Btag_SF) / (1.0 - (1./Btag_eff) );
      
      //upgrade to tagged
      if( coin < mistagPercent ) {newBTag = true;}
    }

  }else{  // use this if SF<1
      
    //downgrade tagged to untagged
    if( isBTagged && coin > Btag_SF ) {newBTag = false;}

  }

  return newBTag;

}

