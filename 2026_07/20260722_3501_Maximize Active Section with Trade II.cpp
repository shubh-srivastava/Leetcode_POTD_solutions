// 22nd July 2026

class Solution {
    vector<int> segType;
    vector<int> leftEnd, rightEnd;
    vector<int> lg;
    vector<vector<int>> sparse;

    int rangeMaxQuery(int left, int right){
        if(left > right){
            return 0;
        }

        int k = lg[right - left + 1];
        return max(sparse[k][left],sparse[k][right - (1 << k) + 1]);
    }

    int calculateGain(int idx, int L, int R, int firstSeg, int lastSeg){
        if (idx <= firstSeg || idx >= lastSeg) return 0;
        if (segType[idx] == 0) return 0;

        int leftLen, rightLen;

        if(idx - 1 == firstSeg){
            leftLen = max(0, rightEnd[idx - 1] - L + 1);
        }
        else{
            leftLen = rightEnd[idx - 1] - leftEnd[idx - 1] + 1;
        }
        if(idx + 1 == lastSeg){
            rightLen = max(0, R - leftEnd[idx + 1] + 1);
        }
        else{
            rightLen = rightEnd[idx + 1] - leftEnd[idx + 1] + 1;
        }
        return leftLen + rightLen;
    }

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries){
        int n = s.size();
        int totalOnes = 0;

        for(char ch : s){
            if (ch == '1'){
                totalOnes++;
            }
        }

        for(int i = 0; i < n;){
            int j = i;
            while(j < n && s[j] == s[i]){
                j++;
            }

            segType.push_back(s[i] - '0');
            leftEnd.push_back(i);
            rightEnd.push_back(j - 1);

            i = j;
        }

        int m = segType.size();

        vector<int> segmentId(n);
        for(int i = 0; i < m; i++){
            for(int j = leftEnd[i]; j <= rightEnd[i]; j++){
                segmentId[j] = i;
            }
        }

        vector<int> gain(m, 0);

        for(int i = 1; i < m - 1; i++){
            if(segType[i] == 1){
                int leftZeros = rightEnd[i - 1] - leftEnd[i - 1] + 1;
                int rightZeros = rightEnd[i + 1] - leftEnd[i + 1] + 1;
                gain[i] = leftZeros + rightZeros;
            }
        }

        lg.assign(m + 1, 0);
        for (int i = 2; i <= m; i++){
            lg[i] = lg[i / 2] + 1;
        }

        int levels = lg[m] + 1;
        sparse.assign(levels, vector<int>(m));

        for(int i = 0; i < m; i++){
            sparse[0][i] = gain[i];
        }

        for(int k = 1; k < levels; k++){
            for(int i = 0; i + (1 << k) <= m; i++){
                sparse[k][i] = max(
                    sparse[k - 1][i],
                    sparse[k - 1][i + (1 << (k - 1))]
                );
            }
        }

        vector<int> answer;

        for(int i = 0; i < queries.size(); i++){
            int L = queries[i][0];
            int R = queries[i][1];

            int firstSeg = segmentId[L];
            int lastSeg = segmentId[R];

            if (lastSeg - firstSeg < 2){
                answer.push_back(totalOnes);
                continue;
            }

            int bestGain = 0;

            bestGain = max(bestGain,calculateGain(firstSeg + 1, L, R, firstSeg, lastSeg));

            bestGain = max(bestGain,calculateGain(lastSeg - 1, L, R, firstSeg, lastSeg));

            if(firstSeg + 2 <= lastSeg - 2){
                bestGain = max(bestGain,rangeMaxQuery(firstSeg + 2, lastSeg - 2));
            }

            answer.push_back(totalOnes + bestGain);
        }

        return answer;
    }
};