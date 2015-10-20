#include<iostream>
#include"SimulatorCore/Task.h"
#include"Containers/Set.h"
#include"Iterators/AbstractIterator.h"
#include"SimulatorCore/Model.h"
#include"SimulatorCore/Simulator.h"

//Include Schedulers here
#include"Schedulers/RM.h"
#include"Schedulers/RR.h"
#include"Schedulers/FIFO.h"
#include"Schedulers/EDF.h"
#include"Schedulers/EDF_BSH.h"

/******************************************************************
					SchedulerSimulator

This file contains the main()-function for the Scheduler Simulator.

This software is created as a part of a Masters project at NTNU.
The SchedulerSimulator can simulate the execution of task sets, 
based on a scheduler algorithm. Relevant reports will be generated.
New schedulers can be added and simulated. Task sets can be created 
manually and generated. 

						June 2015
				by Inger Johanne Rudolfsen
*******************************************************************/







int main()
{
	/****************************************************
	Originalt eksempel
	
	//Declare the schedulers
	FIFO SchedulerFIFO;
	EDF SchedulerEDF;

	//For MANUALLY creating tasks:
	//Create a Task Set:
	Task a(1, 0, 100, 24, 100);
	Task b(2, 0, 80, 20, 80);
	Task c(3, 0, 60, 20, 60);

	Set<Task*> myTasks;
	myTasks.addItem(&a);
	myTasks.addItem(&b);
	myTasks.addItem(&c);

	//Create a model
	Model myModel("MyModel", &myTasks, &SchedulerFIFO, 200);


	//For GENERATING tasks within the model:
	//Create a model with 3 periodic and 4 aperiodic tasks
	Model generatedTasksModel("generatedTasks", 3, 4, &SchedulerEDF);
	//Set simulation run time
	generatedTasksModel.setRunTime(200);

	//Create a simulator
	Simulator mySimulator;

	//Run simulations

	mySimulator.runSimulation(&myModel);
	mySimulator.runSimulation(&generatedTasksModel);

	****************************************************/

	// BSH
	EDF_BSH SchedBSH;

	/*
	// Create a task set
	Task a(1, 10, 130, 20, 0);
	Task b(2, 20, 40, 20, 0);
	Task c(3, 40, 70, 20, 0);
	Task d(4, 50, 110, 20, 0);
	Task e(5, 60, 90, 20, 0);

	Set<Task*> myTasks;
	myTasks.addItem(&a);
	myTasks.addItem(&b);
	myTasks.addItem(&c);
	myTasks.addItem(&d);
	myTasks.addItem(&e);
	
	// Create a model
	Model tryEDFBSH("createdSet1BSH",&myTasks, &SchedBSH, 500);
	*/

	
	Model tryEDFBSH("tilbakeTilVanlig", 4, 4, &SchedBSH);

	tryEDFBSH.setRunTime(500);

	Simulator mySim;

	mySim.runSimulation(&tryEDFBSH);
}


