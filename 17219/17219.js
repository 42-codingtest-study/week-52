//문제: 17219
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
  const [n, m] = input.shift().split(" ").map(Number);
  const set = {};
  input.slice(0, n).forEach((e) => (set[e.split(" ")[0]] = e.split(" ")[1]));
  for (let i = n; i < m + n; i++) {
    console.log(set[input[i]]);
  }
}
