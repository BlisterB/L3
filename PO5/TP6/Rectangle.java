public class Rectangle extends Figure{
	private largeur, hauteur;
	
	public Rectangle(int x, int y, int largeur, int hauteur){
		super(x, y);
		this.largeur = largeur;
		this.hauteur = hauteur;
	}
	
	public void affiche(){
		System.out.printf("Rectangle\nCentre : (%d,%d)\nLargeur : %d\nHauteur : %d\n", x, y, largeur, hauteur);
	}
	
	public int getLargeur(){
		return largeur;
	}
	
	public int getHauteur(){
		return hauteur;
	}
}
