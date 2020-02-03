
CMSI 387: Operating Systems

Homework 1

Authors: Qiyue Aixinjueluo, Jenna Berlinberg, Alvin Lai

1. Middleware is the software between the application programs and the operating system which provides mechanisms to support interactions between the two. Apps tell middleware the actions to perform, then middleware tells the OS what to do, and finally the OS communicates with the hardware to tell it what to do.

2. A thread is a sequence of programmed actions. Being a unit of concurrency, OS's allow multiple threads to run simultaneously. Processes are containers which hold thread(s) and prevents unnecessarry/unwanted interactions between unrelated threads.

3. TODO: consult with group on an answer

4. a) 1 iteration = 10ms (thread A disk I/O) + 1ms (thread A computation)

    100 * (10ms + 1ms) + 1000ms + 1ms = 2101ms

    b) 1 iteration = 10ms (thread A I/O while B computes) + 1ms switch + 1ms thread A computation + 1ms switch

    100 * (10ms + 1ms + 1ms + 1ms) = 1300ms

    c) TODO

5. 
