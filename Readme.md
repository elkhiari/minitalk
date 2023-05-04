# Minitalk

## Process

In computing, a process is an instance of a running program. It is an executing instance of a computer program that has a unique process identifier (PID) and consists of program code, data, and system resources, such as CPU time, memory, and input/output (I/O) operations.

Every program that runs on a computer creates one or more processes. A process can be a single-threaded program, or it can be a multi-threaded program with multiple threads of execution. Each process has its own address space, which means that it can only access its own memory and cannot access the memory of other processes.

Processes are managed by the operating system, which allocates system resources to each process and schedules the execution of each process on the CPU. The operating system provides system calls and APIs that allow programs to create, manage, and communicate with processes.

Processes can communicate with each other through interprocess communication (IPC) mechanisms, such as pipes, sockets, and shared memory. Processes can also create child processes using system calls like fork() or CreateProcess(). These child processes inherit certain properties of their parent process, such as their environment variables and file descriptors.

In summary, a process is an instance of a running program that has a unique process identifier, its own address space, and access to system resources, and is managed by the operating system.

## PID

very process in a computer system has a unique process identifier (PID). The PID is an integer value that is assigned by the operating system to each process when it is created. The PID is used by the operating system to track and manage each process, and it is used by other programs to interact with the process.

The PID is a unique identifier for a process within the context of the operating system. It allows the operating system to distinguish one process from another and to manage system resources, such as CPU time, memory, and I/O operations, for each process separately.

Processes can be identified by their PID using system tools like ps (process status) on Unix-based systems or Task Manager on Windows. These tools can display information about each process running on the system, such as its name, PID, status, CPU and memory usage, and more.

Example :

```
#include<signal.h>
#include<stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    //pid_t is a data type defined in the C standard library that is used to represent a process identifier (PID). It is an integer type that is usually defined as a signed 32-bit or 64-bit integer, depending on the operating system.

    pid = getpid()
    // getpid() is a function in the C standard library that returns the process identifier (PID) of the current process. It is declared in the unistd.h header file on Unix-based systems, and in the process.h header file on Windows.

    printf("My PID is: %d\n", pid); // output : My PID is: 5040
    while(1);
}
```

## signal

In computing, a signal is a software interrupt delivered to a process by the operating system or another process. Signals are a mechanism for communication between processes and between a process and the operating system. Signals can be used to notify a process of events, such as the completion of a system call, the availability of data on a socket, or the occurrence of a hardware exception.

## kill()

function is used to send a signal to a process or a group of processes. The signal sent by kill() can be used to interrupt a process, terminate a process, or notify a process of a particular event.
The kill() function takes two arguments: the process ID (PID) of the process to which the signal should be sent, and the signal number to send.

## SIGUSR1 and SIGUSR2

SIGUSR1 and SIGUSR2 are signals that are reserved for user-defined purposes in Unix and Unix-like operating systems, including Linux.

The SIGUSR1 and SIGUSR2 signals are not associated with any specific behavior or action by default, and their specific use is left up to the programmer to define. This makes them useful for implementing custom signal handling behavior in programs.

In other words, SIGUSR1 and SIGUSR2 can be used by a program to implement custom signal handling functionality. For example, a program might use SIGUSR1 to instruct a process to pause its execution, while SIGUSR2 could be used to resume execution. Alternatively, a program might use SIGUSR1 to trigger a specific action or behavior, such as reloading configuration files, while SIGUSR2 could be used for a different purpose, such as triggering a status report.

Overall, the SIGUSR1 and SIGUSR2 signals are a flexible and useful feature of Unix-like operating systems that allow programmers to implement custom signal handling functionality in their programs.

## Pause

pause() is a function that causes the calling process to sleep until a signal is delivered.

Example :

```
    while(1)
        printf("Server is running...\n");
        pause();
```

## usleep and sleep

Both usleep() and sleep() are functions that are used to pause the execution of a program for a certain amount of time. The main difference between them is the units of time that they accept.

usleep() is a function that is used to pause the execution of a program for a specified number of microseconds. The syntax for usleep() is:

```
#include <unistd.h>

int usleep(useconds_t microseconds);
```

example:

```
#include<stdio.h>
#include <unistd.h>

int main()
{
    printf("%s\n", "Hello world! ,1");
    usleep(1000000);
    printf("%s\n", "Hello world! ,1");

}
```

sleep() is a function that is used to pause the execution of a program for a specified number of seconds. The syntax for sleep() is:

```
#include <unistd.h>

unsigned int sleep(unsigned int seconds);
```

example:

```
#include<stdio.h>
#include <unistd.h>

int main()
{
    int i = 0;
    while (1)
    {
        printf("%d\n",i++);
        sleep(2);
    }

}
```

## Bitwise Operators

<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/Operators-In-C.png"/>

### Left Shift and Right Shift Operators

1. The << (left shift) in C or C++ takes two numbers, the left shifts the bits of the first operand, and the second operand decides the number of places to shift.

example:

```
    int i = 10; 00001010
    int j = i << 2; 00101000 => 40
    printf("%d\n",j); // output : 40
```

2. The >> (right shift) in C or C++ takes two numbers, right shifts the bits of the first operand, and the second operand decides the number of places to shift.

example:

```
    int i = 10; 00001010
    int j = i >> 2; 00000010 => 2
    printf("%d\n",j); // output : 2
```

### bitwise AND

| X   | Y   | X & Y |
| --- | --- | ----- |
| 0   | 0   | 0     |
| 0   | 1   | 0     |
| 1   | 0   | 0     |
| 1   | 1   | 1     |

example:

```
    unsigned char a = 5, b = 9;
    //a = 5(00000101), b = 9(00001001)
    // a = 00000101
    // b = 00001001
    // r = 00000001 = 1
    printf("a&b = %d\n", a & b);


    a = 3;
    b = 8;
    // a = 00000011
    // b = 00001000
    // r = 00000000 = 0
    printf("a&b = %d\n", a & b);

    a = 120;
    b = 110;
    // a = 01111000
    // b = 01101110
    // r = 01101000 = 104
    printf("a&b = %d\n", a & b);
```

## exit()

exit(int) is a library function that is used to terminate the program and return an exit status to the operating system. The int argument passed to exit() represents the exit status or return code of the program.

The exit status is a value that is returned to the calling process or shell that launched the program. A status code of 0 typically indicates that the program ran successfully, while a non-zero status code indicates that the program encountered an error or some other issue.

The exit() function performs a number of actions before terminating the program. It flushes all open output streams, closes all open files, and calls any functions registered with the atexit() function. Once these actions are completed, the program terminates and control is returned to the operating system.

It's worth noting that the behavior of exit() can be modified by installing a signal handler for the SIGTERM signal. If a signal handler is installed, it will be executed instead of the standard exit() function when the SIGTERM signal is received.
