// Code to solve finite element problem for bar element

// Author: PUNEETHA KUMAR D
//MTech in Mechanical Engineering IISc Bangalore
// Date: 29/ 07 / 2024



#include<iostream>
#include<vector>


// Local stiffness matrix for bar element
std::vector < std::vector<int>> local_stiffness_matrix(int size)
{
	std::vector<std::vector<int>> matrix(size, std::vector<int>(size, 0));

	for (int i = 0; i < size; i++)
	{
		matrix[i][i] = 1;
		if (i != size-1)
		{
			matrix[i][i + 1] = -1;
		}
		
		if (i != 0)
		{
			matrix[i][i - 1] = -1;
		}
	}
	return matrix;
}

// Function to Global stiffness matrix for bar element

std:: 

/*int local_stiffness_matrix()
{
	// Declare 2D array
	void stiffness_matrix[2][2];

	for (int i = 0; i < 2; i++) 
	{
		for (int j = 0; j < 2; j++) 
		{
			if (i == j) 
			{
				stiffness_matrix[i][j] = 1;
			}
			if (j == i + 1 || j == i - 1) 
			{
				stiffness_matrix[i][j] = -1;
			}
			else 
			{
				stiffness_matrix[i][j] = 0;

			}

		}

	}
	return stiffness_matrix;
}
*/


int main()
{

	//local_stiffness_matrix();
	
	// For bar element n is 2 for local stiffness matrix
	int n; 
	n = 2;  

	// Local striffness matrix
	std::vector< std::vector<int>> new_matrix = local_stiffness_matrix(n);
	
	// Print the  Local striffness matrix
	for (const auto& row: new_matrix) 
	{
		for (int element : row)
		{
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}

	// Global Stiffness matrix
	/*
	Global stiffness matrix is obtained by assembling the local stiffness matrix for each element.
	
	The dimension of global stiffness matrix depends on number of nodes in whole 
	model and in degrees of freedom of each element.

	size of globle stiffness matrix = Number of nodes in model *  degrees of freedom of each element */

	int number_of_nodes_in_model = 2;
	int Degrees_of_freedom_of_each_element = 1; // For bar element the displacement specifies the state of node. 

	int size_of_global_stiffness_matrix = number_of_nodes_in_model * Degrees_of_freedom_of_each_element;
	std::vector <std::vector<int>> Global_stiffness_matrix = Formation_of_global_stiffness_matrix(size_of_global_stiffness_matrix, local_stiffness_matrix);

	};