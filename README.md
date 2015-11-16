# api_wrapper
when we call some undocumented API, we should firstly declare the function type ,and then use LoadLibrary/GetProcAddress to get the API address. api_wrapper try to reduce such ugly work.

# usage
when call NtCreateFile
```C++
R3API<NTSTATUS> fNtCreateFile("ntdll.dll", "NtCreateFile");
if(fNtCreateFile)
{
  NTSTATUS Status = fNtCreateFile(&devName,
    		SYNCHRONIZE | GENERIC_READ | FILE_READ_ATTRIBUTES,
    		&oa,
    		&Iosb,
    		NULL,
    		FILE_ATTRIBUTE_NORMAL,
    		0,
    		FILE_OPEN,
    		FILE_DIRECTORY_FILE,
    		NULL,
    		0);
}
```

R3API has two template argument, return type, call mode (default mode is std_call)
