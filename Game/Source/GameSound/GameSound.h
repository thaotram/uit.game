#pragma once
#include <xaudio2.h>
#include <windows.h>
#include <memory>
#include <stdio.h>
#include <wrl\client.h>
#include <iostream>
#include <sstream>
#include "../../Define.h"

#define fourccRIFF 'FFIR'
#define fourccDATA 'atad'
#define fourccFMT ' tmf'
#define fourccWAVE 'EVAW'
#define fourccXWMA 'AMWX'
#define fourccDPDS 'sdpd'

using Microsoft::WRL::ComPtr;
using namespace std;

class GameSound {
private:
	IXAudio2* pXAudio2;
	IXAudio2MasteringVoice* pMasterVoice;
	IXAudio2SourceVoice* pSourceVoice;

	WAVEFORMATEXTENSIBLE wfx;
	XAUDIO2_BUFFER buffer;

	HRESULT CreateFileFromString(string pName, HANDLE &pHandleFile);
	HRESULT ReadChunkData(HANDLE hFile, void * buffer, DWORD buffersize, DWORD bufferoffset);
	HRESULT FindChunk(HANDLE hFile, DWORD fourcc, DWORD & dwChunkSize, DWORD & dwChunkDataPosition);
public:
	GameSound();
	~GameSound() {};


	HRESULT Initialization();
	HRESULT LoadAudioData(string pName);
	HRESULT PlayASound();


};
