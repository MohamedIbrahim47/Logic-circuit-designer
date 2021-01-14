#include "AddBUFFER.h"
#include "ApplicationManager.h"

AddBUFFER::AddBUFFER(ApplicationManager* pApp) :Action(pApp)
{
	abort = 0;
}

AddBUFFER::~AddBUFFER(void)
{
}

void AddBUFFER::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("BUFFER Gate: Click to add the gate");

	pIn->GetPointClicked(Cx, Cy);

	pOut->ClearStatusBar();

	//////////////////
	if (Cy < 185 || Cy > 675) {
		abort = 1;
		pOut->PrintMsg("Action aborted, you can only draw in the drawing area");
	}
	//////////////////
}

void AddBUFFER::Execute()
{
	ReadActionParameters();

	if (abort != 0) {
		return;
	}


	int Len = UI.AND2_Width;	//default
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo;

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	BUFFER* pA = new BUFFER(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

void AddBUFFER::Undo()
{}

void AddBUFFER::Redo()
{}

