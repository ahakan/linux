#include <sys/stat.h>
#include <signal.h>
#include <unistd.h>
#include <iostream>
#include <filesystem>

int main(void)
{
    // Our process ID
    pid_t pid, sid;

    /* Fork off the parent process */
    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    /* If we got a good PID, then
        we can exit the parent process. */
    if (pid > 0) {
        // kill(pid, SIGKILL);
        // exit(EXIT_FAILURE);
    }

    /* Change the file mode mask */
    umask(0);

    /* Create a new SID for the child process */
    sid = setsid();
    // if (sid < 0) {
    //     /* Log the failure */
    //     exit(EXIT_FAILURE);
    // }

    /* Change the current working directory */
    if ((chdir("/")) < 0) {
        /* Log any failure here */
        exit(EXIT_FAILURE);
    }

    std::cout << "PID: " << pid << " SID: " << sid << std::endl;
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    /* Close out the standard file descriptors */
    // close(STDIN_FILENO);
    // close(STDOUT_FILENO);
    // close(STDERR_FILENO);

    int index = 0;
    /* The Big Loop */
    while (1) {
        /* Do some task here ... */
        if( pid == 0){
            std::cout << "Looping at index: " << index << std::endl;
            index++;
        }
        sleep(10); /* wait 10 seconds */
    }
    exit(EXIT_SUCCESS);
}