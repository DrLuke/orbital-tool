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
	craftLog* tempLog = new craftLog(pos, vel, timestep);
	log.push_back(tempLog);
}

void craft::applyUnitForce(arma::vec3 force)
{
	vel += force*timestep;
}



craftLog::craftLog(arma::vec3 logPos, arma::vec3 logVel, double logTimestep) : pos(logPos), vel(logVel), timestep(logTimestep)
{
}

craftLog::~craftLog()
{
}
