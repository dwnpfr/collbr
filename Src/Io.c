#include <Windows.h>

#include "Ctx.h"
#include "Defs.h"
#include "Io.h"

#ifdef Col_Os_Windows
typedef tUSz _tFile;
#define _tFile_Err (_tFile)((tSSz)(-1))

#elif defined(Col_Os_Osx)
#error 'Osx is unimplemented.'

#elif defined(Col_Os_Linux)
typedef tU32 _tFile;
#define _tFile_Err (_tFile)((tInt)(-1))

#else
#error 'Err: Unknown operative system.'
#endif

tUSz strLng(const tChr *strng)
{
	for (tUSz iI = tUSz_Min; iI < tUSz_Max; ++iI) if (strng[iI] == '\0') return iI;
	return tUSz_Max;
}

enum _eFilePrms
{
	_eFP_Rd,
	_eFP_Wr,
	_eFP_Ap
};

struct _tFileMd
{
	enum _eFilePrms prms;
	tBln bnry;
	tBln updt;
	tBln exclsv;
};

static tBln _parseMode(struct _tFileMd *flMd, const tChr *strng)
{
	struct _tFileMd md = {0};
	if (strng[0] == 'W' || strng[0] == 'w') md.prms = _eFP_Wr;
	else if (strng[0] == 'R' || strng[0] == 'r') md.prms = _eFP_Rd;
	else if (strng[0] == 'A' || strng[0] == 'a') md.prms = _eFP_Ap;
	else return False;
	for (tUSz iI = 1LLU; strng[iI] != '\0'; ++iI)
	{
		if (strng[iI] == '+')
		{
			if (md.updt == True) return False;
			md.updt = True;
		}
		else if (strng[iI] == 'B' || strng[iI] == 'b')
		{
			if (md.bnry == True) return False;
			md.bnry = True;
		}
		else if (strng[iI] == 'X' || strng[iI] == 'x')
		{
			if (md.exclsv == True) return False;
			md.exclsv = True;
		}
		else return False;
	}
	*flMd = md;
	return True;
}

#ifdef Col_Os_Windows
static _tFile __tFile_WOpen(const tWChr *filePath, const tChr *md)
{
	if (md == Null)
	{
		//TODO(dwnpfr): Set error.
		return _tFile_Err;
	}

	tUSz accss = tUSz_Min;
	tUSz disp = tUSz_Min;

	struct _tFileMd flMd = {0};
	if (!_parseMode(&flMd, md))
	{
		//TODO(dwnpfr): Set error.
		return _tFile_Err;
	}

	if (flMd.prms == _eFP_Wr)
	{
		accss |= GENERIC_WRITE;
		disp |= CREATE_ALWAYS;
	}
	else if (flMd.prms == _eFP_Rd)
	{
		accss |= GENERIC_READ;
		disp |= OPEN_EXISTING;
	}
	else
	{
		//TODO(dwnpfr): Set error.
		return _tFile_Err;
	}

	_tFile ret = (_tFile)CreateFileW(filePath, accss, 0U, NULL, disp, FILE_ATTRIBUTE_NORMAL, NULL);

	if (ret == (_tFile)INVALID_HANDLE_VALUE) pass; //TODO(dwnpfr): Set error.
	return ret;
}

static _tFile __tFile_AOpen(const tChr *filePath, const tChr *md)
{
	if (md == Null)
	{
		//TODO(dwnpfr): Set error.
		return _tFile_Err;
	}

	tUSz accss = tUSz_Min;
	tUSz disp = tUSz_Min;

	struct _tFileMd flMd = {0};
	if (!_parseMode(&flMd, md))
	{
		//TODO(dwnpfr): Set error.
		return _tFile_Err;
	}

	if (flMd.prms == _eFP_Wr)
	{
		accss |= GENERIC_WRITE;
		disp |= CREATE_ALWAYS;
	}
	else if (flMd.prms == _eFP_Rd)
	{
		accss |= GENERIC_READ;
		disp |= OPEN_EXISTING;
	}
	else
	{
		//TODO(dwnpfr): Set error.
		return _tFile_Err;
	}

	_tFile ret = (_tFile)CreateFileA(filePath, accss, 0U, NULL, disp, FILE_ATTRIBUTE_NORMAL, NULL);

	if (ret == (_tFile)INVALID_HANDLE_VALUE) pass; //TODO(dwnpfr): Set error.
	return ret;
}
#else
#error 'Not implemented.'
#endif


static void _tFile_Close_(_tFile *fl)
{
#ifdef Col_Os_Windows
	CloseHandle((tPtr)*fl);
#else
#error 'Not implemented.'
#endif
	*fl = _tFile_Err;
}

static tBln _tFile_Out_(_tFile fl, const tAChr *bffr)
{
	tUSz lng = strLng(bffr);
	tUSz bytesWritten = 0LLU;
	tInt ret = WriteFile((HANDLE)fl, bffr, lng, &bytesWritten, Null);
	if (ret != False) return True;
	else
	{
		if (lng != bytesWritten) pass; //TODO(dwnpfr): Set error.
		else pass; //TODO(dwnpfr): Set error.
	}
	return False;
}