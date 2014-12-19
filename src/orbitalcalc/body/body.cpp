#include "body.hpp"

body::body(int horizonsID, double gravParam) : horizonsID(horizonsID), gravParam(gravParam)
{

}

body::~body()
{

}

void body::update(double timestep)
{
	//TODO: Implement update and interpolation of ephemeris data
}

/* Calculate the force per unit of mass a craft would experience from this body at a certain position
 *
 */
arma::vec3 body::calcForce(arma::vec3 craftPos)
{
	arma::vec3 relpos = craftPos - pos;
	double relposLen = arma::norm(relpos);
	arma::vec3 force = -(gravParam/(relposLen*relposLen)) * arma::normalise(relpos);

	return force;
}
