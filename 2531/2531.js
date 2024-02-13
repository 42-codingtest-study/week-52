//문제: 2531
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
  //회전 초밥 벨트에 놓인 접시의 수 N, 초밥의 가짓수 d, 연속해서 먹는 접시의 수 k, 쿠폰 번호 c
  //2 ≤ N ≤ 30,000, 2 ≤ d ≤ 3,000, 2 ≤ k ≤ 3,000 (k ≤ N), 1 ≤ c ≤ d
  const [N, d, k, c] = input.shift().split(" ").map(Number);
  const sushi = input.map(Number);
  for (let i = 0; i < k - 1; i++) {
    sushi.push(sushi[i]);
  }
  const check_list = Array.from({ length: d + 1 }, () => 0);
  check_list[c] = 1;
  let kind = 1;
  for (let i = 0; i < k; i++) {
    if (check_list[sushi[i]] === 0) {
      check_list[sushi[i]] = 1;
      kind += 1;
    } else {
      check_list[sushi[i]]++;
    }
  }
  let max = kind;

  for (let i = k; i < sushi.length; i++) {
    check_list[sushi[i - k]]--;
    if (check_list[sushi[i - k]] === 0) kind--;
    check_list[sushi[i]]++;
    if (check_list[sushi[i]] === 1 && check_list[sushi[i]] !== c) kind++;
    max = Math.max(max, kind);
  }
  console.log(max);
}
