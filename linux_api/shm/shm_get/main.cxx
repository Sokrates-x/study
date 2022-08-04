#include <iostream>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/ipc.h>

int main(int, char **)
{
	// creat
	key_t key = ftok(".", 111);	
	int shmid = shmget(key, sizeof(char) * 100, IPC_CREAT | 0660);
	char *p, *pp;
	int pid = fork();
	switch (pid) {
	case -1:
		break;
	case 0:
		p = reinterpret_cast<char *>(shmat(shmid, 0, 0));
		*p++ = 'f';	
		*p++ = 'u';	
		*p++ = 'c';	
		*p = 'k';	
		break;	
	default:
		wait(nullptr);	
		pp = reinterpret_cast<char *>(shmat(shmid, 0, 0));
		std::cout << *pp << std::endl;	
	}			

	return 0;
}
