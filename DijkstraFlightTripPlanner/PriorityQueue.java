public class PriorityQueue {

    private GEdge[] heap;
    private int size;
    private static final int TOP = 1;

    public PriorityQueue(int capacity) {
        this.heap = new GEdge[capacity];
        heap[0] = new GEdge(-1, -1, Integer.MIN_VALUE, 0, 0, "");
        this.size = 0;
    }


    private boolean isLeaf(int k) {
        return k * 2 >= this.size;
    }

    private void swap(int k1, int k2) {
        GEdge temp = heap[k1];
        heap[k1] = heap[k2];
        heap[k2] = temp;
    }


    public void enqueue(GEdge data) {
        heap[++size] = data;
        int i = size;
        while (heap[i / 2].getWeight() > heap[i].getWeight()) {
            swap(i / 2, i);
            i = i / 2;
        }
    }

    public GEdge dequeue() {
        GEdge min = heap[TOP];
        heap[TOP] = heap[size--];
        heapify(TOP);
        return min;
    }

    private void heapify(int p) {
        if (isLeaf(p))
            return;
        if (heap[p].getWeight() > heap[p * 2].getWeight() || heap[p].getWeight() > heap[p * 2 + 1].getWeight()) {
            if (heap[p * 2].getWeight() < heap[p * 2 + 1].getWeight()) {
                swap(p, p * 2);
                heapify(p * 2);
            } else {
                swap(p, p * 2 + 1);
                heapify(p * 2 + 1);
            }
        }
    }

    public int Size() {
        return size;
    }

    public GEdge peek() {
        return heap[TOP];
    }

    public boolean isEmpty() {
        return size == 0;
    }


}