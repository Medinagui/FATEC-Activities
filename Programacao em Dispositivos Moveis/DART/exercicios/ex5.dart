import 'dart:io';

main() {
  stdout.write("Entre com um valor : ");
  var anterior = int.parse(stdin.readLineSync().toString()) - 1;
  print("Número anterior = ${anterior}");
}
