#ifndef EXAMPLE_TPM
#define EXAMPLE_TPM 1

/** 
 *  When use this method you can do some invariat thing in the base class.
 *  However the private virtuals can not be used for derived classes. 
 *  Private virtuals can be protected or even public.
 *  Actually, the virtuals are needed for the non-virtual implements.
*/

class Example_tpm_base {
public:
	Example_tpm_base() = default;
	// always keep dtor virtual 
	virtual ~Example_tpm_base() {}

	// classical template method
	void do_somthing();

private:
	virtual void do_step1();
	virtual void do_step2();
	virtual void do_step3();
};

class Example_tpm : public Example_tpm_base {
public:
	// never redefine do_something() because it's non-virtual
private:	
	void do_step1(); 	
	// do default step2 
	void do_step3();
};

#endif // EXAMPLE_TPM
