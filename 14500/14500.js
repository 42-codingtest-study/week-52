//문제: 14500
//0. 문제 이해 : 
//1. 시간 복잡도 확인: 
//2. 적용 알고리즘 확인: 
//3. 맞는 자료구조 확인: 
const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);
function solution(input) {
    const [N, M] = input.shift().split(" ").map(Number);
    const paper = input.map((e)=>e.split(" ").map(Number));
const maxValue = paper
  .reduce(
    (acc, row) => 
    	Math.max(acc, row.reduce((acc, v) => Math.max(acc, v), 0)),
    0
  );
const offset = [[0, 1], [0, -1], [1, 0], [-1, 0]];
const visited = [...Array(N)].map(() => Array(M).fill(false));
let maxSum = 0;

const dfs = (x, y, count, sum) => {
  if (sum + (4 - count) * maxValue <= maxSum) {
    return;
  }

  if (count === 4) {
    maxSum = Math.max(maxSum, sum);
    return;
  }

  for (const [dx, dy] of offset) {
    const nx = x + dx;
    const ny = y + dy;
    if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {

      if (count === 2) {
        visited[nx][ny] = true;
        dfs(x, y, count + 1, sum + paper[nx][ny]);
        visited[nx][ny] = false;
      }

      visited[nx][ny] = true;
      dfs(nx, ny, count + 1, sum + paper[nx][ny]);
      visited[nx][ny] = false;
    }
  }
};

for (let i = 0; i < N; i++) {
  for (let j = 0; j < M; j++) {
    visited[i][j] = true;
    dfs(i, j, 1, paper[i][j]);
    visited[i][j] = false;
  }
}

console.log(maxSum);
}