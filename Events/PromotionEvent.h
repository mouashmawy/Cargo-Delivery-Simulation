#pragma once
#include "Event.h"
#include "../Company.h"

class PromotionEvent: public Event
{
private:
	double ExtraMoney; // Extra money for promotion
	Time ED;
	int ID_normal_cargo;

public:
	PromotionEvent(Company* AppMngr, Time* EventTime, int ID, double ExtraMoney) : Event(AppMngr, EventTime, ID), ExtraMoney(ExtraMoney) {};
	virtual void Execute();
};

