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
	static XAUDIO2_BUFFER buffer;
	static WAVEFORMATEXTENSIBLE wfx;

	static IXAudio2* pXAudio2;
	static IXAudio2MasteringVoice* pMasterVoice;

	IXAudio2SourceVoice* pSourceVoice;

	HRESULT ReadChunkData(HANDLE hFile, void * buffer, DWORD buffersize, DWORD bufferoffset);
	HRESULT FindChunk(HANDLE hFile, DWORD fourcc, DWORD & dwChunkSize, DWORD & dwChunkDataPosition);
public:
	GameSound();
	~GameSound() {};


	static HRESULT Initialization();
	HRESULT LoadAudioData(LPCWSTR pName);
	HRESULT PlayASound();


};
