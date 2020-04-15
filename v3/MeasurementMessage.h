//==============================================================
// Filename : MeasurementMessage.h
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : MeasurementMessage class member function prototypes
//==============================================================

#pragma once

#include "Message.h"
class MeasurementMessage : public Message {
private:
	double m;
public:
	MeasurementMessage(int priority, const std::string &from, const std::string &topic, double m) : Message(priority, from, topic), m(m){};
	double getMeasurement();
	virtual std::string toString();
};

