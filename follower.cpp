#include <iostream>
#include <cmath>

namespace AIcheck
{
    double pi = 3.1415926535;
}

namespace trg
{
   double x, y = 0;
}

using namespace AIcheck;


struct pos 
{
	double x, y, z = 0;
};

pos operator-(const pos & p1, const pos & p2) 
{
    pos p3;
    p3.x = p1.x-p2.x;
    p3.y = p1.y-p2.y;
    p3.z = p1.z-p2.z;
    return (p3);
}

struct AIobj
{
    pos pcur, ppast, prel, ptarg, reltarg;
    double speed, anglexy, anglez, calcspeed, anglechan, chanchan, deltangle, tangle, c = 0;
    int inputSteer, inputThrottle = 0;
    void calc_move ();
};

int setTarget(double a, double b)
{
    a = trg::x;
    b = trg::y;
    return (a, b);
}

void AIobj::calc_move ()
{
    setTarget(ptarg.x, ptarg.y);
    std::cout << "Target is currently " << ptarg.x << " " << ptarg.y << " " << std::endl;
    reltarg = ptarg - pcur;
    c = sqrt(pow(ptarg.x, 2)+pow(ptarg.y, 2));
    std::cout << "Relative distance between position and target is " << c << std::endl;
    tangle = ptarg.x / c;
    if (tangle-1<anglexy<tangle)
    {
        inputSteer = -1;
    }
    if (tangle+1>anglexy>tangle)
    {
        inputSteer = 1;
    }
    speed += 1-(abs(tangle-anglexy)/360) - abs(tangle-anglexy)/360;
    std::cout << "Target angle is " << tangle << std::endl;
    ppast = pcur; 
	while (anglexy >= 360)
	{
		anglexy -= 360; 
	}
	while (anglez >= 360)
	{
		anglez -= 360; 
	}
	std::cout << "Orientation is " << anglexy << std::endl;
	std::cout << "Pitch is " << anglez << std::endl; 
    pcur.x += cos(pi*anglexy / 180)*speed;
	pcur.y += sin(pi*anglexy / 180)*speed;
	pcur.z += sin(pi*anglez / 180)*speed; 
	prel.x = pcur.x - ppast.x;
	prel.y = pcur.y - ppast.y;
	prel.z = pcur.z - ppast.z;  
	calcspeed = cos(pi*anglexy / 180)*prel.x*cos(pi*anglez / 180) + sin(pi*anglexy / 180)*prel.y*cos(pi*anglez / 180) + sin(pi*anglexy / 180)*sin(pi*anglez / 180)*prel.z;
	std::cout << "One tick has passed. The current position is " << pcur.x << " " << pcur.y << " " << pcur.z << "." << std::endl;
	std::cout << "The movement was " << prel.x << " " << prel.y << " " << prel.z << "." << std::endl;
	std::cout << "This results in a calculated speed of " << calcspeed << " compared to the real speed value of " << speed << "." << std::endl; 
}

int selectTarget()
{
    std::cout << "Please select the X coordinate of target" << std::endl;
    std::cin >> trg::x;
    std::cout << "Please select the Y coordinate of target" << std::endl;
    std::cin >> trg::y;
    std::cout << "Target selected. Coordinates are " << trg::x << " " << trg::y << std::endl;
}


int main()
{
    int num, stat = 0;
    double inx, iny;
    AIobj P1;
    P1.speed = 0;
    
    for (int select = 1; select == 1; --select)
    {
    std::cout << "Please select your options:" << std::endl;
    std::cout << "1. Select target" << std::endl;
    std::cout << "2. Time pass" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cin >> stat;
    switch (stat)
    {
        case 1:
            selectTarget();
            ++select;
            break;
        case 2:
            P1.calc_move();
            ++select;
            break;
        case 3:
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            ++select;
            break;
    }
            
    }
  
return 0;
}
