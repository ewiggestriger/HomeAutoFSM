/*
 * Created by Steve Kostoff on 2019-04-11.
 * This is the header for Simulation Executive class.
 * It contains the data structure to contain events,
 * sort them, and run the simulation.
*/
//TODO add method for setting time limited run
#pragma once

#include <vector>
#include "Event.h"
#include "StateMachine.h"

class SimExec
{
public:
    SimExec(); // default constructor
    SimExec(HVACStateMachine *hvac, LightingStateMachine *lights);
    /*
     * SimExec
     * Parameters: point to HVAC state machine, pointer to lighting state machine
     * Return value: none
     * Behavior: constructs the simulation executive
     */
    ~SimExec(); // default destructor
    void AddEvent(Event *en);
    /*
     * AddEvent
     * Parameters: pointer to Event object
     * Return value: none
     * Behavior: adds a pointer to an Event to the event set
     */
    void RunSimulation(); // run simulation until event queue is exhausted
    int GetCurrentSimTime(); // not used
    void Sort();
    /*
     * Sort
     * Parameters: none
     * Return value: none
     * Behavior: sorts the event set vector from first to last according to lambda expression on simulation time of event
     */

private:
    HVACStateMachine *_hvac; // pointer to HVAC state machine
    LightingStateMachine *_lights; // pointer to lighting state machine
    int _currentTime; // current time of simulation
    std::vector<Event*> _eventSet; //event set for entire simulation
};