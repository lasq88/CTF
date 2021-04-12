package main

import (
    "fmt"
    "encoding/base64"
    "sort"
    "crypto/sha1"
    "encoding/hex"
)

func calcSharedKey(key1 []byte, key2 []byte) []byte {
        combined := append(key1, key2...) // put two keys together
        sort.Slice(combined, func(i int, j int) bool { 
            return combined[i] > combined[j] 
            }) // sort descending
        hasher := sha1.New()
        hasher.Write(combined)
        sha := base64.URLEncoding.EncodeToString(hasher.Sum(nil))
        return []byte(sha)
}

func main() {
    key1, err := hex.DecodeString("4f163f5f0f9a621d729566c74d10037c")
    key2, err := hex.DecodeString("52fdfc072182654f163f5f0f9a621d72")
    if err != nil {
            panic(err)
    }
    sharedKey := calcSharedKey(key1, key2)
    fmt.Println(sharedKey)
}

//[104 89 114 88 66 107 50 67 80 105 70 73 84 74 51 116 57 78 67 86 117 88 78 111 106 76 111 61]
//[104,89,114,88,66,107,50,67,80,105,70,73,84,74,51,116,57,78,67,86,117,88,78,111,106,76,111,61]
//hYrXBk2CPiFITJ3t9NCVuXNojLo=