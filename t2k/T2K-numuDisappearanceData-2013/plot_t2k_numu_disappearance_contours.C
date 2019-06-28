{
  TFile f("t2k_2013paper_likelihoodratio_contour_and_deltachisq.root");
  //style
  g_contour_90_o2->SetLineColor(kRed);
  g_contour_68_o2->SetLineColor(kRed);
  g_bestfit_o2->SetMarkerColor(kRed);
  g_contour_68_o2->SetLineStyle(2);
  g_contour_68_o1->SetLineStyle(2);
  //draw
  TCanvas * c = new TCanvas();
  c->SetLeftMargin(0.18);
  h_osc_param_space->GetXaxis()->SetRangeUser(0.9,1.0);
  h_osc_param_space->GetYaxis()->SetRangeUser(0.0021,0.0033);
  h_osc_param_space->Draw();
  g_contour_90_o2->Draw("L");
  g_contour_68_o2->Draw("L");
  g_contour_90_o1->Draw("L");
  g_contour_68_o1->Draw("L");
  g_bestfit_o2->Draw("P");
  g_bestfit_o1->Draw("P");
  //legend
  TLegend * l = new TLegend(0.2,0.6,0.7,0.92);
  l->SetFillColor(0);
  l->SetFillStyle(0);
  l->SetBorderSize(0);
  l->SetTextSize(0.05);
  l->AddEntry(g_bestfit_o1,    "T2K best fit (#theta_{23} #leq #pi/4)", "p");
  l->AddEntry(g_contour_68_o1, "T2K (#theta_{23} #leq #pi/4) 68% C.L.", "l");
  l->AddEntry(g_contour_90_o1, "T2K (#theta_{23} #leq #pi/4) 90% C.L.", "l");
  l->AddEntry(g_bestfit_o2,    "T2K best fit (#theta_{23} #geq #pi/4)", "p");
  l->AddEntry(g_contour_68_o2, "T2K (#theta_{23} #geq #pi/4) 68% C.L.", "l");
  l->AddEntry(g_contour_90_o2, "T2K (#theta_{23} #geq #pi/4) 90% C.L.", "l");
  l->Draw();
  //save
  c->SaveAs("t2k_numu_disappearance_contours.pdf");
  delete c;
  f.Close();
}
