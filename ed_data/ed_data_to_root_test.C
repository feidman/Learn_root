// read ed data from file and write them to root file
// data was stored in TTree structure

void ed_data_to_root_test(){
    // read coords from data file
    fstream fdata("ED_coord_test.data",ios::in);
    if(!fdata){
	cout<<"File open error!\n";
	return;
    }
    
    TTree ed_data("ed_data_test","Coordinates of ED X and Y");
    int num_row=0,num_col=0;
    float x=0,y=0,z=0;
    // link the vars with TTree branches
    ed_data.Branch("num_row",&num_row,"num_row/I");
    ed_data.Branch("num_col",&num_col,"num_col/I");
    ed_data.Branch("x",&x,"x/F");
    ed_data.Branch("y",&y,"y/F");
    ed_data.Branch("z",&z,"z/F");
    // Read the data from file and fill them to the TTree
    while(!fdata.eof()){
	fdata>>num_row>>num_col>>x>>y;
	ed_data.Fill();
	// test the data was read correctly
  	cout<<num_row<<" "<<num_col<<" "<<x<<" "<<y<<" "<<z<<endl;
    }

    TFile ed_ofile("ed_data_test.root","RECREATE");
    // write to root file
    ed_data.Write();
    // close two files 
    fdata.close();
    ed_ofile.Close();
}


