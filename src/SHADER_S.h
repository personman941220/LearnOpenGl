#pragma once
#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
class Shader
{
public:
	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath)
	{
		string vertexCode;
		string fragmentCode;
		ifstream vShaderFile;
		ifstream fShaderFile;
		//检查输入流
		vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
		fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
		try
		{
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);
			stringstream vShaderStream, fShaderStream;
			//读取文件缓存中的内容
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			//关闭输入流
			vShaderFile.close();
			fShaderFile.close();
			//转换输入流到字符串类型
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch (ifstream::failure& e)
		{
			cout << "ERROR::SHADER::FILE_NOT_SUCCESFULY_READ"  <<  endl;
		}

		const char* vShaderCode = vertexCode.c_str();
		const char* fShaderCode = fragmentCode.c_str();
		//编译着色器
		unsigned int vertex, fragment;
		//顶点着色器
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);
		checkCompileErrors(vertex, "VERTEX");
		//片段着色器
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		glCompileShader(fragment);
		checkCompileErrors(fragment, "FRAGMENT");
		// 着色器程序
		ID = glCreateProgram();
		glAttachShader(ID, vertex);
		glAttachShader(ID, fragment);
		glLinkProgram(ID);
		checkCompileErrors(ID, "PROGRAM");
		//删除数据
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}
	void use()
	{
		glUseProgram(ID);
	}

	void setBool(const string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
	}

	void setInt(const string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}

	void setFloat(const string& name, float value)const
	{
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
	}

private:

	void checkCompileErrors(unsigned int shader, string type)
	{
		int success;
		char infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(shader,GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				cout << "Error::shader_compilation_error of type" << type << "\n" << infoLog << endl;
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
				if(!success)
				{
					glGetProgramInfoLog(shader, 1024, NULL, infoLog);
					cout << "Error::program_linking_error of type: " << type << "\n" << infoLog << endl;
				
				}
		}
	}
};

#endif
