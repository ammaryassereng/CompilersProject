#include"header.h"

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;


struct element
{
    int type;
    int isConstant;
    char* VarName;
    int leval;
    int intval;
    char charval;
    float floatval;
    bool boolvalue;
};

/*unordered_map<char*,struct element> SymbolTable;

int insertElement(int type, int isConstant, char* VarName, int intval)
{
    cout<<"I am here"<<endl;
    if(SymbolTable.find(VarName) != SymbolTable.end())
        return 0;    

    struct element Nele;
    Nele.type = type;
    Nele.isConstant = isConstant;
    Nele.VarName = VarName;
    Nele.intval = intval;

    SymbolTable[VarName] = Nele;

    return 1;
}*/

vector<unordered_map<char*,element>> scopes;   // will represent the symbol table in an entire scope

/*bool ExistingVar(char* VarName,int level)
{
    if(level < scopes.size())
    {
        for(int i = level; i >=0; i--)
        {
            if(scopes[level].find(VarName) != scopes[level].end())
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        return false;
    }
}*/

int GetExistingVarLevel(char* VarName,int level)
{
    if(level < (int) scopes.size())
    {
        for(int i = level; i >=0; i--)
        {
            if(scopes[level].find(VarName) != scopes[level].end())
            {
                return i;
            }
        }
        return -1;
    }
    else
    {
        return -1;
    }    
}

void NewLevel()
{
    unordered_map<char*,element> val;
    scopes.push_back(val);
}

void removeLevel()
{
    scopes.pop_back();
}

int InsertNewIntElement(int type, int isconstant, char* name, int level, int intVal)
{
    int Exist = GetExistingVarLevel(name, level);
    //cout<<endl<<level<<endl<<endl;
    if (Exist == -1 || Exist != level)
    {
        struct element Nele;
        Nele.type = type;
        Nele.isConstant = isconstant;
        Nele.VarName = name;
        Nele.intval = intVal;
    
        scopes[level][name] = Nele;
        return 1;        
    }

    return -1;

}

int UpdateIntVal(int type, int isconstant, char* name, int level, int intVal)
{
    int Exist = GetExistingVarLevel(name, level);

    if(Exist == -1 || scopes[Exist][name].type != type || type != 0 )
    {
        return -1;
    }

    struct element Nele;
    Nele.type = type;
    Nele.isConstant = isconstant;
    Nele.VarName = name;
    Nele.intval = intVal;
    
    scopes[Exist][name] = Nele;
    return 1;
}

void PrintFunc(int num)
{
    cout<<num<<endl;
}