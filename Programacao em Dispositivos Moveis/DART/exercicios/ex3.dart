double calcularAreaRetangulo({double base = 0, double altura = 0}) {
  return base * altura;
}

main() {
  double b = 15.0;
  var a = 34.5;

  var resultado = calcularAreaRetangulo(base: b, altura: a);

  print("Área do retângulo = " + resultado.toString());

  print("Área do retângulo = ${resultado}");
}
