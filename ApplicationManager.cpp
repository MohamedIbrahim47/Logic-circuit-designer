#include "ApplicationManager.h"



ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();

	//added//
	Copied = NULL;	//initially nothing is copied
	//
	ConCount = 0;
	for (int i = 0; i < 200; i++)
		ConList[i] = NULL;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
	    case SIM_MODE:
	     	OutputInterface->cleartoolbar();
	    	OutputInterface->CreateSimulationToolBar();
			break;
	    case addcomp:
			OutputInterface->creategatebar();
			break;
		case SAVE:
			break;
		case LOAD:
			break;
		case COPY:
			pAct = new COPY_ACTION(this);
			break;
		case CUT:
			pAct = new CUT_ACTION(this);
			break;
		case PASTE:
			pAct = new PASTE_ACTION(this);
			break;
		case DELETEE:
			pAct = new DELETE_ACTION(this);
			break;
		case mDELETEE:
			pAct = new mDELETE_ACTION(this);
			break;
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;
		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;
		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;
		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;
		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;
		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;
		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);
			break;
		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this);
			break;
		case ADD_XOR_GATE_3:
			pAct = new AddXORgate3(this);
			break;
		case ADD_INV:
			pAct = new AddNOT(this);
			break;
		case ADD_Buff:
			pAct = new AddBUFFER(this);
			break;
		case ADD_Switch:
			pAct = new AddSWITCH(this);
			break;
		case ADD_LED:
			pAct = new AddLED(this);
			break;
		case ADD_CONNECTION:
			pAct = new AddCONNECTION(this);
			break;
		case SELECT:
			pAct = new SELECT_ACTION(this);
			break;
		case MOVE:
			pAct = new MOVE_ACTION(this);
		
		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{

	for (int i = 0; i < CompCount; i++) {
		if(CompList[i]->Getis_deleted() == false)
			CompList[i]->Draw(OutputInterface);
	}
}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::addcompo()
{
	ActionType ActType;
	ActType = GetUserAction();
	//Exexute the action
	ExecuteAction(ActType);
}
////////////////////////////////////////////////////////////////////
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}

//added//
Component** ApplicationManager::GetList() {
	return CompList;
}

int ApplicationManager::GetCompCount() {
	return CompCount;
}

//
void ApplicationManager::SetCopied(Component* c) {
	Copied = c;
}
Component* ApplicationManager::GetCopied() {
	return Copied;
}

//
void ApplicationManager::AddConnection(Connection* pcon) {
	ConList[ConCount++] = pcon;
}
Connection** ApplicationManager::GetConList() {
	return ConList;
}
int ApplicationManager::GetConCount() {
	return ConCount;
}