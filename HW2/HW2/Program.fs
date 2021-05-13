// Justin Gallagher
// HW2: F# Tuples, records, and tagged values
// CSC 402 - 001
// 9/2/2020

module HW2

open System

type Dinosaur = {name : string; weight : float; height : float}
type Shape = | Circle of float
             | Square of float
             | Triangle of float*float*float
             | Rectangle of float*float
let min3 (x, y, z) = (min (min x y) z) // problem1
let tyranno = {name = "Tyrannosaurus"; weight = 7.; height = 3.66}
let brachio = {name = "Brachiosaurus"; weight = 35.; height = 9.4}
let nameOfHeavier x y = if x.weight > y.weight then x.name else y.name // problem2
let threeDDist (x1, y1, z1) (x2, y2, z2) =
    let x = (x1 - x2) * (x1 - x2)
    let y = (y1 - y2) * (y1 - y2)
    let z = (z1 - z2) * (z1 - z2)
    let add = x + y + z
    sqrt (add:float) // problem3
let circ = Circle 2.1
let sq = Square 3.6
let tri = Triangle (5., 12., 13.)
let rect = Rectangle (3., 4.)
let isShape = function
    | Circle r -> r > 0.0
    | Square a -> a > 0.0
    | Triangle (a, b, c) -> a > 0.0 && b > 0.0 && c > 0.0
                          && a < b + c && b < c + a && c < a + b
    | Rectangle (l, w) -> l > 0.0 && w > 0.0
let area x =
    if not (isShape x)
    then failwith "not a legal shape"
    else match x with
            | Circle r -> System.Math.PI * r * r
            | Square a -> a * a
            | Triangle (a, b, c) ->
                let s = (a + b + c) / 2.0
                sqrt(s * (s - a) * (s - b) * ( s - c))
            | Rectangle (l, w) -> l * w
let perimeter x =
    if not (isShape x)
    then failwith "not a legal shape"
    else match x with
            | Circle r -> 2.0 * System.Math.PI * r
            | Square a -> 4.0 * a
            | Triangle (a, b, c) -> a + b + c
            | Rectangle (l, w) -> 2.0 * (l + w) // problem4
            
let makeShape (str:string) a b c =
    let s =  //initialize local variable that will be a shape option
        //conditional branches for checking if appropriate parameters are passed
        if (str = "Circle") && b = None && c = None
        then Some(Circle a) //set s to some circle
        elif (str = "Square") && b = None && c = None
        then Some(Square a) //set s to some square
        elif (str = "Triangle") && b <> None && c <> None
        then Some(Triangle (a, Option.get(b), Option.get(c))) //set s to some triangle
        elif (str = "Rectangle") && b <> None && c = None
        then Some(Rectangle (a, Option.get(b))) //set s to some rectangle
        else None  //set s to none
    // conditional branches for checking 's'
    if s = None then None //check if s is none before testing is shape
    elif not (isShape (Option.get(s))) then None // test isShape
    else s // else return s
    //problem 5
      
            
[<EntryPoint>]
let main argv =
    printfn "Hello World from F#!"
    0 // return an integer exit code