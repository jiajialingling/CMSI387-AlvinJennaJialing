### **CMSI 387: Homework02 <br> Alvin, Jenna, Qiyue**

### 1)
Reversing the steps would prove to be problematic because the current thread would remain in `runnable threads`, thus leaving the possibility of it executing again and disrupting the proper sequence that the threads must executed in.

### 2)
Having `State snapshot = state.get();` in the `audit()` function ensures that the calls `getSeatsRemaining()` and `getCashOnHand()` reference the same object. The removal of `snapshot` opens up the possibility of the State object changing states, thus having the two function calls referencing different objects.

### 6)

Virtual Address: `first = 12288`, `last = 16380`

To get the physical addresses, multiple the addresses by `4096`

Physical Address: `first = 24576`, `last = 28668`

### 7)

`1047552` and `1047553` come from the index of the last page table. Each page can point to 1024 frames, thus multiplying the last page, `1023` by `1024` yields the values `1047552` & `1047553`
