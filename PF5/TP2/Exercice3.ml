(* Les fonctions *)

let rec fonction_auxiliaire_diviseur n k =
	begin
		if (n mod k) == 0
			then print_string((string_of_int k) ^ " ");
		if (k <= n)
			then fonction_auxiliaire_diviseur n (k+1);
	end;;

let diviseurs n = fonction_auxiliaire_diviseur n 1;;

let rec fonction_auxiliaire_premier n l =
	if(l < (n/2))
		then 
			true
		else
			if (n mod l = 0)
				then 
					false
				else
					fonction_auxiliaire_premier n (l+1)
;;

let diviseur n = fonction_auxiliaire_premier n 1;;

(* Main *)

let n = 12;;

print_string("Diviseur de " ^ (string_of_int n) ^" : ");; diviseurs 12;; print_newline();
print_string("Est ce que " ^ (string_of_int n) ^ " est premier ? " ^ (string_of_bool (diviseur n)) ^ "\n");;
