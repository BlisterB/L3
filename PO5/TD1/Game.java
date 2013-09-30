import java.util.Scanner;

class Game{
	public static int tourJoueur;
	public static Joueur j1 = new Joueur(), j2 = new Joueur();

	public static void choix_du_joueur(){
		System.out.println("Bonjour, bienvenue dans le jeu Abapa !\nQuel est le premier joueur ? (1/2)");
		Scanner sc = new Scanner(System.in);
		tourJoueur = sc.nextInt();
	}
	
	public static void afficher_plateau(){
		//J1
		System.out.println("J1 :\n\tt6\tt5\tt4\tt3\tt2\tt1\n" + "\t" + j1.get_case(5) + "\t" + j1.get_case(4) + "\t" + j1.get_case(3) + "\t" + j1.get_case(2) + "\t" + j1.get_case(1) + "\t" + j1.get_case(0));
		//Reserve
		System.out.println(j1.get_case(6) +"\t\t\t\t\t\t\t" + j2.get_case(6));
		//J2
		System.out.println("J2 : \n\tt1\tt2\tt3\tt4\tt5\tt6\n"+ "\t" + j1.get_case(1) + "\t" + j1.get_case(2) + "\t" + j1.get_case(3) + "\t" + j1.get_case(4) + "\t" + j1.get_case(5) + "\t" + j1.get_case(6));
	}
	
	public static void main(String arg[]){
		//Choix du joueur
		choix_du_joueur();
		afficher_plateau();
	}
}
