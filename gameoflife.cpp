/*ICS4U
  Mr. Creelman
  Game of Life program using allegro */
#include <iostream>
#include <apmatrix.h>
#include <allegro.h>

using namespace std;

#define Rows 48
#define Columns 64

void populator(apmatrix<int> &a); //temporary function that populates the matrix randomly
void read_file();
void grid_create();
int neighbor_check(apmatrix<int> &a, int x, int y); //function that takes the coordinates on the grid and returns the number of living neighbors that cell has
bool alive_check(apmatrix<int> &a, int x, int y); //function that determines whether the cell with the specified coordinates is alive or dead

int main(){
	apmatrix<int> grid(Rows,Columns); //create the world
	
	populator(apmatrix<int> grid); //populate the world
	
	//this will go in a function at the end. The function will be looped by a key stroke for each generation.
	for(int x = 0; x < grid.numrows(); x++)
	{
		for(int y = 0; y < grid.numcols(); y++)
		{
			if(neighbor_check(grid, x, y) == 2 || neighbor_check(grid, x, y) == 3 )
			{
				
			}
		}
	}

	/*BITMAP *buffer=NULL;
  
  //allegro initialisation
  allegro_init();
  
  //read_file();
  grid_create();
  neighbor_check();
  alive_check();
  birth();*/
  return 0;
}

void populator(apmatrix<int> &grid){
	for(int x = 0; x < grid.numrows(); x++)
	{
		for(int y = 0; y < grid.numcols(); y++)
		{
			grid[x, y] = rand() % 1; //seed all parts of the matrix with pseudo-random boolean 'alive's or 'dead's
			cout << grid[x, y] << " ";
		}
		cout << endl;
	}
}

/*void read_file(){
  //read in the file here
  //use a structure i.e. Ap matrix
}*/

void grid_create(){
  //create the grid
  //apmatrix<int> grid(Rows,Columns);
  int nRows,nCols,row,col;
  nRows= grid.numrows();
  nCols= grid.numcols();
  //fill in the grid based on the file read in earlier
  return 0;
}

void neighbor_check(){
  if()
}
