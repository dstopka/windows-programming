#pragma once

#ifdef TESTDLL_EXPORTS
#define ZDLL_API __declspec(dllexport)
#include "targetver.h"
#else
#define ZDLL_API __declspec(dllimport)
#endif

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "Time.h"
#include "Date.h"
#include "TimeDate.h"
