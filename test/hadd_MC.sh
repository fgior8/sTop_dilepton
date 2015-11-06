#!/bin/bash

hadd -f ZDYJets_$1.root DYJetsToLL_M10to50_$1.root DYJetsToLL_M50_$1.root
 
hadd -f Tot_MC_$1.root TTWToLNu_$1.root TTWToQQ_$1.root TTZToQQ_$1.root TbarW_$1.root TW_$1.root WW_$1.root WZ_$1.root ZZ_$1.root WJetsToLNu_$1.root TTJets_$1.root 

hadd -f Data_$1.root DoubleEG_$1.root DoubleMuon_$1.root MuonEG_$1.root 

hadd -f TTW_$1.root TTWToLNu_$1.root TTWToQQ_$1.root

hadd -f TTZ_$1.root TTZToQQ_$1.root
