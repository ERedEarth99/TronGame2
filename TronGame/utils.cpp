//Utility file for progam. Store things like validation here.

typedef char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

#define global_variable static;
#define internal static;

//Clamp prevents the game from crashing by giving stable values to the rect, without it, the game can crash if shrunk to much
inline int
clamp(int min, int val, int max) {
	if (val < min) return min;
	if (val > max) return max;
	return val;
}