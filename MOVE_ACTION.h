#ifndef _MOVE_ACTION_H
#define _MOVE_ACTION_H


#include "Actions/Action.h"
class MOVE_ACTION : public Action
{
private:
	int x, y;
public:
	MOVE_ACTION(ApplicationManager* pApp);
	virtual ~MOVE_ACTION(void);

	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif