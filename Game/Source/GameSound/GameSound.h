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
	static IXAudio2* pXAudio2;
	static IXAudio2MasteringVoice* pMasterVoice;

	//# 3 Biến Private xài chung
	IXAudio2SourceVoice* pSourceVoice;
	XAUDIO2_BUFFER buffer;
	WAVEFORMATEXTENSIBLE wfx;

	//# Mấy hàm này chỉ xài nội bộ trong app
	HRESULT ReadChunkData(HANDLE hFile, void * buffer, DWORD buffersize, DWORD bufferoffset);
	HRESULT FindChunk(HANDLE hFile, DWORD fourcc, DWORD & dwChunkSize, DWORD & dwChunkDataPosition);
	HRESULT LoadAudioData(LPCWSTR pName);
public:
	static HRESULT Initialization();
	GameSound(LPCWSTR pName);
	~GameSound() {};

	HRESULT Play();
};
