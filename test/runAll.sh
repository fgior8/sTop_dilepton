#!/bin/bash


#./runAnalyzer.exe -i T2tt_425LSP325.txt -o T2tt_425LSP325 -v $1
./runAnalyzer.exe -i T2tt_500_325.txt -o T2tt_500_325 -v $1
#./runAnalyzer.exe -i T2tt_650LSP325.txt -o T2tt_650LSP325 -v $1
./runAnalyzer.exe -i T2tt_850_100.txt -o T2tt_850_100 -v $1

./runAnalyzer.exe -i TTWToLNu.txt -o TTWToLNu -v $1
./runAnalyzer.exe -i TTWToQQ.txt -o TTWToQQ -v $1
./runAnalyzer.exe -i TTZToQQ.txt -o TTZToQQ -v $1

./runAnalyzer.exe -i WW.txt -o WW -v $1
./runAnalyzer.exe -i WZ.txt -o WZ -v $1
./runAnalyzer.exe -i ZZ.txt -o ZZ -v $1

./runAnalyzer.exe -i TbarW.txt -o TbarW -v $1
./runAnalyzer.exe -i TW.txt -o TW -v $1

./runAnalyzer.exe -i WJetsToLNu.txt -o WJetsToLNu -v $1

./runAnalyzer.exe -i DYJetsToLL_M10to50.txt -o DYJetsToLL_M10to50 -v $1
#./runAnalyzer.exe -i DYJetsToLL_M50.txt -o DYJetsToLL_M50 -v $1

#./runAnalyzer.exe -i TTJets.txt -o TTJets -v $1
./runAnalyzer.exe -i TTLep_pow.txt -o TTLep_pow -v $1

./runAnalyzer.exe -i DoubleMuon.txt -o DoubleMuon -v $1
./runAnalyzer.exe -i DoubleEG.txt -o DoubleEG -v $1
./runAnalyzer.exe -i MuonEG.txt -o MuonEG -v $1
exit 0
