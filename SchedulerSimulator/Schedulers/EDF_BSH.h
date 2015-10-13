#pragma once
#include"../Scheduler.h"

/*
Implementation of an EDF scheduler.

Bendik S. Hjelseng
*/
class EDF_BSH :
	public Scheduler
{
public:
	EDF_BSH();
	~EDF_BSH();
	Task* Schedule(double time);
};