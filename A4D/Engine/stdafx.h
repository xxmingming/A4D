// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
// Windows 头文件: 
#include <windows.h>
// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <list>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <string>

#include <stdio.h>
#include <iomanip>
#include <DbgHelp.h>
#include <strsafe.h>

#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
#include "object.h"

#include <d3d9.h>
#include <d3dx9tex.h>
//#include <D3DX10Math.h>
//#include <D3D10.h>
#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include <functional>
#include <iomanip>
#include "AObject.h"