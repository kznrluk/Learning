const returnZero = () => {
    return 0
}

type ObjectUser = {
    'name' : string,
    'age' : string | number
}

const human1 : ObjectUser = {
    'name' : 'あいうえお',
    'age' : [12312,21312] // => Error
}

console.log(human1.age);