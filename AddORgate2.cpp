#include "AddORgate2.h"
#include "ApplicationManager.h"

AddORgate2::AddORgate2(ApplicationManager* pApp) :Action(pApp)
{
	abort = 0;
}

AddORgate2::~AddORgate2(void)
{
}

void AddORgate2::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("2-Input OR Gate: Click to add the gate");

	pIn->GetPointClicked(Cx, Cy);

	pOut->ClearStatusBar();

	//////////////////
	if (Cy < 185 || Cy > 675) {
		abort = 1;
		pOut->PrintMsg("Action aborted, you can only draw in the drawing area");
	}
	//////////////////

}

void AddORgate2::Execute()
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
	OR2* pA = new OR2(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

void AddORgate2::Undo()
{}

void AddORgate2::Redo()
{}

