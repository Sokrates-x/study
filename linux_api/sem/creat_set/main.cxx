#include <iostream>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <sys/types.h>

union semun {
	int val;
	semid_ds *buf1;
	short *array;
	seminfo *buf2;
};

int main(int, char **)
{

	// creat
	key_t key =  ftok(".", 32);
	int sid = semget(key, 5, IPC_CREAT | 0660);

	// set value 10
	semun usem;	
	usem.val = 10;
	semctl(sid, 0, SETVAL, usem);

	// increase
	sembuf buf = { 0, 1, IPC_NOWAIT }; 
	std::cout << semop(sid, &buf, 1) << std::endl;

	// get value 11
	std::cout << semctl(sid, 0, GETVAL) << std::endl;

	// stat
	semun stat;
	semid_ds mysemds;
	stat.buf1 = &mysemds;
	semctl(sid, 0, SEM_STAT, stat);
	std::cout << "KEY: " << stat.buf1->sem_perm.__key << std::endl;
	std::cout << "UID: " << stat.buf1->sem_perm.uid << std::endl;
	std::cout << "GID: " << stat.buf1->sem_perm.gid << std::endl;
	std::cout << "CUID: " << stat.buf1->sem_perm.cuid << std::endl;
	std::cout << "CGID: " << stat.buf1->sem_perm.cgid << std::endl;
	std::cout << "MODE: " << stat.buf1->sem_perm.mode << std::endl;
	std::cout << "SEQ: " << stat.buf1->sem_perm.__seq << std::endl;

	return 0;
}
