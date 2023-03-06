Object getValor() {
  return "8";
}

bool isNumber(Object valor) {
  return valor is num;
}

main() {
  if (isNumber(getValor())) {
    print("Sim");
  } else {
    print("Não");
  }

  print(getValor());
}
