void BTagSFUtil::GetFastSimPayload(TString BTagAlgorithm, TString FastSimDataset) {

  nFastSimPtBins = 14;
  float ptmin[] = {30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 670};

  for (int ptbin = 0; ptbin<=nFastSimPtBins; ptbin++) 
    FastSimPtBinEdge[ptbin] = ptmin[ptbin];  

  nFastSimEtaBins[0] = 1;
  nFastSimEtaBins[1] = 1;
  nFastSimEtaBins[2] = 2;

  for (int JetFlavor = 0; JetFlavor<3; JetFlavor++) 
    FastSimEtaBinEdge[0][JetFlavor] = 0.;

  FastSimEtaBinEdge[1][2] = 1.2;
  
  if (FastSimDataset=="") {

    IsFastSimDataset = false;

    for (int ptbin = 0; ptbin<nFastSimPtBins; ptbin++) {
      
      FastSimCF_error[ptbin][0][0] = 0.;
      FastSimCF_error[ptbin][0][1] = 0.;
      FastSimCF_error[ptbin][0][2] = 0.;
      FastSimCF_error[ptbin][1][2] = 0.;
      
      FastSimCF[ptbin][0][0] = 1.;
      FastSimCF[ptbin][0][1] = 1.;
      FastSimCF[ptbin][0][2] = 1.;
      FastSimCF[ptbin][1][2] = 1.;
      
    }
    
    return;

  }

  IsFastSimDataset = true;

  if (BTagAlgorithm=="TCHPT") {
    
    float CFb[] = {0.964359,0.967793,0.975224,0.980809,0.982623,0.988594,0.993287,0.991462,0.981804,0.968841,0.906918,0.892630,0.831897,0.793602};
    float CFb_error[] = {0.00826828,0.00246079,0.00426409,0.00448272,0.00462657,0.00210637,0.00341589,0.00217618,0.00316987,0.00799365,0.0112940,0.0137489,0.0204654,0.0726856}; // stat + PU
    float CFb_T1_syst[] = {0.000374645,-0.00538072,-0.0176566,-0.0216954,-0.0274927,-0.0291727,-0.0389976,-0.0437187,-0.0640881,-0.104047,-0.110479,-0.150402,-0.154710,-0.157131};
    float CFb_T1bbbb_syst[] = {0.0147736,0.0182457,0.0152325,0.0143255,0.0143585,0.0111767,0.00960797,0.00562924,-0.00924417,-0.0399529,-0.0526658,-0.0842922,-0.0827916,-0.0748965};
    float CFb_T1tttt_syst[] = {0.0122885,0.0101434,0.00939709,0.00867262,0.00954428,0.00986299,0.0122421,0.0145406,0.00696114,-0.0171145,-0.0251862,-0.0514500,-0.0505717,-0.0435506};
    float CFb_T2_syst[] = {-0.00337908,-0.00237334,-0.0241871,-0.0303425,-0.0271925,-0.0458808,-0.0551667,-0.0648737,-0.0873823,-0.125035,-0.132803,-0.162987,-0.164848,-0.163431};
    float CFb_T2bb_syst[] = {0.0210886,0.0256085,0.0275679,0.0343538,0.0322151,0.0316970,0.0314648,0.0287760,0.0143542,-0.0165442,-0.0299138,-0.0587064,-0.0518594,-0.0284795};
    float CFb_T2bw_syst[] = {0.0227117,0.0201361,0.0157044,0.0132911,0.0120092,0.0107491,0.0116560,0.0133708,0.00368172,-0.0241385,-0.0356680,-0.0641354,-0.0600887,-0.0415041};
    float CFb_T2tt_syst[] = {-0.000457615,0.00358868,0.00471342,0.00371858,0.00380802,0.00117481,-0.000775635,-0.00118667,-0.00725177,-0.0193696,-0.00837988,-0.0111361,0.00709537,0.0182121};
    float CFb_T3w_syst[] = {0.0218543,0.0211283,0.0206869,0.0196210,0.0211878,0.0185773,0.0184845,0.0174223,0.00212207,-0.0275601,-0.0394354,-0.0680114,-0.0663952,-0.0515899}; // SMS syst to be added in quadrature with PU+syst 
        
    for (int ptbin = 0; ptbin<nFastSimPtBins; ptbin++) {
      
      FastSimCF[ptbin][0][0] = CFb[ptbin];
      
      float SMSSystematic = 999.;
      if (FastSimDataset=="T1") SMSSystematic = CFb_T1_syst[ptbin];
      else if (FastSimDataset=="T1bbbb") SMSSystematic = CFb_T1bbbb_syst[ptbin];
      else if (FastSimDataset=="T1tttt") SMSSystematic = CFb_T1tttt_syst[ptbin];
      else if (FastSimDataset=="T2") SMSSystematic = CFb_T2_syst[ptbin];
      else if (FastSimDataset=="T2bb") SMSSystematic = CFb_T2bb_syst[ptbin];
      else if (FastSimDataset=="T2bw") SMSSystematic = CFb_T2bw_syst[ptbin];
      else if (FastSimDataset=="T2tt") SMSSystematic = CFb_T2tt_syst[ptbin];
      else if (FastSimDataset=="T3w") SMSSystematic = CFb_T3w_syst[ptbin];
      else cout << "GetFastSimPayload::Error CFs for " << FastSimDataset << " not available" << endl;

      FastSimCF_error[ptbin][0][0] = sqrt( pow(CFb_error[ptbin], 2) + pow(SMSSystematic, 2) );

    }

  } else if (BTagAlgorithm=="CSVM") {

    float CFb[] = {0.982194,0.980998,0.992014,0.994472,0.996825,0.999822,1.00105,1.00023,0.991994,0.979123,0.947207,0.928006,0.874260,0.839610};
    float CFb_error[] = {0.00253112,0.00296453,0.00113963,0.00128363,0.00232566,0.00232353,0.00219086,0.00156856,0.00322279,0.00400414,0.00737465,0.0105033,0.0171706,0.0344172}; // stat + PU
    float CFb_T1_syst[] = {0.0305974,0.0251517,0.0205015,0.0187029,0.0138344,0.0155380,0.0153906,0.0210581,0.0175900,-0.00234255,0.000241935,-0.0287645,-0.0472476,-0.0841584};
    float CFb_T1bbbb_syst[] = {0.00897405,0.00984249,0.00694051,0.00454724,0.00505632,0.00173861,0.00184828,0.00124377,-0.00265479,-0.0100402,-0.0112412,-0.0261436,-0.0221387,-0.0377308};
    float CFb_T1tttt_syst[] = {0.0112096,0.0127103,0.0107696,0.0105987,0.0102283,0.00953639,0.0107003,0.0118546,0.00837368,0.000790179,-0.00111371,-0.0146178,-0.00818416,-0.0197257};
    float CFb_T2_syst[] = {0.0197094,0.0218538,0.00671038,0.00481349,0.00234514,-0.00960910,-0.00872135,-0.0109075,-0.0185559,-0.0352550,-0.0374648,-0.0604555,-0.0752100,-0.0999645};
    float CFb_T2bb_syst[] = {0.0125569,0.0119411,0.0100657,0.0106521,0.00982046,0.00745928,0.00802320,0.00942034,0.00741357,0.00160137,0.00219074,-0.00892913,0.00172952,-0.000213087};
    float CFb_T2bw_syst[] = {0.0111744,0.0112791,0.00760594,0.00597137,0.00484192,0.00301468,0.00359970,0.00540084,0.00215334,-0.00427964,-0.00468144,-0.0184798,-0.0110016,-0.0187086};
    float CFb_T2tt_syst[] = {0.00574604,0.00677246,0.00509557,0.00374240,0.00314873,0.000637591,-0.000242591,-4.16636e-05,-0.00292352,-0.00581479,-0.000461876,-0.00676391,0.00488830,3.05474e-05};
    float CFb_T3w_syst[] = {0.0197131,0.0171196,0.0159192,0.0127636,0.0132435,0.00963777,0.00937313,0.00896174,0.00418186,-0.00353286,-0.00389037,-0.0171415,-0.0120094,-0.0215860}; // SMS syst to be added in quadrature with PU+syst 
        
    for (int ptbin = 0; ptbin<nFastSimPtBins; ptbin++) {
      
      FastSimCF[ptbin][0][0] = CFb[ptbin];
      
      float SMSSystematic = 999.;
      if (FastSimDataset=="T1") SMSSystematic = CFb_T1_syst[ptbin];
      else if (FastSimDataset=="T1bbbb") SMSSystematic = CFb_T1bbbb_syst[ptbin];
      else if (FastSimDataset=="T1tttt") SMSSystematic = CFb_T1tttt_syst[ptbin];
      else if (FastSimDataset=="T2") SMSSystematic = CFb_T2_syst[ptbin];
      else if (FastSimDataset=="T2bb") SMSSystematic = CFb_T2bb_syst[ptbin];
      else if (FastSimDataset=="T2bw") SMSSystematic = CFb_T2bw_syst[ptbin];
      else if (FastSimDataset=="T2tt") SMSSystematic = CFb_T2tt_syst[ptbin];
      else if (FastSimDataset=="T3w") SMSSystematic = CFb_T3w_syst[ptbin];
      else cout << "GetFastSimPayload::Error CFs for " << FastSimDataset << " not available" << endl;

      FastSimCF_error[ptbin][0][0] = sqrt( pow(CFb_error[ptbin], 2) + pow(SMSSystematic, 2) );

    }
    
  } else if (BTagAlgorithm=="CSVT") {

    float CFb[] = {0.968117,0.967822,0.978278,0.981281,0.987679,0.986590,0.990246,0.984504,0.967024,0.940042,0.873019,0.850847,0.769561,0.650192};
    float CFb_error[] = {0.00223422,0.00367427,0.00145554,0.00337572,0.00344106,0.00591257,0.00218050,0.00472939,0.00353119,0.00739502,0.0193330,0.0158257,0.0306048,0.0603701}; // stat + PU
    float CFb_T1_syst[] = {0.0404417,0.0338855,0.0268602,0.0154959,0.0112958,0.00860152,0.00871485,0.00643355,-0.0189310,-0.0548930,-0.0645469,-0.110725,-0.135682,-0.123968};
    float CFb_T1bbbb_syst[] = {0.0129219,0.0137310,0.0113178,0.00933427,0.00921154,0.00691691,0.00647020,0.00674507,-0.00834304,-0.0302220,-0.0412711,-0.0777479,-0.0823319,-0.0629126};
    float CFb_T1tttt_syst[] = {0.0151952,0.0154848,0.0141975,0.0152467,0.0151888,0.0164594,0.0190932,0.0238398,0.0151870,-0.00265440,-0.0101969,-0.0403102,-0.0398199,-0.0128917};
    float CFb_T2_syst[] = {0.0335889,0.0293072,0.00701576,0.00240481,0.00541189,-0.0178958,-0.0182847,-0.0249884,-0.0600149,-0.0852849,-0.108664,-0.139017,-0.160629,-0.136853};
    float CFb_T2bb_syst[] = {0.0189191,0.0207380,0.0180343,0.0183147,0.0184177,0.0161918,0.0175651,0.0203825,0.0112045,-0.0102938,-0.0205988,-0.0525127,-0.0512335,-0.0153682};
    float CFb_T2bw_syst[] = {0.0163777,0.0155786,0.0114890,0.0101303,0.00891703,0.00743636,0.00856078,0.0129112,0.00174296,-0.0183686,-0.0265031,-0.0612646,-0.0610615,-0.0313782};
    float CFb_T2tt_syst[] = {0.00601965,0.00787908,0.00701177,0.00568053,0.00516674,0.00290364,0.00112420,0.00258505,-0.00883520,-0.0173537,-0.00851473,-0.0216886,-0.00751114,0.0275140};
    float CFb_T3w_syst[] = {0.0284607,0.0245074,0.0227164,0.0191328,0.0193200,0.0166523,0.0169420,0.0180767,0.00327435,-0.0184413,-0.0281253,-0.0619053,-0.0645325,-0.0373348}; // SMS syst to be added in quadrature with PU+syst 
    
    for (int ptbin = 0; ptbin<nFastSimPtBins; ptbin++) {
      
      FastSimCF[ptbin][0][0] = CFb[ptbin];
      
      float SMSSystematic = 999.;
      if (FastSimDataset=="T1") SMSSystematic = CFb_T1_syst[ptbin];
      else if (FastSimDataset=="T1bbbb") SMSSystematic = CFb_T1bbbb_syst[ptbin];
      else if (FastSimDataset=="T1tttt") SMSSystematic = CFb_T1tttt_syst[ptbin];
      else if (FastSimDataset=="T2") SMSSystematic = CFb_T2_syst[ptbin];
      else if (FastSimDataset=="T2bb") SMSSystematic = CFb_T2bb_syst[ptbin];
      else if (FastSimDataset=="T2bw") SMSSystematic = CFb_T2bw_syst[ptbin];
      else if (FastSimDataset=="T2tt") SMSSystematic = CFb_T2tt_syst[ptbin];
      else if (FastSimDataset=="T3w") SMSSystematic = CFb_T3w_syst[ptbin];
      else cout << "GetFastSimPayload::Error CFs for " << FastSimDataset << " not available" << endl;

      FastSimCF_error[ptbin][0][0] = sqrt( pow(CFb_error[ptbin], 2) + pow(SMSSystematic, 2) );

    }
    
  } else cout << "GetFastSimPayload::Error CFs for " << BTagAlgorithm << " not available" << endl;

  if (BTagAlgorithm=="TCHPT") {

    float CFc[] = {0.951496,0.976506,0.978859,0.985243,1.02174,1.00570,1.02313,1.00379,1.01011,1.01158,0.984201,1.01706,0.948002,1.03205};
    float CFc_error[] = {0.0153392,0.0259352,0.0120559,0.0389040,0.0307255,0.0140905,0.0148916,0.0225792,0.0350486,0.0389968,0.0635439,0.161351,0.109165,0.145486}; // stat + PU
    float CFc_T1_syst[] = {-0.0499437,-0.0744560,-0.0690346,-0.0634069,-0.0941935,-0.0933401,-0.119421,-0.121858,-0.136343,-0.174974,-0.186991,-0.221543,-0.154813,-0.0388871};
    float CFc_T1bbbb_syst[] = {-0.0641947,-0.0910950,-0.0993394,-0.119563,-0.156071,-0.150362,-0.186556,-0.201565,-0.242180,-0.276990,-0.282863,-0.326718,-0.271450,-0.235875};
    float CFc_T1tttt_syst[] = {-0.0284447,-0.0271544,-0.0218689,-0.0158781,-0.0225632,-0.0105700,-0.0113826,0.00629336,-0.0122585,-0.0336733,-0.0259307,-0.00608599,0.0494220,0.0139605};
    float CFc_T2_syst[] = {-0.0114704,-0.0428215,-0.0333561,-0.0244805,-0.0329470,0.00558734,-0.0209634,0.00117362,0.00149041,-0.00654751,0.00127462,-0.0274189,0.0848439,0.389300};
    float CFc_T2bb_syst[] = {-0.0306067,-0.0352905,-0.0659296,-0.0858037,-0.128943,-0.125774,-0.172783,-0.182375,-0.205047,-0.221164,-0.250533,-0.276626,-0.244117,-0.197086};
    float CFc_T2bw_syst[] = {-0.0254351,-0.0394273,-0.0280205,-0.0249251,-0.0442438,-0.0273092,-0.0257190,-0.00440568,-0.0154895,-0.0144740,0.0534873,0.151074,0.293829,0.541655};
    float CFc_T2tt_syst[] = {-0.0320756,-0.0377015,-0.0328578,-0.0298043,-0.0411063,-0.0318406,-0.0347562,-0.0167035,-0.0176852,-0.00619823,0.0487959,0.116318,0.205227,0.116302};
    float CFc_T3w_syst[] = {-0.0141360,-0.0216652,-0.00752640,-0.00335300,-0.00954145,0.00293708,0.00610393,0.0310832,0.0231489,0.0241724,0.0381047,0.0350108,0.158593,0.435220}; // SMS syst to be added in quadrature with PU+syst 
    
    for (int ptbin = 0; ptbin<nFastSimPtBins; ptbin++) {
      
      FastSimCF[ptbin][0][1] = CFc[ptbin];
      
      float SMSSystematic = 999.;
      if (FastSimDataset=="T1") SMSSystematic = CFc_T1_syst[ptbin];
      else if (FastSimDataset=="T1bbbb") SMSSystematic = CFc_T1bbbb_syst[ptbin];
      else if (FastSimDataset=="T1tttt") SMSSystematic = CFc_T1tttt_syst[ptbin];
      else if (FastSimDataset=="T2") SMSSystematic = CFc_T2_syst[ptbin];
      else if (FastSimDataset=="T2bb") SMSSystematic = CFc_T2bb_syst[ptbin];
      else if (FastSimDataset=="T2bw") SMSSystematic = CFc_T2bw_syst[ptbin];
      else if (FastSimDataset=="T2tt") SMSSystematic = CFc_T2tt_syst[ptbin];
      else if (FastSimDataset=="T3w") SMSSystematic = CFc_T3w_syst[ptbin];
      else cout << "GetFastSimPayload::Error CFs for " << FastSimDataset << " not available" << endl;

      FastSimCF_error[ptbin][0][1] = sqrt( pow(CFc_error[ptbin], 2) + pow(SMSSystematic, 2) );

    }
    
  } else if (BTagAlgorithm=="CSVM") {

      float CFc[] = {0.988545,0.981714,1.00946,1.01591,1.02810,1.02195,1.02590,1.01936,0.991228,0.955343,0.944433,0.917282,0.935018,1.06375};
      float CFc_error[] = {0.00746259,0.00661831,0.00968682,0.00751322,0.00675507,0.00562821,0.00862890,0.00768003,0.0188981,0.0261163,0.0450601,0.0448453,0.148805,0.177157}; // stat + PU
      float CFc_T1_syst[] = {-0.00104785,-0.00216204,0.00839430,0.00884008,0.00204188,0.00832790,0.0169768,0.0229713,0.0157189,-0.00730190,-0.0692086,-0.108517,-0.137035,-0.181932};
      float CFc_T1bbbb_syst[] = {-0.0169490,-0.0109324,-0.0173578,-0.0226300,-0.0354031,-0.0380664,-0.0406916,-0.0448566,-0.0634652,-0.0916214,-0.142743,-0.168372,-0.179460,-0.223442};
      float CFc_T1tttt_syst[] = {-0.00769350,0.00246567,0.00672805,0.00625175,0.0121922,0.0183616,0.0224260,0.0350031,0.0361672,0.0372230,0.0116431,0.0207569,0.0382855,0.0252644};
      float CFc_T2_syst[] = {-0.0147888,-0.00520468,-0.00901467,-0.0194454,-0.00635600,-0.00759417,-0.00953454,-0.0174082,-0.0184701,-0.0257653,-0.0740010,-0.0899951,-0.0860117,-0.0738075};
      float CFc_T2bb_syst[] = {-0.0126963,0.00240847,-0.0237588,-0.0202803,-0.0362858,-0.0296324,-0.0417801,-0.0566426,-0.0675621,-0.0768022,-0.141505,-0.160204,-0.199828,-0.237504};
      float CFc_T2bw_syst[] = {-0.0177944,-0.0168491,-0.0145971,-0.0171311,-0.0170042,-0.0143744,-0.0160470,-0.0149559,-0.0172561,-0.0137762,-0.0203696,0.00322482,0.0229054,0.0400957};
      float CFc_T2tt_syst[] = {-0.0183669,-0.0125071,-0.0174156,-0.0164738,-0.0167200,-0.0149260,-0.0180894,-0.0154648,-0.0141536,-0.0119079,-0.0206974,0.000753522,0.0221000,0.0209901};
      float CFc_T3w_syst[] = {-0.0126896,-0.00609615,-0.00314039,-0.00273418,-0.00209022,0.000352204,0.000533044,0.00463945,-0.000409096,-0.00550145,-0.0442329,-0.0519994,-0.0384817,-0.0126860}; // SMS syst to be added in quadrature with PU+syst 
    
    for (int ptbin = 0; ptbin<nFastSimPtBins; ptbin++) {
      
      FastSimCF[ptbin][0][1] = CFc[ptbin];
      
      float SMSSystematic = 999.;
      if (FastSimDataset=="T1") SMSSystematic = CFc_T1_syst[ptbin];
      else if (FastSimDataset=="T1bbbb") SMSSystematic = CFc_T1bbbb_syst[ptbin];
      else if (FastSimDataset=="T1tttt") SMSSystematic = CFc_T1tttt_syst[ptbin];
      else if (FastSimDataset=="T2") SMSSystematic = CFc_T2_syst[ptbin];
      else if (FastSimDataset=="T2bb") SMSSystematic = CFc_T2bb_syst[ptbin];
      else if (FastSimDataset=="T2bw") SMSSystematic = CFc_T2bw_syst[ptbin];
      else if (FastSimDataset=="T2tt") SMSSystematic = CFc_T2tt_syst[ptbin];
      else if (FastSimDataset=="T3w") SMSSystematic = CFc_T3w_syst[ptbin];
      else cout << "GetFastSimPayload::Error CFs for " << FastSimDataset << " not available" << endl;

      FastSimCF_error[ptbin][0][1] = sqrt( pow(CFc_error[ptbin], 2) + pow(SMSSystematic, 2) );

    }
      
  } else if (BTagAlgorithm=="CSVT") {
	     
    float CFc[] = {0.960959,0.973876,0.984323,0.996344,1.02418,0.985580,0.994745,0.970489,0.914155,0.872072,0.945289,0.783816,0.942773,0.527354};
    float CFc_error[] = {0.0155733,0.0121900,0.0131678,0.0113739,0.0213937,0.0123294,0.0153230,0.0156350,0.0409568,0.0654966,0.112785,0.187795,0.331301,0.162462}; // stat + PU
    float CFc_T1_syst[] = {-0.0150188,-0.0463591,-0.0315633,-0.0258283,-0.0327155,-0.0267018,-0.0148436,-0.0318809,-0.0359985,-0.0996782,-0.199801,-0.181507,-0.214658,-0.0237959};
    float CFc_T1bbbb_syst[] = {-0.0401338,-0.0623124,-0.0551870,-0.0723321,-0.0831102,-0.0953026,-0.0870973,-0.100656,-0.138856,-0.176190,-0.267756,-0.235408,-0.300116,-0.0866552};
    float CFc_T1tttt_syst[] = {-0.00762913,-0.0119695,0.00505692,0.00110212,0.00860715,0.0268639,0.0194188,0.0441512,0.0267859,0.0139230,-0.0531917,0.0474467,0.0777428,0.324803};
    float CFc_T2_syst[] = {-0.0210332,-0.0259317,-0.0103462,-0.0366923,-0.0190886,0.00934875,-0.00387061,-0.000786334,-0.0159257,-0.0524397,-0.116956,-0.0820041,-0.0804845,0.241786};
    float CFc_T2bb_syst[] = {-0.0376442,-0.0346557,-0.0518969,-0.0535199,-0.0908062,-0.0842518,-0.0974765,-0.105002,-0.117947,-0.151280,-0.254247,-0.216998,-0.284635,-0.0142322};
    float CFc_T2bw_syst[] = {-0.0175963,-0.0338167,-0.0177681,-0.0222040,-0.0251838,-0.0129322,-0.0205147,-0.0147394,-0.0377501,-0.0349037,-0.0639912,0.0514183,0.113051,0.453520};
    float CFc_T2tt_syst[] = {-0.0179060,-0.0272217,-0.0173259,-0.0195665,-0.0235815,-0.0123463,-0.0248161,-0.0109724,-0.0342969,-0.0314718,-0.0592955,0.0535336,0.124457,0.367309};
    float CFc_T3w_syst[] = {-0.0114200,-0.0202786,-0.00171709,-0.00232449,-0.00353348,0.00844371,-0.000867724,0.0146573,-0.0153649,-0.0254736,-0.0965763,-0.0415070,-0.00707200,0.310379}; // SMS syst to be added in quadrature with PU+syst 
    
    for (int ptbin = 0; ptbin<nFastSimPtBins; ptbin++) {
      
      FastSimCF[ptbin][0][1] = CFc[ptbin];
      
      float SMSSystematic = 999.;
      if (FastSimDataset=="T1") SMSSystematic = CFc_T1_syst[ptbin];
      else if (FastSimDataset=="T1bbbb") SMSSystematic = CFc_T1bbbb_syst[ptbin];
      else if (FastSimDataset=="T1tttt") SMSSystematic = CFc_T1tttt_syst[ptbin];
      else if (FastSimDataset=="T2") SMSSystematic = CFc_T2_syst[ptbin];
      else if (FastSimDataset=="T2bb") SMSSystematic = CFc_T2bb_syst[ptbin];
      else if (FastSimDataset=="T2bw") SMSSystematic = CFc_T2bw_syst[ptbin];
      else if (FastSimDataset=="T2tt") SMSSystematic = CFc_T2tt_syst[ptbin];
      else if (FastSimDataset=="T3w") SMSSystematic = CFc_T3w_syst[ptbin];
      else cout << "GetFastSimPayload::Error CFs for " << FastSimDataset << " not available" << endl;

      FastSimCF_error[ptbin][0][1] = sqrt( pow(CFc_error[ptbin], 2) + pow(SMSSystematic, 2) );

    }
    
  } else cout << "GetFastSimPayload::Error CFs for " << BTagAlgorithm << " not available" << endl;

  if (BTagAlgorithm=="TCHPT") {

    float CFudsg_central[] = {1.12192,1.21596,1.13216,1.23803,1.21094,1.25613,1.28927,1.25432,1.39338,1.32455,1.33163,1.45574,1.53371,1.19990};
    float CFudsg_central_error[] = {0.112496,0.0942560,0.0929161,0.0682252,0.0945835,0.0492082,0.0850913,0.0869689,0.135923,0.0882149,0.129597,0.169705,0.202421,0.207169}; // stat + PU
    float CFudsg_central_T1_syst[] = {0.774303,1.01382,1.13539,1.18525,1.15975,1.27517,1.25381,1.12947,1.08656,1.05148,1.15634,1.25129,1.43605,1.99334};
    float CFudsg_central_T1bbbb_syst[] = {-0.144868,-0.0666648,-0.120298,-0.0625720,-0.0714480,-0.0640254,-0.0625371,-0.112070,-0.0656869,-0.101722,-0.0309539,0.0499475,0.164022,0.166060};
    float CFudsg_central_T1tttt_syst[] = {-0.188457,-0.122318,-0.136964,-0.0737517,-0.0733279,-0.0448900,-0.0255176,-0.0529278,0.000286609,-0.0349150,0.0416269,0.146548,0.242402,0.110092};
    float CFudsg_central_T2_syst[] = {0.781334,0.763883,0.936026,0.915092,1.06246,1.35875,1.19397,1.10166,1.03620,1.04390,1.11159,1.18861,1.30728,1.78943};
    float CFudsg_central_T2bb_syst[] = {0.185213,0.368233,0.360249,0.426378,0.420959,0.484738,0.449295,0.380518,0.328642,0.263826,0.311228,0.337594,0.428070,0.501231};
    float CFudsg_central_T2bw_syst[] = {0.0192603,0.132992,0.0757862,0.159349,0.177948,0.217294,0.264984,0.208573,0.235726,0.183978,0.246673,0.395224,0.577729,0.687925};
    float CFudsg_central_T2tt_syst[] = {-0.0893834,-0.00576106,-0.0283973,0.0488394,0.0689143,0.116895,0.164575,0.159322,0.236337,0.218211,0.260401,0.354681,0.425116,0.171876};
    float CFudsg_central_T3w_syst[] = {0.372453,0.455190,0.490323,0.592906,0.658069,0.706155,0.778687,0.760497,0.779500,0.764917,0.864860,0.956683,1.18495,1.56138}; // SMS syst to be added in quadrature with PU+syst 

    float CFudsg_forward[] = {1.60462,2.00786,1.82655,1.96700,1.94393,1.92380,1.97979,2.02555,2.78905,2.73532,4.56895,4.55964,6.55749,14.3414};
    float CFudsg_forward_error[] = {0.310002,0.310535,0.279022,0.266218,0.195363,0.262045,0.219775,0.189776,0.404722,0.401244,0.971019,1.35229,3.11547,15.0349}; // stat + PU
    float CFudsg_forward_T1_syst[] = {1.31216,1.98671,2.28945,2.36455,2.73313,3.06638,3.46452,4.35512,6.96812,9.14562,13.0234,17.6342,23.6853,36.7722};
    float CFudsg_forward_T1bbbb_syst[] = {0.533724,0.841750,0.664852,0.731229,0.759807,0.752969,0.773790,0.814509,1.33465,1.48491,2.66101,2.91472,4.28553,9.46146};
    float CFudsg_forward_T1tttt_syst[] = {0.636071,0.972545,0.955933,1.11764,1.22166,1.31311,1.55357,1.92813,2.70927,3.12719,4.63339,5.30214,6.52787,11.7034};
    float CFudsg_forward_T2_syst[] = {0.950606,1.56856,1.46406,1.57289,2.05526,2.04398,2.46335,2.54023,4.23836,5.49939,7.41108,10.7359,16.0017,34.1147};
    float CFudsg_forward_T2bb_syst[] = {0.811405,1.18283,1.00379,1.24713,1.18582,1.25089,1.26890,1.41075,1.85922,2.17454,3.41786,3.82562,5.03768,12.1203};
    float CFudsg_forward_T2bw_syst[] = {0.861984,1.27996,1.24122,1.34171,1.37729,1.52240,1.68313,2.00468,2.61415,3.20980,4.34701,5.46541,7.10464,11.6557};
    float CFudsg_forward_T2tt_syst[] = {0.744652,1.13194,1.06568,1.23810,1.39540,1.52536,1.70706,2.04054,2.83494,3.28905,4.49659,5.02882,6.28044,9.82066};
    float CFudsg_forward_T3w_syst[] = {1.22720,1.75274,1.77690,2.01708,2.32732,2.59312,3.02791,3.79051,5.52594,7.32081,10.0751,12.5328,16.3230,28.7905}; // SMS syst to be added in quadrature with PU+syst 
    
    for (int ptbin = 0; ptbin<nFastSimPtBins; ptbin++) {
      
      FastSimCF[ptbin][0][2] = CFudsg_central[ptbin];
      
      float SMSSystematicCentral = 999.;
      if (FastSimDataset=="T1") SMSSystematicCentral = CFudsg_central_T1_syst[ptbin];
      else if (FastSimDataset=="T1bbbb") SMSSystematicCentral = CFudsg_central_T1bbbb_syst[ptbin];
      else if (FastSimDataset=="T1tttt") SMSSystematicCentral = CFudsg_central_T1tttt_syst[ptbin];
      else if (FastSimDataset=="T2") SMSSystematicCentral = CFudsg_central_T2_syst[ptbin];
      else if (FastSimDataset=="T2bb") SMSSystematicCentral = CFudsg_central_T2bb_syst[ptbin];
      else if (FastSimDataset=="T2bw") SMSSystematicCentral = CFudsg_central_T2bw_syst[ptbin];
      else if (FastSimDataset=="T2tt") SMSSystematicCentral = CFudsg_central_T2tt_syst[ptbin];
      else if (FastSimDataset=="T3w") SMSSystematicCentral = CFudsg_central_T3w_syst[ptbin];
      else cout << "GetFastSimPayload::Error CFs for " << FastSimDataset << " not available" << endl;

      FastSimCF_error[ptbin][0][2] = sqrt( pow(CFudsg_central_error[ptbin], 2) + pow(SMSSystematicCentral, 2) );
      
      FastSimCF[ptbin][1][2] = CFudsg_forward[ptbin];
      
      float SMSSystematicForward = 999.;
      if (FastSimDataset=="T1") SMSSystematicForward = CFudsg_forward_T1_syst[ptbin];
      else if (FastSimDataset=="T1bbbb") SMSSystematicForward = CFudsg_forward_T1bbbb_syst[ptbin];
      else if (FastSimDataset=="T1tttt") SMSSystematicForward = CFudsg_forward_T1tttt_syst[ptbin];
      else if (FastSimDataset=="T2") SMSSystematicForward = CFudsg_forward_T2_syst[ptbin];
      else if (FastSimDataset=="T2bb") SMSSystematicForward = CFudsg_forward_T2bb_syst[ptbin];
      else if (FastSimDataset=="T2bw") SMSSystematicForward = CFudsg_forward_T2bw_syst[ptbin];
      else if (FastSimDataset=="T2tt") SMSSystematicForward = CFudsg_forward_T2tt_syst[ptbin];
      else if (FastSimDataset=="T3w") SMSSystematicForward = CFudsg_forward_T3w_syst[ptbin];
      else cout << "GetFastSimPayload::Error CFs for " << FastSimDataset << " not available" << endl;

      FastSimCF_error[ptbin][1][2] = sqrt( pow(CFudsg_forward_error[ptbin], 2) + pow(SMSSystematicForward, 2) );

    }

  } else if (BTagAlgorithm=="CSVM") {

    float CFudsg_central[] = {1.21878,1.28615,1.37535,1.38966,1.40320,1.49835,1.44308,1.58198,1.55687,1.65790,1.90233,1.92259,2.66174,3.08688};
    float CFudsg_central_error[] = {0.0182686,0.0373732,0.0461870,0.0288973,0.0333528,0.0513836,0.0420353,0.106627,0.0658359,0.117285,0.185533,0.214071,0.487274,0.871502}; // stat + PU
    float CFudsg_central_T1_syst[] = {0.386488,0.524838,0.679631,0.682134,0.731629,0.757618,0.695844,0.724127,0.623855,0.660598,0.829350,0.905624,1.40528,1.87998};
    float CFudsg_central_T1bbbb_syst[] = {0.269423,0.377897,0.460441,0.456512,0.470195,0.481113,0.438144,0.464775,0.347294,0.411220,0.550301,0.623299,1.14485,1.53694};
    float CFudsg_central_T1tttt_syst[] = {0.118477,0.162964,0.223318,0.220063,0.222306,0.267305,0.222287,0.283804,0.252221,0.324747,0.527015,0.659528,1.19317,1.50547};
    float CFudsg_central_T2_syst[] = {0.411044,0.558016,0.670788,0.776938,0.802923,0.895418,0.806768,0.812508,0.671626,0.715303,0.865253,0.889535,1.36529,1.83958};
    float CFudsg_central_T2bb_syst[] = {0.419325,0.559732,0.664588,0.701051,0.760269,0.876007,0.749539,0.827054,0.657627,0.702294,0.858618,0.837998,1.36137,1.75727};
    float CFudsg_central_T2bw_syst[] = {0.249750,0.331114,0.370544,0.380683,0.375024,0.433907,0.370687,0.430421,0.397210,0.479439,0.675053,0.815746,1.36142,1.86164};
    float CFudsg_central_T2tt_syst[] = {0.241447,0.297617,0.365921,0.372697,0.378869,0.434225,0.385061,0.452832,0.412124,0.498940,0.675028,0.813003,1.31961,1.57929};
    float CFudsg_central_T3w_syst[] = {0.287246,0.388381,0.480550,0.504640,0.531340,0.572774,0.532622,0.586227,0.529575,0.600174,0.792410,0.882505,1.42788,1.91256}; // SMS syst to be added in quadrature with PU+syst 
  
    float CFudsg_forward[] = {1.46970,1.48732,1.69024,1.64494,1.79297,1.90760,1.99867,2.21659,2.20103,2.42645,2.67594,4.24735,3.98979,15.0457};
    float CFudsg_forward_error[] = {0.104716,0.0392025,0.106315,0.115751,0.106807,0.0642086,0.138742,0.182345,0.169922,0.297889,0.320088,0.927736,1.24666,15.1860}; // stat + PU
    float CFudsg_forward_T1_syst[] = {0.686015,0.720420,0.991786,1.02970,1.22030,1.34286,1.64405,2.09951,2.92008,4.41435,6.25081,9.86965,11.9982,25.3907};
    float CFudsg_forward_T1bbbb_syst[] = {0.618506,0.635309,0.794568,0.803646,0.886742,0.988190,1.10888,1.31924,1.49423,1.96107,2.36883,3.67770,4.80525,11.2853};
    float CFudsg_forward_T1tttt_syst[] = {0.772327,0.874528,1.19814,1.24806,1.49608,1.73841,2.00430,2.54257,3.27898,4.35726,5.31846,7.44186,9.19039,15.6896};
    float CFudsg_forward_T2_syst[] = {0.549720,0.580865,0.765356,0.788296,0.913463,1.03193,1.19510,1.40819,1.77895,2.69320,3.44912,5.91765,9.20944,18.0392};
    float CFudsg_forward_T2bb_syst[] = {0.569517,0.548840,0.763820,0.726966,0.927079,0.959964,1.09951,1.29263,1.39602,1.97896,2.41141,3.67147,4.17557,11.7192};
    float CFudsg_forward_T2bw_syst[] = {0.697431,0.759470,1.03429,1.05697,1.23279,1.38067,1.52550,1.89634,2.29738,2.87713,3.64427,5.54452,6.93274,13.9094};
    float CFudsg_forward_T2tt_syst[] = {0.694594,0.753930,1.01105,1.02488,1.18455,1.36025,1.57676,1.87545,2.24691,2.81635,3.46050,5.75946,6.89900,15.8855};
    float CFudsg_forward_T3w_syst[] = {0.773925,0.839802,1.08844,1.16056,1.35051,1.53349,1.76781,2.23936,2.95149,4.32639,5.98244,9.13821,12.3203,24.2016}; // SMS syst to be added in quadrature with PU+syst 
    
    for (int ptbin = 0; ptbin<nFastSimPtBins; ptbin++) {
      
      FastSimCF[ptbin][0][2] = CFudsg_central[ptbin];
      
      float SMSSystematicCentral = 999.;
      if (FastSimDataset=="T1") SMSSystematicCentral = CFudsg_central_T1_syst[ptbin];
      else if (FastSimDataset=="T1bbbb") SMSSystematicCentral = CFudsg_central_T1bbbb_syst[ptbin];
      else if (FastSimDataset=="T1tttt") SMSSystematicCentral = CFudsg_central_T1tttt_syst[ptbin];
      else if (FastSimDataset=="T2") SMSSystematicCentral = CFudsg_central_T2_syst[ptbin];
      else if (FastSimDataset=="T2bb") SMSSystematicCentral = CFudsg_central_T2bb_syst[ptbin];
      else if (FastSimDataset=="T2bw") SMSSystematicCentral = CFudsg_central_T2bw_syst[ptbin];
      else if (FastSimDataset=="T2tt") SMSSystematicCentral = CFudsg_central_T2tt_syst[ptbin];
      else if (FastSimDataset=="T3w") SMSSystematicCentral = CFudsg_central_T3w_syst[ptbin];
      else cout << "GetFastSimPayload::Error CFs for " << FastSimDataset << " not available" << endl;

      FastSimCF_error[ptbin][0][2] = sqrt( pow(CFudsg_central_error[ptbin], 2) + pow(SMSSystematicCentral, 2) );
      
      FastSimCF[ptbin][1][2] = CFudsg_forward[ptbin];
      
      float SMSSystematicForward = 999.;
      if (FastSimDataset=="T1") SMSSystematicForward = CFudsg_forward_T1_syst[ptbin];
      else if (FastSimDataset=="T1bbbb") SMSSystematicForward = CFudsg_forward_T1bbbb_syst[ptbin];
      else if (FastSimDataset=="T1tttt") SMSSystematicForward = CFudsg_forward_T1tttt_syst[ptbin];
      else if (FastSimDataset=="T2") SMSSystematicForward = CFudsg_forward_T2_syst[ptbin];
      else if (FastSimDataset=="T2bb") SMSSystematicForward = CFudsg_forward_T2bb_syst[ptbin];
      else if (FastSimDataset=="T2bw") SMSSystematicForward = CFudsg_forward_T2bw_syst[ptbin];
      else if (FastSimDataset=="T2tt") SMSSystematicForward = CFudsg_forward_T2tt_syst[ptbin];
      else if (FastSimDataset=="T3w") SMSSystematicForward = CFudsg_forward_T3w_syst[ptbin];
      else cout << "GetFastSimPayload::Error CFs for " << FastSimDataset << " not available" << endl;

      FastSimCF_error[ptbin][1][2] = sqrt( pow(CFudsg_forward_error[ptbin], 2) + pow(SMSSystematicForward, 2) );

    }
    
  } else if (BTagAlgorithm=="CSVT") {

    float CFudsg_central[] = {1.24890,1.35145,1.37205,1.32472,1.39976,1.45884,1.59912,1.58971,1.30841,1.55936,1.28346,2.21265,2.06927,2.88109};
    float CFudsg_central_error[] = {0.0751438,0.0651619,0.0604241,0.0726285,0.0968158,0.0931768,0.163039,0.187749,0.198200,0.465354,0.339473,1.07079,1.07723,2.53188}; // stat + PU
    float CFudsg_central_T1_syst[] = {0.541349,0.749937,0.899876,0.913299,1.04832,1.00971,0.948618,0.828252,0.461639,0.515000,0.339278,0.834556,0.922787,1.72162};
    float CFudsg_central_T1bbbb_syst[] = {0.262307,0.382883,0.463978,0.397656,0.450687,0.470582,0.514196,0.478655,0.229171,0.438639,0.200500,0.754263,0.887022,1.60800};
    float CFudsg_central_T1tttt_syst[] = {0.107974,0.146424,0.175264,0.125604,0.148329,0.175837,0.216767,0.212357,0.0737581,0.268330,0.220413,0.810560,0.954838,1.67344};
    float CFudsg_central_T2_syst[] = {0.514257,0.722493,0.824915,1.30112,1.38608,1.41843,1.04881,0.975846,0.539212,0.606663,0.415293,0.763953,0.812614,1.59538};
    float CFudsg_central_T2bb_syst[] = {0.516994,0.673320,0.844278,0.855887,1.08265,1.10285,1.20266,0.989551,0.686524,0.782166,0.602174,0.973691,0.905448,1.66941};
    float CFudsg_central_T2bw_syst[] = {0.284863,0.382788,0.346198,0.313557,0.329289,0.356919,0.347319,0.354319,0.164351,0.357468,0.301092,0.901424,1.13151,1.92501};
    float CFudsg_central_T2tt_syst[] = {0.258683,0.321056,0.326149,0.318511,0.344513,0.360544,0.380937,0.390651,0.208644,0.402611,0.327629,0.955151,1.09279,1.85737};
    float CFudsg_central_T3w_syst[] = {0.402833,0.489644,0.564344,0.587424,0.657689,0.628729,0.663659,0.617975,0.328334,0.460770,0.340796,0.833781,0.972206,1.83632}; // SMS syst to be added in quadrature with PU+syst 
 
    float CFudsg_forward[] = {1.67634,1.70105,1.75999,1.78459,2.19343,2.73199,3.49277,2.58863,2.48824,4.01723,3.86956,0.000456049,2.30988,0.000855693};
    float CFudsg_forward_error[] = {0.222165,0.161403,0.112342,0.275101,0.364229,0.330588,1.00953,0.404417,1.07731,2.65686,3.18286,5.25051e-05,2.38652,0.000438728}; // stat + PU
    float CFudsg_forward_T1_syst[] = {1.12564,1.13767,1.41534,1.51698,2.21567,2.46153,3.52618,3.66658,6.82062,9.53548,11.6888,11.6385,37.8436,55.0746};
    float CFudsg_forward_T1bbbb_syst[] = {0.966686,0.911206,1.01981,1.05643,1.36584,1.83112,2.31922,1.90143,3.29097,3.21403,4.94706,3.62533,10.3981,5.51893};
    float CFudsg_forward_T1tttt_syst[] = {1.07420,1.13792,1.37766,1.43242,1.81959,2.25043,2.85233,3.01381,3.90803,7.90416,7.84521,8.13804,21.4383,90.5637};
    float CFudsg_forward_T2_syst[] = {0.914312,1.00641,1.19010,1.21705,1.54337,1.79515,2.79849,2.58661,3.30393,5.87701,6.11172,9.81007,66.2097,110.301};
    float CFudsg_forward_T2bb_syst[] = {0.952269,0.947869,1.07177,1.07862,1.61536,1.89066,2.38571,2.09688,2.12828,3.69276,4.06967,3.12065,4.10128,-0.649336};
    float CFudsg_forward_T2bw_syst[] = {1.06254,1.07746,1.35255,1.45264,1.89413,2.11516,2.95536,2.60233,3.42582,4.82154,7.41456,6.31043,6.52546,13.4704};
    float CFudsg_forward_T2tt_syst[] = {1.01487,1.07556,1.33002,1.38201,1.77121,2.12163,2.80742,2.57413,3.43778,4.60502,5.42910,4.53808,6.23334,23.3936};
    float CFudsg_forward_T3w_syst[] = {1.17544,1.23456,1.48954,1.57960,2.18616,2.55298,3.25695,3.47147,5.16497,7.76216,11.6997,10.8320,19.7364,64.8392}; // SMS syst to be added in quadrature with PU+syst 
    
    for (int ptbin = 0; ptbin<nFastSimPtBins; ptbin++) {
      
      FastSimCF[ptbin][0][2] = CFudsg_central[ptbin];
      
      float SMSSystematicCentral = 999.;
      if (FastSimDataset=="T1") SMSSystematicCentral = CFudsg_central_T1_syst[ptbin];
      else if (FastSimDataset=="T1bbbb") SMSSystematicCentral = CFudsg_central_T1bbbb_syst[ptbin];
      else if (FastSimDataset=="T1tttt") SMSSystematicCentral = CFudsg_central_T1tttt_syst[ptbin];
      else if (FastSimDataset=="T2") SMSSystematicCentral = CFudsg_central_T2_syst[ptbin];
      else if (FastSimDataset=="T2bb") SMSSystematicCentral = CFudsg_central_T2bb_syst[ptbin];
      else if (FastSimDataset=="T2bw") SMSSystematicCentral = CFudsg_central_T2bw_syst[ptbin];
      else if (FastSimDataset=="T2tt") SMSSystematicCentral = CFudsg_central_T2tt_syst[ptbin];
      else if (FastSimDataset=="T3w") SMSSystematicCentral = CFudsg_central_T3w_syst[ptbin];
      else cout << "GetFastSimPayload::Error CFs for " << FastSimDataset << " not available" << endl;

      FastSimCF_error[ptbin][0][2] = sqrt( pow(CFudsg_central_error[ptbin], 2) + pow(SMSSystematicCentral, 2) );
      
      FastSimCF[ptbin][1][2] = CFudsg_forward[ptbin];
      
      float SMSSystematicForward = 999.;
      if (FastSimDataset=="T1") SMSSystematicForward = CFudsg_forward_T1_syst[ptbin];
      else if (FastSimDataset=="T1bbbb") SMSSystematicForward = CFudsg_forward_T1bbbb_syst[ptbin];
      else if (FastSimDataset=="T1tttt") SMSSystematicForward = CFudsg_forward_T1tttt_syst[ptbin];
      else if (FastSimDataset=="T2") SMSSystematicForward = CFudsg_forward_T2_syst[ptbin];
      else if (FastSimDataset=="T2bb") SMSSystematicForward = CFudsg_forward_T2bb_syst[ptbin];
      else if (FastSimDataset=="T2bw") SMSSystematicForward = CFudsg_forward_T2bw_syst[ptbin];
      else if (FastSimDataset=="T2tt") SMSSystematicForward = CFudsg_forward_T2tt_syst[ptbin];
      else if (FastSimDataset=="T3w") SMSSystematicForward = CFudsg_forward_T3w_syst[ptbin];
      else cout << "GetFastSimPayload::Error CFs for " << FastSimDataset << " not available" << endl;

      FastSimCF_error[ptbin][1][2] = sqrt( pow(CFudsg_forward_error[ptbin], 2) + pow(SMSSystematicForward, 2) );

    }
    
  } else cout << "GetFastSimPayload::Error CFs for " << BTagAlgorithm << " not available" << endl;
    
//   // Using 2011 CFs on 2012 samples
//   for (int ptbin = 0; ptbin<nFastSimPtBins; ptbin++) {
    
//     FastSimCF_error[ptbin][0][0] *= 2.;
//     FastSimCF_error[ptbin][0][1] *= 2.;
//     FastSimCF_error[ptbin][0][2] *= 2.;
//     FastSimCF_error[ptbin][1][2] *= 2.;

//   }
  
}
