/*
 * platform.c
 *
 *  Created on: 2019�~1��5��
 *      Author: John_Chen
 */
//=================================================================================================
// Include.
#include <stdio.h>
#include <stdlib.h>
#include <c100.h>
#include <common.h>


//=================================================================================================
// Define.



//=================================================================================================
// Global Variable.

int platform[PLAT_LEN] = 	{1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,4,4,5,5,5,
							 6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,
							 8,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9};

//=================================================================================================
// Program.
/* Looking for the longest platform */
int platfeau(int *plat, int plat_leng){
int head = 1, length = 1, pivot_index, Lnum = 0;

	pivot_index = head + 1;
	/* Check limitation. */
	while(pivot_index < plat_leng){
		if (plat[head] == plat[pivot_index]){
			Lnum = plat[pivot_index];
			length++;
			pivot_index++;
		}
		else{
			head = pivot_index;
			pivot_index += length;
		}
	}

	//printf("The longest platform number is:%d\n ; length:%d",Lnum ,length);
	return length;
}

//-----------------------------------------------------------------------------

