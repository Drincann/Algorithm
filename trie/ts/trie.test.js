const { Trie } = require('./trie.js');
const { expect } = require('chai');

function randomStr() {
    return Math.random().toString(36).substr(2, 10)
}

describe('delete', () => {
    it('delete completely', () => {
        const trie = new Trie()
        const insertedKey = new Array(100).map(() => randomStr())

        insertedKey.forEach(key => trie.insert(key, 1))
        insertedKey.forEach(key => trie.delete(key))
        expect(trie.root.children.size).to.equal(0)
    })
})