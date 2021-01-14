#include "mDELETE_ACTION.h"
#include "ApplicationManager.h"
#include "Components/AND2.h"

mDELETE_ACTION::mDELETE_ACTION(ApplicationManager* pApp) :Action(pApp)
{

}

mDELETE_ACTION::~mDELETE_ACTION(void)
{

}

void mDELETE_ACTION::ReadActionParameters()
{
}

void mDELETE_ACTION::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();


	Component** List = pManager->GetList();
	GraphicsInfo GInfo;
	GraphicsInfo GInfo_c; //for the connection


	Component* Comp_check = NULL;

	//lets get a list of all connections
	Connection** cons = pManager->GetConList();

	int c = 0;
	if (pManager->GetCompCount() != 0) {
		for (int i = 0; i < pManager->GetCompCount(); i++) {
			if (dynamic_cast<White*>(List[i]) == NULL) {
				if (dynamic_cast<Connection*>(List[i]) == NULL) {
					if (!List[i]->Getis_deleted()) {
						if (List[i]->Getis_selected()) {
							c = 1;
							GInfo.x1 = List[i]->getGraphicsInfo().x1;
							GInfo.x2 = List[i]->getGraphicsInfo().x2;
							GInfo.y1 = List[i]->getGraphicsInfo().y1;
							GInfo.y2 = List[i]->getGraphicsInfo().y2;
							pOut->PrintMsg("Component deleted ");

							List[i]->Setis_deleted(true);
							White* pA = new White(GInfo, AND2_FANOUT);
							pManager->AddComponent(pA);

							Comp_check = List[i];	//used to check if connections will be deleted

							//check for Comp_check if it has a connection to delete
							if (Comp_check != NULL) {
								if (pManager->GetConCount() != 0) {
									for (int i = 0; i < pManager->GetConCount(); i++) {
										if (cons[i]->GetSourceComp() == Comp_check || cons[i]->GetDistComp() == Comp_check) {
											if (!cons[i]->Getis_deleted()) {
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
							}
						}
					}
				}
			}
		}
	}

	pOut->ClearStatusBar();
	if (c == 0) {
		pOut->PrintMsg("No Component was deleted ");
	}
	else
	{
		pOut->PrintMsg("Deleted all selected items ");
	}
}

void mDELETE_ACTION::Undo()
{}

void mDELETE_ACTION::Redo()
{}

