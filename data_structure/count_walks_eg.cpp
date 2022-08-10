// C++ program to count walks from
// u to v with exactly k edges
#include <iostream>
using namespace std;

// Number of vertices in the graph
#define V 4

// A Dynamic programming based function to count walks from u
// to v with k edges
int countwalks(int graph[][V], int u, int v, int k)
{
	// Table to be filled up using DP.
	// The value count[i][j][e] will
	// store count of possible walks from
	// i to j with exactly k edges
	int count[V][V][k + 1];

	// Loop for number of edges from 0 to k
	for (int e = 0; e <= k; e++) {
		for (int i = 0; i < V; i++) // for source
		{
			for (int j = 0; j < V; j++) // for destination
			{
				// initialize value
				count[i][j][e] = 0;

				// from base cases
				if (e == 0 && i == j) // -> distance of go to itself = 0 
					count[i][j][e] = 1;

				if (e == 1 && graph[i][j]) // i can access j
					count[i][j][e] = 1;

				// go to adjacent only when the
				// number of edges is more than 1
				if (e > 1) {
					for (int a = 0; a < V; a++) // adjacent of source i
						if (graph[i][a]) // if i can access a 
							count[i][j][e] += count[a][j][e - 1]; 
                        // if a can access j, that means i can access j 
                        //In this case, it focus on the possibility of i reach j passing more than one edge
				}
			}
		}
	}
    cout << "Count[4][4][3]:" << "{" << endl << endl;
    for(int c = 0; c < 4; c++){
        cout << "{    ";
        for(int d = 0; d < 4; d++){
            cout << "{ ";
            for(int z = 0; z <= 2; z++){
                cout << count[c][d][z];
                if(z != 2)
                    cout << ", ";
            }
            cout << " }";
            if(d != 3)
                cout << ", ";
        }
        cout << "    }, " << endl;
    }
    cout << endl << "}";

	return count[u][v][k];
}

// driver program to test above function
int main()
{
	/* Let us create the graph shown in above diagram*/
	int graph[V][V] = { { 0, 1, 1, 1 },
						{ 0, 0, 0, 1 },
						{ 0, 0, 0, 1 },
						{ 0, 0, 0, 0 } };
	int u = 0, v = 3, k = 2;
    cout << endl;
	cout << countwalks(graph, u, v, k);
	return 0;
}
