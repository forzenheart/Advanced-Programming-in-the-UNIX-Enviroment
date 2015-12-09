#include <fcntl.h>
#include <unistd.h>

int open(const char* pathname, int oflag, ...);
//返回值　成功返回文件描述符，若出错则返回-1
int creat(const char* pathname, mode_t mode);
//返回值，若成功则返回为只写打开的文件描述符，若出错则返回-1
//等同于　open(pathname, O_WRONLY | O_CREAT | O_TRUNC, mode);

//创建一个临时文件
//int n = creat(pathname, mode);
//close(n);
//open(pathname, O_RDWR , mode);
//等同于　open(pathname, O_RDWR | O_CREAT | O_TRUNC, mode);

int close(int filedes);
//返回值　成功则返回0, 出错则返回-1;
//当程序结束时，系统例程会自动关闭系统打开的流

off_t lseek(int filedes, off_t offset, int whence);
//返回值　成功则返回新的文件偏移量，若出错则返回-1
//example
//确定打开文件的当前偏移量
off_t currpos;
currpos = lseek(fd, 0, SEEK_CUR);

ssize_t read(int filedes, void  buf, size_t nbytes);
//返回值　成功则返回读到的字节数，若已到达文件尾则返回0, 出错则返回-1
ssize_t write(int filedes, const void *buf, size_t nbytes);
//返回值　成功则返回已写的字节数，出错则返回-1

int dup(int filedes);
int dup(int filedes, int filedes2);
//如果filedes已经打开，则先将其关闭，如果filedes等于filedes2则返回filedes2,不关闭它。
//返回值　成功则返回新的文件描述符，出错则返回-1

//等待内核将文件从高速缓冲区写到磁盘文件上
int fsync(int filedes);
int fdatasynce(int filedes);

void sync(void);
//返回值　成功返回0, 失败返回-1

//改变现有文件描述符的属性
int fcntl(int filedes, int cmd, ..../* int arg */);
//若成功则依赖于cmd,失败则返回-1

