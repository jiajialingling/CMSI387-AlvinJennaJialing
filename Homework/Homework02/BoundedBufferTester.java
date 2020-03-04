public class BoundedBufferTester {

  public static void main(String[] args) {
    BoundedBuffer buffTest = new BoundedBuffer();

    Thread t1 = new Thread(new Runnable() {
      @Override
      public void run() {
        try {
          buffTest.insert(10);
          System.out.println("10 in");
        } catch (InterruptedException e) {
          System.out.println("huh??");
        }
      }
    }); 

      Thread t2 = new Thread(new Runnable() {
        @Override
        public void run() {
          try {
            System.out.println("we have retrieved:");
            System.out.println(buffTest.retrieve());
          } catch (InterruptedException e) {
            System.out.println("huh??");
          }
        }
      });

    System.out.println("testing buffer");
    t1.start();
    t2.start();

    try {
      t1.join();
      t2.join();
    } catch (InterruptedException e) {
      System.out.println("weird");
    }
  }
}
