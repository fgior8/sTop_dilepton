#include "../src/Fall15TTbar.C"
//#include "../FastSimCorrectionFactors/Summer12.C"

string CampaignName = "Run2015_76X";

string LightMeasurementType = "incl";

float AbsoluteMinJetPt = 20.;

const int nSupportedTaggers = 3;
TString SupportedTaggerName[nSupportedTaggers] = {"JP", "CSVv2", "cMVAv2"};
float MinJetPt[3][nSupportedTaggers] = { { 30.,  30.,  30.},   {30., 30., 30.}, {  20.,   20.,   20.} };
float MaxJetPt[3][nSupportedTaggers] = { {670., 670., 320.}, {670., 670., 320}, {1000., 1000., 1000.} };
float TaggerWP[nSupportedTaggers][3] = { {0.245, 0.515, 0.760}, {0.460, 0.800, 0.935}, {-0.715, 0.185, 0.875} };

const int nFastSimDatasets = 4;
TString FastSimDatasetName[nFastSimDatasets] = {"_T1tttt_1200_800", "_T1tttt_1500_100", "_T1bbbb_1000_900", "_T1bbbb_1500_100"};
float MinJetPtFastSim =  20.;
float MaxJetPtFastSim = 800.;

