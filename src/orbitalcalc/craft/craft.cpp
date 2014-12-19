#include "craft.hpp"

craft::craft(arma::vec3 ainitPos, arma::vec3 ainitVel) : initPos(ainitPos), initVel(ainitVel)
{
	pos = initPos;
	vel = initVel;

}

craft::~craft()
{
	
}

void craft::update()
{
	pos += vel * timestep;
	logData();
}

void craft::logData()
{
	
}

void craft::applyUnitForce(arma::vec3 force)
{
	vel += force*timestep;
}



