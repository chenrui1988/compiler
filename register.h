#ifndef register_table_h_included
#define register_table_h_included

typedef enum {edx, ecx, ebx, esi, edi, eax} regiserEnum;

regiserEnum getUnUseRegister();
void initRegister(regiserEnum reg, int size);
void lockRegister(regiserEnum reg);
void unLockRegister(regiserEnum reg);
char *getRegisterName(regiserEnum reg);
void releaseRegister(regiserEnum reg);



#endif