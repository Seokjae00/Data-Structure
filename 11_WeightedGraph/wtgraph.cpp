//--------------------------------------------------------------------
//
//  Laboratory 13                                          wtgraph.cpp
//
//  Implementation of the Weighted Graph ADT
//
//--------------------------------------------------------------------
#include "wtgraph.h"

//--------------------------------------------------------------------

WtGraph::WtGraph(int maxNumber)
	: maxSize(maxNumber), size(0)
{
	vertexList = new Vertex[maxSize];
	adjMatrix = new int[maxSize * maxSize];
	pathMatrix = new int[maxSize * maxSize];

	for (int i = 0; i < maxSize * maxSize; i++)
	{
		adjMatrix[i] = infiniteEdgeWt;
		pathMatrix[i] = infiniteEdgeWt;
	}
}

WtGraph::~WtGraph()
{
	delete[] vertexList;
	delete[] adjMatrix;
	delete[] pathMatrix;
}

//--------------------------------------------------------------------

int WtGraph::getIndex(char* v)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(vertexList[i].label, v) == 0) return i;
	}

	return -1;
}

int WtGraph::getEdge(int row, int col)
{
	return adjMatrix[row * maxSize + col];
}

void WtGraph::setEdge(int row, int col, int wt) 
{
	adjMatrix[row * maxSize + col] = wt;
}

//--------------------------------------------------------------------

void WtGraph::insertVertex(Vertex newVertex)
{
	if (isFull())
		cout << "Failed -- Graph is full" << endl;
	else
	{
		int index = getIndex(newVertex.label);
		if (index == -1)
			vertexList[size++] = newVertex;
		else
			vertexList[index] = newVertex;
	}
}

void WtGraph::insertEdge(char* v1, char* v2, int wt)
{
	int row = getIndex(v1);
	int col = getIndex(v2);

	if (row == -1 || col == -1)
		cout << "Either v1 and v2 does Not exist" << endl;
	else
	{
		setEdge(row, col, wt);
		setEdge(col, row, wt);
	}
}

//--------------------------------------------------------------------

bool WtGraph::retrieveVertex(char* v, Vertex& vData)
{
	if (getIndex(v) == -1)
		return false;
	else
	{
		vData = vertexList[getIndex(v)];
		return true;
	}
}

bool WtGraph::getEdgeWeight(char* v1, char* v2, int& wt)
{
	int row = getIndex(v1);
	int col = getIndex(v2);

	if (getEdge(row, col) != infiniteEdgeWt)
	{
		wt = adjMatrix[row * maxSize + col];
		return true;
	}
	else
		return false;
}

//--------------------------------------------------------------------

void WtGraph::removeVertex(char* v)
{
	int index = getIndex(v);

	if (index == -1)
		cout << "Vertex does Not exist" << endl;
	else
	{
		for (int i = index; i < size - 1; i++)
			vertexList[i] = vertexList[i + 1];

		for (int i = 0; i < size; i++)
			for (int j = index; j < size - 1; j++)
				setEdge(i, j, getEdge(i, j + 1));

		for (int i = 0; i < size; i++)
			for (int j = index; j < size - 1; j++)
				setEdge(j, i, getEdge(j + 1, i));
		
		--size;
	}
}

void WtGraph::removeEdge(char* v1, char* v2)
{
	int row = getIndex(v1);
	int col = getIndex(v2);

	if (row == -1 || col == -1)
		cout << "Either v1 and v2 does Not exist" << endl;
	else
	{
		setEdge(row, col, infiniteEdgeWt);
		setEdge(col, row, infiniteEdgeWt);
	}
}

//--------------------------------------------------------------------

void WtGraph::clear()
{
	size = 0;

	for (int i = 0; i < maxSize * maxSize; i++)
	{
		adjMatrix[i] = infiniteEdgeWt;
		pathMatrix[i] = infiniteEdgeWt;
	}
}

bool WtGraph::isEmpty() const
{
	return (size == 0);
}

bool WtGraph::isFull() const
{
	return (size == maxSize);
}

//--------------------------------------------------------------------

void WtGraph::showStructure()
{
	int wt,         // Edge weight
		row, col;   // Loop counters

	if (size == 0)
		cout << "Empty graph" << endl;
	else
	{
		cout << endl << "Vertex list : " << endl;
		for (row = 0; row < size; row++)
			cout << row << '\t' << vertexList[row].label << endl;

		cout << endl << "Edge matrix : " << endl << '\t';
		for (col = 0; col < size; col++)
			cout << col << '\t';
		cout << endl;
		for (row = 0; row < size; row++)
		{
			cout << row << '\t';
			for (col = 0; col < size; col++)
			{
				wt = getEdge(row, col);
				if (wt == infiniteEdgeWt)
					cout << "- \t";
				else
					cout << wt << '\t';
			}
			cout << endl;
		}

		cout << endl << "Path matrix : " << endl << '\t';
		for (col = 0; col < size; col++)
			cout << col << '\t';
		cout << endl;
		for (row = 0; row < size; row++)
		{
			cout << row << '\t';
			for (col = 0; col < size; col++)
			{
				wt = getPath(row, col);
				if (wt == infiniteEdgeWt)
					cout << "- \t";
				else
					cout << wt << '\t';
			}
			cout << endl;
		}
	}
}

//--------------------------------------------------------------------

// In-lab 1 functions
int WtGraph::getPath(int row, int col)
{
	return pathMatrix[row * maxSize + col];
}

void WtGraph::setPath(int row, int col, int wt)
{
	pathMatrix[row * maxSize + col] = wt;
}

void WtGraph::computePaths() 
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				pathMatrix[i * maxSize + j] = 0;
			else
				pathMatrix[i * maxSize + j] = adjMatrix[i * maxSize + j];
		}
	}

	for (int m = 0; m < size; m++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				int path1 = getPath(j, m);
				int path2 = getPath(m, k);
				int totalpath = getPath(j, k);

				if (path1 != infiniteEdgeWt && path2 != infiniteEdgeWt && (path1 + path2) < totalpath)
				{
					setPath(j, k, path1 + path2);
					setPath(k, j, path1 + path2);
				}
			}
		}
	}
}