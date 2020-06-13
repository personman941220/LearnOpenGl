// opengl1_c.cpp: 定义应用程序的入口点。
//

#include <iostream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "SHADER_S.h"
using namespace std;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

//settings 
const unsigned int SCR_WIDTH = 900;
const unsigned int SCR_HEIGHT = 600;
/*uniform shadersource
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"  gl_Position = vec4(aPos,1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"uniform vec4  outColor;\n"
"void main()\n"
"{\n"
" FragColor = outColor;\n"
"}\n\0";

const char* vertexShaderSource1 = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"out vec3 ourColor;\n"
"void main()\n"
"{\n"
" gl_Position = vec4(aPos,1.0);\n"
" ourColor = aColor;\n"
"}\0";

const char* fragmentShaderSource1 = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 ourColor;\n"
"void main()\n"
"{\n"
"  FragColor = vec4(ourColor,1.0f);\n"
"}\n\0";*/
//const char* vertexShaderSource = "#version 330 core\n"
//    "layout (location = 0) in vec3 aPos;\n"
//    "void main()\n"
//    "{\n"
//    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//    "}\0";
//const char* fragmentShaderSource = "#version 330 core\n"
//    "out vec4 FragColor;\n"
//    "void main()\n"
//    "{\n"
//    "   FragColor = vec4(0.5, 0.0, 0.5, 1.0);\n"
//    "}\n\0";
//const char* fragmentShaderSource1 = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//" FragColor = vec4(1.0f,1.0f,0.0f,1.0f);\n"
//"}\n\0";

//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(0.5, 0.0, 0.5, 1.0);\n"
//"}\n\0";

int main()
{
    //初始化 glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //查看硬件顶点属性
   /* int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS,&nrAttributes);
    cout << "Maximumnr of vertex attributes supported: " << nrAttributes << endl;*/
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //创建一个窗口对象并检查是否为空
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH,SCR_HEIGHT, "LearnOpenGL", NULL,NULL);
    if (window == NULL)
    {
        cout << "Failed  to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //glad 加载OpenGL函数指针
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return  -1;
    }
    ////构建和编译着色器程序
    //int  vertexShader = glCreateShader(GL_VERTEX_SHADER);
    //glShaderSource(vertexShader, 1, &vertexShaderSource1, NULL);
    //glCompileShader(vertexShader);
    //int vertexShader1 = glCreateShader(GL_VERTEX_SHADER);
    //glShaderSource(vertexShader1, 1, &vertexShaderSource, NULL);
    //glCompileShader(vertexShader1);
    ////检查编译着色器情况
    //int success;
    //char infoLog[512];
    //glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    //if (!success)
    //{
    //    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    //    cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
    //}
    ////片段着色器
    //int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    //int fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
    //int shaderProgram = glCreateProgram();
    //int shaderProgram1 = glCreateProgram();
    //glShaderSource(fragmentShader, 1, &fragmentShaderSource1, NULL);
    //glCompileShader(fragmentShader);
    //glShaderSource(fragmentShader1, 1, &fragmentShaderSource, NULL);
    //glCompileShader(fragmentShader1);

    ////检查片段着色器情况
    //glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    //if (!success)
    //{
    //    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    //    cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
    //}
    ////连接着色器
    ///*int shaderProgram = glCreateProgram();*/
    //glAttachShader(shaderProgram, vertexShader);
    //glAttachShader(shaderProgram, fragmentShader);
    //glLinkProgram(shaderProgram);
    //glAttachShader(shaderProgram1, vertexShader1);
    //glAttachShader(shaderProgram1, fragmentShader1);
    //glLinkProgram(shaderProgram1);

    ////检查连接着色器
    //glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    //if (!success)
    //{
    //    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    //    cout << "ERROR:SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
    //}
    //glDeleteShader(vertexShader);
    //glDeleteShader(fragmentShader);
    //glDeleteShader(fragmentShader1);
    //使用自己的着色器类
    Shader ourShader("C:\\Users\\zsk\\source\\repos\\OpenGl\\shader\\shader_vs.hlsl", "C:\\Users\\zsk\\source\\repos\\OpenGl\\shader\\shader_fs.hlsl");
   /* glDeleteShader(fragmentShader1);*/
    //设置顶点数据
    float vertices[] = {
        -1.0f,-0.5f,0.0f, 1.0f,0.0f,0.0f,
        0.0f,-0.5f,0.05f, 0.0f,1.0f,0.0f,
        -0.5f,0.5f,0.0f,  0.0f,0.0f,1.0f,
        
    };

    /*float vertices1[] = {
        0.0f,-0.5f,0.05f,
        1.0f,-0.5f,0.0f,
        0.5f,0.5f,0.0f
    };*/
   /* unsigned int indices[] = {
        0,1,2,
        1,3,4
    };*/
    unsigned int VBO, VAO;
    /*unsigned int EBO;
    glGenBuffers(1, &EBO);*/
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    //绑定顶点数组对象
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
   

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
   /* glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);*/

    //注意，这是允许的，对glVertexAttribPointer的调用将VBO注册为顶点属性的绑定顶点缓冲区对象，这样之后我们可以安全地解除绑定
    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    //glBindVertexArray(0);

    // 渲染循环 Render loop
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        //渲染
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //绘制
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//绘制线框模式的三角形
        //glUseProgram(shaderProgram);
        //glBindVertexArray(VAOs[0]);
        ///*glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0);*/
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        //glUseProgram(shaderProgram1);
        //float timeValue = glfwGetTime();
        //float outColorValue = sin(timeValue) / 2.0f + 0.5f;
        //int vertexColorLocation = glGetUniformLocation(shaderProgram1, "outColor");
        //glUniform4f(vertexColorLocation, 0.0f, outColorValue, 0.0f, 1.0f);
        //glBindVertexArray(VAOs[1]);
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        //使用自身的着色器
        ourShader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        //glBindVertexArray(0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    //收回绘制资源
   // glDeleteVertexArrays(2, VAOs);
   // glDeleteBuffers(2, VBOs);
   ///* glDeleteBuffers(1, &EBO);*/
   // glDeleteProgram(shaderProgram);
    //终止，清理所有GLFW资源
    glfwSwapBuffers(window);
    return 0;
}
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}