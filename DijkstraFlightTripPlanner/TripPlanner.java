import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class TripPlanner {

    private static String[] readFile(String path) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(path));
        String s = "";
        while (sc.hasNextLine())
            s += sc.nextLine() + '\n';
        return s.split("\n");
    }

    public static void main(String[] args) throws FileNotFoundException {
        String[] data = readFile("example_input.txt");

        Graph graph = new Graph(Integer.parseInt(data[0]), Integer.parseInt(data[2]));

        String constraints[] = data[1].split(" ");
        int startCity = Integer.parseInt(constraints[0]), endCity = Integer.parseInt(constraints[1]);
        int startTime = Integer.parseInt(constraints[2]), endTime = Integer.parseInt(constraints[3]);

        for (int i = 3; i < Integer.parseInt(data[2]) + 3; i++) {
            String temp[] = data[i].split(" ");
            int departed = Integer.parseInt(temp[0]), arrived = Integer.parseInt(temp[1]);
            String name = temp[2];
            int departureTime = Integer.parseInt(temp[3]), arrivalTime = Integer.parseInt(temp[4]);
            int weight = arrivalTime - departureTime;
            if (departureTime >= startTime && arrivalTime <= endTime)
                graph.insertEdge(departed, arrived, weight, departureTime, arrivalTime, name);
        }

        String[][] bestPath = (graph.FindShortestPath(startCity, endCity));

        if (bestPath.length == 0 || !bestPath[graph.i - 1][1].equals(constraints[1]))
            System.out.println(-1);
        else {
            print(bestPath);
        }
    }

    public static void print(String[][] a) {
        int c = 0;
        for (int i = 0; i < a.length; i++) {
            if (a[i][0] != null && !a[i][0].equals("")) {
                System.out.print(a[i][0] + "\t");
                c++;
            }
        }
        System.out.println("Number of Flights: " + c);

    }
}
