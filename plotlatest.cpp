#include "TGraph.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TText.h"
#include "TPaveText.h"
#include "TAxis.h"
#include "TGaxis.h"

#include <iostream>
#include <vector>

const double xlow = 0.25;
const double xhi = 0.75;
const double ylow = 0.5E-3;
const double yhi = 5.0E-3;

const int nt2k = 1;
const int nnova = 1;
const int nminos = 1;
const int nicecube = 1;
const int nsk = 1;

// in 1E-3 units
TGraph **GetMINOS() {
  TGraph **minos = new TGraph*[nminos];

  // https://www-numi.fnal.gov/PublicInfo/plots/MINOS2014/MinosPlusT2K.png
  //TGraph *g_one = new TGraph("minos/minos2014.csv");
  //g_one->SetTitle("MINOS NuMI+atm 2014");
  // https://www-numi.fnal.gov/PublicInfo/plots/MINOS2016/MINOSxx_NOvA_T2K_contours_compare.pdf
  TGraph *g_two = new TGraph("minos/minos2016.csv");
  g_two->SetTitle("MINOS/MINOS+ NuMI+atm 2016");
  //g_one->SetMarkerColor(kRed);
  g_two->SetMarkerColor(kBlue);
  //minos[0] = g_one;
  minos[0] = g_two;
  //minos[1] = g_two;

  for (int i = 0; i < nminos; ++i) {
    for (int j = 0; j < minos[i]->GetN(); ++j) {
      minos[i]->SetPoint(j, minos[i]->GetX()[j], minos[i]->GetY()[j]*1E-3);
    }
  }

  for (int i = 0; i < nminos; ++i) {
    minos[i]->SetLineColor(minos[i]->GetMarkerColor());
    minos[i]->SetMarkerStyle(33);
  }

  return minos;
}

// in 1E-3 units
TGraph **GetIceCube() {

  TGraph **icecube = new TGraph*[nicecube];
  //TGraph *g_one = new TGraph("icecube/icecube2014.csv");
  TGraph *g_two = new TGraph("icecube/icecube2017.csv");
  //g_one->SetMarkerColor(kBlue);
  g_two->SetMarkerColor(kRed);

  icecube[0]=g_two;
  //icecube[1]=g_two;
  for (int i = 0; i < nicecube; ++i) {
    for (int j = 0; j < icecube[i]->GetN(); ++j) {
      icecube[i]->SetPoint(j, icecube[i]->GetX()[j], icecube[i]->GetY()[j]*1E-3);
    }
  }

  for (int i = 0; i < nicecube; ++i) {
    icecube[i]->SetLineColor(icecube[i]->GetMarkerColor());
    icecube[i]->SetMarkerStyle(22);
  }
  return icecube;
}

// Already in right units
TGraph **GetSK() {
  TGraph **sk = new TGraph*[nsk];
  // https://arxiv.org/pdf/1002.3471.pdf
  //TGraph *g_one = new TGraph("superk/superk_2010.csv");
  // https://arxiv.org/pdf/1710.09126.pdf
  //TGraph *g_two = new TGraph("superk/superk_prd_2018_extconst.csv");
  // https://arxiv.org/pdf/1901.03230.pdf
  TGraph *g_three = new TGraph("superk/superk_2019.csv");
  //g_one->SetTitle("SK I+II+III 2010");
  //g_one->SetMarkerColor(kBlack);
  //g_two->SetTitle("SK IV 2017+T2K #theta_{13}");
  //g_two->SetMarkerColor(kBlue);
  g_three->SetTitle("SK IV 2019");
  g_three->SetMarkerColor(kRed);

  //sk[0] = g_one;
  sk[0] = g_three;
  //sk[1] = g_two;
  //sk[2] = g_three;
  for (int i = 0; i < nsk; ++i) {
    sk[i]->SetLineColor(sk[i]->GetMarkerColor());
    sk[i]->SetMarkerStyle(23);
  }
  return sk;
}


TGraph **GetT2K() {
  // ****************************
  // Get the T2K plots
  /*
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
  */


  TFile *five = new TFile("t2k/t2k_neutrino_2018_fits/t2k_atmospheric_fits.root");
  TGraph *g5 = (TGraph*)five->Get("atm_wrc_nh_90_0");
  //TGraph g5 = (TGraph*)four->Get("atm_wrc_ih_90_0");
  g5->SetTitle("Jun 2018 Neutrino");

  // ****************************

  TGraph **t2k = new TGraph*[nt2k];
  /*
  t2k[0]=garg;
  t2k[1]=g6;
  t2k[2]=g3;
  t2k[3]=g2;
  t2k[4]=g7;
  t2k[5]=g4;
  t2k[6]=g5;
  */
  t2k[0]=g5;

  for (int i = 0; i < nt2k; ++i) {
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
  /*
  t2k[1]->SetMarkerColor(kRed);
  t2k[2]->SetMarkerColor(kRed-6);
  t2k[3]->SetMarkerColor(kPink-8);
  t2k[4]->SetMarkerColor(kMagenta+1);
  t2k[5]->SetMarkerColor(kMagenta-6);
  t2k[6]->SetMarkerColor(kMagenta-9);
  */

  return t2k;
}

// Get the nova plots
TGraph **GetNOvA() {

  TGraph *gone = new TGraph("nova/march2016_prd.csv");
  //TGraph *two = new TGraph("neutrino2016.csv");
  TGraph *gthree = new TGraph("nova/april2017_prl.csv");
  //TGraph *four = new TGraph("nufact2017.csv");
  TGraph *gfive = new TGraph("nova/WC_Jan2018.csv");
  TGraph *gsix = new TGraph("nova/neutrino2018.csv");
  TGraph *gseven = new TGraph("nova/latest.csv");

  TGraph **nova = new TGraph*[nnova];
  /*
  nova[0] = gone;
  nova[1] = gthree;
  nova[2] = gfive;
  nova[3] = gsix;
  nova[4] = gseven;
  */
  nova[0] = gseven;

  /*
  nova[0]->SetTitle("Mar 2016 PRD");
  nova[1]->SetTitle("Apr 2017 PRL");
  nova[2]->SetTitle("Jan 2018 W&C");
  nova[3]->SetTitle("Jun 2018 Neutrino");
  */
  nova[0]->SetTitle("Jun 2019 arxiv");

  // Set y-axis to 1E-3
  for (int i = 0; i < nnova; ++i) {
    for (int j = 0; j < nova[i]->GetN(); ++j) {
      nova[i]->SetPoint(j, nova[i]->GetX()[j], nova[i]->GetY()[j]*1E-3);
    }
    nova[i]->SetMarkerSize(0.5);
    nova[i]->SetMarkerStyle(20);
  }

  /*
     nova[0]->SetMarkerColor(kBlack);
     nova[1]->SetMarkerColor(kPink-4);
     nova[2]->SetMarkerColor(kViolet-6);
     nova[3]->SetMarkerColor(kAzure-5);
     nova[4]->SetMarkerColor(kTeal-5);
     */
  nova[0]->SetMarkerColor(kGreen+3);
  /*
  nova[1]->SetMarkerColor(kGreen-3);
  nova[2]->SetMarkerColor(kSpring-4);
  nova[3]->SetMarkerColor(kYellow+2);
  nova[4]->SetMarkerColor(kYellow-6);
  */

  // Could sort to nearest neighbour?

  return nova;
}

void plotlatest() {

  TGraph **t2k = GetT2K();
  TGraph **nova = GetNOvA();
  TGraph **sk = GetSK();
  TGraph **icecube = GetIceCube();
  TGraph **minos = GetMINOS();

  TCanvas *canv = new TCanvas("canv", "canv", 1024, 1024);
  canv->SetLeftMargin(0.14);
  canv->SetRightMargin(0.04);
  canv->SetBottomMargin(0.11);
  canv->SetTopMargin(0.05);
  canv->Print("All_results.gif");
  TGaxis::SetMaxDigits(1);

  bool haveaxis = false;
  // Make a SK TText
  TPaveText *sktext = new TPaveText(0.17, 0.13, 0.35, 0.33, "NDC");
  sktext->SetFillColor(0);
  sktext->SetFillStyle(0);
  sktext->AddText("SK, 90%");
  ((TText*)sktext->GetListOfLines()->At(0))->SetTextSize(0.03);
  for (int i = 0; i < nsk; ++i) {
    sktext->AddText("");
    ((TText*)sktext->GetListOfLines()->At(i+1))->SetTextSize(0.02);
  }
  sktext->SetBorderSize(0);

  for (int i = 0; i < nsk; ++i) {
    std::cout << sk[i]->GetTitle() << std::endl;
    if (!haveaxis) {
      sk[i]->Draw("AP");
      //sk[i]->GetXaxis()->SetRangeUser(0.2, 0.80);
      sk[i]->GetXaxis()->SetLimits(xlow, xhi);
      sk[i]->GetYaxis()->SetRangeUser(ylow, yhi);
      sk[i]->GetYaxis()->SetNoExponent(false);
      sk[i]->GetYaxis()->SetTitleOffset(1.29);
      sk[i]->GetYaxis()->SetTitle("#Deltam^{2}_{23} (eV^{2})");
      sk[i]->GetXaxis()->SetTitle("sin^{2}#theta_{23}");
      haveaxis = true;
    }
    else sk[i]->Draw("P, same");

    ((TText*)sktext->GetListOfLines()->At(i+1))->SetText(0,0, sk[i]->GetTitle());
    ((TText*)sktext->GetListOfLines()->At(i+1))->SetTextColor(sk[i]->GetMarkerColor());
    sk[i]->SetTitle("");
    sktext->Draw("same");
    canv->Print("All_results.gif+50");
  }

  // Make a SK TText
  TPaveText *minostext = new TPaveText(0.36, 0.13, 0.70, 0.33, "NDC");
  minostext->SetFillColor(0);
  minostext->SetFillStyle(0);
  minostext->AddText("MINOS, 90%");
  ((TText*)minostext->GetListOfLines()->At(0))->SetTextSize(0.03);
  for (int i = 0; i < nminos; ++i) {
    minostext->AddText("");
    ((TText*)minostext->GetListOfLines()->At(i+1))->SetTextSize(0.02);
  }
  minostext->SetBorderSize(0);
  for (int i = 0; i < nminos; ++i) {
    minos[i]->Draw("P, same");
    ((TText*)minostext->GetListOfLines()->At(i+1))->SetText(0,0, minos[i]->GetTitle());
    ((TText*)minostext->GetListOfLines()->At(i+1))->SetTextColor(minos[i]->GetMarkerColor());
    minos[i]->SetTitle("");
    minostext->Draw("same");
    canv->Print("All_results.gif+50");
  }


  // Make a SK TText
  TPaveText *icecubetext = new TPaveText(0.65, 0.14, 0.99, 0.32, "NDC");
  icecubetext->SetFillColor(0);
  icecubetext->SetFillStyle(0);
  icecubetext->AddText("IceCube 90%");
  ((TText*)icecubetext->GetListOfLines()->At(0))->SetTextSize(0.03);
  for (int i = 0; i < nicecube; ++i) {
    icecubetext->AddText("");
    ((TText*)icecubetext->GetListOfLines()->At(i+1))->SetTextSize(0.02);
  }
  icecubetext->SetBorderSize(0);
  for (int i = 0; i < nicecube; ++i) {
    icecube[i]->Draw("P,same");
    ((TText*)icecubetext->GetListOfLines()->At(i+1))->SetText(0,0, icecube[i]->GetTitle());
    ((TText*)icecubetext->GetListOfLines()->At(i+1))->SetTextColor(icecube[i]->GetMarkerColor());
    icecube[i]->SetTitle("");
    icecubetext->Draw("same");
    canv->Print("All_results.gif+50");
  }

  // Make a NOvA TText
  TPaveText *novatext = new TPaveText(0.17, 0.64, 0.35, 0.93, "NDC");
  novatext->SetFillColor(0);
  novatext->SetFillStyle(0);
  novatext->AddText("NOvA, 90%");
  ((TText*)novatext->GetListOfLines()->At(0))->SetTextSize(0.03);
  for (int i = 0; i < nnova; ++i) {
    novatext->AddText("");
    ((TText*)novatext->GetListOfLines()->At(i+1))->SetTextSize(0.02);
  }
  novatext->SetBorderSize(0);
  for (int i = 0; i < nnova; ++i) {
    nova[i]->Draw("P, same");
    ((TText*)novatext->GetListOfLines()->At(i+1))->SetText(0,0, nova[i]->GetTitle());
    ((TText*)novatext->GetListOfLines()->At(i+1))->SetTextColor(nova[i]->GetMarkerColor());
    nova[i]->SetTitle("");
    novatext->Draw("same");
    canv->Print("All_results.gif+50");
  }

  // Make a T2K TText
  TPaveText *t2ktext = new TPaveText(0.76, 0.64, 0.92, 0.93, "NDC");
  t2ktext->SetFillColor(0);
  t2ktext->SetFillStyle(0);
  t2ktext->AddText("T2K, 90%");
  ((TText*)t2ktext->GetListOfLines()->At(0))->SetTextSize(0.03);
  t2ktext->SetBorderSize(0);
  for (int i = 0; i < nt2k; ++i) {
    t2ktext->AddText("");
    ((TText*)t2ktext->GetListOfLines()->At(i+1))->SetTextSize(0.02);
  }
  for (int i = 0; i < nt2k; ++i) {
    if (i == 0) t2k[i]->Draw("P,same");
    else {
      t2k[i]->Draw("same");
      t2k[i]->SetLineWidth(4);
      t2k[i]->SetLineColor(t2k[i]->GetMarkerColor());
    }
    ((TText*)t2ktext->GetListOfLines()->At(i+1))->SetText(0,0, t2k[i]->GetTitle());
    ((TText*)t2ktext->GetListOfLines()->At(i+1))->SetTextColor(t2k[i]->GetMarkerColor());
    t2k[i]->SetTitle("");
    t2ktext->Draw("same");
    canv->Print("All_results.gif+50");
  }



  canv->Print("All_results.gif++");
}

