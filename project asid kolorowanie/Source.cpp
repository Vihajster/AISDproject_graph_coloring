#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int main()
{
	int num_subsequent_lines;
	cin >> num_subsequent_lines;
	for (int i = 0; i < num_subsequent_lines; i++)
	{
		int num_vertices;
		string string_matrix;
		cin >> num_vertices;
		cin >> string_matrix;

		int** adjacency_matrix;

		adjacency_matrix = new int* [num_vertices];
		for (int i = 0; i < num_vertices; i++)
			adjacency_matrix[i] = new int[num_vertices];

		for (int i = 0; i < num_vertices; i++)
			for (int j = 0; j < num_vertices; j++)
			{
				adjacency_matrix[i][j] = string_matrix[i * num_vertices + j] - 48;
			}

	/*	for (int i = 0; i < num_vertices; i++)
		{
			for (int j = 0; j < num_vertices; j++)
				cout << adjacency_matrix[i][j];
			cout << endl;
		}*/
		bool complete_graph = true;
		bool cycle_graph = true;
		bool answer = false;

		for (int i = 0; i < num_vertices; i++)
		{
			int sum = 0;
			for (int j = 0; j < num_vertices; j++)
			{
				sum += adjacency_matrix[i][j];
			}

			if (sum < num_vertices - 1)
			{
				complete_graph = false;
				break;
			}			
		}
		if (complete_graph)
			answer = true;
		else if(num_vertices%2)  //
		{
			for (int i = 0; i < num_vertices; i++)
			{
				int sum = 0;
				for (int j = 0; j < num_vertices; j++)
				{
					sum += adjacency_matrix[i][j];					
				}
				if (sum != 2)
				{
					cycle_graph = false;
					break;
				}
			}
			if (cycle_graph)
				answer = true;
		}
			
		if (answer)
			cout << "True" << endl;
		else
			cout << "False" << endl;

	}
}