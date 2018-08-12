void ed_Hist(){
    TH1F *hrow = new TH1F("hrow","Distribution of row Number",100,0,100);
    TH1F *hcol = new TH1F("hcol","Distribution of col Number",100,0,90);
    TH1F *hx = new TH1F("hx","Distribution of x Coordinates",50,33609651,33611300);
    TH1F *hy = new TH1F("hy","Distribution of y Coordinates",100,3248700,3250165);
    TH1F *hz = new TH1F("hz","Distribution of z Coordinates",100,0,100);

    // link vars with the branch of TTree
    int num_row,num_col;
    float x,y,z;
    TFile ed_ifile("ed_data.root");
    TTree* ed_data = (TTree*)ed_ifile.GetObjectChecked("ed_data","TTree");
    ed_data->SetBranchAddress("num_row",&num_row);
    ed_data->SetBranchAddress("num_col",&num_col);
    ed_data->SetBranchAddress("x",&x);
    ed_data->SetBranchAddress("y",&y);
    ed_data->SetBranchAddress("z",&z);

    // fill the histogram
    for(int irow=0;irow<ed_data->GetEntries();irow++){
    ed_data->GetEntry(irow);
    hrow->Fill(num_row);
    hcol->Fill(num_col);
    hx->Fill(x);
    hy->Fill(y);
    hz->Fill(z);    
    }
    
    // Draw the histogram
    TCanvas *c1 = new TCanvas("c1","",0,0,1024,1024);
    c1->Divide(2,2);
    
    c1->cd(1);
    hrow->Draw();
    c1->cd(2);
    hcol->Draw();
    c1->cd(3);
    hx->Draw();
    c1->cd(4);
    hy->Draw();
}
