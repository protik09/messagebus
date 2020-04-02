#pragma once
#include "Message.h"
class MeasurementMessage : public Message {
private:
	double m;
public:
	MeasurementMessage(int priority, const std::string& from, const std::string& topic, double m) : ... , m(m) {};
	double getMeasurement();
	virtual std::string toString();
};

