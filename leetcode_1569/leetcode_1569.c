const int MOD = 1000000007; //modulo 10^9 + 7
long long comb[1001][1001];

void precomputeComb() {
    // C(n,0) = 1 para todo n
    for (int i = 0; i <= 1000; i++) {
        comb[i][0] = 1;
    }
    
    // C(n,k) = C(n-1,k-1) + C(n-1,k)
    for (int n = 1; n <= 1000; n++) {
        for (int k = 1; k <= n; k++) {
            comb[n][k] = (comb[n-1][k-1] + comb[n-1][k]) % MOD;
        }
    }
}

long long solve(int* nums, int size) {
    if (size <= 2) return 1;  // caso base: 0, 1 ou 2 elementos = 1 way
    
    int root = nums[0];  // primeiro elemento = sempre a raiz
    
    // separa em subárvores esquerda e direita
    int left[1000], right[1000];
    int leftSize = 0, rightSize = 0;
    
    for (int i = 1; i < size; i++) {
        if (nums[i] < root) {
            left[leftSize++] = nums[i];
        } else {
            right[rightSize++] = nums[i];
        }
    }
    
    //recursão das subárvores
    long long waysLeft = solve(left, leftSize);
    long long waysRight = solve(right, rightSize);
    
    // total = C(leftSize + rightSize, leftSize) * waysLeft * waysRight
    long long totalWays = comb[leftSize + rightSize][leftSize];
    totalWays = (totalWays * waysLeft) % MOD;
    totalWays = (totalWays * waysRight) % MOD;
    
    return totalWays;
}

int numOfWays(int* nums, int numsSize) {
    precomputeComb();
    
    // subtrai 1 porque a pergunta é "outras formas" oque exclui o original
    long long result = solve(nums, numsSize);
    return (result - 1 + MOD) % MOD;
}

int main() {
    // teste 1
    int nums1[] = {2, 1, 3};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    
    printf("Example 1: Input = [2,1,3], Output = %d\n", numOfWays(nums1, numsSize1));
    
    //teste 2
    int nums2[] = {3, 4, 5, 1, 2};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    
    printf("Example 2: Input = [3,4,5,1,2], Output = %d\n", numOfWays(nums2, numsSize2));
    
    //teste 3
    int nums3[] = {1, 2, 3};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    
    printf("Example 3: Input = [1,2,3], Output = %d\n", numOfWays(nums3, numsSize3));
    
    return 0;
}
