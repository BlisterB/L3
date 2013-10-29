public class Carre extends Figure{
	private int longueur;
	
	public Carre(int x, int y, int longueur){
		super(x, y);
		this.longueur = longueur;
	}
	
	public void affiche(){
		System.out.printf("Carre\nCentre : (%d,%d)\nLargeur : %d\nHauteur : %d\n", x, y, largeur, hauteur);		
	}
	
	public int getLongueur(){
		return longueur;
	}
}
