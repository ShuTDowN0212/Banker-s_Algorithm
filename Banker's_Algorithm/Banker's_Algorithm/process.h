#include <iostream>
#include <vector>
#include <string>

using namespace std;

class process
{
private:
	vector<int> Allocation;
	vector<int> Max;
	vector<int> Need;
	string Name;
	bool pass = false;

public:
	void SetAllocation(vector<int> l);
	void SetMax(vector<int> l);
	void SetNeed();
	void SetName(string);
	void SetPass(bool);
	vector<int> ReturnAllocation();
	vector<int> ReturnMax();
	vector<int> ReturnNeed();
	string ReturnName();
	bool ReturnPassAvailble();
	void Print(int);
};
