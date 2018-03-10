class GEdge {
    private int source;
    private int destination;
    private int weight;
    private int startTime;
    private int endTime;
    private String flightName;
    private GEdge next;

    GEdge(int source, int destination, int weight, int startTime, int endTime, String flightName) {
        this.source = source;
        this.destination = destination;
        this.weight = weight;
        this.startTime = startTime;
        this.endTime = endTime;
        this.flightName = flightName;
        this.next = null;
    }

    GEdge getNext() {
        return next;
    }

    void setNext(GEdge n) {
        next = n;
    }

    public int getWeight() {
        return weight;
    }

    public int getDestination() {
        return destination;
    }

    public int getSource() {
        return source;
    }

    public int getEndTime() {
        return endTime;
    }

    public int getStartTime() {
        return startTime;
    }

    public String getFlightName() {
        return flightName;
    }
}
