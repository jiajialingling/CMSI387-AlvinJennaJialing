## Final Project

Are we really those dumb programmers who forget to commit things and write a readme? Yes, yes we are.

### Changelog

- Virtual Machines: Jenna got Linux kernel 5.6.7 built on her super rad PC, gave it 40 GB and a bit later 4 of the 6 cores. Qiyue and Alvin were unable to get their kernels built.
- Change spec from editing mkdir to creating a new system call upon reading into the implications.
- Start following system call creation tutorials, especially the one on medium.
- Screenshared/discussed the code on Discord/phone calls with Alvin during most of the steps below this.
- Made new directory mkcd: contains mkcd.c, makefile.
- Edited include/linux/syscalls.h to include the prototype sys_mkcd.
- Edited arch/x86/entry/syscalls/syscall_64.tbl as the 548th system call.
- Edited the main Makefile to include the mkcd directory.
- Attempted to compile a few times and fumbled with the include pathways a bit.
- Attempted to compile: function not defined errors on using chdir and mkdir.
- Reached out to Adjunct Professor at USF, former senior director at Motorola, Apple, etc, and Jenna’s mom’s tennis partner, Phil Peterson, for assistance. He recommend using the sys_mkdir and sys_chdir.
- Same error. Further sleuthing was done until we found the comment on line 1231 on include/linux/syscalls.h saying Kernel code should call ksys_callname instead of the sys_callname function. Works the same, but it is preferred- likely to prevent leaks and errors of some kind?
- Attempted to compile, had a trivial declaration issue.
- Reformatted the mkcd.c and definition in include/linux/syscalls.h to look similar to mkdir. Created a do_mkcd that is called by the SYSCALL_DEFINE1, added reference of do_mkcd  and defined ksys_mkcd to call the do_mkcd to syscalls.h.
- Realized we were meant to present the next day, but this code was not done and one of our members was asleep. Had a minor panic attack, but thankfully BJ allowed us to go first on Wednesday, which I am eternally grateful.
- Attempt to compile, got a `cannot find __x64_sys_mkcd` from arch/x86/entry/syscalls/syscall_64.tbl.
- Ran `objdump -S mkcd.o` and found out the sys function being generated was actually __x64_sys_sys_mkcd. Changed the first argument of SYSCALL_DEFINE1 to be mkcd instead of sys_mkcd.
- Attempted to compile. It compiled!
- Created userspace.c file and ran it. cwd didn't change, so it might've failed? The new directory is created, though...
- Printed the cwd before and after, and saw that the child thread main was cd-ing into it, but wasn't connecting to the command line itself. Can this be changed?
- Found out that this whole thing was kind of worthless unless we get it called via command line. But it technically does what is expected? So. Yay?
- Debriefed Qiyue and Alvin on the full specs of the call. Planned out the presentation.
- Added race conditions and printk. Recompiled. Still works the same, just has proper error convention and alerts the user better.
- Made presentation! 
