# Minitalk

### process
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

    printf("My PID is: %d\n", pid); // pid of process
    while(1);
}
```

