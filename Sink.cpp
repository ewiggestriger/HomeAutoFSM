/*
 * Created by Steve Kostoff on 2019-04-28.
*/
#include "Sink.h"

using namespace std;

void Sink::Depart()
{
    cout << "Total entities processed: " << Sink::GetEntities() << endl;
    cout << "Total HVAC cooling state changes: " << Sink::GetHVACcooling() << endl;
    cout << "Total HVAC heating state changes: " << Sink::GetHVACheating() << endl;
    cout << "Total lighting system activations: " << Sink::GetLighting() << endl;
    cout << "Total energy cost: $" << Sink::GetCost() << endl;
}

double Sink::GetCost() // calculate cost of all state changes over course of sim
{
    double aggregrateCost = ((this->GetHVACheating() * _heatingCostPerHour) + (this->GetHVACcooling() * _coolingCostPerHour));
    aggregrateCost += (this->GetLighting() * _lightingCostPerHour);
    Sink::_totalCost = aggregrateCost;
    return Sink::_totalCost;
}

int Sink::GetEntities()
{
    return Sink::_totalEntitiesProcessed;
}

int Sink::GetHVACcooling()
{
    return Sink::_HVACcoolingStateChanges;
}

int Sink::GetHVACheating()
{
    return Sink::_HVACheatingStateChanges;
}

int Sink::GetLighting()
{
    return Sink::_lightingStateChanges;
}

void Sink::SetEntities()
{
    _totalEntitiesProcessed += 1;
}

void Sink::SetHVACcooling()
{
    _HVACcoolingStateChanges += 1;
}

void Sink::SetHVACheating()
{
    _HVACheatingStateChanges += 1;
}

void Sink::SetLighting()
{
    _lightingStateChanges += 1;
}

Sink::Sink()
{
    //initialize all variables to zero
    _totalEntitiesProcessed = 0;
    _HVACcoolingStateChanges = 0;
    _HVACheatingStateChanges = 0;
    _lightingStateChanges = 0;
    _totalCost = 0;
}


