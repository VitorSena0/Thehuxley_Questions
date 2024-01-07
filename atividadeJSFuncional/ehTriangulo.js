const verifica = (lado1) => (lado2) => (lado3) => {
    return (lado1 + lado2 > lado3 || lado1 + lado3 > lado2 || lado2 + lado3 > lado1)
}

const classificaTriangulo = (lado1) => (lado2) => (lado3) => {
    return verifica(lado1)(lado2)(lado3)? comparaLados(lado1)(lado2)(lado3) : "Impossível classificar"
}

const comparaLados = (l1) => (l2) => (l3) => {
    return l1 == l2 && l2 == l3? "Equilátero" : l1 != l2 && l1 != l3 && l3 != l2? "Escaleno" : "Isóceles"
}

//console.log(verifica(10)(250)(15))
console.log(classificaTriangulo(3)(5)(8))
