const readline = require('readline');

// Create interface to read from stdin
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question("Enter your name: ", function(name) {
  console.log(`Hello, ${name}!`);
  rl.close();
});
