#include "CUT_ACTION.h"
#include "ApplicationManager.h"
#include "Components/AND2.h"

CUT_ACTION::CUT_ACTION(ApplicationManager* pApp) :Action(pApp)
{

}

CUT_ACTION::~CUT_ACTION(void)
{

}

void CUT_ACTION::ReadActionParameters()
{
	/////////////////Read Actionparameters//////////////////////////////////
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Select the component you want to cut");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	////////////////////////////////////////////////////////////////////////
}

void CUT_ACTION::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();


	Component** List = pManager->GetList();
	GraphicsInfo GInfo;
	GraphicsInfo GInfo_c; //for the connection


	Component* Comp_check = NULL;

	int del_con = 1;
	int c = 0;
	if (pManager->GetCompCount() != 0) {
		for (int i = 0; i < pManager->GetCompCount(); i++) {
			if (x > List[i]->getGraphicsInfo().x1 && x < List[i]->getGraphicsInfo().x2) {
				if (y > List[i]->getGraphicsInfo().y1 && y < List[i]->getGraphicsInfo().y2) {
					if (dynamic_cast<White*>(List[i]) == NULL) {
						if (dynamic_cast<Connection*>(List[i]) == NULL) {
							if (!List[i]->Getis_deleted()) {
								c = 1;
								GInfo.x1 = List[i]->getGraphicsInfo().x1;
								GInfo.x2 = List[i]->getGraphicsInfo().x2;
								GInfo.y1 = List[i]->getGraphicsInfo().y1;
								GInfo.y2 = List[i]->getGraphicsInfo().y2;

								List[i]->Setis_deleted(true);
								White* pA = new White(GInfo, AND2_FANOUT);
								pManager->AddComponent(pA);
								pManager->SetCopied(List[i]);
								pOut->PrintMsg("Component is cut ");

								Comp_check = List[i];	//used to check if connections will be deleted

								del_con = 0;
								break;
							}
						}
					}
				}
			}
		}
	}
	

	//lets get a list of all connections
	Connection** cons = pManager->GetConList();



	//check for Comp_check if it has a connection to delete
	if (Comp_check != NULL) {
		if (pManager->GetConCount() != 0) {
			for (int i = 0; i < pManager->GetConCount(); i++) {
				if (cons[i]->GetSourceComp() == Comp_check || cons[i]->GetDistComp() == Comp_check) {
					GInfo_c.x1 = cons[i]->getGraphicsInfo().x1;
					GInfo_c.x2 = cons[i]->getGraphicsInfo().x2;
					GInfo_c.y1 = cons[i]->getGraphicsInfo().y1;
					GInfo_c.y2 = cons[i]->getGraphicsInfo().y2;

					cons[i]->Setis_deleted(true);
					Connection_w* pA = new Connection_w(GInfo_c);
					pManager->AddComponent(pA);
				}
			}
		}
	}


	if (c == 0)
		pOut->PrintMsg("No Component was cut ");

}

void CUT_ACTION::Undo()
{}

void CUT_ACTION::Redo()
{}

