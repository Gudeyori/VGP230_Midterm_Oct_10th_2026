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
	float R = 280.0f;
	float r = 90.0f;
	float d = 60.0f;

	const float cenX = width / 2.0f;
	const float cenY = height / 2.0f;

	float t = 0.0f;
	float speed = 10.0f;

	// this vector stores all the positions of our "pencil"
	// so that they can be connected
	std::vector<Vector2> trail;

	// this vector is for cycling through colors :D
	std::vector<Color> colors = { RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, PINK, WHITE };
	int colorIndex = 0; // starting color

	while (!WindowShouldClose())
	{
		// delta-time movement -> decouples speed from framerate
		// prevents speed from being affected by framerate
		float dt = GetFrameTime();
		
		// KEYBOARD CONTROLS //
		
		bool changed = false;

		// Adjust big circle radius
		if (IsKeyDown(KEY_R))
		{
			R += 100.0f * dt;
			changed = true;
		}

		if (IsKeyDown(KEY_F))
		{
			R -= 100.0f * dt;
			changed = true;
		}

		// Adjust small circle radius
		if (IsKeyDown(KEY_T))
		{
			r += 100.0f * dt;
			changed = true;
		}

		if (IsKeyDown(KEY_G))
		{
			r -= 100.0f * dt;
			changed = true;
		}

		// Adjust pencil distance
		if (IsKeyDown(KEY_Y))
		{
			d += 100.0f * dt;
			changed = true;
		}

		if (IsKeyDown(KEY_H))
		{
			d -= 100.0f * dt;
			changed = true;
		}

		// Prevent invalid values
		R = Clamp(R, 10.0f, 450.0f);
		r = Clamp(r, 5.0f, R - 5.0f);
		d = Clamp(d, 0.0f, 400.0f);

		// Reset values
		if (IsKeyPressed(KEY_SPACE))
		{
			R = 280.0f;
			r = 90.0f;
			d = 60.0f;
			changed = true;
		}

		if (IsKeyPressed(KEY_C))
		{
			colorIndex = (colorIndex + 1) % colors.size();
			changed = true;
		}

		// Clear screen and restart drawing when values change
		if (changed)
		{
			trail.clear();
			t = 0.0f;
		}
		
		// CALCULATIONS //
		
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

		// DRAWING //

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
			DrawLineEx(trail[i - 1], trail[i], 2.0f, colors[colorIndex]);
		}

		// DISPLAY CONTROLS //

		DrawText("SPIROGRAPH CONTROLS", 20, 20, 20, WHITE);

		DrawText(TextFormat("R / F : Big Circle Radius (R): %.1f", R), 20, 55, 18, WHITE);

		DrawText(TextFormat("T / G : Small Circle Radius (r): %.1f", r), 20, 80, 18, WHITE);

		DrawText(TextFormat("Y / H : Pencil Distance (d): %.1f", d), 20, 105, 18, WHITE);

		DrawText("C : Change Spirograph Color", 20, 140, 18, LIGHTGRAY);

		DrawText("SPACE : Reset Values", 20, 165, 18, LIGHTGRAY);

		EndDrawing();
	}

	CloseWindow();
}

int main()
{
	Spirograph();

	return 0;
}