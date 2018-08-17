// Draw a Bidimensional Histogram in many ways
// Together with its profiles and projections

void macro7(){
    gStyle->SetPalette(kBird);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);

    TH2F bidi_h("bidi_h","2D Histo; Gaussian Vals; Exp. Vals",
	    30,-5,5, //X axis
	    30,0,10); // Y axis
    TRandom3 rgen;
    for(int i=0;i<500000;i++)
	bidi_h.Fill(rgen.Gaus(0,2),10-rgen.Exp(4),.1);

    auto c1=new TCanvas("c1","Canvas",800,800);
    c1->Divide(2,2);
    c1->cd(1); 
    	bidi_h.DrawClone("Cont1");
    c1->cd(2);
    	bidi_h.DrawClone("Colz");
    c1->cd(3);
    	bidi_h.DrawClone("lego2");
    c1->cd(4);
    	bidi_h.DrawClone("surf3");

    // Profiles and Projections
    
    TCanvas *c2 = new TCanvas("Canvas2","Canvas2",800,800);
    c2->Divide(2,2);
    c2->cd(1);	bidi_h.ProjectionX()->DrawClone();
    c2->cd(2);	bidi_h.ProjectionY()->DrawClone();
    c2->cd(3);	bidi_h.ProfileX()->DrawClone();
    c2->cd(4);	bidi_h.ProfileY()->DrawClone();
    
}

