
#ifdef __cplusplus
extern "C"
{
#endif

extern void PrintFunc(int num);
//extern int insertElement(int type, int isConstant, char* VarName, int intval);
//extern int GetExistingVarLevel(char* VarName,int level);
extern void NewLevel();
extern void removeLevel();
extern char* InserNewElement(int type, int isconstant, char* name, int level, char* value);
extern char* InserNewElementInitial(int type, int isconstant, char* name, int level);
extern char* UpdateVal(int type, char *name, int level, char *data);
extern char* GetInfo(char* name, int level, int* type, int* isconstant, int* isset);
extern int GetIntVal(char* name, int level);
extern float GetFloatVal(char* name, int level);
extern char GetCharVal(char* name, int level);
extern int GetBoolVal(char* name, int level);
extern char* InserNewFunction(int type, char *name, int level);
extern char* InserNewArgument(int type, char *name, int level);
//extern char* GetValue(char* name, int level);
extern int InsertNewIntElement(int type, int isconstant, char* name, int level, int intVal);
extern int UpdateIntVal(int type, int isconstant, char* name, int level, int intVal);
#ifdef __cplusplus
}
#endif
