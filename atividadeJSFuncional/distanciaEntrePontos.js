const distanciaEntrePontos = (f) => (x1,y1) => (x2,y2) => {
    return x1 == x2? y2 - y1 : y1 == y2? x2 - x1 : f((x2-x1),(y2-y1))
}

console.log(distanciaEntrePontos((x,y) => Math.sqrt(x**2+y**2))(4,3)(15,14))