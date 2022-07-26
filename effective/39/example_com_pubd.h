#ifndef EXAMPLE_COM_PUBD_H
#define EXAMPLE_COM_PUBD_H 1

#include <iostream>

class ExComPubd_base {
public:
	ExComPubd_base() = default;
	virtual ~ExComPubd_base() {}

protected:
	virtual void f_() {
		std::cout << "Base: Do somthing." << std::endl;
	}
};

class ExComPubd {
private:
	class My_base : public ExComPubd_base {
	public:	
		void f() {
			f_();
		}
	private:	
		void f_() {
			std::cout << "Derived: Do some special thing." << std::endl;			
			ExComPubd_base::f_();
		}
	};

public:
	ExComPubd();
	~ExComPubd();
	// should disallow copy & move 	
	ExComPubd(const ExComPubd &) = delete;
	ExComPubd(ExComPubd &&) = delete;
	ExComPubd &operator=(const ExComPubd &) = delete;
	ExComPubd &operator=(ExComPubd &&) = delete;
	void do_somthing();

private:
	My_base *mbase_;
};

ExComPubd::ExComPubd() {
	mbase_ = new My_base;
}

ExComPubd::~ExComPubd() {
	delete mbase_;
}

void ExComPubd::do_somthing() {
	mbase_->f();
}

#endif // EXAMPLE_COM_PUBD_H
