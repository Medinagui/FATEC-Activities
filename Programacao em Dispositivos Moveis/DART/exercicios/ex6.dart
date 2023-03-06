import 'dart:io';

main() {
  stdout.write("Entre com um valor : ");
  var posterior = int.parse(stdin.readLineSync().toString()) + 1;
  print("Número posterior = ${posterior}");
}
