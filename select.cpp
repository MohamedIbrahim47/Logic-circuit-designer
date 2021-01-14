#include "select.h"
#include "ApplicationManager.h"
#include "Components/AND2.h"

SELECT::SELECT(ApplicationManager* pApp) :Action(pApp)
{

}

SELECT::~SELECT(void)
{

}

void SELECT::ReadActionParameters()
{
}

void SELECT::Execute()
{
	/////////////////Read Actionparameters//////////////////////////////////
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pIn->GetPointClicked(x, y);
	//pOut->ClearStatusBar();
	////////////////////////////////////////////////////////////////////////

	Component** List = pManager->GetList();
	GraphicsInfo GInfo;

	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	if (*List != NULL) {
		for (int i = 0; i < pManager->GetCompCount(); i++) {
			if (x > List[i]->getGraphicsInfo().x1 && x < List[i]->getGraphicsInfo().x2) {
				if (y > List[i]->getGraphicsInfo().y1 && y < List[i]->getGraphicsInfo().y2) {
					if (dynamic_cast<AND2*>(List[i]) != NULL) {
						GInfo.x1 = x - Len / 2;
						GInfo.x2 = x + Len / 2;
						GInfo.y1 = y - Wdth / 2;
						GInfo.y2 = y + Wdth / 2;
						AND2* pA = new AND2(GInfo, AND2_FANOUT,true);
						pManager->AddComponent(pA);
						break;
					}
					else if (dynamic_cast<OR2*>(List[i]) != NULL)
					{
					}
				}
			}
		}
	}
	AND2* pA = new AND2(GInfo, AND2_FANOUT, true);
	pManager->AddComponent(pA);
}

void SELECT::Undo()
{}

void SELECT::Redo()
{}

