function solution(n, results) {
    // 2차원 배열을 만들어 각 선수 사이의 승패 여부를 저장
    const graph = Array.from({ length: n + 1 }, () => Array(n + 1).fill(false));

    // 경기 결과를 기반으로 그래프를 초기화
    results.forEach(([a, b]) => {
        graph[a][b] = "승";
        graph[b][a] = "패";
    });

    // 플로이드-와샬 알고리즘을 사용하여 모든 선수 쌍에 대한 승패 여부를 업데이트
    for (let k = 1; k <= n; k++) {
        for (let i = 1; i <= n; i++) {
            for (let j = 1; j <= n; j++) {
                if (graph[i][k] === "승" && graph[k][j] === "승") {
                    graph[i][j] = "승";
                }
                if (graph[i][k] === "패" && graph[k][j] === "패") {
                    graph[i][j] = "패";
                }
            }
        }
    }
    // 정확한 순위를 매길 수 있는 선수 수를 count
    let count = 0;
    for (let i = 1; i <= n; i++) {
        if (graph[i].filter(val => val != false).length === n - 1) {
            count++;
        }
    }

    return count;
}