/*
 * Created by Steve Kostoff on 2019-04-28.
*/

#include "Source.h"
#include "Event.h"
#include <iostream>

using namespace std;

static int sequence = 0; // this value determines when the event happened relative to time of natural day/season

Source::Source(SimExec *exec, Triangular *winter, Triangular *spring, Triangular *summer, Triangular *fall, int numGen)
    {
        //initialize variables
        _exec = exec;
        _winter = winter;
        _spring = spring;
        _summer = summer;
        _fall = fall;
        _numGen = numGen;
        // create the temperature and lighting events
        this->CreateEvent();
    }

double Source::generateTempValue()
{
    //make sure sequence is never larger than 8760 (one year)
    if (sequence > 8760)
        sequence -= 8760;
    //check to see season and time of year the sim tick occurs in (one event executes per tick, tick=hour)
    if (sequence <= 2160)
    {
        //the event occurs in the winter
        if (sequence % 24 < 7 || sequence % 24 > 18) // night time
        {
            return (Source::_winter->GetRV() * 0.8);
        }
        else // day time
        {
            return (Source::_winter->GetRV() * 1.1);
        }
    }
    else if (sequence <= 4320)
    {
        //the event occurs in the spring
        if (sequence % 24 < 7 || sequence % 24 > 18) // night time
        {
            return (Source::_spring->GetRV() * 0.8);
        }
        else // day time
        {
            return (Source::_spring->GetRV() * 1.1);
        }
    }
    else if (sequence <= 6480)
    {
        //the event occurs in the summer
        if (sequence % 24 < 7 || sequence % 24 > 18) // night time
        {
            return (Source::_summer->GetRV() * 0.8);
        }
        else // day time
        {
            return (Source::_summer->GetRV() * 1.1);
        }
    }
    else if (sequence <= 8760)
    {
        //the event occurs in the fall
        if (sequence % 24 < 7 || sequence % 24 > 18) // night time
        {
            return (Source::_fall->GetRV() * 0.8);
        }
        else // day time
        {
            return (Source::_fall->GetRV() * 1.1);
        }
    }
}

bool generateLightValue()
{
    if (sequence % 24 < 7 || sequence % 24 > 18) // night time
    {
        return false;
    }
    else // day time
    {
        return true;
    }
}

void Source::CreateEvent()
{
    for (int i = 0; i < _numGen; ++i)
    {
        double newTemp = generateTempValue();
        bool newLight = generateLightValue();
        //increment sequence counter
        sequence++;
        Event *_ev = new Event(i, newTemp, newLight);
        _exec->AddEvent(_ev);
    }
}





