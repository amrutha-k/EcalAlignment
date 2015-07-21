import os

print "Check all SM and Dee alignment"

#####
# mc

for x in range(0, 36):
  toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/eos/cms/store/user/amassiro/ECAL/Alignment/test06Jul2015/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_50ns_WJetsToLNu/150708_201650/0000/treeECALAlignment_*.root\\\",\\\"2015MC\\\",\\\"mc_weight*electrons_classification\=\=0\&\&ETSC\>30\&\&met\>30\\\"," + str(x) + ",-100\)"
  print "toexec = ", toexec
  os.system (toexec)
  
for x in range(0, 4):
  toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/eos/cms/store/user/amassiro/ECAL/Alignment/test06Jul2015/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_50ns_WJetsToLNu/150708_201650/0000/treeECALAlignment_*.root\\\",\\\"2015MC\\\",\\\"mc_weight*electrons_classification\=\=0\&\&ETSC\>30\&\&met\>30\\\",-100," + str(x) + "\)"
  print "toexec = ", toexec
  os.system (toexec)

#######  
# data

for x in range(0, 36):
  toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/treeECALAlignment_DATA_oldTrkAlign.root\\\",\\\"2015DataOldTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\&\&met\>30\\\"," + str(x) + ",-100,0\)"
  print "toexec = ", toexec
  os.system (toexec)
  
for x in range(0, 4):
  toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/treeECALAlignment_DATA_oldTrkAlign.root\\\",\\\"2015DataOldTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\&\&met\>30\\\",-100," + str(x) + ",0\)"
  print "toexec = ", toexec
  os.system (toexec)
