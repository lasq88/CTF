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

#define KEYLENGTH  0x00800000
#define ENCRYPT_ALGORITHM CALG_SHA_256 
#define ENCRYPT_BLOCK_SIZE 16 

bool MyDecryptFile(
    LPTSTR szSource,
    LPTSTR szDestination,
    LPTSTR szPassword);

void MyHandleError(
    const wchar_t* psz,
    int nErrorNumber);

int _tmain(int argc, _TCHAR* argv[])
{
    if (argc < 3)
    {
        _tprintf(TEXT("Usage: <example.exe> <source file> ")
            TEXT("<destination file> | <password>\n"));
        _tprintf(TEXT("<password> is optional.\n"));
        _tprintf(TEXT("Press any key to exit."));
        _gettch();
        return 1;
    }

    LPTSTR pszSource = argv[1];
    LPTSTR pszDestination = argv[2];
    const char bytedata[16] = { 0x2f,0x6b,0x18,0xe4,0x9a,0x33,0xd9,0xc7,0xa0,0x31,0x46,0x1f,0x16,0x66,0x19,0xf7 };
    wchar_t wdata[16];
    mbstowcs(wdata, bytedata, 16);
    LPTSTR pszPassword = (LPTSTR)wdata;

    if (argc >= 4)
    {
        pszPassword = argv[3];
    }

    //---------------------------------------------------------------
    // Call EncryptFile to do the actual encryption.
    if (MyDecryptFile(pszSource, pszDestination, pszPassword))
    {
        _tprintf(
            TEXT("Decryption of the file %s was successful. \n"),
            pszSource);
        _tprintf(
            TEXT("The decrypted data is in file %s.\n"),
            pszDestination);
    }
    else
    {
        MyHandleError(
            TEXT("Error encrypting file!\n"),
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
//  pszPassword, either NULL if a password is not to be used or the 
//   string that is the password.
bool MyDecryptFile(
    LPTSTR pszSourceFile,
    LPTSTR pszDestinationFile,
    LPTSTR pszPassword)
{
    //---------------------------------------------------------------
    // Declare and initialize local variables.
    bool fReturn = false;
    bool fEOF = false;
    HANDLE hSourceFile = INVALID_HANDLE_VALUE;
    HANDLE hDestinationFile = INVALID_HANDLE_VALUE;
    HCRYPTKEY hKey = NULL;
    HCRYPTHASH hHash = NULL;

    HCRYPTPROV hCryptProv = NULL;

    DWORD dwCount;
    PBYTE pbBuffer = NULL;
    DWORD dwBlockLen;
    DWORD dwBufferLen;

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
        _tprintf(
            TEXT("The source encrypted file, %s, is open. \n"),
            pszSourceFile);
    }
    else
    {
        MyHandleError(
            TEXT("Error opening source plaintext file!\n"),
            GetLastError());
        goto Exit_MyDecryptFile;
    }

    //---------------------------------------------------------------
    // Open the destination file. 
    hDestinationFile = CreateFile(
        pszDestinationFile,
        FILE_WRITE_DATA,
        FILE_SHARE_READ,
        NULL,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL);
    if (INVALID_HANDLE_VALUE != hDestinationFile)
    {
        _tprintf(
            TEXT("The destination file, %s, is open. \n"),
            pszDestinationFile);
    }
    else
    {
        MyHandleError(
            TEXT("Error opening destination file!\n"),
            GetLastError());
        goto Exit_MyDecryptFile;
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
        _tprintf(
            TEXT("A cryptographic provider has been acquired. \n"));
    }
    else
    {
        MyHandleError(
            TEXT("Error during CryptAcquireContext!\n"),
            GetLastError());
        goto Exit_MyDecryptFile;
    }

    //---------------------------------------------------------------
    // Create the session key.
    if (!pszPassword || !pszPassword[0])
    {
        //-----------------------------------------------------------
        // Decrypt the file with the saved session key. 

        DWORD dwKeyBlobLen;
        PBYTE pbKeyBlob = NULL;

        // Read the key BLOB length from the source file. 
        if (!ReadFile(
            hSourceFile,
            &dwKeyBlobLen,
            sizeof(DWORD),
            &dwCount,
            NULL))
        {
            MyHandleError(
                TEXT("Error reading key BLOB length!\n"),
                GetLastError());
            goto Exit_MyDecryptFile;
        }

        // Allocate a buffer for the key BLOB.
        if (!(pbKeyBlob = (PBYTE)malloc(dwKeyBlobLen)))
        {
            MyHandleError(
                TEXT("Memory allocation error.\n"),
                E_OUTOFMEMORY);
        }

        //-----------------------------------------------------------
        // Read the key BLOB from the source file. 
        if (!ReadFile(
            hSourceFile,
            pbKeyBlob,
            dwKeyBlobLen,
            &dwCount,
            NULL))
        {
            MyHandleError(
                TEXT("Error reading key BLOB length!\n"),
                GetLastError());
            goto Exit_MyDecryptFile;
        }

        //-----------------------------------------------------------
        // Import the key BLOB into the CSP. 
        if (!CryptImportKey(
            hCryptProv,
            pbKeyBlob,
            dwKeyBlobLen,
            0,
            0,
            &hKey))
        {
            MyHandleError(
                TEXT("Error during CryptImportKey!/n"),
                GetLastError());
            goto Exit_MyDecryptFile;
        }

        if (pbKeyBlob)
        {
            free(pbKeyBlob);
        }
    }
    else
    {
        //-----------------------------------------------------------
        // Decrypt the file with a session key derived from a 
        // password. 

        //-----------------------------------------------------------
        // Create a hash object. 
        if (!CryptCreateHash(
            hCryptProv,
            CALG_SHA_256,
            0,
            0,
            &hHash))
        {
            MyHandleError(
                TEXT("Error during CryptCreateHash!\n"),
                GetLastError());
            goto Exit_MyDecryptFile;
        }

        //-----------------------------------------------------------
        // Hash in the password data. 
        if (!CryptHashData(
            hHash,
            (BYTE*)pszPassword,
            16,
            0))
        {
            MyHandleError(
                TEXT("Error during CryptHashData!\n"),
                GetLastError());
            goto Exit_MyDecryptFile;
        }

        //-----------------------------------------------------------
        // Derive a session key from the hash object. 
        if (!CryptDeriveKey(
            hCryptProv,
            CALG_AES_128,
            hHash,
            0,
            &hKey))
        {
            MyHandleError(
                TEXT("Error during CryptDeriveKey!\n"),
                GetLastError());
            goto Exit_MyDecryptFile;
        }
    }

    //---------------------------------------------------------------
    // The decryption key is now available, either having been 
    // imported from a BLOB read in from the source file or having 
    // been created by using the password. This point in the program 
    // is not reached if the decryption key is not available.

    //---------------------------------------------------------------
    // Determine the number of bytes to decrypt at a time. 
    // This must be a multiple of ENCRYPT_BLOCK_SIZE. 

    dwBlockLen = 1000 - 1000 % ENCRYPT_BLOCK_SIZE;
    dwBufferLen = dwBlockLen;

    //---------------------------------------------------------------
    // Allocate memory for the file read buffer. 
    if (!(pbBuffer = (PBYTE)malloc(dwBufferLen)))
    {
        MyHandleError(TEXT("Out of memory!\n"), E_OUTOFMEMORY);
        goto Exit_MyDecryptFile;
    }

    //---------------------------------------------------------------
    // Decrypt the source file, and write to the destination file. 
    do
    {
        //-----------------------------------------------------------
        // Read up to dwBlockLen bytes from the source file. 
        if (!ReadFile(
            hSourceFile,
            pbBuffer,
            dwBlockLen,
            &dwCount,
            NULL))
        {
            MyHandleError(
                TEXT("Error reading from source file!\n"),
                GetLastError());
            goto Exit_MyDecryptFile;
        }

        if (dwCount < dwBlockLen)
        {
            fEOF = TRUE;
        }

        //-----------------------------------------------------------
        // Decrypt the block of data. 
        if (!CryptDecrypt(
            hKey,
            0,
            fEOF,
            0,
            pbBuffer,
            &dwCount))
        {
            MyHandleError(
                TEXT("Error during CryptDecrypt!\n"),
                GetLastError());
            goto Exit_MyDecryptFile;
        }

        //-----------------------------------------------------------
        // Write the decrypted data to the destination file. 
        if (!WriteFile(
            hDestinationFile,
            pbBuffer,
            dwCount,
            &dwCount,
            NULL))
        {
            MyHandleError(
                TEXT("Error writing ciphertext.\n"),
                GetLastError());
            goto Exit_MyDecryptFile;
        }

        //-----------------------------------------------------------
        // End the do loop when the last block of the source file 
        // has been read, encrypted, and written to the destination 
        // file.
    } while (!fEOF);

    fReturn = true;

Exit_MyDecryptFile:

    //---------------------------------------------------------------
    // Free the file read buffer.
    if (pbBuffer)
    {
        free(pbBuffer);
    }

    //---------------------------------------------------------------
    // Close files.
    if (hSourceFile)
    {
        CloseHandle(hSourceFile);
    }

    if (hDestinationFile)
    {
        CloseHandle(hDestinationFile);
    }

    //-----------------------------------------------------------
    // Release the hash object. 
    if (hHash)
    {
        if (!(CryptDestroyHash(hHash)))
        {
            MyHandleError(
                TEXT("Error during CryptDestroyHash.\n"),
                GetLastError());
        }

        hHash = NULL;
    }

    //---------------------------------------------------------------
    // Release the session key. 
    if (hKey)
    {
        if (!(CryptDestroyKey(hKey)))
        {
            MyHandleError(
                TEXT("Error during CryptDestroyKey!\n"),
                GetLastError());
        }
    }

    //---------------------------------------------------------------
    // Release the provider handle. 
    if (hCryptProv)
    {
        if (!(CryptReleaseContext(hCryptProv, 0)))
        {
            MyHandleError(
                TEXT("Error during CryptReleaseContext!\n"),
                GetLastError());
        }
    }

    return fReturn;
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