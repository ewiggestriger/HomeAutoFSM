/*
 * Created by Steve Kostoff on 2019-04-11.
 * This is the header for the Event class. Each event represents one hour's worth
 * of temperature and lighting information. It contains the relevant information as
 * well as code to execute when called upon by the simulation executive.
*/

#pragma once

class Event
{
public:
    Event(int t, double temp, bool d);
    /*
     * Event
     * Parameters: int t time of arrival
     *              double temp temperature value of event
     *              bool d      daylight value of event
     * Return value: none
     * Behavior: Event constructor.
     */
    int GetID();
    /*
     * GetID
     * Parameters: none
     * Return value: event ID number
     * Behavior: returns unique ID number of event
     */
    int getSimTime();
    /*
     * getSimTime
     * Parameters: none
     * Return value: integer sim time value
     * Behavior: returns sim time of event arrival
     */
    void Execute();
    /*
     * Execute
     * Parameters: none
     * Return value: none
     * Behavior: executes the code within the event, in this case print to console temperature and lighting values
     */
    void setTime(int t);
    /*
     * not used
     */
    double getTemp();
    /*
     * getTemp
     * Parameters: none
     * Return value: double temperature
     * Behavior: returns the event temperature value
     */
    bool getLight();
    /*
     * getLight
     * Parameters: none
     * Return value: boolean
     * Behavior: returns the boolean ambient daylight value
     */

private:
    int _id;  // id of the particular Event object
    static int _nextID;  //static counter to assign a unique ID to all entities created in the simulation
    int _time; // sim time value
    double _temperature; // event ambient temperature value
    bool _dayLight; // event ambient daylight value
};


