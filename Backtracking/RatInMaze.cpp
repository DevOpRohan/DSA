/*Hints to read this code easily..
    first read the RatInMaze() ,then display() and then main()
*/
#include<iostream>
using namespace std;
int count=0,x2,y2;   //x2,y2 for the distination coordinate  and count to maintain number of soutions

int display(int **arr,int m, int n);
int RatInMaze(int **maze,int m, int n, int **sol,int x,int y);  /*a function to take maze(m(i.e problem) and itd dimensions(m by n)
                                                                    as well as a sol matix(m by n) to store the solution.
                                                                    as well as starting coordinte(x,y)
                                                                */
int main()
{
    
    //part 1..Creation of Maze
    
    int m,n;
    cout<<"Enter the dimensions(separated by space):- ";
    cin>>m>>n;
        int **maze = new int*[m];
    for(int i=0;i<m;i++)
    {
        maze[i] = new int[n];
    }

    //input maze
    cout<<"input maze in form of matrix,where 0  means path is block or 1 means path is ok"<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<"Enter the row "<<i+1<<" :"<<endl;
        for(int j=0;j<n;j++)
        {
            cin>>maze[i][j];
        }
  
    }
    





    //Part 2: creation of a solution matrix

    //create a sol matrix which will store the sol.
    int **sol = new int*[m];
    for(int i=0;i<m;i++)
    {
        sol[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            sol[i][j] = 0;   //initialize all elements with zero
        }
    }
    


    //Part 3:-Display the maze on console
    cout<<"Maze : - "<<endl;
    display(maze,m,n);   //displaying maze
    



    //part 4:- Input of start and destination coordinate

    int x1,y1;
    cout<<"Enter the start coordinate(separated by space) : ";   //-->input start coordinate
    cin>>x1>>y1;        //-->input start coordinate
    
    cout<<"Enter the destination coordinate(separated by space) : ";    
    cin>>x2>>y2;        /*-->input destination coordinate and store it in global variables so that
                                any function use it without takiang it as arguments.*/

    



    //Part 5:- Sove the problems
    RatInMaze(maze,m,n,sol,x1,y1);
    
    if(!count)
        cout<<"No solution";
    
    return 0;
}



int display(int **arr,int m, int n)
{
    if(count)
        cout<<"sol "<<count<<" :-"<<endl;
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}


int RatInMaze(int **maze,int m, int n, int **sol,int x,int y)
{
    
    //base case
    if(x==x2 && y==y2)
    {
        sol[x][y] = 1;
        count++;                    //to count the no. of solutions
        display(sol,m,n);           //displaying the solutions
        return 0;
    }


    /*contraints:-  i) x and y should be in maze
                    ii) maze[x][y] shouldn't equals to zero,beacuse zero means path is blocked
                    iii)if sol[x][y] is already 1 ..i.e you are repeating the block.
                        That's why sol[x][y] mustn't equal to 1.
    */

    if(x<0 || x>=m || y<0 || y>=n || maze[x][y] == 0 || sol[x][y] == 1)  /*->if any of these conditions are false
                                                                            means the postion the current positin
                                                                            (x,y) don't satisfy the constraints
    {
        return 0;    
    }
    

    sol[x][y] = 1;                      /*--x,y coordinate is safe now eplore further 
                                            in all directions using recursion*/

    RatInMaze(maze,m,n,sol,x-1,y);      //to up
    RatInMaze(maze,m,n,sol,x+1,y);      //to down
    RatInMaze(maze,m,n,sol,x,y-1);      //to left
    RatInMaze(maze,m,n,sol,x,y+1);      //to right


    sol[x][y] = 0;          /*Backtrack   -->( reason 1)-> if any of the calls don't get the solution
                                                        i.e. you can't find solutions from this coordinate.
                                                        So, put it again as zero.And go back and explore further.
                                              (reason 2)-> if you get the solution ..means you have reached the base case
                                                         and displayed the solution on console.
                                                         now, from here also, you must have to go back
                                                         and explore further for more solutions.
                             */                            
    
    return 0;
}