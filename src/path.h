#pragma once
/*
	path类 用来定义文件路径
*/
#include  <iostream>
#include <string>
using namespace std;
const string shaderpath = "C:\\Users\\zsk\\source\\repos\\OpenGl\\shader\\shader_vs.hlsl";
class path
{
public:
	string getPath() {
		string directory;
		const size_t  last_slash_idx = shaderpath.rfind('\\');
		if (string::npos != last_slash_idx)
		{
			directory = shaderpath.substr(0, last_slash_idx);
		}
		return directory;
	}
	
};