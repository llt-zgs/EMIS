#include"service_mode_impl.h"
#include"emis.h"

void ServiceModeImpl::load(vector<Department>& deptArr)
{
	ifstream ifs(SERVICE_PATH,ios::in);
	
	while(ifs.good())
	{
		Department dept;//创建一个部门
		ifs >> dept;
		if(ifs.good())
		{
			deptArr.push_back(dept);
		}
	}
	
	ifs.close();
}

void ServiceModeImpl::save(vector<Department>& deptArr)
{
	ofstream ofs(SERVICE_PATH,ios::out);
	
	for(uint32_t i=0; i<deptArr.size(); i++)
	{
		ofs << deptArr[i];
	}
	
	ofs.close();
}
