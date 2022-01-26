// searching algorithm uu tien chieu sau

// iterate or searching algorithm in a tree or a graph
// use stack to remember the adjacent vertex 

// algorithm continues until it reaches the desired vertex or reaches a node with no children
// then the algorithm goes back to the vertex searched in the previous step

// this algorithm follows the rules:
// 1 - iterate to the adjacent vertex that has not yet been traversed.
// mark the vertex that has been approved. Show that vertex and push into a stack
// 2 - if cannot find adjacent vertex, take a vertex from stack 
// 3 - repeat rule 1 and 2 until stack is empty

#include<iostream>
using namespace std;

#define MAX 7

struct Vertex{
    char label;
    bool visited;
};

// declare variables for the stack 
int stack[MAX];
int top = -1;

// declare variables related to graph

// declare list of vertex
struct Vertex* lstVertices[MAX];

// declare a adjacency matrix
int adjMatrix[MAX][MAX];

// declare a variable to count the number of vertices
int vertexCount = 0;

// functions that work with the stack 
void push(int item){
    stack[++top] = item;
}

int pop(){
    return stack[top--];
}

int peek(){
    return stack[top];
}

bool isStackEmpty(){
    return top == -1;
}

// functions that work with graph

// add new vertex to lst of vertices
void addVertex(char label){
    struct Vertex* vertex = new Vertex();
    vertex->label = label;
    vertex->visited = false;
    lstVertices[vertexCount++] = vertex;
}

// add new edge to lst of edges 
void addEdge (int start, int end){
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}

// show vertex 
void displayVertex(int vertexIndex){
    cout << lstVertices[vertexIndex]->label << " ";
}

// get unmark vertex from the adjacency matrix
int getAdjUnvisitedVertex(int vertexIndex){
    int i;

    for(i = 0; i < vertexCount; i++){
        if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false)
            return i;
    }

    return -1;
}

void depthFirstSearch(){
    int i;

    // mark first node is visited
    lstVertices[0]->visited = true;

    // show vertex
    displayVertex(0);

    // insert index of vertex to stack
    push(0);

    while(!isStackEmpty()){
        // pul unmark vertex from stack 
        int unvisitedVertex = getAdjUnvisitedVertex(peek());

        // can not find adjacent vertex 
        if(unvisitedVertex == -1){
            pop();
        }else{
            lstVertices[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            push(unvisitedVertex);
        }
    }

    // stack is empty, complete searching, reset value of visited
    for(i = 0; i < vertexCount; i++){
        lstVertices[i]->visited = false;
    } 
}

int main(){
    int i, j;

    for(i = 0; i < MAX; i++){ // set values 
        for(j = 0; j < MAX; j++){ // of adjacency matrix are 0
            adjMatrix[i][j] = 0;
        }
    }

//    addVertex('S');   // 0
//    addVertex('A');   // 1
//    addVertex('B');   // 2
//    addVertex('C');   // 3
//    addVertex('D');   // 4
 
//    addEdge(0, 1);    // S - A
//    addEdge(0, 2);    // S - B
//    addEdge(0, 3);    // S - C
//    addEdge(1, 4);    // A - D
//    addEdge(2, 4);    // B - D
//    addEdge(3, 4);    // C - D

// -> S-A-D-B-C

    addVertex('S');   // 0
    addVertex('A');   // 1
    addVertex('B');   // 2
    addVertex('C');   // 3
    addVertex('D');   // 4
    addVertex('E');   // 5
    addVertex('F');   // 6
    
    addEdge(0, 1);    //S - A
    addEdge(0, 3);    //S - C
    addEdge(0, 5);    //S - E
    addEdge(0, 6);    //S - F
    addEdge(1, 2);    //A - B
    addEdge(2, 3);    //B - C
    addEdge(3, 4);    //C - D
    addEdge(4, 5);    //D - E
    addEdge(5, 6);    //E - F

    cout << "Depth First Search: " ;

    depthFirstSearch();

    return 0;
}