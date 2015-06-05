#ifndef  GRID_QCD_MOBIUS_FERMION_H
#define  GRID_QCD_MOBIUS_FERMION_H

#include <Grid.h>

namespace Grid {

  namespace QCD {

    class MobiusFermion : public CayleyFermion5D
    {
    public:

      virtual void   Instantiatable(void) {};
      // Constructors
      MobiusFermion(LatticeGaugeField &_Umu,
		    GridCartesian         &FiveDimGrid,
		    GridRedBlackCartesian &FiveDimRedBlackGrid,
		    GridCartesian         &FourDimGrid,
		    GridRedBlackCartesian &FourDimRedBlackGrid,
		    RealD _mass,RealD _M5,
		    RealD b, RealD c) : 
      
      CayleyFermion5D(_Umu,
		      FiveDimGrid,
		      FiveDimRedBlackGrid,
		      FourDimGrid,
		      FourDimRedBlackGrid,_mass,_M5)

      {
	RealD eps = 1.0;

	std::cout << "MobiusFermion (b="<<b<<",c="<<c<<") with Ls= "<<Ls<<" Tanh approx"<<std::endl;
	Approx::zolotarev_data *zdata = Approx::higham(eps,this->Ls);// eps is ignored for higham
	assert(zdata->n==this->Ls);
	
	// Call base setter
	this->CayleyFermion5D::SetCoefficientsTanh(zdata,b,c);

	Approx::zolotarev_free(zdata);
 
      }

    };

  }
}

#endif