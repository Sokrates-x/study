#include "example_tpm.h"
#include "example_stgy.h"
#include "example_fobj.h"
#include "strategy.h"
#include "example_cstgy.h"

int main(int, char **)
{
	// The Template Method
	Example_tpm_base *pb_tpm = new Example_tpm_base;
	Example_tpm_base *pd_tpm = new Example_tpm;
	pb_tpm->do_somthing();
	pd_tpm->do_somthing();

	// The Strategy by functions
	Example_stgy_base *pb_stgy = new Example_stgy_base;	
	Example_stgy_base *pd_stgy1 = new Example_stgy(f1);
	Example_stgy_base *pd_stgy2 = new Example_stgy(f2);
	Example_stgy_base *pd_stgy3 = new Example_stgy(f3);
	pb_stgy->do_somthing();
	pd_stgy1->do_somthing();
	pd_stgy2->do_somthing();
	pd_stgy3->do_somthing();

	// Strategy with std::funciton
	Example_fobj_base *pb_fobj = new Example_fobj_base;
	Example_fobj_base *pd_fobj1 = new Example_fobj(fobj1);
	Example_fobj_base *pd_fobj2 = new Example_fobj(fobj2);
	Example_fobj_base *pd_fobj3 = new Example_fobj(fobj3);
	Example_fobj_base *pd_fobj4 = new Example_fobj(fobj4);
	pb_fobj->do_somthing();	
	pd_fobj1->do_somthing();	
	pd_fobj2->do_somthing();	
	pd_fobj3->do_somthing();	
	pd_fobj4->do_somthing();	

	// Classic Strategy
	StrategyA sa;
	StrategyB sb;
	StrategyC sc;
	Example_cstgy_base *pb_cstgy = new Example_cstgy_base(sa);
	Example_cstgy_base *pd_cstgy1 = new Example_cstgy(sa);
	Example_cstgy_base *pd_cstgy2 = new Example_cstgy(sb);
	Example_cstgy_base *pd_cstgy3 = new Example_cstgy(sc);
	pb_cstgy->do_somthing();
	pd_cstgy1->do_somthing();
	pd_cstgy2->do_somthing();
	pd_cstgy3->do_somthing();

	return 0;
}
