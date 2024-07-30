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


int main(){
		//local_stiffness_matrix();
		std::vector< std::vector<int>> new_matrix = local_stiffness_matrix(5);

		// Print the indentity matrix
		for (const auto& row: new_matrix) 
		{
			for (int element : row)
			{
				std::cout << element << " ";
			}
			std::cout << std::endl;

		}

	};