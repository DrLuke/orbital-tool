#ifndef __SPACE_HPP
#define __SPACE_HPP

#include <armadillo>
#include <list>

#include "craft.hpp"
#include "body.hpp"
#include "julian.hpp"

class space
{
	public:
		space();
		~space();
	
		// Getters and Setter for Crafts and Bodies
		std::list<craft*>* getCrafts(){ return &crafts; }
		void addCraft(craft* toAdd);

		std::list<body*>* getBodies(){ return &bodies; }
		void addBody(body* toAdd);

		// Methods
		void simulate(double timestep);
		
	
	private:
		std::list<craft*> crafts;
		std::list<body*> bodies;

		julian time = julian(2451544.5);	// Default time is the year 2000.0
		

};






#endif
