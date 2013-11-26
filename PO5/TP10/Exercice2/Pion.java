enum Couleur {BLEU, ROUGE, JAUNE, VERT};

enum Forme {ROND, CARRE, ETOILE};

class Pion{
	Couleur couleur;
	Forme forme;

	public Pion(Couleur couleur, Forme forme){
		this.couleur = couleur;
		this.forme = forme;
	}

	public static void main(String[] arg){
		Pion p = new Pion(Couleur.BLEU, Forme.ROND);
		System.out.println(p.couleur + " " + p.forme);
	}
}