#include "TDRStyle.cc"

#include "Functions.h"

#include <iostream>
#include <fstream>
#include <sstream>


void drawComparison(TString nameDataTxt, TString nameMCTxt, TString nameData2Txt = ""){

 TDRStyle();
 
 gStyle->SetTitleYOffset(1.1);
 gStyle->cd();
 

 std::ifstream fileData  (nameDataTxt.Data()); 
 std::ifstream fileData2 (nameData2Txt.Data()); 
 std::ifstream fileMC    (nameMCTxt.Data()); 
 
 double Deta_SM_Mean[36];
 double Dphi_SM_Mean[36];
 double DphiEm_SM_Mean[36];
 double DphiEp_SM_Mean[36]; 
 
 double Deta_SM_RMS[36];
 double Dphi_SM_RMS[36];
 double DphiEm_SM_RMS[36];
 double DphiEp_SM_RMS[36];
 
 double Deta_SM_Entries[36];
 double Dphi_SM_Entries[36];
 double DphiEm_SM_Entries[36];
 double DphiEp_SM_Entries[36]; 
 
 
 double Deta_DEE_Mean[4];
 double Dphi_DEE_Mean[4];
 double DphiEm_DEE_Mean[4];
 double DphiEp_DEE_Mean[4]; 
 
 double Deta_DEE_RMS[4];
 double Dphi_DEE_RMS[4];
 double DphiEm_DEE_RMS[4];
 double DphiEp_DEE_RMS[4];
 
 double Deta_DEE_Entries[4];
 double Dphi_DEE_Entries[4];
 double DphiEm_DEE_Entries[4];
 double DphiEp_DEE_Entries[4]; 
 
 
 std::string buffer;
 int numSM;
 int numDEE;
  
 if(!fileData.is_open()) {
  std::cerr << "** ERROR: Can't open '" << nameDataTxt.Data() << "' for input" << std::endl;
 }
 if(!fileData2.is_open()) {
  std::cerr << "** ERROR: Can't open '" << nameData2Txt.Data() << "' for input" << std::endl;
 }
 if(!fileMC.is_open()) {
  std::cerr << "** ERROR: Can't open '" << nameMCTxt.Data() << "' for input" << std::endl;
 }
 
 while(!fileData.eof()) {
  getline(fileData,buffer);
//   std::cout << "buffer = " << buffer << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   std::stringstream line( buffer );      
   line >> numSM; 
   std::cout << numSM << " ";
   line >> numDEE; 
   std::cout << numDEE << " ";

   if (numSM!=-100) {
    line >> Dphi_SM_Mean[numSM];    std::cout << " " << Dphi_SM_Mean[numSM];
    line >> Dphi_SM_RMS[numSM];     std::cout << " " << Dphi_SM_RMS[numSM];
    line >> Dphi_SM_Entries[numSM]; std::cout << " " << Dphi_SM_Entries[numSM];
  
    line >> DphiEp_SM_Mean[numSM];    std::cout << " " << DphiEp_SM_Mean[numSM];
    line >> DphiEp_SM_RMS[numSM];     std::cout << " " << DphiEp_SM_RMS[numSM];
    line >> DphiEp_SM_Entries[numSM]; std::cout << " " << DphiEp_SM_Entries[numSM];
    
    line >> DphiEm_SM_Mean[numSM];    std::cout << " " << DphiEm_SM_Mean[numSM];
    line >> DphiEm_SM_RMS[numSM];     std::cout << " " << DphiEm_SM_RMS[numSM];
    line >> DphiEm_SM_Entries[numSM]; std::cout << " " << DphiEm_SM_Entries[numSM];
    
    line >> Deta_SM_Mean[numSM];    std::cout << " " << Deta_SM_Mean[numSM];
    line >> Deta_SM_RMS[numSM];     std::cout << " " << Deta_SM_RMS[numSM];
    line >> Deta_SM_Entries[numSM]; std::cout << " " << Deta_SM_Entries[numSM];
    
   }
   else {
    line >> Dphi_DEE_Mean[numDEE];    std::cout << " " << Dphi_DEE_Mean[numDEE];
    line >> Dphi_DEE_RMS[numDEE];     std::cout << " " << Dphi_DEE_RMS[numDEE];
    line >> Dphi_DEE_Entries[numDEE]; std::cout << " " << Dphi_DEE_Entries[numDEE];
    
    line >> DphiEp_DEE_Mean[numDEE];    std::cout << " " << DphiEp_DEE_Mean[numDEE];
    line >> DphiEp_DEE_RMS[numDEE];     std::cout << " " << DphiEp_DEE_RMS[numDEE];
    line >> DphiEp_DEE_Entries[numDEE]; std::cout << " " << DphiEp_DEE_Entries[numDEE];
    
    line >> DphiEm_DEE_Mean[numDEE];    std::cout << " " << DphiEm_DEE_Mean[numDEE];
    line >> DphiEm_DEE_RMS[numDEE];     std::cout << " " << DphiEm_DEE_RMS[numDEE];
    line >> DphiEm_DEE_Entries[numDEE]; std::cout << " " << DphiEm_DEE_Entries[numDEE];
    
    line >> Deta_DEE_Mean[numDEE];    std::cout << " " << Deta_DEE_Mean[numDEE];
    line >> Deta_DEE_RMS[numDEE];     std::cout << " " << Deta_DEE_RMS[numDEE];
    line >> Deta_DEE_Entries[numDEE]; std::cout << " " << Deta_DEE_Entries[numDEE];
    
   }
  } 
  
 }

 
 
 
 
 //---- plot
 double SM[36];
 double DEE[4];
 double Zero[36];
 for (int i=0; i<36; i++) {
  SM[i] = i;
  Zero[i] = 0;
 }
 for (int i=0; i<4; i++) {
  DEE[i] = i;
 }
 
 

 //---- delta phi
 
 TCanvas* cSM_Dphi = new TCanvas ("cSM_Dphi","cSM_Dphi",900,900);
 cSM_Dphi->Divide(1,3);
 
 cSM_Dphi->cd(1);
 TGraphErrors* gr_SM_Dphi = new TGraphErrors(36,SM,Dphi_SM_Mean,Zero,Dphi_SM_RMS);
 gr_SM_Dphi->SetTitle("#Delta#phi");
 gr_SM_Dphi->SetMarkerColor(kRed);
 gr_SM_Dphi->SetLineColor(kRed);
 gr_SM_Dphi->SetMarkerStyle(20);
 gr_SM_Dphi->SetMarkerSize(1);
 gr_SM_Dphi->SetLineWidth(1);
 gr_SM_Dphi->GetYaxis()->SetTitle("#Delta#phi");
 gr_SM_Dphi->Draw("AP");
 gPad->SetGrid();

 cSM_Dphi->cd(2);
 TGraphErrors* gr_SM_DphiEp = new TGraphErrors(36,SM,DphiEp_SM_Mean,Zero,DphiEp_SM_RMS);
 gr_SM_DphiEp->SetTitle("#Delta#phiEp");
 gr_SM_DphiEp->SetMarkerColor(kRed);
 gr_SM_DphiEp->SetLineColor(kRed);
 gr_SM_DphiEp->SetMarkerStyle(20);
 gr_SM_DphiEp->SetMarkerSize(1);
 gr_SM_DphiEp->SetLineWidth(1);
 gr_SM_DphiEp->GetYaxis()->SetTitle("#Delta#phi e+");
 gr_SM_DphiEp->Draw("AP");
 gPad->SetGrid();
 
 cSM_Dphi->cd(3);
 TGraphErrors* gr_SM_DphiEm = new TGraphErrors(36,SM,DphiEm_SM_Mean,Zero,DphiEm_SM_RMS);
 gr_SM_DphiEm->SetTitle("#Delta#phiEm");
 gr_SM_DphiEm->SetMarkerColor(kRed);
 gr_SM_DphiEm->SetLineColor(kRed);
 gr_SM_DphiEm->SetMarkerStyle(20);
 gr_SM_DphiEm->SetMarkerSize(1);
 gr_SM_DphiEm->SetLineWidth(1);
 gr_SM_DphiEm->GetYaxis()->SetTitle("#Delta#phi e-");
 gr_SM_DphiEm->Draw("AP");
 gPad->SetGrid();
 
 
 
 TCanvas* cDEE_Dphi = new TCanvas ("cDEE_Dphi","cDEE_Dphi",900,900);
 cDEE_Dphi->Divide(1,3);
 
 cDEE_Dphi->cd(1);
 TGraphErrors* gr_DEE_Dphi = new TGraphErrors(4,DEE,Dphi_DEE_Mean,Zero,Dphi_DEE_RMS);
 gr_DEE_Dphi->SetTitle("#Delta#phi");
 gr_DEE_Dphi->SetMarkerColor(kRed);
 gr_DEE_Dphi->SetLineColor(kRed);
 gr_DEE_Dphi->SetMarkerStyle(20);
 gr_DEE_Dphi->SetMarkerSize(1);
 gr_DEE_Dphi->SetLineWidth(1);
 gr_DEE_Dphi->GetYaxis()->SetTitle("#Delta#phi");
 gr_DEE_Dphi->Draw("AP");
 gPad->SetGrid();
 
 cDEE_Dphi->cd(2);
 TGraphErrors* gr_DEE_DphiEp = new TGraphErrors(4,DEE,DphiEp_DEE_Mean,Zero,DphiEp_DEE_RMS);
 gr_DEE_DphiEp->SetTitle("#Delta#phiEp");
 gr_DEE_DphiEp->SetMarkerColor(kRed);
 gr_DEE_DphiEp->SetLineColor(kRed);
 gr_DEE_DphiEp->SetMarkerStyle(20);
 gr_DEE_DphiEp->SetMarkerSize(1);
 gr_DEE_DphiEp->SetLineWidth(1);
 gr_DEE_DphiEp->GetYaxis()->SetTitle("#Delta#phi e+");
 gr_DEE_DphiEp->Draw("AP");
 gPad->SetGrid();
 
 cDEE_Dphi->cd(3);
 TGraphErrors* gr_DEE_DphiEm = new TGraphErrors(4,DEE,DphiEm_DEE_Mean,Zero,DphiEm_DEE_RMS);
 gr_DEE_DphiEm->SetTitle("#Delta#phiEm");
 gr_DEE_DphiEm->SetMarkerColor(kRed);
 gr_DEE_DphiEm->SetLineColor(kRed);
 gr_DEE_DphiEm->SetMarkerStyle(20);
 gr_DEE_DphiEm->SetMarkerSize(1);
 gr_DEE_DphiEm->SetLineWidth(1);
 gr_DEE_DphiEm->GetYaxis()->SetTitle("#Delta#phi e-");
 gr_DEE_DphiEm->Draw("AP");
 gPad->SetGrid();
 
 
 
 
 //---- delta eta
 
 TCanvas* cSM_Deta = new TCanvas ("cSM_Deta","cSM_Deta",900,300);
 
 TGraphErrors* gr_SM_Deta = new TGraphErrors(36,SM,Deta_SM_Mean,Zero,Deta_SM_RMS);
 gr_SM_Deta->SetTitle("#Delta#eta");
 gr_SM_Deta->SetMarkerColor(kRed);
 gr_SM_Deta->SetLineColor(kRed);
 gr_SM_Deta->SetMarkerStyle(20);
 gr_SM_Deta->SetMarkerSize(1);
 gr_SM_Deta->SetLineWidth(1);
 gr_SM_Deta->GetYaxis()->SetTitle("#Delta#eta");
 gr_SM_Deta->Draw("AP");
 gPad->SetGrid();
 
 
 
 TCanvas* cDEE_Deta = new TCanvas ("cDEE_Deta","cDEE_Deta",900,300);
 
 TGraphErrors* gr_DEE_Deta = new TGraphErrors(4,DEE,Deta_DEE_Mean,Zero,Deta_DEE_RMS);
 gr_DEE_Deta->SetTitle("#Delta#eta");
 gr_DEE_Deta->SetMarkerColor(kRed);
 gr_DEE_Deta->SetLineColor(kRed);
 gr_DEE_Deta->SetMarkerStyle(20);
 gr_DEE_Deta->SetMarkerSize(1);
 gr_DEE_Deta->SetLineWidth(1);
 gr_DEE_Deta->GetYaxis()->SetTitle("#Delta#eta");
 gr_DEE_Deta->Draw("AP");
 gPad->SetGrid();
 
 
 
 
 
 
}