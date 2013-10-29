package pile;

abstract class Pile <T> {
	abstract public boolean estVide();
	abstract public T empiler(T v);
	abstract public T depiler();
}
