# include <iostream>
# include <chrono>

int nqueens(int n, int i = 0, int cols = 0, int diags = 0, int trans = 0){
    if (i == n)
        return 1;
    
    int ans = 0;
    for (int j = 0; j < n; ++j){
        int col = 1 << j;

        // (i + j) of all antidiagonal nodes are the same (such as (1, 0), (0, 1))
        int diag = 1 << (i + j);

        // (i - j) of all main diagonal nodes are the same (such as (1, 0), (2, 1))
        // Because we want to bit operation, add a bias (n - 1) to make the smallest i - j as 0
        int tran = 1 << (i - j + n - 1);

        if (((cols & col) == 0) && ((diags & diag) == 0) && ((trans & tran) == 0))
            ans += nqueens(n, i + 1, cols | col, diags | diag, trans | tran);
    }
    return ans;
}

int main(){
    auto start = std::chrono::system_clock::now();

    int ans = nqueens(8);
    std::cout << ans << std::endl;
    
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "time: " << diff.count() << std::endl;
    return 0;
}