#include "SELECT_ACTION.h"
#include "ApplicationManager.h"
#include "Components/AND2.h"

SELECT_ACTION::SELECT_ACTION(ApplicationManager* pApp) :Action(pApp)
{

}

SELECT_ACTION::~SELECT_ACTION(void)
{

}

void SELECT_ACTION::ReadActionParameters()
{
	/////////////////Read Actionparameters//////////////////////////////////
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Confirm the component you want to select/unselect");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	////////////////////////////////////////////////////////////////////////
}

void SELECT_ACTION::Execute()
{
	ReadActionParameters();

	Component** List = pManager->GetList();
	GraphicsInfo GInfo;

	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	Component* OLD = NULL;
	Component* NEW = NULL;

	int c = 0;
	if (*List != NULL) {
		for (int i = 0; i < pManager->GetCompCount(); i++) {
			if (x > List[i]->getGraphicsInfo().x1 && x < List[i]->getGraphicsInfo().x2) {
				if (y > List[i]->getGraphicsInfo().y1 && y < List[i]->getGraphicsInfo().y2) {
					if (List[i]->Getis_deleted() == false ) {				//cant select a deleted component
						if (dynamic_cast<White*>(List[i]) == NULL)			
						{
							if (dynamic_cast<AND2*>(List[i]) != NULL) {
								GInfo.x1 = List[i]->getGraphicsInfo().x1;
								GInfo.x2 = List[i]->getGraphicsInfo().x2;
								GInfo.y1 = List[i]->getGraphicsInfo().y1;
								GInfo.y2 = List[i]->getGraphicsInfo().y2;
								AND2* pA;
								if (List[i]->Getis_selected() == false) {			//if gate is not selected then draws highlighted & deletes old
									pA = new AND2(GInfo, AND2_FANOUT, true);
									pA->Setis_selected(true);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								else
								{
									pA = new AND2(GInfo, AND2_FANOUT, false);
									pA->Setis_selected(false);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								OLD = List[i];
								NEW = pA;
								pManager->AddComponent(pA);
								c = 1;
								break;
							}
							else if (dynamic_cast<OR2*>(List[i]) != NULL)
							{
								GInfo.x1 = List[i]->getGraphicsInfo().x1;
								GInfo.x2 = List[i]->getGraphicsInfo().x2;
								GInfo.y1 = List[i]->getGraphicsInfo().y1;
								GInfo.y2 = List[i]->getGraphicsInfo().y2;
								OR2* pA;
								if (List[i]->Getis_selected() == false) {			//if gate is not selected then draws highlighted & deletes old
									pA = new OR2(GInfo, AND2_FANOUT, true);
									pA->Setis_selected(true);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								else
								{
									pA = new OR2(GInfo, AND2_FANOUT, false);
									pA->Setis_selected(false);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								OLD = List[i];
								NEW = pA;
								pManager->AddComponent(pA);
								c = 1;
								break;
							}
							else if (dynamic_cast<NAND2*>(List[i]) != NULL)
							{
								GInfo.x1 = List[i]->getGraphicsInfo().x1;
								GInfo.x2 = List[i]->getGraphicsInfo().x2;
								GInfo.y1 = List[i]->getGraphicsInfo().y1;
								GInfo.y2 = List[i]->getGraphicsInfo().y2;
								NAND2* pA;
								if (List[i]->Getis_selected() == false) {		
									pA = new NAND2(GInfo, AND2_FANOUT, true);
									pA->Setis_selected(true);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								else
								{
									pA = new NAND2(GInfo, AND2_FANOUT, false);
									pA->Setis_selected(false);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								OLD = List[i];
								NEW = pA;
								pManager->AddComponent(pA);
								c = 1;
								break;
							}
							else if (dynamic_cast<NOR2*>(List[i]) != NULL)
							{
								GInfo.x1 = List[i]->getGraphicsInfo().x1;
								GInfo.x2 = List[i]->getGraphicsInfo().x2;
								GInfo.y1 = List[i]->getGraphicsInfo().y1;
								GInfo.y2 = List[i]->getGraphicsInfo().y2;
								NOR2* pA;
								if (List[i]->Getis_selected() == false) {		
									pA = new NOR2(GInfo, AND2_FANOUT, true);
									pA->Setis_selected(true);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								else
								{
									pA = new NOR2(GInfo, AND2_FANOUT, false);
									pA->Setis_selected(false);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								OLD = List[i];
								NEW = pA;
								pManager->AddComponent(pA);
								c = 1;
								break;
							}
							else if (dynamic_cast<XOR2*>(List[i]) != NULL)
							{
								GInfo.x1 = List[i]->getGraphicsInfo().x1;
								GInfo.x2 = List[i]->getGraphicsInfo().x2;
								GInfo.y1 = List[i]->getGraphicsInfo().y1;
								GInfo.y2 = List[i]->getGraphicsInfo().y2;
								XOR2* pA;
								if (List[i]->Getis_selected() == false) {		
									pA = new XOR2(GInfo, AND2_FANOUT, true);
									pA->Setis_selected(true);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								else
								{
									pA = new XOR2(GInfo, AND2_FANOUT, false);
									pA->Setis_selected(false);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								OLD = List[i];
								NEW = pA;
								pManager->AddComponent(pA);
								c = 1;
								break;
							}
							else if (dynamic_cast<XNOR2*>(List[i]) != NULL)
							{
								GInfo.x1 = List[i]->getGraphicsInfo().x1;
								GInfo.x2 = List[i]->getGraphicsInfo().x2;
								GInfo.y1 = List[i]->getGraphicsInfo().y1;
								GInfo.y2 = List[i]->getGraphicsInfo().y2;
								XNOR2* pA;
								if (List[i]->Getis_selected() == false) {
									pA = new XNOR2(GInfo, AND2_FANOUT, true);
									pA->Setis_selected(true);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								else
								{
									pA = new XNOR2(GInfo, AND2_FANOUT, false);
									pA->Setis_selected(false);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								OLD = List[i];
								NEW = pA;
								pManager->AddComponent(pA);
								c = 1;
								break;
							}
							else if (dynamic_cast<AND3*>(List[i]) != NULL)
							{
								GInfo.x1 = List[i]->getGraphicsInfo().x1;
								GInfo.x2 = List[i]->getGraphicsInfo().x2;
								GInfo.y1 = List[i]->getGraphicsInfo().y1;
								GInfo.y2 = List[i]->getGraphicsInfo().y2;
								AND3* pA;
								if (List[i]->Getis_selected() == false) {
									pA = new AND3(GInfo, AND2_FANOUT, true);
									pA->Setis_selected(true);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								else
								{
									pA = new AND3(GInfo, AND2_FANOUT, false);
									pA->Setis_selected(false);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								OLD = List[i];
								NEW = pA;
								pManager->AddComponent(pA);
								c = 1;
								break;
							}
							else if (dynamic_cast<NOR3*>(List[i]) != NULL)
							{
								GInfo.x1 = List[i]->getGraphicsInfo().x1;
								GInfo.x2 = List[i]->getGraphicsInfo().x2;
								GInfo.y1 = List[i]->getGraphicsInfo().y1;
								GInfo.y2 = List[i]->getGraphicsInfo().y2;
								NOR3* pA;
								if (List[i]->Getis_selected() == false) {
									pA = new NOR3(GInfo, AND2_FANOUT, true);
									pA->Setis_selected(true);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								else
								{
									pA = new NOR3(GInfo, AND2_FANOUT, false);
									pA->Setis_selected(false);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								OLD = List[i];
								NEW = pA;
								pManager->AddComponent(pA);
								c = 1;
								break;
							}
							else if (dynamic_cast<XOR3*>(List[i]) != NULL)
							{
								GInfo.x1 = List[i]->getGraphicsInfo().x1;
								GInfo.x2 = List[i]->getGraphicsInfo().x2;
								GInfo.y1 = List[i]->getGraphicsInfo().y1;
								GInfo.y2 = List[i]->getGraphicsInfo().y2;
								XOR3* pA;
								if (List[i]->Getis_selected() == false) {
									pA = new XOR3(GInfo, AND2_FANOUT, true);
									pA->Setis_selected(true);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								else
								{
									pA = new XOR3(GInfo, AND2_FANOUT, false);
									pA->Setis_selected(false);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								OLD = List[i];
								NEW = pA;
								pManager->AddComponent(pA);
								c = 1;
								break;
							}
							else if (dynamic_cast<NOT*>(List[i]) != NULL)
							{
								GInfo.x1 = List[i]->getGraphicsInfo().x1;
								GInfo.x2 = List[i]->getGraphicsInfo().x2;
								GInfo.y1 = List[i]->getGraphicsInfo().y1;
								GInfo.y2 = List[i]->getGraphicsInfo().y2;
								NOT* pA;
								if (List[i]->Getis_selected() == false) {
									pA = new NOT(GInfo, AND2_FANOUT, true);
									pA->Setis_selected(true);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								else
								{
									pA = new NOT(GInfo, AND2_FANOUT, false);
									pA->Setis_selected(false);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								OLD = List[i];
								NEW = pA;
								pManager->AddComponent(pA);
								c = 1;
								break;
							}
							else if (dynamic_cast<BUFFER*>(List[i]) != NULL)
							{
								GInfo.x1 = List[i]->getGraphicsInfo().x1;
								GInfo.x2 = List[i]->getGraphicsInfo().x2;
								GInfo.y1 = List[i]->getGraphicsInfo().y1;
								GInfo.y2 = List[i]->getGraphicsInfo().y2;
								BUFFER* pA;
								if (List[i]->Getis_selected() == false) {
									pA = new BUFFER(GInfo, AND2_FANOUT, true);
									pA->Setis_selected(true);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								else
								{
									pA = new BUFFER(GInfo, AND2_FANOUT, false);
									pA->Setis_selected(false);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								OLD = List[i];
								NEW = pA;
								pManager->AddComponent(pA);
								c = 1;
								break;
							}
							else if (dynamic_cast<LED*>(List[i]) != NULL)
							{
								GInfo.x1 = List[i]->getGraphicsInfo().x1;
								GInfo.x2 = List[i]->getGraphicsInfo().x2;
								GInfo.y1 = List[i]->getGraphicsInfo().y1;
								GInfo.y2 = List[i]->getGraphicsInfo().y2;
								LED* pA;
								if (List[i]->Getis_selected() == false) {
									pA = new LED(GInfo, AND2_FANOUT, true);
									pA->Setis_selected(true);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								else
								{
									pA = new LED(GInfo, AND2_FANOUT, false);
									pA->Setis_selected(false);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								OLD = List[i];
								NEW = pA;
								pManager->AddComponent(pA);
								c = 1;
								break;
							}
							else if (dynamic_cast<SWITCH*>(List[i]) != NULL)
							{
								GInfo.x1 = List[i]->getGraphicsInfo().x1;
								GInfo.x2 = List[i]->getGraphicsInfo().x2;
								GInfo.y1 = List[i]->getGraphicsInfo().y1;
								GInfo.y2 = List[i]->getGraphicsInfo().y2;
								SWITCH* pA;
								if (List[i]->Getis_selected() == false) {
									pA = new SWITCH(GInfo, AND2_FANOUT, true);
									pA->Setis_selected(true);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								else
								{
									pA = new SWITCH(GInfo, AND2_FANOUT, false);
									pA->Setis_selected(false);
									List[i]->Setis_deleted(true);
									//
									pA->sethas(List[i]->gethas());
								}
								OLD = List[i];
								NEW = pA;
								pManager->AddComponent(pA);
								c = 1;
								break;
						}
						}
					}
				}
			}
		}
	}
	// transfer connection from OLD to NEW
	Connection** cons = pManager->GetConList();
	if (c != 0) {
		if (pManager->GetConCount() != 0) {
			for (int i = 0; i < pManager->GetConCount(); i++) {
				if (cons[i]->GetDistComp() == OLD) {
					cons[i]->SetDistComp(NEW);
				}
				else if (cons[i]->GetSourceComp() == OLD)
				{
					cons[i]->SetSourceComp(NEW);
				}
			}
		}
	}



	Output* pOut = pManager->GetOutput();
	if (c != 0) {
		pOut->PrintMsg("Item selected");
	}
	else
	{
		pOut->PrintMsg("No Item selected");
	}

}

void SELECT_ACTION::Undo()
{}

void SELECT_ACTION::Redo()
{}

