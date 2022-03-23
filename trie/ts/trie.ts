interface TrieNode<T> {
    data: T | null
    children: Map<string, TrieNode<T>>
}

export class Trie<T> {
    public root: TrieNode<T>
    public constructor() {
        this.root = { data: null, children: new Map }
    }

    public insert(key: string, data: T): Trie<T> {
        let node = this.root
        for (let index = 0; index < key.length; ++index) {
            const keyChar = key[index]
            if (!node.children.has(keyChar)) {
                node.children.set(keyChar, {
                    data: index == key.length - 1 ? data : null,
                    children: new Map,
                })
            }
            node = node.children.get(keyChar) as TrieNode<T>
        }
        return this
    }

    private dfsDelete(node: TrieNode<T> | undefined, key: string): void {
        if (node == null) return
        this.dfsDelete(node.children.get(key[0]), key.slice(1))
        node.children.delete(key[0])
    }

    public delete(key: string): Trie<T> {
        let node: TrieNode<T> | null = this.root
        let startNode: TrieNode<T> | null = null
        let startIndex: number = 0
        for (let index = 0; index < key.length; ++index) {
            const keyChar = key[index]
            if (node.children.has(keyChar)) {
                const nextNode = node.children.get(keyChar) as TrieNode<T>
                if (nextNode.data != null) {
                    startNode = node
                    startIndex = index
                }
                node = nextNode
            } else {
                if (index == key.length - 1) {
                    throw new Error("key error")
                }
            }
        }
        startNode != null && this.dfsDelete(startNode, key.slice(startIndex))
        return this
    }

    private dfsSearch(node: TrieNode<T>): { key: string, data: T }[] {
        if (node == null) return []

        let wordsList: { key: string, data: T }[] = []
        if (node.data != null) {
            wordsList.push({ key: '', data: node.data })
        }

        for (const [keyChar, nextNode] of Array.from(node.children.entries())) {
            wordsList = wordsList.concat(
                this.dfsSearch(nextNode)
                    .map(({ key, data }) => ({ key: keyChar + key, data }))
            )
        }

        return wordsList
    }

    public search(key: string): { key: string, data: T }[] {
        let node = this.root
        for (let index = 0; index < key.length; ++index) {
            const keyChar = key[index]
            if (node.children.has(keyChar)) {
                if (index == key.length - 1) {
                    return this.dfsSearch(node.children.get(keyChar) as TrieNode<T>)
                        .map(({ key: partOfKey, data }) => ({ key: key + partOfKey, data }))
                }
                node = node.children.get(keyChar) as TrieNode<T>
            } else {
                return []
            }
        }
        return []
    }
}