#ifndef EXAMPLE_MI_H
#define EXAMPLE_MI_H 1

#include <string>
using std::ostream;

// An interface class
class Example_mi_vbase {
public:
	Example_mi_vbase() = default;
	virtual ~Example_mi_vbase() {}

	virtual int id () const = 0;
};

// An interface class with more interfaces
class Example_mi_base1 : virtual public Example_mi_vbase {
public:
	Example_mi_base1() = default;
	virtual ~Example_mi_base1() {}

	virtual std::string name() const = 0;
	virtual void print(ostream &os) const = 0;
};

// A class supply the methods
class Example_mi_base2 : virtual public Example_mi_vbase {
public:
	Example_mi_base2() = default;
	virtual ~Example_mi_base2() {}
protected:
	virtual std::string get_name_from_id() const {
		return "Name_" + std::to_string(id());
	}
};

class Example_mi : public Example_mi_base1, private Example_mi_base2 {
public:
	Example_mi(int i = 0) : id_(i) { }
	
	int id() const { return id_; }
	std::string name() const { return get_name_from_id(); }
	void print(ostream &os) const {
		os << "Id: " << id() << '\n';
		os << "Name: " << name() << '\n';
	}
private:
	// redefine the name format
	std::string get_name_from_id() const final {
		return "[" + Example_mi_base2::get_name_from_id() + "]";
	}

	int id_;
};

#endif // EXAMPLE_MI_H
