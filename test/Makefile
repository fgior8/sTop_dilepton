CC=g++
#wildcard, this finds all *.c file and make *.o files
objects = $(patsubst %.c,%.o,$(wildcard *.c))

#standard dir
INCLUDEDIR       = ./include/
INCLUDEDIRCOMMON = ./
#INCLUDEDIRTMVA   = ./TMVA/include
SRCDIR           = ./src/
TESTCDIR         = ./test/
OUTLIB	         = ./lib/

ROOTCFLAGS    := $(shell $(ROOTSYS)/bin/root-config --cflags)
ROOTLIBS      := $(shell $(ROOTSYS)/bin/root-config --libs)
#ROOTGLIBS     := $(shell $(ROOTSYS)/bin/root-config --glibs) -L TMVA/lib
ROOTGLIBS     := $(shell $(ROOTSYS)/bin/root-config --glibs)

CXX           = clang++ -std=c++11 -m64 
CXXFLAGS      = -g -fPIC -Wno-deprecated -O -ansi -D_GNU_SOURCE -g -O2 -Xlinker -zmuldefs
LD            = g++ -m64
LDFLAGS       = -g
SOFLAGS       = -shared

.SUFFIXES: .cc,.C,.c,.hh,.h
.PREFIXES: ./lib/

all: analyzer
covariance.o : matrix_inverse.h
resulution : resolution

#rule for basic objects
%.o: %.c %.h
	$(CXX) -Wall -g -c $< -o $@


analyzer: $(SRCDIR)runAnalyzer.cc 
	$(CXX) $(CXXFLAGS) -I $(INCLUDEDIR) $(SRCDIR)mt2bisect.cc $(SRCDIR)Data.cc $(SRCDIR)ChainEntries.cc $(SRCDIR)ChainMaker.cc $(SRCDIR)XSlist.cc $(SRCDIR)Reweight.cc $(SRCDIR)OtherFunctions.cc $(SRCDIR)SignalPlots.cc $(SRCDIR)BTagSFUtil.C $(SRCDIR)StdPlots.cc $(SRCDIR)JetPlots.cc $(SRCDIR)ElectronPlots.cc $(SRCDIR)MuonPlots.cc $(SRCDIR)ZDYPlots.cc $(SRCDIR)SelectionFunctions.cc $(SRCDIR)LeptonSelection.cc $(SRCDIR)ElectronSelection.cc $(SRCDIR)MuonSelection.cc $(SRCDIR)JetSelection.cc $(SRCDIR)GenParticleSelection.cc $(SRCDIR)FillTandG.cc $(SRCDIR)Analyzer.cc $(SRCDIR)runAnalyzer.cc \
	$(ROOTCFLAGS) \
	$(ROOTLIBS) \
	$(FFTWIND) $(FFTWLIB) \
	-o runAnalyzer.exe

resolution: $(SRCDIR)runResolution.cc 
	$(CXX) $(CXXFLAGS) -I $(INCLUDEDIR) $(SRCDIR)ResolutionTree.C $(SRCDIR)mt2bisect.cc $(SRCDIR)ChainMaker.cc $(SRCDIR)OtherFunctions.cc $(SRCDIR)SignalPlots.cc $(SRCDIR)StdPlots.cc $(SRCDIR)JetPlots.cc $(SRCDIR)ElectronPlots.cc $(SRCDIR)MuonPlots.cc $(SRCDIR)ZDYPlots.cc $(SRCDIR)ResAnalyzer.cc $(SRCDIR)runResolution.cc \
	$(ROOTCFLAGS) \
	$(ROOTLIBS) \
	$(FFTWIND) $(FFTWLIB) \
	-o runResolution.exe 

clean:
	rm -f *.o
