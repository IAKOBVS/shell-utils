#ifndef SHELL_UTILS_DEF_H__
#define SHELL_UTILS_DEF_H__

#ifdef __cplusplus
#	define RESTRICT
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#	define RESTRICT restrict
#elif defined(__GNUC__) || defined(__clang__)
#	define RESTRICT __restrict__
#elif defined(_MSC_VER)
#	define RESTRICT __restrict
#else
#	define RESTRICT
#endif

#if defined(__GNUC__) || defined(__clang__)
#	define ALWAYS_INLINE __attribute__((always_inline)) inline
#elif defined(_MSC_VER)
#	define ALWAYS_INLINE __forceinline inline
#else
#	define ALWAYS_INLINE inline
#endif

#if defined(__PRETTY_FUNCTION__)
#	define CURR_FUNC __PRETTY_FUNCTION__
#elif defined(__FUNCTION__)
#	define CURR_FUNC __FUNCTION__
#elif defined(__func__)
#	define CURR_FUNC __func__
#else
#	define CURR_FUNC ""
#endif

#if (defined(__GNUC__) && (__GNUC__ >= 3)) || (defined(__clang__) && __has_builtin(__builtin_expect))
#	define likely(x) __builtin_expect(!!(x), 1)
#	define unlikely(x) __builtin_expect(!!(x), 0)
#else
#	define likely(x) (x)
#	define unlikely(x) (x)
#endif

#if defined(__GNUC__) || defined(__clang__)
#	if __has_attribute(pure)
#		define PURE __attribute__((pure))
#	else
#		define PURE
#	endif

#	if __has_attribute(const)
#		define CONST __attribute__((const))
#	else
#		define CONST
#	endif

#	if __has_attribute(flatten)
#		define FLATTEN __attribute__((flatten))
#	else
#		define FLATTEN
#	endif
#elif defined(_MSC_VER)
#	define PURE __declspec(noalias)
#	define CONST __declspec(restrict)
#	define FLATTEN
#else
#	define PURE
#	define CONST
#	define FLATTEN
#endif

#define CASE_VOWEL_LOWER case 'a': case 'i': case 'u': case 'e': case 'o':
#define CASE_VOWEL_UPPER case 'A': case 'I': case 'U': case 'E': case 'O':
#define CASE_VOWEL CASE_VOWEL_UPPER CASE_VOWEL_LOWER

#define CASE_CONSONANT_LOWER case 'b': case 'c': case 'd': case 'f': case 'g': case 'h': case 'j': case 'k': case 'l': case 'm': case 'n': case 'p': case 'q': case 'r': case 's': case 't': case 'v': case 'w': case 'x': case 'y': case 'z':
#define CASE_CONSONANT_UPPER case 'B': case 'C': case 'D': case 'F': case 'G': case 'H': case 'J': case 'K': case 'L': case 'M': case 'N': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'V': case 'W': case 'X': case 'Y': case 'Z':
#define CASE_CONSONANT CASE_CONSONANT_UPPER CASE_CONSONANT_LOWER

#define CASE_DIGIT case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
#define CASE_LOWER case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
#define CASE_UPPER case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z':

#define CASE_ALPHA CASE_LOWER CASE_UPPER
#define CASE_ALPHANUM CASE_DIGIT CASE_ALPHA

#include <stddef.h>
#include <sys/stat.h>
#include <stdio.h>

ALWAYS_INLINE
size_t sizeof_file(const char *RESTRICT filename)
{
	struct stat st;
	return !stat(filename, &st) ? st.st_size : 0;
}

ALWAYS_INLINE
int cat(char *RESTRICT buf,
		const char *RESTRICT filename,
		const size_t sizeof_file)
{
	FILE *fp = fopen(filename, "r");
	if (unlikely(!fp))
		return 0;
	fread(buf, 1, sizeof_file, fp);
	fclose(fp);
	*(buf + sizeof_file) = '\0';
	return 1;
}

#endif
