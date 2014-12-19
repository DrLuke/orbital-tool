#ifndef __BODY_HPP
#define __BODY_HPP

#include <armadillo>

class body
{
	public:
		body(int horizonsID = 0, double gravParam = 0.0);
		~body();

		// int horizonsID
		int getHorizonsID(){ return horizonsID; }
		void setHorizonsID(int newHorizonsID){ horizonsID = newHorizonsID; }

		// int ID
		int getID(){ return ID; }
		void setID(int newID){ ID = newID; }

		// double gravParam
		double getGravParam(){ return gravParam; }
		void setGravParam(double newGravParam){ gravParam = newGravParam; }

		// arma::vec3 pos
		arma::vec3 getPos(){ return pos; }
		void setPos(arma::vec3 newPos){ pos = newPos; }

		// double initJulianTime
		double getInitJulianTime(){ return initJulianTime; }
		void setInitJulianTime(double newInitJulianTime){ initJulianTime = newInitJulianTime; }

		// body* parentBody
		body* getParentBody(){ return parentBody; }
		void setParentBody(body* newParentBody){ parentBody = newParentBody; }


		// Methods
		void update(double timestep);	// Update position from Ephemeris data
		
		// Functions
		arma::vec3 calcForce(arma::vec3 craftPos);

	private:
		int horizonsID = 0;
		int ID = 0;
		double gravParam = 0.0;

		arma::vec3 pos = arma::zeros<arma::vec>(3);
		double initJulianTime = 0.0;
		
		body* parentBody = nullptr;

};

#endif
