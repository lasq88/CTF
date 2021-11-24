// Decrypting_a_File.cpp : Defines the entry point for the console 
// application.
//


#include <tchar.h>
#include <stdio.h>
#include <windows.h>
#include <wincrypt.h>
#include <conio.h>

// Link with the Advapi32.lib file.
#pragma comment (lib, "advapi32")
#pragma warning(disable : 4996)
#pragma warning(disable : 4838)
#pragma warning(disable : 4309)

#define KEYLENGTH  0x00800000
#define ENCRYPT_ALGORITHM CALG_SHA_256 
#define ENCRYPT_BLOCK_SIZE 16 

bool MyDecryptFile(LPTSTR szSource);

void MyHandleError(
    const wchar_t* psz,
    int nErrorNumber);

void EndianSwap(unsigned int& x);

int _tmain(int argc, _TCHAR* argv[])
{
    if (argc < 2)
    {
        _tprintf(TEXT("Usage: <example.exe> <source file> ")
            TEXT("<destination file> | <password>\n"));
        _tprintf(TEXT("<password> is optional.\n"));
        _tprintf(TEXT("Press any key to exit."));
        _gettch();
        return 1;
    }

    LPTSTR pszSource = argv[1];
    

    //---------------------------------------------------------------
    // Call EncryptFile to do the actual encryption.
    if (MyDecryptFile(pszSource))
    {
        //_tprintf(TEXT("Decryption of the file %s was successful. \n"),pszSource);
    }
    else
    {
        MyHandleError(
            TEXT("Error decrypting file!\n"),
            GetLastError());
    }

    return 0;
}

//-------------------------------------------------------------------
// Code for the function MyDecryptFile called by main.
//-------------------------------------------------------------------
// Parameters passed are:
//  pszSource, the name of the input file, an encrypted file.
//  pszDestination, the name of the output, a plaintext file to be 
//   created.
bool MyDecryptFile(LPTSTR pszSourceFile)
{
    //---------------------------------------------------------------
    // Declare and initialize local variables.
    DWORD dwKeyBlobLen = 48;
    BYTE blobdata_1[12] = { 0x08, 0x02, 0x00, 0x00, 0x10, 0x66, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00 };
    BYTE blobdata_2[16] = { 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0x00, 0x00, 0x00, 0x00 };
    BYTE blob[48] = { 0 };
    BYTE myIV[] = { 0x30, 0x30, 0x31, 0x30, 0x30, 0x30, 0x30, 0x33, 0x30, 0x30, 0x30, 0x30, 0x33, 0x30, 0x30, 0x37 };
    
    bool fReturn = false;
    bool fEOF = false;
    HANDLE hSourceFile = INVALID_HANDLE_VALUE;
    LARGE_INTEGER filesize;
    HCRYPTKEY hKey = NULL;
    HCRYPTHASH hHash = NULL;
    HCRYPTPROV hCryptProv = NULL;
    DWORD dwHashLen;
    DWORD dwHashLenSize = sizeof(DWORD);
    BYTE* pbHash;

    DWORD dwCount;
    PBYTE pbBuffer = NULL;
    PBYTE pbTempBuffer = NULL;
    DWORD dwBlockLen;
    DWORD dwBufferLen;
    PBYTE pbEndOfLine;

    char flag[7] = {0};
    unsigned int * pbOrgSize[4];
    unsigned int * pbHexNum[4];

    dwBlockLen = ENCRYPT_BLOCK_SIZE * 4;
    dwBufferLen = dwBlockLen;

    //---------------------------------------------------------------
        // Open the source file. 
    hSourceFile = CreateFile(
        pszSourceFile,
        FILE_READ_DATA,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);
    if (INVALID_HANDLE_VALUE != hSourceFile)
    {
        //_tprintf(TEXT("The source encrypted file, %s, is open. \n"),pszSourceFile);
        // Get File size
        if (!GetFileSizeEx(hSourceFile, &filesize))
        {
            CloseHandle(hSourceFile);
            MyHandleError(
                TEXT("Error calculating file size!\n"),
                GetLastError());
            return false;
        }
    }
    else
    {
        MyHandleError(
            TEXT("Error opening source plaintext file!\n"),
            GetLastError());
        return false;
    }

    // Read flag from source file

    if (!ReadFile(
        hSourceFile,
        flag,
        6,
        &dwCount,
        NULL))
    {
        MyHandleError(
            TEXT("Error reading from source file!\n"),
            GetLastError());
        CloseHandle(hSourceFile);
        return false;
    }

    // Read original file size from source file

    if (!ReadFile(
        hSourceFile,
        pbOrgSize,
        4,
        &dwCount,
        NULL))
    {
        MyHandleError(
            TEXT("Error reading from source file!\n"),
            GetLastError());
        CloseHandle(hSourceFile);
        return false;
    }

    // Read hex number size from source file

    if (!ReadFile(
        hSourceFile,
        pbHexNum,
        4,
        &dwCount,
        NULL))
    {
        MyHandleError(
            TEXT("Error reading from source file!\n"),
            GetLastError());
        CloseHandle(hSourceFile);
        return false;
    }

    // Allocate memory for the file read buffer. 
    if (!(pbBuffer = (PBYTE)malloc(filesize.QuadPart - 14)))
    {
        CloseHandle(hSourceFile);
        MyHandleError(TEXT("Out of memory!\n"), E_OUTOFMEMORY);
        return false;
    }

    if (!(pbTempBuffer = (PBYTE)malloc(filesize.QuadPart - 14)))
    {
        CloseHandle(hSourceFile);
        MyHandleError(TEXT("Out of memory!\n"), E_OUTOFMEMORY);
        return false;
    }

    //Read the encrypted data

    if (!ReadFile(
        hSourceFile,
        pbBuffer,
        filesize.QuadPart - 14,
        &dwCount,
        NULL))
    {
        MyHandleError(
            TEXT("Error reading from source file!\n"),
            GetLastError());
        CloseHandle(hSourceFile);
        return false;
    }

    //---------------------------------------------------------------
    // Get the handle to the default provider. 
    if (CryptAcquireContext(
        &hCryptProv,
        NULL,
        MS_ENH_RSA_AES_PROV,
        PROV_RSA_AES,
        4026531840))
    {
        //_tprintf(TEXT("A cryptographic provider has been acquired. \n"));
    }
    else
    {
        MyHandleError(
            TEXT("Error during CryptAcquireContext!\n"),
            GetLastError());
        //goto Exit_MyDecryptFile;
        return false;
    }

    for (int i = 0; i < 0xFF * 6; i++)
    {
        char keyString[120] = "";
        //--------------------------------------------------------------------
        // Create a hash.
        if (CryptCreateHash(
            hCryptProv,
            CALG_SHA1,
            0,
            0,
            &hHash))
        {
            //printf("An empty hash object has been created. \n");
        }
        else
        {
            MyHandleError(TEXT("Error during CryptCreateHash."), GetLastError());
            return false;
        }

        snprintf(keyString, 120, "YouTakeTheRedPillYouStayInWonderlandAndIShowYouHowDeepTheRabbitHoleGoes0mgisthebestg%08x%d---%d", *pbHexNum, *pbOrgSize, i);
        //printf("%s\n", keyString);

        //--------------------------------------------------------------------
        // Compute SHA-1 from the string.
        if (CryptHashData(
            hHash,
            (BYTE*)keyString,
            strlen(keyString),
            0))
        {
            //printf("Data has been hashed. \n");
        }
        else
        {
            MyHandleError(TEXT("Error during CryptCreateHash."), GetLastError());
            return false;
        }

        // Get hash size

        if (CryptGetHashParam(
            hHash,
            HP_HASHSIZE,
            (BYTE*)&dwHashLen,
            &dwHashLenSize,
            0))
        {
            // It worked. Do nothing.
        }
        else
        {
            MyHandleError(TEXT("CryptGetHashParam failed to get size."), GetLastError());
            return false;
        }

        // initialize memory

        if (pbHash = (BYTE*)malloc(dwHashLen))
        {
            // It worked. Do nothing.
        }
        else
        {
            MyHandleError(TEXT("Out of memory!\n"), E_OUTOFMEMORY);
            return false;
        }

        // Get the hash value

        if (CryptGetHashParam(
            hHash,
            HP_HASHVAL,
            pbHash,
            &dwHashLen,
            0))
        {
            // create blob
            memcpy(blob,blobdata_1,sizeof(blobdata_1));
            memcpy(blob + sizeof(blobdata_1), pbHash, dwHashLen);
            memcpy(blob + sizeof(blobdata_1) + dwHashLen, blobdata_2, sizeof(blobdata_2));

            /*Print the blob.
            for (int j = 0; j < sizeof(blob); j++)
            {
                printf("%02x ", blob[j]);
            }
            printf("\n");*/
        }
        else
        {
            MyHandleError(TEXT("Error during CryptGetHashParam."), GetLastError());
            return false;
        }

        // Import the key BLOB into the CSP. 
        if (!CryptImportKey(
            hCryptProv,
            blob,
            dwKeyBlobLen,
            0,
            0,
            &hKey))
        {
            MyHandleError(
                TEXT("Error during CryptImportKey!/n"),
                GetLastError());
            return false;
        }

        if (!CryptSetKeyParam(
            hKey,
            KP_IV,
            myIV,
            0))
        {
            MyHandleError(
                TEXT("Error during CryptSetKeyParam!/n"),
                GetLastError());
            return false;
        }

        dwCount = dwBlockLen;
        //printf("dwCount: %d\n",dwCount);

        memcpy(pbTempBuffer, pbBuffer, filesize.QuadPart - 14);
        
        /*printf("first bytes: ");
        for (int j = 0; j < 50; j++)
        {
            printf("%02x ", pbTempBuffer[j]);
        }
        printf("\n");*/

        //-----------------------------------------------------------
        // Decrypt the block of data. 
        if (CryptDecrypt(
            hKey,
            0,
            false,
            0,
            pbTempBuffer,
            &dwCount))
        {
            if (memcmp(flag, pbTempBuffer, 6) == 0)
            {
                printf("Congratz, you found a flag!\n");
                pbEndOfLine = (BYTE*)memchr(pbTempBuffer, 10, filesize.QuadPart);
                printf("%.*s\n", pbEndOfLine - pbTempBuffer, pbTempBuffer);
                break;
            }
        }
        else
        {
            MyHandleError(
                TEXT("Error during CryptDecrypt!\n"),
                GetLastError());
            return false;
        }
    }

    return true;
}


//-------------------------------------------------------------------
//  This example uses the function MyHandleError, a simple error
//  handling function, to print an error message to the  
//  standard error (stderr) file and exit the program. 
//  For most applications, replace this function with one 
//  that does more extensive error reporting.

void MyHandleError(const wchar_t* psz, int nErrorNumber)
{
    _ftprintf(stderr, TEXT("An error occurred in the program. \n"));
    _ftprintf(stderr, TEXT("%s\n"), psz);
    _ftprintf(stderr, TEXT("Error number %x.\n"), nErrorNumber);
}