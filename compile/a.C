//Builds a graph with errors, displays it and saves it
//as image. First, include some header files (within, CINT these will be ignored).

#include "iostream"
#include "KMEvent.h"

using namespace std;

void macro1(){
    //the values and the errors on the Y axis
    KMEvent * myevent = new KMEvent();
    KMHit * myhit = new KMHit();
    cout<<"Here is the x_value:"<<myevent->getx()<<endl;
}

int main(){
    macro1();
    return 0;
}
