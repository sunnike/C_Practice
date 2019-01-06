/*
 ============================================================================
 Name        : C_Test.c
 Author      : John_Chen
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


/*
 ============================================================================
 Name        : Main.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <common.h>
#include <c100.h>


#define ASM_TIMER_SET 1

/* assembly code to read the TSC */

static inline QWORD RDTSC(){
unsigned int hi, lo;

  __asm__ volatile("rdtsc" : "=a" (lo), "=d" (hi));

  return ((QWORD)hi << 32) | (QWORD)lo;

}



int main(void) {
#if ASM_TIMER_SET
//int   hStart = 0, lStart = 0, hEnd = 0, lEnd = 0;
QWORD start, end;
#else
clock_t start, end;
#endif

#if ASM_TIMER_SET
	start = RDTSC();
#else
	start = clock();
#endif



	platfeau(platform, PLAT_LEN);

	end = RDTSC();


#if ASM_TIMER_SET
	printf("\nProgram elapse time: %I64d ns\n",end - start);
#else
	printf("\nProgram elapse time: %lu ms\n",(end -start));
#endif

	return EXIT_SUCCESS;
}
