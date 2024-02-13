def solution(n, results):

    dist_array = [[0]*n for _ in range(n)]
    
    for result_win, result_lose in results:
        dist_array[result_win-1][result_lose-1] = 1

    for k in range(n): # path via k+1
        for i in range(n):
            for j in range(n):
                # i+1 wins k+1 && k+1 wins j+1 -> i+1 wins j+1
                if dist_array[i][j] == 0 and dist_array[i][k] and dist_array[k][j]:
                    dist_array[i][j] = 1
    
    column_sum = [0]*n
    row_sum = [0]*n
    for row in range(n):
        for column in range(n):
            column_sum[column] += dist_array[row][column]
            row_sum[row] += dist_array[row][column]
    
    answer = 0
    for index in range(n):
        if column_sum[index] + row_sum[index] == n-1:
            answer+=1

    return answer