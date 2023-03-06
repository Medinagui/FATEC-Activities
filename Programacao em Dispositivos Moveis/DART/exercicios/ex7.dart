import 'dart:io';

main() {
  stdout.write("Entre com um valor : ");
  var valor = int.parse(stdin.readLineSync().toString());
  var dobro = valor * 2;
  var triplo = valor * 3;
  print("Dobro = ${dobro}");
  print("Triplo = ${triplo}");
}
