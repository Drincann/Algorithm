/**
 * 快排的尾递归函数式实现
 * @param arr 
 * @param callback
 */
const qsTr = (arr: number[], callback: (result: number[]) => void) => {
    if (arr.length <= 1) {
        return callback(arr);
    }

    const [base, ...rest] = arr;

    const small = rest.filter(v => v <= base);
    const big = rest.filter(v => v > base);
    qsTr(small, smallSorted => {
        qsTr(big, bigSorted => {
            callback([...smallSorted, base, ...bigSorted]);
        })
    });
}

qsTr([3, 2, 1, 2, 1], result => {
    console.log(result);
});