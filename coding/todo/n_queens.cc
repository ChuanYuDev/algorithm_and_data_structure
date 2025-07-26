# include <iostream>
# include <chrono>

int nqueens(int n, int i = 0, int cols = 0, int diags = 0, int trans = 0){
    if (i == n)
        return 1;
    
    int ans = 0;
    for (int j = 0; j < n; ++j){
        int col = 1 << j;
        int diag = 1 << (i + j);
        int tran = 1 << (i - j + n - 1);

        if (((cols & col) == 0) && ((diags & diag) == 0) && ((trans & tran) == 0))
            ans += nqueens(n, i + 1, cols | col, diags | diag, trans | tran);
    }
    return ans;
}

int main(){
    auto start = std::chrono::system_clock::now();

    int ans = nqueens(15);
    std::cout << ans << std::endl;
    
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "time: " << diff.count() << std::endl;
    return 0;
}