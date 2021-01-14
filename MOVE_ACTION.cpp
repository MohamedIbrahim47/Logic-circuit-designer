#include "MOVE_ACTION.h"
#include "ApplicationManager.h"
#include "Components/AND2.h"

MOVE_ACTION::MOVE_ACTION(ApplicationManager* pApp) :Action(pApp)
{

}

MOVE_ACTION::~MOVE_ACTION(void)
{

}

void MOVE_ACTION::ReadActionParameters()
{
	/////////////////Read Actionparameters//////////////////////////////////
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Select the component you want to move ");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	////////////////////////////////////////////////////////////////////////
}

void MOVE_ACTION::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	Component** List = pManager->GetList();
	Component *comp;
	GraphicsInfo GInfo;

	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	int c = 0;
	if (*List != NULL) {
		for (int i = 0; i < pManager->GetCompCount(); i++) {
			if (x > List[i]->getGraphicsInfo().x1 && x < List[i]->getGraphicsInfo().x2) {
				if (y > List[i]->getGraphicsInfo().y1 && y < List[i]->getGraphicsInfo().y2) {
					if (!List[i]->Getis_deleted()) {
						if (dynamic_cast<White*>(List[i]) == NULL) {
							if (dynamic_cast<Connection*>(List[i]) == NULL) {
								c = 1;
								comp = List[i];

								pOut->PrintMsg("Select where you want to move the selected component ");
								pIn->GetPointClicked(x, y);
								pOut->ClearStatusBar();

								GInfo.x1 = List[i]->getGraphicsInfo().x1;
								GInfo.x2 = List[i]->getGraphicsInfo().x2;
								GInfo.y1 = List[i]->getGraphicsInfo().y1;
								GInfo.y2 = List[i]->getGraphicsInfo().y2;

								List[i]->Setis_deleted(true);
								White* pA = new White(GInfo, AND2_FANOUT);
								pManager->AddComponent(pA);

								GInfo.x1 = x - Len / 2;
								GInfo.x2 = x + Len / 2;
								GInfo.y1 = y - Wdth / 2;
								GInfo.y2 = y + Wdth / 2;
								if (true) {
									if (dynamic_cast<AND2*>(List[i]) != NULL)
									{
										AND2* pA;
										if (List[i]->Getis_selected() == false)
											pA = new AND2(GInfo, AND2_FANOUT, false);
										else
											pA = new AND2(GInfo, AND2_FANOUT, true);
										pA->Setis_selected(List[i]->Getis_selected());
										pManager->AddComponent(pA);
									}
									else if (dynamic_cast<OR2*>(List[i]) != NULL)
									{
										OR2* pA;
										if (List[i]->Getis_selected() == false)
											pA = new OR2(GInfo, AND2_FANOUT, false);
										else
											pA = new OR2(GInfo, AND2_FANOUT, true);
										pA->Setis_selected(List[i]->Getis_selected());
										pManager->AddComponent(pA);
									}
									else if (dynamic_cast<NAND2*>(List[i]) != NULL)
									{
										NAND2* pA;
										if (List[i]->Getis_selected() == false)
											pA = new NAND2(GInfo, AND2_FANOUT, false);
										else
											pA = new NAND2(GInfo, AND2_FANOUT, true);
										pA->Setis_selected(List[i]->Getis_selected());
										pManager->AddComponent(pA);
									}
									else if (dynamic_cast<NOR2*>(List[i]) != NULL)
									{
										NOR2* pA;
										if (List[i]->Getis_selected() == false)
											pA = new NOR2(GInfo, AND2_FANOUT, false);
										else
											pA = new NOR2(GInfo, AND2_FANOUT, true);
										pA->Setis_selected(List[i]->Getis_selected());
										pManager->AddComponent(pA);
									}
									else if (dynamic_cast<XOR2*>(List[i]) != NULL)
									{
										XOR2* pA;
										if (List[i]->Getis_selected() == false)
											pA = new XOR2(GInfo, AND2_FANOUT, false);
										else
											pA = new XOR2(GInfo, AND2_FANOUT, true);
										pA->Setis_selected(List[i]->Getis_selected());
										pManager->AddComponent(pA);
									}
									else if (dynamic_cast<XNOR2*>(List[i]) != NULL)
									{
										XNOR2* pA;
										if (List[i]->Getis_selected() == false)
											pA = new XNOR2(GInfo, AND2_FANOUT, false);
										else
											pA = new XNOR2(GInfo, AND2_FANOUT, true);
										pA->Setis_selected(List[i]->Getis_selected());
										pManager->AddComponent(pA);
									}
									else if (dynamic_cast<AND3*>(List[i]) != NULL)
									{
										AND3* pA;
										if (List[i]->Getis_selected() == false)
											pA = new AND3(GInfo, AND2_FANOUT, false);
										else
											pA = new AND3(GInfo, AND2_FANOUT, true);
										pA->Setis_selected(List[i]->Getis_selected());
										pManager->AddComponent(pA);
									}
									else if (dynamic_cast<NOR3*>(List[i]) != NULL)
									{
										NOR3* pA;
										if (List[i]->Getis_selected() == false)
											pA = new NOR3(GInfo, AND2_FANOUT, false);
										else
											pA = new NOR3(GInfo, AND2_FANOUT, true);
										pA->Setis_selected(List[i]->Getis_selected());
										pManager->AddComponent(pA);
									}
									else if (dynamic_cast<XOR3*>(List[i]) != NULL)
									{
										XOR3* pA;
										if (List[i]->Getis_selected() == false)
											pA = new XOR3(GInfo, AND2_FANOUT, false);
										else
											pA = new XOR3(GInfo, AND2_FANOUT, true);
										pA->Setis_selected(List[i]->Getis_selected());
										pManager->AddComponent(pA);
									}
									else if (dynamic_cast<BUFFER*>(List[i]) != NULL)
									{
										BUFFER* pA;
										if (List[i]->Getis_selected() == false)
											pA = new BUFFER(GInfo, AND2_FANOUT, false);
										else
											pA = new BUFFER(GInfo, AND2_FANOUT, true);
										pA->Setis_selected(List[i]->Getis_selected());
										pManager->AddComponent(pA);
									}
									else if (dynamic_cast<NOT*>(List[i]) != NULL)
									{
										NOT* pA;
										if (List[i]->Getis_selected() == false)
											pA = new NOT(GInfo, AND2_FANOUT, false);
										else
											pA = new NOT(GInfo, AND2_FANOUT, true);
										pA->Setis_selected(List[i]->Getis_selected());
										pManager->AddComponent(pA);
									}
									else if (dynamic_cast<LED*>(List[i]) != NULL)
									{
										LED* pA;
										if (List[i]->Getis_selected() == false)
											pA = new LED(GInfo, AND2_FANOUT, false);
										else
											pA = new LED(GInfo, AND2_FANOUT, true);
										pA->Setis_selected(List[i]->Getis_selected());
										pManager->AddComponent(pA);
									}
									else if (dynamic_cast<SWITCH*>(List[i]) != NULL)
									{
										SWITCH* pA;
										if (List[i]->Getis_selected() == false)
											pA = new SWITCH(GInfo, AND2_FANOUT, false);
										else
											pA = new SWITCH(GInfo, AND2_FANOUT, true);
										pA->Setis_selected(List[i]->Getis_selected());
										pManager->AddComponent(pA);
									}
								}
								

								break;
							}
						}
					}
				}
			}
		}
	}

	if (c == 0) {
		pOut->PrintMsg("No Component selected ");
		return;
	}

	OutputPin* pSrcPin = new OutputPin(5);
	InputPin* pDstPin = new InputPin();

	//lets get a list of all connections
	Connection** cons = pManager->GetConList();


	int count = 0;
	//check for Comp_check if it has a connection to delete
	if (comp != NULL) {
		if (pManager->GetConCount() != 0) {
			for (int i = 0; i < pManager->GetConCount(); i++) {
				if (!cons[i]->Getis_deleted()) {
					if (cons[i]->GetSourceComp() == comp || cons[i]->GetDistComp() == comp) {

						GInfo.x1 = cons[i]->getGraphicsInfo().x1;
						GInfo.x2 = cons[i]->getGraphicsInfo().x2;
						GInfo.y1 = cons[i]->getGraphicsInfo().y1;
						GInfo.y2 = cons[i]->getGraphicsInfo().y2;

						cons[i]->Setis_deleted(true);
						Connection_w* pA = new Connection_w(GInfo);
						pManager->AddComponent(pA);
					}
				}
			}
		}
	}
}

void MOVE_ACTION::Undo()
{}

void MOVE_ACTION::Redo()
{}

