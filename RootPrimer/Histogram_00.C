//1st historgram example in ROOT

void Histogram_00(){
    TF1 efunc("efunc","exp([0]+[1]*x)",0.,5.);
    efunc.SetParameter(0,1);
    efunc.SetParameter(1,-1);
    //  TH1F h = TH1F("h","Example histogram",100,0.,5.);
    //  no graph displayed on the canvas if there is no poiter defined
    //  but with the environment of root it is OKEY
    TH1F *h = new TH1F("h","Example histogram",100,0.,5.);
    
    for(int i=0;i<1000;i++)
    {
	h->Fill(efunc.GetRandom());
    }
    h->Draw();

}
