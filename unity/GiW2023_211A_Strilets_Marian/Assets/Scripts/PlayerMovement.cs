using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour 
{
//***************************************************************************************************************************
    public float turnSpeed  = 20f; // Szybkość obracanie postaći
    Animator m_Animator; // Stworzenie zmiennej przechowującej referencję do komponentu Animatora
    Rigidbody m_Rigidbody; // Tworzenia zmiennej dla powiązanie przesunięcia i rotacji z postacią    
    Vector3 m_Movement; // Tworzenie wektora dla połączenia wartości dla osi poziomej i pionowej (horizontal, vertical)   
    Quaternion m_Rotation = Quaternion.identity; // Kwaterniony są sposobem na przechowywanie rotacji w formie wektorów 3D
//***************************************************************************************************************************
//********************************** Start **********************************************************************************
    void Start() // Start is called before the first frame update
    {
        m_Animator = GetComponent<Animator>(); // Ustawienie referencji do komponentu Animatora
        m_Rigidbody = GetComponent<Rigidbody>(); // Ustawienie referencji do komponentu Rigidbody
    }
//***************************************************************************************************************************
//************************************* FixedUpdate *************************************************************************   
    void FixedUpdate() // Update is called once per frame
    { 
    //---------------------------------------------------------------------------------------------------------------------------
    // ---------------------------Tworzenie zmiennych dla osi poziomych i pionowych ---------------------------------------------
    // horizontal - Utworzona zmienna horizontal będzie przechowywać wartość osi poziomej pobranej z wejścia. Oś jest podawana jako 
    //              argument funkcji GetAxis. W Unity osie wejścia zwracają wartości pomiędzy -1 i 1 typu float
    // vertical - Utworzona zmienna vertical będzie przechowywać wartość osi pionowej pobranej z wejścia.
    float horizontal = Input.GetAxis ("Horizontal"); 
    float vertical = Input.GetAxis ("Vertical"); 
    //===========================================================================================================================
    //---------------------------------------------------------------------------------------------------------------------------
    // Połaczenia do wektora wartości osi poziomej i pionowej (horizontal, vertical)
    //      (x, y, z) => (horizontal, 0f, vertical)  
    //      osi x => wektor ruchu posiada teraz wejście poziome (horizontal)
    //      osi y => 0f => Litera f po wartości 0 traktowanie tej liczby jako typ float. 
    //      osi z => wektor ruchu posiada teraz wejście pionowe (vertical)
    m_Movement.Set(horizontal, 0f, vertical); 
    //  Normalizowanie wektora to zachowanie jego kierunku bez zmian przy jednoczesnej zmianie jego długości do 1. 
    m_Movement.Normalize();
    //===========================================================================================================================
    //---------------------------------------------------------------------------------------------------------------------------
    // --------------------------- Ustawianie komponentu Animatora --------------------------------------------------------------
    //      Musimy przekazać komputerowi, aby informował komponent Animatora czy postać aktualnie chodzi
    //      zmienną bool (hasHorizontalInput i hasVerticalInput) ustawiamy poprzez wywołanie metody Approximately. 
    //      Przyjmuje ona dwie zmienne typu float i zwraca wartość 
    //          bool - prawdę, jeśli oba floaty mają zbliżone do siebie wartości, i fałsz w przeciwnym przypadku. 
    bool hasHorizontalInput = !Mathf.Approximately(horizontal, 0f);
    bool hasVerticalInput = !Mathf.Approximately(vertical, 0f); 

    //      zmienną bool isWalking, przyjmie wartość prawda, jeśli którakolwiek ze zmiennych hasHorizontalInput i hasVerticalInput 
    //      ma wartość prawda. W przeciwnym wypadku przyjmie wartość fałsz. 
    bool isWalking = hasHorizontalInput || hasVerticalInput;
    //===========================================================================================================================
    // ustawienia parametru Animatora IsWalking
    //      SetBool przy użyciu komponentu Animatora, do którego referencję właśnie ustawiliśmy. 
    //      1 parametrem jest nazwa parametru Animatora, którego wartość chcemy ustawić, 
    //      2 parametrem jest wartością, którą chcemy nadać temu parametrowi
    m_Animator.SetBool ("IsWalking", isWalking);
    //===========================================================================================================================
    //---------------------------------------------------------------------------------------------------------------------------
    // Ta linia kodu wykonuje następujące operacje: 
    //      Ustawia wartość zmiennej desiredForward na wyjście metody RotateTowards, która jest metodą statyczną klasy Vector3. 
    //      1 parametr - (Vector3) to wektor odpowiednio „z”  których się obracają. Kod rozpoczyna się zmienną transform.forward,
    //              która jest kierowana w stronę zmiennej m_Movement. 
    //              transform.forward jest skrótem do uzyskania komponentu Transform i pobrania jego wektora na wprost.
    //      2 parametr - (Vector3) to wektor odpowiednio „do” których się obracają. 
    //      3 parametr - jest zmianą wyrażoną kątem (w radianach), 
    //              Time.deltaTime to czas jaki minął od poprzedniej klatki (można to traktować jako czas, który minął między klatkami)
    //      4 parametr - zmianą wielkości (długości) wektora

    Vector3 desiredForward = Vector3.RotateTowards(transform.forward, m_Movement, turnSpeed * Time.deltaTime, 0f); 
    //===========================================================================================================================
    // Dla  zmiennej określającą rotację ustawienie zmiennej desiredForward
    m_Rotation = Quaternion.LookRotation (desiredForward); 
    }  
//***************************************************************************************************************************
//********************************** OnAnimatorMove *************************************************************************
    void OnAnimatorMove() // metoda pozwala na zastosowanie root motion w dowolny sposób, co oznacza, że możemy zatwierdzać osobno ruch i obrót
    { 
    //  przemieszczania się postaci (zmiany pozycji)
    //      Używamy referencji do komponentu Rigidbody dla wywołania metody MovePosition, przekazując do niej jeden parametr: nową pozycję. 
    //          Zaczynamy od aktualnej pozycji Rigidbody, 
    //          a następnie dodajemy do niej zmianę - wektor ruchu pomnożony przez długość wektora deltaPosition Animatora.  
    //      deltaPosition - w Animatorze  to zmiana pozycji wynikająca z root motion, która zostałaby zastosowana do aktualnej klatki.
    //          Pobieramy jej długość (magnitude) i mnożymy przez wektor ruchu, 
    //          który posiada właściwy kierunek, zgodny z kierunkiem ruchu postaci
    m_Rigidbody.MovePosition (m_Rigidbody.position + m_Movement * m_Animator.deltaPosition.magnitude); 

    // To wywołanie jest bardzo podobne do MovePosition z tą różnicą, że dotyczy rotacji.
    //      Tym razem jednak nie wprowadzamy zmiany do rotacji, tylko bezpośrednio ją ustawiamy. 
    m_Rigidbody.MoveRotation (m_Rotation); 
    }
//***************************************************************************************************************************
}
