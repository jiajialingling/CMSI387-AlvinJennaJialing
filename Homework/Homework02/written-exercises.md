# **CMSI 387: Homework02**
###**Alvin, Jenna, Qiyue**

### 1)
Reversing the steps would prove to be problematic because the current thread would remain in `runnable threads`, thus leaving the possibility of it executing again and disrupting the proper sequence that the threads must executed in.

### 2)
Having `State snapshot = state.get();` in the `audit()` function ensures that the calls `getSeatsRemaining()` and `getCashOnHand()` reference the same object. The removal of `snapshot` opens up the possibility of the State object changing states, thus having the two function calls referencing different objects.
