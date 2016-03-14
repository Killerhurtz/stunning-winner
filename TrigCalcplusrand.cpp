#include <iostream>
#include <cmath>
#include <math.h>

namespace trigcalc //Establishing the file's namespace.
{
	double 	pi = 3.1415926535;
}

using namespace trigcalc; //It's actually a better idea to use a custom namespace. That way you can use different namespaces without breaking anything when they update. Standard namespace is std::.

struct pos //Structure to establish a 3D space
{
	double x, y, z;
};

int main()
{
	double speed;
	pos pcur;
	pos ppast;
	pos prel; //Initializing my three required spacial coords using the aforementioned structure
	double anglexy = 0;
	double anglez = 0;
	double calcspeed;
	int select;
	int stat;
	select = 0;
	pcur.x = 0;
	pcur.y = 0;
	pcur.z = 0;
	speed = 0;
	std::cout << "Init done." << std::endl; //Verboose!

	for (int loopreset = 0; loopreset < 99; ++loopreset) //Decided to make an overarching failsafe this time.
	{
		for (int select = 0; select < 1; ++select) //Good ol' selection options.
		{
			std::cout << "Select your option:" << std::endl;
			std::cout << "1. Set speed" << std::endl;
			std::cout << "2. Change horizontal orientation" << std::endl;
			std::cout << "3. Change vertical angle" << std::endl;
			std::cout << "4. Pass time" << std::endl;
			std::cout << "5. Exit" << std::endl;
			std::cout << "6. Generate weapon" << std::endl;
			std::cin >> stat;

			switch (stat) //Switches, because I was told about them and it's prettier/simpler. DO NOT FORGET TO break; YOUR SHIT. Or else your shit will break. Ironic innit?
			{

			case 5:
					return 0; //The soft exit route. Better than exit(0)
					break;
			case 1:
					std::cout << "Input desired speed" << std::endl; 
					std::cin >> speed;
					std::cout << "Value accepted. Current speed is " << speed << std::endl;
					--select;
					break;
			case 2:
					std::cout << "Select desired angle" << std::endl;
					std::cin >> anglexy;
					std::cout << "Value accepted. Orientation is now " << anglexy << std::endl;
					--select;
					break;
			case 3:
					std::cout << "Select desired pitch" << std::endl;
					std::cin >> anglez;
					std::cout << "Value accepted. Pitch is now " << anglez << std::endl;
					--select;
					break;
			case 4:
					ppast.x = pcur.x;
					ppast.y = pcur.y;
					ppast.z = pcur.z; // As before, establishes a delta-distance, per dimension.
					while (anglexy >= 360)
					{
						anglexy -= 360; //Corrects the orientation if it's above 360, because you know, circles.
					}
					while (anglez >= 360)
					{
						anglez -= 360; // Same as above.
					}
					std::cout << "Orientation is " << anglexy << std::endl;
					std::cout << "Pitch is " << anglez << std::endl; // More verbose to make sure the angle correction went right...
					pcur.x += cos(pi*anglexy / 180)*speed;
					pcur.y += sin(pi*anglexy / 180)*speed;
					pcur.z += sin(pi*anglez / 180)*speed; //Calculates how much the unidentified "object" moved in each direction.
					prel.x = pcur.x - ppast.x;
					prel.y = pcur.y - ppast.y;
					prel.z = pcur.z - ppast.z; //Establishes the relative position in each dimension. 
					calcspeed = cos(pi*anglexy / 180)*prel.x*cos(pi*anglez / 180) + sin(pi*anglexy / 180)*prel.y*cos(pi*anglez / 180) + sin(pi*anglexy / 180)*sin(pi*anglez / 180)*prel.z; //Calculates the global speed of the object in relation to each angle. I'm proud of that one, it's accurate to 0.01%.
					std::cout << "One second has passed. The current position is " << pcur.x << " " << pcur.y << " " << pcur.z << "." << std::endl;
					std::cout << "The movement was " << prel.x << " " << prel.y << " " << prel.z << "." << std::endl;
					std::cout << "This results in a calculated speed of " << calcspeed << " compared to the real speed value of " << speed << "." << std::endl; //Then, in three lines, it tells me the values calculated.
					--select;
					break;
				case 6:
				    double possum = pcur.x + pcur.y + pcur.z; //Makes a sum of all positions for randomization purposes
				    int numsum = trunc(possum); //Truncate the possum so that you have an integer.
				    int weapval = (numsum % 14) + 1; //Have the number modulo 13 to have a value 0-13, then plus one to have 1-14. Vary the modulo to always have x+1 options.
				    switch (weapval)//SWITCHES ARE AWESOME
				    {
				        case 1:
				            std::cout << "You got Weapon 1" << std::endl;//Tells me what I got.
				            break;
				        case 2:
				            std::cout << "You got Weapon 2" << std::endl;
				            break;
				        case 3:
				            std::cout << "You got Weapon 3" << std::endl;
				            break;
				        case 4:
				            std::cout << "You got Weapon 4" << std::endl;
				            break;
				        case 5:
				            std::cout << "You got Weapon 5" << std::endl;
				            break;
				        case 6:
				            std::cout << "You got Weapon 6" << std::endl;
				            break;
				        case 7:
				            std::cout << "You got Weapon 7" << std::endl;
				            break;
				        case 8:
				            std::cout << "You got Weapon 8" << std::endl;
				            break;
				        case 9:
				            std::cout << "You got Weapon 9" << std::endl;
				            break;
				        case 10:
				            std::cout << "You got Weapon 10" << std::endl;
				            break;
				        case 11:
				            std::cout << "You got Weapon 11" << std::endl;
				            break;
				        case 12:
				            std::cout << "You got Weapon 12" << std::endl;
				            break;
				        case 13:
				            std::cout << "You got Weapon 13" << std::endl;
				            break;
				        case 14:
				            std::cout << "You got Weapon 14" << std::endl;
				            break;
				    }
				    
			}
		}
	}
return 0;
}
