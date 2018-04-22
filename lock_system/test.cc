#include <ariadne.h>
#include "lock_system.hh"
#include "analysis.hh" 
int main(int argc, char **argv)
{
    int verb = 0;
    if (argc > 1)
        verb = atoi(argv[1]);

    bool plot_results = true;

    HybridIOAutomaton system = Ariadne::getSystem(0.08,0.08,1.0,1.0,4.0);

    cout << system << endl;

    HybridBoundedConstraintSet initial_set(system.state_space());
    initial_set[DiscreteLocation("S0,a1_idle,a2_idle,on_first")] = Box(4, 1.0,1.0, 0.0,0.0, 0.0,0.0, 3.9,3.91);


    // initial_set[DiscreteLocation("S0,idle,two_falling")] = Box(3, 0.0,0.0, 2.5,3.5, 3.5,6.5);

    analyse(system, initial_set, verb, plot_results);
    return 0;
}