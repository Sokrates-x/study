#ifndef STRATEGY_H
#define STRATEGY_H 1

/**
 * not real NVI. Just move the virtuals to the strategy classes.
 */

class Strategy {
public:
	Strategy() = default;
	virtual ~Strategy() {}

	// pure virtual
	virtual void exec() = 0;
};

class StrategyA : public Strategy {
public:
	void exec();
};

class StrategyB : public Strategy {
public:
	void exec();
};

class StrategyC : public Strategy {
public:
	void exec();
};

#endif // STRATEGY_H
