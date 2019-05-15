/*
 * Created by Steve Kostoff on 2019-04-11.
 *
 * This is the header for the finite state machine classes.
 * HVACStateMachine and LightingStateMachine are the two
 * state machines that comprise the simulation. They receive
 * input from the simulation executive and change state
 * as required.
 *
*/

#pragma once

#include <iostream>
#include <string>
#include "Sink.h"

//these are the states: heating, cooling, idle; lights on, lights off.

class HVACStateMachine
{
public:
    HVACStateMachine(Sink *sink);
    /*
     * HVACStateMachine
     * Parameters: pointer to Sink object
     * Return value: none
     * Behavior: builds a HVAC state machine
     */
    void checkState(double temp);
    /*
     * checkState
     * Parameters: double temperature value
     * Return value: none
     * Behavior: checks event temperature input and changes state as necessary, then reports to sink
     */
    std::string getSystemState(); // not used

private:
    enum HVACStates {idle, heating, cooling}; //enum to specify the different states
    //current state variable
    int _currentState;
    //threshold values to trigger HVAC state changes
    const double _idle2hot = 68.0; // threshold to turn on heating system
    const double _idle2cool = 80.0; // threshold to turn on cooling system
    //sink pointer
    Sink *_sink;
};

class LightingStateMachine
{
public:
    LightingStateMachine(Sink *sink);
    /*
     * LightingStateMachine
     * Parameters: pointer to Sink object
     * Return value: none
     * Behavior: builds a lighting state machine
     */
    void checkState(bool l);
    /*
     * checkState
     * Parameters: boolean ambient light value
     * Return value: none
     * Behavior: checks event ambient light input and changes state as necessary, then reports to sink
     */
    std::string getSystemState(); // not used
private:
    enum AmbientLight {dark, light}; // enum to specify the different states
    int _currentState;
    //sink pointer
    Sink *_sink;
};