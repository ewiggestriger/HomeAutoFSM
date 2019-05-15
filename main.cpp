/*
 * This is the main method. It runs the simulation for one year and outputs results.
 */

#include <iostream>
#include <string>
#include <fstream>
#include "StateMachine.h"
#include "Source.h"
#include "Distribution.h"

using namespace std;

int main()
{
    ofstream output; //file object
    output.open("FSMoutput.csv");
    int numGen = 8760; // this is one year's worth of events
    Triangular *winter = new Triangular(30, 40, 50);
    Triangular *spring = new Triangular(55, 67, 80);
    Triangular *summer = new Triangular(67, 85, 90);
    Triangular *fall = new Triangular(40, 55, 60);
    Sink *sink = new Sink();
    HVACStateMachine *hvac = new HVACStateMachine(sink);
    LightingStateMachine *lights = new LightingStateMachine(sink);
    SimExec *eventManager = new SimExec(hvac, lights);
    Source source(eventManager, winter, spring, summer, fall, numGen);


    eventManager->RunSimulation();
    sink->Depart();
    //write data to output file for analysis
    output << "Number of events processed,Total Heating State Changes,Total Cooling State Changes,Total Lighting State Changes,Total Annual Cost\n";
    output << sink->GetEntities() << "," << sink->GetHVACheating() << "," << sink->GetHVACcooling() << "," << sink->GetLighting() << "," << sink->GetCost() << endl;
    output.close();
    return 0;
}