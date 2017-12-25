#include "GameSound.h"
#include <winapifamily.h>

GameSound::GameSound() {
	pSourceVoice = NULL;
}

HRESULT GameSound::Initialization() {
	HRESULT hr;
	pXAudio2 = NULL;
	pMasterVoice = NULL;

	if (FAILED(hr = XAudio2Create(&pXAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR)))
		return hr;
	if (FAILED(hr = pXAudio2->CreateMasteringVoice(&pMasterVoice)))
		return hr;
	return 1;
}
HRESULT GameSound::LoadAudioData(string pName) {
	wfx = { 0 };
	buffer = { 0 };

	HANDLE hFile = CreateFile(
		TEXT("Sound/01_Storyline.wav"),
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		0,
		NULL
	);
	if (INVALID_HANDLE_VALUE == hFile) return HRESULT_FROM_WIN32(GetLastError());
	if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, 0, NULL, FILE_BEGIN)) return HRESULT_FROM_WIN32(GetLastError());

	//# 3. Locate the 'RIFF' chunk in the audio file, and check the file type.
	DWORD dwChunkSize;
	DWORD dwChunkPosition;
	DWORD filetype;
	FindChunk(hFile, fourccRIFF, dwChunkSize, dwChunkPosition);
	ReadChunkData(hFile, &filetype, sizeof(DWORD), dwChunkPosition);
	if (filetype != fourccWAVE) return S_FALSE;

	//# 4. Locate the 'fmt ' chunk, and copy its contents into a WAVEFORMATEXTENSIBLE structure.
	FindChunk(hFile, fourccFMT, dwChunkSize, dwChunkPosition);
	ReadChunkData(hFile, &wfx, dwChunkSize, dwChunkPosition);

	//# 5. Locate the 'data' chunk, and read its contents into a buffer.
	FindChunk(hFile, fourccDATA, dwChunkSize, dwChunkPosition); // fill out the audio data buffer with the contents of the fourccDATA chunk
	BYTE * pDataBuffer = new BYTE[dwChunkSize];
	ReadChunkData(hFile, pDataBuffer, dwChunkSize, dwChunkPosition);

	//# 6. Populate an XAUDIO2_BUFFER structure.
	buffer.AudioBytes = dwChunkSize;		// buffer containing audio data
	buffer.pAudioData = pDataBuffer;		// size of the audio buffer in bytes
	buffer.Flags = XAUDIO2_END_OF_STREAM;	// tell the source voice not to expect any data after this buffer

	return 1;
}
HRESULT GameSound::PlayASound() {
	HRESULT hr;
	if (FAILED(hr = pXAudio2->CreateSourceVoice(&pSourceVoice, (WAVEFORMATEX*)&wfx)))
		return hr;
	if (FAILED(hr = pSourceVoice->SubmitSourceBuffer(&buffer)))
		return hr;
	if (FAILED(hr = pSourceVoice->Start(0)))
		return hr;
	return 0;
}

//# Private
HRESULT GameSound::CreateFileFromString(string pName, HANDLE &hFile) {
	hFile = CreateFile(
		StringToLPCWSTR(pName),
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		0,
		NULL
	);

	if (INVALID_HANDLE_VALUE == hFile)
		return HRESULT_FROM_WIN32(GetLastError());

	if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, 0, NULL, FILE_BEGIN))
		return HRESULT_FROM_WIN32(GetLastError());

	return 1;
}
HRESULT GameSound::ReadChunkData(HANDLE hFile, void * buffer, DWORD buffersize, DWORD bufferoffset) {
	HRESULT hr = S_OK;
	if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, bufferoffset, NULL, FILE_BEGIN))
		return HRESULT_FROM_WIN32(GetLastError());
	DWORD dwRead;
	if (0 == ReadFile(hFile, buffer, buffersize, &dwRead, NULL))
		hr = HRESULT_FROM_WIN32(GetLastError());
	return hr;
}
HRESULT GameSound::FindChunk(HANDLE hFile, DWORD fourcc, DWORD & dwChunkSize, DWORD & dwChunkDataPosition) {
	HRESULT hr = S_OK;
	if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, 0, NULL, FILE_BEGIN)) {
		return HRESULT_FROM_WIN32(GetLastError());
	}

	DWORD dwChunkType;
	DWORD dwChunkDataSize;
	DWORD dwRIFFDataSize = 0;
	DWORD dwFileType;
	DWORD bytesRead = 0;
	DWORD dwOffset = 0;

	while (hr == S_OK) {
		DWORD dwRead;
		if (0 == ReadFile(hFile, &dwChunkType, sizeof(DWORD), &dwRead, NULL)) {
			hr = HRESULT_FROM_WIN32(GetLastError());
		}

		if (0 == ReadFile(hFile, &dwChunkDataSize, sizeof(DWORD), &dwRead, NULL)) {
			hr = HRESULT_FROM_WIN32(GetLastError());
		}

		switch (dwChunkType) {
		case fourccRIFF:
			dwRIFFDataSize = dwChunkDataSize;
			dwChunkDataSize = 4;
			if (0 == ReadFile(hFile, &dwFileType, sizeof(DWORD), &dwRead, NULL)) {
				hr = HRESULT_FROM_WIN32(GetLastError());
			}
			break;
		default:
			if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, dwChunkDataSize, NULL, FILE_CURRENT)) {
				return HRESULT_FROM_WIN32(GetLastError());
			}
		}
		dwOffset += sizeof(DWORD) * 2;
		if (dwChunkType == fourcc) {
			dwChunkSize = dwChunkDataSize;
			dwChunkDataPosition = dwOffset;
			return S_OK;
		}
		dwOffset += dwChunkDataSize;
		if (bytesRead >= dwRIFFDataSize) return S_FALSE;
	}
	return S_OK;
}