/*	The Pruefer Correspondence
**  
**	Amanda Rohn, March 2001
**
**	Based on Assignment #7 for the Monday 3:30 recitation of ENGR 131.
**	This full version incorporates dynamic memory allocation so that
**	the size of the tree is not fixed at compile-time.  Full error-checking
**	is also included.
**
**	Full documentation available at http://home.cwru.edu/~aer8/pruefer.html
*/

#include <iostream>
#include <climits>

using std::cin;
using std::cout;
using std::endl;

int GetInteger(const char* prompt, int min, int max, const char* err_msg = "");
void GetTree(bool ** T, int vertices);
void MakeS(bool ** T, int * S, int vertices);
void MakeT(bool ** T, int * S, int vertices);
void ShowTree(bool ** T, int vertices);
void ShowS(int * S, int vertices);
int Find(int n, int * a, int size);

int main()
{
	for(;;)
	{

	cout << "This program can:\n"
		 << "1. Find the Pruefer Code for a given tree\n"
		 << "2. Find the tree with a given Pruefer Code\n";

	int choice = GetInteger("Enter your choice (0 to quit)", 0, 2);

	if(choice == 0)
		break;

	else if(choice == 1)
	{
		try		// if the user enters something that's not a tree, it's easier to wait
		{		// for the resultant crash than it is to prevent such an entry.

			int vertices = GetInteger("\nHow many vertices does your tree have?", 3, INT_MAX,
							"Only trees with three or more vertices have a Pruefer code.");
	
			// Create two-dimensional array representation of a tree
			// (This tree is specified by the user)

			bool ** T1 = new bool* [vertices + 1];
	
			for(int i = 1; i < vertices + 1; i++)
			{
				T1[i] = new bool[vertices + 1];
				for(int j = 1; j < vertices + 1; j++)
					T1[i][j] = false;
			};

			// Array to hold the Pruefer Code, S
	
			int * S = new int[vertices];
			for(i = 0; i < vertices; i++)
				S[i] = 0;

			// Get the tree from the user, then create and display S

			GetTree(T1, vertices);
			ShowTree(T1, vertices);

			MakeS(T1, S, vertices);
			ShowS(S, vertices);
		}
		catch(...) 
		{
			cout << "\nThe graph you entered was not a tree, so it has no Pruefer Code.\n\n";
			continue;
		}
	}

	else if(choice == 2)
	{
		int vertices = 2 + GetInteger("\nHow many entries are in the Pruefer Code?", 0, INT_MAX);

		// Create S (holds the Pruefer Code)

		int * S = new int[vertices];
		S[0] = S[vertices-1] = 0;
		cout << "Enter the numbers in the Pruefer Code at the prompts:\n";
		for(int i = 1; i < vertices-1; i++)
		{
			cout << i << ' ';
			S[i] = GetInteger("Entry", 0, vertices);
		}

		// Create two-dimensional array representation of a tree
		// (This is the tree that's created by the algorithm)

		bool ** T2 = new bool* [vertices + 1];
	
		for(i = 1; i < vertices + 1; i++)
		{
			T2[i] = new bool[vertices + 1];
			for(int j = 1; j < vertices + 1; j++)
				T2[i][j] = false;
		}
		
		// Create and display the new tree

		MakeT(T2, S, vertices);

		ShowTree(T2, vertices);
	}

	cout << endl;

	}

	return 0;
}


int GetInteger(const char* prompt, int min, int max, const char* err_msg)
{
	int num;

	for(;;)
	{
		cout << prompt << ": ";
		cin >> num;
		if(cin.fail() || cin.peek() != '\n' || num < min || num > max)
		{
			cin.clear();
			cin.ignore(1024,'\n');
			cout << err_msg << endl;
			cout << "Please enter only an integer between " << min << " and " << max << endl;
		}
		else break;
	}
	cin.ignore(1024, '\n');
	return num;
}


void GetTree(bool ** T, int vertices)
{
	cout << "Please enter the " << vertices-1 << " edges of your tree, one at a time.\n";

	int i, j;	//the vertices on each edge

	for(int x = 1; x < vertices; x++)	//ask for n-1 edges
	{
		cout << "\nEdge #" << x << '\n';
		i = GetInteger("First Vertex", 1, vertices);
		j = GetInteger("Second Vertex", 1, vertices);

		if(i == j)				// this graph is not a tree
		{
			cout << "A graph is not a tree if a vertex is connected to itself. Try again.";
			x--;
			continue;	//try again for input
		}
		else if(T[i][j])		// this edge has already been entered
		{
			cout << "You have already entered this edge.  In a tree, each edge is unique. Try again.";
			x--;
			continue;	// try again for input
		}

		//add this edge

		T[i][j] = true;			//edges are bidirectional
		T[j][i] = true;
	}
}


void MakeS(bool ** T, int * S, int vertices)
{
	int smallest, adj;

	for(int x = 1; x <= vertices-2; x++)
	{
		// 1. find vertex of degree one with smallest label
		int degree;

		for(smallest = 1; smallest <= vertices; smallest++)	//start checking row (vertex) 1
		{
			degree = 0;

			for(int j = 1; j <= vertices; j++)
			{
				if(T[smallest][j])
				{
					adj = j;	//most recently seen adjacent vertex
					degree++;
				}
			}

			if(degree == 1)		//if this vertex has degree one, move to next step
				break;
		}

		// 2. make the vertex adjacent to the vertex in (1) the next term in S

		S[x] = adj;

		// 3. Remove the vertex in (1) and its adjacent edge from T
		
		for(int j = 1; j <= vertices; j++)
		{
			T[smallest][j] = false;
			T[j][smallest] = false;
		}

		// 4. Repeat until there are two vertices left (taken care of by main for-loop)
	}
}


void MakeT(bool ** T, int * S, int vertices)
{
	int smallest;
	int first;

	int i,j;	//counting variables
		
	// 1. Draw vertices, labelled 1,2,...,(vertices) (this is the tree, T)
	//	  Make a list 1,2,...,(vertices)

	bool * list = new bool[vertices + 1];
	list[0] = false;
	for(int y = 1; y <= vertices; y++)
		list[y] = true;

	for(int x = 0; x < vertices-2; x++)
	{
		// 2a. Find the smallest number which is in the list but not in S

		for(int i = 1; i <= vertices; i++)
		{
			if( list[i] && (Find(i, S, vertices) == -1))	//if i is in the list and not in S
			{
				smallest = i;
				list[smallest] = false;		// 3. Remove it from the list
				break;
			}
		}

		// 2b. Find the first number in S

		for(i = 0; i < vertices; i++)
		{
			if(S[i] != 0)
			{
				first = S[i];
				S[i] = 0;		// 3. Remove it from S
				break;
			}
		}

		// 2c. Join the numbers from (2a) and (2b)

		T[smallest][first] = true;
		T[first][smallest] = true;

		// 4a. Repeat until there are only two numbers left on the list
		//	   (taken care of by the main for-loop)
	}

	// 4b. Join the last two vertices on the list

	int a, b;	//the two numbers

	for(i = 1; i <= vertices; i++)	//go through the list
	{
		if(list[i])				//look for one that's still there
		{
			a = i;				//assign it to a
			break;
		}
	}
	for(j = 1; j <= vertices; j++)	//go through again
	{
		if(a != j && list[j])	//look for the other one
		{
			b = j;
			break;
		}
	}

	T[a][b] = true;
	T[b][a] = true;
}

void ShowTree(bool ** T, int vertices)
{
	cout << "\nThe tree is given by the following matrix:\n\n    ";

	int i,j;	//counters

	for(i = 1; i <= vertices; i++)
		cout << i << "  ";

	cout << "\n\n";

	for(i = 1; i <= vertices; i++)
	{
		cout << i << "   ";
		for(j = 1; j <= vertices; j++)
			cout << T[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}
	

void ShowS(int * S, int vertices)
{
	cout << "\nThe Pruefer Code is ( ";

	for(int i = 1; i < vertices-1; i++)
		cout << S[i] << " ";

	cout << ")\n";
}

int Find(int n, int * a, int size)
// if n is in the array a, returns the index at which it first appears
// if n is not in the array, returns -1
{
	for(int i = 0; i < size; i++)
	{
		if(a[i] == n)
		{
			return i;
		}
	}

	return -1;
}
		
