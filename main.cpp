//
//
//// priority_queue in STL
////#include<bits/stdc++.h>
//#include <utility>
//#include<list>
//using namespace std;
//# define INF 0x3f3f3f3f
//
//// iPair ==>  Integer Pair
//typedef pair<int, int> iPair;
//
//// This class represents a directed graph using
//// adjacency list representation
//class Graph
//{
//    int V;    // No. of vertices
//
//    // In a weighted graph, we need to store vertex
//    // and weight pair for every edge
//    list< pair<int, int> > *adj;
//
//public:
//    Graph(int V);  // Constructor
//
//    // function to add an edge to graph
//    void addEdge(int u, int v, int w);
//
//    // prints shortest path from s
//    void shortestPath(int s);
//};
//
//// Allocates memory for adjacency list
//Graph::Graph(int V)
//{
//    this->V = V;
//    adj = new list<iPair> [V];
//}
//
//void Graph::add_edge(int u, int v, int w)
//{
//    adj[u].push_back(make_pair(v, w));
//    adj[v].push_back(make_pair(u, w));
//}
//
//// Prints shortest paths from src to all other vertices
//void Graph::shortestPath(int src)
//{
//    // Create a priority queue to store vertices that
//    // are being preprocessed. This is weird syntax in C++.
//    // Refer below link for details of this syntax
//    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
//    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
//
//    // Create a vector for distances and initialize all
//    // distances as infinite (INF)
//    vector<int> dist(V, INF);
//
//    // Insert source itself in priority queue and initialize
//    // its distance as 0.
//    pq.push(make_pair(0, src));
//    dist[src] = 0;
//
//    /* Looping till priority queue becomes empty (or all
//     distances are not finalized) */
//    while (!pq.empty())
//    {
//        // The first vertex in pair is the minimum distance
//        // vertex, extract it from priority queue.
//        // vertex label is stored in second of pair (it
//        // has to be done this way to keep the vertices
//        // sorted distance (distance must be first item
//        // in pair)
//        int u = pq.top().second;
//        pq.pop();
//
//        // 'i' is used to get all adjacent vertices of a vertex
//        list< pair<int, int> >::iterator i;
//        for (i = adj[u].begin(); i != adj[u].end(); ++i)
//        {
//            // Get vertex label and weight of current adjacent
//            // of u.
//            int v = (*i).first;
//            int weight = (*i).second;
//
//            //  If there is shorted path to v through u.
//            if (dist[v] > dist[u] + weight)
//            {
//                // Updating distance of v
//                dist[v] = dist[u] + weight;
//                pq.push(make_pair(dist[v], v));
//            }
//        }
//    }
//
//    // Print shortest distances stored in dist[]
//    printf("Vertex   Distance from Source\n");
//    for (int i = 0; i < V; ++i)
//        printf("%d \t\t %d\n", i, dist[i]);
//}
//
//// Driver program to test methods of graph class
//int main()
//{
//    // create the graph given in above fugure
//    int V = 4;
//    Graph g(V);
//
//    //  making above shown graph
//    g.addEdge(0, 1, 1);
//    g.addEdge(0, 2, 2);
//    g.addEdge(0, 3, 10);
//    g.addEdge(0, 3, 3);
//    g.addEdge(1, 3, 2);
//    g.addEdge(2, 3, 1);
//    g.addEdge(1, 1, 1);
//
//
//    g.shortestPath(0);
//
//    return 0;
//}


#include<iostream>
#include<list>
#include<queue>
using namespace std;
list<pair<int, int>> lst;
////priority_queue declarations
priority_queue<int> pqueue;


//public data members for points and traits
int points, trails, meters_of_flowers = 0;

//class to store values of p1, p2 and distance between
struct trail_of_flowery_garden{
    int p1,p2,l;
public:
    //addfunction
    void add(int pp1,int pp2,int ll){
        p1=pp1;
        p2=pp2;
        l=ll;
    }
    //overloaded extraction/right-shift operator to insert the values from user
    friend istream& operator >> (istream& in, trail_of_flowery_garden& obj);
    //overloaded insertion/left-shift operator to insert the values from user
    friend ostream& operator << (ostream& in, trail_of_flowery_garden& obj);
}*trait_obj; //pointer to object of class trait

//definition of right-shift operator
istream& operator >> (istream& in, trail_of_flowery_garden& obj){
    in>>obj.p1;
    in>>obj.p2;
    in>>obj.l;
    //validation check for lenght
    if(obj.l< 1 || obj.l>1000){
        cout<<"Enter valid value for lenght:";
        cin>>obj.l;
    }
    return in;
}

//definition of left-shift operator
ostream& operator << (ostream& in, trail_of_flowery_garden& obj){
    cout<<obj.p1<<" "<<obj.p2<<" "<<obj.l<<endl;
    return in;
}

//this function will all of the data from user in defined sequence
void read_input(){
//    cin>>points; cin>>traits;
//    // in case of invalid input program terminates
//    if(points<2 || points> 10000)
//        exit(1);
//    if(traits<1 || traits> 10000)
//        exit(1);
//    //memory has been allocated on the heap so it can be accessed anywhere in program
//    trait_obj = new trait[traits];
//    //read all of the points and their distance
//    cout<<"Input points and distance:";
//    for(int i=0;i<traits;i++){
//        cin>>trait_obj[i];
//    }

    points = 4; trails = 7;
    trait_obj = new trail_of_flowery_garden[trails];
    trait_obj[0].add(0,1,1);
    trait_obj[1].add(0,2,2);
    trait_obj[2].add(0,3,10);
    trait_obj[3].add(0,3,3);
    trait_obj[4].add(1,3,2);
    trait_obj[5].add(2,3,1);
    trait_obj[6].add(1,1,1);
    
    cout<<points<<" "<<trails<<endl;
        for(int i=0;i<trails;i++){
            cout<<trait_obj[i];
    }
}

//function to check whether the point already visited or not
bool visited_point(list<pair<int,int>> val,int p1,int p2){
    for (auto it=val.begin(); it!=val.end(); it++) {
        pair<int,int> p = *it;
        if(p.first == p1 && p.second == p2)
            return true;
    }
    return false;
}

// Graph class represents a directed graph
// using adjacency list representation
class Flowery_Trails
{
    int V;    // No. of vertices
    // Pointer to an array containing
    // adjacency lists
    list<int> *adj;
    
    // A recursive function used by printAllPaths()
    void all_path_until(int v1, int v2, bool visited[], int path[], int index);
public:
    Flowery_Trails(int V);   // Constructor
    bool path_exist; //variable to indicate if path exist or not
    // function to add an edge to graph
    void add_edge(int v, int w);
    void all_popular_paths(int v1, int v2);
    
};

Flowery_Trails::Flowery_Trails(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Flowery_Trails::add_edge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

// A recursive function to print all paths from 'v1' to 'v2'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and index is current
// index in path[]
void Flowery_Trails::all_path_until(int v1, int v2, bool visited[], int path[], int index)
{
    // Mark the current node as visited and store it in path[]
    visited[v1] = true;
    path[index]=v1;
    index++;
    // If current vertex is same as v2, then print
    // current path[]
    if(v1==v2){
        int i;
        path_exist=true;
        for(i=0;i<index-1;i++)
            {
                if(!visited_point(lst,path[i],path[i+1]))
                for (int j=0; j<trails; j++) {
                    if(path[i] == trait_obj[j].p1 && path[i+1] == trait_obj[j].p2){
                        pair<int,int> p(path[i],path[i+1]);
                        lst.push_back(p);
                        meters_of_flowers += trait_obj[j].l;
                        if(trait_obj[j].p2 == (points-1))
                            {
//                                cout<<meters_of_flowers<<endl;
                                pqueue.push(meters_of_flowers * (-1));
                                meters_of_flowers=0;
                            }
                    }
                }
            }
        }
    else{ // If current vertex is not v2
        // Recur for all the vertices adjacent
        // to this vertex
        list<int>::iterator i;
        for (i = adj[v1].begin(); i != adj[v1].end(); ++i)
            if (!visited[*i])
                all_path_until(*i, v2, visited, path, index);
    }
    // Remove current vertex from path[] and mark it as unvisited
    index--;
    visited[v1]=false;
}

// DFS traversal of the vertices reachable from v.
// It uses recursive prinAllPathsUtil
void Flowery_Trails::all_popular_paths(int v1, int v2)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    // Create an array to store paths
    int *path = new int[V];
    // Initialize path[] as empty
    int index = 0;
    path_exist=false;
    // Call the recursive helper function to print all paths
    all_path_until(v1,v2,visited,path,index);
}
//Dijkstra Algorithm
void Dijkstra_Algorithm(){
    Flowery_Trails g(points-1);
    //making the graph for flowery trail
    for (int i =0; i<trails; i++) {
        g.add_edge(trait_obj[i].p1, trait_obj[i].p2);
    }
    //finding the all popular paths from entrance to highest-peak and storing them in a min-heap priority-queue
    g.all_popular_paths(0, points-1);
    //accessing the shortest popular path
    int shortest_path = pqueue.top()* (-1);
    meters_of_flowers = shortest_path;
    pqueue.pop();
    //visiting the queue to sum all popular paths
    while (!pqueue.empty()) {
        if(pqueue.top()* (-1) == shortest_path)
            meters_of_flowers += shortest_path;
        pqueue.pop();
    }
    //here the final output
    cout<<"Extent of flowers needed to cover both sides of the popular trails is "<<meters_of_flowers*2<<" meters"<<endl;
}

// Driver code
int main()
{
    read_input();
    Dijkstra_Algorithm();
    return 0;
    
}
