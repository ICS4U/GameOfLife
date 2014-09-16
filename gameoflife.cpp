/*ICS4U
  Mr. Creelman
  Game of Life program using allegro */
#include <iostream>
#include <iostream>
#include <allegro.h>

using namespace std;

#define Rows 48
#define Columns 64

apmatrix<int> grid(Rows,Columns);

void read_file();
void grid_create();
void neighbor_check();
bool alive_check();
void birth();

int main(){
  BITMAP *buffer=NULL;
  
  //allegro initialisation
  allegro_init();
  
  read_file();
  grid_create();
  neighbor_check();
  alive_check();
  birth();
  return 0;
}

void read_file(){
  //read in the file here
  //use a structure i.e. Ap matrix
}

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
