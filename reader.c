#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
	int id = shmget(137, 2048, IPC_CREAT | 0666);
	char *msg = (char *)shmat(id, (void *)0, 0);

	printf("Reading from memory...\n");
	printf("Data is: %s\n", msg);

	shmdt(msg);
	shmctl(id, IPC_RMID, NULL);
	return 0;
}
