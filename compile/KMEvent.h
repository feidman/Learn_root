// just for test a self-def class 
//


class KMEvent  {

  private:
    double x,y,z; 
  public:
    // constructor and distructor
    KMEvent();
    virtual ~KMEvent();
    // Set Methods
    double getx();
 };

class KMHit {
	private:
	  int a,b,c;
	public:
	  KMHit();
	  virtual ~KMHit(){};
	  int geta();
};
