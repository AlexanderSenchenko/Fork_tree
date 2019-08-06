#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid_buff;
	int status;

	pid_buff = fork();
	if (pid_buff == 0) {
		pid_buff = fork();
		if (pid_buff == 0) {
			printf("parent=%d\tchild=%d\n", getppid(), getpid());
		} else {
			printf("parent=%d\tchild=%d\n", getppid(), getpid());
			wait(&status);
		}
	} else {
		pid_buff = fork();
		if (pid_buff == 0) {
			pid_buff = fork();
			if (pid_buff == 0) {
				printf("parent=%d\tchild=%d\n", getppid(), getpid());
			} else {
				pid_buff = fork();
				if (pid_buff == 0) {
					printf("parent=%d\tchild=%d\n", getppid(), getpid());
				} else {
					printf("parent=%d\tchild=%d\n", getppid(), getpid());
					wait(&status);
					wait(&status);
				}
			}
		} else {
			printf("parent=%d\tchild=%d\n", getppid(), getpid());
			wait(&status);
			wait(&status);
		}
	}

	return 0;
}

