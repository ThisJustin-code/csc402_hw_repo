// Justin Gallagher
// HW1: F# Getting Started
// CSC 402 - 001
// 8/19/2020

module HW1

open System

let circleArea r = System.Math.PI * r * r // problem1
let isLowerCaseVowel ch = ch = 'a' || ch = 'e' || ch = 'i' || ch = 'o' || ch = 'u' // problem2
let ithCharEquals (str:string) i ch = (i >= 0 && i < str.Length) && str.[i].Equals(ch) // problem3
let ithCharSatisfies (str:string) i f = (i >= 0 && i < str.Length) && f str.[i] // problem4
let min3 a b c = if a < b then
                    if a < c then a
                    else c  
                 else b  // problem5
                 
let min3WithMin a b c = (min (min a b) c) // problem6
                                                                                       
[<EntryPoint>]
let main argv =
    printfn "Hello World from F#!"
    printfn "The area of a circle with radius %1.1f is %1.8f" 3.0 (circleArea 3.0)
    0 // return an integer exit code
