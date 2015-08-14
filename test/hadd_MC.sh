#!/bin/bash

hadd -f ZDYJets_aMCatNLO_$1.root DYJets_aMCatNLO_$1.root ZJets_aMCatNLO_$1.root
 
hadd -f Tot_MC_$1.root TbarW_$1.root TW_$1.root WW_$1.root WZ_$1.root ZZ_$1.root WJets_aMCatNLO_$1.root TTbar_Powheg_$1.root 

hadd -f Data_$1.root DoubleEG_40_$1.root DoubleMuon_40_$1.root MuEG_40_$1.root 
