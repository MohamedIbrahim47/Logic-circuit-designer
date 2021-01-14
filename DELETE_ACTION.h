#ifndef _DELETE_ACTION_H
#define _DELETE_ACTION_H

#include "Actions/Action.h"
#include "White.h"
#include "Connection_w.h"
class DELETE_ACTION : public Action
{
private:
	int x, y;
public:
	DELETE_ACTION(ApplicationManager* pApp);
	virtual ~DELETE_ACTION(void);

	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif