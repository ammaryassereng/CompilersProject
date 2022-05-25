
#ifdef __cplusplus
extern "C"
{
#endif

extern void PrintFunc(int num);
//extern int insertElement(int type, int isConstant, char* VarName, int intval);
//extern int GetExistingVarLevel(char* VarName,int level);
extern void NewLevel();
extern void removeLevel();
extern int InsertNewIntElement(int type, int isconstant, char* name, int level, int intVal);
extern int UpdateIntVal(int type, int isconstant, char* name, int level, int intVal);
#ifdef __cplusplus
}
#endif
