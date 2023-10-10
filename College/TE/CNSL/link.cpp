//Write a program to implement Distance vector routing protocol to find suitable path for transmission.
#include<iostream>
using namespace std;
#define INF 9999 

int main()
{
    int n,i,j,k; 
    cout<<"Enter the number of nodes: ";
    cin>>n; 
    int d[n][n],p[n][n];
    cout<<"Enter the distance matrix:\n";
    for(i=0;i<n;i++) // loop over all nodes
    {
        for(j=0;j<n;j++) // loop over all pairs of nodes
        {
            cin>>d[i][j]; // read the distance between the current pair of nodes from the user
            if(d[i][j]==0) // if the distance is 0, set the path between the nodes to infinity
            {
                p[i][j]=INF;
            }
            else // otherwise, set the path to the destination node
            {
                p[i][j]=j;
            }
        }
    }
    for(k=0;k<n;k++) // loop over all nodes
    {
        for(i=0;i<n;i++) // loop over all pairs of nodes
        {
            for(j=0;j<n;j++) // loop over all pairs of nodes
            {
                if(d[i][j]>d[i][k]+d[k][j]) // if the distance between the current pair of nodes is greater than the sum of the distance between the current node and a third node, and the distance between the third node and the destination node
                {
                    d[i][j]=d[i][k]+d[k][j]; // update the distance matrix
                    p[i][j]=p[i][k]; // update the path matrix
                }
            }
        }
    }
    cout<<"The shortest distance matrix is:\n";
    for(i=0;i<n;i++) // loop over all nodes
    {
    	   cout<<"Router "<<i<<" : ";
        for(j=0;j<n;j++) // loop over all pairs of nodes
        {
            cout<<d[i][j]<<" "; // print the shortest distance between the current pair of nodes
        }
        cout<<"\n";
    }
    
    return 0; // end the main function and return 0 to indicate successful execution of the program
}


























/*
Distance Vector Routing (DVR) is a type of routing algorithm used in computer networks to determine the 
best path for data packets based on distance. In simple words, it is a way for routers to communicate with each other 
and share information about the network topology.
Here is how DVR works in simple terms:
Each router maintains a routing table that contains information about the network topology.
The routing table contains the best-known distance from the source to the destination and which route is used to get there.
The routers periodically exchange routing tables with each other to update the information.
The distance between routers is usually measured in hops, which means the number of routers a packet has to pass through
to reach its destination.
The routers use the Bellman-Ford algorithm to calculate the best route across the network.
The algorithm works by having each router maintain a distance vector that contains the distance to each of its neighbors.
The router then uses this information to calculate the shortest path to each destination.
The router updates its routing table based on the information it receives from its neighbors.
The process of updating the routing table keeps on repeating periodically to update the shortest path in case the link 
goes down or there is a topology change.
Overall, DVR is a simple and efficient way for routers to communicate with each other and share information about the 
network topology. It is widely used in computer networks to ensure that data packets are delivered to their destination 
in the most efficient way possible.
Distance Vector Routing (DVR) is a type of routing algorithm used in computer networks to determine the best path for 
data packets based on distance. It is a simple and efficient way for routers to communicate with each other and share 
information about the network topology.
DVR works by having each router maintain a routing table that contains information about the network topology. The 
routing table contains the best-known distance from the source to the destination and which route is used to get there. 
The routers periodically exchange routing tables with each other to update the information. The distance between routers 
is usually measured in hops, which means the number of routers a packet has to pass through to reach its destination.
The routers use the Bellman-Ford algorithm to calculate the best route across the network. The algorithm works by having
each router maintain a distance vector that contains the distance to each of its neighbors. The router then uses 
this information to calculate the shortest path to each destination. The router updates its routing table based on the 
information it receives from its neighbors. The process of updating the routing table keeps on repeating periodically 
to u pdate the shortest path in case the link goes down or there is a topology change.
DVR is different from Link State Routing (LSR), which is another type of routing algorithm used in computer networks. 
LSR is a dynamic routing algorithm in which each router shares knowledge of its neighbors with every other router in 
the network. A router sends its information about its neighbors only to all the routers through flooding. 
Information sharing takes place only whenever there is a change. It makes use of Dijkstra’s Algorithm for making 
outing tables.
Overall, DVR is a simple and efficient way for routers to communicate with each other and share information about the 
network topology. It is widely used in computer networks to ensure that data packets are delivered to their destination 
in the most efficient way possible.

*/
