#include <TF1.h>
#include <TH1F.h>
#include <TROOT.h>

// Macro myfunc.C
Double_t myfunction(Double_t *x, Double_t *par)
{
    //x[0] is the self_varialbe, just as x; 
    // if it is 2D function, there will be x[0] and x[1] 
    // which represents x and y respectively
    Float_t xx = x[0];
    Double_t f= TMath::Abs(par[0]+par[1]*sin(xx));
    return f;
}

void myfunc(){
    // the "2" represents theare are 2 parameteres in "myfunction"
    TF1 *f1 = new TF1("myfunc",myfunction,0,10,2); 
    f1->SetParameters(2,10);
    f1->SetParNames("constant","coefficient");
    f1->Draw();
}

void myfit(){
    TH1F *h1 = new TH1F("h1","test",100,0,10);
    h1->FillRandom("myfunc",20000);
    TF1 *f1 = (TF1 *)gROOT->GetFunction("myfunc");
    f1->SetParameters(5,10);
    h1->Fit("myfunc");
}


