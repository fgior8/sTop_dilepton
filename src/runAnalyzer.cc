#include "Analyzer.h"
#include "ChainMaker.h"

void display_usage() {
  cout << "simple instrunctions" << endl;
  cout << "Two arguments are needed: -i <input file> -o <output file> and the directory if different from current one." << endl 
       << "Optional arguments are: " << endl
       << "* the version number -v (otherwise set to 1)" << endl
       << "* the number of events -n (otherwise all events in the dataset will be processes)" << endl
       << "* the input direction -d" << endl;
}

int main (int argc, const char* argv[]) {

  const char * _output   = 0;
  const char * _input    = 0;
  const char * _dir      = "./DataSetList/25ns/";
  const char * _version  = 0;
  const char * _nevents  = 0;
  
  cout << " Hello " << endl;
  // Arguments used
  //std::set<int> usedargs;
  //Parsing input options
  if(argc == 1){
    display_usage();
    return -1;
  }
  else{
    //Argument 1 must be a valid input fileName
    for (int i = 1; i < argc; i++){
      if( strcmp(argv[i],"-i") == 0 ){
        _input = argv[i+1];
        i++;
      }
      if( strcmp(argv[i],"-o") == 0 ){
        _output= argv[i+1];
        i++;
      }
      if( strcmp(argv[i],"-d") == 0 ){
        _dir = argv[i+1];
        i++;
      }
      if( strcmp(argv[i],"-v") == 0 ){
        _version = argv[i+1];
        i++;
      }
      if( strcmp(argv[i],"-n") == 0 ){
        _nevents = argv[i+1];
        i++;
      }
      if( strcmp(argv[i],"-h") == 0 ||
          strcmp(argv[i],"--help") == 0 ){
        display_usage();
        return 0;
      }
    }
  }//else
  if( _input == 0){
    std::cerr << "\033[1;31mskimfile ERROR:\033[1;m The '-i' option is mandatory!"
              << std::endl;
    display_usage();
    return -1;
  }
  if(_version ==0) _version = "1";
  if(_nevents==0) _nevents = "-1";
  
  // reassigning
  TString fname(_input);
  TString hname(_output);
  TString fdir(_dir);
  Int_t ver = atoi (_version);
  Long64_t nev = atol (_nevents);

  Analyzer Pippo;
  cout << "fname " << fname << endl;
  fdir.Append(fname);
  cout << "Running on " << fdir << endl;
  TChain* chain = ChainMaker(fdir);
  Pippo.Init(chain); 
  Pippo.SetName(hname,ver);
  Pippo.SetEvtN(nev);
  Pippo.SetWeight(hname);
  cout << "Saved in " << hname << endl;  
  Pippo.Loop();

cout << endl << endl;
}
