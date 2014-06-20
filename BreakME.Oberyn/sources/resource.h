static HINSTANCE hThisInstance = NULL;
HDC hdc, hdcmem;
HBITMAP hBmp, hOldBmp;
HWND txtEdit, btnOk, lblRight, lblWrong;

BOOL check(wchar_t buffer[]) {

	char url[94] =
		"https://raw.githubusercontent.com/tfairane/BreakME/master/BreakME.Oberyn/OberynSeriously.jpg";
	char secret[16] = { '\0' }, curl[16] = { '\0' };
	memcpy(curl, &url[73], 15);

	if (*(buffer + 0) == 'R')
		*(secret + 0) = 'O';
	if (*(buffer + 1) == 'I')
		*(secret + 1) = 'b';
	if (*(buffer + 2) == 'P')
		*(secret + 2) = 'e';
	if (*(buffer + 3) == 'P')
		*(secret + 3) = 'r';
	if (*(buffer + 4) == 'r')
		*(secret + 4) = 'y';
	if (*(buffer + 5) == 'i')
		*(secret + 5) = 'n';
	if (*(buffer + 6) == 'n')
		*(secret + 6) = 'S';
	if (*(buffer + 7) == 'c')
		*(secret + 7) = 'e';
	if (*(buffer + 8) == 'e')
		*(secret + 8) = 'r';
	if (*(buffer + 9) == 'O')
		*(secret + 9) = 'i';
	if (*(buffer + 10) == 'b')
		*(secret + 10) = 'o';
	if (*(buffer + 11) == 'e')
		*(secret + 11) = 'u';
	if (*(buffer + 12) == 'r')
		*(secret + 12) = 's';
	if (*(buffer + 13) == 'y')
		*(secret + 13) = 'l';
	if (*(buffer + 14) == 'n')
		*(secret + 14) = 'y';

	if (!strcmp(secret, curl))
		return TRUE;
	return FALSE;
}

BOOL PlayResource(LPCWSTR lpName) {
	BOOL bRtn;
	LPCWSTR lpRes;
	HRSRC hResInfo, hRes;

	// Find the WAVE resource.

	hResInfo = FindResource(hThisInstance, lpName, TEXT("WAVE"));
	if (hResInfo == NULL)
		return FALSE;

	// Load the WAVE resource.

	hRes = (HRSRC) LoadResource(hThisInstance, hResInfo);
	if (hRes == NULL)
		return FALSE;

	// Lock the WAVE resource and play it.

	lpRes = (LPCWSTR) LockResource(hRes);
	if (lpRes != NULL) {
		bRtn = sndPlaySound(lpRes, SND_MEMORY | SND_SYNC | SND_NODEFAULT);
		UnlockResource(hRes);
	} else
		bRtn = 0;

	// Free the WAVE resource and return success or failure.

	FreeResource(hRes);
	return bRtn;
}
