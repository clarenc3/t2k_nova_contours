
The ROOT files with the data release are:

1) sinsqth23Vsdmsq_Run18_Data_react_nh.root (fig. X)
- chisq distribution and confidence regions as a function of sinsqth23 (X) and dmsq32 (Y) for normal ordering
- sin^2\theta_{13} has been constrained with the reactor measurements (PDG 2016)
- the file contains two graphs with the 68% and 90% CL contours, the likelihood surface, the chisq and dchisq maps and the best-fit point: 
  KEY: TGraph	g90_0;1
  KEY: TGraph	g68_0;1
  KEY: TH2D     likelihood_2D;1
  KEY: TH2D	chisq_map_2D;1
  KEY: TH2D     dchisq_map_2D;1
  KEY: TMarker	best_fit_point_marker;1

2) sinsqth23Vsdmsq_Run18_Data_react_ih.root (fig. X)
- chisq distribution and confidence regions as a function of sinsqth23 (X) and dmsq32 (Y) for inverted ordering
- sin^2\theta_{13} has been constrained with the reactor measurements (PDG 2016)
- the file contains two graphs with the 68% and 90% CL contours, the likelihood surface, the chisq and dchisq maps and the best-fit point: 
  KEY: TGraph	g90_0;1
  KEY: TGraph	g68_0;1
  KEY: TH2D     likelihood_2D;1
  KEY: TH2D	chisq_map_2D;1
  KEY: TH2D     dchisq_map_2D;1
  KEY: TMarker	best_fit_point_marker;1

3) sinsqth13Vsdcp_Run18_Data_t2konly_nh.root (fig. Y)
- chisq distribution and confidence regions as a function of dcp (X) and sinsqth13 (Y) for normal ordering
- the chisq distribution is the result of the analysis of the T2K data only (no reactor constraint)
- the file contains 4 graphs with the 68% and 90% CL contours, the likelihood surface, the chisq and dchisq maps and the best-fit point: 
  KEY: TGraph	g90_0;1
  KEY: TGraph	g90_1;1
  KEY: TGraph	g68_0;1
  KEY: TGraph	g68_1;1
  KEY: TH2D     likelihood_2D;1
  KEY: TH2D	chisq_map_2D;1
  KEY: TH2D	dchisq_map_2D;1
  KEY: TMarker	best_fit_point_marker;1

4) sinsqth13Vsdcp_Run18_Data_t2konly_ih.root (fig. Y)
- chisq distribution and confidence regions as a function of dcp (X) and sinsqth13 (Y) for inverted ordering
- the chisq distribution is the result of the analysis of the T2K data only (no reactor constraint)
- the file contains 3 graphs with the 68% and 90% CL contours, the likelihood surface, the chisq and dchisq maps and the best-fit point: 
  KEY: TGraph	g90_0;1
  KEY: TGraph	g90_1;1
  KEY: TGraph	g68_0;1
  KEY: TGraph	g68_1;1
  KEY: TH2D     likelihood_2D;1
  KEY: TH2D	chisq_map_2D;1
  KEY: TH2D	dchisq_map_2D;1
  KEY: TMarker	best_fit_point_marker;1

5) deltachisq_deltacp_Run18_Data_react.root (fig. Z)
- the deltachisq distribution for deltaCP for both normal and inverted mass ordering is done with respect to the overall best-fit point, which is in normal ordering
- sin^2\theta_{13} has been constrained with the reactor measurements (PDG 2016)
- the file contains the deltachisq maps for both mass orderings
  KEY: TH1D	hdeltachisq1D_GlobMin_file0_mh0;1	hchisq_marg_1D
  KEY: TH1D	hdeltachisq1D_GlobMin_file0_mh1;1	hchisq_marg_1D

Notes: 
- the 2D confidence regions are done independently for normal and inverted ordering
- the 2D confidence regions are computed assuming the gaussian approximation, 
  setting the critical deltachisq values to 2.3 and 4.61 respectively for the 68% and 90% CL 

