#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;



int** initMatrix(int x) {
	int** p_matrix = nullptr;
	p_matrix = new int* [(int)pow(2, x)];
	for (int i = 0; i < (int)pow(2, x); ++i) {
		p_matrix[i] = new int[(int)pow(2,13)];
	}
	return p_matrix;
}


void deleteMatrix(int** p_matrix, int column_size) {
	for (int i = 0; i < column_size; ++i)
		delete[] p_matrix[i];
	delete[] p_matrix;
}

void deleteMatrix(nanoseconds** p_matrix, int column_size) {
	for (int i = 0; i < column_size; ++i)
		delete[] p_matrix[i];
	delete[] p_matrix;
}


void fillMatrix1(int** p_matrix, int x) {
	for (int i = 0; i < (int)pow(2, x); ++i) {
		for (int j = 0; j < (int)pow(2,13); ++j) {
			p_matrix[i][j] = ((int)pow(2, 13 - x) * i + j) * 2;
		}
	}

}

void fillMatrix2(int** p_matrix, int x) {
	for (int i = 0; i < (int)pow(2, x); ++i) {
		for (int j = 0; j < (int)pow(2, 13); ++j) {
			p_matrix[i][j] = ((int)pow(2, 5 - x) * i * j) * 2;
		}
	}
}


//
//int binSearch(int* col_matrix, int target, int point_s, int point_f)
//{
//	while (point_s <= point_f)
//	{
//		if (col_matrix[(int)floor((point_f + point_s) / 2)] == target)
//			return (int)floor((point_f + point_s) / 2);
//		else if (col_matrix[(int)floor((point_f + point_s) / 2)] > target)
//			point_f = (int)floor((point_f + point_s) / 2) - 1;
//		else
//			point_s = (int)floor((point_f + point_s) / 2) + 1;
//	}
//	point_s == 0 ? ++point_s : 1;
//	return -point_s;
//}


nanoseconds binSearch2DMatrix(int** p_matrix, int x, int target) {

	int flag = -1;
	auto start = high_resolution_clock::now();
	for (int i = 0; i < (int)pow(2, x) && flag < 0; ++i)
	{
		int point_s = 0;
		int point_f = (int)pow(2, 13) - 1;
		while (point_s <= point_f && flag < 0)
		{
			p_matrix[i][(int)floor((point_f + point_s) / 2)] == target ?	flag = (int)floor((point_f + point_s) / 2):
			p_matrix[i][(int)floor((point_f + point_s) / 2)] > target ? point_f = (int)floor((point_f + point_s) / 2) - 1:
			point_s = (int)floor((point_f + point_s) / 2) + 1;
		}
	}
	auto stop = high_resolution_clock::now();
	return duration_cast<nanoseconds>(stop - start);
}


nanoseconds stepSearch2DMatrix(int** p_matrix, int x, int target) {

	int i = 0;
	int j = (int)pow(2,13) - 1;
	char flag = '0';
	auto start = high_resolution_clock::now();
	while (i < (int)pow(2, x) && j >= 0 && flag == '0')
	{
		p_matrix[i][j] != target ? p_matrix[i][j] > target ? --j : ++i : flag = '1';
	}
	auto stop = high_resolution_clock::now();
	return duration_cast<nanoseconds>(stop - start);
}

//int expSearch(int* col_matrix, int n, int target)
//{
//	int ind = 0;
//	while (col_matrix[ind] < target && ind < n)
//	{
//		ind != 0 ? ind *= 2 : ++ind;
//	}
//	ind >= n ? ind = n - 1 : 1;
//	ind = abs(binSearch(col_matrix, target, ind / 2, ind - 1));
//	return ind;
//}


nanoseconds expStepSearch2DMatrix(int** p_matrix, int x, int target) {

	int i = 0;
	int j = (int)pow(2,13) - 1;
	int flag = -1;
	auto start = high_resolution_clock::now();
	while (i < pow(2, x) && j >= 0 && flag == -1)
	{
		if ((p_matrix[i][j] < target) && ((int)pow(2, x) - i > 1)) {
			while (i < (int)pow(2, x) && p_matrix[i][j] < target)
			{
				i != 0 ? i *= 2 : ++i;
			}
			i >= (int)pow(2, x) ? i = (int)pow(2, x) - 1 : 1;
			int point_s = i / 2;
			int point_f = i - 1;
			while (point_s <= point_f && flag < 0)
			{
				p_matrix[(int)floor((point_f + point_s) / 2)][j] == target ? i = (int)floor((point_f + point_s) / 2), flag = 1:
				p_matrix[(int)floor((point_f + point_s) / 2)][j] > target ? point_f = (int)floor((point_f + point_s) / 2) - 1 :
											point_s = (int)floor((point_f + point_s) / 2) + 1;
			}			
			i = point_s;
		}
		if (p_matrix[i][j] != target) {
			if (p_matrix[i][j] < target) {
				break;
			}
			else
				--j;
		}
		else flag = i;
	}
	auto stop = high_resolution_clock::now();
	return duration_cast<nanoseconds>(stop - start);
}


int main()
{
	nanoseconds** time_table1 = new nanoseconds * [2];
	nanoseconds** time_table2 = new nanoseconds * [2];
	nanoseconds** time_table3 = new nanoseconds * [2];
	for (int i = 0; i < 2; ++i) {
		time_table1[i] = new nanoseconds[13];
		time_table2[i] = new nanoseconds[13];
		time_table3[i] = new nanoseconds[13];
	}
	auto time = high_resolution_clock::now();
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 13; ++j) {
			time_table1[i][j] = duration_cast<nanoseconds>(time - time);
			time_table2[i][j] = duration_cast<nanoseconds>(time - time);
			time_table3[i][j] = duration_cast<nanoseconds>(time - time);
		}

	for (int x = 1; x <= 13; ++x)
	{
		int** matrix = initMatrix(x);
		// The first type of generation of a matrix
		fillMatrix1(matrix, x);
		int target = 2 * (int)pow(2, 13) + 1;
		// Run algorithms for 100 times to get more accurate (average) time 
		for (int i = 0; i < 100; ++i) { 
			time_table1[0][x - 1] += binSearch2DMatrix(matrix, x, target);
			time_table2[0][x - 1] += stepSearch2DMatrix(matrix, x, target);
			time_table3[0][x - 1] += expStepSearch2DMatrix(matrix, x, target);
		}
		// The second type of generation of a matrix
		fillMatrix2(matrix, x);
		target = 16 * (int)pow(2,13) + 1;
		// Run algorithms for 100 times to get more accurate (average) time 
		for (int i = 0; i < 100; ++i) {
			time_table1[1][x - 1] += binSearch2DMatrix(matrix, x, target);
			time_table2[1][x - 1] += stepSearch2DMatrix(matrix, x, target);
			time_table3[1][x - 1] += expStepSearch2DMatrix(matrix, x, target);
		}

		deleteMatrix(matrix, (int)pow(2, x));
	}
	// Enter the results
	cout << "Runtime of the first algorithm\nFor the first and second generation\n";
	for (int i = 0; i < 13; ++i) {
		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(time_table1[0][i]/100).count() << ' ' <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(time_table1[1][i]/100).count() << ' '<<" ns\n";
	}cout << "Runtime of the second algorithm\nFor the first and second generation\n";
	for (int i = 0; i < 13; ++i) {
		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(time_table2[0][i]/100).count() << ' ' <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(time_table2[1][i]/100).count() << ' ' << " ns\n";
	}
	cout << "Runtime of the third algorithm\nFor the first and second generation\n";
	for (int i = 0; i < 13; ++i) {
		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(time_table3[0][i]/100).count() << ' ' <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(time_table3[1][i]/100).count() << ' ' << " ns\n";
	}

	deleteMatrix(time_table1, 2);
	deleteMatrix(time_table2, 2);
	deleteMatrix(time_table3, 2);
	return 0;
}