main() {
  List<double> notas = [5.6, 7.8, 10.0, 8.0];
  print("Média = ${notas.reduce((a, nota) => a + nota) / notas.length}");
}
