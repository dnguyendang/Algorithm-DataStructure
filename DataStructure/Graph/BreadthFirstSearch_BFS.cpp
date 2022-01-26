// traverse a graph by breadth and use a queue to remember the adjacent vertex to start the search 
// this algorithm follows rules:
// 1 - iterate adjacent vertex that has not yet been traversed
// show this vertex and push into queue 
// 2 - if can not find adjacent vertex, then delete first vertex in queue
// 3 - repeat rules 1 and 2 until queue is empty

#include<iostream>
using namespace std;

#define MAX 7

struct Vertex{
    char label;
    bool visited;
};

// declare variables for queue
int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;

// declare variables for graph

// declare list of vertex
struct Vertex* lstVertices[MAX];

// declare adjacency matrix 
int adjMatrix[MAX][MAX];

// a variable counts the number of vertexes
int vertexCount = 0;

// functions that work with queue
bool isQueueFull(){
    return queueItemCount == MAX;
}

void insert(int data){
    if(!isQueueFull()){
        if(rear == MAX - 1)
            rear = -1;
        queue[++rear] = data;
        queueItemCount++;        
    }
}

int removeData(){
    int data = queue[front++];
    if(front == MAX){
        front = 0;
    }    
    queueItemCount--;
    return data;
}

bool isQueueEmpty(){
    return queueItemCount == 0;
}

// functions that work with graph

// add vertex to lst of vertices
void addVertex(char label){
    struct Vertex* vertex = new Vertex();
    vertex->label = label;
    vertex->visited = false;
    lstVertices[vertexCount++] = vertex;
}

// add edge to lst of edges
void addEdge(int start, int end){
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}

// show vertex
void displayVertex(int vertexIndex){
    cout << lstVertices[vertexIndex]->label << " " ;
}

// get vertex that has not been traversed
int getAdjUnvisitedVertex(int vertexIndex){
    int i;
    for(i = 0; i < vertexCount; i++){
        if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false)
            return i;
    }
    return -1;
}

void breadthFirstSearch(){
    int i;

    // mark first node is visited
    lstVertices[0]->visited = true;

    // show vertex
    displayVertex(0);

    // insert index of vertex to queue
    insert(0);
    int unvisitedVertex;

    while(!isQueueEmpty()){
        // pull vertex that has not been traversed
        int tempVertex = removeData();

        // can not find adjacent vertex
        while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1){
            lstVertices[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            insert(unvisitedVertex);
        }
    }

    // queue is empty, complete seaching, reset values of visited
    for(int i = 0; i < vertexCount; i++){
        lstVertices[i]->visited = false;
    }
}

int main(){
    int i, j;

    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            adjMatrix[i][j] = 0;
        }
    }

    // addVertex('S');   // 0
    // addVertex('A');   // 1
    // addVertex('B');   // 2
    // addVertex('C');   // 3
    // addVertex('D');   // 4
    
    // addEdge(0, 1);    // S - A
    // addEdge(0, 2);    // S - B
    // addEdge(0, 3);    // S - C
    // addEdge(1, 4);    // A - D
    // addEdge(2, 4);    // B - D
    // addEdge(3, 4);    // C - D
    
    //-> S - A - B - C - D
    
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

    cout << "Breadth First Search: ";
    
    breadthFirstSearch();
}