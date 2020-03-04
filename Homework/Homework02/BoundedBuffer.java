public class BoundedBuffer {
    private Object[] buffer = new Object[20];    // arbitrary size
    private int numOccupied = 0;
    private int firstOccupied = 0;

    // invariant: 0 <= numOccupied <= buffer.length
    // 0 <= firstOccupied < buffer.length
    // buffer[(firstOccupied + i) % buffer.length]
    // contains the (i+1)th oldest entry,
    // for all i such that 0 <= i < numOccupied

    public synchronized void insert( Object o ) throws InterruptedException {
       while( numOccupied == buffer.length ) {
          wait();        // wait for space
       }
       buffer[( firstOccupied + numOccupied ) % buffer.length] = o;
       numOccupied++;
       notifyAll();      // in case any retrieves are waiting for data, wake them
    }

    public synchronized Object retrieve() throws InterruptedException {
       while( numOccupied == buffer.length ) {
          wait();        // wait for space
       }
       Object retrieved = buffer[firstOccupied];
       buffer[firstOccupied] = null;       // may help garbage collector
       firstOccupied = (firstOccupied + 1) % buffer.length;
       numOccupied--;
       notifyAll();      // in case any retrieves are waiting for data, wake them
       return retrieved;
    }
 }
