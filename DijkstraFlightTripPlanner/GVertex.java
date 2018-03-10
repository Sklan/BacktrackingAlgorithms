public class GVertex {
    private GEdge head;

    public void insert(GEdge gEdge) {
        if (head != null)
            head.setNext(insert(head.getNext(), gEdge));
        else
            head = gEdge;
    }

    private GEdge insert(GEdge temp, GEdge gEdge) {
        if (temp == null) return gEdge;
        else temp.setNext(insert(temp.getNext(), gEdge));
        return temp;
    }


    public GEdge getHead() {
        return head;
    }

    public void printGVertex() {
        printGVertex(head);
    }

    private void printGVertex(GEdge temp) {
        if (temp
                != null) {
            System.out.print(temp.getDestination() + "\t");
            printGVertex(temp.getNext());
        }
    }
}
