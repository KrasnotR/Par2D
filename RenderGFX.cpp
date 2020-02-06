//
// Created by krasno on 2020-02-06.
//

#include "RenderGFX.hpp"

int Par_RenderDrawFilledEllipse(SDL_Renderer *pRenderer, float cx, float cy, float rx, float ry, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    int n, xi, yi = 0;
    uint result = 0;
    double s, v, x, y, dx, dy;

    if ((rx <= 0.0) || (ry <= 0.0))
        return -1;

    result |= (uint)SDL_SetRenderDrawBlendMode(pRenderer, SDL_BLENDMODE_BLEND);

    if (rx >= ry) {
        n = (int)ry + 1;
        for (yi = (int)cy - n - 1; (float)yi <= cy + (float)n + 1; yi++) {
            if (yi < (cy - 0.5))
                y = yi;
            else
                y = yi + 1;
            s = (y - cy) / ry;
            s = s * s;
            x = 0.5;
            if (s < 1.0) {
                x = rx * sqrt(1.0 - s);
                result |= (uint)SDL_RenderDrawLine(pRenderer, (int)(cx - x) + 1, yi, (int)(cx + x) - 1, yi);
            }
            s = 8 * ry * ry;
            dy = fabs(y - cy) - 1.0;
            xi = (int)(cx - x);
            while (true) {
                dx = (cx - (float)xi - 1) * ry / rx;
                v = s - 4 * (dx - dy) * (dx - dy);
                if (v < 0) break;
                v = (sqrt(v) - 2 * (dx + dy)) / 4;
                if (v < 0) break;
                if (v > 1.0) v = 1.0;
                result |= (uint)SDL_SetRenderDrawColor(pRenderer, r, g, b, (double)a * v);
                result |= (uint)SDL_RenderDrawPoint(pRenderer, xi, yi);
                xi -= 1;
            }
            xi = (int)(cx + x);
            while (true) {
                dx = ((float)xi - cx) * ry / rx;
                v = s - 4 * (dx - dy) * (dx - dy);
                if (v < 0) break;
                v = (sqrt(v) - 2 * (dx + dy)) / 4;
                if (v < 0) break;
                if (v > 1.0) v = 1.0;
                result |= (uint)SDL_SetRenderDrawColor(pRenderer, r, g, b, (double)a * v);
                result |= (uint)SDL_RenderDrawPoint(pRenderer, xi, yi);
                xi += 1;
            }
        }
    } else {
        n = (int)rx + 1;
        for (xi = (int)cx - n - 1; (float)xi <= cx + (float)n + 1; xi++) {
            if (xi < (cx - 0.5))
                x = xi;
            else
                x = xi + 1;
            s = (x - cx) / rx;
            s = s * s;
            y = 0.5;
            if (s < 1.0) {
                y = ry * sqrt(1.0 - s);
                if (y >= 0.5) {
                    result |= (uint)SDL_SetRenderDrawColor(pRenderer, r, g, b, a);
                    result |= (uint)SDL_RenderDrawLine(pRenderer, xi, (int)(cy - y) + 1, xi, (int)(cy + y) - 1);
                }
            }
            s = 8 * rx * rx;
            dx = fabs(x - cx) - 1.0;
            yi = (int)(cy - y);
            while (true) {
                dy = (cy - (float)yi - 1) * rx / ry;
                v = s - 4 * (dy - dx) * (dy - dx);
                if (v < 0) break;
                v = (sqrt(v) - 2 * (dy + dx)) / 4;
                if (v < 0) break;
                if (v > 1.0) v = 1.0;
                result |= (uint)SDL_SetRenderDrawColor(pRenderer, r, g, b, (double)a * v);
                result |= (uint)SDL_RenderDrawPoint(pRenderer, xi, yi);
                yi -= 1;
            }
            yi = (int)(cy + y);
            while (true) {
                dy = ((float)yi - cy) * rx / ry;
                v = s - 4 * (dy - dx) * (dy - dx);
                if (v < 0) break;
                v = (sqrt(v) - 2 * (dy + dx)) / 4;
                if (v < 0) break;
                if (v > 1.0) v = 1.0;
                result |= (uint)SDL_SetRenderDrawColor(pRenderer, r, g, b, (double)a * v);
                result |= (uint)SDL_RenderDrawPoint(pRenderer, xi, yi);
                yi += 1;
            }
        }
    }
    return result;
}
