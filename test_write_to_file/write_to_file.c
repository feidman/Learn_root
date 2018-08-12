#include "TH1F.h"
#include "TFile.h"

void write_to_file(){

    // Let's open a TFile
    TFile out_file("my_rootfile.root","RECREATE");

    // Instance of our histogram
    TH1F h("my_histogram","My Title;X; # of entries",100,-5,5);

    // Let's fill it randomly
    h.FillRandom("gaus");



    // Write the histogram in the file
    out_file.Write();
    // Close the file
    out_file.Close();
}

