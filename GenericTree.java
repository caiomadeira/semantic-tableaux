import java.util.LinkedList;

public class GenericTree<E>
{
    // private class node
    private class Node<E> {
        public Node father;
        public E element;
        public LinkedList<Node> subtrees;

        public Node(E element)
        {
            this.father = null;
            this.element = element;
            subtrees = new LinkedList<>();
        }
    }

    

}