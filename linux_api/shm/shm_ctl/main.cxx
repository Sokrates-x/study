#include <iostream>
#include <sys/shm.h>
#include <sys/ipc.h>

int main(int, char **)
{
	// creat
	key_t key = ftok(".", 34);		
	int shmid = shmget(key, sizeof(char) * 10, IPC_CREAT | 0660);

	// ctl
	shmid_ds shmds;
	shmctl(shmid, SHM_STAT, &shmds);
	std::cout << "Size: " << shmds.shm_segsz << std::endl;
	std::cout << "Natt: " << shmds.shm_nattch << std::endl;
	std::cout << "CPID: " << shmds.shm_cpid << std::endl;
	std::cout << "LPID: " << shmds.shm_lpid << std::endl;
	std::cout << "KEY: " << shmds.shm_perm.__key << std::endl;
	std::cout << "UID: " << shmds.shm_perm.uid << std::endl;
	std::cout << "GID: " << shmds.shm_perm.gid << std::endl;
	std::cout << "CUID: " << shmds.shm_perm.cuid << std::endl;
	std::cout << "CGID: " << shmds.shm_perm.cgid << std::endl;
	std::cout << "MODE: " << shmds.shm_perm.mode << std::endl;
	std::cout << "SEQ: " << shmds.shm_perm.__seq << std::endl;
	return 0;
}
