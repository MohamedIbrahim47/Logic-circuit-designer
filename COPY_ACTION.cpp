#include "COPY_ACTION.h"
#include "ApplicationManager.h"
#include "Components/AND2.h"

COPY_ACTION::COPY_ACTION(ApplicationManager* pApp) :Action(pApp)
{

}

COPY_ACTION::~COPY_ACTION(void)
{

}

void COPY_ACTION::ReadActionParameters()
{
	/////////////////Read Actionparameters//////////////////////////////////
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Select the component you want to copy ");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	////////////////////////////////////////////////////////////////////////
}

void COPY_ACTION::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();


	Component** List = pManager->GetList();
	GraphicsInfo GInfo;

	int c = 0;
	if (*List != NULL) {
		for (int i = 0; i < pManager->GetCompCount(); i++) {
			if (x > List[i]->getGraphicsInfo().x1 && x < List[i]->getGraphicsInfo().x2) {
				if (y > List[i]->getGraphicsInfo().y1 && y < List[i]->getGraphicsInfo().y2) {
					if (!List[i]->Getis_deleted()) {
						c = 1;
						pManager->SetCopied(List[i]);
						pOut->PrintMsg("Component copied ");

						//////////////////////
						pManager->GetCopied()->Setis_selected(List[i]->Getis_selected());
						//////////////////////


						break;
					}
				}
			}
		}
	}

	if (c == 0)
		pOut->PrintMsg("No Component copied ");

}

void COPY_ACTION::Undo()
{}

void COPY_ACTION::Redo()
{}

