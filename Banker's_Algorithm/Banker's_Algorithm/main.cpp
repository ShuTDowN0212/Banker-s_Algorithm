#include "process.h"

void Bankers_Algorithm(int, int, vector<process>);

void Bankers_Algorithm(int Process_Count, int Resources_Count,  vector<process> l)
{
	vector<int> Resources_Instances;
	vector<int> Available;
	vector<process> Result;
	cout << "=== Setting Resources's Instance ===" << endl;
	for (int i = 0; i < Resources_Count; i++)
	{
		int instance = 0;
		cout << "Enter the Instance of the Resource : ";
		cin >> instance;
		cout << "R" << i + 1 << " has " << instance << "instances." << endl;
		Resources_Instances.push_back(instance);
	}
	
	cout << "=== Setting Processes' Allocation, Max, Available ===" << endl;
	for (int i = 0; i < Process_Count; i++)
	{
		process newp;
		cout << "Process " << i << endl;
		newp.SetMax(Resources_Instances);
		newp.SetAllocation(Resources_Instances);
		newp.SetNeed();
		newp.SetName("Process" + to_string(i));
		l.push_back(newp);
	}
	
	for (int i = 0; i < Resources_Count; i++)
	{
		int instance = 0;
		int TotalInstance = 0;
		for (int j = 0; j < Process_Count; j++)
		{
			vector<int> Temp_Allocation = l[j].ReturnAllocation();
			TotalInstance += Temp_Allocation[i];
		}
		instance = Resources_Instances[i] - TotalInstance;
		Available.push_back(instance);
	}

	//=== Using Bankers Algorithm ===
	while (Result.size() != Process_Count)
	{
		for (int i = 0; i < Process_Count; i++)
		{
			bool confirmed = true;
			vector<int> Temp_Need = l[i].ReturnNeed();
			vector<int> Temp_Allocation = l[i].ReturnAllocation();
			vector<int> Temp_Max = l[i].ReturnMax();
			
			for (int k = 0; k < Resources_Count; k++)
			{
				if (Temp_Need[k] > Available[k])
				{
					confirmed = false;
				}
			}

			if (l[i].ReturnPassAvailble() == false && confirmed == true)
			{
				l[i].SetPass(true);
				for (int j = 0; j < Resources_Count; j++)
				{
					Available[j] += Temp_Allocation[j];
				}
				Result.push_back(l[i]);
			}
		}
	}

	cout << "=== Result ===" << endl;
	for (int i = 0; i < Result.size(); i++)
	{
		cout << Result[i].ReturnName() << "   ";
	}
}

int main()
{
	int Total_Process = 0;
	int Total_Resources = 0;
	vector<process> snapshot;
	cout << "Enter the Number of the Processes : ";
	cin >> Total_Process;
	cout << "Enter the Number of the Resources : ";
	cin >> Total_Resources;
	cout << endl;

	Bankers_Algorithm(Total_Process, Total_Resources, snapshot);
	return 0;
}