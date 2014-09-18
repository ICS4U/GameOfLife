/*ICS4U
  Mr. Creelman
  Game of Life program using allegro */
#include <iostream>
#include <apmatrix.h>
#include <allegro.h>
#include <fstream>

using namespace std;

#define Rows 20
#define Columns 50
#define SQUARE_SIZE 10
//const char ALIVE = 'x';
//const char DEAD = '.';
void grid_create();
void display(apmatrix <int> grid, int x, int y); //displays the results
void populator(apmatrix<int> &grid); //temporary function that populates the matrix randomly
void read_file(apmatrix<int> &grid); //reads in the data
int neighbor_check(apmatrix<int> &grid, int x, int y); //function that takes the coordinates on the grid and returns the number of living neighbors that cell has

int main(){
    BITMAP *buffer = NULL;
  
    //initialize 
    allegro_init(); 
    install_keyboard(); 
    install_timer();
   
    buffer = create_bitmap(640, 480);
	if (!buffer)
		return 1;
 
    srand(time(NULL));

    //initialize video mode to 640x480
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, COLUMNS*SQUARE_SIZE, ROWS*SQUARE_SIZE, 0, 0)) {
        allegro_message(allegro_error);
        return 1;
    }
	apmatrix<int> grid(Rows,Columns); //create the world
	
	//read_file();
	
	populator(apmatrix<int> grid); //populate the world
	
	grid_create();
	
	//this will go in a function at the end. The function will be looped by a key stroke for each generation.
	for(int x = 0; x < grid.numrows(); x++)
	{
		for(int y = 0; y < grid.numcols(); y++)
		{
			if (grid[x, y] == 1) //if there is a living thing in the spot
			{
				if(neighbor_check(grid, x, y) != 2 && neighbor_check(grid, x, y) != 3) //and it has too few or too many neighbors it will die
					grid[x, y] = 0; //kill it
			}
			else //if nothing lives here
			{
				if(neighbor_check(grid, x, y) == 3) //but there are 3 living neighbors
					grid[x, y] = 1; //give it life
			}
			display(grid, x, y);
			//rectfill(buffer, x1, y1, x2, y2, colour);
		}
	}
	
	
	
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

void read_file(){
  //read in the file here
  //use a structure i.e. Ap matrix
  //normal file i/o will work fine
  //read in the 'data' from a file, basically, run a for loop until eof 
  //and then have an if statement check for 'x' or '.', setting a live or dead value to the ap 
  //matrix
  //be carefull of the null value that it could read in before recognizing the eof
  ifstream infile("LIFE_CAT.DAT"); //creates filepointer
  if (!infile) 
  	cerr<<"unable to open file"<<endl;
  infile.open;
  while (!infile.eof){
  	for(int y = 0; y < ROWS; y++)
  	{
  		for(int x = 0; x < COLUMNS; x++)
        		cin >> grid[x , y] >> endl;
  	}
  }
  infile.close;
}

int neighbor_check(apmatrix<int> &grid, int x, int y){
	int neighbors = 0; //create a running total of neighbors variable

	if(grid[x, y+1] == 1) //if there is life to the right
		neighbors++;
	if(grid[x, y-1] == 1) //if there is life to the left
		neighbors++;
	if(grid[x+1, y] == 1) //above
		neighbors++;
	if(grid[x-1, y] == 1) //below
		neighbors++;
	if(grid[x+1, y+1] == 1) //northeast
		neighbors++;
	if(grid[x+1, y-1] == 1) //northwest
		neighbors++;
	if(grid[x-1, y+1] == 1) //southeast
		neighbors++;
	if(grid[x-1, y-1] == 1) //southwest
		neighbors++;
		
	return neighbors;
}


