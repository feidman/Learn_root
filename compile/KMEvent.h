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
    void Setxyz(double x_value, double y_value, double z_value)
    { x=x_value; y=y_value;z=z_value; } ; 

    // Get Methods
    double getx()      { return x; } ;
 };