### **CMSI 387: Homework02 <br> Alvin, Jenna, Qiyue**

### 1)
Reversing the steps would prove to be problematic because the current thread would remain in `runnable threads`, thus leaving the possibility of it executing again and disrupting the proper sequence that the threads must executed in.

### 2)
Having `State snapshot = state.get();` in the `audit()` function ensures that the calls `getSeatsRemaining()` and `getCashOnHand()` reference the same object. The removal of `snapshot` opens up the possibility of the State object changing states, thus having the two function calls referencing different objects.

### 3)

See BoundedBufferTester.java for the code.

### 4)

BoundedBuffer.java contains the modified code.

### 5)

When using two-phase locking, it is impossible for T2 to see the old value of x and the new value of y since two-phase locking guarantees serializability between transactions- in this case, the writing and subsequent reading. T2 will only read new values. For "read committed" isolation level, this situation is possible. For snapshot isolation, it is not possible to do so since it would either read both old values or both new values. 

### 6)

Virtual Address: `first = 12288`, `last = 16380`

To get the physical addresses, multiple the addresses by `4096`

Physical Address: `first = 24576`, `last = 28668`

### 7)

`1047552` and `1047553` come from the index of the last page table. Each page can point to 1024 frames, thus multiplying the last page, `1023` by `1024` yields the values `1047552` & `1047553`

### 8)

Program see loopTiming.c
Hardware: Mac Pro computer.
Software: Visual Studio.
I created a char array that has 4096 element. I created a holder for accssed elelmet. I then use the time.h to time how long the inner loop took to run through all elements. I then printed out the total time used.

### 9)

There are `8 processes` from the C program, `2 processes` from bash. `10 total processes`
