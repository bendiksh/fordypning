#include "EDF_BSH.h"
#include<iostream>

/*
Implementation of an EDF scheduler.

Bendik S. Hjelseng
*/

EDF_BSH::EDF_BSH()
{
	preemptive = true;
}

EDF_BSH::~EDF_BSH()
{
}

Task* EDF_BSH::Schedule(double time)
{
	availableTaskIterator->First();
	Task* bestTask = availableTaskIterator->CurrentItem();
	double closestDeadline = bestTask->getTarrival() + bestTask->getDeadline() - time;

	Task* tempTask;
	double tempDeadline;

	for (availableTaskIterator->First(); !availableTaskIterator->IsDone(); availableTaskIterator->Next())
	{
		tempTask = availableTaskIterator->CurrentItem();
		tempDeadline = tempTask->getTarrival() + tempTask->getDeadline() - time;
		if ((tempDeadline < closestDeadline) && (tempDeadline > 0) && (closestDeadline > 0 ))
		{
			closestDeadline = tempDeadline;
			bestTask = tempTask;
		}
	}
	return bestTask;
}