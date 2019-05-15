#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
	int id = shmget(137, 2048, IPC_CREAT | 0666);
	char *msg = (char *)shmat(id, (void *)0, 0);

	printf("Write some data: ");
	fgets(msg, 100, stdin);

	shmdt(msg);
	printf("Data written...\n");
	return 0;
}
