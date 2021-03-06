#pragma once
#include <ariadne.h>

namespace hydropower
{
HybridIOAutomaton getSystem(
	RealVariable 		a, 
	RealVariable 		b, 
	RealVariable 		l, 
	RealVariable 		p, 
	RealParameter 		alpha, 
	RealParameter 		beta, 
	RealParameter 		psi, 
	RealParameter 		gamma, 
	RealParameter 		epsilon, 
	DiscreteLocation 	flow)
{
   // Automaton registration
	HybridIOAutomaton system("hydropower");

	//Registration of variables
	system.add_input_var(a);
	system.add_input_var(b);
	system.add_output_var(l);
	system.add_output_var(p);

	//Registration of events
	//NO events

	//Registration of locations
	system.new_mode(flow);


	//Registration of dynamics
	system.set_dynamics(flow, l, -alpha * a * l + epsilon);
	system.set_dynamics(flow, p, alpha * psi * a - beta * b);

    return system;
}
}
namespace city
{
HybridIOAutomaton getSystem(
	RealVariable 		b,
	RealVariable	 	time,
	DiscreteLocation 	day,
	DiscreteLocation 	night,
	DiscreteEvent 		consuming,
	DiscreteEvent 		saving,
	RealParameter 		midday_v)
{
   	///Automaton registration
	HybridIOAutomaton city("city");
	///Resets
	std::map<RealVariable, RealExpression> reset;
	std::map<RealVariable, RealExpression> reset_0;
	///Guards
	RealExpression midday = time - midday_v; //!< w>=treshold
	RealExpression midnight = time - (2.0 * midday_v);

	//Registration of variables
	city.add_output_var(b);
	city.add_output_var(time);

	city.add_output_event(saving);
	city.add_output_event(consuming);

	//Registration of locations
	city.new_mode(day);
	city.new_mode(night);

	RealParameter c("c",10.0);

	//Registration of dynamics
	city.set_dynamics(day, b, 1.0*c);
	city.set_dynamics(night,b,-1.0*c);
	city.set_dynamics(day,time,1.0);
	city.set_dynamics(night,time,1.0);

	reset[b] = b;
	reset[time] = time;

	reset_0[b] = b;
	reset_0[time] = 0.0;


    city.new_forced_transition(saving, night, day, reset_0, midnight);
    city.new_forced_transition(consuming, day, night, reset, midday);


    return city;
}	
}