//============================================================================
// Name        : cpp-template-ex.cpp
// Author      : Henryk Paluch
// Version     :
// Copyright   : Copyright (C) Henryk Paluch
// Description : Example to (mis)use Macro and template
//============================================================================

#include <iostream>
using namespace std;

#define MY_DEBUG(msg) cout << __FILE__ << ":" << __LINE__ << " " << __PRETTY_FUNCTION__ << " " << (msg) <<  endl

#define MY_MAX(x,y) ( (x) > (y) ? (x) : (y) )

static void maxAsMacro()
{
	int x=1,y=5;
	double e=2.78,pi=3.14;
	int m=1,n=0;
	MY_DEBUG("Entering");

	// proper use of macro
	cout << "MACRO Max of " << x << " and " << y << " is " << MY_MAX(x,y) << endl;
	cout << "MACRO Max of " << pi << " and " << e << " is " << MY_MAX(pi,e) << endl;

	// unexpected side effects!
	cout << "m before macro: " << m << endl;
	// gcc is clever enough to warn you (about 'm' and 'm++' in single expression) with:
	// warning: operation on ‘m’ may be undefined [-Wsequence-point]
	cout << "MACRO Max of m++ " << m << " and " << n << " is " << MY_MAX(m++,n) << endl;
	// above produces: MACRO Max of m++ 3 and 0 is 2 (WRONG!)

	// above are two problems:
	// a) double increment of m (instead of single)
	// b) the m value in cout is already 3 (expressions are evaluated prior << operators) !!!

	// avoid problem b) (but problem a) remains)
	m=1,n=0;
	cout << "MACRO Max of m++ " << m << " and " << n << " is ";
	cout << MY_MAX(m++,n) << endl;
	// above produces: MACRO Max of m++ 1 and 0 is 2 (WRONG!)

	MY_DEBUG("Exiting");
}

template<typename T>
T myMax(T x, T y)
{
		return ( x > y ? x : y);
};

static void maxAsTemplate()
{
	int x=1,y=5;
	double e=2.78,pi=3.14;
	int m=1,n=0;
	MY_DEBUG("Entering");

	// proper use of template
	cout << "Template Max of " << x << " and " << y << " is " << myMax(x,y) << endl;
	cout << "Template Max of " << pi << " and " << e << " is " << myMax(pi,e) << endl;

	// unexpected side effect!
	cout << "m before Template: " << m << endl;
	// gcc is clever enough to warn you (about 'm' and 'm++' in single expression) with:
	// warning: operation on ‘m’ may be undefined [-Wsequence-point]
	cout << "Template Max of m++ " << m << " and " << n << " is " << myMax(m++,n) << endl;
	// avoid produces: Template Max of m++ 2 and 0 is 1 (WRONG!)

	// only ordering problem remains:
	// a) the m value in cout is already 2 (expressions are evaluated prior << operators) !!!

	// solving ordering problem
	m=1,n=0;
	// force evaluation of cout and ++ separately
	cout << "Template Max of m++ " << m << " and " << n << " is ";
	cout << myMax(m++,n) << endl;
	// above produces: Template Max of m++ 1 and 0 is 1

	MY_DEBUG("Exiting");
}

/*
 * Conclusions:
 * 1. never use modifying operators (ex. ++/--) in macros
 * 2. never use same variable with ++/-- more than once in expression
 *    (ex. don't use 'x' and 'x++' in single command simultaneously).
 *
 */

int main() {
	maxAsMacro();
	maxAsTemplate();
	return 0;
}
