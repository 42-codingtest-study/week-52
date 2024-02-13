//문제: 16165
const fs = require("fs");
const { setMaxIdleHTTPParsers } = require("http");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
  const [n_group, n_question] = input.shift().split(" ").map(Number);
  const set = {};
  const set2 = {};
  for (let i = 0; i < n_group; i++) {
    let [name, n] = input.splice(0, 2);
    const group = input.splice(0, n);
    set2[name] = group.sort((a, b) => (a > b ? 1 : -1));
    group.forEach((e) => {
      set[e] = name;
    });
  }
  for (let i = 0; i < n_question; i++) {
    if (input[2 * i + 1] === "1") console.log(set[input[i * 2]]);
    else if (input[2 * i + 1] === "0") {
      console.log(set2[input[i * 2]].join("\n"));
    }
  }
}
