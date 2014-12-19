#include "julian.hpp"

julian::julian(double setTime) : julianTime(setTime)
{

}

julian::~julian()
{

}

void julian::setTimeFromUnix(int unixTime)
{
	julianTime = ((double)unixTime / 86400.0) + 2440587.5;	
}

void julian::addSeconds(double secondsToAdd)
{
	julianTime += secondsToAdd / 86400.0;
}
