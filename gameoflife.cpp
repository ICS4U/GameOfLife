/*ICS4U
  Mr. Creelman
  Game of Life program using allegro */
#include <iostream>
#include <iostream>
#include <apmatrix>
#include <allegro.h>

using namespace std;

#define Rows 48
#define Columns 64

void populator(apmatrix<int> &a); //temporary function that populates the matrix randomly
void read_file();
void grid_create();
void neighbor_check();
bool alive_check();
void birth();

int main(){
	apmatrix<int> grid(Rows,Columns); //create the world
	
	populator(apmatrix<int> grid); //populate the world
	
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
