#include <unistd.h>
#include <fcntl.h>
#define STDIN_FILENO 0

#define	STDOUT_FILENO 1
#define STDERR_FILENO 2

O_RDONLY
O_WRONLY
O_RDWR

O_APPEND
O_CREAT
O_EXCL
O_TUNC

O_SYNC
O_DSYNC
O_RSYNC

SEEK_SET 0
SEEK_CUR 1
SEEK_END 2

F_DUPFD
F_GETFD
F_SETFD
F_GETFL
F_SETFL
F_GETDOWN
F_SETDOWN

F_GETLK
F_SETLK
F_SETLKW


int	open(const char *pathname, int oflag, .../*mode_t mode*/);
int	creat(const char *pathname, mode_t mode);
int	close(int filedes);

ssize_t	read(int filedes, void *pathname, size_t nbutes);
ssize_t	write(int filedes, const char *buf, size_t nbytys);

off_t	lseek(int filedes, off_t offset, int whence);

int	dup(int filedes);
int	dup2(int filede, int filedes2);

int	fcntl(int filedes, int cmd, ...);

int	fsync(int filedes);
void	sync(void);
int	fdatasync(int filedes);
