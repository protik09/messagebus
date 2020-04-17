//==============================================================
// Filename : Nodes.h
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : Nodes class member function prototypes
//==============================================================

#pragma once

#include "Node.h"
#include "MessageBus.h"
#include "TextMessage.h"
#include "ImageMessage.h"
#include "MeasurementMessage.h"

class Nodes
{
private:
	void run();
public:
	MessageBus* bus;
	Nodes(MessageBus* bus) : bus(bus) {}
	void start();
};
