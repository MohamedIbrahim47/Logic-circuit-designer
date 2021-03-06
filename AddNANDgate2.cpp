#include "AddNANDgate2.h"
#include "../Project Code Framework/ApplicationManager.h"

AddNANDgate2::AddNANDgate2(ApplicationManager* pApp) :Action(pApp)
{
	abort = 0;
}

AddNANDgate2::~AddNANDgate2(void)
{
}

void AddNANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input NAND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

	//////////////////
	if (Cy < 185 || Cy > 675) {
		abort = 1;
		pOut->PrintMsg("Action aborted, you can only draw in the drawing area");
	}
	/////////////////

}

void AddNANDgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	if (abort != 0) {
		return;
	}

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	NAND2* pA = new NAND2(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

void AddNANDgate2::Undo()
{}

void AddNANDgate2::Redo()
{}

