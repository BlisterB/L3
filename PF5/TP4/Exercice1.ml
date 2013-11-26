type 'a tree =
| Nil
| Node of 'a * 'a tree * 'a tree
;;

(* Fonction *)

let rec taille a = match a with
| Nil -> 1
| Node (x, g, d) -> 1 + taille g + taille d
;;

let rec hauteur a = match a with
| Nil -> 1
| Node (x,g,d) -> 1 + max (hauteur g) (hauteur d)
;;

let rec mem x tree = match tree with
| Nil -> false
| Node (v, g, d) -> if(x = v) then true else ((mem x g) || (mem x d))
;;

let rec complet tree = match tree with
| Nil -> true
| Node (v, g, d) -> (hauteur g = hauteur d) && complet g && complet d
;;

let rec completBONNECOMPLEXITE t =
  let rec min_hauteur t = match t with
    | Nil -> 0
    | Node(_, g, d) -> 1 + (min (hauteur g) (hauteur d))
  in min_hauteur t = hauteur t
;; 

let rec elements x = match x with
| Nil -> []
| Node (v,g, d) -> [v]@(elements g)@(elements d)
;;

(* Main *)

let x = Node (42, Node(10, Nil, Nil), Nil);;

print_string("Taille de l'arbre  : " ^ string_of_int(taille x) ^ "\n");;
print_string("Hauteur de l'arbre : " ^ string_of_int(hauteur x) ^ "\n");;
print_string("Est ce que l'arbre contient 42 " ^ string_of_bool(mem 42 x) ^ "\n");;
print_string("Est ce que l'arbre est complet ? " ^ string_of_bool(complet x) ^ "\n");;