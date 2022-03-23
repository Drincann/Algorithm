/**
 * 快排的函数式实现
 * @param arr 
 */
const qs = (arr: number[]): number[] => {
    if (arr.length <= 1) {
        return arr
    }
    const [base, ...rest] = arr
    const small = rest.filter(val => val <= base)
    const big = rest.filter(val => val > base)
    return [...qs(small), base, ...qs(big)]
}

console.log(qs([3, 2, 1, 2, 1]))

