#ifndef __CRAFT_HPP
#define __CRAFT_HPP

#include <armadillo>
#include <vector>

class craftLog
{
	public:
		craftLog();
		~craftLog();

		arma::vec3 pos;
		arma::vec3 vel;
		double timestep;


};

class craft
{
	public:
		craft(	arma::vec3 ainitPos = arma::zeros<arma::vec>(3),
			arma::vec3 ainitVel = arma::zeros<arma::vec>(3)
			);
		~craft();

		// Setter and Getters
		// arma::vec3 pos	
		arma::vec3 getPos(){ return pos; }
		void setPos(arma::vec3 newPos){ pos = newPos; }

		// arma::vec3 vel
		arma::vec3 getVel(){ return vel; }
		void setVel(arma::vec3 newVel){ vel = newVel; }

		// arma::vec3 initPos
		arma::vec3 getInitPos(){ return initPos; }
		void setInitPos(arma::vec3 newInitPos){ initPos = newInitPos; }

		// arma::vec3 initVel
		arma::vec3 getInitVel(){ return initVel; }
		void setInitVel(arma::vec3 newInitVel){ initVel = newInitVel; }
		
		// std::string name
		std::string getName(){ return name; }
		void setName(std::string newName){ name = newName; }

		// double timestep
		double getTimestep(){ return timestep; }
		void setTimestep(double newTimestep){ timestep = newTimestep; }

		// Methods
		void update();	// Reset to initial conditions
		void logData();
		
		// Functions
		void applyUnitForce(arma::vec3 force);	// Apply a force with the unit Newton/Kg
	
	private:
		arma::vec3 pos = arma::zeros<arma::vec>(3);
		arma::vec3 vel = arma::zeros<arma::vec>(3);

		arma::vec3 initPos = arma::zeros<arma::vec>(3);
		arma::vec3 initVel = arma::zeros<arma::vec>(3);

		std::string name;
		double timestep;

		std::vector<logData*> log;
};

#endif
