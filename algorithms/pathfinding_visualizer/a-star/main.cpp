#include <SFML/Graphics.hpp>
#include <queue>
#include <vector>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <unistd.h>   // usleep (Linux). Replace with <thread> sleep if desired.

struct Cell {
    int r{}, c{};
    float g = std::numeric_limits<float>::infinity();
    float h = 0.f;
    float f = 0.f;
    bool obstacle = false;
    bool inOpen = false;
    bool inClosed = false;
    bool inPath = false;
    int parent_r = -1, parent_c = -1;
};

constexpr int ROWS = 40;
constexpr int COLS = 60;
constexpr int CELL_SIZE = 15;
constexpr int WIDTH = COLS * CELL_SIZE;
constexpr int HEIGHT = ROWS * CELL_SIZE;

float heuristic(int r1, int c1, int r2, int c2) {
    // Manhattan distance for 4-neighborhood
    return std::abs(r1 - r2) + std::abs(c1 - c2);
}

struct PQItem {
    int r, c;
    float f;
};

struct PQCompare {
    bool operator()(const PQItem& a, const PQItem& b) const {
        return a.f > b.f; // smallest f on top
    }
};

bool inBounds(int r, int c) {
    return r >= 0 && r < ROWS && c >= 0 && c < COLS;
}

std::vector<std::pair<int,int>> neighbors4(int r, int c) {
    static const int dr[4] = {-1, 1, 0, 0};
    static const int dc[4] = {0, 0, -1, 1};
    std::vector<std::pair<int,int>> out;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i], nc = c + dc[i];
        if (inBounds(nr, nc)) out.emplace_back(nr, nc);
    }
    return out;
}

void drawGrid(sf::RenderWindow& window,
              const std::vector<std::vector<Cell>>& grid,
              sf::Vector2i start, sf::Vector2i goal) {
    window.clear(sf::Color::Black);
    sf::RectangleShape rect(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));

    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            const Cell& cell = grid[r][c];
            if (cell.obstacle)                     rect.setFillColor(sf::Color(50,50,50));
            else if (cell.inPath)                  rect.setFillColor(sf::Color::Yellow);
            else if (r == start.y && c == start.x) rect.setFillColor(sf::Color::Cyan);
            else if (r == goal.y  && c == goal.x)  rect.setFillColor(sf::Color::Magenta);
            else if (cell.inClosed)                rect.setFillColor(sf::Color::Red);
            else if (cell.inOpen)                  rect.setFillColor(sf::Color::Green);
            else                                   rect.setFillColor(sf::Color::White);

            rect.setPosition(c * CELL_SIZE, r * CELL_SIZE);
            window.draw(rect);
        }
    }
    window.display();
}

void reconstructPath(std::vector<std::vector<Cell>>& grid, int r, int c) {
    while (grid[r][c].parent_r != -1) {
        grid[r][c].inPath = true;
        int pr = grid[r][c].parent_r;
        int pc = grid[r][c].parent_c;
        r = pr; c = pc;
    }
}

bool aStar(sf::RenderWindow& window,
           std::vector<std::vector<Cell>>& grid,
           sf::Vector2i start, sf::Vector2i goal,
           useconds_t delay_us = 4000) {

    std::priority_queue<PQItem, std::vector<PQItem>, PQCompare> open;

    Cell& s = grid[start.y][start.x];
    s.g = 0.f;
    s.h = heuristic(start.y, start.x, goal.y, goal.x);
    s.f = s.g + s.h;
    s.inOpen = true;
    open.push(PQItem{start.y, start.x, s.f});

    while (!open.empty()) {
        // keep window responsive
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        PQItem cur = open.top(); open.pop();
        int r = cur.r, c = cur.c;

        if (grid[r][c].inClosed) continue; // skip stale entries

        grid[r][c].inOpen = false;
        grid[r][c].inClosed = true;

        drawGrid(window, grid, start, goal);
        usleep(delay_us);

        if (r == goal.y && c == goal.x) {
            reconstructPath(grid, r, c);
            drawGrid(window, grid, start, goal);
            return true;
        }

        for (auto [nr, nc] : neighbors4(r, c)) {
            Cell& nb = grid[nr][nc];
            if (nb.obstacle || nb.inClosed) continue;

            float tentative_g = grid[r][c].g + 1.f; // cost to neighbor

            if (tentative_g < nb.g) {
                nb.parent_r = r;
                nb.parent_c = c;
                nb.g = tentative_g;
                nb.h = heuristic(nr, nc, goal.y, goal.x);
                nb.f = nb.g + nb.h;
                if (!nb.inOpen) {
                    nb.inOpen = true;
                }
                open.push(PQItem{nr, nc, nb.f}); // lazy update
            }
        }
    }
    return false;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "A* Visualization (SFML)");
    window.setFramerateLimit(60);
    std::srand(std::time(nullptr));

    // Grid init
    std::vector<std::vector<Cell>> grid(ROWS, std::vector<Cell>(COLS));
    for (int r = 0; r < ROWS; ++r)
        for (int c = 0; c < COLS; ++c) {
            grid[r][c].r = r; grid[r][c].c = c;
            grid[r][c].obstacle = (std::rand() % 100) < 25; // 25% obstacles
        }

    sf::Vector2i start(2, 2);
    sf::Vector2i goal(COLS - 3, ROWS - 3);
    grid[start.y][start.x].obstacle = false;
    grid[goal.y][goal.x].obstacle = false;

    drawGrid(window, grid, start, goal);
    aStar(window, grid, start, goal, 3000); // 3ms per step

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
    }
    return 0;
}
