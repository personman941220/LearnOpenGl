#ifndef TPR_STB_IMAGE_NO_WARNINGS_H_
#define TPR_STB_IMAGE_NO_WARNINGS_H_

//-- 屏蔽掉 stb_image 中的所有 warnings -- 将该文件中所涉及的所有内容定义为系统头文件的代码 可以不完全遵守C标准
#pragma clang system_header
//STB_IMAGE_IMPLEMENTATION 预处理将头部文件变成一个cpp文件 可以直接使用 未声明此处理 将导致undefined
#ifndef STB_IMAGE_IMPLEMENTATION
    #define STB_IMAGE_IMPLEMENTATION
#endif
#include "stb_image_inn/stb_image.h" //-- 加载图片数据用

#endif
