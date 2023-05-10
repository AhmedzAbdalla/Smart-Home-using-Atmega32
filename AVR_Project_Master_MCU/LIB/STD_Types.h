#ifndef STD_TYPES_H
#define	STD_TYPES_H

#define NULL (void *) 0UL

typedef unsigned char	u8;
typedef unsigned short 	u16;
typedef unsigned int 	u32;

typedef signed char 	s8;
typedef signed short 	s16;
typedef signed int 		s32;

typedef float 			f32;
typedef double 			f64;

typedef enum STD_Return
{
	Not_OK = 0,
	OK,
	duplicate_id,
	id_found,
	slot_busy
}STD_Return_t;


#endif	/* STD_TYPES_H */
