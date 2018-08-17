// Manage several graphs as a single entity.
//
void multigraph(){
    TCanvas *c1 = new TCanvas("c1","multigraph",700,500);
    c1->SetGrid();

    TMultiGraph *mg = new TMultiGraph();

    // Create first graph
    const Int_t n1 = 10;
    Double_t px1[]={-0.1,0.05,0.25,0.35,0.5,0.61,0.7,0.85,0.89,0.95};
    Double_t py1[]={-1,2.9,5.6,7.4,9,9.6,8.7,6.3,4.5,1};
    Double_t ex1[]={0.05,0.1,0.07,0.07,0.04,0.05,0.06,.07,.08,.05};
    Double_t ey1[]={.8,.7,.6,.5,.4,.4,.5,.6,.7,.8};
    TGraphErrors *gr1 = new TGraphErrors(n1,px1,py1,ex1,ey1);
    gr1->SetMarkerColor(kBlue);
    gr1->SetMarkerStyle(21);
    mg->Add(gr1);

    // crate 2nd graph
    const Int_t n2=10;
    Float_t px2[]={-0.28,.005,.19,.29,.45,.56,.65,.8,.9,1.01};
    Float_t py2[]={2.1,3.86,7,9,10,10.55,9.64,7.26,5.42,2};
    Float_t ex2[]={.04,.12,.08,.06,.05,.04,.07,.06,.08,.04};
    Float_t ey2[]={.6,.8,.7,.4,.3,.3,.4,.5,.6,.7};
    TGraphErrors *gr2 = new TGraphErrors(n2,px2,py2,ex2,ey2);
    gr2->SetMarkerColor(kRed);
    gr2->SetMarkerStyle(20);
    mg->Add(gr2);

    mg->Draw("apl");
    mg->GetXaxis()->SetTitle("X values");
    mg->GetYaxis()->SetTitle("Y values");

    gPad->Update();
    gPad->Modified();
}
