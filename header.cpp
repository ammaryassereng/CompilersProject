#include "header.h"

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct element
{
    int GlobalType;
    int type;
    int isConstant;
    string VarName;
    int leval;
    int intval;
    char charval;
    float floatval;
    bool boolvalue;
    bool IsSet;
};

ofstream myfile;

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

vector<unordered_map<string, element>> scopes; // will represent the symbol table in an entire scope

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

bool IsDigits(string str)
{
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (str[0] == '-')
            continue;
        if (!(str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9'))
            return false;
    }
    return true;
}

bool Isfloat(string str)
{
    bool foundDot = false;
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (str[0] == '-')
            continue;
        if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
            continue;
        else if (str[i] == '.' && foundDot == false)
            foundDot = true;
        else
            return false;
    }
    return true;
}

int GetExistingVarLevel(string VarName, int level)
{
    if (level < (int)scopes.size())
    {
        for (int i = level; i >= 0; i--)
        {
            if (scopes[i].find(VarName) != scopes[i].end())
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
    if (!myfile.is_open())
        myfile.open("SymbolTable.txt");
    unordered_map<string, element> val;
    scopes.push_back(val);
}

void removeLevel()
{
    int currlevel = scopes.size() - 1;
    myfile << "scoope Id: " << currlevel << endl;
    for (pair<string, element> Variable : scopes[currlevel])
    {
        string dataToPrint = Variable.second.VarName;

        if (Variable.second.GlobalType == 0)
            dataToPrint += " Variable";
        else if (Variable.second.GlobalType == 1)
            dataToPrint += " Function";
        else if (Variable.second.GlobalType == 2)
            dataToPrint += " Argument";

        if (Variable.second.type == 0)
            dataToPrint += " type: int";
        else if (Variable.second.type == 1)
            dataToPrint += " type: float";
        else if (Variable.second.type == 2)
            dataToPrint += " type: char";
        else if (Variable.second.type == 3)
            dataToPrint += " type: bool";

        if (Variable.second.GlobalType == 0)
        {
            if (Variable.second.type == 0)
                dataToPrint += ", value = " + to_string(Variable.second.intval);
            else if (Variable.second.type == 1)
                dataToPrint += ", value = " + to_string(Variable.second.floatval);
            else if (Variable.second.type == 2)
            {
                dataToPrint += ", value = " + to_string(Variable.second.charval);
            }
            else if (Variable.second.type == 3)
                dataToPrint += ", value = " + to_string(Variable.second.boolvalue);

            if (Variable.second.isConstant == true)
                dataToPrint += " Constant: true";
            else
                dataToPrint += " Constant: false";

            if (Variable.second.IsSet)
                dataToPrint += " initiallized: true";
            else
                dataToPrint += " initiallized: false";
        }
        myfile << dataToPrint << endl;
    }
    if (currlevel == 0)
    {
        myfile.close();
    }
    scopes.pop_back();
}

char *InserNewElement(int type, int isconstant, char *name, int level, char *value)
{
    string str = name;
    int Exist = GetExistingVarLevel(str, level);
    if (Exist == -1 || Exist != level)
    {
        string Val = value;
        struct element Nele;
        Nele.GlobalType = 0;
        Nele.type = type;
        Nele.isConstant = isconstant;
        Nele.VarName = str;
        Nele.IsSet = true;
        switch (type)
        {
        case 0:
        {
            if (Isfloat(Val))
                Nele.intval = stoi(Val);
            else
                return (char *)"ERROR! Type mismatch";
            break;
        }
        case 1:
            if (Isfloat(Val))
                Nele.floatval = stof(Val);
            else
                return (char *)"ERROR! Type mismatch";
            break;
        case 2:
        {
            if (str.size() == 0)
                Nele.charval = '\0';
            else
                Nele.charval = Val[0];
            break;
        }
        case 3:
        {
            if (Val == "1")
                Nele.boolvalue = true;
            else if (Val == "0")
                Nele.boolvalue = false;
            else
                return (char *)"ERROR! Type mismatch";
            break;
        }
        }
        scopes[level][str] = Nele;

        return (char *)"1";
    }
    return (char *)"ERROR! varialbe already declared";
}

char *InserNewElementInitial(int type, int isconstant, char *name, int level)
{
    string str = name;
    int Exist = GetExistingVarLevel(str, level);
    if (Exist == -1 || Exist != level)
    {
        struct element Nele;
        Nele.GlobalType = 0;
        Nele.type = type;
        Nele.isConstant = isconstant;
        Nele.VarName = str;
        Nele.IsSet = false;
        switch (type)
        {
        case 0:
            Nele.intval = 0;
            break;
        case 1:
            Nele.floatval = 0.0;
            break;
        case 2:
            Nele.charval = '\0';
            break;
        case 3:
            Nele.boolvalue = false;
            break;
        }
        scopes[level][str] = Nele;
        return (char *)"1";
    }
    return (char *)"ERROR! varialbe already declared";
}

char *InserNewFunction(int type, char *name, int level)
{
    string str = name;
    int Exist = GetExistingVarLevel(str, level);
    if (Exist == -1 || Exist != level)
    {
        struct element Nele;
        Nele.GlobalType = 1;
        Nele.type = type;
        Nele.VarName = str;
        Nele.IsSet = false;
        scopes[level][str] = Nele;
        return (char *)"1";
    }
    return (char *)"ERROR! Function name already declared";
}

char *InserNewArgument(int type, char *name, int level)
{
    string str = name;
    int Exist = GetExistingVarLevel(str, level);
    if (Exist == -1 || Exist != level)
    {
        struct element Nele;
        Nele.GlobalType = 2;
        Nele.type = type;
        Nele.VarName = str;
        Nele.IsSet = false;
        scopes[level][str] = Nele;
        return (char *)"1";
    }
    return (char *)"ERROR! Argument name already declared";
}

char *UpdateVal(int type, char *name, int level, char *data)
{
    string str = name;
    int Exist = GetExistingVarLevel(str, level);

    if (Exist == -1)
    {
        return (char *)"ERROR! varialbe not declared";
    }
    if (scopes[Exist][str].isConstant == 1)
    {
        return (char *)"ERROR! Cannot change the value of a const";
    }

    struct element Nele = scopes[Exist][str];
    Nele.IsSet = true;

    string Val = data;

    switch (scopes[Exist][str].type)
    {
    case 0:
    {
        if (Isfloat(Val) && type != 2)
            Nele.intval = stoi(Val);
        else
            return (char *)"ERROR! Type mismatch";
        break;
    }
    case 1:
        if (Isfloat(Val) && type != 2)
            Nele.floatval = stof(Val);
        else
            return (char *)"ERROR! Type mismatch";
        break;
    case 2:
    {
        if (type != 2)
        {
            return (char *)"ERROR! Type mismatch";
        }
        if (str.size() == 0)
            Nele.charval = '\0';
        else
            Nele.charval = Val[0];
        break;
    }
    case 3:
    {
        if (Val == "1" && type != 2)
            Nele.boolvalue = true;
        else if (Val == "0" && type != 2)
            Nele.boolvalue = false;
        else
            return (char *)"ERROR! Type mismatch";
        break;
    }
    }
    scopes[Exist][str] = Nele;
    return (char *)"1";
}

char *GetInfo(char *name, int level, int *type, int *isconstant, int *isset)
{
    string str = name;
    int Exist = GetExistingVarLevel(str, level);
    if (Exist == -1)
        return (char *)"ERROR! Variable not declared";

    *type = scopes[Exist][str].type;

    if (scopes[Exist][str].isConstant == true)
        *isconstant = 1;
    else
        *isconstant = 0;

    if (scopes[Exist][str].IsSet == true)
        *isset = 1;
    else
        *isset = 0;

    return (char *)"1";
}

char *GetFuncInfo(char *name, int level, int type)
{
    string str = name;
    int Exist = GetExistingVarLevel(str, level);
    if (Exist == -1)
        return (char *)"ERROR! Function not defined";
    
    if(scopes[Exist][str].GlobalType != 1)
    {
        return (char *)"ERROR! this is not a Function";
    }

    if(scopes[Exist][str].type != type)
    {
        return (char *)"ERROR! TYPE MISMATCH";
    }

    return (char *)"1";
}

int GetIntVal(char *name, int level)
{
    string str = name;
    int Exist = GetExistingVarLevel(str, level);

    if (Exist == -1 || scopes[Exist][str].type != 0)
    {
        return -1;
    }

    return scopes[Exist][str].intval;
}

float GetFloatVal(char *name, int level)
{
    string str = name;
    int Exist = GetExistingVarLevel(str, level);

    if (Exist == -1 || scopes[Exist][str].type != 1)
    {
        return -1;
    }

    return scopes[Exist][str].floatval;
}

char GetCharVal(char *name, int level)
{
    string str = name;
    int Exist = GetExistingVarLevel(str, level);

    if (Exist == -1 || scopes[Exist][str].type != 2)
    {
        return -1;
    }

    return scopes[Exist][str].charval;
}

int GetBoolVal(char *name, int level)
{
    string str = name;
    int Exist = GetExistingVarLevel(str, level);

    if (Exist == -1 || scopes[Exist][str].type != 3)
    {
        return -1;
    }

    if (scopes[Exist][str].boolvalue == true)
        return 1;
    return 0;
}

/*char* GetValue(char* name, int level)
{
    string str = name;
    int Exist = GetExistingVarLevel(str, level);

    if(Exist == -1 || scopes[Exist][str].IsSet == false)
        return (char*)"Error_Message";

    switch (scopes[Exist][str].type)
    {
    case 0:
    {
        //char* ret = to_string(scopes[Exist][str].intval);
        return &to_string(scopes[Exist][str].intval)[0];
    }
    case 1:
        return (char*)&to_string(scopes[Exist][str].floatval)[0];
    case 2:
        return &(scopes[Exist][str].charval);
    }
    return (char*)"Error_Message";
}*/

int getany(int &a)
{
    a = 5;
    return 4;
}

int InsertNewIntElement(int type, int isconstant, char *name, int level, int intVal)
{
    try
    {
        string str = name;
        int Exist = GetExistingVarLevel(str, level);
        // cout<<endl<<level<<endl<<endl;
        if (Exist == -1 || Exist != level)
        {
            struct element Nele;
            Nele.type = type;
            Nele.isConstant = isconstant;
            Nele.VarName = str;
            Nele.intval = intVal;
            scopes[level][str] = Nele;
            return 1;
        }

        return -1;
    }
    catch (int e)
    {
        return -1;
    }
}

int UpdateIntVal(int type, int isconstant, char *name, int level, int intVal)
{

    string str = name;

    int Exist = GetExistingVarLevel(str, level);

    if (Exist == -1 || scopes[Exist][str].type != type || type != 0)
    {
        return -1;
    }

    struct element Nele;
    Nele.type = type;
    Nele.isConstant = isconstant;
    Nele.VarName = str;
    Nele.intval = intVal;

    scopes[Exist][str] = Nele;
    return 1;
}

void PrintFunc(int num)
{
    cout << num << endl;
}