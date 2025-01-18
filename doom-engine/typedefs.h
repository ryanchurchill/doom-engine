#pragma once

#define MAX_POLYS 10
#define MAX_VERTS 8

typedef struct
{
	float x, y;
} Vec2;

typedef struct
{
	Vec2 p1, p2;
} LineSeg;

typedef struct
{
	Vec2 vert[MAX_VERTS];
	int vertCnt;
	float height;
	float curDist;
} Polygon;


// surface of the wall displayed on the screen
typedef struct
{
	//a plane has 4 vertices since it's a quadrilateral
	Vec2 vert[4];
	float distFromCamera;
	int planeIdInPoly;
} ScreenSpacePoly;

typedef struct
{
	float camAngle;
	float stepWave;
	Vec2 camPos;
	Vec2 oldCamPos;
} Camera;