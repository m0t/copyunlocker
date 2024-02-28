#include<windows.h>

PVOID GetLibraryProcAddress(PSTR LibraryName, PSTR ProcName)
{
    return GetProcAddress(GetModuleHandleA(LibraryName), ProcName);
}

INT cmpstr( _In_ LPCSTR String1, _In_ LPCSTR String2 )
{
	for ( ; *String1 == *String2; String1++, String2++ )
	{
		if ( *String1 == '\0' )
        {
			return 0;
        };
	};
	return ( ( *( LPCSTR )String1 < *( LPCSTR )String2 ) ? -1 : +1 );
};

SIZE_T WCharStringToCharString(_Inout_ PCHAR Destination, _In_ PWCHAR Source, _In_ SIZE_T MaximumAllowed)
{
	INT Length = (INT)MaximumAllowed;

	while (--Length >= 0)
	{
		if (!(*Destination++ = *Source++))
			return MaximumAllowed - Length - 1;
	}

	return MaximumAllowed - Length;
}