#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Actions\AddANDgate2.h"
#include "AddANDgate3.h"
#include"AddBUFFER.h"
#include"AddNANDgate2.h"
#include"AddNORgate2.h"
#include"AddNORgate3.h"
#include"AddNOT.h"
#include"AddORgate2.h"
#include"AddXNORgate2.h"
#include"AddXORgate2.h"
#include"AddXORgate3.h"
#include"AddLED.h"
#include"AddSWITCH.h"
#include"AddCONNECTION.h"
#include"SELECT_ACTION.h"
#include"COPY_ACTION.h"
#include"PASTE_ACTION.h"
#include"DELETE_ACTION.h"
#include"CUT_ACTION.h"
#include"mDELETE_ACTION.h"
#include"MOVE_ACTION.h"


//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface

	//added//
	Component* Copied;
	
	//
	int ConCount;
	Connection* ConList[200];
public:


public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	void addcompo();

	//destructor
	~ApplicationManager();

	
	
	//added//
	//addedd
	Component** GetList();
	int GetCompCount();

	//
	void SetCopied(Component *c);
	Component* GetCopied();
	
	
	//
	void AddConnection(Connection* pcon);
	Connection** GetConList();
	int GetConCount();
	
};

#endif