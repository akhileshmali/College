from collections import deque

class Graph:
    def __init__(self, adjac_lis):
        self.adjac_lis = adjac_lis

    def a_star_algorithm(self, start, stop):
        open_lst = set([start])
        closed_lst = set([])
        poo = {start: 0}
        par = {start: start}

        while len(open_lst) > 0:
            n = min(open_lst, key=lambda x: poo[x])

            if n == stop:
                reconst_path = []
                while n != start:
                    reconst_path.append(n)
                    n = par[n]
                reconst_path.append(start)
                reconst_path.reverse()
                print('Path found: {}'.format(reconst_path))
                return reconst_path

            for m, weight in self.adjac_lis[n]:
                if m not in open_lst and m not in closed_lst:
                    open_lst.add(m)
                    par[m] = n
                    poo[m] = poo[n] + weight
                else:
                    if poo[m] > poo[n] + weight:
                        poo[m] = poo[n] + weight
                        par[m] = n
                        if m in closed_lst:
                            closed_lst.remove(m)
                            open_lst.add(m)

            open_lst.remove(n)
            closed_lst.add(n)

        print('Path does not exist!')
        return None

# Get user input for the graph
adjac_lis = {}
num_nodes = int(input("Enter the number of nodes in the graph: "))
for i in range(num_nodes):
    node = input("Enter the name of node {}: ".format(i+1))
    adjac_lis[node] = []
    num_neighbors = int(input("Enter the number of neighbors for node {}: ".format(node)))
    for j in range(num_neighbors):
        neighbor, weight = input("Enter the name of neighbor {} and its weight: ".format(j+1)).split()
        adjac_lis[node].append((neighbor, int(weight)))

# Create the graph object and run the A* algorithm
graph1 = Graph(adjac_lis)
start = input("Enter the starting node: ")
stop = input("Enter the stopping node: ")
graph1.a_star_algorithm(start, stop)

"""
Enter the number of nodes in the graph: 4
Enter the name of node 1: A
Enter the number of neighbors for node A: 3
Enter the name of neighbor 1 and its weight: B 1
Enter the name of neighbor 2 and its weight: C 3
Enter the name of neighbor 3 and its weight: D 7
Enter the name of node 2: B
Enter the number of neighbors for node B: 1
Enter the name of neighbor 1 and its weight: D 5
Enter the name of node 3: C
Enter the number of neighbors for node C: 1
Enter the name of neighbor 1 and its weight: D 12
Enter the name of node 4: D
Enter the number of neighbors for node D: 0
Enter the starting node: A
Enter the stopping node: D
"""
