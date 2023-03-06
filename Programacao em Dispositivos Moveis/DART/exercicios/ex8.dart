import 'dart:io';

main() {
  stdout.write("Entre com um valor : ");
  var valor = int.parse(stdin.readLineSync().toString());
  print("25% = ${valor * 0.25}");
  print("50% = ${valor * 0.5}");
  print("100% = ${valor * 1}");
  print("150% = ${valor * 1.5}");
}
