/*******************************************************************************
* Author	: zhaozhongshu@baidu.com
* Date	    : 2015-08-07 16:54:35
********************************************************************************/
#pragma once

enum CALL_MODE
{
	default_call,
	cdecl_call,
	fast_call,
	std_call,
};
template<typename T>
struct TYPE_HOLDER
{
};
#define RET(x)	((TYPE_HOLDER<x>*)NULL)

template<CALL_MODE mode,typename RVal>
struct BASE_CALL
{
	PVOID addr;

	operator bool()
	{
		return addr != NULL;
	}

	__forceinline RVal operator()()
	{ 
		switch(mode)
		{
		case std_call:
			return (static_cast<RVal(_stdcall* )()>(addr))();
		case fast_call:
			return (static_cast<RVal(_fastcall*)()>(addr))();
		case cdecl_call:
			return (static_cast<RVal(_cdecl*   )()>(addr))();
		default:
			return (static_cast<RVal(*         )()>(addr))();
		}
	}

	template<typename T1> 
	__forceinline RVal operator()(T1 v1)
	{ 
		switch(mode)
		{
		case std_call:
			return (static_cast<RVal(_stdcall* )(T1)>(addr))(v1);
		case fast_call:
			return (static_cast<RVal(_fastcall*)(T1)>(addr))(v1);
		case cdecl_call:
			return (static_cast<RVal(_cdecl*   )(T1)>(addr))(v1);
		default:
			return (static_cast<RVal(*         )(T1)>(addr))(v1);
		}
	}

	template<typename T1, typename T2> 
	__forceinline RVal operator()(T1 v1, T2 v2)
	{ 
		switch(mode)
		{
		case std_call:
			return (static_cast<RVal(_stdcall* )(T1,T2)>(addr))(v1,v2);
		case fast_call:
			return (static_cast<RVal(_fastcall*)(T1,T2)>(addr))(v1,v2);
		case cdecl_call:
			return (static_cast<RVal(_cdecl*   )(T1,T2)>(addr))(v1,v2);
		default:
			return (static_cast<RVal(*         )(T1,T2)>(addr))(v1,v2);
		}
	}

	template<typename T1, typename T2, typename T3> 
	__forceinline RVal operator()(T1 v1, T2 v2, T3 v3)
	{ 
		switch(mode)
		{
		case std_call:
			return (static_cast<RVal(_stdcall* )(T1,T2,T3)>(addr))(v1,v2,v3);
		case fast_call:
			return (static_cast<RVal(_fastcall*)(T1,T2,T3)>(addr))(v1,v2,v3);
		case cdecl_call:
			return (static_cast<RVal(_cdecl*   )(T1,T2,T3)>(addr))(v1,v2,v3);
		default:
			return (static_cast<RVal(*         )(T1,T2,T3)>(addr))(v1,v2,v3);
		}
	}

	template<typename T1, typename T2, typename T3, typename T4> 
	__forceinline RVal operator()(T1 v1, T2 v2, T3 v3, T4 v4)
	{ 
		switch(mode)
		{
		case std_call:
			return (static_cast<RVal(_stdcall *)(T1,T2,T3,T4)>(addr))(v1,v2,v3,v4);
		case fast_call:
			return (static_cast<RVal(_fastcall*)(T1,T2,T3,T4)>(addr))(v1,v2,v3,v4);
		case cdecl_call:
			return (static_cast<RVal(_cdecl   *)(T1,T2,T3,T4)>(addr))(v1,v2,v3,v4);
		default:
			return (static_cast<RVal(*         )(T1,T2,T3,T4)>(addr))(v1,v2,v3,v4);
		}
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5> 
	__forceinline RVal operator()(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5)
	{ 
		switch(mode)
		{
		case std_call:
			return (static_cast<RVal(_stdcall *)(T1,T2,T3,T4,T5)>(addr))(v1,v2,v3,v4,v5);
		case fast_call:
			return (static_cast<RVal(_fastcall*)(T1,T2,T3,T4,T5)>(addr))(v1,v2,v3,v4,v5);
		case cdecl_call:
			return (static_cast<RVal(_cdecl   *)(T1,T2,T3,T4,T5)>(addr))(v1,v2,v3,v4,v5);
		default:
			return (static_cast<RVal(*         )(T1,T2,T3,T4,T5)>(addr))(v1,v2,v3,v4,v5);
		}
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6> 
	__forceinline RVal operator()(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6)
	{ 
		switch(mode)
		{
		case std_call:
			return (static_cast<RVal(_stdcall *)(T1,T2,T3,T4,T5,T6)>(addr))(v1,v2,v3,v4,v5,v6);
		case fast_call:
			return (static_cast<RVal(_fastcall*)(T1,T2,T3,T4,T5,T6)>(addr))(v1,v2,v3,v4,v5,v6);
		case cdecl_call:
			return (static_cast<RVal(_cdecl   *)(T1,T2,T3,T4,T5,T6)>(addr))(v1,v2,v3,v4,v5,v6);
		default:
			return (static_cast<RVal(*         )(T1,T2,T3,T4,T5,T6)>(addr))(v1,v2,v3,v4,v5,v6);
		}
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7> 
	__forceinline RVal operator()(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6, T7 v7)
	{ 
		switch(mode)
		{
		case std_call:
			return (static_cast<RVal(_stdcall *)(T1,T2,T3,T4,T5,T6,T7)>(addr))(v1,v2,v3,v4,v5,v6,v7);
		case fast_call:
			return (static_cast<RVal(_fastcall*)(T1,T2,T3,T4,T5,T6,T7)>(addr))(v1,v2,v3,v4,v5,v6,v7);
		case cdecl_call:
			return (static_cast<RVal(_cdecl   *)(T1,T2,T3,T4,T5,T6,T7)>(addr))(v1,v2,v3,v4,v5,v6,v7);
		default:
			return (static_cast<RVal(*         )(T1,T2,T3,T4,T5,T6,T7)>(addr))(v1,v2,v3,v4,v5,v6,v7);
		}
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8> 
	__forceinline RVal operator()(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6, T7 v7, T8 v8)
	{ 
		switch(mode)
		{
		case std_call:
			return (static_cast<RVal(_stdcall *)(T1,T2,T3,T4,T5,T6,T7,T8)>(addr))(v1,v2,v3,v4,v5,v6,v7,v8);
		case fast_call:
			return (static_cast<RVal(_fastcall*)(T1,T2,T3,T4,T5,T6,T7,T8)>(addr))(v1,v2,v3,v4,v5,v6,v7,v8);
		case cdecl_call:
			return (static_cast<RVal(_cdecl   *)(T1,T2,T3,T4,T5,T6,T7,T8)>(addr))(v1,v2,v3,v4,v5,v6,v7,v8);
		default:
			return (static_cast<RVal(*         )(T1,T2,T3,T4,T5,T6,T7,T8)>(addr))(v1,v2,v3,v4,v5,v6,v7,v8);
		}
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9> 
	__forceinline RVal operator()(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6, T7 v7, T8 v8, T9 v9)
	{ 
		switch(mode)
		{
		case std_call:
			return (static_cast<RVal(_stdcall *)(T1,T2,T3,T4,T5,T6,T7,T8,T9)>(addr))(v1,v2,v3,v4,v5,v6,v7,v8,v9);
		case fast_call:
			return (static_cast<RVal(_fastcall*)(T1,T2,T3,T4,T5,T6,T7,T8,T9)>(addr))(v1,v2,v3,v4,v5,v6,v7,v8,v9);
		case cdecl_call:
			return (static_cast<RVal(_cdecl   *)(T1,T2,T3,T4,T5,T6,T7,T8,T9)>(addr))(v1,v2,v3,v4,v5,v6,v7,v8,v9);
		default:
			return (static_cast<RVal(*         )(T1,T2,T3,T4,T5,T6,T7,T8,T9)>(addr))(v1,v2,v3,v4,v5,v6,v7,v8,v9);
		}
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10> 
	__forceinline RVal operator()(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6, T7 v7, T8 v8, T9 v9, T10 v10)
	{ 
		switch(mode)
		{
		case std_call:
			return (static_cast<RVal(_stdcall *)(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10)>(addr))(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10);
		case fast_call:
			return (static_cast<RVal(_fastcall*)(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10)>(addr))(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10);
		case cdecl_call:
			return (static_cast<RVal(_cdecl   *)(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10)>(addr))(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10);
		default:
			return (static_cast<RVal(*         )(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10)>(addr))(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10);
		}
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11> 
	__forceinline RVal operator()(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6, T7 v7, T8 v8, T9 v9, T10 v10, T11 v11)
	{ 
		switch(mode)
		{
		case std_call:
			return (static_cast<RVal(_stdcall *)(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11)>(addr))(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11);
		case fast_call:
			return (static_cast<RVal(_fastcall*)(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11)>(addr))(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11);
		case cdecl_call:
			return (static_cast<RVal(_cdecl   *)(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11)>(addr))(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11);
		default:
			return (static_cast<RVal(*         )(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11)>(addr))(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11);
		}
	}
};

template<typename RVal,CALL_MODE mode = std_call>
struct R3API : public BASE_CALL<mode, RVal>
{
	HMODULE hModule;
	__forceinline explicit R3API(const char* dllname, const char* apiname, bool bCurrentDir = false) : hModule(NULL)
	{
		addr = NULL;
		HMODULE hDll = GetModuleHandleA(dllname);
		if( hDll )
		{
			addr = GetProcAddress(hDll, apiname);
			return;
		}
		if( bCurrentDir )
		{
			char szDll[MAX_PATH] = {0};
			GetModuleFileNameA(NULL, szDll, MAX_PATH);
			char* tail = strrchr(szDll, '\\');
			if( tail )
			{
				tail++;
				*tail = '\0';
				strncat_s(szDll, MAX_PATH, dllname, _TRUNCATE);
			}
			hModule = LoadLibraryA(szDll);
		}
		else
		{
			hModule = LoadLibraryA(dllname);
		}
		if( hModule )
		{
			addr = GetProcAddress(hModule, apiname);
		}
	}

	__forceinline explicit R3API(HMODULE hModule, const char* apiname) : hModule(NULL)
	{
		addr = GetProcAddress(hModule, apiname);
	}

	__forceinline ~R3API()
	{
		if( hModule )
		{
			FreeLibrary(hModule);
			hModule = NULL;
		}
		addr = NULL;
	}
};


template<typename RVal,CALL_MODE mode = default_call>
struct R0API : public BASE_CALL<mode,RVal>
{
	__forceinline explicit R0API(const char* dllname, const char* apiname)
	{
		addr = NULL;
		HMODULE hDll = GetModuleHandleA(dllname);
		if( hDll )
		{
			addr = GetProcAddress(hDll, apiname);
			return;
		}
	}

	__forceinline explicit R0API(HANDLE hModule, const char* apiname)
	{
		addr = GetProcAddress(hModule, apiname);
	}

	__forceinline ~R0API()
	{
		addr = NULL;
	}
};