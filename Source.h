/*
 * Created by Steve Kostoff on 2019-04-11.
 *
 * This is the header for the Source class. Source generates events for the simulation and sends them to
 * the simulation executive. It is seasonally based, so requires four different statistical distributions for
 * generating seasonal temperature results. It will generate a number of events specified in its constructor.
 * Each events has a one hour duration.
*/

#pragma once

#include <string>
#include "Distribution.h"
#include "StateMachine.h"
#include "SimExec.h"
#include "Event.h"

class Source
{
public:
    Source(SimExec *exec, Triangular *winter, Triangular *spring, Triangular *summer, Triangular *fall, int numGen);
    /*
     * Source
     *  Parameters:
     *  SimExec *exec   Pointer to the simulation executive
     *  Triangular *winter (etc) Pointers to the statistical distributions governing seasonal temperatures
     *  int numGen      number of events to create
     */
    double generateTempValue();
    /*
     * generateTempValue
     *      Parameters: none
     *      Return Value: double
     *      Behavior:
     *          generates a temperature value according to the seasonal distribution
     */

private:
    SimExec *_exec; // holds the pointer to the simulation executive
    Triangular *_winter; // point to the winter distribution
    Triangular *_spring; // pointer to the spring distribution
    Triangular *_summer; // pointer ot the summer distribution
    Triangular *_fall; // pointer to the fall distribution
    int _numGen; // number of entities to create

    void CreateEvent();
    /*
     * CreateEvent
     *      Parameters: none
     *      Return value: none
     *      Behavior: Creates Events and sends them to the simulation executive
     */
};


