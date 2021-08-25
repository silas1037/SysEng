#ifndef HEADER_C3CCF765386E5366
#define HEADER_C3CCF765386E5366

/*
	ALICE SOFT SYSTEM 3 for Win32

	[ Common Header ]
*/

#ifndef _COMMON_H_
#define _COMMON_H_

#include <SDL.h>
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <cstring>
#include <cwchar>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

#define FONT_RESOURCE_NAME "MTLc3m.ttf"

// type definition
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;

#define ERROR(fmt, ...) \
	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s:%d: " fmt, __func__, __LINE__, ##__VA_ARGS__)
#define WARNING(fmt, ...) \
	SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "%s:%d: " fmt, __func__, __LINE__, ##__VA_ARGS__)
#define NOTICE SDL_Log

#ifdef WIN32

#include <stdlib.h>

#define sscanf_s sscanf
#define sprintf_s snprintf

/*
inline void strcpy_s(char* dst, size_t n, const char* src)
{
	strncpy(dst, src, n);
	dst[n - 1] = '\0';
}
*/

#endif

#ifndef WIN32

#define _MAX_PATH PATH_MAX
#define sscanf_s sscanf
#define sprintf_s snprintf

/*
inline void strcpy_s(char* dst, size_t n, const char* src)
{
	strncpy(dst, src, n);
	dst[n - 1] = '\0';
}
*/

#endif // !WIN32

static inline bool is_1byte_message(uint8_t c) {
	return c == ' '; // || (0xa1 <= c && c <= 0xdd);
}

static inline bool is_2byte_message(uint8_t c) {
	return (0x81 <= c && c <= 0xfe) || 0xe0 <= c;
}

// resource.cpp
SDL_RWops* open_resource(const char* name, const char* type);
SDL_RWops* open_file(const char* name);

#endif
#endif // header guard

