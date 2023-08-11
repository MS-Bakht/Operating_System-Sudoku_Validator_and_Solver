//|=======================================|
//| Member 1: Shayan Bakht                |
//| Member 2: Qasim Khan                  |
//| AI-K      Project-OS                  |
//|=======================================|

#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
using namespace std;
// Using semaphore 
sem_t sem ;
//===========================================| Functions For Grids |===========================================
// making main and subgrids
int main_grid[9][9], sub_grid_1[9], sub_grid_2[9], sub_grid_3[9], sub_grid_4[9],
    sub_grid_5[9], sub_grid_6[9], sub_grid_7[9], sub_grid_8[9], sub_grid_9[9];

//for checking 
//int results_row,results_col, results_subGrid[9];
bool final_results_part1[11]; //Combining the above commented variables into a single array

// Displaying the main grid of size 9x9
void main_grid_display() {
  cout << "|===========================|" << endl;
  cout << "|   Display Main Grid       |" << endl;
  cout << "|===========================|" << endl;
  for (int row = 0; row < 9; row++) {
    cout << "|";
    for (int col = 0; col < 9; col++) {
      cout << " " << main_grid[row][col] << " ";
    }
    cout << "|" << endl;
  }
  cout << "|===========================|" << endl;
}

// Generating a perfect Sudoku grid
void generate_main_grid_correct() {
  int perfect_grid[9][9] = {
      {3, 7, 9, 2, 4, 5, 8, 6, 1}, {2, 8, 5, 3, 6, 1, 9, 7, 4},
      {1, 6, 4, 9, 7, 8, 2, 3, 5}, {9, 5, 8, 6, 3, 4, 1, 2, 7},
      {4, 3, 7, 1, 9, 2, 6, 5, 8}, {6, 2, 1, 8, 5, 7, 4, 9, 3},
      {7, 9, 2, 4, 1, 3, 5, 8, 6}, {8, 4, 3, 5, 2, 6, 7, 1, 9},
      {5, 1, 6, 7, 8, 9, 3, 4, 2}};

  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      main_grid[row][col] = perfect_grid[row][col];
    }
  }
}

// Generating an im perfect Sudoku grid
void generate_main_grid_incorrect() {
  int imperfect_grid[9][9] = {
      {3, 7, 3, 2, 4, 5, 8, 6, 1}, 
      {2, 8, 5, 3, 6, 1, 9, 7, 4},
      {1, 6, 4, 9, 7, 8, 2, 3, 5}, 
      {9, 5, 8, 6, 3, 4, 1, 2, 7},
      {4, 3, 7, 1, 9, 2, 6, 5, 8}, 
      {6, 2, 1, 8, 5, 7, 4, 9, 3},
      {7, 9, 2, 4, 1, 3, 5, 8, 6}, 
      {8, 4, 3, 5, 2, 6, 7, 1, 9},
      {5, 1, 6, 7, 8, 9, 3, 4, 2}};

  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      main_grid[row][col] = imperfect_grid[row][col];
    }
  }
}
// making an input grid function
void input_main_grid() {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      cout << "Enter Position [" << row + 1 << "][" << col + 1 << "]";
      cin >> main_grid[row][col];
      cout << endl;
    }
  }
  cout << "The grid is set!" << endl;
}

//Displaying the start menu 
void display_starting_menu() {
  cout << "|===================================|" << endl;
  cout << "|   Welcome To Sudoku Validation    |" << endl;
  cout << "|===================================|" << endl;
  cout << "|Press 1 - Generate correct grid    |" << endl;
  cout << "|Press 2 - Generate incorrect grid  |" << endl;
  cout << "|Press 3 - Input grid               |" << endl;
  cout << "|===================================|" << endl;
}

//Innitiating the subgrids using the main grid
void fill_sub_grid_arrays()
{
    //first taking the first three rows for the first 3 sub grids
    int row_lower_limit = 0;
    int row_upper_limit = 2;  
    //selecting cols for the first grid
    int col_lower_limit = 0;
    int col_upper_limit = 2;
    //counter for the sub grid 
    int counter = 0;

    //Initiating the first grid
    for(int row = row_lower_limit; row <= row_upper_limit; row++ )
    {
        for( int col = col_lower_limit; col <= col_upper_limit; col++)
        {
            sub_grid_1[counter] = main_grid[row][col];
            counter++;
        }
    }

    //row limits would be same three grids, but the cols would change
    col_lower_limit = 3;
    col_upper_limit = 5;
    counter = 0;
    //initiating the second grid
    for(int row = row_lower_limit; row <= row_upper_limit; row++ )
    {
        for( int col = col_lower_limit; col <= col_upper_limit; col++)
        {
            sub_grid_2[counter] = main_grid[row][col];
            counter++;
        }
    }

    //changing cols for 3third grid again 
    col_lower_limit = 6;
    col_upper_limit = 8;
    counter = 0;
    //initiating the third grid
    for(int row = row_lower_limit; row <= row_upper_limit; row++ )
    {
        for( int col = col_lower_limit; col <= col_upper_limit; col++)
        {
            sub_grid_3[counter] = main_grid[row][col];
            counter++;
        }
    }

    //Now initiating grid 4,5,6 
    row_lower_limit = 3;
    row_upper_limit = 5;  
    //selecting cols for the first grid
    col_lower_limit = 0;
    col_upper_limit = 2;
    //counter for the sub grid 
    counter = 0;

    //Initiating the four grid
    for(int row = row_lower_limit; row <= row_upper_limit; row++ )
    {
        for( int col = col_lower_limit; col <= col_upper_limit; col++)
        {
            sub_grid_4[counter] = main_grid[row][col];
            counter++;
        }
    }

    //row limits would be same three grids, but the cols would change
    col_lower_limit = 3;
    col_upper_limit = 5;
    counter = 0;
    //initiating the second grid
    for(int row = row_lower_limit; row <= row_upper_limit; row++ )
    {
        for( int col = col_lower_limit; col <= col_upper_limit; col++)
        {
            sub_grid_5[counter] = main_grid[row][col];
            counter++;
        }
    }

    //changing cols for 3third grid again 
    col_lower_limit = 6;
    col_upper_limit = 8;
    counter = 0;
    //initiating the third grid
    for(int row = row_lower_limit; row <= row_upper_limit; row++ )
    {
        for( int col = col_lower_limit; col <= col_upper_limit; col++)
        {
            sub_grid_6[counter] = main_grid[row][col];
            counter++;
        }
    }

    //Now initiating 7,8,9
    row_lower_limit = 6;
    row_upper_limit = 8;  
    //selecting cols for the first grid
    col_lower_limit = 0;
    col_upper_limit = 2;
    //counter for the sub grid 
    counter = 0;

    //Initiating the four grid
    for(int row = row_lower_limit; row <= row_upper_limit; row++ )
    {
        for( int col = col_lower_limit; col <= col_upper_limit; col++)
        {
            sub_grid_7[counter] = main_grid[row][col];
            counter++;
        }
    }

    //row limits would be same three grids, but the cols would change
    col_lower_limit = 3;
    col_upper_limit = 5;
    counter = 0;
    //initiating the second grid
    for(int row = row_lower_limit; row <= row_upper_limit; row++ )
    {
        for( int col = col_lower_limit; col <= col_upper_limit; col++)
        {
            sub_grid_8[counter] = main_grid[row][col];
            counter++;
        }
    }

    //changing cols for 3third grid again 
    col_lower_limit = 6;
    col_upper_limit = 8;
    counter = 0;
    //initiating the third grid
    for(int row = row_lower_limit; row <= row_upper_limit; row++ )
    {
        for( int col = col_lower_limit; col <= col_upper_limit; col++)
        {
            sub_grid_9[counter] = main_grid[row][col];
            counter++;
        }
    }
} 

//Printing the sub grids 
void sub_grid_display(int sgrid[])
{
    int tmp=0;
    for(int index=0 ; index <9 ; index ++)
    {
        cout<<" "<<sgrid[index]<<" ";
        tmp++;
        if(tmp==3) // The sub grid is supposed to be a grid of 3x3, so this would print it in the structure understandable by the user. 
        {
          cout<<endl;
          tmp =0;
        }
    }
    cout<<endl;
}

//Checking a row for 
bool check_single_row(int key, int row) //This function will check  an individual row for the given key and return true if found else false
{
    for ( int col = 0 ; col <= 8 ; col++) // each row has 9 coloumns 
    {
        if(main_grid[row][col] == key)
        { // If the value sent as argument is found then it would return true 
            return 1;
        } // but if it isnt found throughout the row then it would return a false check
    }//Row search ended and the key wasnt found so returning false.
    return 0;
}
//Combining the results
/*
int* calculate_results()
{
    int tmp[11];
    tmp[0]= results_row;
    tmp[1]= results_col;
    int count = 2;
    for(int i =0 ; i< 9; i++)
    {
        tmp[count] = results_subGrid[i];
        count++;
    }

    return tmp;
}
*/
//Making a function which would check all rows in the grid
void* check_all_rows(void *arg)
{
    for(int row=0 ; row <9 ; row++)
    {
        for( int key = 1 ; key <=9 ; key++)
        {
            if(check_single_row(key,row) == false)
            {
                sem_wait(&sem);
                cout<<"ROW CHECK FAILURE: key = "<<key<<" doesn't exist in row "<<row +1<<endl;
                final_results_part1[0] = false;
                sem_post (&sem);
                pthread_exit(NULL);
            }
        }
    }
    sem_wait(&sem);
    cout<<"ROW CHECK SUCCESS: all rows checked"<<endl;
    final_results_part1[0] = true;
    sem_post (&sem);
    pthread_exit(NULL);
}

bool check_single_col(int key, int col)
{
    for ( int row = 0 ; row <= 8 ; row++) // each row has 9 coloumns 
    {
        if(main_grid[row][col] == key)
        { // If the value sent as argument is found then it would return true 
            return 1;
        } // but if it isnt found throughout the row then it would return a false check
    }//Row search ended and the key wasnt found so returning false.
    return 0;
}

void* check_all_cols(void *arg)
{
    for (int col = 0; col < 9; col++)
    {
        for(int key =1; key <=9 ; key++)
        {
          if(check_single_col(key,col) == false)
            {
                sem_wait(&sem);
                cout<<"COL CHECK FAILURE: key = "<<key<<" doesn't exist in coloumn "<<col +1 <<endl;
                final_results_part1[1] = false;
                sem_post (&sem);
                pthread_exit(NULL);
            }
        }
    }
    sem_wait(&sem);
    cout<<"COL CHECK SUCCESS: all rows checked"<<endl;
    final_results_part1[1] = true;
    sem_post (&sem);
    pthread_exit(NULL);
}

bool check_single_subgrid(int subgrid[] , int key)
{
  for (int index=0; index < 9; index ++) // Each sub grid has a size of 3x3, which means there are 9 elements
  {
    if(subgrid[index] == key) // function is to retuen true if the value sent as argument is found
    {
      return 1;
    }
  }
  return 0; //and the function would return false if the key isnt found 
}

bool check_result(bool res[] , int key)
{
  for (int index=0; index < 11; index ++) // Each sub grid has a size of 3x3, which means there are 9 elements
  {
    if(res[index] == key) // function is to retuen true if the value sent as argument is found
    {
      return 1;
    }
  }
  return 0; //and the function would return false if the key isnt found 
}

void copy_sub_grid(int sg[], int tmp[])
{
  for (int index = 0 ; index < 9 ; index++)
  {
    tmp[index] = sg[index];
  } 
}

void *check_specific_number_subgrid(void *arg) //This function would take the number of subgrid as an argument 
{
  int sub_grid_number =  *((int *)arg);
  sub_grid_number ++; // adding one to make it the actual number of the grid, becasue the argument recieved would srange from 0-8 instead of 1-9 
  int copied_sub_grid[9];
  //coping the grid with the number recieved 
  //for subgrid1
  if( sub_grid_number == 1) 
  {copy_sub_grid(sub_grid_1,copied_sub_grid);} //copying sub grid
  //for subgrid 2
  else if( sub_grid_number == 2) 
  {copy_sub_grid(sub_grid_2,copied_sub_grid);}//copying sub grid
  //for subgrid 3
  else if( sub_grid_number == 3)
  {copy_sub_grid(sub_grid_3,copied_sub_grid);}//copying sub grid
  //for subgrid 4
  else if( sub_grid_number == 4)
  {copy_sub_grid(sub_grid_4,copied_sub_grid);}//copying sub grid
  //for subgrid 5
  else if( sub_grid_number == 5)
  {copy_sub_grid(sub_grid_5,copied_sub_grid);}//copying sub grid
  //for subgrid 6
  else if( sub_grid_number == 6)
  {copy_sub_grid(sub_grid_6,copied_sub_grid);}//copying sub grid
  //for subgrid 7
  else if( sub_grid_number == 7)
  {copy_sub_grid(sub_grid_7,copied_sub_grid);}//copying sub grid
  //for subgrid 8
  else if( sub_grid_number == 8)
  {copy_sub_grid(sub_grid_8,copied_sub_grid);}//copying sub grid
  //for subgrid 9
  else if( sub_grid_number == 9)
  {copy_sub_grid(sub_grid_9,copied_sub_grid);}//copying sub grid
  //if the number is out of rang
  else
  {
    cout<<"Error in grid number (function: check_specific_number_subgrid), Code ending!"<<endl;
    pthread_exit(NULL);
  }

  //now we have gridnumber and that sub grid copied 
  for (int key = 1 ; key <= 9 ; key++)
  {
    if(check_single_subgrid(copied_sub_grid,key) == false)
    {
      sem_wait(&sem);
      cout<<"SUB-Grid CHECK FAILURE: key = "<<key<<" doesn't exist in sub_grid_"<<sub_grid_number<<endl;
      final_results_part1[sub_grid_number +1] = false;
      sem_post (&sem);
      pthread_exit(NULL);
    }
  }
  sem_wait(&sem);
  cout<<"SUB-Grid CHECK SUCCESS: sub_grid_"<<sub_grid_number<<endl;
  final_results_part1[sub_grid_number +1] = true;
  sem_post (&sem);
  pthread_exit(NULL);
}

//|=======================================================================================================================================|
//| CODE RELATED TO PART 2
//|=======================================================================================================================================|

bool perfect_sub_grid(int subgrid[]) {
  // returns true if the argument subgrid has no repitition
  // returns false if the argument subgrid has repititionsdi
  for (int i = 0; i < 9 - 1; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (subgrid[i] == subgrid[j]) {
        return false;
      }
    }
  }
  return true;
}

int repeting_element_sub_grid(int subgrid[]) {
  // returns the  first repeting number in subgrid
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (subgrid[i] == subgrid[j]) {
        return subgrid[i];
      }
    }
  }
}

int repeating_element_index_sub_grid(int subgrid[], int repeat) {
  // returns the indexes where the values repeat\
    // 3 7 3 2 4 ...
  // (0102)  0*1000+1*100
  int indexes = 0;
  for (int i = 0; i < 9 - 1; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (subgrid[i] == subgrid[j] && repeat == subgrid[i]) {
        if (i < 3) {
          indexes = (0 + 1) * 1000 + (i + 1) * 100;
          if (j < 3)
            indexes += (0 + 1) * 10 + (j + 1) * 1;
          else if (j >= 3 && j < 6)
            indexes += (1 + 1) * 10 + (j - 3 + 1) * 1;
          else
            indexes += (2 + 1) * 10 + (j - 6 + 1) * 1;

        } else if (i >= 3 && i < 6) {
          indexes = (1 + 1) * 1000 + (i - 3 + 1) * 100;
          if (j < 3)
            indexes += (0 + 1) * 10 + (j + 1) * 1;
          else if (j >= 3 && j < 6)
            indexes += (1 + 1) * 10 + (j - 3 + 1) * 1;
          else
            indexes += (2 + 1) * 10 + (j - 6 + 1) * 1;

        } else {
          indexes = (2 + 1) * 1000 + (i - 6 + 1) * 100;
          if (j < 3)
            indexes += (0 + 1) * 10 + (j + 1) * 1;
          else if (j >= 3 && j < 6)
            indexes += (1 + 1) * 10 + (j - 3 + 1) * 1;
          else
            indexes += (2 + 1) * 10 + (j - 6 + 1) * 1;
        }
        return indexes;
      }
    }
  }
}

bool perfect_row_check(int row) {
  // checks that row in main gird
  // returns true if theres no repition
  // returns false if there is repition
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (main_grid[row][i] == main_grid[row][j]) {
        return false;
      }
    }
  }
  return true;
}

bool perfect_col_check(int col) {
  // checks that col in main gird
  // returns true if theres no repition
  // returns false if there is repition
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (main_grid[i][col] == main_grid[j][col]) {
        return false;
      }
    }
  }
  return true;
}

int missing_value_row(int row) {
  // uses main grid
  // returns the missing value in that row
  for (int key = 1; key <= 9; key++) {
    if (check_single_row(key, row) == false) {
      return key;
    }
  }
}

int missing_value_col(int col) {
  // uses main grid
  // returns the missing value in that col       check_single_col(int key, int
  // col)
  for (int key = 1; key <= 9; key++) {
    if (check_single_row(key, col) == false) {
      return key;
    }
  }
}

int repeat_element_row(int row) {
  // checks the row of main grid
  // returns the first repeatign element
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (main_grid[row][i] == main_grid[row][j]) {
        return main_grid[row][i];
      }
    }
  }
}

int invalid_entries_counter() {
  // checks the row of main grid
  // returns total invalid entries
  int counter = 0;
  for (int row = 0; row < 9; row++) {
    for (int i = 0; i < 9; i++) {
      for (int j = i + 1; j < 9; j++) {
        if (main_grid[row][i] == main_grid[row][j]) {
          counter++;
        }
      }
    }
  }
  return counter;
}

int repeat_element_col(int col) {
  // checks the col of main grid
  // returns the first repeatign element
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (main_grid[i][col] == main_grid[j][col]) {
        return main_grid[i][col];
      }
    }
  }
}

int index_repeating_elements_row(int row, int elemtnt) {
  // checks main grid
  // returns index of both elements as a single 4 digit number (frfcsrsc =
  // firstrow-firstcol-secondrow-secondcol)
  // main_grid[row][i]
  int indexes = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (main_grid[row][i] == main_grid[row][j]) {
        indexes =
            (row + 1) * 1000 + (i + 1) * 100 + (row + 1) * 10 + (j + 1) * 1;
        return indexes;
      }
    }
  }
}

int index_repeating_elements_col(int col, int elemtnt) {
  // checks main grid
  // returns index of both elements as a single 4 digit number (frfcsrsc =
  // firstrow-firstcol-secondrow-secondcol)
  // main_grin[i][col]
  int indexes = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (main_grid[i][col] == main_grid[j][col]) {
        indexes =
            (i + 1) * 1000 + (col + 1) * 100 + (j + 1) * 10 + (col + 1) * 1;
        return indexes;
      }
    }
  }
}
bool check_subgrid(int key, int sg[]) // This function will check  an individual row for the
                      // given key and return true if found else false
{
  for (int col = 0; col <= 8; col++) // each row has 9 coloumns
  {
    if (sg[col] == key) { // If the value sent as argument is found
                                      // then it would return true
      return 1;
    } // but if it isnt found throughout the row then it would return a false
      // check
  }   // Row search ended and the key wasnt found so returning false.
  return 0;
}

int missing_value_subgrid(int sg[]) {
  // uses main grid
  // returns the missing value in that row
  for (int key = 1; key <= 9; key++) {
    if (check_subgrid(key, sg) == false) {
      return key;
    }
  }
}
void correct_subgrid(int[],int,int);
void *correct_grid(void *arg) {
  // checks the sub grids one by one.
  // sends the selected subgrid to perfect_sub_grid
  // if false, checks for repeting element using repeting_element_sub_grid
  // function, it would return the repeat element
  // will use function repeating_element_index_sub_grid to get the indexes of
  // repeating element. if both the elements have the same col, we would check
  // the rows of both the elements using perfect_row_check, and will find the
  // missing value of the imperfect row ( perfect_row_check returns false) and
  // would replace the corresponding entry in the subgrid by that missing
  // value.
  correct_subgrid(sub_grid_1,0,0); 
  correct_subgrid(sub_grid_2,0,3);
  correct_subgrid(sub_grid_3,0,6);
  correct_subgrid(sub_grid_4,3,0);
  correct_subgrid(sub_grid_5,3,3);
  correct_subgrid(sub_grid_6,3,6);
  correct_subgrid(sub_grid_7,6,0);
  correct_subgrid(sub_grid_8,6,3);
  correct_subgrid(sub_grid_9,6,6);
  
  cout<<"Corrected Grid:\n\n";
  main_grid_display();
}



void correct_subgrid(int subgrid[],int row_lower, int col_min)
{
  int missing_element , repeating_element;
  //recheck:
  //cout<<"Checkpoint: before if!"<<endl;
  if(perfect_sub_grid(subgrid) == false) //only enter if subgrid is imperfect
  {
    //cout<<"Checkpoint2: inside if!"<<endl;
    missing_element = missing_value_subgrid(subgrid);
    repeating_element =  repeting_element_sub_grid(subgrid);
    int cordinates = repeating_element_index_sub_grid(subgrid,repeating_element);
    int first_Relement_row = row_lower + ((cordinates / 1000) -1);
    int first_Relement_col = col_min + ( ((cordinates / 100) %10) -1);
    int next_Relement_row = row_lower + ( ((cordinates / 10) % 10) -1);
    int next_Relement_col = col_min + ( (cordinates % 10) -1);
   // if(col_min > 0)
   // {
   //   next_Relement_col= col_min - next_Relement_col; //01
   // }

    //all four of the coordinated are now mapped on the main grid
    //main_grid[row][col] = missing_element
    //cout<<first_Relement_row<<first_Relement_col<<next_Relement_row<<next_Relement_col;
  
    
  if(first_Relement_row == next_Relement_row)
  {
    //cout<<"Checkpint3: inside main is"<<endl;
    if(perfect_col_check(first_Relement_col) == false) 
    {
      main_grid[first_Relement_row][first_Relement_col] = missing_element;
      cout<<"Location of Invalid Entry and its New Position : "<<first_Relement_row<<" "<< first_Relement_col<<endl;
    }
    else if(perfect_col_check(next_Relement_col) == false)
    {
      main_grid[next_Relement_row][next_Relement_col] = missing_element;
      cout<<"Location of Invalid Entry and its New Position : "<<next_Relement_row<<" "<< next_Relement_col<<endl;
    }
    
   //else cout<<"Throwback!"<<endl;
    
  }
  else if (first_Relement_col == next_Relement_col)
  {
    if(perfect_row_check(first_Relement_row) == false)
    {
      main_grid[first_Relement_row][first_Relement_col] = missing_element;
      cout<<"Location of Invalid Entry and its New Position : "<<first_Relement_row<<" "<< first_Relement_col<<endl;
    }
    else if(perfect_row_check(next_Relement_row) == false)
    {
      main_grid[next_Relement_row][next_Relement_col] = missing_element;
      cout<<"Location of Invalid Entry and its New Position : "<<next_Relement_row<<" "<< next_Relement_col<<endl;
    }
  }
  else
  {
    if(check_single_row(missing_element, first_Relement_row) == true)
    {
      main_grid[next_Relement_row][next_Relement_col] = missing_element;
      cout<<"Location of Invalid Entry and its New Position : "<<next_Relement_row<<" "<< next_Relement_col<<endl;
    }
    else
    {
      main_grid[first_Relement_row][first_Relement_col] = missing_element;
      cout<<"Location of Invalid Entry and its New Position : "<<first_Relement_row<<" "<< first_Relement_col<<endl;
    }
      
  }
  
    //goto recheck;
  }
  
}
//|=======================================================================================================================================|
//| Code INT MAIN
//|=======================================================================================================================================|

int main() 
{
  sem_init (&sem,0,1);
  //creating threads
  pthread_t thread_row_check;
  pthread_t thread_col_check;
  pthread_t thread_grid_check[9];
  pthread_t thread_correction;
  
  //=========================================| Start menu and grid / subgrids initialization |===================================================================
  // Start menu to set grid of users choice 
  int start_menu_input;
  startMenu:
  display_starting_menu();
  cout << " Enter: ";
  cin >> start_menu_input;
  cout << endl;

  if (start_menu_input == 1) {
    generate_main_grid_correct();
    main_grid_display();
  } else if (start_menu_input == 2) {
    generate_main_grid_incorrect();
    main_grid_display();
  } else if (start_menu_input == 3) {
    input_main_grid();
    main_grid_display();
  } else {
    cout << endl << "Invalid Input! Showing menu again!" << endl;
    goto startMenu;
  }

  fill_sub_grid_arrays();
  // sub_grid_display( sub_grid_2); //For checking and verification purposes
  

  //=========================================| Checking/ Validating Rows Cols and subgrids |===================================================================
 cout<<endl<<endl<<endl;

 //Checking the sub-grids first
 for (int index=0; index < 9; index++)
 {
    cout<<"\nUsing Thread id "<<thread_grid_check[index]<<" for subgrid search \n"<<endl;
    pthread_create(&thread_grid_check[index],NULL,check_specific_number_subgrid,&index);
    pthread_join(thread_grid_check[index],NULL);
 }
 
  //col-validation create and join
  cout<<"\nUsing Thread id "<<thread_col_check<<" for column search\n "<<endl;
  pthread_create(&thread_col_check,NULL,check_all_cols,NULL);
  pthread_join(thread_col_check,NULL);
  
  //row-validation create and join 
  cout<<"\nUsing Thread id "<<thread_row_check<<" for row search \n"<<endl;
  pthread_create(&thread_row_check, NULL, check_all_rows, NULL );
  pthread_join(thread_row_check, NULL);

  //Calculation the final results:
  cout<<endl<<endl<<endl;
  if(check_result(final_results_part1, false) == true)
  {
    cout<<"|============================|"<<endl;
    cout<<"|Soultion: Invalid           |"<<endl;
    cout<<"|Invalid Entries: "<<invalid_entries_counter()<<"          |"<<endl;
    cout<<"|============================|"<<endl<<endl;

    //correct_grid
    cout<<"\nUsing Thread id "<<thread_correction<<" for correcting the grid \n"<<endl;
    pthread_create(&thread_correction, NULL,correct_grid,NULL);
    pthread_join(thread_correction,NULL);
  }
  else
  {
    cout<<"|============================|"<<endl;
    cout<<"|Soultion: Valid             |"<<endl;
    cout<<"|============================|"<<endl;
  }

  return 0;
}