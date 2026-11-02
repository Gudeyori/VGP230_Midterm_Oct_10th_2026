# Hypotrochoid Spirograph 🎨

An interactive, real-time hypotrochoid spirograph simulator built using **C++** and **raylib**.

<img width="939" height="937" alt="SpiroBoi2" src="https://github.com/user-attachments/assets/61992c82-c018-4550-b990-1f5c8eb560af" />

The program simulates a small circle rolling around the inside of a larger stationary circle. A pencil attached to the smaller circle traces a geometric pattern, creating beautiful and unique spirograph designs.

Users can adjust the circle sizes, pencil distance, and drawing color in real time to create different patterns.

## Preview

The simulation features:

- A large stationary outer circle.
- A smaller circle rotating along the inside of the larger circle.
- An animated pencil attached to the smaller circle.
- A continuously drawn trail that creates the spirograph pattern.
- Real-time parameter adjustments using keyboard controls.
- Customizable drawing colors.

<!-- Add a screenshot or GIF of your simulation here -->

## Built With

- **C++** – Core programming language.
- **raylib** – Graphics rendering, window management, and keyboard input.
- **raymath** – Mathematical utilities, including value clamping.
- **C++ Standard Library** – Uses `std::vector` to store previous pencil positions.

## Getting Started

### Prerequisites

Before running the project, make sure you have:

- A C++ compiler supporting C++11 or later.
- raylib installed and configured.
- A compatible build environment.

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/Gudeyori/VGP230_Midterm_Oct_10th_2026.git
   ```

2. Navigate to the project directory:

   ```bash
   cd VGP230_Midterm_Oct_10th_2026
   ```

3. Open the solution or project files in your preferred development environment.

### Compilation

Compile the source file using a command similar to:

```bash
g++ main.cpp -o Spirograph -lraylib -lopengl32 -lgdi32 -lwinmm
```

**Note:** These linking flags are intended for Windows with MinGW. Other operating systems may require different linking flags.

### Running

After compiling, run the executable:

**Linux / macOS:**

```bash
./Spirograph
```

**Windows:**

```bash
Spirograph.exe
```

## Controls

All parameters can be adjusted while the simulation is running.

| Key | Action |
|---|---|
| `R` | Increase outer circle radius |
| `F` | Decrease outer circle radius |
| `T` | Increase inner circle radius |
| `G` | Decrease inner circle radius |
| `Y` | Increase pencil distance |
| `H` | Decrease pencil distance |
| `C` | Change spirograph color |
| `SPACE` | Reset all parameters to default values |

## Adjustable Parameters

| Parameter | Default Value | Description |
|---|---:|---|
| Outer Radius (R) | 280 | Radius of the stationary outer circle |
| Inner Radius (r) | 90 | Radius of the smaller rotating circle |
| Pencil Distance (d) | 60 | Distance between the inner circle's center and the pencil tip |

### Parameter Limits

The simulation uses value clamping to prevent invalid parameter values.

| Parameter | Minimum | Maximum |
|---|---:|---:|
| Outer Radius (R) | 10 | 450 |
| Inner Radius (r) | 5 | R - 5 |
| Pencil Distance (d) | 0 | 400 |

Whenever a parameter is changed, the existing drawing is cleared and the animation restarts using the updated values.

## How It Works

The simulator uses the mathematical principles of a hypotrochoid.

A hypotrochoid is a geometric curve created when a point attached to a smaller circle traces a path as that circle rolls along the inside of a larger circle.

By changing the relationship between the outer radius, inner radius, and pencil distance, the simulation generates different geometric patterns.

## Project Structure

```text
VGP230_Midterm_Oct_10th_2026/
│
├── Hypotrochoid_Spirograph/
│   └── Project source files
│
├── VGP230_Midterm_Oct_10th_2026_Kayori_McKenzie.slnx
├── .gitattributes
├── .gitignore
└── README.md
```

## Learning Objectives

This project explores several programming and mathematical concepts:

- Real-time graphics programming.
- Object movement and rotation.
- Trigonometry and geometric calculations.
- Mathematical curve generation.
- Keyboard input and user interaction.
- Dynamic drawing and animation.
- Parameter validation and value clamping.
- Using external graphics libraries with C++.

## Author

**Gudeyori**

GitHub: [@Gudeyori](https://github.com/Gudeyori)

## License

No license has currently been specified for this project. Please contact the repository owner before redistributing or reusing its code.
