/*
 * Created by Steve Kostoff on 2019-04-11
 *
 * This is the header for the Sink class.
 * Sink records all state changes, calculates and displays final simulation statistics.
*/

#pragma once

#include <iostream>
#include "Event.h"

class Sink
{
public:
    Sink();
    void Depart();
    /*
     * Depart
     * Parameters: none
     * Return value: none
     * Behavior: calculates statistics and prints them to console
     */
    int GetEntities();
    /*
     * Getters and setters
     * below are all the getters and setters for the sink values. Only GetCost is unique.
     */
    int GetHVACcooling();
    int GetHVACheating();
    int GetLighting();
    double GetCost();
    /*
     * GetCost
     * Parameters: none
     * Return value: double
     * Behavior: calculates total energy costs over the simulation run from all relevant state changes
     */
    void SetEntities();
    void SetHVACcooling();
    void SetHVACheating();
    void SetLighting();

private:
    int _totalEntitiesProcessed;
    int _HVACcoolingStateChanges;
    int _HVACheatingStateChanges;
    int _lightingStateChanges;
    double _totalCost;
    const double _heatingCostPerHour = 0.2594; //cost per hour of operation for home boiler
    const double _coolingCostPerHour = 0.62; // cost per hour of operation for home cooling
    const double _lightingCostPerHour = 0.09; //cost per hour of operation of home lights
};