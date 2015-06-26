#!/bin/bash


./runAnalyzer.exe -i T2tt_425LSP325.txt -o T2tt_425LSP325 -v $1
./runAnalyzer.exe -i T2tt_500LSP325.txt -o T2tt_500LSP325 -v $1
./runAnalyzer.exe -i T2tt_650LSP325.txt -o T2tt_650LSP325 -v $1

./runAnalyzer.exe -i TTWJets.txt -o TTWJets -v $1
./runAnalyzer.exe -i TTZJets.txt -o TTZJets -v $1
#./runAnalyzer.exe -i TTH125.txt -o TTH125 -v $1

./runAnalyzer.exe -i  WZTo3LNu.txt -o  WZTo3LNu -v $1
#./runAnalyzer.exe -i WWTo2L2Nu_Powheg.txt -o WWTo2L2Nu_Powheg -v $1
#./runAnalyzer.exe -i ZZ4L.txt -o ZZ4L -v $1
#./runAnalyzer.exe -i ZZ.txt -o ZZ -v $1
#./runAnalyzer.exe -i HWW125.txt -o HWW125 -v $1
#./runAnalyzer.exe -i VBF125.txt -o VBF125 -v $1

./runAnalyzer.exe -i TbarW.txt -o TbarW -v $1
./runAnalyzer.exe -i TW.txt -o TW -v $1
./runAnalyzer.exe -i ZJets_Madgraph.txt -o ZJets_Madgraph -v $1
./runAnalyzer.exe -i WJets_Madgraph.txt -o WJets_Madgraph -v $1

exit 0
