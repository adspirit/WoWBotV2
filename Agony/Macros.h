#pragma once

#define IS_NULL_RETN(OBJECT, ADDR, RETN) if ((DWORD*)(OBJECT + ADDR) == nullptr) { return RETN; }

#define MAKE_GET(NAME, TYPE, OFFSET) TYPE Get##NAME##() { return *reinterpret_cast<TYPE*>(this + OFFSET); }

//#define MAKE_GET_SET(NAME, TYPE, OFFSET) TYPE## Get##NAME##() { return (TYPE)(this + static_cast<__int32>(OFFSET)); } \
//void Set##NAME##(TYPE value) { Get##NAME() = value; }

//#define MAKE_BOOL(NAME, OFFSET, SHIFT) inline bool Get##NAME##() { return ((byte)(this + static_cast<__int32>(OFFSET)) ##SHIFT) == 1; }

#ifndef DLLEXPORT
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

//#define MAKE_RVA(ADDRESS) ( Core::GetAddress<DWORD>( (DWORD) ADDRESS) )