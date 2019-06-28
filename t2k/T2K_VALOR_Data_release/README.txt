The ROOT files with the data release are:

1) sinsqth13Vsdcp_Run17_Data_t2konly_nh.root or sinsqth13Vsdcp_Run17_Data_t2konly_ih.root
- chisq distribution and confidence regions as a function of dcp (X) and sinsqth13 (Y) for normal or inverted ordering
- the chisq distribution is the result of the analysis of the T2K data only (no reactor constraint)
- the file contains graphs with the 68% and 90% CL contours, the chisq and delta chisq map, the likelihood  and the best-fit point: 
  KEY: TGraph	g90_valor_0;1	Graph
  KEY: TGraph	g90_valor_1;1	Graph
  KEY: TGraph	g68_valor_0;1	Graph
  KEY: TH2D	chisq_map_2D;1	hchisq_marg_2D
  KEY: TH2D	dchisq_map_2D;1	hchisq_marg_2D
  KEY: TH2D	likelihood_2D;1	hchisq_marg_2D
  KEY: TMarker	best_fit_point_marker;1	Marker

2) sinsqth13Vsdcp_Run17_Data_t2kreactor_nh.root or sinsqth13Vsdcp_Run17_Data_t2kreactor_ih.root
 - chisq distribution and confidence regions as a function of dcp (X) and sinsqth13 (Y) for normal or inverted ordering
- the distributions are the results of the analysis of the T2K data with reactor constraint
- the file contains graphs with the 68% and 90% CL contours, the chisq and delta chisq map, the likelihood  and the best-fit point:
  KEY: TGraph					g90_valor_0;1	Graph
  KEY: TGraph					g90_valor_1;1	Graph
  KEY: TGraph					g68_valor_0;1	Graph
  KEY: TH2D					chisq_map_2D;1	hchisq_marg_2D
  KEY: TH2D					dchisq_map_2D;1	hchisq_marg_2D
  KEY: TH2D					likelihood_2D;1	hchisq_marg_2D
  KEY: TMarker					best_fit_point_marker;1	Marker

3) sinsqth23Vsdmsq_Run17_Data_t2kreactor_nh.root or sinsqth23Vsdmsq_Run17_Data_t2kreactor_ih.root
 - chisq distribution and confidence regions as a function of sinsqth23 (X) and dmsq32 (Y) for normal or inverted ordering
- the distributions are the results of the analysis of the T2K data with reactor constraint
- the file contains graphs with the 68% and 90% CL contours, the chisq and delta chisq map, the likelihood  and the best-fit point:

  KEY: TGraph					g90_valor_0;1		Graph
  KEY: TGraph					g68_valor_0;1		Graph
  KEY: TH2D					chisq_map_2D;1		hchisq_marg_2D
  KEY: TH2D					dchisq_map_2D;1		hchisq_marg_2D
  KEY: TH2D					likelihood_2D;1		hchisq_marg_2D
  KEY: TMarker					best_fit_point_marker;1	Marker

4) dcp_Run17_Data_t2kreactor_nh.root or dcp_Run17_Data_t2kreactor_ih.root



Notes: 
- the 2D confidence regions are done independently for normal and inverted ordering
- the 2D confidence regions are computed assuming the gaussian approximation, 
  setting the critical deltachisq values to 2.3 and 4.61 respectively for the 68% and 90% CL 
