#pragma once
#include <vector>
#include "role.h"
#include "..\board\position.h"

// Forward declare Board template
template<typename T> class Board;

using namespace std;

enum class MoveShape {
    Pattern,
    Line
};

struct MoveRule {
    MoveShape shape;
    vector<board_position> directions;
    int range;
    bool stopWhenBlocked;
    bool usePatternGrid;
};

template <typename T>
class MovementPattern {
private:
    vector<MoveRule> rules;
    bool pattern[7][7] = {{false}};
    static constexpr int CENTER = 3;

public:
    MovementPattern() = default;

    void addPatternRule(const bool p[7][7]) {
        for (int y = 0; y < 7; y++)
            for (int x = 0; x < 7; x++)
                pattern[y][x] = p[y][x];

        rules.push_back({
            MoveShape::Pattern,
            {}, 0, false, true
        });
    }

    void addLineRule(const vector<board_position>& dirs, int range, bool stopWhenBlocked) {
        rules.push_back({
            MoveShape::Line,
            dirs,
            range,
            stopWhenBlocked,
            false
        });
    }

    vector<board_position> getPossibleMoves(const Board<T>& board, int cx, int cy) const {
        vector<board_position> result;

        for (const MoveRule& rule : rules) {
            if (rule.shape == MoveShape::Pattern && rule.usePatternGrid) {
                for (int dy = 0; dy < 7; dy++) {
                    for (int dx = 0; dx < 7; dx++) {
                        if (pattern[dy][dx]) {
                            int nx = cx + dx - CENTER;
                            int ny = cy + dy - CENTER;
                            if (board.isWithinBounds(nx, ny) && !board.hasObstacle(nx, ny)) {
                                result.push_back({nx, ny});
                            }
                        }
                    }
                }
            } else if (rule.shape == MoveShape::Line) {
                for (auto dir : rule.directions) {
                    for (int step = 1; step <= rule.range; step++) {
                        int nx = cx + dir.x * step;
                        int ny = cy + dir.y * step;
                        if (!board.isWithinBounds(nx, ny)) break;
                        if (board.hasObstacle(nx, ny)) {
                            if (rule.stopWhenBlocked) break;
                        }
                        result.push_back({nx, ny});
                        if (rule.stopWhenBlocked && board.hasObstacle(nx, ny)) break;
                    }
                }
            }
        }

        return result;
    }
    vector<board_position> getAllPossibleMoves(const Board<T>& board, int cx, int cy) const {
        vector<board_position> result;

        for (const MoveRule& rule : rules) {
            if (rule.shape == MoveShape::Pattern && rule.usePatternGrid) {
                for (int dy = 0; dy < 7; dy++) {
                    for (int dx = 0; dx < 7; dx++) {
                        if (pattern[dy][dx]) {
                            int nx = cx + dx - CENTER;
                            int ny = cy + dy - CENTER;
                            if (board.isWithinBounds(nx, ny)) {
                                result.push_back({nx, ny});
                            }
                        }
                    }
                }
            } else if (rule.shape == MoveShape::Line) {
                for (auto dir : rule.directions) {
                    for (int step = 1; step <= rule.range; step++) {
                        int nx = cx + dir.x * step;
                        int ny = cy + dir.y * step;
                        if (!board.isWithinBounds(nx, ny)) break;
                        if (board.hasObstacle(nx, ny)) {
                            result.push_back({nx, ny});
                            if (rule.stopWhenBlocked) break;
                        }
                        result.push_back({nx, ny});
                        if (rule.stopWhenBlocked && board.hasObstacle(nx, ny)) break;
                    }
                }
            }
        }

        return result;
    }
};
