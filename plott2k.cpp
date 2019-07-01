#include "TGraph.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TText.h"
#include "TPaveText.h"
#include "TAxis.h"
#include "TGaxis.h"

#include <iostream>
#include <vector>


TGraph **GetT2K() {

  // ****************************
  // Get the T2K plots
  TGraph *garg = new TGraph("t2k/T2K-numuDisappearanceData-2013/handscan.csv");
  for (int i = 0; i < garg->GetN(); ++i) {
    garg->SetPoint(i, garg->GetX()[i], garg->GetY()[i]*1.E-3);
  }
  garg->SetTitle("Nov 2013 PRL");

  TFile *six = new TFile("t2k/T2K-numuDisappearanceData-Run1to4-2014/T2K-numuDisappearanceData-Run1to4-2014.root", "open");
  TGraph *g6 = (TGraph*)six->Get("t2krun1to4_normal_2D_FC_90CLcontour");
  //TGraph g6 = (TGraph*)six->Get("t2krun1to4_inverted_2D_FC_90CLcontour");
  g6->SetTitle("May 2014 PRL");

  TFile *three = new TFile("t2k/T2KJointNuNuBarOscillation_Run17c_2016/sinsqth23Vsdmsq_Run17c_Data_react_nh.root","open");
  //TFile *three = new TFile("T2KJointNuNuBarOscillation_Run17c_2016/sinsqth23Vsdmsq_Run17c_Data_react_ih.root","open");
  TGraph *g3 = (TGraph*)three->Get("g90_valor_0");
  g3->SetTitle("Apr 2017 PRL");

  TFile *two = new TFile("t2k/t2kdata-numu-numubar-disap-2016/T2K_NuMuDissap-Run1_Run7_2016.root", "open");
  TGraph *g2 = (TGraph*)two->Get("NuMu_cont_2d_90_normal");
  //TGraph g2 = (TGraph*)two->Get("NuMuBar_cont_2d_90_normal");
  g2->SetTitle("Jul 2017 PRD");

  //TFile *seven = new TFile("T2K_VALOR_Data_release/sinsqth23Vsdmsq_Run17_Data_t2kreactor_ih.root","open");
  TFile *seven = new TFile("t2k/T2K_VALOR_Data_release/sinsqth23Vsdmsq_Run17_Data_t2kreactor_nh.root", "open");
  TGraph *g7 = (TGraph*)seven->Get("g90_valor_0");
  g7->SetTitle("Nov 2017 PRD");

  TFile *four = new TFile("t2k/T2KJointNuNuBarOscillation_Run18_2017/sinsqth23Vsdmsq_Run18_Data_react_nh.root", "open");
  //TFile *four = new TFile("T2KJointNuNuBarOscillation_Run18_2017/sinsqth23Vsdmsq_Run18_Data_react_ih.root", "open");
  TGraph *g4 = (TGraph*)four->Get("g90_0");
  g4->SetTitle("Oct 2018 PRL");


  TFile *five = new TFile("t2k/t2k_neutrino_2018_fits/t2k_atmospheric_fits.root");
  TGraph *g5 = (TGraph*)five->Get("atm_wrc_nh_90_0");
  //TGraph g5 = (TGraph*)four->Get("atm_wrc_ih_90_0");
  g5->SetTitle("Jun 2018 Neutrino");

  // ****************************

  TGraph **t2k = new TGraph*[7];
  t2k[0]=garg;
  t2k[1]=g6;
  t2k[2]=g3;
  t2k[3]=g2;
  t2k[4]=g7;
  t2k[5]=g4;
  t2k[6]=g5;

  for (int i = 0; i < 7; ++i) {
    t2k[i]->SetMarkerSize(0.5);
    t2k[i]->SetMarkerStyle(20);
  }
  /*
  t2k[0]->SetMarkerColor(kBlack);
  t2k[1]->SetMarkerColor(kRed-4);
  t2k[2]->SetMarkerColor(kMagenta-6);
  t2k[3]->SetMarkerColor(kBlue-7);
  t2k[4]->SetMarkerColor(kCyan-3);
  t2k[5]->SetMarkerColor(kGreen-2);
  t2k[6]->SetMarkerColor(kYellow-3);
  */
  t2k[0]->SetMarkerColor(kRed+3);
  t2k[1]->SetMarkerColor(kRed);
  t2k[2]->SetMarkerColor(kRed-6);
  t2k[3]->SetMarkerColor(kPink-8);
  t2k[4]->SetMarkerColor(kMagenta+1);
  t2k[5]->SetMarkerColor(kMagenta-6);
  t2k[6]->SetMarkerColor(kMagenta-9);

  return t2k;
}

void plott2k() {

  const int nt2k = 7;
  TGraph **t2k = GetT2K();
  Double_t s23bf[1];
  Double_t m23bf[1];

  s23bf[0] = 0.514;
  m23bf[0] = 0.00244;
  TGraph *t2k_0bf = new TGraph(1,s23bf,m23bf);
  s23bf[0] = 0.514;
  m23bf[0] = 0.00251;
  TGraph *t2k_1bf = new TGraph(1,s23bf,m23bf);
  s23bf[0] = 0.532;
  m23bf[0] = 0.002545;
  TGraph *t2k_2bf = new TGraph(1,s23bf,m23bf);
  s23bf[0] = 0.51;
  m23bf[0] = 0.00253;
  TGraph *t2k_3bf = new TGraph(1,s23bf,m23bf);
  s23bf[0] = 0.51;
  m23bf[0] = 0.00254;
  TGraph *t2k_4bf = new TGraph(1,s23bf,m23bf);
  s23bf[0] = 0.526;
  m23bf[0] = 0.002463;
  TGraph *t2k_5bf = new TGraph(1,s23bf,m23bf);
  s23bf[0] = 0.536;
  m23bf[0] = 0.002434;
  TGraph *t2k_6bf = new TGraph(1,s23bf,m23bf);

  TGraph **t2kbf = new TGraph*[7];
  t2kbf[0] = t2k_0bf;
  t2kbf[1] = t2k_1bf;
  t2kbf[2] = t2k_2bf;
  t2kbf[3] = t2k_3bf;
  t2kbf[4] = t2k_4bf;
  t2kbf[5] = t2k_5bf;
  t2kbf[6] = t2k_6bf;

  TCanvas *canv = new TCanvas("canv", "canv", 512, 512);
  canv->SetLeftMargin(0.14);
  canv->SetRightMargin(0.03);
  canv->SetBottomMargin(0.11);
  canv->SetTopMargin(0.05);
  canv->Print("T2K_results.gif");
  TGaxis::SetMaxDigits(1);

  // Make a T2K TText
  TPaveText *t2ktext = new TPaveText(0.15, 0.55, 0.95, 0.95, "NDC");
  t2ktext->SetFillColor(0);
  t2ktext->SetFillStyle(0);
  t2ktext->AddText("T2K results, 90%");
  ((TText*)t2ktext->GetListOfLines()->At(0))->SetTextSize(0.04);
  t2ktext->SetBorderSize(0);
  t2ktext->SetTextSize(0.03);
  for (int i = 0; i < nt2k; ++i) {
    t2ktext->AddText("");
  }
  for (int i = 0; i < nt2k; ++i) {
    if (i == 0) {
      t2k[i]->Draw("AP");
      t2k[i]->GetXaxis()->SetRangeUser(0.3, 0.7);
      t2k[i]->GetYaxis()->SetRangeUser(2E-3, 4.2E-3);
      t2k[i]->GetYaxis()->SetNoExponent(false);
      t2k[i]->GetYaxis()->SetTitleOffset(1.29);
      t2k[i]->GetYaxis()->SetTitle("#Deltam^{2}_{23} (eV^{2})");
      t2k[i]->GetXaxis()->SetTitle("sin^{2}#theta_{23}");
      t2kbf[i]->SetMarkerStyle(34);
      t2kbf[i]->Draw("same,P");
      t2kbf[i]->SetMarkerColor(t2k[i]->GetMarkerColor());
    }
    else {
      t2k[i]->Draw("same");
      t2k[i]->SetLineWidth(4);
      t2k[i]->SetLineColor(t2k[i]->GetMarkerColor());
      t2kbf[i]->SetMarkerStyle(34);
      t2kbf[i]->Draw("same,P");
      t2kbf[i]->SetMarkerColor(t2k[i]->GetMarkerColor());
     }
    ((TText*)t2ktext->GetListOfLines()->At(i+1))->SetText(0,0, t2k[i]->GetTitle());
    ((TText*)t2ktext->GetListOfLines()->At(i+1))->SetTextColor(t2k[i]->GetMarkerColor());
    t2k[i]->SetTitle("");
    t2ktext->Draw("same");
    canv->Print("T2K_results.gif+50");
  }

}

