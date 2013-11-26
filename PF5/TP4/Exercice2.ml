type 'a tree =
| Nil
| Node of 'a * 'a tree * 'a tree
;;

(* Fonction *)

let rec mem_abr x a = match a with
| Nil -> false
| Node (v,g,d)-> 
	if(x = v) then true else
		if(x > v) then (mem_abr x d) else (mem_abr x g)
;;

(* RENVOIE UN ABR, NE LE MODIFIE PAS *)
let rec add_abr v tree = match tree with
| Nil -> Node (v,Nil,Nil)
| Node(x,g,d) -> if (v=x) then Node(x,g,d) else
	if(v<x) then Node(x,(add_abr v g),d)
	else Node(x,g,(add_abr v d))
;;

let rec max_abr tree = match tree with
| Nil -> 0
| Node(v,Nil,Nil) -> v
| Node(v,g,Nil) -> max v (max_abr g)
| Node(v,Nil,d) -> max v (max_abr d)
| Node(v,g,d) -> max v (max (max_abr g) (max_abr d))
;;

let rec min_abr tree = match tree with
| Nil -> 0
| Node(v,Nil,Nil) -> v
| Node(v,g,Nil) -> min v (min_abr g)
| Node(v,Nil,d) -> min v (min_abr d)
| Node(v,g,d) -> min v (min (min_abr g) (min_abr d))
;;

let rec is_abr tree = match tree with
| Nil -> true
| Node(v,g,Nil) -> v >= max_abr g
| Node(v,Nil,d) -> v <= min_abr d
| Node(v,g,d) -> (v >= max_abr g) && (v <= min_abr d)
;;

(* Main *)

let x = Node (42, Node(10, Nil, Nil), Nil);;

print_string("10 fait-il parti de l'arbre ? " ^ string_of_bool(mem_abr 10 x) ^ "\n");
print_string("Quel est le max de l'abre ?" ^ string_of_int(max_abr x) ^"\n");;
print_string("Quel est le min de l'abre ?" ^ string_of_int(min_abr x) ^"\n");;
print_string("L'arbre est il un ABR ? " ^ string_of_bool(is_abr x) ^"\n");;
