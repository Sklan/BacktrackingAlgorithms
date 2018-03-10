public class Graph {
    GVertex vertices[];
    int numberOfVertices, numberOfEdges;
    int i = 0;

    Graph(int n, int m) {
        vertices = new GVertex[n + 1];

        for (int i = 1; i < n + 1; i++)
            vertices[i] = new GVertex();

        this.numberOfVertices = n;
        this.numberOfEdges = m;

    }

    public void insertEdge(int source, int destination, int weight, int startTime, int endTime, String name) {
        vertices[source].insert(new GEdge(source, destination, weight, startTime, endTime, name));
    }

    public String[][] FindShortestPath(int start, int end) {

        int distance[] = new int[numberOfVertices + 1];
        boolean marked[] = new boolean[numberOfVertices + 1], shortestPath[] = new boolean[numberOfVertices + 1];
        String flights[][] = new String[numberOfEdges + 1][2];


        for (int i = 1; i < numberOfVertices + 1; i++)
            distance[i] = Integer.MAX_VALUE;
        distance[start] = 0;

        PriorityQueue pq = new PriorityQueue(numberOfVertices + 1);
        pq.enqueue(new GEdge(0, start, distance[start], 0, 0, ""));

        int wait = 0;
        while (!pq.isEmpty()) {
            GEdge min = pq.dequeue();
            int v = min.getDestination();

            if (v == end) {
                shortestPath[v] = true;
                flights[this.i][0] = min.getFlightName();
                flights[this.i++][1] = Integer.toString(min.getDestination());
                break;
            }


            if (!marked[v]) {
                marked[v] = true;
                GEdge temp = vertices[v].getHead();
                int k = 0;
                while (temp != null) {
                    wait = temp.getStartTime() - k;
                    int w = temp.getDestination(), weight = temp.getWeight() - wait;

                    if (wait >= 0 && distance[w] >= distance[v] + weight && min.getEndTime() <= temp.getStartTime()) {
                        distance[w] = distance[v] + weight;
                        pq.enqueue(new GEdge(v, w, distance[w], temp.getStartTime(), temp.getEndTime(), temp.getFlightName()));
                        shortestPath[v] = true;
                        flights[this.i][0] = min.getFlightName();
                        flights[this.i++][1] = Integer.toString(min.getDestination());

                    }
                    k = temp.getEndTime();
                    temp = temp.getNext();
                }
            }
        }

        return flights;
    }

}
