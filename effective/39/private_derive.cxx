/**
 * The private derive just means 'is implementated in-terms-of'
 * Composition + public derive will also do this, think twice before decision.
 * c++ supplies final now!
 */

#include "example_pvtd.h"
#include "example_com_pubd.h"

int main(int, char **)
{
	// simple & perfect if final is availiable
	ExPvtd *p = new ExPvtd;	
	p->do_somthing();

	// complex & not easy to use
	ExComPubd *pp = new ExComPubd;
	pp->do_somthing();

	return 0;
}
