#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <iterator>
#include <functional>
#include <unistd.h>

int main(int, char **)
{
	auto key = ftok(".", 311);
	std::cout << key << std::endl;
	auto msgqid = msgget(key, IPC_CREAT | 0660);			
	std::cout << msgqid << std::endl;

	// msg struct
	struct mesbuf {
		long mtype;	
		char mtext[20];
	};

	// send
	mesbuf mbuf;
	mbuf.mtype = 10086;	
	mbuf.mtext[0] = 'f';
	mbuf.mtext[1] = 'u';
	mbuf.mtext[2] = 'c';
	mbuf.mtext[3] = 'k';
	mbuf.mtext[4] = '\0';
	msgsnd(msgqid, &mbuf, 20, IPC_NOWAIT);

	mesbuf mbuf1;
	mbuf1.mtype = 10086;	
	mbuf1.mtext[0] = 'c';
	mbuf1.mtext[1] = 's';
	mbuf1.mtext[2] = 't';
	mbuf1.mtext[3] = 'r';
	mbuf1.mtext[4] = '\0';
	msgsnd(msgqid, &mbuf1, 20, IPC_NOWAIT);

	sleep(1);	

	// recive
	mesbuf rbuf;
	msgrcv(msgqid, &rbuf, 20, 10086, IPC_NOWAIT);
	std::copy(std::begin(rbuf.mtext), std::end(rbuf.mtext),
		std::ostream_iterator<char>(std::cout, ""));
	std::cout << std::endl;

	// anthor ?
	mesbuf rbuf2;
	msgrcv(msgqid, &rbuf2, 20, 10086, IPC_NOWAIT);
	std::copy(std::begin(rbuf2.mtext), std::end(rbuf2.mtext),
		std::ostream_iterator<char>(std::cout, ""));
	std::cout << std::endl;

	// Emmm ... it's FIFO
	
	return 0;
}
