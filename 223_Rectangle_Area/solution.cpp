class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1 = (C - A) * (D - B), s2 = (G - E) * (H - F), s3;
        if(min(C, G) > max(A, E) && min(D, H) > max(B, F))
            s3 = (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
        else s3 = 0;
        return s1 + s2 - s3;
    }
};