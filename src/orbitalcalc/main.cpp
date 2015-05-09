#include <stdio.h>
#include <iostream>

#include <zmq.hpp>
#include <armadillo>

#include "space/space.hpp"
#include "craft/craft.hpp"
#include "body/body.hpp"

int main(int argc, char** argv)
{
	space* spacesys = new space();

	arma::vec3 craftAPos = {6800000, 0, 0};
	arma::vec3 craftAVel = {0, 7700, 0};



	craft* craftA = new craft(craftAPos, craftAVel);

	body* bodyA = new body(0, 398600441800000);

	spacesys->addCraft(craftA);
	spacesys->addBody(bodyA);

	for(int i = 0; i < std::stoi(argv[1]); i++)
	{
		spacesys->simulate(0.1);
	}
	//std::cout << "Pos: " << craftA->getPos() << std::endl;
	//std::cout << "Vel: " << craftA->getVel() << std::endl;

	craftA->writeLog("testlog.csv");

	return 0;
}
