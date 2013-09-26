#include "General.h"
#include "DYestimate.h"

void DYestimate(){
  
  std::vector<float> MM_2jets;
  DYestimate("mumu","2Jets", MM_2jets);
  std::vector<float> EE_2jets;
  DYestimate("ee","2Jets", EE_2jets);
  std::vector<float> MM_MET;
  DYestimate("mumu","MET", MM_MET);
  std::vector<float> EE_MET;
  DYestimate("ee","MET", EE_MET);
  std::vector<float> MM_1btag;
  DYestimate("mumu","1btag", MM_1btag);
  std::vector<float> EE_1btag;
  DYestimate("ee","1btag", EE_1btag);


  std::vector<float> MM_MT2ll;
  DYestimate("mumu","1btag", MM_MT2ll);
  std::vector<float> EE_MT2ll;
  DYestimate("ee","1btag", EE_MT2ll);


  TString filename = Form("DYestimate.tex");
  FILE* fp = fopen(filename.Data(), "w");

  cout << filename << endl;

  // Save table
  //----------------------------------------------------------------------------
  fprintf(fp,"\\begin{table}[htbp!]\n");
  fprintf(fp,"\\begin{center}\n");
  fprintf(fp,"\\begin{small}\n");

  fprintf(fp,"\\begin{tabular}{|l|c|c|c|}\n");
  fprintf(fp,"\\hline\n");
  fprintf(fp,"  & $\\geq$ 2 jets & $\\geq$ 2 jets + \\MET & $\\geq$ 2 jets + \\MET + $\\geq$ 1 btag \\\\ \\hline \n");
  fprintf(fp,"\\hline\n");
  fprintf(fp, " ee & &  & \\\\ \n");
  fprintf(fp, "%s & %.1f $\\pm$ %.1f & %.1f $\\pm$ %.1f & %.1f $\\pm$ %.1f \\\\ \n", 
	  "DY MC",                      EE_2jets[0], EE_2jets[1], EE_MET[0], EE_MET[1], EE_1btag[0], EE_1btag[1]);
  fprintf(fp, "%s & %.1f $\\pm$ %.1f & %.1f $\\pm$ %.1f & %.1f $\\pm$ %.1f \\\\ \n", 
	  "DY data-driven estimate ",   EE_2jets[2], sqrt(EE_2jets[2]*EE_2jets[2]*(0.3*0.3) + EE_2jets[3]*EE_2jets[3]), 
	  EE_MET[2],   sqrt(EE_MET[2]*EE_MET[2]*(0.3*0.3) + EE_MET[3]*EE_MET[3]), 
	  EE_1btag[2], sqrt(EE_1btag[2]*EE_1btag[2]*(0.3*0.3) + EE_1btag[3]*EE_1btag[3]));
  fprintf(fp, "%s & %.3f $\\pm$ %.3f & %.3f $\\pm$ %.3f & %.3f $\\pm$ %.3f \\\\ \n", 
	  "$R_{out/in}$", EE_2jets[4], EE_2jets[5], EE_MET[4], EE_MET[5], EE_1btag[4], EE_1btag[5]);
  fprintf(fp,"\\hline \n");
  fprintf(fp, "%s & %.3f & %.3f & %.3f \\\\ \n", 
	  "SF data/MC",                      EE_2jets[2]/EE_2jets[0], EE_MET[2]/EE_MET[0], EE_1btag[2]/EE_1btag[0]);
  fprintf(fp,"\\hline \n");
  fprintf(fp,"\\hline\n");
  fprintf(fp, "\\mumu & & & \\\\ \n");
  fprintf(fp, "%s & %.1f $\\pm$ %.1f & %.1f $\\pm$ %.1f & %.1f $\\pm$ %.1f \\\\ \n", 
	  "DY MC",                      MM_2jets[0], MM_2jets[1], MM_MET[0], MM_MET[1], MM_1btag[0], MM_1btag[1]);;
  fprintf(fp, "%s & %.1f $\\pm$ %.1f & %.1f $\\pm$ %.1f & %.1f $\\pm$ %.1f \\\\ \n", 
   	  "DY data-driven estimate ",   MM_2jets[2], sqrt( MM_2jets[2]*MM_2jets[2]*(0.3*0.3) + MM_2jets[3]*MM_2jets[3]), 
	  MM_MET[2],   sqrt(MM_MET[2]*MM_MET[2]*(0.3*0.3) + MM_MET[3]*MM_MET[3]), 
	  MM_1btag[2], sqrt(MM_1btag[2]*MM_1btag[2]*(0.3*0.3) + MM_1btag[3]*MM_1btag[3]));
  fprintf(fp, "%s & %.3f $\\pm$ %.3f & %.3f $\\pm$ %.3f & %.3f $\\pm$ %.3f \\\\ \n", 
	  "$R_{out/in}$", MM_2jets[4], MM_2jets[5], MM_MET[4], MM_MET[5], MM_1btag[4], MM_1btag[5]);
  fprintf(fp,"\\hline \n");
  fprintf(fp, "%s & %.3f & %.3f & %.3f \\\\ \n", 
	  "SF data/MC",                      MM_2jets[2]/MM_2jets[0], MM_MET[2]/MM_MET[0], MM_1btag[2]/MM_1btag[0]);
  fprintf(fp,"\\hline\n");
  fprintf(fp,"\\end{tabular}\n");
  fprintf(fp,"\\end{small}\n");
  fprintf(fp,"\\end{center}\n");
  fprintf(fp,"\\caption{Data-driven Drell-Yan background estimation in the ee and \\mumu $ $ channels compared with simulation, for several steps of the analysis.}\\label{tab:dy}\n");
  fprintf(fp,"\\end{table}\n");
  
  fclose(fp);

}

int DYestimate(TString channel, TString cut, std::vector<float> &result){
  
  if(cut != "2Jets" && cut != "MET" && cut != "1btag" && cut != "2btag" && cut != "MT2ll") return 1;

  if(cut == "2btag") return DYestimate(channel,"1btag", result); 

  if ( channel != "mumu" && channel != "ee" ) return 1; 

  result.clear();
 
  float DYMC_in  = 0.;
  float DYMC_out = 0.;
  
  float Entries_DYMC_in  = 0.;
  float Entries_DYMC_out = 0.;
  
  float EvData_in_mumu = 0.;
  float EvData_in_ee = 0.;

  float EvData_in = 0.;
  float EvData_in_mue = 0.;
  
  TFile *f = NULL; 
  //f = TFile::Open("StopResults/stop/h"+fl+"_ZDY.root");
  f = TFile::Open(dirnameIn+"h"+fl+"_ZDY.root");
 
  TString htitle_Z_In  = "hDYIn_" + channel + "_" + cut;
  TString htitle_Z_Out = "hDYOut_" + channel + "_" + cut;

  TH1F* dummy;

  dummy = (TH1F*) f->Get(htitle_Z_In);
  // Entries
  Entries_DYMC_in  = dummy->GetEntries();  
  // To include Triggers
  if (channel == "mumu") dummy->Scale(SFmumu);
  else if (channel == "ee") dummy->Scale(SFee);
  DYMC_in  = dummy->Integral(-1,1000);

  dummy = (TH1F*) f->Get(htitle_Z_Out);
  // Entries
  Entries_DYMC_out  = dummy->GetEntries();  
  // To include Triggers
  if (channel == "mumu")  dummy->Scale(SFmumu);
  else if (channel == "ee") dummy->Scale(SFee);
  DYMC_out  = dummy->Integral(-1,1000);

  //TFile *fMu = TFile::Open("StopResults/stop/h"+fl+"_DataMu12.root");
  TFile *fMu = TFile::Open(dirnameIn+"h"+fl+"_DataMu12.root");
  
  TString htitle_In_Data_mumu  = "hDYIn_mumu_2Jets";
  dummy = (TH1F*) fMu->Get(htitle_In_Data_mumu);
  EvData_in_mumu  = dummy->Integral(-1,1000);  

  //TFile *fEG = TFile::Open("StopResults/stop/h"+fl+"_DataEG12.root");
  TFile *fEG = TFile::Open(dirnameIn+"h"+fl+"_DataEG12.root");

  TString htitle_In_Data_ee  = "hDYIn_ee_2Jets";
  dummy = (TH1F*) fEG->Get(htitle_In_Data_ee);
  EvData_in_ee  = dummy->Integral(-1,1000);  

  if (channel == "mumu")    f = fMu;
  else if (channel == "ee") f = fEG;

  TString htitle_In_Data  = "hDYIn_" + channel + "_" + cut;
  dummy = (TH1F*) f->Get(htitle_In_Data);
  EvData_in  = dummy->Integral(-1,1000);  

  // MuEG as reference
  //f = TFile::Open("StopResults/stop/h"+fl+"_DataMuEG12.root");
  f = TFile::Open(dirnameIn+"h"+fl+"_DataMuEG12.root");

  TString htitle_In_mue = "hDYIn_mue_" + cut;
  dummy = (TH1F*) f->Get(htitle_In_mue);
  EvData_in_mue = dummy->Integral(-1,1000);  

  // R 
  float R = DYMC_out / DYMC_in;

  cout << "R = " << R << " = " << DYMC_out << "/" << DYMC_in << endl; 
  
  // k
  float k = 0.;
  if (channel == "mumu")      k = 0.5 * sqrt((double)EvData_in_mumu/(double)EvData_in_ee);
  else if (channel == "ee")   k = 0.5 * sqrt((double)EvData_in_ee/(double)EvData_in_mumu);
  
  cout << "k = " << k << endl; 


  //
  float NDY_DD = R * (EvData_in - k*EvData_in_mue);

  cout << "EvData_in=" << EvData_in << " k=" << k << " EvData_in_mue=" << EvData_in_mue <<endl;

  ///////////// evaluate uncertainty

  cout << "Entries_DYMC_out = " << Entries_DYMC_out << endl;

  float err_DYMC_in  = sqrt(Entries_DYMC_in)  * (DYMC_in  / Entries_DYMC_in);
  float err_DYMC_out = sqrt(Entries_DYMC_out) * (DYMC_out / Entries_DYMC_out);

  float err_R2 = R*R * ( (err_DYMC_out/DYMC_out)*(err_DYMC_out/DYMC_out) +
                         (err_DYMC_in/DYMC_in)  *(err_DYMC_in/DYMC_in) );

  float err_k2 = 0.;
  if (channel == "mumu")      err_k2 = 0.25 * ( (1./(4.*EvData_in_ee)) + (EvData_in_mumu/(4.*EvData_in_ee*EvData_in_ee)) ); 
  else if (channel == "ee")   err_k2 = 0.25 * ( (1./(4.*EvData_in_mumu)) + (EvData_in_ee/(4.*EvData_in_mumu*EvData_in_mumu)) );

  float err_tmp = EvData_in + k*k*EvData_in_mue + EvData_in_mue*EvData_in_mue*err_k2;

  float err_DY_DD2 = NDY_DD*NDY_DD * ( (err_R2/(R*R)) +  (err_tmp*R*R/(NDY_DD*NDY_DD)) ); 

  float err_R     = sqrt(err_R2);
  float err_DY_DD = sqrt(err_DY_DD2);

  // Output
  cout << "---------------------------------" << endl;
  cout << " At " << cut << " level and channel " << channel << endl;
  cout << "--------------------------------"  << endl;

  cout << " DY MC :  " << DYMC_out << " +- " << err_DYMC_out << endl;
  cout << " DY DD :  " << NDY_DD   << " +- " << err_DY_DD    << endl;
  cout << " R     :  " << R        << " +- " << err_R        << endl;

  cout << "-------------------------------" << endl;

  result.push_back(DYMC_out); // [0]
  result.push_back(err_DYMC_out); // [1] 
  result.push_back(NDY_DD); // [2] 
  result.push_back(err_DY_DD); // [3]
  result.push_back(R); // [4]
  result.push_back(err_R); // [5]

  return 0;
}
