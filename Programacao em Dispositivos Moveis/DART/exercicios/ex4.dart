double calcularAreaTriangulo({double base = 0, double altura = 0}) {
  return (base * altura) / 2;
}

main() {
  var b = 16.0;
  var a = 14.5;

  print("Área do triângulo = ${calcularAreaTriangulo(base: b, altura: a)}");
}
