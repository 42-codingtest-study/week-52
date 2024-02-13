//문제: 9375
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
  let n_case = +input.shift();
  for (let i = 0; i < n_case; i++) {
    let n = input.shift();
    const set = {};
    input.splice(0, n).forEach((e) => {
      if (set[e.split(" ")[1]]) set[e.split(" ")[1]].push(e.split(" ")[0]);
      else set[e.split(" ")[1]] = [e.split(" ")[0]];
    });
    const values = Object.values(set);
    let a = 1;
    values.forEach((e) => (a *= e.length + 1));
    console.log(a - 1);
  }
}
