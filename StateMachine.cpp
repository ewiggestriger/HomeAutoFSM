/*
 * Created by Steve Kostoff on 2019-04-28.
*/

#include "StateMachine.h"

using namespace std;

HVACStateMachine::HVACStateMachine(Sink *sink)
{
    _sink = sink;
    _currentState = idle; //initialize HVAC system to idle
};

void HVACStateMachine::checkState(double temp)
{
    //determine which state to set the system in based on thresholds
    //state change and time must be reported out to sink
    _sink->SetEntities();
    if (temp >= _idle2cool) {
        _currentState = cooling;
        _sink->SetHVACcooling();
    }
    else if (temp <= _idle2hot) {
        _currentState = heating;
        _sink->SetHVACheating();
    }
    else
        _currentState = idle;
}

string HVACStateMachine::getSystemState()
{
    switch (_currentState)
    {
        case idle:
            return "Idle";
        case heating:
            return "Heating";
        case cooling:
            return "Cooling";
    }
}

LightingStateMachine::LightingStateMachine(Sink *sink)
{
    _sink = sink;
    _currentState = dark; //initialize lighting system to dark (off)
};

void LightingStateMachine::checkState(bool l)
{
    //determine which state to set the system in based on thresholds
    //state change and time must be reported out to sink
    _currentState = l;
    if (l)
        _sink->SetLighting();
}

string LightingStateMachine::getSystemState()
{
    switch (_currentState)
    {
        case dark:
            return "Interior lights off.";
        case light:
            return "Interior lights on.";
    }
}