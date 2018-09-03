#include <iostream>
#include <array>
using std::cout;
using std::endl;
using std::array;

//WIDTH and HEIGHT should be odd numbers
const int WIDTH = 9;
const int HEIGHT = 9;
const int EXPANDEDWIDTH = (WIDTH*2-1);
const int EXPANDEDHEIGHT = (HEIGHT*2-1);
/*
array<array<int, EXPANDEDWIDTH>,EXPANDEDHEIGHT> randomize (const array<array<int, EXPANDEDWIDTH>,EXPANDEDHEIGHT> &eg)
{
	return &eg;
}
*/

array<array<int,EXPANDEDWIDTH>,EXPANDEDHEIGHT> randomize (array<array<int,EXPANDEDWIDTH>,EXPANDEDHEIGHT> connectorGrid)
{
	for(int i = 0; i < EXPANDEDHEIGHT; i++)
	{
		for(int j = 0; j < EXPANDEDWIDTH; j++)
		{
			connectorGrid[i][j] = (i%2 == 0) ? ((j%2 == 0) ? 0 : 1) : ((j%2 == 0) ? 1 : 0);
		}
	}
	return connectorGrid;
}

array<array<int,WIDTH>,HEIGHT> collapse (array<array<int, EXPANDEDWIDTH>,EXPANDEDHEIGHT> tempGrid)
{
	array<array<int,WIDTH>,HEIGHT> collapsed = {0};
	int iCount = 0, jCount = 0;
	for(int i = 0; i < EXPANDEDHEIGHT; i += 2)
	{	
		for(int j = 0; j < EXPANDEDWIDTH; j += 2)
		{
			//collapsed[iCount][jCount] = -1;
			if(i > 0 && tempGrid[i-1][j] == 1)//should not be error if c++ short circuits
				collapsed[iCount][jCount] += 1;
			if(j < (EXPANDEDWIDTH-1) && tempGrid[i][j+1] == 1)
				collapsed[iCount][jCount] += 2;
			if(i < (EXPANDEDHEIGHT-1) && tempGrid[i+1][j] == 1)
				collapsed[iCount][jCount] += 5;
			if(j > 0 && tempGrid[i][j-1] == 1)
				collapsed[iCount][jCount] += 10;
			++jCount;
		}
		jCount = 0;
		++iCount;
	}
	return collapsed;
}

void printExArray(array<array<int,EXPANDEDWIDTH>,EXPANDEDHEIGHT> arr)
{
	for(int i = 0; i < EXPANDEDHEIGHT; i++)
	{
		for(int j = 0; j < EXPANDEDWIDTH; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void printCoArray(array<array<int,WIDTH>,HEIGHT> arr)
{
	for(int i = 0; i < HEIGHT; i++)
	{
		for(int j = 0; j < WIDTH; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{	
	array<array<int, EXPANDEDWIDTH>,EXPANDEDHEIGHT> expandedGrid = {0};
	array<array<int,WIDTH>,HEIGHT> collapsedGrid = {0};
//	expandedGrid = randomizeEG(expandedGrid);

	printExArray(expandedGrid);

	expandedGrid = randomize(expandedGrid);
	cout << "" << endl;
	printExArray(expandedGrid);
	
	cout << endl;
	printCoArray(collapsedGrid);

	collapsedGrid = collapse(expandedGrid);
	cout << endl;
	printCoArray(collapsedGrid);
}


