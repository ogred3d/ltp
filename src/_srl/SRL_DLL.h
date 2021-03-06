#ifndef __SRL_DLL_H__
#define __SRL_DLL_H__

//#define STL_USING_ALL
//#include <STL.h>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

#define SRL_DLL_API

#ifdef _WIN32
		#undef SRL_DLL_API
		#ifdef SRL_DLL_API_EXPORT
			#define SRL_DLL_API extern "C" _declspec(dllexport) 
		#else
			#define SRL_DLL_API extern "C" _declspec(dllimport)
			#pragma comment(lib, "_srl.lib")
		#endif
#endif

int SRL(
				 const vector<string> &words,
				 const vector<string> &POSs,
				 const vector<string> &NEs,
				 const vector< pair<int, string> > &parse,
				 vector< pair< int, vector< pair<const char *, pair< int, int > > > > > &vecSRLResult
				 );


// 加载资源
SRL_DLL_API int SRL_LoadResource(const string &ConfigDir);

// 释放分词器的资源
SRL_DLL_API int SRL_ReleaseResource();

// SRL
SRL_DLL_API int DoSRL(
				 const vector<string> &words,
				 const vector<string> &POSs,
				 const vector<string> &NEs,
				 const vector< pair<int, string> > &parse
				 );

SRL_DLL_API int GetSRLResult_size(
		vector< pair< int, vector< pair<const char *, pair< int, int > > > > > &vecSRLResult);


SRL_DLL_API int GetSRLResult(
		vector< pair< int, vector< pair<const char *, pair< int, int > > > > > &vecSRLResult);

#endif


