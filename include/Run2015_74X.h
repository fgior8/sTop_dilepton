//#include "../src/Fall15TTbar.C"
//#include "../FastSimCorrectionFactors/Summer12.C"

string CampaignName = "Run2015_74X";

string LightMeasurementType = "comb";

float AbsoluteMinJetPt = 20.;

const int nSupportedTaggers = 2;
TString SupportedTaggerName[nSupportedTaggers] = {"JP", "CSVv2"};
float MinJetPt[3][nSupportedTaggers] = { { 30.,  30.},   {30., 30.}, {  20.,   20.} };
float MaxJetPt[3][nSupportedTaggers] = { {670., 670.}, {670., 670.}, {1000., 1000.} };
float TaggerWP[nSupportedTaggers][3] = { {0.275, 0.545, 0.790}, {0.605, 0.890, 0.970} };

const int nFastSimDatasets = 4;
TString FastSimDatasetName[nFastSimDatasets] = {"_T1tttt_1200_800", "_T1tttt_1500_100", "_T1bbbb_1000_900", "_T1bbbb_1500_100"};
float MinJetPtFastSim =  20.;
float MaxJetPtFastSim = 800.;

