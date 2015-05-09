#include "space.hpp"

space::space()
{

}

space::~space()
{

}

void space::addCraft(craft* toAdd)
{
	crafts.push_back(toAdd);
}

void space::addBody(body* toAdd)
{
	bodies.push_back(toAdd);
}

void space::simulate(double timestep)
{
	// Iterate through all bodies and update them
	for(std::list<body*>::iterator itb = bodies.begin(); itb != bodies.end(); itb++)
	{
		(*itb)->update(timestep);
	}

	// Iterate through all crafts and apply forces from bodies to them
	for(std::list<craft*>::iterator itc = crafts.begin(); itc != crafts.end(); itc++)
	{
		(*itc)->setTimestep(timestep);	// Update the timestep on each craft
		for(std::list<body*>::iterator itb = bodies.begin(); itb != bodies.end(); itb++)
		{
			(*itc)->applyUnitForce( (*itb)->calcForce( (*itc)->getPos() ) ); // Apply forces from each body to craft
		}
		(*itc)->update();	// After all forces have been added, update position of craft
	}
}
