const iguais = (a) => (b) => (c) => {
    return a == b & b == c? 3 : a != b && b != c && c != a? 0 : 2
}

console.log(iguais(2)(2)(2))
console.log(iguais(3)(5)(7))
console.log(iguais(-2)(3)(3))