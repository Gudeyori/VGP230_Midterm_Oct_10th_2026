#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <vector>

void Spirograph()
{
	const int width = 1000;
	const int height = 1000;

	InitWindow(width, height, "Hypotrochoid Spirograph");
	SetTargetFPS(60);

	// adjusting these changes the spirographs shape!
	const float R = 280.0f;
	const float r = 90.0f;
	const float d = 60.0f;

	const float cenX = width / 2.0f;
	const float cenY = height / 2.0f;

	float t = 0.0f;
	float speed = 10.0f;

	// this vector stores all the positions of our "pencil"
	// so that they can be connected
	std::vector<Vector2> trail;

	while (!WindowShouldClose())
	{
		// delta-time movement -> decouples speed from framerate
		// prevents speed from being affected by framerate
		float dt = GetFrameTime();
		t += speed * dt;

		// big circle center
		Vector2 largeCenter = { cenX, cenY };

		// small circle center
		Vector2 smallCenter = { cenX + (R - r) * cos(t), cenY + (R - r) * sin(t) };

		// rotation of the small circle around its own center
		// equation for angular rotation of a circle (in radians)
		float rotation = ((R - r) / r) * t;

		// this calculates where the "tip" of our pencil is
		Vector2 drawingPoint = { cenX + (R - r) * cos(t) + d * cos(rotation), cenY + (R - r) * sin(t) - d * sin(rotation)};

		// store the current position of pencil tip
		trail.push_back(drawingPoint);

		BeginDrawing();
		ClearBackground(BLACK);

		// draw big circle
		DrawCircleLines(cenX, cenY, R, WHITE);

		// draw small rotating circle
		DrawCircleLines( smallCenter.x, smallCenter.y, r, GRAY );

		// draw "pencil"
		// line from center to drawing point = pencil body
		DrawLineEx( smallCenter, drawingPoint, 2.0f, YELLOW );

		// pencil "tip"
		DrawCircleV(drawingPoint, 4, RED);

		// pencil "eraser"
		DrawCircleV(smallCenter, 3, WHITE);

		// draw trail
		// take previous tip position and current tip position and connect them
		for (int i = 1; i < trail.size(); i++)
		{
			DrawLineEx( trail[i - 1], trail[i], 2.0f, SKYBLUE );
		}

		EndDrawing();
	}

	CloseWindow();
}

int main()
{
	Spirograph();

	return 0;
}