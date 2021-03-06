EcalAlignment
=============

EcalAlignment framework

    read doc/README

where:

    /afs/cern.ch/work/a/amassiro/ECALAlignment/CMSSW_5_3_3/src/EcalValidation/EcalAlignment
    /afs/cern.ch/work/a/amassiro/ECALAlignment/CMSSW_7_0_6_patch1/src/EcalValidation/EcalAlignment
    /afs/cern.ch/work/a/amassiro/ECALAlignment/CMSSW_7_0_7_patch1/src/EcalValidation/EcalAlignment
    /afs/cern.ch/work/a/amassiro/ECALAlignment/CMSSW_7_2_1/src/EcalValidation/EcalAlignment
    /afs/cern.ch/work/a/amassiro/ECALAlignment/CMSSW_7_3_1/src/EcalValidation/EcalAlignment
    /afs/cern.ch/work/a/amassiro/ECALAlignment/CMSSW_7_3_3/src/EcalValidation/EcalAlignment
    /afs/cern.ch/work/a/amassiro/ECALAlignment/CMSSW_7_4_4/src/EcalValidation/EcalAlignment
    /afs/cern.ch/work/a/amassiro/ECALAlignment/CMSSW_7_4_6_patch4/src/EcalValidation/EcalAlignment  --> 2015
    /afs/cern.ch/work/a/amassiro/ECALAlignment/CMSSW_7_4_14/src/EcalValidation/EcalAlignment
    /afs/cern.ch/work/a/amassiro/ECALAlignment/CMSSW_8_0_3/src/EcalValidation/EcalAlignment/
    /afs/cern.ch/work/a/amassiro/ECALAlignment/CMSSW_8_0_5/src/EcalValidation/EcalAlignment/  --> bad
    /afs/cern.ch/work/a/amassiro/ECALAlignment/CMSSW_8_0_8/src/EcalValidation/EcalAlignment/
    /afs/cern.ch/work/a/amassiro/ECALAlignment/CMSSW_9_2_0_patch4/src/EcalValidation/EcalAlignment
    /afs/cern.ch/user/a/amassiro/work/ECALAlignment/CMSSW_9_2_1/src/EcalValidation/EcalAlignment
    /afs/cern.ch/user/a/amassiro/work/ECALAlignment/CMSSW_9_2_11/src/EcalValidation/EcalAlignment
    
    
    
    kate: LXPLUS-ECALAlignment
    xps kate: lxplus-ECAL-alignment


    
    /home/amassiro/Cern/Code/ECAL/ECALAlignment
    just to make plots faster in local

    
to setup:

    mkdir EcalValidation
    cd EcalValidation
    git clone git@github.com:amassiro/EcalAlignment.git

    cmsenv
    scramv1 b -j 8 -Werror=unused-variable

        NB: the "unused variable" errors must be disabled, because are coming from CLHEP libraries loaded by geometry, I have no access to


where alignment constants are backuped:

    /afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/


    
=============
Luminosity

How to measure the luminosity and where to get the lumisection json mask
 
    json:  /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions17/13TeV/
    
    e.g.: /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions17/13TeV/PromptReco/Cert_294297-999999_13TeV_PromptReco_Collisions17_JSON.txt
    
Luminosity: 
first install brilcal, following the recipe from https://cms-service-lumi.web.cern.ch/cms-service-lumi/brilwsdoc.html
Then:

     brilcalc lumi -u /pb -i  /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions17/13TeV/PromptReco/Cert_294297-999999_13TeV_PromptReco_Collisions17_JSON.txt

Output:

    +-------------+-------------------+-----+------+----------------+---------------+
    | run:fill    | time              | nls | ncms | delivered(/pb) | recorded(/pb) |
    +-------------+-------------------+-----+------+----------------+---------------+
    | 296174:5750 | 06/06/17 06:29:30 | 22  | 22   | 1.096          | 1.067         |
    +-------------+-------------------+-----+------+----------------+---------------+
    #Summary: 
    +-------+------+-----+------+-------------------+------------------+
    | nfill | nrun | nls | ncms | totdelivered(/pb) | totrecorded(/pb) |
    +-------+------+-----+------+-------------------+------------------+
    | 1     | 1    | 22  | 22   | 1.096             | 1.067            |
    +-------+------+-----+------+-------------------+------------------+

meaning

    1.067/pb
    
    
=============

Tools:

CombineRotoTraslations

    CombineRotoTraslations   origin.txt    modification.txt    new.txt
    CombineRotoTraslations   /afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/1Mar2011/myEEAlignment_2010.txt   myEEAlignment_2011.txt    myEEAlignment_2011_combined.txt

e.g.

    subtract two tags
    CombineRotoTraslations   myEEAlignment_2011.txt   myEEAlignment_2012.txt    myEEAlignment_2011_2012_difference.txt
    CombineRotoTraslations   myEBAlignment_2011.txt   myEBAlignment_2012.txt    myEBAlignment_2011_2012_difference.txt


    CombineRotoTraslations   data/myEBAlignment_2015_startup.txt   myEBAlignment_2015_NewTrkAlign_31Aug2015.txt    myEBAlignment_2015.txt
    CombineRotoTraslations   data/myEEAlignment_2015_startup.txt   myEEAlignment_2015_NewTrkAlign_31Aug2015.txt    myEEAlignment_2015.txt
    
    CombineRotoTraslations   /afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/2015/31Aug/myEEAlignment_2015.txt  myEEAlignment_2015_NewTrkAlign_31Aug2015_additional.txt    myEEAlignment_2015.txt
    

    CombineRotoTraslations   /afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/2015/31Aug/myEEAlignment_2015.txt  myEEAlignment_2015_NewTrkAlign_31Aug2015_additional_NEW.txt    myEEAlignment_2015.txt
    




Transform ES to EE

    TransformRotoTraslationsWithES   originES.txt   newForEE.txt

    
    CombineRotoTraslations     /afs/cern.ch/work/a/amassiro/ECALAlignment/CMSSW_7_4_14/src/EcalValidation/EcalAlignment/test/myEEAlignment_2015_combined_27Oct.txt   \
                               macro/newForEE.txt      \
                               myEEAlignment_2016_combined_19Apr.txt
                               
                               
    
    
    
    
    