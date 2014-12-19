#ifndef __JULIAN_HPP
#define __JULIAN_HPP

class julian
{
	public:
		julian(double setTime);
		~julian();

		// double julianTime
		double getJulianTime(){ return julianTime; }
		void setJulianTime(double newJulianTime){ julianTime = newJulianTime; }

		void setTimeFromUnix(int unixTime);
		void addSeconds(double secondsToAdd);
	
	private:
		double julianTime = 0.0;




};




#endif

