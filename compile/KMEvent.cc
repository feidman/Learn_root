//just for test 
#include "KMEvent.h"


KMEvent::KMEvent()
{
x=1;
y=2;
z=3;
};
double KMEvent::getx()
{
    KMHit * myhit = new KMHit();

    return myhit->geta()*x;
};
KMEvent::~KMEvent()
{
};

KMHit::KMHit()
{
	a=b=c=134;
};

int KMHit::geta()
{
	return a;
};
    
