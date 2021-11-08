# A-STAR-Alogrithm-Implementation-to-Find-the-Path-Between-Two-Points-in-a-Two-D-Map-
This is an example of A Start implementation in C++. 
### Program Sequence
The Implementation is done simply as the following sequence:
- The main program creates an object of the class A_STAR
- The instance of A_STAR reads an input file in string format. The default name of the file is **file.txt**
- Input data are converted to a state table **vector\<vector\<Node\>\>** with the name **grid**
- grid shows the route from the start point to the end point
- Start point has the symbol **S**
- Goal point has te symbol **F**
- Empty Points have the symbol **E**
- Points which are not empty have the symbol **O**
- An output example should be as follows:  
<pre>
S  O  E  E  O  E  E  O  E  E  O  E  
P  O  E  E  O  E  E  O  E  E  E  E  
P  O  E  E  E  E  E  O  E  E  O  E  
P  O  O  E  E  E  E  O  E  E  O  E  
P  E  E  E  E  E  E  O  E  E  O  E  
P  E  E  E  E  E  E  O  E  E  O  E  
P  E  E  E  E  E  E  E  E  E  O  E  
P  P  P  P  P  P  F  O  E  E  O  E  
</pre>
This is the path from the point (0,0) until the point (7,6). One can see the start point(x=0, y=0) in the upper left with the symbol **S**. The the path goes along with the symbol **P**. Finally, the target is the point with the symbol **F**.  
**Important Notice:** As the indexing of a vector of vector is inverted compared to normal coordinates, the cordinates hier are inverted. This means the point (7,6) has the x=6 and y=7. Positive y axis is going downward. 

### Input file
The content of the input file **file.txt** for the former grid example is the following:  
<pre>
0,1,0,0,1,0,0,1,0,0,1,0,  
0,1,0,0,1,0,0,1,0,0,0,0,  
0,1,0,0,0,0,0,1,0,0,1,0,  
0,1,1,0,0,0,0,1,0,0,1,0,  
0,0,0,0,0,0,0,1,0,0,1,0,  
0,0,0,0,0,0,0,1,0,0,1,0,  
0,0,0,0,0,0,0,0,0,0,1,0,  
0,0,0,0,0,0,0,1,0,0,1,0, 
</pre>
### Main Body of The Program
Below is a copy of main.cpp which is self explained:  
```
vector<vector<State>> grid;
  try {
    // create an Object of A_STAR
    // remove the comment and edit file name according to your file name
    A_STAR Pathfinder /*("file.txt")*/;
    // search the path between the points (0,0) and (7,6)
    Pathfinder.Search(0, 0, 7, 6);
    // return the grid table
    grid = Pathfinder.GetGrid();
    // print the grid which includes the path between the two points
    std::cout << grid;
    // uncomment to show the points of the detected path
    // std::cout << Pathfinder.getPath();
  } catch (const invalid_argument &e) {
    std::cout << e.what() << endl;
  }
  std::cout << "Exit correctly\n";
  return 0;
```

## Compile the Program
For the current time I did not create a Makefile or a CMakeLists.txt file but one can simply compile and run the program as follows:  
- Clone the Repo  
git clone https://github.com/abdulkarim723/A-STAR-Alogrithm-Implementation-to-Find-the-Path-Between-Two-Points-in-a-Two-D-Map-.git  
- Go inside the cloned folder from the terminal:  
```
cd A-STAR-Alogrithm-Implementation-to-Find-the-Path-Between-Two-Points-in-a-Two-D-Map-
```
- Compile the program as follows: 
```
g++ -std=c++17 -Wall *.cpp -o ASTAR
```
- Finally, run the program
```
.\ASTAR.exe
```
