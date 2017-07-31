
// automatically generated by m4 from headers in proto subdir


#ifndef __ESXDOS_H__
#define __ESXDOS_H__

#include <arch.h>
#include <stdint.h>

// Limits

#define ESXDOS_PATH_MAX  __ESXDOS_PATH_MAX   // max pathname length in bytes including terminating \0
#define ESXDOS_NAME_MAX  __ESXDOS_NAME_MAX   // max filename length in bytes not including terminating \0

// Esxdos Drive Shortcuts

#define ESXDOS_DRIVE_CURRENT  __ESXDOS_DRIVE_CURRENT
#define ESXDOS_DRIVE_SYSTEM   __ESXDOS_DRIVE_SYSTEM

// Esxdos File Mode

#define ESXDOS_MODE_R   __ESXDOS_MODE_READ
#define ESXDOS_MODE_W   __ESXDOS_MODE_WRITE

#define ESXDOS_MODE_OE  __ESXDOS_MODE_OPEN_EXIST
#define ESXDOS_MODE_OC  __ESXDOS_MODE_OPEN_CREAT

#define ESXDOS_MODE_CN  __ESXDOS_MODE_CREAT_NOEXIST
#define ESXDOS_MODE_CT  __ESXDOS_MODE_CREAT_TRUNC

#define ESXDOS_MODE_P3  __ESXDOS_MODE_USE_HEADER

// Esxdos Seek Whence

#define ESXDOS_SEEK_SET  __ESXDOS_SEEK_SET   // set file pointer
#define ESXDOS_SEEK_FWD  __ESXDOS_SEEK_FWD   // forward from file pointer
#define ESXDOS_SEEK_BWD  __ESXDOS_SEEK_BWD   // backward from file pointer

// Esxdos Data Structures

struct esx_device
{
   uint8_t  path;    // bits 7..3 = major, bits 2..0 = minor
   uint8_t  flags;
   uint32_t size;    // device size in blocks
};

struct esx_p3_hdr
{
   uint8_t  type;    // 0 = program, 1 = numeric array, 2 = char array, 3 = code
   uint16_t length;
   uint8_t  data[4];
   uint8_t  unused;
};

struct esx_stat
{
   uint8_t  drive;
   uint8_t  device;
   uint8_t  attr;
   uint32_t date;
   uint32_t size;
};

//
// SELECT APPROPRIATE ESXDOS INTERFACE
//
// When esxdos is used from within esxdos, such as from dot commands,
// it expects parameters to be passed in the hl register pair.
//
// However when general programs use esxdos, it expects those same
// parameters to be passed in ix.
//
// To solve this, the toolchain indicates a dot command is being
// generated through -D__ESXDOS_DOT_COMMAND so that macros here can
// select the proper interface to esxdos automatically.
//
// Programs can also call the dot/ram versions of the esxdos interface
// directly if needed.
//

#ifdef __ESXDOS_DOT_COMMAND

// TOOLCHAIN IS GENERATING A DOT COMMAND

#define esxdos_disk_info     esxdos_dot_disk_info
#define esxdos_disk_read     esxdos_dot_disk_read
#define esxdos_disk_write    esxdos_dot_disk_write

#define esxdos_m_getdrv      esxdos_dot_m_getdrv
#define esxdos_m_setdrv      esxdos_dot_m_setdrv
#define esxdos_m_gethandle   esxdos_dot_m_gethandle
#define esxdos_m_getdate     esxdos_dot_m_getdate

#define esxdos_f_opendir     esxdos_dot_f_opendir
#define esxdos_f_opendir_p3  esxdos_dot_f_opendir_p3
#define esxdos_f_readdir     esxdos_dot_f_readdir
#define esxdos_f_getcwd      esxdos_dot_f_getcwd
#define esxdos_f_chdir       esxdos_dot_f_chdir
#define esxdos_f_unlink      esxdos_dot_f_unlink

#define esxdos_f_open        esxdos_dot_f_open
#define esxdos_f_open_p3     esxdos_dot_f_open_p3
#define esxdos_f_close       esxdos_dot_f_close
#define esxdos_f_sync        esxdos_dot_f_sync
#define esxdos_f_fstat       esxdos_dot_f_fstat
#define esxdos_f_fgetpos     esxdos_dot_f_fgetpos
#define esxdos_f_seek        esxdos_dot_f_seek
#define esxdos_f_read        esxdos_dot_f_read
#define esxdos_f_write       esxdos_dot_f_write

#else

// TOOLCHAIN IS NOT GENERATING A DOT COMMAND

#define esxdos_disk_info     esxdos_ram_disk_info
#define esxdos_disk_read     esxdos_ram_disk_read
#define esxdos_disk_write    esxdos_ram_disk_write

#define esxdos_m_getdrv      esxdos_ram_m_getdrv
#define esxdos_m_setdrv      esxdos_ram_m_setdrv
#define esxdos_m_gethandle   esxdos_ram_m_gethandle
#define esxdos_m_getdate     esxdos_ram_m_getdate

#define esxdos_f_opendir     esxdos_ram_f_opendir
#define esxdos_f_opendir_p3  esxdos_ram_f_opendir_p3
#define esxdos_f_readdir     esxdos_ram_f_readdir
#define esxdos_f_getcwd      esxdos_ram_f_getcwd
#define esxdos_f_chdir       esxdos_ram_f_chdir
#define esxdos_f_unlink      esxdos_ram_f_unlink

#define esxdos_f_open        esxdos_ram_f_open
#define esxdos_f_open_p3     esxdos_ram_f_open_p3
#define esxdos_f_close       esxdos_ram_f_close
#define esxdos_f_sync        esxdos_ram_f_sync
#define esxdos_f_fstat       esxdos_ram_f_fstat
#define esxdos_f_fgetpos     esxdos_ram_f_fgetpos
#define esxdos_f_seek        esxdos_ram_f_seek
#define esxdos_f_read        esxdos_ram_f_read
#define esxdos_f_write       esxdos_ram_f_write

#endif

//
// ESXDOS FROM DOT COMMANDS
//

// Raw Disk IO on Specific Device

extern int __LIB__ esxdos_dot_disk_info(unsigned char device,struct esx_device *ed) __smallc;
extern int __LIB__ __CALLEE__ esxdos_dot_disk_info_callee(unsigned char device,struct esx_device *ed) __smallc;
#define esxdos_dot_disk_info(a,b) esxdos_dot_disk_info_callee(a,b)


extern int __LIB__ esxdos_dot_disk_read(unsigned char device,uint32_t position,void *dst) __smallc;
extern int __LIB__ __CALLEE__ esxdos_dot_disk_read_callee(unsigned char device,uint32_t position,void *dst) __smallc;
#define esxdos_dot_disk_read(a,b,c) esxdos_dot_disk_read_callee(a,b,c)


extern int __LIB__ esxdos_dot_disk_write(unsigned char device,uint32_t position,void *src) __smallc;
extern int __LIB__ __CALLEE__ esxdos_dot_disk_write_callee(unsigned char device,uint32_t position,void *src) __smallc;
#define esxdos_dot_disk_write(a,b,c) esxdos_dot_disk_write_callee(a,b,c)



// Miscellaneous

extern unsigned char __LIB__ esxdos_dot_m_getdrv(void) __smallc;


extern unsigned char __LIB__ __FASTCALL__ esxdos_dot_m_setdrv(unsigned char drive) __smallc;



extern unsigned char __LIB__ esxdos_dot_m_gethandle(void) __smallc;



extern uint32_t __LIB__ esxdos_dot_m_getdate(void) __smallc;



// Operations on Directories

extern unsigned char __LIB__ __FASTCALL__ esxdos_dot_f_opendir(void *pathname) __smallc;


extern unsigned char __LIB__ __FASTCALL__ esxdos_dot_f_opendir_p3(void *pathname) __smallc;


extern unsigned char __LIB__ esxdos_dot_f_readdir(unsigned char handle,void *dirent) __smallc;
extern unsigned char __LIB__ __CALLEE__ esxdos_dot_f_readdir_callee(unsigned char handle,void *dirent) __smallc;
#define esxdos_dot_f_readdir(a,b) esxdos_dot_f_readdir_callee(a,b)



extern int __LIB__ __FASTCALL__ esxdos_dot_f_getcwd(void *buf) __smallc;



extern int __LIB__ __FASTCALL__ esxdos_dot_f_chdir(void *pathname) __smallc;



extern int __LIB__ __FASTCALL__ esxdos_dot_f_unlink(void *filename) __smallc;



// Operations on Files

extern unsigned char __LIB__ esxdos_dot_f_open(void *filename,unsigned char mode) __smallc;
extern unsigned char __LIB__ __CALLEE__ esxdos_dot_f_open_callee(void *filename,unsigned char mode) __smallc;
#define esxdos_dot_f_open(a,b) esxdos_dot_f_open_callee(a,b)


extern unsigned char __LIB__ esxdos_dot_f_open_p3(void *filename,unsigned char mode,struct esx_p3_hdr *h) __smallc;
extern unsigned char __LIB__ __CALLEE__ esxdos_dot_f_open_p3_callee(void *filename,unsigned char mode,struct esx_p3_hdr *h) __smallc;
#define esxdos_dot_f_open_p3(a,b,c) esxdos_dot_f_open_p3_callee(a,b,c)


extern int __LIB__ __FASTCALL__ esxdos_dot_f_close(unsigned char handle) __smallc;



extern int __LIB__ __FASTCALL__ esxdos_dot_f_sync(unsigned char handle) __smallc;


extern int __LIB__ esxdos_dot_f_fstat(unsigned char handle,struct esx_stat *es) __smallc;
extern int __LIB__ __CALLEE__ esxdos_dot_f_fstat_callee(unsigned char handle,struct esx_stat *es) __smallc;
#define esxdos_dot_f_fstat(a,b) esxdos_dot_f_fstat_callee(a,b)


extern uint32_t __LIB__ __FASTCALL__ esxdos_dot_f_fgetpos(unsigned char handle) __smallc;



extern uint32_t __LIB__ esxdos_dot_f_seek(unsigned char handle,uint32_t distance,unsigned char whence) __smallc;
extern uint32_t __LIB__ __CALLEE__ esxdos_dot_f_seek_callee(unsigned char handle,uint32_t distance,unsigned char whence) __smallc;
#define esxdos_dot_f_seek(a,b,c) esxdos_dot_f_seek_callee(a,b,c)


extern int __LIB__ esxdos_dot_f_read(unsigned char handle,void *dst,size_t nbytes) __smallc;
extern int __LIB__ __CALLEE__ esxdos_dot_f_read_callee(unsigned char handle,void *dst,size_t nbytes) __smallc;
#define esxdos_dot_f_read(a,b,c) esxdos_dot_f_read_callee(a,b,c)


extern int __LIB__ esxdos_dot_f_write(unsigned char handle,void *src,size_t nbytes) __smallc;
extern int __LIB__ __CALLEE__ esxdos_dot_f_write_callee(unsigned char handle,void *src,size_t nbytes) __smallc;
#define esxdos_dot_f_write(a,b,c) esxdos_dot_f_write_callee(a,b,c)



//
// ESXDOS FROM GENERAL RAM
//

// Raw Disk IO on Specific Device

extern int __LIB__ esxdos_ram_disk_info(unsigned char device,struct esx_device *ed) __smallc;
extern int __LIB__ __CALLEE__ esxdos_ram_disk_info_callee(unsigned char device,struct esx_device *ed) __smallc;
#define esxdos_ram_disk_info(a,b) esxdos_ram_disk_info_callee(a,b)


extern int __LIB__ esxdos_ram_disk_read(unsigned char device,uint32_t position,void *dst) __smallc;
extern int __LIB__ __CALLEE__ esxdos_ram_disk_read_callee(unsigned char device,uint32_t position,void *dst) __smallc;
#define esxdos_ram_disk_read(a,b,c) esxdos_ram_disk_read_callee(a,b,c)


extern int __LIB__ esxdos_ram_disk_write(unsigned char device,uint32_t position,void *src) __smallc;
extern int __LIB__ __CALLEE__ esxdos_ram_disk_write_callee(unsigned char device,uint32_t position,void *src) __smallc;
#define esxdos_ram_disk_write(a,b,c) esxdos_ram_disk_write_callee(a,b,c)



// Miscellaneous

extern unsigned char __LIB__ esxdos_ram_m_getdrv(void) __smallc;


extern unsigned char __LIB__ __FASTCALL__ esxdos_ram_m_setdrv(unsigned char drive) __smallc;



extern unsigned char __LIB__ esxdos_ram_m_gethandle(void) __smallc;



extern uint32_t __LIB__ esxdos_ram_m_getdate(void) __smallc;



// Operations on Directories

extern unsigned char __LIB__ __FASTCALL__ esxdos_ram_f_opendir(void *pathname) __smallc;


extern unsigned char __LIB__ __FASTCALL__ esxdos_ram_f_opendir_p3(void *pathname) __smallc;


extern unsigned char __LIB__ esxdos_ram_f_readdir(unsigned char handle,void *dirent) __smallc;
extern unsigned char __LIB__ __CALLEE__ esxdos_ram_f_readdir_callee(unsigned char handle,void *dirent) __smallc;
#define esxdos_ram_f_readdir(a,b) esxdos_ram_f_readdir_callee(a,b)



extern int __LIB__ __FASTCALL__ esxdos_ram_f_getcwd(void *buf) __smallc;



extern int __LIB__ __FASTCALL__ esxdos_ram_f_chdir(void *pathname) __smallc;



extern int __LIB__ __FASTCALL__ esxdos_ram_f_unlink(void *filename) __smallc;



// Operations on Files

extern unsigned char __LIB__ esxdos_ram_f_open(void *filename,unsigned char mode) __smallc;
extern unsigned char __LIB__ __CALLEE__ esxdos_ram_f_open_callee(void *filename,unsigned char mode) __smallc;
#define esxdos_ram_f_open(a,b) esxdos_ram_f_open_callee(a,b)


extern unsigned char __LIB__ esxdos_ram_f_open_p3(void *filename,unsigned char mode,struct esx_p3_hdr *h) __smallc;
extern unsigned char __LIB__ __CALLEE__ esxdos_ram_f_open_p3_callee(void *filename,unsigned char mode,struct esx_p3_hdr *h) __smallc;
#define esxdos_ram_f_open_p3(a,b,c) esxdos_ram_f_open_p3_callee(a,b,c)


extern int __LIB__ __FASTCALL__ esxdos_ram_f_close(unsigned char handle) __smallc;



extern int __LIB__ __FASTCALL__ esxdos_ram_f_sync(unsigned char handle) __smallc;


extern int __LIB__ esxdos_ram_f_fstat(unsigned char handle,struct esx_stat *es) __smallc;
extern int __LIB__ __CALLEE__ esxdos_ram_f_fstat_callee(unsigned char handle,struct esx_stat *es) __smallc;
#define esxdos_ram_f_fstat(a,b) esxdos_ram_f_fstat_callee(a,b)


extern uint32_t __LIB__ __FASTCALL__ esxdos_ram_f_fgetpos(unsigned char handle) __smallc;



extern uint32_t __LIB__ esxdos_ram_f_seek(unsigned char handle,uint32_t distance,unsigned char whence) __smallc;
extern uint32_t __LIB__ __CALLEE__ esxdos_ram_f_seek_callee(unsigned char handle,uint32_t distance,unsigned char whence) __smallc;
#define esxdos_ram_f_seek(a,b,c) esxdos_ram_f_seek_callee(a,b,c)


extern int __LIB__ esxdos_ram_f_read(unsigned char handle,void *dst,size_t nbytes) __smallc;
extern int __LIB__ __CALLEE__ esxdos_ram_f_read_callee(unsigned char handle,void *dst,size_t nbytes) __smallc;
#define esxdos_ram_f_read(a,b,c) esxdos_ram_f_read_callee(a,b,c)


extern int __LIB__ esxdos_ram_f_write(unsigned char handle,void *src,size_t nbytes) __smallc;
extern int __LIB__ __CALLEE__ esxdos_ram_f_write_callee(unsigned char handle,void *src,size_t nbytes) __smallc;
#define esxdos_ram_f_write(a,b,c) esxdos_ram_f_write_callee(a,b,c)




#endif
