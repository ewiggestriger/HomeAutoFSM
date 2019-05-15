/*
 * Created by Steve Kostoff on 2019-04-12.
*/

#include "Event.h"
#include "Source.h"
#include "StateMachine.h"

using namespace std;

int Event::_nextID = 0;

Event::Event(int t, double temp, bool d)
{
    //assign the unique id to the entity and increment the ID counter
    _id = _nextID++;
    //assign values to private variables
    _time = t;
    _temperature = temp;
    _dayLight = d;
}

void Event::Execute() // print event data to console when it is time to execute
{
    cout << "Temperature is: " << this->getTemp() << " at time " << this->getSimTime() << endl;
    cout << "Daylight is: " << this->getLight() << " at time " << this->getSimTime() << endl;
}

int Event::GetID()
{
    return _id;
}

int Event::getSimTime()
{
    return _time;
}

void Event::setTime(int t)
{
    _time = t;
}


double Event::getTemp()
{
    return _temperature;
}

bool Event::getLight()
{
    return _dayLight;
}



