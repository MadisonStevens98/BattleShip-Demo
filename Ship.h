#pragma once
#ifndef SHIP
#define SHIP

using namespace std;

class Ship {

public:
	void BoardPlace(int, char, char[10][10]);
	int spaces;
	char place;
};

#endif 