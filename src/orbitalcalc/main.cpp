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

	arma::vec3 craftAPos = {6000, 0, 0};
	arma::vec3 craftAVel = {0, 2000, 5};



	craft* craftA = new craft(craftAPos, craftAVel);

	body* bodyA = new body(0, 400000);

	spacesys->addCraft(craftA);
	spacesys->addBody(bodyA);

	for(int i = 0; i < std::stoi(argv[1]); i++)
	{
		spacesys->simulate(0.01);
	}
	std::cout << "Pos: " << craftA->getPos() << std::endl;
	std::cout << "Vel: " << craftA->getVel() << std::endl;

	return 0;
}
