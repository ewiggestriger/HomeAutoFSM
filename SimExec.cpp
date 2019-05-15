/*
 * Created by Steve Kostoff on 2019-04-11.
*/

#include <vector> // for the event set
#include <algorithm> // for sorting functions
#include "SimExec.h"
#include "Event.h"

using namespace std;

SimExec::SimExec() {}

SimExec::SimExec(HVACStateMachine *hvac, LightingStateMachine *lights)
{
    _hvac = hvac;
    _lights = lights;
}

SimExec::~SimExec() {}

//vector methods are add event and sort
void SimExec::AddEvent(Event *en)
{
    SimExec::_eventSet.push_back(en);
}

//since we are using a vector containing objects, sorting by lambda expression is necessary
void SimExec::Sort()
{
   std::sort(SimExec::_eventSet.begin(), SimExec::_eventSet.end(), [] (const auto& lhs, const auto& rhs)
   {
       return lhs->getSimTime() > rhs->getSimTime();
   });
}

int SimExec::GetCurrentSimTime()
{
    return SimExec::_currentTime;
}

void SimExec::RunSimulation()
{
    //sort events before running simulation
    SimExec::Sort();
    while (!(SimExec::_eventSet.empty()))
    {
        //set simulation clock to event time
        SimExec::_currentTime = SimExec::_eventSet.back()->getSimTime();
        //execute the event code
        SimExec::_eventSet.back()->Execute();
        //send state change input to the finite state machines
        SimExec::_hvac->checkState(SimExec::_eventSet.back()->getTemp());
        SimExec::_lights->checkState(SimExec::_eventSet.back()->getLight());
        //remove event from event set
        SimExec::_eventSet.pop_back();
    }
}