#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "register.h"


struct regiserStrut
{
	int size;   
    int used;
    regiserEnum _register; 
}registerType[5] = {
	{0, 0, ebx},
    {0, 0, edx},
    {0, 0, ecx},
    {0, 0, esi},
    {0, 0, edi}
};

regiserEnum getUnUseRegister() 
{
	regiserEnum _registerEnum;
	for(int i = 0; i < 5; i++) 
	{
		if(registerType[i].used == 0) 
		{
			registerType[i].used = 1;
			_registerEnum = registerType[i]._register;
			lockRegister(_registerEnum);
			break;
		}
	}
	return _registerEnum;
}


void initRegister(regiserEnum reg, int size)
{
	for(int i = 0; i < 5; i++)
	{
		if(registerType[i]._register == reg) 
		{
			registerType[i].size = size;
			regiserEnum _registerEnum = registerType[i]._register;
			printf("\tmovl\t%s,\t-%d(%%ebp)\n", getRegisterName(reg), registerType[i].size);
			break;
		}
	}
}

void lockRegister(regiserEnum reg)
{
	for(int i = 0; i < 5; i++)
	{
		if(registerType[i]._register == reg) 
		{	
			//printf("lock%s\n", getRegisterName(reg));
			registerType[i].used = 1;
			break;
		}
	}
}

void unLockRegister(regiserEnum reg)
{
	for(int i = 0; i < 5; i++)
	{
		if(registerType[i]._register == reg) 
		{
			//printf("unlock%s\n", getRegisterName(reg));
			registerType[i].used = 0;
			break;
		}
	}
}

char *getRegisterName(regiserEnum reg) 
{
	char* s = (char*)calloc(10,   sizeof(char*)); 
	switch(reg) 
	{
		case ebx: 
			strcpy (s, "%ebx");
			break;
		case edx: 
			strcpy (s, "%edx");
			break;
		case ecx: 
			strcpy (s, "%ecx");
			break;
		case esi: 
			strcpy (s, "%esi");
			break;
		case eax:
			strcpy (s, "%eax");
			break;
		case edi:
			strcpy (s, "%edi");
			break;
	}
	return s;
}

void releaseRegister(regiserEnum reg) 
{
	for(int i = 0; i < 5; i++) 
	{
		if(registerType[i]._register == reg) 
		{
			printf("\tmovl\t-%d(%%ebp),\t%s\n", registerType[i].size, getRegisterName(reg));
			registerType[i].size = 0;
			break;
		}
	}
}
