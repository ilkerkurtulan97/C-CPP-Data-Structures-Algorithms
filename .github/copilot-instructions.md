# Copilot Instructions for C/C++ Data Structures & Algorithms Repository

## Repository Overview
Educational portfolio showcasing C/C++ programming skills across multiple domains: system programming, object-oriented design, algorithms, and interactive visualizations. Organized into standalone projects with minimal cross-dependencies.

---

## Project Structure & Architecture

### 1. **Standalone Examples** (Root Level)
- `pointer.cpp`, `reverse_array_pointer.cpp`, `sample_class.cpp`, `sample_work.cpp`
- **Pattern**: Single-file educational snippets demonstrating fundamental concepts
- **Convention**: No external dependencies; compiled directly with `g++` or included in builds

### 2. **Car Rental System** (`car_rental/`)
- **Architecture**: Multi-class OOP design with inheritance and polymorphism
- **Key Pattern**: Virtual base classes with pure virtual methods
  - `Car` (base) → `EconomyCar`, `LuxuryCar` (derived)
  - Each subclass implements `calculateRentalCost()` differently
- **Data Flow**: `Customer` → `Rental` → `Car`; rentals calculate costs via polymorphic method calls
- **Structure**:
  - `include/`: Header files for all classes
  - `src/`: Implementation files + `main.cpp`
  - Build: CMake-based with C++17 standard

### 3. **Interactive Visualizers** (SFML-based)
- **Sorting Visualizer** (`sorting_visualizer/`): Real-time bubble sort animation
- **A* Pathfinding** (`pathfinding_visualizer/a-star/`): Grid-based pathfinding with visualization
- **Common Dependencies**: SFML 2.5+ (graphics, window, system)
- **Common Pattern**: 
  - Grid/data structures updated in algorithm
  - `usleep()` calls for animation delays (Linux-specific; use `<thread>` for cross-platform)
  - Render loop with continuous updates

---

## Build & Compilation

### Car Rental System
```bash
cd car_rental && mkdir -p build && cd build
cmake ..
make
./car_rental
```

### Visualizers (Requires SFML)
```bash
cd sorting_visualizer/build  # or pathfinding_visualizer/a-star/build
cmake ..
make
./sorting_visualizer  # or ./a_star
```

**CMake Standards**:
- C++17 is the standard across projects
- SFML projects use `find_package(SFML 2.5 REQUIRED)` for dependency resolution
- Single-file visualizers are compiled directly via `add_executable()`

---

## Key Coding Patterns & Conventions

### OOP & Polymorphism (Car Rental Example)
- **Virtual Destructors**: Always use `virtual ~ClassName()` in base classes to enable proper cleanup of derived objects
- **Pure Virtual Methods**: `virtual double calculateRentalCost(int days) const = 0;` forces derived classes to implement specifics
- **Override Keyword**: Use `override` on derived methods for clarity (e.g., `double calculateRentalCost(int days) const override;`)

### Memory Management
- **Manual Allocation**: Uses `new`/`delete` (no smart pointers in portfolio)
- **Cleanup Pattern**: Store pointers in vectors, iterate and delete at end (see `main.cpp`)
- **Never Mix**: Don't mix manual and automatic memory management in same class

### Visualization Patterns (SFML)
- **Grid Representation**: Use struct arrays (`Cell grid[ROWS][COLS]`) for spatial data
- **Animation Timing**: `usleep(microseconds)` for frame delays; commonly 10-50ms per frame
- **Render-Update Loop**: Clear → Update Algorithm → Draw → Display

### Header/Implementation Split (Car Rental)
- Headers in `include/`, implementations in `src/`
- Include guards: `#ifndef CLASSNAME_H / #define CLASSNAME_H`
- CMake auto-discovery: `file(GLOB SOURCES "src/*.cpp")` compiles all .cpp files

---

## Critical External Dependencies

- **SFML 2.5+**: Required for visualizer projects; provides graphics, windowing, and system abstractions
- **C++17**: Minimum standard for all projects (enforced in CMakeLists.txt)
- **Linux-specific**: `<unistd.h>` (usleep) used in visualizers; consider `<thread>` for portability

---

## Common Development Tasks

### Adding a New Car Type
1. Create `NewCar.h` in `car_rental/include/` inheriting from `Car`
2. Implement `calculateRentalCost()` override in `NewCar.cpp`
3. Update `CMakeLists.txt` (auto-included via `file(GLOB)`)
4. Instantiate in `main.cpp` and add to `cars` vector

### Creating a New Standalone Example
1. Create `.cpp` file in root directory
2. Compile: `g++ -std=c++17 filename.cpp -o filename`
3. No build system needed for simple examples

### Extending a Visualizer
- Modify algorithm logic in `main.cpp`
- Adjust grid constants (`ROWS`, `COLS`, `CELL_SIZE`) at top of file
- Add new rendering logic in draw function; SFML objects: `sf::RectangleShape`, `sf::CircleShape`, etc.

---

## Important Notes for AI Agents

1. **Test Compilation Before Refactoring**: Always verify CMake builds succeed; SFML linking is fragile
2. **Manual Memory Management**: Watch for memory leaks; verify all `new` statements have corresponding `delete`
3. **Polymorphic Cleanup**: Ensure base class destructors are virtual before storing derived objects in base pointers
4. **Platform Considerations**: `usleep()` is Linux-specific; flag for future cross-platform work
5. **Educational Focus**: Code prioritizes clarity over optimization; preserve explanatory comments and verbose naming
