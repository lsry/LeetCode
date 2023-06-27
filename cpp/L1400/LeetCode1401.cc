class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if (x1 > xCenter + radius || x2 < xCenter - radius || y1 > yCenter + radius || y2 < yCenter - radius) {
            return false;
        }      
        int plb = (x1 - xCenter) * (x1 - xCenter) + (y1 - yCenter) * (y1 - yCenter);
        int plt = (x1 - xCenter) * (x1 - xCenter) + (y2 - yCenter) * (y2 - yCenter);
        int prb = (x2 - xCenter) * (x2 - xCenter) + (y1 - yCenter) * (y1 - yCenter);
        int prt = (x2 - xCenter) * (x2 - xCenter) + (y2 - yCenter) * (y2 - yCenter);
        int r2 = radius * radius;
        if (x1 >= xCenter - radius && x1 <= xCenter + radius && (plb <= r2 || plt <= r2 || (y1 <= yCenter - radius && y2 >= yCenter + radius))) {
            return true;
        }
        if (x2 >= xCenter - radius && x2 <= xCenter + radius && (prb <= r2 || prt <= r2 || (y1 <= yCenter - radius && y2 >= yCenter + radius))) {
            return true;
        }
        if (y1 >= yCenter - radius && y1 <= yCenter + radius && (plb <= r2 || prb <= r2 || (x1 <= xCenter - radius && x2 >= xCenter + radius))) {
            return true;
        }
        if (y2 >= yCenter - radius && y2 <= yCenter + radius && (plt <= r2 || prt <= r2 || (x1 <= xCenter + radius && x2 >= xCenter + radius))) {
            return true;
        }
        if (x1 <= xCenter - radius && x2 >= xCenter + radius && y1 <= yCenter - radius && y2 >= yCenter + radius) {
            return true;
        }
        return false;
    }
};