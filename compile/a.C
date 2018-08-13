//Builds a graph with errors, displays it and saves it
//as image. First, include some header files (within, CINT these will be ignored).

#include "iostream"
#include "KMEvent.h"



void macro1(){
    //the values and the errors on the Y axis
    KMEvent * myevent = new KMEvent();
    std::cout << myevent->getx();
}

int main(){
    macro1();
    return 0;
}
