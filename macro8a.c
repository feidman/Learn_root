int macro8a(){

TF1 parabola("parabola", "[0]+[1]*x+[2]*x**2",0,20);
parabola.SetParameters(1,1,1);

//gaussian.Draw();
TCanvas * c1 = new TCanvas();
parabola.Draw();
//gausppar.Draw();
}
