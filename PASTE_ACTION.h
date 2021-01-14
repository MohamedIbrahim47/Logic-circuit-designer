#ifndef _PASTE_ACTION_H
#define _PASTE_ACTION_H


#include "Actions/Action.h"
class PASTE_ACTION : public Action
{
private:
	int x, y;

	//
	int abort;
public:
	PASTE_ACTION(ApplicationManager* pApp);
	virtual ~PASTE_ACTION(void);

	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif