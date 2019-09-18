void plotlatest() {
  TCanvas *canv = new TCanvas("canv", "canv", 1024, 1024);
  canv->SetLeftMargin(0.12);
  canv->SetRightMargin(0.014);
  canv->SetTopMargin(0.1);
  canv->SetBottomMargin(0.12);
  // Get NOvA, http://nova-docdb.fnal.gov/cgi-bin/ShowDocument?docid=38911
  TFile *nova_file = new TFile("novaroot/NOvA_2019_official_contour_ssth23dmsq32.root");
  TGraph *nova = (TGraph*)nova_file->Get("NH_90CL");
  // Get T2K
  TFile *t2k_file = new TFile("t2kroot/Data_RC_Atmo_Smeared.root");
  TGraph *t2k = (TGraph*)t2k_file->Get("g2_dl_90_0_NH");
  // Get IceCube, https://icecube.wisc.edu/science/data/2018nuosc
  TGraph *icecube = new TGraph("icecuberoot/IC2017_90CL_FC.dat");
  // Get SK, http://www-sk.icrr.u-tokyo.ac.jp/sk/publications/result-e.html
  TFile *sk_file = new TFile("skroot/sk1234.atmospheric.201803.nh.root");
  TGraph *sk = (TGraph*)sk_file->Get("sk1234_NH_S23M23_90CL");

  // Scale SK file
  for (int i = 0; i < sk->GetN(); ++i) sk->SetPoint(i, sk->GetX()[i], sk->GetY()[i]*1E3);
  for (int i = 0; i < t2k->GetN(); ++i) t2k->SetPoint(i, t2k->GetX()[i], t2k->GetY()[i]*1E3);

  sk->Draw("al");
  nova->Draw("l,same");
  t2k->Draw("l,same");
  icecube->Draw("l,same");

  // Prettify
  sk->SetLineColor(kRed-4);
  nova->SetLineColor(kBlue-6);
  icecube->SetLineColor(kYellow-2);
  t2k->SetLineColor(kGreen-6);
  sk->SetLineWidth(2);
  t2k->SetLineWidth(2);
  nova->SetLineWidth(2);
  icecube->SetLineWidth(2);

  sk->GetXaxis()->SetTitle("sin^{2} #theta_{23}");
  sk->GetYaxis()->SetTitle("#Deltam^{2}_{23} (#times 10^{-3} eV^{2})");
  sk->GetYaxis()->SetRangeUser(1.9, 3.55);
  sk->GetXaxis()->SetLimits(0.33, 0.67);
  sk->SetTitle("90% Normal Hierarchy");

  TLegend *leg1 = new TLegend(0.17, 0.63, 0.96, 0.87);
  leg1->SetNColumns(2);
  leg1->AddEntry(sk, "Super-K 2018", "l");
  leg1->AddEntry(nova, "NOvA 2019", "l");
  leg1->AddEntry(t2k, "T2K 2018", "l");
  leg1->AddEntry(icecube, "IceCube 2018", "l");

  leg1->Draw("same");
  canv->Print("plotlatest.pdf");
}
