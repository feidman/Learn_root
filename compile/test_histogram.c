void test_histogram(){
    TH1F *h = new TH1F("h","",100,0,10);
    h->FillRandom("gaus",10000);
    h->Draw();
}
