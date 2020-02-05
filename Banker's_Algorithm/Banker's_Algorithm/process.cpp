#include "process.h"

void process::SetAllocation(vector<int> l)
{
	for (int i = 0; i < l.size(); i++)
	{
		int instance = 0;
	tryAgain:
		cout << "Enter The Allocation. The Capacity of the Instance is " << Max[i] << " : ";
		cin >> instance;
		
		if (instance > Max[i])
		{
			cout << "Capacity is Exceeded than Max Capacity." << endl;
			goto tryAgain;
		}

		else
		{
			Allocation.push_back(instance);
		}
	}
}

void process::SetMax(vector<int> l)
{
	for (int i = 0; i < l.size(); i++)
	{
		int instance = 0;
	tryAgain:
		cout << "Enter The Max Capacity. The Capacity of the Instance is " << l[i] << " : ";
		cin >> instance;

		if (instance > l[i])
		{
			cout << "Capacity is Exceeded than the Resources' Capacity." << endl;
			goto tryAgain;
		}

		else
		{
			Max.push_back(instance);
		}
	}
}

void process::SetNeed()
{
	for (int i = 0; i < Max.size(); i++)
	{
		int instance = 0;
		instance = Max[i] - Allocation[i];
		Need.push_back(instance);
	}
}

void process::SetName(string newName)
{
	Name = newName;
}

void process::SetPass(bool t)
{
	pass = t;
}

vector<int> process::ReturnAllocation()
{
	return Allocation;
}

vector<int> process::ReturnMax()
{
	return Max;
}

vector<int> process::ReturnNeed()
{
	return Need;
}

string process::ReturnName()
{
	return Name;
}

bool process::ReturnPassAvailble()
{
	return pass;
}

void process::Print(int x)
{
	if (x = 1)
	{
		for (int i = 0; i < Allocation.size(); i++)
		{
			cout << Allocation[i] << "   ";
		}
		
		cout << endl;
	}

	else if (x = 2)
	{
		for (int i = 0; i < Max.size(); i++)
		{
			cout << Max[i] << "   ";
		}

		cout << endl;
	}

}