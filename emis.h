#ifndef EMIS_H
#define EMIS_H
#include "manager_view.h"

#define ID_PATH 		"data/id.dat"
#define ADMIN_PATH      "data/.admin.dat"
#define MANAGER_PATH 	"data/manager.dat"
#define SERVICE_PATH	"data/service.dat"

class EMIS
{
	static EMIS* emis;
	
	ManagerView* mgrView;
	
	EMIS(void);
	
	EMIS(const EMIS& that) {}
public:
	~EMIS(void);
	
	static EMIS* create(void);
	
	void start(void);
};

#endif //EMIS_H
