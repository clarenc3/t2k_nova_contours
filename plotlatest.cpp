void plotlatest() {
  // Get NOvA, http://nova-docdb.fnal.gov/cgi-bin/ShowDocument?docid=38911
  TFile *nova_file = new TFile("novaroot/NOvA_2019_official_contour_ssth23dmsq32.root");
  TGraph *nova = (TGraph*)nova_file->Get("NH_90CL");
  // Get T2K
  // Get IceCube, https://icecube.wisc.edu/science/data/2018nuosc
  TGraph *icecube = new TGraph("icecuberoot/IC2017_90CL_FC.dat");
  // Get SK, http://www-sk.icrr.u-tokyo.ac.jp/sk/publications/result-e.html
  TFile *sk_file = new TFile("skroot/sk1234.atmospheric.201803.nh.root");
  TGraph *sk = (TGraph*)sk_file->Get("sk1234_NH_S23M23_90CL");

  // Scale SK file
  for (int i = 0; i < sk->GetN(); ++i) sk->SetPoint(i, sk->GetX()[i], sk->GetY()[i]*1E3);

  sk->Draw();
  nova->Draw("same");
  icecube->Draw("same");

  // Prettify
  sk->SetLineColor(kRed+4);
  nova->SetLineColor(kBlue+7);
  icecube->SetLineColor(kYellow+3);
  sk->SetLineWidth(2);
  nova->SetLineWidth(2);
  icecube->SetLineWidth(2);

  sk->GetXaxis()->SetTitle("sin^{2} #theta_{23}");
  sk->GetYaxis()->SetTitle("#Deltam^{2}_{23} (#times 10^{-3} eV^{2})");
}
