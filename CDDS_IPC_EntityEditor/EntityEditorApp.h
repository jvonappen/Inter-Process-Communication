#pragma once
#include <vector>
#include "raylib.h"
#include "WinInc.h"
#include <windows.h>

struct Entity {
	float x = 0, y = 0;
	float rotation = 0;
	float speed = 0;
	unsigned char r = 0, g = 0, b = 0;
	float size = 1;
};


class EntityEditorApp {
public:
	EntityEditorApp(int screenWidth = 800, int screenHeight = 450);
	~EntityEditorApp();

	bool Startup();
	void Shutdown();

	void Update(float deltaTime);
	void Draw();


	HANDLE fileHandle = CreateFileMapping(
		INVALID_HANDLE_VALUE,				// a handle to an existing virtual file, or invalid 
		nullptr,							// optional security attributes 
		PAGE_READWRITE,						// read/write access control 
		0, sizeof(Entity),					// size of the memory block,  
		L"MySharedMemory");

	HANDLE sizeHandle = CreateFileMapping(
		INVALID_HANDLE_VALUE,				// a handle to an existing virtual file, or invalid 
		nullptr,							// optional security attributes 
		PAGE_READWRITE,						// read/write access control 
		0, sizeof(int),					// size of the memory block,  
		L"MySized");

protected:
	int m_screenWidth;
	int m_screenHeight;

	// define a block of entities that should be shared
	enum { ENTITY_COUNT = 10 };
	Entity m_entities[ENTITY_COUNT];

	
};