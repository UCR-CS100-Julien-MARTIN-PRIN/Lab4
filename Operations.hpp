#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

#include "base.hpp"

using namespace std;

class Op : public Base
{
	private:
	       	double value;

	public:
		Op(double value_)
		{
			this->value=value_;
		};
			
		virtual double evaluate() { return value;};
		virtual string stringify() { return (to_string(value));};
};



class Rand : public Base
{
	private:
		double value;

	public:
		Rand ()
		{
			value = rand()%100;
		};

		virtual double evaluate() {return value;};
		virtual string stringify() {return (to_string(value));};
};



class Mult : public Base
{
	private:
		Base* a;
		Base* b;

	public:
		Mult(double a_, double b_)
		{
			a= new Op(a_);
			b= new Op (b_);
		};
		
		virtual double evaluate() {return (a->evaluate() * b->evaluate());};
		virtual string stringify() {return (to_string(a->evaluate()) + " * " + to_string(b->evaluate()));};
};



class Div : public Base
{
	private:
		Base* a;
		Base* b;

	public:
		/* Constructors */
		Div(double a_, double b_)
		{
			a=new Op(a_);
			b=new Op(b_);
		};
	
		virtual double evaluate() {return (a->evaluate() / b->evaluate());};
		virtual string stringify() {return (to_string(a->evaluate()) + " / " + to_string(b->evaluate()));};
};



class Add : public Base
{
	private:
		Base* a;
		Base* b;

	public:
		/* Constructors */
		Add(double a_, double b_)
		{
			a= new Op(a_);
			b= new  Op(b_);
		};

		virtual double evaluate() {return (a->evaluate() + b->evaluate());};
		virtual string stringify() {return (to_string(a->evaluate()) + " + " + to_string(b->evaluate()));};
};



class Sub : public Base
{
	private:
		Base* a;
		Base* b;

	public:
		/* Constructors */
		Sub(double a_, double b_)
		{
			a= new Op (a_);
			b= new Op (b_);
		};

		virtual double evaluate() {return (a->evaluate() - b->evaluate());};
		virtual string stringify() {return (to_string(a->evaluate()) + " - " + to_string(b->evaluate()));};
};



class Pow : public Base
{
	private:
		Base* a;
		Base* p;

	public:
		/* Constructors */
		Pow(double a_, double power)
		{
			a= new Op(a_);
			p= new Op(power);
		};

		virtual double evaluate() {double  x = a-> evaluate();
			double y = p->evaluate();
			for(int i=0; i<y;i++)
			{
				x*= x;
			};
			return x;
		};
		virtual string stringify() { return (to_string(a->evaluate()) + " ** " + to_string(p->evaluate()));};
};
