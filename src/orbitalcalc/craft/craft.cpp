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
	//std::cout << "\nForce:\n" << force << "Timestep: " << timestep << "\nNew Vel:\n" << vel << std::endl << std::endl;

}

void craft::writeLog(std::string filename)
{
	std::ofstream logfile;
	logfile.open(filename, std::ofstream::out | std::ofstream::trunc);

	logfile << "X;Y;Z;vX;vY;vZ;Timestep\n";

	for(std::vector<craftLog*>::iterator it = log.begin(); it != log.end(); it++)
	{
		logfile << (*it)->pos[0] << ";" << (*it)->pos[1] << ";" << (*it)->pos[2] << ";" 
			<< (*it)->vel[0] << ";" << (*it)->vel[1] << ";" << (*it)->vel[2] << ";"
			<< (*it)->timestep << "\n";
	}
	logfile.close();
}

craftLog::craftLog(arma::vec3 logPos, arma::vec3 logVel, double logTimestep) : pos(logPos), vel(logVel), timestep(logTimestep)
{
}

craftLog::~craftLog()
{
}
