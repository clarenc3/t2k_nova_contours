#include "TGraph.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TText.h"
#include "TPaveText.h"
#include "TAxis.h"
#include "TGaxis.h"

#include <iostream>
#include <vector>

// Get the nova plots
TGraph **GetNOvA() {

  TGraph *gone = new TGraph("nova/march2016_prd.csv");
  //TGraph *two = new TGraph("neutrino2016.csv");
  TGraph *gthree = new TGraph("nova/april2017_prl.csv");
  //TGraph *four = new TGraph("nufact2017.csv");
  TGraph *gfive = new TGraph("nova/WC_Jan2018.csv");
  TGraph *gsix = new TGraph("nova/neutrino2018.csv");
  TGraph *gseven = new TGraph("nova/latest.csv");

  TGraph **nova = new TGraph*[5];
  nova[0] = gone;
  nova[1] = gthree;
  nova[2] = gfive;
  nova[3] = gsix;
  nova[4] = gseven;

  nova[0]->SetTitle("Mar 2016 PRD");
  nova[1]->SetTitle("Apr 2017 PRL");
  nova[2]->SetTitle("Jan 2018 W&C");
  nova[3]->SetTitle("Jun 2018 Neutrino");
  nova[4]->SetTitle("Jun 2019 arxiv");

  // Set y-axis to 1E-3
  for (int i = 0; i < 5; ++i) {
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
  nova[1]->SetMarkerColor(kGreen-3);
  nova[2]->SetMarkerColor(kSpring-4);
  nova[3]->SetMarkerColor(kYellow+2);
  nova[4]->SetMarkerColor(kYellow-6);

  // Could sort to nearest neighbour?

  return nova;
}

void plotnova() {

  const int nnova = 5;
  TGraph **nova = GetNOvA();

  Double_t s23bf[1];
  Double_t m23bf[1];
  Double_t s23bf_deg[2];
  Double_t m23bf_deg[2];

  s23bf_deg[0] = 0.43;
  m23bf_deg[0] = 0.00252;
  s23bf_deg[1] = 0.60;
  m23bf_deg[1] = 0.00252;
  TGraph *nova_0bf = new TGraph(2,s23bf_deg,m23bf_deg);
  s23bf_deg[0] = 0.404;
  m23bf_deg[0] = 0.00267;
  s23bf_deg[1] = 0.624;
  m23bf_deg[1] = 0.00267;
  TGraph *nova_1bf = new TGraph(2,s23bf_deg,m23bf_deg);
  s23bf[0] = 0.558;
  m23bf[0] = 0.002444;
  TGraph *nova_2bf = new TGraph(1,s23bf,m23bf);
  s23bf[0] = 0.58;
  m23bf[0] = 0.00251;
  TGraph *nova_3bf = new TGraph(1,s23bf,m23bf);
  s23bf[0] = 0.56;
  m23bf[0] = 0.00248;
  TGraph *nova_4bf = new TGraph(1,s23bf,m23bf);

  TGraph **novabf = new TGraph*[5];
  novabf[0] = nova_0bf;
  novabf[1] = nova_1bf;
  novabf[2] = nova_2bf;
  novabf[3] = nova_3bf;
  novabf[4] = nova_4bf;


  TCanvas *canv = new TCanvas("canv", "canv", 512, 512);
  canv->SetLeftMargin(0.14);
  canv->SetRightMargin(0.03);
  canv->SetBottomMargin(0.11);
  canv->SetTopMargin(0.05);
  canv->Print("NOvA_results.gif");
  TGaxis::SetMaxDigits(1);

  // Make a NOvA TText
  TPaveText *novatext = new TPaveText(0.15, 0.55, 0.95, 0.95, "NDC");
  novatext->SetFillColor(0);
  novatext->SetFillStyle(0);
  novatext->AddText("NOvA results, 90%");
  ((TText*)novatext->GetListOfLines()->At(0))->SetTextSize(0.04);
  for (int i = 0; i < nnova; ++i) {
    novatext->AddText("");
  }

  novatext->SetBorderSize(0);
  novatext->SetTextSize(0.03);
  bool haveaxis = false;
  for (int i = 0; i < nnova; ++i) {
    if (!haveaxis) {
      nova[i]->Draw("AP");
      nova[i]->GetXaxis()->SetRangeUser(0.3, 0.7);
      nova[i]->GetYaxis()->SetRangeUser(2E-3, 4.2E-3);
      nova[i]->GetYaxis()->SetNoExponent(false);
      nova[i]->GetYaxis()->SetTitleOffset(1.29);
      nova[i]->GetYaxis()->SetTitle("#Deltam^{2}_{23} (eV^{2})");
      nova[i]->GetXaxis()->SetTitle("sin^{2}#theta_{23}");
      haveaxis = true;
      novabf[i]->SetMarkerStyle(34);
      novabf[i]->Draw("same,P");
      novabf[i]->SetMarkerColor(nova[i]->GetMarkerColor()); 
    }
    else {
      nova[i]->Draw("P, same");
      novabf[i]->SetMarkerStyle(34);
      novabf[i]->Draw("same,P");
      novabf[i]->SetMarkerColor(nova[i]->GetMarkerColor()); 
    }
    ((TText*)novatext->GetListOfLines()->At(i+1))->SetText(0,0, nova[i]->GetTitle());
    ((TText*)novatext->GetListOfLines()->At(i+1))->SetTextColor(nova[i]->GetMarkerColor());
    nova[i]->SetTitle("");
    novatext->Draw("same");
    canv->Print("NOvA_results.gif+50");
  }
}

