#ifndef SERVICE_CTRL_IMPL_H
#define SERVICE_CTRL_IMPL_H
#include"service_ctrl.h"
#include"service_mode.h"
#include "department.h"

class ServiceCtrlImpl :public ServiceCtrl
{
	ServiceMode* srcMode;
	vector<Department> deptArr;

public:
	ServiceCtrlImpl(void);
	
	~ServiceCtrlImpl(void);
	
    bool addDept(Department& dept);

    bool delDept(int id);

    vector<Department>& listDept(void);

    bool addEmp(int id,Employee& emp);

    bool delEmp(int id);

    bool modEmp(int id,Employee& emp);

    Department* listEmp(int);

    vector<Department>& listAllEmp();
};

#endif// SERVICE_CTRL_IMPL_H
